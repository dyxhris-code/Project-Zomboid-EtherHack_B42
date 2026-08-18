/*
 * Semantic name: findReturnedPallet
 * Address: 0x18001aee0
 * Module: item-grant
 * Confidence: high
 * Summary: Scans the current square for the returned IsoTrap by item ID or marker and type.
 * Ghidra function: findReturnedPallet
 * Callers:
 *   - beginPalletItemGrant @ 0x18001b510
 *   - pollPalletItemGrant @ 0x18001bc80
 * Callees:
 *   - jniCallObjectMethodWithIntArg @ 0x180001810
 *   - jniCallIntMethod @ 0x1800018a0
 *   - invokeLuaBoundMethod @ 0x180025840
 *   - memcmp @ 0x1800cf424
 *   - strlen @ 0x1800cf652
 * Referenced strings:
 *   - getCurrentSquare
 *   - getObjects
 */


/* Scans the current square for the returned IsoTrap by item ID or marker and type. */

longlong findReturnedPallet(longlong *param_1,longlong param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  char *_Str;
  size_t sVar8;
  undefined8 *_Buf1;
  longlong lVar9;
  uint uVar10;
  int iVar11;
  uint local_res18 [2];
  longlong local_res20;
  longlong local_48 [2];
  
  local_res18[0] = local_res18[0] & 0xffffff00;
  local_48[0] = 0;
  local_48[1] = 0;
  lVar5 = invokeLuaBoundMethod(param_1,param_2,0x1800ddb48,local_48,(undefined1 *)local_res18);
  if (((char)local_res18[0] == '\0') || (lVar5 == 0)) {
    lVar9 = 0;
    local_res20 = 0;
    cVar2 = (char)local_res18[0];
    if (lVar5 == 0) goto LAB_18001af89;
  }
  else {
    local_48[0] = 0;
    local_48[1] = 0;
    local_res20 = invokeLuaBoundMethod(param_1,lVar5,0x1800dfd20,local_48,(undefined1 *)local_res18)
    ;
    cVar2 = (char)local_res18[0];
  }
  lVar9 = local_res20;
  (**(code **)(*param_1 + 0xb8))(param_1,lVar5);
LAB_18001af89:
  if (cVar2 == '\0') {
    if (lVar9 != 0) {
      (**(code **)(*param_1 + 0xb8))(param_1,lVar9);
    }
  }
  else if (lVar9 != 0) {
    local_res18[0] = jniCallIntMethod(param_1);
    iVar11 = 0;
    local_48[0] = 0;
    iVar3 = carrierItemId;
    lVar5 = local_48[0];
    uVar10 = local_res18[0];
    if (0 < (int)local_res18[0]) {
      do {
        cVar2 = (**(code **)(*param_1 + 0x720))(param_1);
        if (cVar2 != '\0') {
          (**(code **)(*param_1 + 0x88))();
          iVar3 = carrierItemId;
          lVar5 = local_48[0];
          break;
        }
        lVar5 = jniCallObjectMethodWithIntArg(param_1);
        if (lVar5 != 0) {
          cVar2 = (**(code **)(*param_1 + 0x100))(param_1,lVar5,classIsoTrap);
          if (cVar2 == '\x01') {
            lVar6 = jniCallObjectMethodWithIntArg(param_1);
            if (lVar6 == 0) {
              iVar3 = -1;
            }
            else {
              iVar3 = jniCallIntMethod(param_1);
            }
            if ((carrierItemId < 0) || (iVar3 != carrierItemId)) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            if (lVar6 != 0) {
              if (carrierItemId < 0) {
                cVar2 = (**(code **)(*param_1 + 0x720))(param_1);
                if (cVar2 == '\0') {
                  iVar4 = jniCallIntMethod(param_1);
                  lVar7 = jniCallObjectMethodWithIntArg(param_1);
                  if (lVar7 == 0) {
                    _Str = (char *)0x0;
                  }
                  else {
                    _Str = (char *)(**(code **)(*param_1 + 0x548))(param_1,lVar7,0);
                  }
                  cVar2 = (**(code **)(*param_1 + 0x720))(param_1);
                  if (cVar2 == '\0') {
                    if ((iVar4 != 0x505c) || (_Str == (char *)0x0)) goto LAB_18001b159;
                    sVar8 = strlen(_Str);
                    _Buf1 = &selectedCarrierType;
                    if (0xf < DAT_1800ffcb0) {
                      _Buf1 = selectedCarrierType;
                    }
                    if ((DAT_1800ffca8 != sVar8) ||
                       ((DAT_1800ffca8 != 0 &&
                        (iVar4 = memcmp(_Buf1,_Str,DAT_1800ffca8), iVar4 != 0))))
                    goto LAB_18001b159;
                    bVar1 = true;
LAB_18001b161:
                    (**(code **)(*param_1 + 0x550))(param_1,lVar7,_Str);
                  }
                  else {
                    (**(code **)(*param_1 + 0x88))(param_1);
LAB_18001b159:
                    bVar1 = false;
                    if (_Str != (char *)0x0) goto LAB_18001b161;
                  }
                  lVar9 = local_res20;
                  uVar10 = local_res18[0];
                  if (lVar7 != 0) {
                    (**(code **)(*param_1 + 0xb8))(param_1,lVar7);
                    lVar9 = local_res20;
                    uVar10 = local_res18[0];
                  }
                }
                else {
                  (**(code **)(*param_1 + 0x88))();
                }
              }
              (**(code **)(*param_1 + 0xb8))(param_1,lVar6);
            }
            cVar2 = (**(code **)(*param_1 + 0x720))(param_1);
            if (cVar2 == '\0') {
              if (bVar1) break;
            }
            else {
              (**(code **)(*param_1 + 0x88))(param_1);
            }
          }
          (**(code **)(*param_1 + 0xb8))(param_1,lVar5);
        }
        iVar11 = iVar11 + 1;
        iVar3 = carrierItemId;
        lVar5 = local_48[0];
      } while (iVar11 < (int)uVar10);
    }
    local_48[0] = lVar5;
    carrierItemId = iVar3;
    (**(code **)(*param_1 + 0xb8))(param_1,lVar9);
    return local_48[0];
  }
  return 0;
}

