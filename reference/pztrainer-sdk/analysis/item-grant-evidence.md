# Disposable pallet item-grant evidence

This note separates instruction-backed facts from the human-readable reconstruction in
`analysis/reconstructed/item-grant-pallet.cpp`.

## Confirmed functions

| Address | Semantic name | Evidence |
| --- | --- | --- |
| `0x18001a3e0` | `initializePalletGrantBridge` | Resolves `InventoryItemFactory`, `HandWeapon`, `IsoTrap`, `AddExplosiveTrapPacket`, `NetTimedActionPacket`, and packet fields/methods. |
| `0x18001a940` | `selectSafePalletCarrier` | Iterates `Base.Hammer`, `Base.RollingPin`, `Base.Saucepan`, and `Base.Fork`; rejects non-`HandWeapon` items and any carrier with positive world-effect fields. |
| `0x18001aba0` | `sendDisposablePallet` | Calls `CreateItem`, sets remote-control ID `0x505c`, records item ID, constructs `AddExplosiveTrapPacket`, calls `set`, then `sendToServer(AddExplosiveTrap)`. |
| `0x18001aee0` | `findReturnedPallet` | Scans `getCurrentSquare()->getObjects()`, checks `IsoTrap`, then matches carrier item ID or marker plus full type. |
| `0x18001b260` | `submitTakeBricksAction` | Builds six arguments in order: player, pallet, pallet square, null sprite, requested type, amount; invokes `ISTakeBricks.createNewAndSend`. |
| `0x18001b510` | `beginPalletItemGrant` | Validates item type and amount, prevents overlap, starts packet delivery, and initializes pending state. |
| `0x18001bc80` | `pollPalletItemGrant` | Polls the current square, submits the native action, detects pallet removal, and handles timeout messages. |

## Confirmed constants and timing

- Carrier marker: `0x505c`.
- Requested amount is clamped to `1..100`.
- First server-object polling delay: approximately `150 ms`.
- Server-object deadline: approximately `5 s`.
- After native action submission, polling resumes after approximately `150 ms`.
- The later deadline scales with the requested amount in the native state machine.

## External server behavior

The native game `ISTakeBricks:complete()` removes the supplied pallet from its square, calls
`character:getInventory():AddItems(item, amount)`, and registers the returned items with
`sendAddItemsToContainer`. This is why the resulting inventory entries are server-created and persistent.

## Remaining uncertainty

- Native C++ helper and state-structure types are reconstructed from usage because the PDB is absent.
- JNI local-reference cleanup is represented semantically rather than line-for-line.
- Time points are inferred from `std::chrono` constants and state transitions; generated Ghidra output remains the primary address-level evidence.
