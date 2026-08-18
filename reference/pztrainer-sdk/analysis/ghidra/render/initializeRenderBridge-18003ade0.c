/*
 * Semantic name: initializeRenderBridge
 * Address: 0x18003ade0
 * Module: render
 * Confidence: high
 * Summary: Initializes ImGui, Win32/OpenGL backends, and input integration.
 * Ghidra function: initializeRenderBridge
 * Callers:
 *   - FUN_18003b390 @ 0x18003b390
 * Callees:
 *   - SetWindowLongPtrW @ 0xEXTERNAL:00000024
 *   - WindowFromDC @ 0xEXTERNAL:00000025
 *   - SetLastError @ 0xEXTERNAL:0000004d
 *   - GetLastError @ 0xEXTERNAL:00000053
 *   - FUN_180008090 @ 0x180008090
 *   - destroySmallString @ 0x180008440
 *   - appendSmallString @ 0x180008dd0
 *   - FUN_18000d010 @ 0x18000d010
 *   - FUN_180012f60 @ 0x180012f60
 *   - FUN_180032140 @ 0x180032140
 *   - FUN_18003a9f0 @ 0x18003a9f0
 *   - FUN_180067210 @ 0x180067210
 *   - FUN_180076fa0 @ 0x180076fa0
 *   - FUN_18007c4b0 @ 0x18007c4b0
 *   - FUN_18007c930 @ 0x18007c930
 *   - FUN_1800804c0 @ 0x1800804c0
 *   - FUN_180080580 @ 0x180080580
 *   - FUN_180081d80 @ 0x180081d80
 *   - FUN_180083ed0 @ 0x180083ed0
 *   - FUN_180091730 @ 0x180091730
 *   - FUN_18009a210 @ 0x18009a210
 *   - FUN_1800a90b0 @ 0x1800a90b0
 *   - FUN_1800a9520 @ 0x1800a9520
 *   - FUN_1800c82e0 @ 0x1800c82e0
 *   - FUN_1800c84b0 @ 0x1800c84b0
 *   - FUN_1800ca450 @ 0x1800ca450
 *   - FUN_1800ca6f0 @ 0x1800ca6f0
 *   - __security_check_cookie @ 0x1800cd520
 *   - strlen @ 0x1800cf652
 * Referenced strings:
 *   - WindowFromDC failed; waiting for the next frame.
 *   - C:\Windows\Fonts\msyh.ttc
 *   - While loading '%s'\n
 *   - Could not load font file!
 *   - Microsoft YaHei UI font was unavailable; using the ImGui default font.
 *   - ImGui Win32 backend initialization failed.
 *   - ImGui OpenGL backend initialization failed.
 *   - Glass blur unavailable: 
 *   - Glass blur initialized.
 *   - Native model chams OpenGL hooks initialized, status=
 *   - Native model chams OpenGL hooks could not be initialized, status=
 *   - Failed to install the game-window input hook.
 *   - ImGui initialized. Press Insert to show or hide the menu.
 */


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Initializes ImGui, Win32/OpenGL backends, and input integration. */

ulonglong initializeRenderBridge(HDC param_1,undefined8 param_2,undefined8 param_3,int *param_4)

