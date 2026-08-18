// callconv: rax ms (rcx, rdx, r8, r9, stack);
void fcn.18002a7c0 (int64_t arg1) {
        // CALL XREF from fcn.18002d670 @ 0x18002d707(x)
        push (rbx)
        rsp -= 0x20
        v = byte [0x180102490] - 0 // [0x180102490:1]=0
        rbx = rcx    // arg1
        if (!v) goto loc_0x18002a7da // likely
        return rax;
    loc_0x18002a7da:
        // CODE XREF from fcn.18002a7c0 @ 0x18002a7d0(x)
        rdx = rip + str.zombie_characters_IsoPlayer // 0x1800d74b0 // "zombie/characters/IsoPlayer"
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_inventory_InventoryItem // 0x1800de6e0 // "zombie/inventory/InventoryItem"
        qword [0x180102498] = rax // [0x180102498:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_inventory_types_HandWeapon // 0x1800de350 // "zombie/inventory/types/HandWeapon"
        qword [0x1801024a0] = rax // [0x1801024a0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_core_physics_BallisticsController // 0x1800e2f40 // "zombie/core/physics/BallisticsController"
        qword [0x1801024a8] = rax // [0x1801024a8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_iso_Vector3 // 0x1800e2f70 // "zombie/iso/Vector3"
        qword [0x1801024b0] = rax // [0x1801024b0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_iso_Vector2 // 0x1800e2f88 // "zombie/iso/Vector2"
        qword [0x1801024b8] = rax // [0x1801024b8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_input_Mouse // 0x1800e2a78 // "zombie/input/Mouse"
        qword [0x1801024c0] = rax // [0x1801024c0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_iso_IsoUtils // 0x1800d75c8 // "zombie/iso/IsoUtils"
        qword [0x1801024c8] = rax // [0x1801024c8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_network_GameClient // 0x1800d7470 // "zombie/network/GameClient"
        qword [0x1801024d0] = rax // [0x1801024d0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_core_raknet_UdpConnection // 0x1800e2fa0 // "zombie/core/raknet/UdpConnection"
        qword [0x1801024d8] = rax // [0x1801024d8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_CombatManager // 0x1800d7748 // "zombie/CombatManager"
        qword [0x1801024e0] = rax // [0x1801024e0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_ai_states_SwipeStatePlayer // 0x1800e2fc8 // "zombie/ai/states/SwipeStatePlayer"
        qword [0x1801024e8] = rax // [0x1801024e8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = qword [0x180102498] // [0x180102498:8]=0
        qword [0x1801024f0] = rax // [0x1801024f0:8]=0
        v = rdx & rdx
        if (!v) goto loc_0x18002b7e1 // likely
        goto loc_0x18002a8ef;
    loc_0x18002b7e1:
        // XREFS: CODE 0x18002a8e9  CODE 0x18002a8f7  CODE 0x18002a905
        // XREFS: CODE 0x18002a913  CODE 0x18002a921  CODE 0x18002a92f
        // XREFS: CODE 0x18002a93d  CODE 0x18002a94b  CODE 0x18002a959
        // XREFS: CODE 0x18002a967  CODE 0x18002a975  CODE 0x18002a97e
        al = 0
        rsp += 0x20
        rbx = pop ()
        return
        goto loc_0x18002a8fd;
    loc_0x18002a7d2: // orphan
         al = 1
         rsp += 0x20
         rbx = pop ()
         return

    loc_0x18002a8ef: // orphan
         v = qword [0x1801024a0] - 0 // [0x1801024a0:8]=0
         if (!v) 
         goto loc_0x18002a8fd;
    loc_0x18002a8fd: // orphan
         v = qword [0x1801024a8] - 0 // [0x1801024a8:8]=0
         if (!v) 
         goto loc_0x18002a90b;
    loc_0x18002a90b: // orphan
         v = qword [0x1801024b0] - 0 // [0x1801024b0:8]=0
         if (!v) 
         goto loc_0x18002a919;
    loc_0x18002a919: // orphan
         v = qword [0x1801024b8] - 0 // [0x1801024b8:8]=0
         if (!v) 
         goto loc_0x18002a927;
    loc_0x18002a927: // orphan
         v = qword [0x1801024c0] - 0 // [0x1801024c0:8]=0
         if (!v) 
         goto loc_0x18002a935;
    loc_0x18002a935: // orphan
         v = qword [0x1801024c8] - 0 // [0x1801024c8:8]=0
         if (!v) 
         goto loc_0x18002a943;
    loc_0x18002a943: // orphan
         v = qword [0x1801024d0] - 0 // [0x1801024d0:8]=0
         if (!v) 
         goto loc_0x18002a951;
    loc_0x18002a951: // orphan
         v = qword [0x1801024d8] - 0 // [0x1801024d8:8]=0
         if (!v) 
         goto loc_0x18002a95f;
    loc_0x18002a95f: // orphan
         v = qword [0x1801024e0] - 0 // [0x1801024e0:8]=0
         if (!v) 
         goto loc_0x18002a96d;
    loc_0x18002a96d: // orphan
         v = qword [0x1801024e8] - 0 // [0x1801024e8:8]=0
         if (!v) 
         goto loc_0x18002a97b;
    loc_0x18002a97b: // orphan
         v = rax & rax
         if (!v) 
         goto loc_0x18002a984;
    loc_0x18002a984: // orphan
         rax = qword [rbx]
         r9 = rip + str.__Lzombie_characters_IsoPlayer_ // 0x1800d78c8 // "()Lzombie/characters/IsoPlayer;"
         r8 = rip + str.getInstance // 0x1800d78e8 // "getInstance"
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + 0xacfc8       // "()I" // 0x1800d7974
         qword [0x1801024f8] = rax // [0x1801024f8:8]=0
         r8 = rip + str.getID     // 0x1800d7a0c // "getID"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str.__Lzombie_inventory_InventoryItem_ // 0x1800de398 // "()Lzombie/inventory/InventoryItem;"
         qword [0x1801026f8] = rax // [0x1801026f8:8]=0
         r8 = rip + str.getPrimaryHandItem // 0x1800de3c0 // "getPrimaryHandItem"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + 0xacfc8       // "()Z" // 0x1800d79c4
         qword [0x180102500] = rax // [0x180102500:8]=0
         r8 = rip + str.isAiming  // 0x1800e2a90 // "isAiming"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         qword [0x180102508] = rax // [0x180102508:8]=0
         r8 = rip + str.setIsAiming // 0x1800e2ff0 // "setIsAiming"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + 0xacf78       // "()Z" // 0x1800d79c4
         qword [0x180102510] = rax // [0x180102510:8]=0
         r8 = rip + str.isForceAim // 0x1800e3000 // "isForceAim"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         qword [0x180102518] = rax // [0x180102518:8]=0
         r8 = rip + str.setForceAim // 0x1800e3010 // "setForceAim"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + 0xacdf0       // "Z" // 0x1800d788c
         qword [0x180102520] = rax // [0x180102520:8]=0
         r8 = rip + str.isCharging // 0x1800e3020 // "isCharging"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x2f0] ()   // 752 // 0x2f0(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + 0xad5b4       // "()V" // 0x1800d8078
         qword [0x180102528] = rax // [0x180102528:8]=0
         r8 = rip + str.updateBallistics // 0x1800e3030 // "updateBallistics"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + 0xad58c       // "()V" // 0x1800d8078
         qword [0x180102530] = rax // [0x180102530:8]=0
         r8 = rip + str.setAngleFromAim // 0x1800e3048 // "setAngleFromAim"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + 0xaceb0       // "()Z" // 0x1800d79c4
         qword [0x180102538] = rax // [0x180102538:8]=0
         r8 = rip + str.isAttackStarted // 0x1800e3058 // "isAttackStarted"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str.__Lzombie_core_physics_BallisticsController_ // 0x1800e3068 // "()Lzombie/core/physics/BallisticsController;"
         qword [0x180102540] = rax // [0x180102540:8]=0
         r8 = rip + str.getBallisticsController // 0x1800e3098 // "getBallisticsController"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180102548] = rax // [0x180102548:8]=0
         r8 = rip + str.setRecoilVarX // 0x1800e2aa0 // "setRecoilVarX"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180102550] = rax // [0x180102550:8]=0
         r8 = rip + str.setRecoilVarY // 0x1800e2ab0 // "setRecoilVarY"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + 0xace3c       // "()F" // 0x1800d79f0
         qword [0x180102558] = rax // [0x180102558:8]=0
         r8 = rip + str.getAimOriginPosX // 0x1800e30b0 // "getAimOriginPosX"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + 0xace14       // "()F" // 0x1800d79f0
         qword [0x180102560] = rax // [0x180102560:8]=0
         r8 = rip + str.getAimOriginPosY // 0x1800e30c8 // "getAimOriginPosY"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + 0xacdec       // "()F" // 0x1800d79f0
         qword [0x180102568] = rax // [0x180102568:8]=0
         r8 = rip + str.getAimOriginPosZ // 0x1800e30e0 // "getAimOriginPosZ"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + 0xacdc4       // "()F" // 0x1800d79f0
         qword [0x180102570] = rax // [0x180102570:8]=0
         r8 = rip + str.getForwardDirectionX // 0x1800d7ab0 // "getForwardDirectionX"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + 0xacd9c       // "()F" // 0x1800d79f0
         qword [0x180102578] = rax // [0x180102578:8]=0
         r8 = rip + str.getForwardDirectionY // 0x1800d7ac8 // "getForwardDirectionY"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._FF_V     // 0x1800e1f78 // "(FF)V"
         qword [0x180102580] = rax // [0x180102580:8]=0
         r8 = rip + str.setForwardDirection // 0x1800e30f8 // "setForwardDirection"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180102588] = rax // [0x180102588:8]=0
         r8 = rip + str.setTargetVerticalAimAngle // 0x1800e3110 // "setTargetVerticalAimAngle"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180102590] = rax // [0x180102590:8]=0
         r8 = rip + str.setCurrentVerticalAimAngle // 0x1800e3130 // "setCurrentVerticalAimAngle"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180102598] = rax // [0x180102598:8]=0
         r8 = rip + str.setMoveDelta // 0x1800e3150 // "setMoveDelta"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x1801025a0] = rax // [0x1801025a0:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         rax = qword [rbx]
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r8 = rip + str.setMoving // 0x1800e3160 // "setMoving"
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         qword [0x1801025a8] = rax // [0x1801025a8:8]=0
         r8 = rip + str.setRunning // 0x1800e3170 // "setRunning"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         qword [0x1801025b0] = rax // [0x1801025b0:8]=0
         r8 = rip + str.setSprinting // 0x1800e3180 // "setSprinting"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + 0xacc30       // "()Z" // 0x1800d79c4
         qword [0x1801025b8] = rax // [0x1801025b8:8]=0
         r8 = rip + str.isAllowRun // 0x1800e3190 // "isAllowRun"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         qword [0x1801025c0] = rax // [0x1801025c0:8]=0
         r8 = rip + str.setAllowRun // 0x1800e31a0 // "setAllowRun"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + 0xacbe0       // "()Z" // 0x1800d79c4
         qword [0x1801025c8] = rax // [0x1801025c8:8]=0
         r8 = rip + str.isAllowSprint // 0x1800e31b0 // "isAllowSprint"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         qword [0x1801025d0] = rax // [0x1801025d0:8]=0
         r8 = rip + str.setAllowSprint // 0x1800e31c0 // "setAllowSprint"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + 0xacb90       // "()Z" // 0x1800d79c4
         qword [0x1801025d8] = rax // [0x1801025d8:8]=0
         r8 = rip + str.isIgnoreInputsForDirection // 0x1800e31d0 // "isIgnoreInputsForDirection"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         qword [0x1801025e0] = rax // [0x1801025e0:8]=0
         r8 = rip + str.setIgnoreInputsForDirection // 0x1800e31f0 // "setIgnoreInputsForDirection"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         qword [0x1801025e8] = rax // [0x1801025e8:8]=0
         r8 = rip + str.setForceRun // 0x1800e3210 // "setForceRun"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         qword [0x1801025f0] = rax // [0x1801025f0:8]=0
         r8 = rip + str.setForceSprint // 0x1800e3220 // "setForceSprint"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + 0xacaf0       // "()Z" // 0x1800d79c4
         qword [0x1801025f8] = rax // [0x1801025f8:8]=0
         r8 = rip + str.isBlockMovement // 0x1800e3230 // "isBlockMovement"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         qword [0x180102600] = rax // [0x180102600:8]=0
         r8 = rip + str.setBlockMovement // 0x1800e3240 // "setBlockMovement"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str.Lzombie_iso_Vector2_ // 0x1800e3258 // "Lzombie/iso/Vector2;"
         qword [0x180102608] = rax // [0x180102608:8]=0
         r8 = rip + str.playerMoveDir // 0x1800e3270 // "playerMoveDir"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x2f0] ()   // 752 // 0x2f0(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str.__Lzombie_iso_Vector2_ // 0x1800e3280 // "()Lzombie/iso/Vector2;"
         qword [0x180102610] = rax // [0x180102610:8]=0
         r8 = rip + str.getMoveForwardVec // 0x1800e3298 // "getMoveForwardVec"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024a0] // [0x1801024a0:8]=0
         r9 = rip + str.__Ljava_lang_String_ // 0x1800d7b40 // "()Ljava/lang/String;"
         qword [0x180102618] = rax // [0x180102618:8]=0
         r8 = rip + str.getFullType // 0x1800de978 // "getFullType"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024a0] // [0x1801024a0:8]=0
         r9 = rip + 0xac9d8       // "()I" // 0x1800d7974
         qword [0x180102620] = rax // [0x180102620:8]=0
         r8 = rip + str.getCurrentAmmoCount // 0x1800df588 // "getCurrentAmmoCount"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024a8] // [0x1801024a8:8]=0
         r9 = rip + 0xaca00       // "()Z" // 0x1800d79c4
         qword [0x180102628] = rax // [0x180102628:8]=0
         r8 = rip + str.isRanged  // 0x1800e06c8 // "isRanged"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024a8] // [0x1801024a8:8]=0
         r9 = rip + 0xaca04       // "()F" // 0x1800d79f0
         qword [0x180102630] = rax // [0x180102630:8]=0
         r8 = rip + str.getMaxRange // 0x1800e2ac0 // "getMaxRange"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024a8] // [0x1801024a8:8]=0
         r9 = rip + 0xac9dc       // "()F" // 0x1800d79f0
         qword [0x180102638] = rax // [0x180102638:8]=0
         r8 = rip + str.getProjectileSpread // 0x1800e32b0 // "getProjectileSpread"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024a8] // [0x1801024a8:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180102640] = rax // [0x180102640:8]=0
         r8 = rip + str.setProjectileSpread // 0x1800e32c8 // "setProjectileSpread"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024a8] // [0x1801024a8:8]=0
         r9 = rip + 0xac910       // "()I" // 0x1800d7974
         qword [0x180102648] = rax // [0x180102648:8]=0
         r8 = rip + str.getHitChance // 0x1800e32e0 // "getHitChance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024a8] // [0x1801024a8:8]=0
         r9 = rip + str._I_V      // 0x1800df59c // "(I)V"
         qword [0x180102650] = rax // [0x180102650:8]=0
         r8 = rip + str.setHitChance // 0x1800e32f0 // "setHitChance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x180102658] = rax // [0x180102658:8]=0
         r9 = rip + 0xac93c       // "()F" // 0x1800d79f0
         rax = qword [rbx]
         r8 = rip + str.getMinDamage // 0x1800e3300 // "getMinDamage"
         rdx = qword [0x1801024a8] // [0x1801024a8:8]=0
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024a8] // [0x1801024a8:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180102660] = rax // [0x180102660:8]=0
         r8 = rip + str.setMinDamage // 0x1800e3310 // "setMinDamage"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024a8] // [0x1801024a8:8]=0
         r9 = rip + 0xac8ec       // "()F" // 0x1800d79f0
         qword [0x180102668] = rax // [0x180102668:8]=0
         r8 = rip + str.getMaxDamage // 0x1800e2ad0 // "getMaxDamage"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024a8] // [0x1801024a8:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180102670] = rax // [0x180102670:8]=0
         r8 = rip + str.setMaxDamage // 0x1800e3320 // "setMaxDamage"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024a8] // [0x1801024a8:8]=0
         r9 = rip + 0xac820       // "()I" // 0x1800d7974
         qword [0x180102678] = rax // [0x180102678:8]=0
         r8 = rip + str.getAimingTime // 0x1800e3330 // "getAimingTime"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024a8] // [0x1801024a8:8]=0
         r9 = rip + str._I_V      // 0x1800df59c // "(I)V"
         qword [0x180102680] = rax // [0x180102680:8]=0
         r8 = rip + str.setAimingTime // 0x1800e3340 // "setAimingTime"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180102688] = rax // [0x180102688:8]=0
         r8 = rip + str.setAimingDelay // 0x1800e3350 // "setAimingDelay"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180102690] = rax // [0x180102690:8]=0
         r8 = rip + str.setBeenMovingFor // 0x1800e3360 // "setBeenMovingFor"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024b0] // [0x1801024b0:8]=0
         r9 = rip + str.__Lzombie_iso_Vector3_ // 0x1800e2ef0 // "()Lzombie/iso/Vector3;"
         qword [0x180102698] = rax // [0x180102698:8]=0
         r8 = rip + str.getIsoAimingPosition // 0x1800e2f08 // "getIsoAimingPosition"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024b0] // [0x1801024b0:8]=0
         r9 = rip + str.Lzombie_iso_Vector3_ // 0x1800e3378 // "Lzombie/iso/Vector3;"
         qword [0x1801026a0] = rax // [0x1801026a0:8]=0
         r8 = rip + str.targetPosition // 0x1800e3390 // "targetPosition"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x2f0] ()   // 752 // 0x2f0(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024b8] // [0x1801024b8:8]=0
         r9 = rip + str._FFF_Lzombie_iso_Vector3_ // 0x1800e2f20 // "(FFF)Lzombie/iso/Vector3;"
         qword [0x1801026a8] = rax // [0x1801026a8:8]=0
         r8 = rip + 0xb3a2a       // "set" // 0x1800dec7c
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024c0] // [0x1801024c0:8]=0
         r9 = rip + str._FF_Lzombie_iso_Vector2_ // 0x1800e33a0 // "(FF)Lzombie/iso/Vector2;"
         qword [0x1801026b0] = rax // [0x1801026b0:8]=0
         r8 = rip + 0xb3a02       // "set" // 0x1800dec7c
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x1801026b8] = rax // [0x1801026b8:8]=0
         rax = qword [rbx]
         r9 = rip + 0xac6dd       // "()I" // 0x1800d7974
         rdx = qword [0x1801024c8] // [0x1801024c8:8]=0
         r8 = rip + str.getXA     // 0x1800e2ae0 // "getXA"
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024c8] // [0x1801024c8:8]=0
         r9 = rip + 0xac6b8       // "()I" // 0x1800d7974
         qword [0x1801026c0] = rax // [0x1801026c0:8]=0
         r8 = rip + str.getYA     // 0x1800e2ae8 // "getYA"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024d0] // [0x1801024d0:8]=0
         r9 = rip + str._FFFI_F   // 0x1800d7da0 // "(FFFI)F"
         qword [0x1801026c8] = rax // [0x1801026c8:8]=0
         r8 = rip + str.XToScreenExact // 0x1800d7da8 // "XToScreenExact"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024d0] // [0x1801024d0:8]=0
         r9 = rip + str._FFFI_F   // 0x1800d7da0 // "(FFFI)F"
         qword [0x1801026d0] = rax // [0x1801026d0:8]=0
         r8 = rip + str.YToScreenExact // 0x1800d7db8 // "YToScreenExact"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024d8] // [0x1801024d8:8]=0
         r9 = rip + 0xac558       // "Z" // 0x1800d788c
         qword [0x1801026d8] = rax // [0x1801026d8:8]=0
         r8 = rip + str.client    // 0x1800d7890 // "client"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024d8] // [0x1801024d8:8]=0
         r9 = rip + str.Lzombie_core_raknet_UdpConnection_ // 0x1800e33c0 // "Lzombie/core/raknet/UdpConnection;"
         qword [0x1801026e0] = rax // [0x1801026e0:8]=0
         r8 = rip + str.connection // 0x1800e33e8 // "connection"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024e0] // [0x1801024e0:8]=0
         r9 = rip + 0xac5f0       // "()I" // 0x1800d7974
         qword [0x1801026e8] = rax // [0x1801026e8:8]=0
         r8 = rip + str.getAveragePing // 0x1800e33f8 // "getAveragePing"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024e8] // [0x1801024e8:8]=0
         r9 = rip + str.__Lzombie_CombatManager_ // 0x1800e3408 // "()Lzombie/CombatManager;"
         qword [0x1801026f0] = rax // [0x1801026f0:8]=0
         r8 = rip + str.getInstance // 0x1800d78e8 // "getInstance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801024f0] // [0x1801024f0:8]=0
         r9 = rip + str.__Lzombie_ai_states_SwipeStatePlayer_ // 0x1800e3428 // "()Lzombie/ai/states/SwipeStatePlayer;"
         qword [0x180102700] = rax // [0x180102700:8]=0
         r8 = rip + str.instance  // 0x1800d78b8 // "instance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180102498] // [0x180102498:8]=0
         r9 = rip + str.__Lzombie_AttackType_ // 0x1800e3450 // "()Lzombie/AttackType;"
         qword [0x180102708] = rax // [0x180102708:8]=0
         r8 = rip + str.getAttackType // 0x1800e3468 // "getAttackType"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x180102710] = rax // [0x180102710:8]=0
         rcx = rbx
         rax = qword [rbx]
         qword [rax + 0x720] ()   // 1824 // 0x720(0x0, 0x0, 0x0, 0x0)
         v = al & al
         if (!v) 
         goto loc_0x18002b42d;
    loc_0x18002b42d: // orphan
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x88] ()    // 136 // 0x88(0x0, 0x0, 0x0, 0x0)

    loc_0x18002b439: // orphan
         // XREFS(68)
         al = 0
         byte [0x180102490] = al  // [0x180102490:1]=0
         rsp += 0x20
         rbx = pop ()
         return

    loc_0x18002b447: // orphan
         // CODE XREF from fcn.18002a7c0 @ 0x18002b42b(x)
         v = qword [0x1801024f8] - 0 // [0x1801024f8:8]=-1
         if (!v) 
         goto loc_0x18002b451;
    loc_0x18002b451: // orphan
         v = qword [0x1801026f8] - 0 // [0x1801026f8:8]=-1
         if (!v) 
         goto loc_0x18002b45b;
    loc_0x18002b45b: // orphan
         v = qword [0x180102500] - 0 // [0x180102500:8]=-1
         if (!v) 
         goto loc_0x18002b465;
    loc_0x18002b465: // orphan
         v = qword [0x180102508] - 0 // [0x180102508:8]=-1
         if (!v) 
         goto loc_0x18002b46f;
    loc_0x18002b46f: // orphan
         v = qword [0x180102510] - 0 // [0x180102510:8]=-1
         if (!v) 
         goto loc_0x18002b479;
    loc_0x18002b479: // orphan
         v = qword [0x180102518] - 0 // [0x180102518:8]=-1
         if (!v) 
         goto loc_0x18002b483;
    loc_0x18002b483: // orphan
         v = qword [0x180102520] - 0 // [0x180102520:8]=-1
         if (!v) 
         goto loc_0x18002b48d;
    loc_0x18002b48d: // orphan
         v = qword [0x180102528] - 0 // [0x180102528:8]=-1
         if (!v) 
         goto loc_0x18002b497;
    loc_0x18002b497: // orphan
         v = qword [0x180102530] - 0 // [0x180102530:8]=-1
         if (!v) 
         goto loc_0x18002b4a1;
    loc_0x18002b4a1: // orphan
         v = qword [0x180102538] - 0 // [0x180102538:8]=-1
         if (!v) 
         goto loc_0x18002b4ab;
    loc_0x18002b4ab: // orphan
         v = qword [0x180102540] - 0 // [0x180102540:8]=-1
         if (!v) 
         goto loc_0x18002b4b5;
    loc_0x18002b4b5: // orphan
         v = qword [0x180102548] - 0 // [0x180102548:8]=-1
         if (!v) 
         goto loc_0x18002b4c3;
    loc_0x18002b4c3: // orphan
         v = qword [0x180102550] - 0 // [0x180102550:8]=-1
         if (!v) 
         goto loc_0x18002b4d1;
    loc_0x18002b4d1: // orphan
         v = qword [0x180102558] - 0 // [0x180102558:8]=-1
         if (!v) 
         goto loc_0x18002b4df;
    loc_0x18002b4df: // orphan
         v = qword [0x180102560] - 0 // [0x180102560:8]=-1
         if (!v) 
         goto loc_0x18002b4ed;
    loc_0x18002b4ed: // orphan
         v = qword [0x180102568] - 0 // [0x180102568:8]=-1
         if (!v) 
         goto loc_0x18002b4fb;
    loc_0x18002b4fb: // orphan
         v = qword [0x180102570] - 0 // [0x180102570:8]=-1
         if (!v) 
         goto loc_0x18002b509;
    loc_0x18002b509: // orphan
         v = qword [0x180102578] - 0 // [0x180102578:8]=-1
         if (!v) 
         goto loc_0x18002b517;
    loc_0x18002b517: // orphan
         v = qword [0x180102580] - 0 // [0x180102580:8]=-1
         if (!v) 
         goto loc_0x18002b525;
    loc_0x18002b525: // orphan
         v = qword [0x180102588] - 0 // [0x180102588:8]=-1
         if (!v) 
         goto loc_0x18002b533;
    loc_0x18002b533: // orphan
         v = qword [0x180102590] - 0 // [0x180102590:8]=-1
         if (!v) 
         goto loc_0x18002b541;
    loc_0x18002b541: // orphan
         v = qword [0x180102598] - 0 // [0x180102598:8]=-1
         if (!v) 
         goto loc_0x18002b54f;
    loc_0x18002b54f: // orphan
         v = qword [0x1801025a0] - 0 // [0x1801025a0:8]=-1
         if (!v) 
         goto loc_0x18002b55d;
    loc_0x18002b55d: // orphan
         v = qword [0x1801025a8] - 0 // [0x1801025a8:8]=-1
         if (!v) 
         goto loc_0x18002b56b;
    loc_0x18002b56b: // orphan
         v = qword [0x1801025b0] - 0 // [0x1801025b0:8]=-1
         if (!v) 
         goto loc_0x18002b579;
    loc_0x18002b579: // orphan
         v = qword [0x1801025b8] - 0 // [0x1801025b8:8]=-1
         if (!v) 
         goto loc_0x18002b587;
    loc_0x18002b587: // orphan
         v = qword [0x1801025c0] - 0 // [0x1801025c0:8]=-1
         if (!v) 
         goto loc_0x18002b595;
    loc_0x18002b595: // orphan
         v = qword [0x1801025c8] - 0 // [0x1801025c8:8]=-1
         if (!v) 
         goto loc_0x18002b5a3;
    loc_0x18002b5a3: // orphan
         v = qword [0x1801025d0] - 0 // [0x1801025d0:8]=-1
         if (!v) 
         goto loc_0x18002b5b1;
    loc_0x18002b5b1: // orphan
         v = qword [0x1801025d8] - 0 // [0x1801025d8:8]=-1
         if (!v) 
         goto loc_0x18002b5bf;
    loc_0x18002b5bf: // orphan
         v = qword [0x1801025e0] - 0 // [0x1801025e0:8]=-1
         if (!v) 
         goto loc_0x18002b5cd;
    loc_0x18002b5cd: // orphan
         v = qword [0x1801025e8] - 0 // [0x1801025e8:8]=-1
         if (!v) 
         goto loc_0x18002b5db;
    loc_0x18002b5db: // orphan
         v = qword [0x1801025f0] - 0 // [0x1801025f0:8]=-1
         if (!v) 
         goto loc_0x18002b5e9;
    loc_0x18002b5e9: // orphan
         v = qword [0x1801025f8] - 0 // [0x1801025f8:8]=-1
         if (!v) 
         goto loc_0x18002b5f7;
    loc_0x18002b5f7: // orphan
         v = qword [0x180102600] - 0 // [0x180102600:8]=-1
         if (!v) 
         goto loc_0x18002b605;
    loc_0x18002b605: // orphan
         v = qword [0x180102608] - 0 // [0x180102608:8]=-1
         if (!v) 
         goto loc_0x18002b613;
    loc_0x18002b613: // orphan
         v = qword [0x180102610] - 0 // [0x180102610:8]=-1
         if (!v) 
         goto loc_0x18002b621;
    loc_0x18002b621: // orphan
         v = qword [0x180102618] - 0 // [0x180102618:8]=-1
         if (!v) 
         goto loc_0x18002b62f;
    loc_0x18002b62f: // orphan
         v = qword [0x180102620] - 0 // [0x180102620:8]=-1
         if (!v) 
         goto loc_0x18002b63d;
    loc_0x18002b63d: // orphan
         v = qword [0x180102628] - 0 // [0x180102628:8]=-1
         if (!v) 
         goto loc_0x18002b64b;
    loc_0x18002b64b: // orphan
         v = qword [0x180102630] - 0 // [0x180102630:8]=-1
         if (!v) 
         goto loc_0x18002b659;
    loc_0x18002b659: // orphan
         v = qword [0x180102638] - 0 // [0x180102638:8]=-1
         if (!v) 
         goto loc_0x18002b667;
    loc_0x18002b667: // orphan
         v = qword [0x180102640] - 0 // [0x180102640:8]=-1
         if (!v) 
         goto loc_0x18002b675;
    loc_0x18002b675: // orphan
         v = qword [0x180102648] - 0 // [0x180102648:8]=-1
         if (!v) 
         goto loc_0x18002b683;
    loc_0x18002b683: // orphan
         v = qword [0x180102650] - 0 // [0x180102650:8]=-1
         if (!v) 
         goto loc_0x18002b691;
    loc_0x18002b691: // orphan
         v = qword [0x180102658] - 0 // [0x180102658:8]=-1
         if (!v) 
         goto loc_0x18002b69f;
    loc_0x18002b69f: // orphan
         v = qword [0x180102660] - 0 // [0x180102660:8]=-1
         if (!v) 
         goto loc_0x18002b6ad;
    loc_0x18002b6ad: // orphan
         v = qword [0x180102668] - 0 // [0x180102668:8]=-1
         if (!v) 
         goto loc_0x18002b6bb;
    loc_0x18002b6bb: // orphan
         v = qword [0x180102670] - 0 // [0x180102670:8]=-1
         if (!v) 
         goto loc_0x18002b6c9;
    loc_0x18002b6c9: // orphan
         v = qword [0x180102678] - 0 // [0x180102678:8]=-1
         if (!v) 
         goto loc_0x18002b6d7;
    loc_0x18002b6d7: // orphan
         v = qword [0x180102680] - 0 // [0x180102680:8]=-1
         if (!v) 
         goto loc_0x18002b6e5;
    loc_0x18002b6e5: // orphan
         v = qword [0x180102688] - 0 // [0x180102688:8]=-1
         if (!v) 
         goto loc_0x18002b6f3;
    loc_0x18002b6f3: // orphan
         v = qword [0x180102690] - 0 // [0x180102690:8]=-1
         if (!v) 
         goto loc_0x18002b701;
    loc_0x18002b701: // orphan
         v = qword [0x180102698] - 0 // [0x180102698:8]=-1
         if (!v) 
         goto loc_0x18002b70f;
    loc_0x18002b70f: // orphan
         v = qword [0x1801026a0] - 0 // [0x1801026a0:8]=-1
         if (!v) 
         goto loc_0x18002b71d;
    loc_0x18002b71d: // orphan
         v = qword [0x1801026a8] - 0 // [0x1801026a8:8]=-1
         if (!v) 
         goto loc_0x18002b72b;
    loc_0x18002b72b: // orphan
         v = qword [0x1801026b0] - 0 // [0x1801026b0:8]=-1
         if (!v) 
         goto loc_0x18002b739;
    loc_0x18002b739: // orphan
         v = qword [0x1801026b8] - 0 // [0x1801026b8:8]=-1
         if (!v) 
         goto loc_0x18002b747;
    loc_0x18002b747: // orphan
         v = qword [0x1801026c0] - 0 // [0x1801026c0:8]=-1
         if (!v) 
         goto loc_0x18002b755;
    loc_0x18002b755: // orphan
         v = qword [0x1801026c8] - 0 // [0x1801026c8:8]=-1
         if (!v) 
         goto loc_0x18002b763;
    loc_0x18002b763: // orphan
         v = qword [0x1801026d0] - 0 // [0x1801026d0:8]=-1
         if (!v) 
         goto loc_0x18002b771;
    loc_0x18002b771: // orphan
         v = qword [0x1801026d8] - 0 // [0x1801026d8:8]=-1
         if (!v) 
         goto loc_0x18002b77f;
    loc_0x18002b77f: // orphan
         v = qword [0x1801026e0] - 0 // [0x1801026e0:8]=-1
         if (!v) 
         goto loc_0x18002b78d;
    loc_0x18002b78d: // orphan
         v = qword [0x1801026e8] - 0 // [0x1801026e8:8]=-1
         if (!v) 
         goto loc_0x18002b79b;
    loc_0x18002b79b: // orphan
         v = qword [0x1801026f0] - 0 // [0x1801026f0:8]=-1
         if (!v) 
         goto loc_0x18002b7a9;
    loc_0x18002b7a9: // orphan
         v = qword [0x180102700] - 0 // [0x180102700:8]=-1
         if (!v) 
         goto loc_0x18002b7b7;
    loc_0x18002b7b7: // orphan
         v = qword [0x180102708] - 0 // [0x180102708:8]=-1
         if (!v) 
         goto loc_0x18002b7c5;
    loc_0x18002b7c5: // orphan
         v = qword [0x180102710] - 0 // [0x180102710:8]=-1
         if (!v) 
         return rax;
    loc_0x18002b7d3: // orphan
         al = 1
         byte [0x180102490] = al  // [0x180102490:1]=0
         rsp += 0x20
         rbx = pop ()
         return

}

