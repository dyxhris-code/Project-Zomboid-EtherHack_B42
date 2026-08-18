// callconv: rax ms (rcx, rdx, r8, r9, stack);
void fcn.180009f30 (int64_t arg1) {
        // CALL XREF from fcn.18000b8a0 @ 0x18000b90b(x)
        // CALL XREF from fcn.18000be40 @ 0x18000bea6(x)
        // CALL XREF from fcn.18000c190 @ 0x18000c218(x)
        push (rbx)
        rsp -= 0x20
        v = byte [0x180101270] - 0 // [0x180101270:1]=0
        rbx = rcx    // arg1
        if (!v) goto loc_0x180009f4a // likely
        return rax;
    loc_0x180009f4a:
        // CODE XREF from fcn.180009f30 @ 0x180009f40(x)
        rdx = rip + str.zombie_network_GameClient // 0x1800d7470 // "zombie/network/GameClient"
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_network_GameServer // 0x1800d7490 // "zombie/network/GameServer"
        qword [0x180101278] = rax // [0x180101278:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_characters_IsoPlayer // 0x1800d74b0 // "zombie/characters/IsoPlayer"
        qword [0x180101280] = rax // [0x180101280:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_characters_IsoGameCharacter_XP // 0x1800dd980 // "zombie/characters/IsoGameCharacter$XP"
        qword [0x180101288] = rax // [0x180101288:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_characters_skills_PerkFactory_Perks // 0x1800dd9a8 // "zombie/characters/skills/PerkFactory$Perks"
        qword [0x180101290] = rax // [0x180101290:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_characters_skills_PerkFactory_Perk // 0x1800dd9d8 // "zombie/characters/skills/PerkFactory$Perk"
        qword [0x180101298] = rax // [0x180101298:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_radio_ZomboidRadio // 0x1800dda08 // "zombie/radio/ZomboidRadio"
        qword [0x1801012a0] = rax // [0x1801012a0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_radio_devices_WaveSignalDevice // 0x1800dda28 // "zombie/radio/devices/WaveSignalDevice"
        qword [0x1801012a8] = rax // [0x1801012a8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_radio_devices_DeviceData // 0x1800dda50 // "zombie/radio/devices/DeviceData"
        qword [0x1801012b0] = rax // [0x1801012b0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.java_util_ArrayList // 0x1800d7568 // "java/util/ArrayList"
        qword [0x1801012b8] = rax // [0x1801012b8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_Lua_LuaManager // 0x1800dda70 // "zombie/Lua/LuaManager"
        qword [0x1801012c0] = rax // [0x1801012c0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.se_krka_kahlua_vm_KahluaTable // 0x1800dda88 // "se/krka/kahlua/vm/KahluaTable"
        qword [0x1801012c8] = rax // [0x1801012c8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.se_krka_kahlua_integration_LuaCaller // 0x1800ddaa8 // "se/krka/kahlua/integration/LuaCaller"
        qword [0x1801012d0] = rax // [0x1801012d0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.se_krka_kahlua_integration_LuaReturn // 0x1800ddad0 // "se/krka/kahlua/integration/LuaReturn"
        qword [0x1801012d8] = rax // [0x1801012d8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.java_lang_Object // 0x1800ddaf8 // "java/lang/Object"
        qword [0x1801012e0] = rax // [0x1801012e0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.java_lang_Number // 0x1800ddb10 // "java/lang/Number"
        qword [0x1801012e8] = rax // [0x1801012e8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = qword [0x180101278] // [0x180101278:8]=0
        qword [0x1801012f0] = rax // [0x1801012f0:8]=0
        v = rdx & rdx
        if (!v) goto loc_0x18000a921 // likely
        goto loc_0x18000a0b7;
    loc_0x18000a921:
        // XREFS: CODE 0x18000a0b1  CODE 0x18000a0bf  CODE 0x18000a0cd
        // XREFS: CODE 0x18000a0db  CODE 0x18000a0e9  CODE 0x18000a0f7
        // XREFS: CODE 0x18000a105  CODE 0x18000a113  CODE 0x18000a121
        // XREFS: CODE 0x18000a12f  CODE 0x18000a13d  CODE 0x18000a14b
        // XREFS: CODE 0x18000a159  CODE 0x18000a167  CODE 0x18000a175
        // XREFS: CODE 0x18000a17e
        al = 0
        rsp += 0x20
        rbx = pop ()
        return
        goto loc_0x18000a0c5;
    loc_0x180009f42: // orphan
         al = 1
         rsp += 0x20
         rbx = pop ()
         return

    loc_0x18000a0b7: // orphan
         v = qword [0x180101280] - 0 // [0x180101280:8]=0
         if (!v) 
         goto loc_0x18000a0c5;
    loc_0x18000a0c5: // orphan
         v = qword [0x180101288] - 0 // [0x180101288:8]=0
         if (!v) 
         goto loc_0x18000a0d3;
    loc_0x18000a0d3: // orphan
         v = qword [0x180101290] - 0 // [0x180101290:8]=0
         if (!v) 
         goto loc_0x18000a0e1;
    loc_0x18000a0e1: // orphan
         v = qword [0x180101298] - 0 // [0x180101298:8]=0
         if (!v) 
         goto loc_0x18000a0ef;
    loc_0x18000a0ef: // orphan
         v = qword [0x1801012a0] - 0 // [0x1801012a0:8]=0
         if (!v) 
         goto loc_0x18000a0fd;
    loc_0x18000a0fd: // orphan
         v = qword [0x1801012a8] - 0 // [0x1801012a8:8]=0
         if (!v) 
         goto loc_0x18000a10b;
    loc_0x18000a10b: // orphan
         v = qword [0x1801012b0] - 0 // [0x1801012b0:8]=0
         if (!v) 
         goto loc_0x18000a119;
    loc_0x18000a119: // orphan
         v = qword [0x1801012b8] - 0 // [0x1801012b8:8]=0
         if (!v) 
         goto loc_0x18000a127;
    loc_0x18000a127: // orphan
         v = qword [0x1801012c0] - 0 // [0x1801012c0:8]=0
         if (!v) 
         goto loc_0x18000a135;
    loc_0x18000a135: // orphan
         v = qword [0x1801012c8] - 0 // [0x1801012c8:8]=0
         if (!v) 
         goto loc_0x18000a143;
    loc_0x18000a143: // orphan
         v = qword [0x1801012d0] - 0 // [0x1801012d0:8]=0
         if (!v) 
         goto loc_0x18000a151;
    loc_0x18000a151: // orphan
         v = qword [0x1801012d8] - 0 // [0x1801012d8:8]=0
         if (!v) 
         goto loc_0x18000a15f;
    loc_0x18000a15f: // orphan
         v = qword [0x1801012e0] - 0 // [0x1801012e0:8]=0
         if (!v) 
         goto loc_0x18000a16d;
    loc_0x18000a16d: // orphan
         v = qword [0x1801012e8] - 0 // [0x1801012e8:8]=0
         if (!v) 
         goto loc_0x18000a17b;
    loc_0x18000a17b: // orphan
         v = rax & rax
         if (!v) 
         goto loc_0x18000a184;
    loc_0x18000a184: // orphan
         rax = qword [rbx]
         r9 = rip + 0xcd6fe       // "Z" // 0x1800d788c
         r8 = rip + str.client    // 0x1800d7890 // "client"
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101280] // [0x180101280:8]=0
         r9 = rip + 0xcd6e0       // "Z" // 0x1800d788c
         qword [0x1801012f8] = rax // [0x1801012f8:8]=0
         r8 = rip + str.server    // 0x1800d7898 // "server"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101288] // [0x180101288:8]=0
         r9 = rip + str.__Lzombie_characters_IsoPlayer_ // 0x1800d78c8 // "()Lzombie/characters/IsoPlayer;"
         qword [0x180101300] = rax // [0x180101300:8]=0
         r8 = rip + str.getInstance // 0x1800d78e8 // "getInstance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101288] // [0x180101288:8]=0
         r9 = rip + str.__Lzombie_iso_IsoGridSquare_ // 0x1800ddb28 // "()Lzombie/iso/IsoGridSquare;"
         qword [0x180101308] = rax // [0x180101308:8]=0
         r8 = rip + str.getCurrentSquare // 0x1800ddb48 // "getCurrentSquare"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101288] // [0x180101288:8]=0
         r9 = rip + str.__Lzombie_characters_IsoGameCharacter_XP_ // 0x1800ddb60 // "()Lzombie/characters/IsoGameCharacter$XP;"
         qword [0x180101310] = rax // [0x180101310:8]=0
         r8 = rip + str.getXp     // 0x1800ddb8c // "getXp"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101288] // [0x180101288:8]=0
         r9 = rip + str._Lzombie_characters_skills_PerkFactory_Perk__I // 0x1800ddb98 // "(Lzombie/characters/skills/PerkFactory$Perk;)I"
         qword [0x180101318] = rax // [0x180101318:8]=0
         r8 = rip + str.getPerkLevel // 0x1800ddbc8 // "getPerkLevel"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "\u011f" // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101288] // [0x180101288:8]=0
         r9 = rip + 0xcd77c       // "()F" // 0x1800d79f0
         qword [0x180101320] = rax // [0x180101320:8]=0
         r8 = rip + str.getX      // 0x1800d79f4 // "getX"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "\u069f" // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101288] // [0x180101288:8]=0
         r9 = rip + 0xcd754       // "()F" // 0x1800d79f0
         qword [0x180101328] = rax // [0x180101328:8]=0
         r8 = rip + str.getY      // 0x1800d79fc // "getY"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101288] // [0x180101288:8]=0
         r9 = rip + 0xcd72c       // "()F" // 0x1800d79f0
         qword [0x180101330] = rax // [0x180101330:8]=0
         r8 = rip + str.getZ      // 0x1800d7a04 // "getZ"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101290] // [0x180101290:8]=0
         r9 = rip + str._Lzombie_characters_skills_PerkFactory_Perk__F // 0x1800ddbd8 // "(Lzombie/characters/skills/PerkFactory$Perk;)F"
         qword [0x180101338] = rax // [0x180101338:8]=0
         r8 = rip + str.getXP     // 0x1800ddc08 // "getXP"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101290] // [0x180101290:8]=0
         r9 = rip + str._Lzombie_characters_skills_PerkFactory_Perk__F // 0x1800ddbd8 // "(Lzombie/characters/skills/PerkFactory$Perk;)F"
         qword [0x180101340] = rax // [0x180101340:8]=0
         r8 = rip + str.getMultiplier // 0x1800ddc10 // "getMultiplier"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101290] // [0x180101290:8]=0
         r9 = rip + str._Lzombie_characters_skills_PerkFactory_Perk_F_V // 0x1800ddc20 // "(Lzombie/characters/skills/PerkFactory$Perk;F)V"
         qword [0x180101348] = rax // [0x180101348:8]=0
         r8 = rip + str.AddXP     // 0x1800ddc50 // "AddXP"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012a0] // [0x1801012a0:8]=0
         r9 = rip + str._I_F      // 0x1800d7de0 // "(I)F"
         qword [0x180101350] = rax // [0x180101350:8]=0
         r8 = rip + str.getTotalXpForLevel // 0x1800ddc58 // "getTotalXpForLevel"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012a8] // [0x1801012a8:8]=0
         r9 = rip + str.__Lzombie_radio_ZomboidRadio_ // 0x1800ddc70 // "()Lzombie/radio/ZomboidRadio;"
         qword [0x180101358] = rax // [0x180101358:8]=0
         r8 = rip + str.getInstance // 0x1800d78e8 // "getInstance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012a8] // [0x1801012a8:8]=0
         r9 = rip + str.__Ljava_util_ArrayList_ // 0x1800d7918 // "()Ljava/util/ArrayList;"
         qword [0x180101360] = rax // [0x180101360:8]=0
         r8 = rip + str.getDevices // 0x1800ddc90 // "getDevices"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012c0] // [0x1801012c0:8]=0
         r9 = rip + 0xcd598       // "()I" // 0x1800d7974
         qword [0x180101368] = rax // [0x180101368:8]=0
         r8 = rip + str.size      // 0x1800d7978 // "size"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012c0] // [0x1801012c0:8]=0
         r9 = rip + str._I_Ljava_lang_Object_ // 0x1800d7980 // "(I)Ljava/lang/Object;"
         qword [0x180101370] = rax // [0x180101370:8]=0
         r8 = rip + 0xcd586       // "get" // 0x1800d7998
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012b0] // [0x1801012b0:8]=0
         r9 = rip + str.__Lzombie_radio_devices_DeviceData_ // 0x1800ddca0 // "()Lzombie/radio/devices/DeviceData;"
         qword [0x180101378] = rax // [0x180101378:8]=0
         r8 = rip + str.getDeviceData // 0x1800ddcc8 // "getDeviceData"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012b0] // [0x1801012b0:8]=0
         r9 = rip + 0xcd59c       // "()F" // 0x1800d79f0
         qword [0x180101380] = rax // [0x180101380:8]=0
         r8 = rip + str.getX      // 0x1800d79f4 // "getX"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012b0] // [0x1801012b0:8]=0
         r9 = rip + 0xcd574       // "()F" // 0x1800d79f0
         qword [0x180101388] = rax // [0x180101388:8]=0
         r8 = rip + str.getY      // 0x1800d79fc // "getY"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012b0] // [0x1801012b0:8]=0
         r9 = rip + 0xcd54c       // "()F" // 0x1800d79f0
         qword [0x180101390] = rax // [0x180101390:8]=0
         r8 = rip + str.getZ      // 0x1800d7a04 // "getZ"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012b8] // [0x1801012b8:8]=0
         r9 = rip + 0xcd4f8       // "()Z" // 0x1800d79c4
         qword [0x180101398] = rax // [0x180101398:8]=0
         r8 = rip + str.getIsTurnedOn // 0x1800ddcd8 // "getIsTurnedOn"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012b8] // [0x1801012b8:8]=0
         r9 = rip + 0xcd480       // "()I" // 0x1800d7974
         qword [0x1801013a0] = rax // [0x1801013a0:8]=0
         r8 = rip + str.getChannel // 0x1800ddce8 // "getChannel"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x1801013a8] = rax // [0x1801013a8:8]=0
         r9 = rip + 0xcd4a8       // "()Z" // 0x1800d79c4
         rax = qword [rbx]
         rdx = qword [0x1801012b8] // [0x1801012b8:8]=0
         r8 = rip + str.getIsTelevision // 0x1800ddcf8 // "getIsTelevision"
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012b8] // [0x1801012b8:8]=0
         r9 = rip + 0xcd4ac       // "()F" // 0x1800d79f0
         qword [0x1801013b0] = rax // [0x1801013b0:8]=0
         r8 = rip + str.getDeviceVolume // 0x1800ddd08 // "getDeviceVolume"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012b8] // [0x1801012b8:8]=0
         r9 = rip + 0xcd458       // "()Z" // 0x1800d79c4
         qword [0x1801013b8] = rax // [0x1801013b8:8]=0
         r8 = rip + str.isPlayingMedia // 0x1800ddd18 // "isPlayingMedia"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012b8] // [0x1801012b8:8]=0
         r9 = rip + 0xcd430       // "()Z" // 0x1800d79c4
         qword [0x1801013c0] = rax // [0x1801013c0:8]=0
         r8 = rip + str.isNoTransmit // 0x1800ddd28 // "isNoTransmit"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101278] // [0x180101278:8]=0
         r9 = rip + str._IIILjava_lang_String_Ljava_lang_String_Ljava_lang_String_FFFIZ_V // 0x1800ddd40 // "(IIILjava/lang/String;Ljava/lang/String;Ljava/lang/String;FFFIZ)V"
         qword [0x1801013c8] = rax // [0x1801013c8:8]=0
         r8 = rip + str.sendIsoWaveSignal // 0x1800ddd88 // "sendIsoWaveSignal"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012c8] // [0x1801012c8:8]=0
         r9 = rip + str._Ljava_lang_String__Ljava_lang_Object_ // 0x1800ddda0 // "(Ljava/lang/String;)Ljava/lang/Object;"
         qword [0x1801013d0] = rax // [0x1801013d0:8]=0
         r8 = rip + str.getTableObject // 0x1800dddc8 // "getTableObject"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012c8] // [0x1801012c8:8]=0
         r9 = rip + str._Ljava_lang_String__Ljava_lang_Object_ // 0x1800ddda0 // "(Ljava/lang/String;)Ljava/lang/Object;"
         qword [0x1801013d8] = rax // [0x1801013d8:8]=0
         r8 = rip + str.getFunctionObject // 0x1800dddd8 // "getFunctionObject"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012d0] // [0x1801012d0:8]=0
         r9 = rip + str._Ljava_lang_Object__Ljava_lang_Object_ // 0x1800dddf0 // "(Ljava/lang/Object;)Ljava/lang/Object;"
         qword [0x1801013e0] = rax // [0x1801013e0:8]=0
         r8 = rip + str.rawget    // 0x1800dde18 // "rawget"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012c8] // [0x1801012c8:8]=0
         r9 = rip + str.Lse_krka_kahlua_integration_LuaCaller_ // 0x1800dde20 // "Lse/krka/kahlua/integration/LuaCaller;"
         qword [0x1801013e8] = rax // [0x1801013e8:8]=0
         r8 = rip + str.caller    // 0x1800dde48 // "caller"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012c8] // [0x1801012c8:8]=0
         r9 = rip + str.Lse_krka_kahlua_vm_KahluaThread_ // 0x1800dde50 // "Lse/krka/kahlua/vm/KahluaThread;"
         qword [0x1801013f0] = rax // [0x1801013f0:8]=0
         r8 = rip + str.thread    // 0x1800dde74 // "thread"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012e0] // [0x1801012e0:8]=0
         r9 = rip + 0xcd318       // "()Z" // 0x1800d79c4
         qword [0x1801013f8] = rax // [0x1801013f8:8]=0
         r8 = rip + str.isSuccess // 0x1800dde80 // "isSuccess"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012e0] // [0x1801012e0:8]=0
         r9 = rip + str.__Ljava_lang_Object_ // 0x1800d79d0 // "()Ljava/lang/Object;"
         qword [0x180101400] = rax // [0x180101400:8]=0
         r8 = rip + str.getFirst  // 0x1800dde90 // "getFirst"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801012f0] // [0x1801012f0:8]=0
         r9 = rip + 0xcd278       // "()I" // 0x1800d7974
         qword [0x180101408] = rax // [0x180101408:8]=0
         r8 = rip + str.intValue  // 0x1800ddea0 // "intValue"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x180101410] = rax // [0x180101410:8]=0
         rcx = rbx
         rax = qword [rbx]
         qword [rax + 0x720] ()   // 1824 // 0x720(0x0, 0x0, 0x0, 0x0)
         v = al & al
         if (!v) 
         goto loc_0x18000a72d;
    loc_0x18000a72d: // orphan
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x88] ()    // 136 // 0x88(0x0, 0x0, 0x0, 0x0)

    loc_0x18000a739: // orphan
         // XREFS(36)
         al = 0
         byte [0x180101270] = al  // [0x180101270:1]=0
         rsp += 0x20
         rbx = pop ()
         return

    loc_0x18000a747: // orphan
         // CODE XREF from fcn.180009f30 @ 0x18000a72b(x)
         v = qword [0x1801012f8] - 0 // [0x1801012f8:8]=-1
         if (!v) 
         goto loc_0x18000a751;
    loc_0x18000a751: // orphan
         v = qword [0x180101300] - 0 // [0x180101300:8]=-1
         if (!v) 
         goto loc_0x18000a75b;
    loc_0x18000a75b: // orphan
         v = qword [0x180101308] - 0 // [0x180101308:8]=-1
         if (!v) 
         goto loc_0x18000a765;
    loc_0x18000a765: // orphan
         v = qword [0x180101310] - 0 // [0x180101310:8]=-1
         if (!v) 
         goto loc_0x18000a76f;
    loc_0x18000a76f: // orphan
         v = qword [0x180101318] - 0 // [0x180101318:8]=-1
         if (!v) 
         goto loc_0x18000a779;
    loc_0x18000a779: // orphan
         v = qword [0x180101320] - 0 // [0x180101320:8]=-1
         if (!v) 
         goto loc_0x18000a783;
    loc_0x18000a783: // orphan
         v = qword [0x180101328] - 0 // [0x180101328:8]=-1
         if (!v) 
         goto loc_0x18000a78d;
    loc_0x18000a78d: // orphan
         v = qword [0x180101330] - 0 // [0x180101330:8]=-1
         if (!v) 
         goto loc_0x18000a797;
    loc_0x18000a797: // orphan
         v = qword [0x180101338] - 0 // [0x180101338:8]=-1
         if (!v) 
         goto loc_0x18000a7a1;
    loc_0x18000a7a1: // orphan
         v = qword [0x180101340] - 0 // [0x180101340:8]=-1
         if (!v) 
         goto loc_0x18000a7ab;
    loc_0x18000a7ab: // orphan
         v = qword [0x180101348] - 0 // [0x180101348:8]=-1
         if (!v) 
         goto loc_0x18000a7b5;
    loc_0x18000a7b5: // orphan
         v = qword [0x180101350] - 0 // [0x180101350:8]=-1
         if (!v) 
         goto loc_0x18000a7c3;
    loc_0x18000a7c3: // orphan
         v = qword [0x180101358] - 0 // [0x180101358:8]=-1
         if (!v) 
         goto loc_0x18000a7d1;
    loc_0x18000a7d1: // orphan
         v = qword [0x180101360] - 0 // [0x180101360:8]=-1
         if (!v) 
         goto loc_0x18000a7df;
    loc_0x18000a7df: // orphan
         v = qword [0x180101368] - 0 // [0x180101368:8]=-1
         if (!v) 
         goto loc_0x18000a7ed;
    loc_0x18000a7ed: // orphan
         v = qword [0x180101370] - 0 // [0x180101370:8]=-1
         if (!v) 
         goto loc_0x18000a7fb;
    loc_0x18000a7fb: // orphan
         v = qword [0x180101378] - 0 // [0x180101378:8]=-1
         if (!v) 
         goto loc_0x18000a809;
    loc_0x18000a809: // orphan
         v = qword [0x180101380] - 0 // [0x180101380:8]=-1
         if (!v) 
         goto loc_0x18000a817;
    loc_0x18000a817: // orphan
         v = qword [0x180101388] - 0 // [0x180101388:8]=-1
         if (!v) 
         goto loc_0x18000a825;
    loc_0x18000a825: // orphan
         v = qword [0x180101390] - 0 // [0x180101390:8]=-1
         if (!v) 
         goto loc_0x18000a833;
    loc_0x18000a833: // orphan
         v = qword [0x180101398] - 0 // [0x180101398:8]=-1
         if (!v) 
         goto loc_0x18000a841;
    loc_0x18000a841: // orphan
         v = qword [0x1801013a0] - 0 // [0x1801013a0:8]=-1
         if (!v) 
         goto loc_0x18000a84f;
    loc_0x18000a84f: // orphan
         v = qword [0x1801013a8] - 0 // [0x1801013a8:8]=-1
         if (!v) 
         goto loc_0x18000a85d;
    loc_0x18000a85d: // orphan
         v = qword [0x1801013b0] - 0 // [0x1801013b0:8]=-1
         if (!v) 
         goto loc_0x18000a86b;
    loc_0x18000a86b: // orphan
         v = qword [0x1801013b8] - 0 // [0x1801013b8:8]=-1
         if (!v) 
         goto loc_0x18000a879;
    loc_0x18000a879: // orphan
         v = qword [0x1801013c0] - 0 // [0x1801013c0:8]=-1
         if (!v) 
         goto loc_0x18000a887;
    loc_0x18000a887: // orphan
         v = qword [0x1801013c8] - 0 // [0x1801013c8:8]=-1
         if (!v) 
         goto loc_0x18000a895;
    loc_0x18000a895: // orphan
         v = qword [0x1801013d0] - 0 // [0x1801013d0:8]=-1
         if (!v) 
         goto loc_0x18000a8a3;
    loc_0x18000a8a3: // orphan
         v = qword [0x1801013d8] - 0 // [0x1801013d8:8]=-1
         if (!v) 
         goto loc_0x18000a8b1;
    loc_0x18000a8b1: // orphan
         v = qword [0x1801013e0] - 0 // [0x1801013e0:8]=-1
         if (!v) 
         goto loc_0x18000a8bf;
    loc_0x18000a8bf: // orphan
         v = qword [0x1801013e8] - 0 // [0x1801013e8:8]=-1
         if (!v) 
         goto loc_0x18000a8cd;
    loc_0x18000a8cd: // orphan
         v = qword [0x1801013f0] - 0 // [0x1801013f0:8]=-1
         if (!v) 
         goto loc_0x18000a8db;
    loc_0x18000a8db: // orphan
         v = qword [0x1801013f8] - 0 // [0x1801013f8:8]=-1
         if (!v) 
         goto loc_0x18000a8e9;
    loc_0x18000a8e9: // orphan
         v = qword [0x180101400] - 0 // [0x180101400:8]=-1
         if (!v) 
         goto loc_0x18000a8f7;
    loc_0x18000a8f7: // orphan
         v = qword [0x180101408] - 0 // [0x180101408:8]=-1
         if (!v) 
         goto loc_0x18000a905;
    loc_0x18000a905: // orphan
         v = qword [0x180101410] - 0 // [0x180101410:8]=-1
         if (!v) 
         return rax;
    loc_0x18000a913: // orphan
         al = 1
         byte [0x180101270] = al  // [0x180101270:1]=0
         rsp += 0x20
         rbx = pop ()
         return

}

