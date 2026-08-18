/*
 * Semantic name: submitTakeBricksAction
 * Address: 0x18001b260
 * Module: item-grant
 * Confidence: high
 * Summary: Calls ISTakeBricks.createNewAndSend with player, pallet, square, type, and amount.
 * Ghidra function: submitTakeBricksAction
 * Callers:
 *   - beginPalletItemGrant @ 0x18001b510
 *   - pollPalletItemGrant @ 0x18001bc80
 * Callees:
 *   - jniCallStaticObjectMethodOneArg @ 0x180001930
 *   - invokeLuaBoundMethod @ 0x180025840
 * Referenced strings:
 *   - getSquare
 *   - ISTakeBricks
 *   - createNewAndSend
 */


/* Calls ISTakeBricks.createNewAndSend with player, pallet, square, type, and amount. */

undefined8 submitTakeBricksAction(longlong *param_1,undefined8 param_2,longlong param_3)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  char local_res8 [32];
  longlong *local_78;
  undefined1 *puStack_70;
  longlong local_68;
  undefined8 local_60;
  longlong local_58;
  undefined1 local_50 [16];
  
  local_res8[0] = '\0';
  local_78 = (longlong *)0x0;
  puStack_70 = (undefined1 *)0x0;
  lVar2 = invokeLuaBoundMethod(param_1,param_3,0x1800def38,(longlong *)&local_78,local_res8);
  lVar3 = (**(code **)(*param_1 + 0x538))(param_1,"ISTakeBricks");
  puVar8 = &requestedItemType;
  if (0xf < DAT_1800ffc90) {
    puVar8 = requestedItemType;
  }
  lVar4 = (**(code **)(*param_1 + 0x538))(param_1,puVar8);
  lVar5 = jniCallStaticObjectMethodOneArg(param_1);
  lVar6 = (**(code **)(*param_1 + 0x560))(param_1,6,classJavaObject,0);
  if (lVar6 != 0) {
    (**(code **)(*param_1 + 0x570))(param_1,lVar6,0,param_2);
    (**(code **)(*param_1 + 0x570))(param_1,lVar6,1,param_3);
    (**(code **)(*param_1 + 0x570))(param_1,lVar6,2,lVar2);
    (**(code **)(*param_1 + 0x570))(param_1,lVar6,3,0);
    (**(code **)(*param_1 + 0x570))(param_1,lVar6,4,lVar4);
    (**(code **)(*param_1 + 0x570))(param_1,lVar6,5,lVar5);
  }
  if ((((local_res8[0] == '\0') || (lVar2 == 0)) || (lVar3 == 0)) ||
     (((lVar4 == 0 || (lVar5 == 0)) || (lVar6 == 0)))) {
LAB_18001b40a:
    uVar9 = 0;
    if (lVar6 == 0) goto LAB_18001b421;
  }
  else {
    cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 0x88))();
      goto LAB_18001b40a;
    }
    local_78 = &local_68;
    puStack_70 = local_50;
    local_res8[0] = '\0';
    local_68 = lVar3;
    local_60 = param_2;
    local_58 = lVar6;
    lVar7 = invokeLuaBoundMethod
                      (param_1,classNetTimedActionPacket,0x1800df5f8,(longlong *)&local_78,
                       local_res8);
    if (lVar7 != 0) {
      (**(code **)(*param_1 + 0xb8))(param_1,lVar7);
    }
    if (local_res8[0] == '\0') goto LAB_18001b40a;
    uVar9 = 1;
  }
  (**(code **)(*param_1 + 0xb8))(param_1,lVar6);
LAB_18001b421:
  if (lVar5 != 0) {
    (**(code **)(*param_1 + 0xb8))(param_1,lVar5);
  }
  if (lVar4 != 0) {
    (**(code **)(*param_1 + 0xb8))(param_1,lVar4);
  }
  if (lVar3 != 0) {
    (**(code **)(*param_1 + 0xb8))(param_1,lVar3);
  }
  if (lVar2 != 0) {
    (**(code **)(*param_1 + 0xb8))(param_1,lVar2);
  }
  return uVar9;
}

