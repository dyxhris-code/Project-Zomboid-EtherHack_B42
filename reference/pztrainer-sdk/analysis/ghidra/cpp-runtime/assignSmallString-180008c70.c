/*
 * Semantic name: assignSmallString
 * Address: 0x180008c70
 * Module: cpp-runtime
 * Confidence: high
 * Summary: Assigns bytes to an MSVC small-string value.
 * Ghidra function: assignSmallString
 * Callers:
 *   - FUN_180003800 @ 0x180003800
 *   - FUN_180003940 @ 0x180003940
 *   - FUN_180003ad0 @ 0x180003ad0
 *   - FUN_180007c50 @ 0x180007c50
 *   - FUN_18000a9f0 @ 0x18000a9f0
 *   - FUN_18000b1b0 @ 0x18000b1b0
 *   - FUN_18000b8a0 @ 0x18000b8a0
 *   - FUN_18000be40 @ 0x18000be40
 *   - FUN_18000c190 @ 0x18000c190
 *   - FUN_18000cc00 @ 0x18000cc00
 *   - FUN_18000e0f0 @ 0x18000e0f0
 *   - FUN_180010480 @ 0x180010480
 *   - FUN_180011650 @ 0x180011650
 *   - FUN_180015340 @ 0x180015340
 *   - FUN_180015910 @ 0x180015910
 *   - FUN_180016b70 @ 0x180016b70
 *   - FUN_180016f40 @ 0x180016f40
 *   - FUN_1800181c0 @ 0x1800181c0
 *   - FUN_180018e70 @ 0x180018e70
 *   - FUN_180019420 @ 0x180019420
 *   - FUN_180019ac0 @ 0x180019ac0
 *   - selectSafePalletCarrier @ 0x18001a940
 *   - sendDisposablePallet @ 0x18001aba0
 *   - beginPalletItemGrant @ 0x18001b510
 *   - pollPalletItemGrant @ 0x18001bc80
 *   - FUN_18001c3a0 @ 0x18001c3a0
 *   - FUN_18001db90 @ 0x18001db90
 *   - FUN_18001e8d0 @ 0x18001e8d0
 *   - FUN_18001ec30 @ 0x18001ec30
 *   - FUN_18001ef80 @ 0x18001ef80
 *   - FUN_18001f250 @ 0x18001f250
 *   - FUN_180020810 @ 0x180020810
 *   - FUN_180020b80 @ 0x180020b80
 *   - FUN_180020f50 @ 0x180020f50
 *   - FUN_180021450 @ 0x180021450
 *   - FUN_180021c30 @ 0x180021c30
 *   - FUN_180022970 @ 0x180022970
 *   - FUN_180024860 @ 0x180024860
 *   - FUN_180026f00 @ 0x180026f00
 *   - FUN_180029010 @ 0x180029010
 *   - FUN_18002d480 @ 0x18002d480
 *   - FUN_18002d670 @ 0x18002d670
 *   - FUN_180034550 @ 0x180034550
 *   - FUN_18004a050 @ 0x18004a050
 *   - FUN_18004b190 @ 0x18004b190
 *   - FUN_18004bc00 @ 0x18004bc00
 *   - FUN_18005ca20 @ 0x18005ca20
 *   - FUN_18005d0e0 @ 0x18005d0e0
 *   - FUN_18005d470 @ 0x18005d470
 *   - FUN_18005fc90 @ 0x18005fc90
 *   - FUN_180060080 @ 0x180060080
 *   - FUN_180066f60 @ 0x180066f60
 *   - FUN_180067210 @ 0x180067210
 *   - FUN_180069e10 @ 0x180069e10
 *   - FUN_180069ed0 @ 0x180069ed0
 * Callees:
 *   - FUN_180001ac0 @ 0x180001ac0
 *   - FUN_180001b60 @ 0x180001b60
 *   - FUN_1800cd540 @ 0x1800cd540
 *   - free @ 0x1800cd8ec
 *   - memcpy @ 0x1800cf42a
 *   - memmove @ 0x1800cf430
 */


/* Assigns bytes to an MSVC small-string value. */

longlong * assignSmallString(longlong *param_1,void *param_2,size_t param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  void *pvVar3;
  code *pcVar4;
  longlong lVar5;
  ulonglong uVar6;
  void *_Memory;
  undefined1 *puVar7;
  longlong *_Dst;
  ulonglong uVar8;
  void *unaff_R14;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  uVar2 = param_1[3];
  if (param_3 <= uVar2) {
    _Dst = param_1;
    if (0xf < uVar2) {
      _Dst = (longlong *)*param_1;
    }
    param_1[2] = param_3;
    memmove(_Dst,param_2,param_3);
    *(undefined1 *)(param_3 + (longlong)_Dst) = 0;
    return param_1;
  }
  uVar8 = 0x7fffffffffffffff;
  if (0x7fffffffffffffff < param_3) {
                    /* WARNING: Subroutine does not return */
    FUN_180001b60();
  }
  uVar6 = param_3 | 0xf;
  if ((uVar6 < 0x8000000000000000) && (uVar2 <= 0x7fffffffffffffff - (uVar2 >> 1))) {
    uVar1 = (uVar2 >> 1) + uVar2;
    uVar8 = uVar6;
    if (uVar6 < uVar1) {
      uVar8 = uVar1;
    }
    uVar1 = uVar8 + 1;
    if (uVar1 == 0) {
      unaff_R14 = (void *)0x0;
    }
    else {
      if (0xfff < uVar1) {
        uVar6 = uVar8 + 0x28;
        if (uVar6 <= uVar1) {
                    /* WARNING: Subroutine does not return */
          FUN_180001ac0();
        }
        goto LAB_180008d2b;
      }
      unaff_R14 = (void *)FUN_1800cd540(uVar1);
    }
LAB_180008d4e:
    param_1[2] = param_3;
    param_1[3] = uVar8;
    memcpy(unaff_R14,param_2,param_3);
    *(undefined1 *)((longlong)unaff_R14 + param_3) = 0;
    if (uVar2 < 0x10) goto LAB_180008da8;
    pvVar3 = (void *)*param_1;
    _Memory = pvVar3;
    puVar7 = auStack_48;
    if ((0xfff < uVar2 + 1) &&
       (_Memory = *(void **)((longlong)pvVar3 + -8), puVar7 = auStack_48,
       0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)_Memory)))) goto LAB_180008d96;
  }
  else {
    uVar6 = 0x8000000000000027;
LAB_180008d2b:
    lVar5 = FUN_1800cd540(uVar6);
    if (lVar5 != 0) {
      unaff_R14 = (void *)(lVar5 + 0x27U & 0xffffffffffffffe0);
      *(longlong *)((longlong)unaff_R14 - 8) = lVar5;
      goto LAB_180008d4e;
    }
LAB_180008d96:
    _Memory = (void *)0x5;
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)();
    puVar7 = auStack_40;
  }
  *(undefined8 *)(puVar7 + -8) = 0x180008da8;
  free(_Memory);
LAB_180008da8:
  *param_1 = (longlong)unaff_R14;
  return param_1;
}

