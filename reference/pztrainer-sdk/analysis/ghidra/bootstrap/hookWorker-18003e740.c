/*
 * Semantic name: hookWorker
 * Address: 0x18003e740
 * Module: bootstrap
 * Confidence: high
 * Summary: Waits for SwapBuffers and installs the rendering hook.
 * Ghidra function: hookWorker
 * Callers: none
 * Callees:
 *   - HeapCreate @ 0xEXTERNAL:00000037
 *   - GetProcAddress @ 0xEXTERNAL:00000049
 *   - GetModuleHandleW @ 0xEXTERNAL:0000004a
 *   - Sleep @ 0xEXTERNAL:00000052
 *   - FUN_180008090 @ 0x180008090
 *   - destroySmallString @ 0x180008440
 *   - FUN_18003a9f0 @ 0x18003a9f0
 *   - FUN_1800cc530 @ 0x1800cc530
 *   - FUN_1800cc7d0 @ 0x1800cc7d0
 * Referenced strings:
 *   - DLL loaded; waiting for the OpenGL presentation function.
 *   - gdi32.dll
 *   - SwapBuffers
 *   - Could not resolve gdi32!SwapBuffers.
 *   - MinHook initialization failed.
 *   - Failed to create the SwapBuffers hook.
 *   - Failed to enable the SwapBuffers hook.
 *   - SwapBuffers hook enabled.
 */


/* Waits for SwapBuffers and installs the rendering hook. */

undefined8 hookWorker(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  char *pcVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  longlong local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  uVar5 = 0x39;
  pcVar2 = "DLL loaded; waiting for the OpenGL presentation function.";
  FUN_180008090(&local_48,"DLL loaded; waiting for the OpenGL presentation function.",0x39);
  FUN_18003a9f0(&local_48,pcVar2,uVar5);
  destroySmallString(&local_48);
  while (hModule = GetModuleHandleW(L"gdi32.dll"), hModule == (HMODULE)0x0) {
    Sleep(100);
  }
  pFVar1 = GetProcAddress(hModule,"SwapBuffers");
  if (pFVar1 == (FARPROC)0x0) {
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    uStack_30 = 0;
    uVar5 = 0x24;
    pcVar2 = "Could not resolve gdi32!SwapBuffers.";
    FUN_180008090(&local_48,"Could not resolve gdi32!SwapBuffers.",0x24);
    FUN_18003a9f0(&local_48,pcVar2,uVar5);
    destroySmallString(&local_48);
    return 1;
  }
  uVar4 = 0;
  LOCK();
  bVar6 = DAT_180100928 == 0;
  iVar3 = 1;
  if (bVar6) {
    DAT_180100928 = 1;
  }
  UNLOCK();
  while (!bVar6) {
    Sleep((uint)(0x1f < uVar4));
    uVar4 = uVar4 + 1;
    LOCK();
    bVar6 = DAT_180100928 == 0;
    if (bVar6) {
      DAT_180100928 = 1;
    }
    UNLOCK();
  }
  if (DAT_180100b28 == (HANDLE)0x0) {
    DAT_180100b28 = HeapCreate(0,0,0);
    iVar3 = 9;
    if (DAT_180100b28 != (HANDLE)0x0) {
      iVar3 = 0;
    }
  }
  LOCK();
  DAT_180100928 = 0;
  UNLOCK();
  if (iVar3 == 0) {
    uVar5 = FUN_1800cc530((undefined8 *)pFVar1,FUN_18003b390,&DAT_180102b90);
    if ((int)uVar5 != 0) {
      local_48 = 0;
      uStack_40 = 0;
      local_38 = 0;
      uStack_30 = 0;
      uVar5 = 0x26;
      pcVar2 = "Failed to create the SwapBuffers hook.";
      FUN_180008090(&local_48,"Failed to create the SwapBuffers hook.",0x26);
      FUN_18003a9f0(&local_48,pcVar2,uVar5);
      destroySmallString(&local_48);
      return 1;
    }
    uVar4 = FUN_1800cc7d0((longlong)pFVar1);
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    uStack_30 = 0;
    if ((int)uVar4 == 0) {
      uVar5 = 0x19;
      pcVar2 = "SwapBuffers hook enabled.";
      FUN_180008090(&local_48,"SwapBuffers hook enabled.",0x19);
      FUN_18003a9f0(&local_48,pcVar2,uVar5);
      destroySmallString(&local_48);
      return 0;
    }
    uVar5 = 0x26;
    pcVar2 = "Failed to enable the SwapBuffers hook.";
    FUN_180008090(&local_48,"Failed to enable the SwapBuffers hook.",0x26);
    FUN_18003a9f0(&local_48,pcVar2,uVar5);
    destroySmallString(&local_48);
    return 1;
  }
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  uVar5 = 0x1e;
  pcVar2 = "MinHook initialization failed.";
  FUN_180008090(&local_48,"MinHook initialization failed.",0x1e);
  FUN_18003a9f0(&local_48,pcVar2,uVar5);
  destroySmallString(&local_48);
  return 1;
}

