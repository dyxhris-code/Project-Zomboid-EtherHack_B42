/*
 * Semantic name: sendDisposablePallet
 * Address: 0x18001aba0
 * Module: item-grant
 * Confidence: high
 * Summary: Creates, marks, serializes, and sends an AddExplosiveTrapPacket carrier.
 * Ghidra function: sendDisposablePallet
 * Callers:
 *   - beginPalletItemGrant @ 0x18001b510
 * Callees:
 *   - jniCallIntMethod @ 0x1800018a0
 *   - jniCallVoidMethodWithIntArg @ 0x180001900
 *   - jniCallStaticObjectMethodOneArg @ 0x180001930
 *   - assignSmallString @ 0x180008c70
 *   - readSteadyClockTimePoint @ 0x180009be0
 *   - invokeLuaBoundMethod @ 0x180025840
 * Referenced strings:
 *   - getCurrentSquare
 *   - sendToServer
 */


/* Creates, marks, serializes, and sends an AddExplosiveTrapPacket carrier. */

ulonglong sendDisposablePallet(longlong *param_1,longlong param_2)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  undefined4 uVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  longlong *plVar11;
  undefined8 *puVar12;
  char local_res8 [8];
  longlong local_res18;
  undefined1 local_res20 [8];
  longlong *local_68;
  undefined1 *puStack_60;
  longlong local_58;
  longlong local_50;
  longlong local_48;
  undefined1 local_40 [8];
  
  puVar12 = &selectedCarrierType;
  if (0xf < DAT_1800ffcb0) {
    puVar12 = selectedCarrierType;
  }
  lVar5 = (**(code **)(*param_1 + 0x538))(param_1,puVar12);
  uVar7 = 0;
  if (lVar5 == 0) goto LAB_18001ac3b;
  lVar6 = jniCallStaticObjectMethodOneArg(param_1);
  uVar7 = (**(code **)(*param_1 + 0xb8))(param_1,lVar5);
  if (lVar6 == 0) goto LAB_18001ac3b;
  cVar3 = (**(code **)(*param_1 + 0x720))(param_1);
  if (cVar3 == '\0') {
    jniCallVoidMethodWithIntArg(param_1);
    uVar4 = jniCallIntMethod(param_1);
    local_res8[0] = (**(code **)(*param_1 + 0x720))(param_1);
    if (local_res8[0] == '\0') {
      local_68 = (longlong *)0x0;
      puStack_60 = (undefined1 *)0x0;
      lVar5 = invokeLuaBoundMethod(param_1,param_2,0x1800ddb48,(longlong *)&local_68,local_res8);
      if ((local_res8[0] == '\0') || (lVar5 == 0)) {
        lVar8 = 0;
      }
      else {
        local_68 = (longlong *)0x0;
        puStack_60 = (undefined1 *)0x0;
        lVar8 = invokeLuaBoundMethod
                          (param_1,classAddExplosiveTrapPacket,0x1800dec04,(longlong *)&local_68,
                           local_res8);
      }
      if ((local_res8[0] == '\0') || (lVar8 == 0)) {
LAB_18001ae05:
        lVar9 = 0;
LAB_18001ae07:
        bVar1 = false;
        bVar2 = false;
        if (lVar9 != 0) goto LAB_18001ae0f;
      }
      else {
        local_68 = &local_58;
        puStack_60 = local_40;
        local_res8[0] = '\0';
        local_58 = lVar6;
        local_50 = param_2;
        local_48 = lVar5;
        lVar9 = invokeLuaBoundMethod(param_1,lVar8,0x1800dec7c,(longlong *)&local_68,local_res8);
        if (lVar9 != 0) {
          (**(code **)(*param_1 + 0xb8))(param_1,lVar9);
        }
        if (local_res8[0] == '\0') goto LAB_18001ae05;
        lVar9 = (**(code **)(*param_1 + 0x488))
                          (param_1,classPacketType,fieldPacketTypeAddExplosiveTrap);
        if (lVar9 == 0) goto LAB_18001ae07;
        cVar3 = (**(code **)(*param_1 + 0x720))(param_1);
        if (cVar3 != '\0') {
          (**(code **)(*param_1 + 0x88))();
          goto LAB_18001ae07;
        }
        local_68 = &local_res18;
        puStack_60 = local_res20;
        local_res8[0] = '\0';
        local_res18 = lVar9;
        lVar10 = invokeLuaBoundMethod(param_1,lVar8,0x1800deb98,(longlong *)&local_68,local_res8);
        if (lVar10 != 0) {
          (**(code **)(*param_1 + 0xb8))(param_1,lVar10);
        }
        if (local_res8[0] == '\0') goto LAB_18001ae07;
        bVar2 = true;
LAB_18001ae0f:
        bVar1 = bVar2;
        (**(code **)(*param_1 + 0xb8))(param_1,lVar9);
      }
      if (lVar8 != 0) {
        (**(code **)(*param_1 + 0xb8))(param_1,lVar8);
      }
      if (lVar5 != 0) {
        (**(code **)(*param_1 + 0xb8))(param_1,lVar5);
      }
      uVar7 = (**(code **)(*param_1 + 0xb8))(param_1,lVar6);
      if (bVar1) {
        pendingGrantState = 1;
        carrierItemId = uVar4;
        plVar11 = readSteadyClockTimePoint((longlong *)local_res8);
        nextGrantPollAt = *plVar11 + 150000000;
        plVar11 = readSteadyClockTimePoint((longlong *)local_res8);
        grantDeadline = *plVar11 + 5000000000;
        plVar11 = assignSmallString(&grantStatusMessage,&DAT_1800e03a8,0x36);
        return CONCAT71((int7)((ulonglong)plVar11 >> 8),1);
      }
      goto LAB_18001ac3b;
    }
  }
  (**(code **)(*param_1 + 0x88))();
  uVar7 = (**(code **)(*param_1 + 0xb8))(param_1,lVar6);
LAB_18001ac3b:
  return uVar7 & 0xffffffffffffff00;
}

