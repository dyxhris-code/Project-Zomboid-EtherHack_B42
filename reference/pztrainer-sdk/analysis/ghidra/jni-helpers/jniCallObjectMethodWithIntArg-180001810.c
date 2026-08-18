/*
 * Semantic name: jniCallObjectMethodWithIntArg
 * Address: 0x180001810
 * Module: jni-helpers
 * Confidence: medium
 * Summary: Calls a cached JNI object-returning instance method with one integer argument.
 * Ghidra function: jniCallObjectMethodWithIntArg
 * Callers:
 *   - FUN_180001b80 @ 0x180001b80
 *   - FUN_180003940 @ 0x180003940
 *   - FUN_180003ad0 @ 0x180003ad0
 *   - FUN_180006b00 @ 0x180006b00
 *   - FUN_1800071e0 @ 0x1800071e0
 *   - findGlobalJniClass @ 0x180009cc0
 *   - FUN_18000ac90 @ 0x18000ac90
 *   - FUN_18000b1b0 @ 0x18000b1b0
 *   - FUN_18000b8a0 @ 0x18000b8a0
 *   - FUN_18000be40 @ 0x18000be40
 *   - FUN_18000c190 @ 0x18000c190
 *   - FUN_18000cc00 @ 0x18000cc00
 *   - FUN_18000df20 @ 0x18000df20
 *   - FUN_18000e0f0 @ 0x18000e0f0
 *   - FUN_180010480 @ 0x180010480
 *   - FUN_180014d30 @ 0x180014d30
 *   - FUN_180015340 @ 0x180015340
 *   - FUN_180016630 @ 0x180016630
 *   - FUN_1800187b0 @ 0x1800187b0
 *   - FUN_180019420 @ 0x180019420
 *   - FUN_180019ac0 @ 0x180019ac0
 *   - findReturnedPallet @ 0x18001aee0
 *   - FUN_18001c3a0 @ 0x18001c3a0
 *   - FUN_18001db90 @ 0x18001db90
 *   - FUN_18001e440 @ 0x18001e440
 *   - FUN_18001e8d0 @ 0x18001e8d0
 *   - FUN_18001ef80 @ 0x18001ef80
 *   - FUN_18001f250 @ 0x18001f250
 *   - FUN_180021450 @ 0x180021450
 *   - FUN_180021c30 @ 0x180021c30
 *   - FUN_180022970 @ 0x180022970
 *   - FUN_180023c20 @ 0x180023c20
 *   - FUN_180023f20 @ 0x180023f20
 *   - FUN_180024110 @ 0x180024110
 *   - FUN_180024540 @ 0x180024540
 *   - invokeLuaBoundMethod @ 0x180025840
 *   - FUN_180025f90 @ 0x180025f90
 *   - FUN_180026380 @ 0x180026380
 *   - FUN_180026f00 @ 0x180026f00
 *   - FUN_180029010 @ 0x180029010
 *   - FUN_180029e20 @ 0x180029e20
 *   - FUN_18002a4b0 @ 0x18002a4b0
 *   - FUN_18002c660 @ 0x18002c660
 *   - FUN_18002c970 @ 0x18002c970
 *   - FUN_18002ccf0 @ 0x18002ccf0
 *   - FUN_18002d670 @ 0x18002d670
 *   - FUN_18002f770 @ 0x18002f770
 *   - FUN_1800388b0 @ 0x1800388b0
 * Callees: none
 */


/* Calls a cached JNI object-returning instance method with one integer argument. */

void jniCallObjectMethodWithIntArg(longlong *param_1)

{
  (**(code **)(*param_1 + 0x118))();
  return;
}

