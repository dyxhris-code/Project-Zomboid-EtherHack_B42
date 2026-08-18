/*
 * Semantic name: pollPalletItemGrant
 * Address: 0x18001bc80
 * Module: item-grant
 * Confidence: high
 * Summary: Polls for the server object, submits the native action, and handles completion or timeout.
 * Ghidra function: pollPalletItemGrant
 * Callers:
 *   - FUN_1800113d0 @ 0x1800113d0
 * Callees:
 *   - copySmallString @ 0x180007c90
 *   - destroySmallString @ 0x180008440
 *   - assignSmallString @ 0x180008c70
 *   - readSteadyClockTimePoint @ 0x180009be0
 *   - initializePalletGrantBridge @ 0x18001a3e0
 *   - findReturnedPallet @ 0x18001aee0
 *   - submitTakeBricksAction @ 0x18001b260
 *   - strlen @ 0x1800cf652
 */


/* Polls for the server object, submits the native action, and handles completion or timeout. */

void pollPalletItemGrant(longlong *param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong *plVar3;
  size_t sVar4;
  longlong lVar5;
  undefined *puVar6;
  char *_Str;
  longlong local_res8;
  longlong local_60 [8];
  int local_20;
  undefined4 local_1c;
  longlong local_18;
  longlong lStack_10;
  
  if ((((param_1 != (longlong *)0x0) && (param_2 != 0)) &&
      (uVar2 = initializePalletGrantBridge(param_1), (char)uVar2 != '\0')) &&
     ((pendingGrantState != 0 &&
      (plVar3 = readSteadyClockTimePoint(&local_res8), nextGrantPollAt <= *plVar3)))) {
    plVar3 = readSteadyClockTimePoint(&local_res8);
    if (*plVar3 < grantDeadline) {
      lVar5 = findReturnedPallet(param_1,param_2);
      if (pendingGrantState == 1) {
        if (lVar5 == 0) {
          plVar3 = readSteadyClockTimePoint(&local_res8);
          nextGrantPollAt = *plVar3 + 100000000;
          return;
        }
        uVar2 = submitTakeBricksAction(param_1,param_2,lVar5);
        (**(code **)(*param_1 + 0xb8))(param_1,lVar5);
        if ((char)uVar2 != '\0') {
          pendingGrantState = 2;
          plVar3 = readSteadyClockTimePoint(&local_res8);
          iVar1 = requestedItemAmount * 0xfa;
          nextGrantPollAt = *plVar3 + 150000000;
          plVar3 = readSteadyClockTimePoint(&local_res8);
          grantDeadline = ((longlong)iVar1 + 8000) * 1000000 + *plVar3;
          assignSmallString(&grantStatusMessage,&DAT_1800e0608,0x39);
          return;
        }
        sVar4 = 0x36;
        puVar6 = &DAT_1800e05d0;
      }
      else {
        if (lVar5 != 0) {
          (**(code **)(*param_1 + 0xb8))(param_1,lVar5);
          plVar3 = readSteadyClockTimePoint(&local_res8);
          nextGrantPollAt = *plVar3 + 150000000;
          return;
        }
        sVar4 = 0x48;
        puVar6 = &DAT_1800e0650;
      }
      assignSmallString(&grantStatusMessage,puVar6,sVar4);
      local_60[3] = 0xf;
      local_60[1] = 0;
      local_60[0] = 0;
      local_60[5] = 0;
      local_60[4] = 0;
      local_18 = 0;
      lStack_10 = 0;
      local_60[2] = 0;
      local_60[6] = 0;
      local_60[7] = 0xf;
      local_20 = 0;
      local_1c = 0xffffffff;
      pendingGrantState = 0;
      copySmallString(&requestedItemType,local_60);
      copySmallString(&selectedCarrierType,local_60 + 4);
      requestedItemAmount = local_20;
      carrierItemId = local_1c;
      nextGrantPollAt = local_18;
      grantDeadline = lStack_10;
      destroySmallString(local_60 + 4);
      destroySmallString(local_60);
    }
    else {
      _Str = &DAT_1800e0598;
      if (pendingGrantState == 1) {
        _Str = &DAT_1800e0558;
      }
      sVar4 = strlen(_Str);
      assignSmallString(&grantStatusMessage,_Str,sVar4);
      local_60[3] = 0xf;
      local_60[1] = 0;
      local_60[0] = 0;
      local_60[5] = 0;
      local_60[4] = 0;
      local_18 = 0;
      lStack_10 = 0;
      local_60[2] = 0;
      local_60[6] = 0;
      local_60[7] = 0xf;
      local_20 = 0;
      local_1c = 0xffffffff;
      pendingGrantState = 0;
      copySmallString(&requestedItemType,local_60);
      copySmallString(&selectedCarrierType,local_60 + 4);
      requestedItemAmount = local_20;
      carrierItemId = local_1c;
      nextGrantPollAt = local_18;
      grantDeadline = lStack_10;
      destroySmallString(local_60 + 4);
      destroySmallString(local_60);
    }
  }
  return;
}

