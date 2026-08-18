/*
 * Semantic name: selectSafePalletCarrier
 * Address: 0x18001a940
 * Module: item-grant
 * Confidence: high
 * Summary: Selects an effect-free HandWeapon from a fixed candidate list.
 * Ghidra function: selectSafePalletCarrier
 * Callers:
 *   - beginPalletItemGrant @ 0x18001b510
 * Callees:
 *   - jniCallIntMethod @ 0x1800018a0
 *   - jniCallStaticObjectMethodOneArg @ 0x180001930
 *   - assignSmallString @ 0x180008c70
 *   - strlen @ 0x1800cf652
 * Referenced strings:
 *   - Base.Hammer
 *   - Base.RollingPin
 *   - Base.Saucepan
 *   - Base.Fork
 */


/* Selects an effect-free HandWeapon from a fixed candidate list. */

undefined1 * selectSafePalletCarrier(longlong *param_1,longlong *param_2)

{
  char *_Str;
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  size_t sVar9;
  longlong *plVar10;
  char **ppcVar11;
  undefined1 auStack_100 [96];
  undefined8 uStack_a0;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  longlong *local_68;
  char *local_60 [4];
  char *local_40;
  
  local_60[0] = "Base.Hammer";
  ppcVar11 = local_60;
  local_60[1] = "Base.RollingPin";
  local_60[2] = "Base.Saucepan";
  local_60[3] = "Base.Fork";
  local_68 = param_2;
  do {
    _Str = *ppcVar11;
    uStack_a0 = 0x18001a9a6;
    lVar7 = (**(code **)(*param_1 + 0x538))(param_1,_Str);
    if (lVar7 == 0) {
      lVar8 = 0;
      goto LAB_18001ab17;
    }
    uStack_a0 = 0x18001a9ce;
    lVar8 = jniCallStaticObjectMethodOneArg(param_1);
    uStack_a0 = 0x18001a9e1;
    (**(code **)(*param_1 + 0xb8))(param_1,lVar7);
    if (lVar8 != 0) {
      uStack_a0 = 0x18001a9f6;
      cVar2 = (**(code **)(*param_1 + 0x720))(param_1);
      lVar7 = *param_1;
      if (cVar2 == '\0') {
        uStack_a0 = 0x18001aa14;
        cVar2 = (**(code **)(lVar7 + 0x100))(param_1,lVar8,classHandWeapon);
        if (cVar2 != '\x01') goto LAB_18001ab17;
        uStack_a0 = 0x18001aa2e;
        iVar3 = jniCallIntMethod(param_1);
        uStack_a0 = 0x18001aa42;
        iVar4 = jniCallIntMethod(param_1);
        uStack_a0 = 0x18001aa57;
        iVar5 = jniCallIntMethod(param_1);
        uStack_a0 = 0x18001aa6c;
        iVar6 = jniCallIntMethod(param_1);
        uStack_a0 = 0x18001aa81;
        local_78 = jniCallIntMethod(param_1);
        uStack_a0 = 0x18001aa97;
        local_74 = jniCallIntMethod(param_1);
        uStack_a0 = 0x18001aaad;
        local_70 = jniCallIntMethod(param_1);
        uStack_a0 = 0x18001aac3;
        local_6c = jniCallIntMethod(param_1);
        uStack_a0 = 0x18001aad3;
        cVar2 = (**(code **)(*param_1 + 0x720))(param_1);
        if (cVar2 != '\0') {
          lVar7 = *param_1;
          goto LAB_18001ab11;
        }
        if (((((0 < iVar3) || (0 < iVar4)) || (0 < iVar5)) || ((0 < iVar6 || (0 < local_78)))) ||
           ((0 < local_74 || ((0 < local_70 || (0 < local_6c)))))) goto LAB_18001ab17;
        bVar1 = true;
      }
      else {
LAB_18001ab11:
        uStack_a0 = 0x18001ab17;
        (**(code **)(lVar7 + 0x88))(param_1);
LAB_18001ab17:
        if (lVar8 == 0) goto LAB_18001ab33;
        bVar1 = false;
      }
      uStack_a0 = 0x18001ab2e;
      (**(code **)(*param_1 + 0xb8))(param_1,lVar8);
      if (bVar1) {
        uStack_a0 = 0x18001ab8c;
        sVar9 = strlen(_Str);
        uStack_a0 = 0x18001ab9c;
        plVar10 = assignSmallString(local_68,_Str,sVar9);
        return (undefined1 *)CONCAT71((int7)((ulonglong)plVar10 >> 8),1);
      }
    }
LAB_18001ab33:
    uStack_a0 = 0x18001ab3f;
    cVar2 = (**(code **)(*param_1 + 0x720))(param_1);
    if (cVar2 != '\0') {
      uStack_a0 = 0x18001ab4f;
      (**(code **)(*param_1 + 0x88))(param_1);
    }
    ppcVar11 = ppcVar11 + 1;
    if (ppcVar11 == &local_40) {
      return auStack_100;
    }
  } while( true );
}

