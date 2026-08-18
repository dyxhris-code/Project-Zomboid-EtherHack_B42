// callconv: rax ms (rcx, rdx, r8, r9, stack);
void fcn.18003ade0 (HDC hDC) {
        // CALL XREF from fcn.18003ade0 @ +0x60a(x)
        push (rbp)
        push (rbx)
        push (rsi)
        push (rdi)
        push (r14)
        push (r15)
        rbp = rsp - 0xd8
        rsp -= 0x1d8
        rax = qword [0x1800ff040] // [0x1800ff040:8]=0x2b992ddfa232
        rax ^= rsp
        qword [var_c0h] = rax
        r15d = 0
        qword [sym.imp.USER32.dll_WindowFromDC] () // [0x1800d4520:8]=0xfc9d6 reloc.USER32.dll_WindowFromDC // reloc.USER32.dll_WindowFromDC // HWND WindowFromDC(0)
        qword [0x180102b78] = rax // [0x180102b78:8]=0
        v = rax & rax
        if (v) goto loc_0x18003ae63 // likely
        goto loc_0x18003ae1e;
    loc_0x18003ae63:
        // CODE XREF from fcn.18003ade0 @ 0x18003ae1c(x)
        rbx = qword [0x180100920] // [0x180100920:8]=0
        ecx = 0x2a30 // '0*'
        fcn.180083ed0 () // fcn.180083ed0(0x0)
        qword [var_48h] = rax
        rcx = var_40h
        qword [rbp] = rcx
        qword [var_8h] = rax
        v = rax & rax
        if (!v) goto loc_0x18003ae97 // likely
        goto loc_0x18003ae8b;
    loc_0x18003ae97:
        // CODE XREF from fcn.18003ade0 @ 0x18003ae89(x)
        rax = r15
        
    loc_0x18003ae9a:
        // CODE XREF from fcn.18003ade0 @ 0x18003ae95(x)
        qword [0x180100920] = rax // [0x180100920:8]=0
        fcn.180081d80 ()
        v = rbx & rbx
        if (!v) goto loc_0x18003aeb4 // likely
        goto loc_0x18003aeab;
    loc_0x18003ae1e: // orphan
         xmm0 ^= xmm0
         xmmword [var_sp_20h] = xmm0
         xmm1 ^= xmm1
         xmmword [var_sp_30h] = xmm1
         r8d = 0x30               // '0' // 48
         rdx = rip + str.WindowFromDC_failed__waiting_for_the_next_frame. // 0x1800e3ed0 // "WindowFromDC failed; waiting for the next frame."
         rcx = var_sp_20h
         fcn.180008090 ()         // fcn.180008090(0x0, 0x0, 0x1800e3ed0)
         rcx = var_sp_20h
         fcn.18003a9f0 ()         // fcn.18003a9f0(0x0)
         rcx = var_sp_20h
         fcn.180008440 ()         // fcn.180008440(0x0)
         al = 0
         
         goto loc_0x18003ae63;
    loc_0x18003ae8b: // orphan
         edx = 0
         rcx = rax
         fcn.180080580 ()         // fcn.180080580(0x0, 0x0)
         
         goto loc_0x18003ae97;
    loc_0x18003aeab: // orphan
         qword [0x180100920] = rbx // [0x180100920:8]=0
         
         goto loc_0x18003aeb4;
    loc_0x18003aeb4: // orphan
         // CODE XREF from fcn.18003ade0 @ 0x18003aea9(x)
         rbx = qword [0x180100920] // [0x180100920:8]=0

    loc_0x18003aebb: // orphan
         // CODE XREF from fcn.18003ade0 @ 0x18003aeb2(x)
         qword [rbx + 0x48] = r15
         qword [rbx + 0x50] = r15
         dword [rbx + 0x28] |= 1
         rsi = qword [rbx + 0x60]
         qword [var_48h] = r15
         r8 = var_48h
         r14 = rip + str.C:WindowsFontsmsyh.ttc // 0x1800e3f08 // "C:\\Windows\\Fonts\\msyh.ttc"
         rcx = r14                // "C:\Windows\Fonts\msyh.ttc" str.C:WindowsFontsmsyh.ttc
         fcn.18007c930 ()         // fcn.18007c930(0x0)
         rdi = rax
         v = rax & rax
         if (v) 
         goto loc_0x18003aeec;
    loc_0x18003aeec: // orphan
         rdx = r14
         rcx = rip + str.While_loading__s_n // 0x1800e9a28 // "While loading '%s'\n"
         fcn.18009a210 ()         // fcn.18009a210(0x0, 0x0, 0x0, 0x1800e9a28)
         rcx = rip + str.Could_not_load_font_file_ // 0x1800e9a50 // "Could not load font file!"
         fcn.180091730 ()         // fcn.180091730(0x0, 0x0)
         
         goto loc_0x18003af0c;
    loc_0x18003af0c: // orphan
         // CODE XREF from fcn.18003ade0 @ 0x18003aeea(x)
         xmm2 ^= xmm2
         xmmword [var_60h] = xmm2
         xmmword [var_bp_40h] = xmm2
         xmmword [var_30h] = xmm2
         xmmword [var_20h] = xmm2
         byte [var_5ch] = 1
         dword [var_58h] = 0
         dword [var_34h] = 0x7f7fffff
         dword [var_24h] = 0x3f800000
         dword [var_20h] = 0x3f800000
         xmmword [var_30h_2] = xmm2
         xmmword [rbp + 0x40] = xmm2
         xmmword [var_50h] = xmm2
         xmm0 = xmmword [var_60h]
         xmmword [var_60h_2] = xmm0
         xmmword [var_70h] = xmm2
         xmm0 = xmmword [var_bp_40h]
         xmmword [var_80h] = xmm0
         xmm1 = xmmword [var_30h]
         xmmword [var_90h] = xmm1
         xmm0 = xmmword [var_20h]
         xmmword [var_a0h] = xmm0
         xmmword [var_b0h] = xmm2
         r9 = rip + 0xa8f9b       // 0x1800e3f21

    loc_0x18003af90: // orphan
         // CODE XREF from fcn.18003ade0 @ 0x18003afa5(x)
         rcx = r9 - 1
         eax = byte [rcx]
         v = al - 0x2f            // '/' // 47
         if (!v) 
         goto loc_0x18003af9b;
    loc_0x18003af9b: // orphan
         v = al - 0x5c            // '\\' // 92
         if (!v) 
         goto loc_0x18003af9f;
    loc_0x18003af9f: // orphan
         r9 = rcx
         v = rcx - r14
         if (((unsigned) v) > 0) 
         goto loc_0x18003afa7;
    loc_0x18003afa7: // orphan
         // CODE XREFS from fcn.18003ade0 @ 0x18003af99(x), 0x18003af9d(x)
         r8 = rip + 0xa9f8a       // "%s" // 0x1800e4f38
         edx = 0x28               // '(' // 40
         rcx = var_30h_2
         fcn.18007c4b0 ()         // fcn.18007c4b0(0x0, 0x0, 0x28, 0x178030)
         eax = dword [var_48h]
         xmm0 = xmmword [var_30h_2]
         xmmword [var_sp_70h] = xmm0
         xmm1 = xmmword [rbp + 0x40]
         xmmword [var_80h_2] = xmm1
         xmm0 = xmmword [var_50h]
         xmmword [var_70h_2] = xmm0
         xmm1 = xmmword [var_60h_2]
         xmmword [var_60h] = xmm1
         xmm0 = xmmword [var_70h]
         xmmword [var_50h_2] = xmm0
         xmm1 = xmmword [var_80h]
         xmmword [var_bp_40h] = xmm1
         xmm0 = xmmword [var_90h]
         xmmword [var_30h] = xmm0
         xmm1 = xmmword [var_a0h]
         xmmword [var_20h] = xmm1
         xmm0 = xmmword [var_b0h]
         xmmword [var_10h] = xmm0
         qword [var_68h] = rdi
         dword [var_60h] = eax
         dword [var_54h] = 0x41880000
         rdx = var_sp_70h
         rcx = rsi
         fcn.1800a90b0 ()         // fcn.1800a90b0(0x0, 0x0)
         v = rax & rax
         if (v) 
         goto loc_0x18003b035;
    loc_0x18003b035: // orphan
         // CODE XREF from fcn.18003ade0 @ 0x18003af07(x)
         rcx = qword [rbx + 0x60]
         fcn.1800a9520 ()         // fcn.1800a9520(0x0)
         xmm0 ^= xmm0
         xmmword [var_sp_20h] = xmm0
         xmm1 ^= xmm1
         xmmword [var_sp_30h] = xmm1
         r8d = 0x46               // 'F'
         rdx = rip + str.Microsoft_YaHei_UI_font_was_unavailable__using_the_ImGui_default_font. // 0x1800e3f30 // "Microsoft YaHei UI font was unavailable; using the ImGui default font."
         rcx = var_sp_20h
         fcn.180008090 ()         // fcn.180008090(0x0, 0x0, 0x1800e3f30)
         rcx = var_sp_20h
         fcn.18003a9f0 ()         // fcn.18003a9f0(0x0)
         rcx = var_sp_20h
         fcn.180008440 ()         // fcn.180008440(0x0)

    loc_0x18003b07c: // orphan
         // CODE XREF from fcn.18003ade0 @ 0x18003b033(x)
         fcn.180076fa0 ()
         rcx = qword [0x180102b78] // [0x180102b78:8]=0x2b992dc8dfca
         fcn.1800c82e0 ()         // fcn.1800c82e0(0x0)
         v = al & al
         if (v) 
         goto loc_0x18003b091;
    loc_0x18003b091: // orphan
         xmm0 ^= xmm0
         xmmword [var_sp_20h] = xmm0
         xmm1 ^= xmm1
         xmmword [var_sp_30h] = xmm1
         r8d = 0x2a               // '*' // 42
         rdx = rip + str.ImGui_Win32_backend_initialization_failed. // 0x1800e3f78 // "ImGui Win32 backend initialization failed."
         rcx = var_sp_20h
         fcn.180008090 ()         // fcn.180008090(0x0, 0x0, 0x1800e3f78)
         rcx = var_sp_20h
         fcn.18003a9f0 ()         // fcn.18003a9f0(0x0)
         rcx = var_sp_20h
         fcn.180008440 ()         // fcn.180008440(0x0)
         fcn.1800804c0 ()
         al = 0
         
         goto loc_0x18003b0db;
    loc_0x18003b0db: // orphan
         // CODE XREF from fcn.18003ade0 @ 0x18003b08f(x)
         fcn.1800ca450 ()
         v = al & al
         if (v) 
         goto loc_0x18003b0e4;
    loc_0x18003b0e4: // orphan
         xmm0 ^= xmm0
         xmmword [var_sp_20h] = xmm0
         xmm1 ^= xmm1
         xmmword [var_sp_30h] = xmm1
         r8d = 0x2b               // '+' // 43
         rdx = rip + str.ImGui_OpenGL_backend_initialization_failed. // 0x1800e3fb8 // "ImGui OpenGL backend initialization failed."
         rcx = var_sp_20h
         fcn.180008090 ()         // fcn.180008090(0x0, 0x0, 0x1800e3fb8)
         rcx = var_sp_20h
         fcn.18003a9f0 ()         // fcn.18003a9f0(0x0)
         rcx = var_sp_20h
         fcn.180008440 ()         // fcn.180008440(0x0)
         fcn.1800c84b0 ()
         fcn.1800804c0 ()
         al = 0
         
         goto loc_0x18003b133;
    loc_0x18003b133: // orphan
         // CODE XREF from fcn.18003ade0 @ 0x18003b0e2(x)
         fcn.180067210 ()
         xmm0 ^= xmm0
         xmm1 ^= xmm1
         rcx = var_sp_20h
         xmmword [var_sp_20h] = xmm0
         xmmword [var_sp_30h] = xmm1
         v = al & al
         if (v) 
         goto loc_0x18003b152;
    loc_0x18003b152: // orphan
         rbx = rip + 0xc4e8f      // 0x1800fffe8
         v = qword [0x1800ffff1] - 0xf // [0x180100000:8]=15
         cmova rbx qword [0x1800fffe8] // [0x1800fffe8:8]=0
         r8d = 0x18               // 24
         rdx = rip + str.Glass_blur_unavailable: // 0x1800e3fe8 // "Glass blur unavailable:"
         fcn.180008090 ()         // fcn.180008090(0x0, 0x0, 0x1800e3fe8)
         rcx = rbx                // const char *s
         sub.api_ms_win_crt_string_l1_1_0.dll_strlen () // size_t strlen("")
         r8 = rax
         rdx = rbx
         rcx = var_sp_20h
         fcn.180008dd0 ()         // fcn.180008dd0(0x0, 0x0, 0x1800fffe8)
         xmm0 = xmmword [rax]
         xmmword [var_sp_50h] = xmm0
         xmm1 = xmmword [rax + 0x10]
         xmmword [var_sp_60h] = xmm1
         qword [rax + 0x10] = r15
         qword [rax + 0x18] = 0xf // [0xf:8]=255
         byte [rax] = 0
         rcx = var_sp_50h
         fcn.18003a9f0 ()         // fcn.18003a9f0(0x0)
         rcx = var_sp_50h
         fcn.180008440 ()         // fcn.180008440(0x0)
         
         goto loc_0x18003b1cc;
    loc_0x18003b1cc: // orphan
         // CODE XREF from fcn.18003ade0 @ 0x18003b150(x)
         r8d = 0x17
         rdx = rip + str.Glass_blur_initialized. // 0x1800e4008 // "Glass blur initialized."
         fcn.180008090 ()         // fcn.180008090(0x0, 0x0, 0x1800e4008)
         rcx = var_sp_20h
         fcn.18003a9f0 ()         // fcn.18003a9f0(0x0)

    loc_0x18003b1ea: // orphan
         // CODE XREF from fcn.18003ade0 @ 0x18003b1ca(x)
         rcx = var_sp_20h
         fcn.180008440 ()         // fcn.180008440(0x0)
         fcn.180032140 ()
         byte [0x18010118d] = al  // [0x18010118d:1]=0
         edx = dword [0x180102880] // [0x180102880:4]=0
         dword [0x180102ba8] = edx // [0x180102ba8:4]=0
         rcx = var_10h_2
         fcn.18000d010 ()         // fcn.18000d010(0x0, 0x0)
         rdi = rax
         rax = rip + str.Native_model_chams_OpenGL_hooks_initialized__status // 0x1800e4020 // "Native model chams OpenGL hooks initialized, status="
         rbx = rip + str.Native_model_chams_OpenGL_hooks_could_not_be_initialized__status // 0x1800e4060 // "Native model chams OpenGL hooks could not be initialized, status="
         v = byte [0x18010118d] - 0 // [0x18010118d:1]=0
         if (!zf) rbx = rax
         xmm0 ^= xmm0
         xmmword [var_sp_20h] = xmm0
         xmm1 ^= xmm1
         xmmword [var_sp_30h] = xmm1
         rcx = rbx                // const char *s // "Native model chams OpenGL hooks could not be initialized, statu" str.Native_model_chams_OpenGL_hooks_could_not_be_initialized__status
         sub.api_ms_win_crt_string_l1_1_0.dll_strlen () // size_t strlen("Native model chams OpenGL hooks could not be initialized, status=")
         r8 = rax                 // "Native model chams OpenGL hooks initialized, status=" str.Native_model_chams_OpenGL_hooks_initialized__status
         rdx = rbx                // "Native model chams OpenGL hooks could not be initialized, statu" str.Native_model_chams_OpenGL_hooks_could_not_be_initialized__status
         rcx = var_sp_20h         // rsp
         fcn.180008090 ()         // fcn.180008090(0x0, 0x0, 0x1800e4060)
         r9 = rdi
         r8 = var_sp_20h
         rcx = var_sp_50h
         fcn.180012f60 ()         // fcn.180012f60(0x0, 0x0, 0x1800e4060)
         rcx = var_sp_50h
         fcn.18003a9f0 ()         // fcn.18003a9f0(0x0)
         rcx = var_sp_50h
         fcn.180008440 ()         // fcn.180008440(0x0)
         rcx = var_sp_20h
         fcn.180008440 ()         // fcn.180008440(0x0)
         rcx = var_10h_2
         fcn.180008440 ()         // fcn.180008440(0x0)
         ecx = 0                  // DWORD dwErrCode
         qword [sym.imp.KERNEL32.dll_SetLastError] () // [0x1800d4118:8]=0xfcbe6 reloc.KERNEL32.dll_SetLastError // reloc.KERNEL32.dll_SetLastError // VOID SetLastError(0)
         r8 = rip - 0x5e6         // 0x18003acc0 // LONG_PTR dwNewLong
         edx = 0xfffffffc         // 4294967292 // int nIndex
         rcx = qword [0x180102b78] // [0x180102b78:8]=0x2b992dc8dfca // HWND hWnd
         qword [sym.imp.USER32.dll_SetWindowLongPtrW] () // [0x1800d4518:8]=0xfc9e6 reloc.USER32.dll_SetWindowLongPtrW // reloc.USER32.dll_SetWindowLongPtrW // LONG_PTR SetWindowLongPtrW(-1, -1, 0xec83485756555340)
         qword [0x180102bb8] = rax // [0x180102bb8:8]=0
         v = rax & rax
         if (v) 
         goto loc_0x18003b2c4;
    loc_0x18003b2c4: // orphan
         qword [sym.imp.KERNEL32.dll_GetLastError] () // [0x1800d4148:8]=0xfcc44 reloc.KERNEL32.dll_GetLastError // "D\xcc\x0f" // reloc.KERNEL32.dll_GetLastError // DWORD GetLastError(void)
         v = eax & eax
         if (!v) 
         goto loc_0x18003b2ce;
    loc_0x18003b2ce: // orphan
         xmm0 ^= xmm0
         xmmword [var_sp_20h] = xmm0
         xmm1 ^= xmm1
         xmmword [var_sp_30h] = xmm1
         r8d = 0x2d               // '-' // 45
         rdx = rip + str.Failed_to_install_the_game_window_input_hook. // 0x1800e40a8 // "Failed to install the game-window input hook."
         rcx = var_sp_20h
         fcn.180008090 ()         // fcn.180008090(0x0, 0x0, 0x1800e40a8)
         rcx = var_sp_20h
         fcn.18003a9f0 ()         // fcn.18003a9f0(0x0)
         rcx = var_sp_20h
         fcn.180008440 ()         // fcn.180008440(0x0)
         fcn.1800ca6f0 ()
         fcn.1800c84b0 ()
         fcn.1800804c0 ()
         al = 0
         
         goto loc_0x18003b31f;
    loc_0x18003b31f: // orphan
         // CODE XREFS from fcn.18003ade0 @ 0x18003b2c2(x), 0x18003b2cc(x)
         byte [0x18010118c] = 1   // [0x18010118c:1]=0
         xmm0 ^= xmm0
         xmmword [var_sp_20h] = xmm0
         xmm1 ^= xmm1
         xmmword [var_sp_30h] = xmm1
         r8d = 0x39               // '9'
         rdx = rip + str.ImGui_initialized._Press_Insert_to_show_or_hide_the_menu. // 0x1800e40d8 // "ImGui initialized. Press Insert to show or hide the menu."
         rcx = var_sp_20h
         fcn.180008090 ()         // fcn.180008090(0x0, 0x0, 0x1800e40d8)
         rcx = var_sp_20h
         fcn.18003a9f0 ()         // fcn.18003a9f0(0x0)
         rcx = var_sp_20h
         fcn.180008440 ()         // fcn.180008440(0x0)
         al = 1

    loc_0x18003b366: // orphan
         // CODE XREFS from fcn.18003ade0 @ 0x18003ae5e(x), 0x18003b0d6(x), 0x18003b12e(x), 0x18003b31d(x)
         rcx = qword [var_c0h]
         rcx ^= rsp
         fcn.1800cd520 ()         // fcn.1800cd520(0x0)
         rsp += 0x1d8
         r15 = pop ()
         r14 = pop ()
         rdi = pop ()
         rsi = pop ()
         rbx = pop ()
         rbp = pop ()
         return

}

