param(
    [string]$SdkRoot = "$PSScriptRoot\..",
    [string]$Output = "$PSScriptRoot\..\analysis\ghidra"
)

$ErrorActionPreference = "Stop"
Set-StrictMode -Version Latest

$SdkRoot = [System.IO.Path]::GetFullPath($SdkRoot)
$Output = [System.IO.Path]::GetFullPath($Output)
$functionManifestPath = Join-Path $SdkRoot "metadata\semantic-functions.tsv"
$dataManifestPath = Join-Path $SdkRoot "metadata\semantic-data.tsv"
$functionIndexPath = Join-Path $Output "INDEX.md"
$dataIndexPath = Join-Path $Output "DATA_SYMBOLS.md"

foreach ($required in @($functionManifestPath, $dataManifestPath, $functionIndexPath, $dataIndexPath)) {
    if (-not (Test-Path -LiteralPath $required -PathType Leaf)) {
        throw "Missing readable SDK file: $required"
    }
}

function Import-SemanticManifest {
    param(
        [Parameter(Mandatory)]
        [string]$Path
    )

    $rows = @(Import-Csv -LiteralPath $Path -Delimiter "`t")
    if ($rows.Count -eq 0) {
        throw "Semantic manifest is empty: $Path"
    }

    foreach ($row in $rows) {
        foreach ($column in @("address", "name", "module", "confidence", "summary")) {
            if ([string]::IsNullOrWhiteSpace($row.$column)) {
                throw "Missing '$column' in semantic manifest: $Path"
            }
        }
        if ($row.address -notmatch '^0x[0-9a-fA-F]+$') {
            throw "Invalid address '$($row.address)' in semantic manifest: $Path"
        }
    }

    foreach ($column in @("address", "name")) {
        $duplicates = @(
            $rows |
                ForEach-Object { $_.$column } |
                Group-Object |
                Where-Object Count -gt 1
        )
        if ($duplicates.Count -gt 0) {
            $values = ($duplicates | ForEach-Object Name) -join ", "
            throw "Duplicate $column values in ${Path}: $values"
        }
    }

    return $rows
}

$functionRows = @(Import-SemanticManifest -Path $functionManifestPath)
$dataRows = @(Import-SemanticManifest -Path $dataManifestPath)
$generatedFiles = @(Get-ChildItem -LiteralPath $Output -Recurse -Filter "*.c" -File)

$generatedFunctions = foreach ($file in $generatedFiles) {
    $header = Get-Content -LiteralPath $file.FullName -TotalCount 12
    $nameLine = $header | Where-Object { $_ -match '^ \* Semantic name: (.+)$' } | Select-Object -First 1
    $addressLine = $header | Where-Object { $_ -match '^ \* Address: (0x[0-9a-fA-F]+)$' } | Select-Object -First 1
    if ($null -eq $nameLine -or $null -eq $addressLine) {
        throw "Generated C file lacks a semantic header: $($file.FullName)"
    }

    $null = $nameLine -match '^ \* Semantic name: (.+)$'
    $semanticName = $Matches[1]
    $null = $addressLine -match '^ \* Address: (0x[0-9a-fA-F]+)$'
    $address = $Matches[1].ToLowerInvariant()

    [pscustomobject]@{
        address = $address
        name = $semanticName
        key = "$address|$semanticName"
        path = $file.FullName
    }
}

$duplicateGenerated = @($generatedFunctions | Group-Object key | Where-Object Count -gt 1)
if ($duplicateGenerated.Count -gt 0) {
    throw "Duplicate generated function keys: $(($duplicateGenerated | ForEach-Object Name) -join ', ')"
}

$expectedKeys = @(
    $functionRows | ForEach-Object {
        "$($_.address.ToLowerInvariant())|$($_.name)"
    }
)
$actualKeys = @($generatedFunctions | ForEach-Object key)
$missingFunctions = @($expectedKeys | Where-Object { $_ -notin $actualKeys })
$extraFunctions = @($actualKeys | Where-Object { $_ -notin $expectedKeys })
if ($missingFunctions.Count -gt 0 -or $extraFunctions.Count -gt 0) {
    throw "Generated functions do not match manifest. Missing: $($missingFunctions -join ', '); extra: $($extraFunctions -join ', ')"
}

$functionIndex = Get-Content -LiteralPath $functionIndexPath -Raw
foreach ($row in $functionRows) {
    $entry = "| ``$($row.address)`` | ``$($row.name)`` |"
    if (-not $functionIndex.Contains($entry)) {
        throw "Function index is missing $($row.address) $($row.name)"
    }
}

$dataIndex = Get-Content -LiteralPath $dataIndexPath -Raw
$generatedText = ($generatedFiles | ForEach-Object { Get-Content -LiteralPath $_.FullName -Raw }) -join "`n"
foreach ($row in $dataRows) {
    $entry = "| ``$($row.address)`` | ``$($row.name)`` |"
    if (-not $dataIndex.Contains($entry)) {
        throw "Data index is missing $($row.address) $($row.name)"
    }
    if (-not $generatedText.Contains($row.name)) {
        throw "Semantic data label '$($row.name)' is absent from generated C output"
    }
}

Write-Output "Validated $($functionRows.Count) functions, $($dataRows.Count) data symbols, and $($generatedFiles.Count) generated C files"
