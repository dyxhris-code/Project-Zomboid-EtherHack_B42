/*
 * Semantic name: copySmallString
 * Address: 0x180007c90
 * Module: cpp-runtime
 * Confidence: medium
 * Summary: Copies an MSVC small-string value.
 * Ghidra function: copySmallString
 * Callers:
 *   - FUN_180003ad0 @ 0x180003ad0
 *   - FUN_18000e0f0 @ 0x18000e0f0
 *   - FUN_18000ec20 @ 0x18000ec20
 *   - FUN_180011650 @ 0x180011650
 *   - FUN_180013270 @ 0x180013270
 *   - FUN_180013b20 @ 0x180013b20
 *   - FUN_180013b90 @ 0x180013b90
 *   - FUN_180014710 @ 0x180014710
 *   - FUN_180015340 @ 0x180015340
 *   - FUN_180015910 @ 0x180015910
 *   - FUN_180016b70 @ 0x180016b70
 *   - FUN_180016f40 @ 0x180016f40
 *   - FUN_1800181c0 @ 0x1800181c0
 *   - FUN_180018e70 @ 0x180018e70
 *   - FUN_180019420 @ 0x180019420
 *   - FUN_180019ac0 @ 0x180019ac0
 *   - beginPalletItemGrant @ 0x18001b510
 *   - pollPalletItemGrant @ 0x18001bc80
 *   - FUN_180026f00 @ 0x180026f00
 *   - FUN_18004bc00 @ 0x18004bc00
 *   - FUN_18004c4b0 @ 0x18004c4b0
 *   - FUN_18004e1e0 @ 0x18004e1e0
 *   - FUN_180067210 @ 0x180067210
 * Callees:
 *   - free @ 0x1800cd8ec
 */


/* Copies an MSVC small-string value. */

longlong * copySmallString(longlong *param_1,longlong *param_2)

{
  void *pvVar1;
  code *pcVar2;
  longlong lVar3;
  void *_Memory;
  undefined1 *puVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (param_1 != param_2) {
    if (0xf < (ulonglong)param_1[3]) {
      pvVar1 = (void *)*param_1;
      _Memory = pvVar1;
      puVar4 = auStack_28;
      if ((0xfff < param_1[3] + 1U) &&
         (_Memory = *(void **)((longlong)pvVar1 + -8), puVar4 = auStack_28,
         0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
        pcVar2 = (code *)swi(0x29);
        _Memory = (void *)(*pcVar2)(5);
        puVar4 = auStack_20;
      }
      *(undefined8 *)(puVar4 + -8) = 0x180007ce4;
      free(_Memory);
    }
    param_1[3] = 0xf;
    param_1[2] = 0;
    *(undefined1 *)param_1 = 0;
    lVar3 = param_2[1];
    *param_1 = *param_2;
    param_1[1] = lVar3;
    lVar3 = param_2[3];
    param_1[2] = param_2[2];
    param_1[3] = lVar3;
    param_2[2] = 0;
    param_2[3] = 0xf;
    *(undefined1 *)param_2 = 0;
  }
  return param_1;
}

