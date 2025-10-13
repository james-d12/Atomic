#!/usr/bin/env pwsh
$ErrorActionPreference = "Stop"

# Fail early if required environment variables are missing
if (-not $env:COMPILERS) { Write-Host "❌ COMPILERS is required"; exit 1 }
if (-not $env:STANDARDS) { Write-Host "❌ STANDARDS is required"; exit 1 }
if (-not $env:MODES)     { Write-Host "❌ MODES is required"; exit 1 }

$Compilers = $env:COMPILERS.Split(" ")
$Standards = $env:STANDARDS.Split(" ")
$Modes     = $env:MODES.Split(" ")

Write-Host "🏗️  Running build matrix in parallel"
Write-Host "Compilers: $($Compilers -join ', ')"
Write-Host "Standards: $($Standards -join ', ')"
Write-Host "Modes: $($Modes -join ', ')"
Write-Host ""

# Prepare combinations
$Matrix = foreach ($Compiler in $Compilers) {
    foreach ($Standard in $Standards) {
        foreach ($Mode in $Modes) {
            [PSCustomObject]@{
                Compiler = $Compiler
                Standard = $Standard
                Mode     = $Mode
            }
        }
    }
}

# Create a temporary file to collect failures
$FailureFile = "$env:GITHUB_WORKSPACE/build-matrix-failures.txt"
if (Test-Path $FailureFile) { Remove-Item $FailureFile }

# Run builds/tests in parallel
$Matrix | ForEach-Object -Parallel {
    param($Compiler, $Standard, $Mode, $Workspace, $FailureFile)

    Write-Host "::group::$Compiler ($Standard, $Mode)"
    $BuildDir = "build-$Compiler-$Standard-$Mode"
    cmake -E make_directory $BuildDir
    Push-Location $BuildDir

    # Helper to log failures
    function RecordFailure($msg) {
        Add-Content -Path $FailureFile -Value $msg
    }

    # CMake configure
    try {
        cmake $Workspace `
            -DCMAKE_BUILD_TYPE=$Mode `
            -DCMAKE_CXX_FLAGS="-std=$Standard" `
            -DCMAKE_CXX_COMPILER=$Compiler
    } catch { RecordFailure "$Compiler $Standard $Mode (cmake configure)"; Pop-Location; Write-Host "::endgroup::"; return }

    # Build
    try {
        cmake --build . --config $Mode
    } catch { RecordFailure "$Compiler $Standard $Mode (build)"; Pop-Location; Write-Host "::endgroup::"; return }

    # Test executable
    $TestExe = Join-Path $PWD "Tests.exe"
    if (-not (Test-Path $TestExe)) { $TestExe = Join-Path $PWD $Mode "Tests.exe" }

    if (Test-Path $TestExe) {
        try { & $TestExe } catch { RecordFailure "$Compiler $Standard $Mode (tests)" }
    } else {
        Write-Host "⚠️  No test binary found in $BuildDir"
        RecordFailure "$Compiler $Standard $Mode (no test binary)"
    }

    Pop-Location
    Write-Host "::endgroup::"

} -ThrottleLimit 4 -ArgumentList $FailureFile,$env:GITHUB_WORKSPACE

# Collect failures
$Failures = @()
if (Test-Path $FailureFile) { $Failures = Get-Content $FailureFile }

# Summary
Write-Host ""
Write-Host "🧾 Build Matrix Summary:"
if ($Failures.Count -eq 0) {
    Write-Host "✅ All builds and tests passed!"
} else {
    Write-Host "❌ $($Failures.Count) failed combination(s):"
    foreach ($fail in $Failures) { Write-Host "  - $fail" }
    exit 1
}
