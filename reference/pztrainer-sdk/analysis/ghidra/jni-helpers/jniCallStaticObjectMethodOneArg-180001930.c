/*
 * Semantic name: jniCallStaticObjectMethodOneArg
 * Address: 0x180001930
 * Module: jni-helpers
 * Confidence: medium
 * Summary: Calls a cached JNI static object method with one object argument.
 * Ghidra function: jniCallStaticObjectMethodOneArg
 * Callers:
 *   - initializeCoreJniBridge @ 0x180001df0
 *   - FUN_180003ad0 @ 0x180003ad0
 *   - FUN_180006860 @ 0x180006860
 *   - FUN_180006f40 @ 0x180006f40
 *   - FUN_180007620 @ 0x180007620
 *   - findGlobalJniClass @ 0x180009cc0
 *   - FUN_18000ac90 @ 0x18000ac90
 *   - FUN_18000b1b0 @ 0x18000b1b0
 *   - FUN_18000b8a0 @ 0x18000b8a0
 *   - FUN_18000be40 @ 0x18000be40
 *   - FUN_18000c190 @ 0x18000c190
 *   - FUN_18000df20 @ 0x18000df20
 *   - FUN_18000e0f0 @ 0x18000e0f0
 *   - FUN_18000f790 @ 0x18000f790
 *   - FUN_180010480 @ 0x180010480
 *   - FUN_1800113d0 @ 0x1800113d0
 *   - FUN_180011650 @ 0x180011650
 *   - FUN_1800181c0 @ 0x1800181c0
 *   - FUN_180018e70 @ 0x180018e70
 *   - FUN_180019420 @ 0x180019420
 *   - selectSafePalletCarrier @ 0x18001a940
 *   - sendDisposablePallet @ 0x18001aba0
 *   - submitTakeBricksAction @ 0x18001b260
 *   - beginPalletItemGrant @ 0x18001b510
 *   - FUN_18001c3a0 @ 0x18001c3a0
 *   - FUN_18001e730 @ 0x18001e730
 *   - FUN_18001e8d0 @ 0x18001e8d0
 *   - FUN_18001ec30 @ 0x18001ec30
 *   - FUN_18001ef80 @ 0x18001ef80
 *   - FUN_18001f250 @ 0x18001f250
 *   - FUN_180020b80 @ 0x180020b80
 *   - FUN_180020f50 @ 0x180020f50
 *   - FUN_180021450 @ 0x180021450
 *   - FUN_180021c30 @ 0x180021c30
 *   - FUN_180022970 @ 0x180022970
 *   - FUN_180024860 @ 0x180024860
 *   - invokeLuaBoundMethod @ 0x180025840
 *   - FUN_180025b00 @ 0x180025b00
 *   - FUN_1800261d0 @ 0x1800261d0
 *   - FUN_1800264f0 @ 0x1800264f0
 *   - FUN_180026dd0 @ 0x180026dd0
 *   - FUN_180026f00 @ 0x180026f00
 *   - FUN_180029010 @ 0x180029010
 *   - FUN_18002d480 @ 0x18002d480
 *   - FUN_18002d670 @ 0x18002d670
 *   - FUN_18002f770 @ 0x18002f770
 *   - FUN_18002f9b0 @ 0x18002f9b0
 *   - FUN_1800388b0 @ 0x1800388b0
 * Callees: none
 */


/* Calls a cached JNI static object method with one object argument. */

void jniCallStaticObjectMethodOneArg(longlong *param_1)

{
  (**(code **)(*param_1 + 0x398))();
  return;
}

