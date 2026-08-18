param(
    [string]$Binary = "D:\Data\QQFile\pztrainer.dll",
    [string]$Ghidra = "D:\Develope\Tools\ghidra_12.1.2_PUBLIC",
    [string]$ProjectRoot = "$PSScriptRoot\..\..\..\build\ghidra-project",
    [string]$Output = "$PSScriptRoot\..\analysis\ghidra"
)

$ErrorActionPreference = "Stop"

$sdkRoot = (Resolve-Path "$PSScriptRoot\..").Path
$ProjectRoot = [System.IO.Path]::GetFullPath($ProjectRoot)
$Output = [System.IO.Path]::GetFullPath($Output)
$manifest = Join-Path $sdkRoot "metadata\semantic-functions.tsv"
$dataManifest = Join-Path $sdkRoot "metadata\semantic-data.tsv"
$scriptPath = Join-Path $sdkRoot "tools\ghidra"
$headless = Join-Path $Ghidra "support\analyzeHeadless.bat"
$projectName = "pztrainer"
$programName = Split-Path $Binary -Leaf

foreach ($required in @($Binary, $manifest, $dataManifest, $headless)) {
    if (-not (Test-Path -LiteralPath $required -PathType Leaf)) {
        throw "Missing required file: $required"
    }
}

New-Item -ItemType Directory -Force -Path $ProjectRoot, $Output | Out-Null
$env:JAVA_HOME = "D:\Develope\Dev_Env\JDK25"

$projectFile = Join-Path $ProjectRoot "$projectName.gpr"
$commonArgs = @(
    $ProjectRoot,
    $projectName,
    "-scriptPath", $scriptPath,
    "-postScript", "ExportReadableSdk.java", (Resolve-Path $Output).Path, $manifest, $dataManifest
)

if (Test-Path -LiteralPath $projectFile -PathType Leaf) {
    $invokeArgs = @(
        $commonArgs[0],
        $commonArgs[1],
        "-process",
        $programName,
        "-noanalysis"
    ) + $commonArgs[2..($commonArgs.Count - 1)]
} else {
    $invokeArgs = @(
        $commonArgs[0],
        $commonArgs[1],
        "-import",
        $Binary,
        "-analysisTimeoutPerFile",
        "600"
    ) + $commonArgs[2..($commonArgs.Count - 1)]
}

& $headless @invokeArgs

if ($LASTEXITCODE -ne 0) {
    throw "Ghidra readable SDK export failed with exit code $LASTEXITCODE"
}

$index = Join-Path $Output "INDEX.md"
if (-not (Test-Path -LiteralPath $index -PathType Leaf)) {
    throw "Ghidra export did not produce $index"
}

$validator = Join-Path $sdkRoot "tools\validate_readable_sdk.ps1"
& $validator -SdkRoot $sdkRoot -Output $Output

$actualCount = @(Get-ChildItem -LiteralPath $Output -Recurse -Filter "*.c" -File).Count
Write-Output "Readable SDK exported and validated $actualCount functions to $Output"
