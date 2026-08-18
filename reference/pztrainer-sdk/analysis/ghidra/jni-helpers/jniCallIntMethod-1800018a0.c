/*
 * Semantic name: jniCallIntMethod
 * Address: 0x1800018a0
 * Module: jni-helpers
 * Confidence: high
 * Summary: Calls a cached JNI integer-returning instance method without additional arguments.
 * Ghidra function: jniCallIntMethod
 * Callers:
 *   - FUN_180003ad0 @ 0x180003ad0
 *   - FUN_18000ac90 @ 0x18000ac90
 *   - FUN_18000b1b0 @ 0x18000b1b0
 *   - FUN_18000de00 @ 0x18000de00
 *   - FUN_18000df20 @ 0x18000df20
 *   - FUN_18000e0f0 @ 0x18000e0f0
 *   - FUN_180010480 @ 0x180010480
 *   - FUN_180014d30 @ 0x180014d30
 *   - FUN_180015340 @ 0x180015340
 *   - FUN_180015910 @ 0x180015910
 *   - FUN_180016b70 @ 0x180016b70
 *   - FUN_180016f40 @ 0x180016f40
 *   - FUN_180017fc0 @ 0x180017fc0
 *   - FUN_1800181c0 @ 0x1800181c0
 *   - FUN_1800187b0 @ 0x1800187b0
 *   - FUN_180019420 @ 0x180019420
 *   - selectSafePalletCarrier @ 0x18001a940
 *   - sendDisposablePallet @ 0x18001aba0
 *   - findReturnedPallet @ 0x18001aee0
 *   - FUN_18001c3a0 @ 0x18001c3a0
 *   - FUN_180021c30 @ 0x180021c30
 *   - FUN_180022750 @ 0x180022750
 *   - FUN_180022970 @ 0x180022970
 *   - FUN_180026f00 @ 0x180026f00
 *   - FUN_18002c2f0 @ 0x18002c2f0
 *   - FUN_18002ccf0 @ 0x18002ccf0
 *   - FUN_18002d670 @ 0x18002d670
 *   - FUN_1800388b0 @ 0x1800388b0
 * Callees: none
 */


/* Calls a cached JNI integer-returning instance method without additional arguments. */

void jniCallIntMethod(longlong *param_1)

{
  (**(code **)(*param_1 + 400))();
  return;
}

