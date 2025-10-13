#!/usr/bin/env pwsh
$ErrorActionPreference = "Stop"

# Defaults if not provided
$Compilers = if ($env:COMPILERS) { $env:COMPILERS.Split(" ") } else { @("cl") }
$Standards = if ($env:STANDARDS) { $env:STANDARDS.Split(" ") } else { @("c++17") }
$Modes     = if ($env:MODES)     { $env:MODES.Split(" ") }     else { @("Debug") }

Write-Host "🏗️  Running build matrix"
Write-Host "Compilers: $($Compilers -join ', ')"
Write-Host "Standards: $($Standards -join ', ')"
Write-Host "Modes: $($Modes -join ', ')"
Write-Host ""

foreach ($Compiler in $Compilers) {
    foreach ($Standard in $Standards) {
        foreach ($Mode in $Modes) {
            Write-Host "::group::$Compiler ($Standard, $Mode)"
            $BuildDir = "build-$Compiler-$Standard-$Mode"
            cmake -E make_directory $BuildDir
            Push-Location $BuildDir

            cmake $env:GITHUB_WORKSPACE `
                -DCMAKE_BUILD_TYPE=$Mode `
                -DCMAKE_CXX_FLAGS="-std=$Standard" `
                -DCMAKE_CXX_COMPILER=$Compiler

            cmake --build . --config $Mode

            if (Test-Path "./Tests.exe") {
                ./Tests.exe
            } elseif (Test-Path "./Tests") {
                ./Tests
            } else {
                Write-Host "⚠️  No test binary found in $BuildDir"
            }

            Pop-Location
            Write-Host "::endgroup::"
        }
    }
}
