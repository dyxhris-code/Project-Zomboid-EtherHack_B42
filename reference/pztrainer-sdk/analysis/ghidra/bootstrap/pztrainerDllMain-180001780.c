/*
 * Semantic name: pztrainerDllMain
 * Address: 0x180001780
 * Module: bootstrap
 * Confidence: high
 * Summary: DLL entry point that starts the hook worker on process attach.
 * Ghidra function: pztrainerDllMain
 * Callers:
 *   - FUN_1800cdd70 @ 0x1800cdd70
 * Callees:
 *   - DisableThreadLibraryCalls @ 0xEXTERNAL:00000048
 *   - CloseHandle @ 0xEXTERNAL:00000054
 *   - CreateThread @ 0xEXTERNAL:00000055
 */


/* DLL entry point that starts the hook worker on process attach. */

undefined8 pztrainerDllMain(HMODULE param_1,int param_2)

{
  HANDLE hObject;
  
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    DAT_180102ba0 = param_1;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,hookWorker,(LPVOID)0x0,0,(LPDWORD)0x0);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
    }
  }
  return 1;
}

