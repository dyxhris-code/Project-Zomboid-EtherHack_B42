/*
 * Semantic name: readSteadyClockTimePoint
 * Address: 0x180009be0
 * Module: cpp-runtime
 * Confidence: high
 * Summary: Reads a steady-clock time point used by request polling deadlines.
 * Ghidra function: readSteadyClockTimePoint
 * Callers:
 *   - FUN_18000b8a0 @ 0x18000b8a0
 *   - FUN_18000be40 @ 0x18000be40
 *   - FUN_18000c190 @ 0x18000c190
 *   - FUN_18000cc00 @ 0x18000cc00
 *   - FUN_18000e0f0 @ 0x18000e0f0
 *   - FUN_18000f2c0 @ 0x18000f2c0
 *   - FUN_1800113d0 @ 0x1800113d0
 *   - FUN_180015340 @ 0x180015340
 *   - FUN_180015910 @ 0x180015910
 *   - FUN_180016b70 @ 0x180016b70
 *   - FUN_180016f40 @ 0x180016f40
 *   - FUN_1800181c0 @ 0x1800181c0
 *   - FUN_180018e70 @ 0x180018e70
 *   - FUN_180019ac0 @ 0x180019ac0
 *   - sendDisposablePallet @ 0x18001aba0
 *   - beginPalletItemGrant @ 0x18001b510
 *   - pollPalletItemGrant @ 0x18001bc80
 *   - FUN_18001e8d0 @ 0x18001e8d0
 *   - FUN_180020810 @ 0x180020810
 *   - FUN_180020b80 @ 0x180020b80
 *   - FUN_180020f50 @ 0x180020f50
 *   - FUN_180021c30 @ 0x180021c30
 *   - FUN_180025b00 @ 0x180025b00
 *   - FUN_180025f90 @ 0x180025f90
 *   - FUN_18002d370 @ 0x18002d370
 *   - FUN_18002d670 @ 0x18002d670
 * Callees:
 *   - _Query_perf_frequency @ 0xEXTERNAL:00000077
 *   - _Query_perf_counter @ 0xEXTERNAL:00000078
 */


/* Reads a steady-clock time point used by request polling deadlines. */

longlong * readSteadyClockTimePoint(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = _Query_perf_frequency();
  lVar2 = _Query_perf_counter();
  if (lVar1 == 10000000) {
    *param_1 = lVar2 * 100;
    return param_1;
  }
  if (lVar1 == 24000000) {
    lVar1 = lVar2 + SUB168(SEXT816(-0x4d0b03f86b6f730d) * SEXT816(lVar2),8);
    lVar3 = (lVar1 >> 0x18) - (lVar1 >> 0x3f);
    lVar1 = (lVar2 + lVar3 * -24000000) * 1000000000;
    lVar1 = SUB168(SEXT816(-0x4d0b03f86b6f730d) * SEXT816(lVar1),8) + lVar1;
    *param_1 = ((lVar1 >> 0x18) - (lVar1 >> 0x3f)) + lVar3 * 1000000000;
    return param_1;
  }
  *param_1 = ((lVar2 % lVar1) * 1000000000) / lVar1 + (lVar2 / lVar1) * 1000000000;
  return param_1;
}

