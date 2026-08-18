/*
 * Semantic name: invokeLuaBoundMethod
 * Address: 0x180025840
 * Module: jni-helpers
 * Confidence: high
 * Summary: Invokes a named Lua-bound Java method with a dynamically assembled argument list.
 * Ghidra function: invokeLuaBoundMethod
 * Callers:
 *   - FUN_18000e0f0 @ 0x18000e0f0
 *   - FUN_180011650 @ 0x180011650
 *   - FUN_1800150c0 @ 0x1800150c0
 *   - FUN_180015340 @ 0x180015340
 *   - FUN_180015910 @ 0x180015910
 *   - FUN_180016840 @ 0x180016840
 *   - FUN_1800168d0 @ 0x1800168d0
 *   - FUN_180016f40 @ 0x180016f40
 *   - FUN_1800180e0 @ 0x1800180e0
 *   - FUN_1800181c0 @ 0x1800181c0
 *   - FUN_1800187b0 @ 0x1800187b0
 *   - FUN_180018b30 @ 0x180018b30
 *   - FUN_180018ca0 @ 0x180018ca0
 *   - FUN_180019ac0 @ 0x180019ac0
 *   - sendDisposablePallet @ 0x18001aba0
 *   - findReturnedPallet @ 0x18001aee0
 *   - submitTakeBricksAction @ 0x18001b260
 *   - FUN_1800206e0 @ 0x1800206e0
 *   - FUN_180020810 @ 0x180020810
 *   - FUN_180021450 @ 0x180021450
 *   - FUN_180026f00 @ 0x180026f00
 * Callees:
 *   - FUN_1800017e0 @ 0x1800017e0
 *   - jniCallObjectMethodWithIntArg @ 0x180001810
 *   - jniCallStaticObjectMethodOneArg @ 0x180001930
 *   - FUN_180009bb0 @ 0x180009bb0
 *   - FUN_180025530 @ 0x180025530
 * Referenced strings:
 *   - getValue
 */


/* Invokes a named Lua-bound Java method with a dynamically assembled argument list. */

longlong invokeLuaBoundMethod
                   (longlong *param_1,longlong param_2,longlong param_3,longlong *param_4,
                   undefined1 *param_5)

{
  undefined8 *puVar1;
  int iVar2;
  char cVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 *puVar9;
  
  if (param_5 != (undefined1 *)0x0) {
    *param_5 = 0;
  }
  if (param_1 == (longlong *)0x0) {
    return 0;
  }
  if (param_2 == 0) {
    return 0;
  }
  if (param_3 == 0) {
    return 0;
  }
  uVar4 = FUN_180025530(param_1);
  if ((char)uVar4 == '\0') {
    return 0;
  }
  puVar9 = (undefined8 *)*param_4;
  puVar1 = (undefined8 *)param_4[1];
  lVar5 = (**(code **)(*param_1 + 0x560))
                    (param_1,(longlong)puVar1 - (longlong)puVar9 >> 3,DAT_180102240,0);
  iVar2 = 0;
  for (; puVar9 != puVar1; puVar9 = puVar9 + 1) {
    (**(code **)(*param_1 + 0x570))(param_1,lVar5,iVar2,*puVar9);
    iVar2 = iVar2 + 1;
  }
  lVar6 = (**(code **)(*param_1 + 0x538))(param_1,param_3);
  if ((lVar5 == 0) || (lVar6 == 0)) {
    lVar7 = 0;
    if (lVar5 != 0) goto LAB_180025952;
  }
  else {
    lVar7 = FUN_1800017e0(param_1);
LAB_180025952:
    (**(code **)(*param_1 + 0xb8))(param_1,lVar5);
  }
  if (lVar6 != 0) {
    (**(code **)(*param_1 + 0xb8))(param_1,lVar6);
  }
  if (lVar7 == 0) {
    return 0;
  }
  cVar3 = (**(code **)(*param_1 + 0x720))(param_1);
  lVar5 = *param_1;
  lVar6 = lVar7;
  if (cVar3 == '\0') {
    lVar5 = (**(code **)(lVar5 + 0x538))(param_1,"getValue");
    if (lVar5 == 0) goto LAB_180025ac5;
    lVar8 = jniCallStaticObjectMethodOneArg(param_1);
    (**(code **)(*param_1 + 0xb8))(param_1,lVar5);
    if (lVar8 == 0) goto LAB_180025ac5;
    cVar3 = (**(code **)(*param_1 + 0x720))(param_1);
    if (cVar3 != '\0') {
      (**(code **)(*param_1 + 0x88))();
      (**(code **)(*param_1 + 0xb8))(param_1,lVar8);
      goto LAB_180025ac5;
    }
    FUN_180009bb0(param_1);
    (**(code **)(*param_1 + 0xb8))(param_1,lVar8);
    cVar3 = (**(code **)(*param_1 + 0x720))(param_1);
    if (cVar3 == '\0') {
      lVar6 = jniCallObjectMethodWithIntArg(param_1);
      cVar3 = (**(code **)(*param_1 + 0x720))(param_1);
      if (cVar3 == '\0') {
        (**(code **)(*param_1 + 0xb8))(param_1,lVar7);
        if (param_5 != (undefined1 *)0x0) {
          *param_5 = 1;
          return lVar6;
        }
        return lVar6;
      }
      (**(code **)(*param_1 + 0x88))(param_1);
      (**(code **)(*param_1 + 0xb8))(param_1,lVar7);
      if (lVar6 == 0) {
        return 0;
      }
      goto LAB_180025ac5;
    }
    lVar5 = *param_1;
  }
  (**(code **)(lVar5 + 0x88))();
LAB_180025ac5:
  (**(code **)(*param_1 + 0xb8))(param_1,lVar6);
  return 0;
}

