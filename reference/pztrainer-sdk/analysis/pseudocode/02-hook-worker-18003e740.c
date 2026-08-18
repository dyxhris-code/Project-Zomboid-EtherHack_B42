// callconv: rax ms (rcx, rdx, r8, r9, stack);
void fcn.18003e740 (void) {
        // DATA XREF from fcn.180001780 @ 0x1800017a2(r)
        push (rbp)
        push (rbx)
        push (rsi)
        push (rdi)
        rbp = rsp
        rsp -= 0x48
        xmm0 ^= xmm0
        xmmword [var_28h] = xmm0
        xmm1 ^= xmm1
        xmmword [var_18h] = xmm1
        r8d = 0x39   // '9' // 57
        rdx = rip + str.DLL_loaded__waiting_for_the_OpenGL_presentation_function. // 0x1800e4548 // "DLL loaded; waiting for the OpenGL presentation function."
        rcx = var_28h
        fcn.180008090 () // fcn.180008090(0x0, 0x0, 0x1800e4548)
        rcx = var_28h
        fcn.18003a9f0 () // fcn.18003a9f0(0x0)
        rcx = var_28h
        fcn.180008440 () // fcn.180008440(0x0)
        
    loc_0x18003e790:
        // CODE XREF from fcn.18003e740 @ 0x18003e7ad(x)
        rcx = rip + str.gdi32.dll // 0x1800e4588 // "gdi32.dll"
        qword [sym.imp.KERNEL32.dll_GetModuleHandleW] () // [0x1800d4100:8]=0xfcbaa reloc.KERNEL32.dll_GetModuleHandleW // reloc.KERNEL32.dll_GetModuleHandleW // HMODULE GetModuleHandleW("g")
        v = rax & rax
        if (v) goto loc_0x18003e7af // unlikely
        goto loc_0x18003e7a2;
        return rax;
    loc_0x18003e7a2:
        ecx = 0x64   // 'd' // 100
        qword [sym.imp.KERNEL32.dll_Sleep] () // [0x1800d4140:8]=0xfcc3c reloc.KERNEL32.dll_Sleep // "<\xcc\x0f" // reloc.KERNEL32.dll_Sleep // VOID Sleep(-1)
        goto loc_0x18003e790
        break;
    loc_0x18003e7af: // orphan
         // CODE XREF from fcn.18003e740 @ 0x18003e7a0(x)
         rdx = rip + str.SwapBuffers // 0x1800e45a0 // "SwapBuffers"
         rcx = rax
         qword [sym.imp.KERNEL32.dll_GetProcAddress] () // [0x1800d40f8:8]=0xfcb98 reloc.KERNEL32.dll_GetProcAddress // reloc.KERNEL32.dll_GetProcAddress // FARPROC GetProcAddress(0, 0x6666754270617753)
         rsi = rax
         v = rax & rax
         if (v) 
    loc_0x18003e80e: // orphan
         // CODE XREF from fcn.18003e740 @ 0x18003e7c5(x)
         edi = 0
         ebx = 1
         eax = 0
         lock cmpxchg dword [0x180100928] ebx
         if (!v) 
    loc_0x18003e842: // orphan
         // CODE XREF from fcn.18003e740 @ 0x18003e81f(x)
         v = qword [0x180100b28] - 0 // [0x180100b28:8]=0
         if (v) 
    loc_0x18003e86f: // orphan
         // CODE XREF from fcn.18003e740 @ 0x18003e84a(x)
         edx = ebx

         goto loc_0x18003e8c1;
    loc_0x18003e8c1: // orphan
         // CODE XREF from fcn.18003e740 @ 0x18003e87b(x)
         r8 = rip + 0xc42c8       // 0x180102b90
         rdx = rip - 0x353f       // 0x18003b390
         rcx = rsi
         fcn.1800cc530 ()         // fcn.1800cc530(0x0, 0x0, 0x18003b390)
         v = eax & eax
         if (!v) 
    loc_0x18003e91f: // orphan
         // CODE XREF from fcn.18003e740 @ 0x18003e8d9(x)
         rcx = rsi
         fcn.1800cc7d0 ()         // fcn.1800cc7d0(0x0)
         xmm0 ^= xmm0
         xmm1 ^= xmm1
         rcx = var_28h
         xmmword [var_28h] = xmm0
         xmmword [var_18h] = xmm1
         v = eax & eax
         if (!v) 
    loc_0x18003e96f: // orphan
         // CODE XREF from fcn.18003e740 @ 0x18003e93c(x)
         r8d = 0x19               // 25
         rdx = rip + str.SwapBuffers_hook_enabled. // 0x1800e4648 // "SwapBuffers hook enabled."
         fcn.180008090 ()         // fcn.180008090(0x0, 0x0, 0x1800e4648)
         rcx = var_28h
         fcn.18003a9f0 ()         // fcn.18003a9f0(0x0)
         rcx = var_28h
         fcn.180008440 ()         // fcn.180008440(0x0)
         eax = 0
         rsp += 0x48
         rdi = pop ()
         rsi = pop ()
         rbx = pop ()
         rbp = pop ()
         return

    loc_0x18003e93e: // orphan
         r8d = 0x26               // '&' // 38
         rdx = rip + str.Failed_to_enable_the_SwapBuffers_hook. // 0x1800e4620 // "Failed to enable the SwapBuffers hook."
         fcn.180008090 ()         // fcn.180008090(0x0, 0x0, 0x1800e4620)
         rcx = var_28h
         fcn.18003a9f0 ()         // fcn.18003a9f0(0x0)
         rcx = var_28h
         fcn.180008440 ()         // fcn.180008440(0x0)
         eax = ebx
         rsp += 0x48
         rdi = pop ()
         rsi = pop ()
         rbx = pop ()
         rbp = pop ()
         return

    loc_0x18003e8db: // orphan
         xmm0 ^= xmm0
         xmmword [var_28h] = xmm0
         xmm1 ^= xmm1
         xmmword [var_18h] = xmm1
         r8d = 0x26               // '&' // 38
         rdx = rip + str.Failed_to_create_the_SwapBuffers_hook. // 0x1800e45f8 // "Failed to create the SwapBuffers hook."
         rcx = var_28h
         fcn.180008090 ()         // fcn.180008090(0x0, 0x0, 0x1800e45f8)
         rcx = var_28h
         fcn.18003a9f0 ()         // fcn.18003a9f0(0x0)
         rcx = var_28h
         fcn.180008440 ()         // fcn.180008440(0x0)
         eax = ebx
         rsp += 0x48
         rdi = pop ()
         rsi = pop ()
         rbx = pop ()
         rbp = pop ()
         return

    loc_0x18003e87d: // orphan
         xmm0 ^= xmm0
         xmmword [var_28h] = xmm0
         xmm1 ^= xmm1
         xmmword [var_18h] = xmm1
         r8d = 0x1e               // 30
         rdx = rip + str.MinHook_initialization_failed. // 0x1800e45d8 // "MinHook initialization failed."
         rcx = var_28h
         fcn.180008090 ()         // fcn.180008090(0x0, 0x0, 0x1800e45d8)
         rcx = var_28h
         fcn.18003a9f0 ()         // fcn.18003a9f0(0x0)
         rcx = var_28h
         fcn.180008440 ()         // fcn.180008440(0x0)
         eax = ebx
         rsp += 0x48
         rdi = pop ()
         rsi = pop ()
         rbx = pop ()
         rbp = pop ()
         return

    loc_0x18003e84c: // orphan
         r8d = 0
         edx = 0
         ecx = 0
         qword [sym.imp.KERNEL32.dll_HeapCreate] () // [0x1800d4068:8]=0xfcd7c reloc.KERNEL32.dll_HeapCreate // "|\xcd\x0f" // reloc.KERNEL32.dll_HeapCreate // HANDLE HeapCreate(0, 0, 0)
         qword [0x180100b28] = rax // [0x180100b28:8]=0
         edx = 9
         ecx = 0
         v = rax & rax
         if (!zf) edx = ecx
         
    loc_0x18003e871: // orphan
         // CODE XREF from fcn.18003e740 @ 0x18003e86d(x)
         eax = 0
         dword [0x180100928], eax = eax, dword [rip + 0xc20af]
         v = edx & edx
         if (!v) 
         goto loc_0x18003e821;
    loc_0x18003e821: // orphan
         // CODE XREF from fcn.18003e740 @ 0x18003e840(x)
         v = rdi - 0x20           // 32
         jae 0x18003e82b          // unlikely

    loc_0x18003e82b: // orphan
         // CODE XREF from fcn.18003e740 @ 0x18003e825(x)
         ecx = ebx

         goto loc_0x18003e827;
    loc_0x18003e827: // orphan
         ecx = 0
         
    loc_0x18003e82d: // orphan
         // CODE XREF from fcn.18003e740 @ 0x18003e829(x)
         qword [sym.imp.KERNEL32.dll_Sleep] () // [0x1800d4140:8]=0xfcc3c reloc.KERNEL32.dll_Sleep // "<\xcc\x0f" // reloc.KERNEL32.dll_Sleep // VOID Sleep(0)
         rdi++
         eax = 0
         lock cmpxchg dword [0x180100928] ebx
         if (v) 
         return rax;
    loc_0x18003e7c7: // orphan
         xmm0 ^= xmm0
         xmmword [var_28h] = xmm0
         xmm1 ^= xmm1
         xmmword [var_18h] = xmm1
         r8d = 0x24               // '$' // 36
         rdx = rip + str.Could_not_resolve_gdi32_SwapBuffers. // 0x1800e45b0 // "Could not resolve gdi32!SwapBuffers."
         rcx = var_28h
         fcn.180008090 ()         // fcn.180008090(0x0, 0x0, 0x1800e45b0)
         rcx = var_28h
         fcn.18003a9f0 ()         // fcn.18003a9f0(0x0)
         rcx = var_28h
         fcn.180008440 ()         // fcn.180008440(0x0)
         eax = 1
         rsp += 0x48
         rdi = pop ()
         rsi = pop ()
         rbx = pop ()
         rbp = pop ()
         return

}

