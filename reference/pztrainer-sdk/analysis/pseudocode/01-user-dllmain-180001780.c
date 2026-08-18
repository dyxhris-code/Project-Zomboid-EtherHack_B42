// callconv: rax ms (rcx, rdx, r8, r9, stack);
void fcn.180001780 (int64_t arg1, int64_t arg2) {
        // CALL XREFS from entry0 @ 0x1800cddf5(x), 0x1800cde11(x)
        push (rbx)
        rsp -= 0x30
        rbx = rcx    // arg1
        v = edx - 1  // 1 // arg2
        if (v) goto loc_0x1800017c8 // likely
        goto loc_0x18000178e;
    loc_0x1800017c8:
        // CODE XREFS from fcn.180001780 @ 0x18000178c(x), 0x1800017bd(x)
        eax = 1
        rsp += 0x30
        rbx = pop ()
        return
        goto loc_0x1800017bf;
        return rax;
    loc_0x1800017bf:
        rcx = rax    // HANDLE hObject
        qword [sym.imp.KERNEL32.dll_CloseHandle] () // [0x1800d4150:8]=0xfcc54 reloc.KERNEL32.dll_CloseHandle // "T\xcc\x0f" // reloc.KERNEL32.dll_CloseHandle // BOOL CloseHandle(0)
        break;
    loc_0x18000178e: // orphan
         qword [sym.imp.KERNEL32.dll_DisableThreadLibraryCalls] () // [0x1800d40f0:8]=0xfcb7c reloc.KERNEL32.dll_DisableThreadLibraryCalls // "|\xcb\x0f" // reloc.KERNEL32.dll_DisableThreadLibraryCalls // BOOL DisableThreadLibraryCalls(0)
         eax = 0
         qword [0x180102ba0] = rbx // [0x180102ba0:8]=0
         qword [lpThreadId] = rax // LPDWORD lpThreadId
         r8 = rip + 0x3cf97       // 0x18003e740 // LPTHREAD_START_ROUTINE lpStartAddress
         r9d = 0                  // LPVOID lpParameter
         dword [dwCreationFlags] = eax // DWORD dwCreationFlags
         edx = 0                  // SIZE_T dwStackSize
         ecx = 0                  // LPSECURITY_ATTRIBUTES lpThreadAttributes
         qword [sym.imp.KERNEL32.dll_CreateThread] () // [0x1800d4158:8]=0xfcc62 reloc.KERNEL32.dll_CreateThread // "b\xcc\x0f" // reloc.KERNEL32.dll_CreateThread // HANDLE CreateThread(0, 0, 0xec8b485756535540, 0, 0, 0)
         v = rax & rax
         if (!v) 
}

