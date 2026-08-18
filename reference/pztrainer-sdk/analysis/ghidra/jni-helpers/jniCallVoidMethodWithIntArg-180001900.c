/*
 * Semantic name: jniCallVoidMethodWithIntArg
 * Address: 0x180001900
 * Module: jni-helpers
 * Confidence: high
 * Summary: Calls a cached JNI void instance method with one integer argument.
 * Ghidra function: jniCallVoidMethodWithIntArg
 * Callers:
 *   - FUN_180003ad0 @ 0x180003ad0
 *   - FUN_18000be40 @ 0x18000be40
 *   - FUN_18000c190 @ 0x18000c190
 *   - FUN_1800113d0 @ 0x1800113d0
 *   - FUN_1800150c0 @ 0x1800150c0
 *   - FUN_180015340 @ 0x180015340
 *   - FUN_1800168d0 @ 0x1800168d0
 *   - FUN_180016b70 @ 0x180016b70
 *   - FUN_1800181c0 @ 0x1800181c0
 *   - FUN_180018ca0 @ 0x180018ca0
 *   - sendDisposablePallet @ 0x18001aba0
 *   - FUN_18001c3a0 @ 0x18001c3a0
 *   - FUN_18001ec30 @ 0x18001ec30
 *   - FUN_180020810 @ 0x180020810
 *   - FUN_180021c30 @ 0x180021c30
 *   - FUN_180022750 @ 0x180022750
 *   - FUN_1800239a0 @ 0x1800239a0
 *   - FUN_180023b20 @ 0x180023b20
 *   - FUN_180023c20 @ 0x180023c20
 *   - FUN_180023e80 @ 0x180023e80
 *   - FUN_180023f20 @ 0x180023f20
 *   - FUN_180024110 @ 0x180024110
 *   - FUN_1800244a0 @ 0x1800244a0
 *   - FUN_180024540 @ 0x180024540
 *   - FUN_180024860 @ 0x180024860
 *   - FUN_180026790 @ 0x180026790
 *   - FUN_180026ce0 @ 0x180026ce0
 *   - FUN_180026dd0 @ 0x180026dd0
 *   - FUN_180026f00 @ 0x180026f00
 *   - FUN_180029010 @ 0x180029010
 *   - FUN_18002c1d0 @ 0x18002c1d0
 *   - FUN_18002c2f0 @ 0x18002c2f0
 *   - FUN_18002c870 @ 0x18002c870
 *   - FUN_18002c970 @ 0x18002c970
 *   - FUN_18002ccf0 @ 0x18002ccf0
 *   - FUN_18002d370 @ 0x18002d370
 *   - FUN_18002d670 @ 0x18002d670
 * Callees: none
 */


/* Calls a cached JNI void instance method with one integer argument. */

void jniCallVoidMethodWithIntArg(longlong *param_1)

{
  (**(code **)(*param_1 + 0x1f0))();
  return;
}

