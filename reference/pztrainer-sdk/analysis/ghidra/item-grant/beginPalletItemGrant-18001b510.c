/*
 * Semantic name: beginPalletItemGrant
 * Address: 0x18001b510
 * Module: item-grant
 * Confidence: high
 * Summary: Validates the request, starts carrier delivery, and initializes the polling state.
 * Ghidra function: beginPalletItemGrant
 * Callers:
 *   - FUN_180011650 @ 0x180011650
 *   - FUN_180020f50 @ 0x180020f50
 * Callees:
 *   - jniCallStaticObjectMethodOneArg @ 0x180001930
 *   - copySmallString @ 0x180007c90
 *   - destroySmallString @ 0x180008440
 *   - assignSmallString @ 0x180008c70
 *   - appendSmallString @ 0x180008dd0
 *   - readSteadyClockTimePoint @ 0x180009be0
 *   - FUN_18000d010 @ 0x18000d010
 *   - FUN_1800142e0 @ 0x1800142e0
 *   - initializePalletGrantBridge @ 0x18001a3e0
 *   - selectSafePalletCarrier @ 0x18001a940
 *   - sendDisposablePallet @ 0x18001aba0
 *   - findReturnedPallet @ 0x18001aee0
 *   - submitTakeBricksAction @ 0x18001b260
 *   - __security_check_cookie @ 0x1800cd520
 *   - memcpy @ 0x1800cf42a
 *   - memmove @ 0x1800cf430
 */


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Validates the request, starts carrier delivery, and initializes the polling state. */

uint beginPalletItemGrant
               (longlong *param_1,longlong param_2,undefined8 *param_3,uint param_4,
               longlong *param_5)

