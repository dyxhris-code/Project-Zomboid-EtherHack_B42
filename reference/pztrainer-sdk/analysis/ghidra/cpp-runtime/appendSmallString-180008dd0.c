/*
 * Semantic name: appendSmallString
 * Address: 0x180008dd0
 * Module: cpp-runtime
 * Confidence: medium
 * Summary: Appends bytes to an MSVC small-string value.
 * Ghidra function: appendSmallString
 * Callers:
 *   - FUN_180003ad0 @ 0x180003ad0
 *   - FUN_1800067f0 @ 0x1800067f0
 *   - FUN_18000e0f0 @ 0x18000e0f0
 *   - FUN_18000ee60 @ 0x18000ee60
 *   - FUN_18000f2c0 @ 0x18000f2c0
 *   - FUN_18000f790 @ 0x18000f790
 *   - FUN_180011650 @ 0x180011650
 *   - FUN_180012680 @ 0x180012680
 *   - FUN_180015340 @ 0x180015340
 *   - FUN_180015910 @ 0x180015910
 *   - FUN_180016f40 @ 0x180016f40
 *   - FUN_180018e70 @ 0x180018e70
 *   - FUN_180019420 @ 0x180019420
 *   - beginPalletItemGrant @ 0x18001b510
 *   - FUN_180026f00 @ 0x180026f00
 *   - FUN_180034df0 @ 0x180034df0
 *   - FUN_180036660 @ 0x180036660
 *   - FUN_180037680 @ 0x180037680
 *   - FUN_18003a9f0 @ 0x18003a9f0
 *   - initializeRenderBridge @ 0x18003ade0
 *   - FUN_18003b390 @ 0x18003b390
 *   - FUN_18005d0e0 @ 0x18005d0e0
 *   - FUN_180067210 @ 0x180067210
 *   - FUN_180068550 @ 0x180068550
 *   - FUN_180068bb0 @ 0x180068bb0
 *   - FUN_180068e00 @ 0x180068e00
 *   - FUN_18006b8f0 @ 0x18006b8f0
 * Callees:
 *   - FUN_180009460 @ 0x180009460
 *   - memmove @ 0x1800cf430
 */


/* Appends bytes to an MSVC small-string value. */

longlong * appendSmallString(longlong *param_1,void *param_2,size_t param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong *plVar3;
  
  lVar1 = param_1[2];
  uVar2 = param_1[3];
  if (uVar2 - lVar1 < param_3) {
    plVar3 = (longlong *)FUN_180009460(param_1,param_3,uVar2,param_2,param_3);
    return plVar3;
  }
  param_1[2] = lVar1 + param_3;
  plVar3 = param_1;
  if (0xf < uVar2) {
    plVar3 = (longlong *)*param_1;
  }
  memmove((void *)(lVar1 + (longlong)plVar3),param_2,param_3);
  *(undefined1 *)(lVar1 + (longlong)plVar3 + param_3) = 0;
  return param_1;
}

