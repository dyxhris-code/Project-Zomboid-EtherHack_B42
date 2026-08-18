# Ghidra semantic export

Program: `pztrainer.dll`

| Address | Semantic name | Module | Confidence | Callers | Callees | Strings |
| --- | --- | --- | --- | ---: | ---: | ---: |
| `0x180001780` | `pztrainerDllMain` | bootstrap | high | 1 | 3 | 0 |
| `0x180001810` | `jniCallObjectMethodWithIntArg` | jni-helpers | medium | 48 | 0 | 0 |
| `0x1800018a0` | `jniCallIntMethod` | jni-helpers | high | 28 | 0 | 0 |
| `0x180001900` | `jniCallVoidMethodWithIntArg` | jni-helpers | high | 37 | 0 | 0 |
| `0x180001930` | `jniCallStaticObjectMethodOneArg` | jni-helpers | medium | 48 | 0 | 0 |
| `0x180007c90` | `copySmallString` | cpp-runtime | medium | 23 | 1 | 0 |
| `0x180008440` | `destroySmallString` | cpp-runtime | medium | 145 | 1 | 0 |
| `0x180008c70` | `assignSmallString` | cpp-runtime | high | 55 | 6 | 0 |
| `0x180008dd0` | `appendSmallString` | cpp-runtime | medium | 27 | 2 | 0 |
| `0x180009be0` | `readSteadyClockTimePoint` | cpp-runtime | high | 26 | 2 | 0 |
| `0x180009cc0` | `findGlobalJniClass` | jni-helpers | high | 18 | 6 | 5 |
| `0x18003e740` | `hookWorker` | bootstrap | high | 0 | 9 | 8 |
| `0x18003ade0` | `initializeRenderBridge` | render | high | 1 | 29 | 13 |
| `0x180001df0` | `initializeCoreJniBridge` | jni-core | medium | 1 | 2 | 118 |
| `0x180009f30` | `initializeSkillBridge` | skills | medium | 3 | 1 | 59 |
| `0x18000d220` | `initializeItemWeaponBridge` | items | medium | 4 | 1 | 72 |
| `0x18001a3e0` | `initializePalletGrantBridge` | item-grant | high | 2 | 1 | 32 |
| `0x18001a940` | `selectSafePalletCarrier` | item-grant | high | 1 | 4 | 4 |
| `0x18001aba0` | `sendDisposablePallet` | item-grant | high | 1 | 6 | 2 |
| `0x18001aee0` | `findReturnedPallet` | item-grant | high | 2 | 5 | 2 |
| `0x18001b260` | `submitTakeBricksAction` | item-grant | high | 2 | 2 | 3 |
| `0x18001b510` | `beginPalletItemGrant` | item-grant | high | 2 | 16 | 0 |
| `0x18001bc80` | `pollPalletItemGrant` | item-grant | high | 1 | 8 | 0 |
| `0x18001d190` | `initializeCharacterStatsBridge` | character | medium | 4 | 1 | 62 |
| `0x180021840` | `initializePlayerDamageBridge` | player | medium | 1 | 1 | 24 |
| `0x180022ed0` | `initializeClimateBridge` | climate | medium | 1 | 1 | 51 |
| `0x180025840` | `invokeLuaBoundMethod` | jni-helpers | high | 21 | 5 | 1 |
| `0x18002a7c0` | `initializeBallisticsBridge` | ballistics | medium | 1 | 1 | 93 |

Function names are curated in `metadata/semantic-functions.tsv`; generated C remains decompiler output and is not source code.
Data names are curated in `metadata/semantic-data.tsv` and are backed by initializer and use-site evidence.
