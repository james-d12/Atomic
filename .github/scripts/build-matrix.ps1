#!/usr/bin/env pwsh
$ErrorActionPreference = "Stop"

# Fail early if required environment variables are missing
if (-not $env:COMPILERS) { Write-Host "❌ COMPILERS is required"; exit 1 }
if (-not $env:STANDARDS) { Write-Host "❌ STANDARDS is required"; exit 1 }
if (-not $env:MODES)     { Write-Host "❌ MODES is required"; exit 1 }

$Compilers = $env:COMPILERS.Split(" ")
$Standards = $env:STANDARDS.Split(" ")
$Modes     = $env:MODES.Split(" ")

Write-Host "🏗️  Running build matrix"
Write-Host "Compilers: $($Compilers -join ', ')"
Write-Host "Standards: $($Standards -join ', ')"
Write-Host "Modes: $($Modes -join ', ')"
Write-Host ""

# Array to track failures
$Failures = @()

foreach ($Compiler in $Compilers) {
    foreach ($Standard in $Standards) {
        foreach ($Mode in $Modes) {
            Write-Host "::group::$Compiler ($Standard, $Mode)"
            $BuildDir = "build-$Compiler-$Standard-$Mode"
            cmake -E make_directory $BuildDir
            Push-Location $BuildDir

            # CMake configure
            try {
                cmake $env:GITHUB_WORKSPACE `
                    -DCMAKE_BUILD_TYPE=$Mode `
                    -DCMAKE_CXX_FLAGS="-std=$Standard" `
                    -DCMAKE_CXX_COMPILER=$Compiler
            } catch {
                $Failures += "$Compiler $Standard $Mode (cmake configure)"
                Pop-Location
                Write-Host "::endgroup::"
                continue
            }

            # Build
            try {
                cmake --build . --config $Mode
            } catch {
                $Failures += "$Compiler $Standard $Mode (build)"
                Pop-Location
                Write-Host "::endgroup::"
                continue
            }

            # Test executable path
            $TestExe = Join-Path $PWD "Tests.exe"
            if (-not (Test-Path $TestExe)) {
                $TestExe = Join-Path $PWD $Mode "Tests.exe"
            }

            # Run tests
            if (Test-Path $TestExe) {
                try {
                    & $TestExe
                } catch {
                    $Failures += "$Compiler $Standard $Mode (tests)"
                }
            } else {
                Write-Host "⚠️  No test binary found in $BuildDir"
                $Failures += "$Compiler $Standard $Mode (no test binary)"
            }

            Pop-Location
            Write-Host "::endgroup::"
        }
    }
}

# Summary
Write-Host ""
Write-Host "🧾 Build Matrix Summary:"
if ($Failures.Count -eq 0) {
    Write-Host "✅ All builds and tests passed!"
} else {
    Write-Host "❌ $($Failures.Count) failed combination(s):"
    foreach ($fail in $Failures) {
        Write-Host "  - $fail"
    }
    exit 1
}