{
  size_t *psVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  uint *puVar7;
  uint *puVar8;
  longlong *plVar9;
  undefined8 *puVar10;
  undefined *puVar11;
  longlong *_Src;
  size_t sVar12;
  longlong lVar13;
  longlong *_Size;
  undefined1 auStackY_178 [32];
  longlong local_140 [8];
  undefined4 local_100;
  undefined4 local_fc;
  longlong local_f8;
  longlong lStack_f0;
  uint local_e8 [2];
  uint local_e0 [2];
  longlong local_d8;
  longlong lStack_d0;
  longlong local_c8;
  longlong lStack_c0;
  longlong local_b8;
  longlong lStack_b0;
  longlong local_a8;
  longlong lStack_a0;
  longlong local_98;
  longlong lStack_90;
  longlong local_88;
  longlong lStack_80;
  longlong local_78 [4];
  uint local_58 [2];
  ulonglong local_50;
  
  local_50 = DAT_1800ff040 ^ (ulonglong)auStackY_178;
  local_58[0] = param_4;
  plVar9 = param_5;
  if (((param_1 == (longlong *)0x0) || (param_2 == 0)) ||
     (uVar4 = initializePalletGrantBridge(param_1), (char)uVar4 == '\0')) {
    sVar12 = 0x21;
    param_5 = (longlong *)&DAT_1800e03f0;
  }
  else if (pendingGrantState == 0) {
    puVar10 = param_3;
    if (0xf < (ulonglong)param_3[3]) {
      puVar10 = (undefined8 *)*param_3;
    }
    lVar5 = (**(code **)(*param_1 + 0x538))(param_1,puVar10);
    if (lVar5 != 0) {
      lVar13 = lVar5;
      lVar6 = jniCallStaticObjectMethodOneArg(param_1);
      (**(code **)(*param_1 + 0xb8))(param_1,lVar5);
      if (lVar6 != 0) {
        cVar2 = (**(code **)(*param_1 + 0x720))(param_1);
        if (cVar2 == '\0') {
          (**(code **)(*param_1 + 0xb8))(param_1,lVar6);
          local_140[1] = 0;
          local_140[2] = 0;
          local_140[3] = 0xf;
          local_140[0] = 0;
          local_140[5] = 0;
          local_140[6] = 0;
          local_140[7] = 0xf;
          local_140[4] = 0;
          local_100 = 0;
          local_fc = 0xffffffff;
          local_f8 = 0;
          lStack_f0 = 0;
          pendingGrantState = 0;
          copySmallString(&requestedItemType,local_140);
          copySmallString(&selectedCarrierType,local_140 + 4);
          requestedItemAmount = local_100;
          carrierItemId = local_fc;
          nextGrantPollAt = local_f8;
          grantDeadline = lStack_f0;
          destroySmallString(local_140 + 4);
          destroySmallString(local_140);
          if (param_3 != &requestedItemType) {
            puVar10 = param_3;
            if (0xf < (ulonglong)param_3[3]) {
              puVar10 = (undefined8 *)*param_3;
            }
            assignSmallString(&requestedItemType,puVar10,param_3[2]);
          }
          local_e8[0] = 100;
          local_e0[0] = 1;
          puVar8 = local_e0;
          if (0 < (int)param_4) {
            puVar8 = local_58;
          }
          puVar7 = local_e8;
          if ((int)param_4 < 0x65) {
            puVar7 = puVar8;
          }
          requestedItemAmount = *puVar7;
          uVar4 = selectSafePalletCarrier(param_1,&selectedCarrierType);
          if ((char)uVar4 == '\0') {
            local_140[1] = 0;
            local_140[2] = 0;
            local_140[3] = 0xf;
            local_140[0] = 0;
            local_140[5] = 0;
            local_140[6] = 0;
            local_140[7] = 0xf;
            local_140[4] = 0;
            local_100 = 0;
            local_fc = 0xffffffff;
            local_f8 = 0;
            lStack_f0 = 0;
            pendingGrantState = 0;
            copySmallString(&requestedItemType,local_140);
            copySmallString(&selectedCarrierType,local_140 + 4);
            requestedItemAmount = local_100;
            carrierItemId = local_fc;
            nextGrantPollAt = local_f8;
            grantDeadline = lStack_f0;
            destroySmallString(local_140 + 4);
            destroySmallString(local_140);
            sVar12 = 0x3c;
            puVar11 = &DAT_1800e0478;
          }
          else {
            lVar5 = findReturnedPallet(param_1,param_2);
            if (lVar5 == 0) {
              uVar4 = sendDisposablePallet(param_1,param_2);
              if ((char)uVar4 != '\0') goto LAB_18001b962;
              local_140[1] = 0;
              local_140[2] = 0;
              local_140[3] = 0xf;
              local_140[0] = 0;
              local_140[5] = 0;
              local_140[6] = 0;
              local_140[7] = 0xf;
              local_140[4] = 0;
              local_100 = 0;
              local_fc = 0xffffffff;
              local_f8 = 0;
              lStack_f0 = 0;
              pendingGrantState = 0;
              copySmallString(&requestedItemType,local_140);
              copySmallString(&selectedCarrierType,local_140 + 4);
              requestedItemAmount = local_100;
              carrierItemId = local_fc;
              nextGrantPollAt = local_f8;
              grantDeadline = lStack_f0;
              destroySmallString(local_140 + 4);
              destroySmallString(local_140);
              sVar12 = 0x2a;
              puVar11 = &DAT_1800e04f0;
            }
            else {
              uVar4 = submitTakeBricksAction(param_1,param_2,lVar5);
              (**(code **)(*param_1 + 0xb8))(param_1,lVar5);
              if ((char)uVar4 != '\0') {
                pendingGrantState = 2;
                plVar9 = readSteadyClockTimePoint((longlong *)local_e8);
                nextGrantPollAt = *plVar9 + 150000000;
                iVar3 = requestedItemAmount * 0xfa;
                plVar9 = readSteadyClockTimePoint((longlong *)local_e8);
                grantDeadline = ((longlong)iVar3 + 8000) * 1000000 + *plVar9;
LAB_18001b962:
                plVar9 = FUN_18000d010(local_78,requestedItemAmount);
                lVar5 = plVar9[2];
                if ((ulonglong)(plVar9[3] - lVar5) < 0x28) {
                  plVar9 = (longlong *)FUN_1800142e0(plVar9,0x28,lVar5,lVar13,&DAT_1800e0528,0x28);
                }
                else {
                  plVar9[2] = lVar5 + 0x28;
                  _Src = plVar9;
                  if (0xf < (ulonglong)plVar9[3]) {
                    _Src = (longlong *)*plVar9;
                  }
                  if ((&UNK_1800e054f < _Src) ||
                     ((undefined *)((longlong)_Src + lVar5) < &DAT_1800e0528)) {
                    _Size = (longlong *)0x28;
                  }
                  else if (&DAT_1800e0528 < _Src) {
                    _Size = _Src + -0x3001c0a5;
                  }
                  else {
                    _Size = (longlong *)0x0;
                  }
                  memmove(_Src + 5,_Src,lVar5 + 1);
                  memcpy(_Src,&DAT_1800e0528,(size_t)_Size);
                  memcpy((undefined *)((longlong)_Src + (longlong)_Size),_Size + 0x3001c0aa,
                         0x28 - (longlong)_Size);
                }
                local_b8 = *plVar9;
                lStack_b0 = plVar9[1];
                local_a8 = plVar9[2];
                lStack_a0 = plVar9[3];
                plVar9[2] = 0;
                plVar9[3] = 0xf;
                *(undefined1 *)plVar9 = 0;
                plVar9 = appendSmallString(&local_b8,&DAT_1800e051c,5);
                local_d8 = *plVar9;
                lStack_d0 = plVar9[1];
                local_c8 = plVar9[2];
                lStack_c0 = plVar9[3];
                plVar9[2] = 0;
                plVar9[3] = 0xf;
                *(undefined1 *)plVar9 = 0;
                psVar1 = param_3 + 2;
                if (0xf < (ulonglong)param_3[3]) {
                  param_3 = (undefined8 *)*param_3;
                }
                plVar9 = appendSmallString(&local_d8,param_3,*psVar1);
                local_98 = *plVar9;
                lStack_90 = plVar9[1];
                local_88 = plVar9[2];
                lStack_80 = plVar9[3];
                plVar9[2] = 0;
                plVar9[3] = 0xf;
                *(undefined1 *)plVar9 = 0;
                copySmallString(param_5,&local_98);
                destroySmallString(&local_98);
                destroySmallString(&local_d8);
                destroySmallString(&local_b8);
                destroySmallString(local_78);
                if (param_5 != &grantStatusMessage) {
                  psVar1 = (size_t *)(param_5 + 2);
                  if (0xf < (ulonglong)param_5[3]) {
                    param_5 = (longlong *)*param_5;
                  }
                  assignSmallString(&grantStatusMessage,param_5,*psVar1);
                  return requestedItemAmount;
                }
                return requestedItemAmount;
              }
              local_140[1] = 0;
              local_140[2] = 0;
              local_140[3] = 0xf;
              local_140[0] = 0;
              local_140[5] = 0;
              local_140[6] = 0;
              local_140[7] = 0xf;
              local_140[4] = 0;
              local_100 = 0;
              local_fc = 0xffffffff;
              local_f8 = 0;
              lStack_f0 = 0;
              pendingGrantState = 0;
              copySmallString(&requestedItemType,local_140);
              copySmallString(&selectedCarrierType,local_140 + 4);
              requestedItemAmount = local_100;
              carrierItemId = local_fc;
              nextGrantPollAt = local_f8;
              grantDeadline = lStack_f0;
              destroySmallString(local_140 + 4);
              destroySmallString(local_140);
              sVar12 = 0x33;
              puVar11 = &DAT_1800e04b8;
            }
          }
          assignSmallString(param_5,puVar11,sVar12);
          plVar9 = &grantStatusMessage;
          if (param_5 == &grantStatusMessage) {
            return 0;
          }
          sVar12 = param_5[2];
          if (0xf < (ulonglong)param_5[3]) {
            param_5 = (longlong *)*param_5;
          }
          goto LAB_18001bc4a;
        }
        (**(code **)(*param_1 + 0x88))();
        (**(code **)(*param_1 + 0xb8))(param_1,lVar6);
      }
    }
    sVar12 = 0x30;
    param_5 = (longlong *)&DAT_1800e0440;
  }
  else {
    sVar12 = 0x27;
    param_5 = (longlong *)&DAT_1800e0418;
  }
LAB_18001bc4a:
  assignSmallString(plVar9,param_5,sVar12);
  return 0;
}