{
  int *piVar1;
  uint *puVar2;
  DWORD DVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  void *pvVar6;
  size_t sVar7;
  longlong *plVar8;
  undefined8 *puVar9;
  HWND pHVar10;
  char *pcVar11;
  undefined8 uVar12;
  undefined8 **ppuVar13;
  float *pfVar14;
  undefined1 auStack_208 [32];
  longlong local_1e8 [4];
  undefined1 local_1c8 [8];
  undefined8 *local_1c0;
  longlong local_1b8;
  longlong lStack_1b0;
  longlong local_1a8;
  longlong lStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  void *pvStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined1 *local_108;
  undefined8 *local_100;
  longlong local_f8 [4];
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = DAT_1800ff040 ^ (ulonglong)auStack_208;
  puVar5 = (undefined8 *)0x0;
  DAT_180102b78 = WindowFromDC(param_1);
  puVar9 = DAT_180100920;
  if (DAT_180102b78 == (HWND)0x0) {
    local_1e8[0] = 0;
    local_1e8[1] = 0;
    local_1e8[2] = 0;
    local_1e8[3] = 0;
    uVar12 = 0x30;
    pcVar11 = "WindowFromDC failed; waiting for the next frame.";
    FUN_180008090(local_1e8,"WindowFromDC failed; waiting for the next frame.",0x30);
    FUN_18003a9f0(local_1e8,pcVar11,uVar12);
    uVar4 = destroySmallString(local_1e8);
    return uVar4 & 0xffffffffffffff00;
  }
  local_1c0 = FUN_180083ed0(0x2a30);
  local_108 = local_1c8;
  local_100 = local_1c0;
  if (local_1c0 != (undefined8 *)0x0) {
    param_2 = 0;
    puVar5 = FUN_180080580(local_1c0);
  }
  DAT_180100920 = puVar5;
  FUN_180081d80();
  if (puVar9 != (undefined8 *)0x0) {
    DAT_180100920 = puVar9;
  }
  puVar9 = DAT_180100920;
  DAT_180100920[9] = 0;
  puVar9[10] = 0;
  *(uint *)(puVar9 + 5) = *(uint *)(puVar9 + 5) | 1;
  puVar2 = (uint *)puVar9[0xc];
  local_1c0 = (undefined8 *)0x0;
  ppuVar13 = &local_1c0;
  pvVar6 = FUN_18007c930("C:\\Windows\\Fonts\\msyh.ttc",param_2,(size_t *)ppuVar13);
  if (pvVar6 == (void *)0x0) {
    pcVar11 = "C:\\Windows\\Fonts\\msyh.ttc";
    FUN_18009a210("While loading \'%s\'\n","C:\\Windows\\Fonts\\msyh.ttc",ppuVar13,
                  (ulonglong)param_4);
    FUN_180091730((float *)"Could not load font file!",(float *)pcVar11,(float *)ppuVar13,
                  (ulonglong)param_4);
  }
  else {
    local_148 = 0;
    local_138 = 0;
    uStack_120 = 0;
    local_168 = 0x100000000;
    uStack_160 = 0;
    uStack_140 = 0x7f7fffff00000000;
    uStack_130 = 0x3f80000000000000;
    local_128 = 0x3f800000;
    local_d8 = 0;
    uStack_d0 = 0;
    local_c8 = 0;
    uStack_c0 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    local_a8 = 0x100000000;
    uStack_a0 = 0;
    local_98 = 0;
    uStack_90 = 0;
    local_88 = 0;
    uStack_80 = 0x7f7fffff00000000;
    local_78 = 0;
    uStack_70 = 0x3f80000000000000;
    local_68 = 0x3f800000;
    uStack_60 = 0;
    local_58 = 0;
    uStack_50 = 0;
    param_4 = (int *)0x1800e3f21;
    do {
      piVar1 = (int *)((longlong)param_4 - 1);
      if (((char)*piVar1 == '/') || ((char)*piVar1 == '\\')) break;
      param_4 = piVar1;
    } while ("C:\\Windows\\Fonts\\msyh.ttc" < piVar1);
    ppuVar13 = (undefined8 **)&DAT_1800e4f38;
    FUN_18007c4b0((longlong)&local_d8,0x28,&DAT_1800e4f38,param_4);
    local_198 = local_d8;
    uStack_190 = uStack_d0;
    local_188 = local_c8;
    uStack_180 = uStack_c0;
    local_178 = local_b8;
    local_158 = local_98;
    uStack_150 = uStack_90;
    local_148 = local_88;
    uStack_140 = uStack_80;
    local_138 = local_78;
    uStack_130 = uStack_70;
    local_128 = local_68;
    uStack_120 = uStack_60;
    local_118 = local_58;
    uStack_110 = uStack_50;
    local_168 = CONCAT44((int)((ulonglong)local_a8 >> 0x20),local_1c0._0_4_);
    uStack_160 = CONCAT44(0x41880000,(int)uStack_a0);
    pcVar11 = (char *)&local_198;
    pvStack_170 = pvVar6;
    puVar5 = FUN_1800a90b0(puVar2,(undefined8 *)pcVar11,(undefined *)ppuVar13,param_4);
    if (puVar5 != (undefined8 *)0x0) goto LAB_18003b07c;
  }
  FUN_1800a9520((uint *)puVar9[0xc],pcVar11,ppuVar13,param_4);
  local_1e8[0] = 0;
  local_1e8[1] = 0;
  local_1e8[2] = 0;
  local_1e8[3] = 0;
  ppuVar13 = (undefined8 **)0x46;
  pcVar11 = "Microsoft YaHei UI font was unavailable; using the ImGui default font.";
  FUN_180008090(local_1e8,"Microsoft YaHei UI font was unavailable; using the ImGui default font.",
                0x46);
  FUN_18003a9f0(local_1e8,pcVar11,ppuVar13);
  destroySmallString(local_1e8);
LAB_18003b07c:
  FUN_180076fa0();
  pHVar10 = DAT_180102b78;
  uVar12 = FUN_1800c82e0(DAT_180102b78);
  if ((char)uVar12 == '\0') {
    local_1e8[0] = 0;
    local_1e8[1] = 0;
    local_1e8[2] = 0;
    local_1e8[3] = 0;
    pfVar14 = (float *)0x2a;
    pcVar11 = "ImGui Win32 backend initialization failed.";
    FUN_180008090(local_1e8,"ImGui Win32 backend initialization failed.",0x2a);
    FUN_18003a9f0(local_1e8,pcVar11,pfVar14);
    plVar8 = local_1e8;
    destroySmallString(plVar8);
    uVar4 = FUN_1800804c0(plVar8,(float *)pcVar11,pfVar14,(ulonglong)param_4);
    uVar4 = uVar4 & 0xffffffffffffff00;
  }
  else {
    uVar12 = FUN_1800ca450(pHVar10,pcVar11,(int *)ppuVar13,param_4);
    if ((char)uVar12 == '\0') {
      local_1e8[0] = 0;
      local_1e8[1] = 0;
      local_1e8[2] = 0;
      local_1e8[3] = 0;
      pfVar14 = (float *)0x2b;
      pcVar11 = "ImGui OpenGL backend initialization failed.";
      FUN_180008090(local_1e8,"ImGui OpenGL backend initialization failed.",0x2b);
      FUN_18003a9f0(local_1e8,pcVar11,pfVar14);
      plVar8 = local_1e8;
      destroySmallString(plVar8);
      FUN_1800c84b0();
      uVar4 = FUN_1800804c0(plVar8,(float *)pcVar11,pfVar14,(ulonglong)param_4);
      uVar4 = uVar4 & 0xffffffffffffff00;
    }
    else {
      uVar4 = FUN_180067210();
      local_1e8[0] = 0;
      local_1e8[1] = 0;
      local_1e8[2] = 0;
      local_1e8[3] = 0;
      if ((char)uVar4 == '\0') {
        pcVar11 = (char *)&DAT_1800fffe8;
        if (0xf < DAT_180100000) {
          pcVar11 = DAT_1800fffe8;
        }
        FUN_180008090(local_1e8,"Glass blur unavailable: ",0x18);
        sVar7 = strlen(pcVar11);
        plVar8 = appendSmallString(local_1e8,pcVar11,sVar7);
        local_1b8 = *plVar8;
        lStack_1b0 = plVar8[1];
        local_1a8 = plVar8[2];
        lStack_1a0 = plVar8[3];
        plVar8[2] = 0;
        plVar8[3] = 0xf;
        *(undefined1 *)plVar8 = 0;
        FUN_18003a9f0(&local_1b8,pcVar11,sVar7);
        destroySmallString(&local_1b8);
      }
      else {
        uVar12 = 0x17;
        pcVar11 = "Glass blur initialized.";
        FUN_180008090(local_1e8,"Glass blur initialized.",0x17);
        FUN_18003a9f0(local_1e8,pcVar11,uVar12);
      }
      destroySmallString(local_1e8);
      uVar12 = FUN_180032140();
      DAT_18010118d = (char)uVar12;
      DAT_180102ba8 = DAT_180102880;
      puVar9 = FUN_18000d010(local_f8,DAT_180102880);
      pcVar11 = "Native model chams OpenGL hooks could not be initialized, status=";
      if (DAT_18010118d != '\0') {
        pcVar11 = "Native model chams OpenGL hooks initialized, status=";
      }
      local_1e8[0] = 0;
      local_1e8[1] = 0;
      local_1e8[2] = 0;
      local_1e8[3] = 0;
      sVar7 = strlen(pcVar11);
      FUN_180008090(local_1e8,pcVar11,sVar7);
      plVar8 = local_1e8;
      FUN_180012f60(&local_1b8,pcVar11,plVar8,puVar9);
      FUN_18003a9f0(&local_1b8,pcVar11,plVar8);
      destroySmallString(&local_1b8);
      destroySmallString(local_1e8);
      destroySmallString(local_f8);
      SetLastError(0);
      DAT_180102bb8 = SetWindowLongPtrW(DAT_180102b78,-4,0x18003acc0);
      if ((DAT_180102bb8 == 0) && (DVar3 = GetLastError(), DVar3 != 0)) {
        local_1e8[0] = 0;
        local_1e8[1] = 0;
        local_1e8[2] = 0;
        local_1e8[3] = 0;
        pfVar14 = (float *)0x2d;
        pcVar11 = "Failed to install the game-window input hook.";
        FUN_180008090(local_1e8,"Failed to install the game-window input hook.",0x2d);
        FUN_18003a9f0(local_1e8,pcVar11,pfVar14);
        plVar8 = local_1e8;
        destroySmallString(plVar8);
        FUN_1800ca6f0();
        FUN_1800c84b0();
        uVar4 = FUN_1800804c0(plVar8,(float *)pcVar11,pfVar14,(ulonglong)puVar9);
        uVar4 = uVar4 & 0xffffffffffffff00;
      }
      else {
        DAT_18010118c = 1;
        local_1e8[0] = 0;
        local_1e8[1] = 0;
        local_1e8[2] = 0;
        local_1e8[3] = 0;
        uVar12 = 0x39;
        pcVar11 = "ImGui initialized. Press Insert to show or hide the menu.";
        FUN_180008090(local_1e8,"ImGui initialized. Press Insert to show or hide the menu.",0x39);
        FUN_18003a9f0(local_1e8,pcVar11,uVar12);
        uVar12 = destroySmallString(local_1e8);
        uVar4 = CONCAT71((int7)((ulonglong)uVar12 >> 8),1);
      }
    }
  }
  return uVar4;
}

