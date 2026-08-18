// callconv: rax ms (rcx, rdx, r8, r9, stack);
void fcn.18001d190 (int64_t arg1) {
        // CALL XREF from fcn.18001e8d0 @ 0x18001e8ea(x)
        // CALL XREF from fcn.18001ec30 @ 0x18001ecbb(x)
        // CALL XREF from fcn.18001ef80 @ 0x18001effe(x)
        // CALL XREF from fcn.18001f250 @ 0x18001f2aa(x)
        push (rbx)
        rsp -= 0x20
        v = byte [0x180101ad0] - 0 // [0x180101ad0:1]=0
        rbx = rcx    // arg1
        if (!v) goto loc_0x18001d1aa // likely
        return rax;
    loc_0x18001d1aa:
        // CODE XREF from fcn.18001d190 @ 0x18001d1a0(x)
        rdx = rip + str.zombie_network_GameClient // 0x1800d7470 // "zombie/network/GameClient"
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_network_GameServer // 0x1800d7490 // "zombie/network/GameServer"
        qword [0x180101ad8] = rax // [0x180101ad8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_characters_IsoPlayer // 0x1800d74b0 // "zombie/characters/IsoPlayer"
        qword [0x180101ae0] = rax // [0x180101ae0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_characters_Stats // 0x1800e0bc8 // "zombie/characters/Stats"
        qword [0x180101ae8] = rax // [0x180101ae8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_characters_CharacterStat // 0x1800e0be0 // "zombie/characters/CharacterStat"
        qword [0x180101af0] = rax // [0x180101af0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_characters_Role // 0x1800e0c00 // "zombie/characters/Role"
        qword [0x180101af8] = rax // [0x180101af8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_characters_Capability // 0x1800e0c18 // "zombie/characters/Capability"
        qword [0x180101b00] = rax // [0x180101b00:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_network_PacketTypes_PacketType // 0x1800de7a0 // "zombie/network/PacketTypes$PacketType"
        qword [0x180101b08] = rax // [0x180101b08:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_network_packets_INetworkPacket // 0x1800e06a0 // "zombie/network/packets/INetworkPacket"
        qword [0x180101b10] = rax // [0x180101b10:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_network_packets_SyncPlayerStatsPacket // 0x1800e0c38 // "zombie/network/packets/SyncPlayerStatsPacket"
        qword [0x180101b18] = rax // [0x180101b18:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.java_lang_Integer // 0x1800e0c68 // "java/lang/Integer"
        qword [0x180101b20] = rax // [0x180101b20:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.java_lang_Object // 0x1800ddaf8 // "java/lang/Object"
        qword [0x180101b28] = rax // [0x180101b28:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = qword [0x180101ad8] // [0x180101ad8:8]=0
        qword [0x180101b30] = rax // [0x180101b30:8]=0
        v = rdx & rdx
        if (!v) goto loc_0x18001db7a // likely
        goto loc_0x18001d2bf;
    loc_0x18001db7a:
        // XREFS: CODE 0x18001d2b9  CODE 0x18001d2c7  CODE 0x18001d2d5
        // XREFS: CODE 0x18001d2e3  CODE 0x18001d2f1  CODE 0x18001d2ff
        // XREFS: CODE 0x18001d30d  CODE 0x18001d31b  CODE 0x18001d329
        // XREFS: CODE 0x18001d337  CODE 0x18001d345  CODE 0x18001d34e
        al = 0
        rsp += 0x20
        rbx = pop ()
        return
        goto loc_0x18001d2cd;
    loc_0x18001d1a2: // orphan
         al = 1
         rsp += 0x20
         rbx = pop ()
         return

    loc_0x18001d2bf: // orphan
         v = qword [0x180101ae0] - 0 // [0x180101ae0:8]=0
         if (!v) 
         goto loc_0x18001d2cd;
    loc_0x18001d2cd: // orphan
         v = qword [0x180101ae8] - 0 // [0x180101ae8:8]=0
         if (!v) 
         goto loc_0x18001d2db;
    loc_0x18001d2db: // orphan
         v = qword [0x180101af0] - 0 // [0x180101af0:8]=0
         if (!v) 
         goto loc_0x18001d2e9;
    loc_0x18001d2e9: // orphan
         v = qword [0x180101af8] - 0 // [0x180101af8:8]=0
         if (!v) 
         goto loc_0x18001d2f7;
    loc_0x18001d2f7: // orphan
         v = qword [0x180101b00] - 0 // [0x180101b00:8]=0
         if (!v) 
         goto loc_0x18001d305;
    loc_0x18001d305: // orphan
         v = qword [0x180101b08] - 0 // [0x180101b08:8]=0
         if (!v) 
         goto loc_0x18001d313;
    loc_0x18001d313: // orphan
         v = qword [0x180101b10] - 0 // [0x180101b10:8]=0
         if (!v) 
         goto loc_0x18001d321;
    loc_0x18001d321: // orphan
         v = qword [0x180101b18] - 0 // [0x180101b18:8]=0
         if (!v) 
         goto loc_0x18001d32f;
    loc_0x18001d32f: // orphan
         v = qword [0x180101b20] - 0 // [0x180101b20:8]=0
         if (!v) 
         goto loc_0x18001d33d;
    loc_0x18001d33d: // orphan
         v = qword [0x180101b28] - 0 // [0x180101b28:8]=0
         if (!v) 
         goto loc_0x18001d34b;
    loc_0x18001d34b: // orphan
         v = rax & rax
         if (!v) 
         goto loc_0x18001d354;
    loc_0x18001d354: // orphan
         rax = qword [rbx]
         r9 = rip + 0xba52e       // "Z" // 0x1800d788c
         r8 = rip + str.client    // 0x1800d7890 // "client"
         qword [var_38h] = rdi
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae0] // [0x180101ae0:8]=0
         r9 = rip + 0xba50b       // "Z" // 0x1800d788c
         qword [0x180101b38] = rax // [0x180101b38:8]=0
         r8 = rip + str.server    // 0x1800d7898 // "server"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101af8] // [0x180101af8:8]=0
         r9 = rip + str._Lzombie_characters_CharacterStat_ // 0x1800e0c80 // "[Lzombie/characters/CharacterStat;"
         qword [0x180101b40] = rax // [0x180101b40:8]=0
         r8 = rip + str.ORDERED_STATS // 0x1800e0ca8 // "ORDERED_STATS"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101b08] // [0x180101b08:8]=0
         r9 = rip + str.Lzombie_characters_Capability_ // 0x1800e0cb8 // "Lzombie/characters/Capability;"
         qword [0x180101b48] = rax // [0x180101b48:8]=0
         r8 = rip + str.CanModifyBodyStats // 0x1800e0cd8 // "CanModifyBodyStats"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101b10] // [0x180101b10:8]=0
         r9 = rip + str.Lzombie_network_PacketTypes_PacketType_ // 0x1800de7c8 // "Lzombie/network/PacketTypes$PacketType;"
         qword [0x180101b50] = rax // [0x180101b50:8]=0
         r8 = rip + str.SyncPlayerStats // 0x1800e0cf0 // "SyncPlayerStats"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + str.__Lzombie_characters_IsoPlayer_ // 0x1800d78c8 // "()Lzombie/characters/IsoPlayer;"
         qword [0x180101b58] = rax // [0x180101b58:8]=0
         r8 = rip + str.getInstance // 0x1800d78e8 // "getInstance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + str.__Lzombie_characters_Stats_ // 0x1800e0d00 // "()Lzombie/characters/Stats;"
         qword [0x180101b60] = rax // [0x180101b60:8]=0
         r8 = rip + str.getStats  // 0x1800e0d20 // "getStats"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + str.__Lzombie_characters_Role_ // 0x1800e0d30 // "()Lzombie/characters/Role;"
         qword [0x180101b68] = rax // [0x180101b68:8]=0
         r8 = rip + str.getRole   // 0x1800e0d50 // "getRole"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101b00] // [0x180101b00:8]=0
         r9 = rip + str._Lzombie_characters_Capability__Z // 0x1800e0d58 // "(Lzombie/characters/Capability;)Z"
         qword [0x180101b70] = rax // [0x180101b70:8]=0
         r8 = rip + str.hasCapability // 0x1800e0d80 // "hasCapability"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101af0] // [0x180101af0:8]=0
         r9 = rip + str._Lzombie_characters_CharacterStat__F // 0x1800e0d90 // "(Lzombie/characters/CharacterStat;)F"
         qword [0x180101b78] = rax // [0x180101b78:8]=0
         r8 = rip + 0xba4c9       // "get" // 0x1800d7998
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101af0] // [0x180101af0:8]=0
         r9 = rip + str._Lzombie_characters_CharacterStat_F_Z // 0x1800e0db8 // "(Lzombie/characters/CharacterStat;F)Z"
         qword [0x180101b80] = rax // [0x180101b80:8]=0
         r8 = rip + 0xc1785       // "set" // 0x1800dec7c
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101af0] // [0x180101af0:8]=0
         r9 = rip + str._Lzombie_characters_CharacterStat__Z // 0x1800e0de0 // "(Lzombie/characters/CharacterStat;)Z"
         qword [0x180101b88] = rax // [0x180101b88:8]=0
         r8 = rip + str.reset     // 0x1800e0e08 // "reset"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101af8] // [0x180101af8:8]=0
         r9 = rip + str.__Ljava_lang_String_ // 0x1800d7b40 // "()Ljava/lang/String;"
         qword [0x180101b90] = rax // [0x180101b90:8]=0
         r8 = rip + str.getId     // 0x1800d7c40 // "getId"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101af8] // [0x180101af8:8]=0
         r9 = rip + 0xba48f       // "()F" // 0x1800d79f0
         qword [0x180101b98] = rax // [0x180101b98:8]=0
         r8 = rip + str.getMinimumValue // 0x1800e0e10 // "getMinimumValue"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101af8] // [0x180101af8:8]=0
         r9 = rip + 0xba467       // "()F" // 0x1800d79f0
         qword [0x180101ba0] = rax // [0x180101ba0:8]=0
         r8 = rip + str.getMaximumValue // 0x1800e0e20 // "getMaximumValue"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101af8] // [0x180101af8:8]=0
         r9 = rip + 0xba43f       // "()F" // 0x1800d79f0
         qword [0x180101ba8] = rax // [0x180101ba8:8]=0
         r8 = rip + str.getDefaultValue // 0x1800e0e30 // "getDefaultValue"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101b20] // [0x180101b20:8]=0
         r9 = rip + str._Lzombie_characters_CharacterStat__I // 0x1800e0e40 // "(Lzombie/characters/CharacterStat;)I"
         qword [0x180101bb0] = rax // [0x180101bb0:8]=0
         r8 = rip + str.getBitMaskForStat // 0x1800e0e68 // "getBitMaskForStat"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101b28] // [0x180101b28:8]=0
         r9 = rip + str._I_Ljava_lang_Integer_ // 0x1800e0e80 // "(I)Ljava/lang/Integer;"
         qword [0x180101bb8] = rax // [0x180101bb8:8]=0
         r8 = rip + str.valueOf   // 0x1800e0360 // "valueOf"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101b18] // [0x180101b18:8]=0
         r9 = rip + str._Lzombie_network_PacketTypes_PacketType__Ljava_lang_Object__V // 0x1800e06e8 // "(Lzombie/network/PacketTypes$PacketType;[Ljava/lang/Object;)V"
         qword [0x180101bc0] = rax // [0x180101bc0:8]=0
         r8 = rip + str.send      // 0x1800e0728 // "send"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + 0xba39f       // "()F" // 0x1800d79f0
         qword [0x180101bc8] = rax // [0x180101bc8:8]=0
         r8 = rip + str.getSleepingTabletEffect // 0x1800e0e98 // "getSleepingTabletEffect"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + 0xba377       // "()F" // 0x1800d79f0
         qword [0x180101bd0] = rax // [0x180101bd0:8]=0
         r8 = rip + str.getSleepingTabletDelta // 0x1800e0ee8 // "getSleepingTabletDelta"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180101bf0] = rax // [0x180101bf0:8]=0
         r8 = rip + str.setSleepingTabletEffect // 0x1800e0f30 // "setSleepingTabletEffect"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180101c10] = rax // [0x180101c10:8]=0
         r8 = rip + str.setSleepingTabletDelta // 0x1800e0f80 // "setSleepingTabletDelta"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x180101c30] = rax // [0x180101c30:8]=0
         rax = qword [rbx]
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         r8 = rip + str.SleepingTablet // 0x1800e08e8 // "SleepingTablet"
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + 0xba2d7       // "()F" // 0x1800d79f0
         qword [0x180101c50] = rax // [0x180101c50:8]=0
         r8 = rip + str.getBetaEffect // 0x1800e0eb0 // "getBetaEffect"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + 0xba2af       // "()F" // 0x1800d79f0
         qword [0x180101bd8] = rax // [0x180101bd8:8]=0
         r8 = rip + str.getBetaDelta // 0x1800e0f00 // "getBetaDelta"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180101bf8] = rax // [0x180101bf8:8]=0
         r8 = rip + str.setBetaEffect // 0x1800e0f48 // "setBetaEffect"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180101c18] = rax // [0x180101c18:8]=0
         r8 = rip + str.setBetaDelta // 0x1800e0f98 // "setBetaDelta"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180101c38] = rax // [0x180101c38:8]=0
         r8 = rip + str.BetaBlockers // 0x1800e0928 // "BetaBlockers"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + 0xba20f       // "()F" // 0x1800d79f0
         qword [0x180101c58] = rax // [0x180101c58:8]=0
         r8 = rip + str.getDepressEffect // 0x1800e0ec0 // "getDepressEffect"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + 0xba1e7       // "()F" // 0x1800d79f0
         qword [0x180101be0] = rax // [0x180101be0:8]=0
         r8 = rip + str.getDepressDelta // 0x1800e0f10 // "getDepressDelta"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180101c00] = rax // [0x180101c00:8]=0
         r8 = rip + str.setDepressEffect // 0x1800e0f58 // "setDepressEffect"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180101c20] = rax // [0x180101c20:8]=0
         r8 = rip + str.setDepressDelta // 0x1800e0fa8 // "setDepressDelta"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180101c40] = rax // [0x180101c40:8]=0
         r8 = rip + str.BetaAntiDepress // 0x1800e0fc8 // "BetaAntiDepress"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + 0xba147       // "()F" // 0x1800d79f0
         qword [0x180101c60] = rax // [0x180101c60:8]=0
         r8 = rip + str.getPainEffect // 0x1800e0ed8 // "getPainEffect"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + 0xba11f       // "()F" // 0x1800d79f0
         qword [0x180101be8] = rax // [0x180101be8:8]=0
         r8 = rip + str.getPainDelta // 0x1800e0f20 // "getPainDelta"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180101c08] = rax // [0x180101c08:8]=0
         r8 = rip + str.setPainEffect // 0x1800e0f70 // "setPainEffect"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180101c28] = rax // [0x180101c28:8]=0
         r8 = rip + str.setPainDelta // 0x1800e0fb8 // "setPainDelta"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101ae8] // [0x180101ae8:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180101c48] = rax // [0x180101c48:8]=0
         r8 = rip + str.PainMeds  // 0x1800e0990 // "PainMeds"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         v = qword [0x180101bd0] - 0 // [0x180101bd0:8]=-1
         qword [0x180101c68] = rax // [0x180101c68:8]=0
         if (!v) 
         goto loc_0x18001d978;
    loc_0x18001d978: // orphan
         v = qword [0x180101bf0] - 0 // [0x180101bf0:8]=-1
         if (!v) 
         goto loc_0x18001d986;
    loc_0x18001d986: // orphan
         v = qword [0x180101c10] - 0 // [0x180101c10:8]=-1
         if (!v) 
         goto loc_0x18001d994;
    loc_0x18001d994: // orphan
         v = qword [0x180101c30] - 0 // [0x180101c30:8]=-1
         if (!v) 
         goto loc_0x18001d9a2;
    loc_0x18001d9a2: // orphan
         v = qword [0x180101c50] - 0 // [0x180101c50:8]=-1
         if (!v) 
         goto loc_0x18001d9b0;
    loc_0x18001d9b0: // orphan
         v = qword [0x180101bd8] - 0 // [0x180101bd8:8]=-1
         if (!v) 
         goto loc_0x18001d9be;
    loc_0x18001d9be: // orphan
         v = qword [0x180101bf8] - 0 // [0x180101bf8:8]=-1
         if (!v) 
         goto loc_0x18001d9cc;
    loc_0x18001d9cc: // orphan
         v = qword [0x180101c18] - 0 // [0x180101c18:8]=-1
         if (!v) 
         goto loc_0x18001d9d6;
    loc_0x18001d9d6: // orphan
         v = qword [0x180101c38] - 0 // [0x180101c38:8]=-1
         if (!v) 
         goto loc_0x18001d9e0;
    loc_0x18001d9e0: // orphan
         v = qword [0x180101c58] - 0 // [0x180101c58:8]=-1
         if (!v) 
         goto loc_0x18001d9ea;
    loc_0x18001d9ea: // orphan
         v = qword [0x180101be0] - 0 // [0x180101be0:8]=-1
         if (!v) 
         goto loc_0x18001d9f4;
    loc_0x18001d9f4: // orphan
         v = qword [0x180101c00] - 0 // [0x180101c00:8]=-1
         if (!v) 
         goto loc_0x18001d9fe;
    loc_0x18001d9fe: // orphan
         v = qword [0x180101c20] - 0 // [0x180101c20:8]=-1
         if (!v) 
         goto loc_0x18001da08;
    loc_0x18001da08: // orphan
         v = qword [0x180101c40] - 0 // [0x180101c40:8]=-1
         if (!v) 
         goto loc_0x18001da12;
    loc_0x18001da12: // orphan
         v = qword [0x180101c60] - 0 // [0x180101c60:8]=-1
         if (!v) 
         goto loc_0x18001da1c;
    loc_0x18001da1c: // orphan
         v = qword [0x180101be8] - 0 // [0x180101be8:8]=-1
         if (!v) 
         goto loc_0x18001da26;
    loc_0x18001da26: // orphan
         v = qword [0x180101c08] - 0 // [0x180101c08:8]=-1
         if (!v) 
         goto loc_0x18001da30;
    loc_0x18001da30: // orphan
         v = qword [0x180101c28] - 0 // [0x180101c28:8]=-1
         if (!v) 
         goto loc_0x18001da3a;
    loc_0x18001da3a: // orphan
         v = qword [0x180101c48] - 0 // [0x180101c48:8]=-1
         if (!v) 
         goto loc_0x18001da44;
    loc_0x18001da44: // orphan
         v = rax & rax
         if (!v) 
         goto loc_0x18001da49;
    loc_0x18001da49: // orphan
         dil = 1
         
         goto loc_0x18001da4e;
    loc_0x18001da4e: // orphan
         // XREFS: CODE 0x18001d972  CODE 0x18001d980  CODE 0x18001d98e   // XREFS: CODE 0x18001d99c  CODE 0x18001d9aa  CODE 0x18001d9b8   // XREFS: CODE 0x18001d9c6  CODE 0x18001d9d4  CODE 0x18001d9de   // XREFS: CODE 0x18001d9e8  CODE 0x18001d9f2  CODE 0x18001d9fc   // XREFS: CODE 0x18001da06  CODE 0x18001da10  CODE 0x18001da1a   // XREFS: CODE 0x18001da24  CODE 0x18001da2e  CODE 0x18001da38   // XREFS: CODE 0x18001da42  CODE 0x18001da47  
         dil = 0

    loc_0x18001da51: // orphan
         // CODE XREF from fcn.18001d190 @ 0x18001da4c(x)
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x720] ()   // 1824 // 0x720(0x0, 0x0, 0x0, 0x0)
         v = al & al
         if (!v) 
         goto loc_0x18001da61;
    loc_0x18001da61: // orphan
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x88] ()    // 136 // 0x88(0x0, 0x0, 0x0, 0x0)

    loc_0x18001da6d: // orphan
         // XREFS: CODE 0x18001da83  CODE 0x18001da8d  CODE 0x18001da97   // XREFS: CODE 0x18001daa1  CODE 0x18001daab  CODE 0x18001dab5   // XREFS: CODE 0x18001dabf  CODE 0x18001dac9  CODE 0x18001dad3   // XREFS: CODE 0x18001dadd  CODE 0x18001dae7  CODE 0x18001daf1   // XREFS: CODE 0x18001daff  CODE 0x18001db0d  CODE 0x18001db1b   // XREFS: CODE 0x18001db29  CODE 0x18001db37  CODE 0x18001db45   // XREFS: CODE 0x18001db53  CODE 0x18001db61  
         rdi = qword [var_38h]
         al = 0
         byte [0x180101ad0] = al  // [0x180101ad0:1]=0
         rsp += 0x20
         rbx = pop ()
         return

    loc_0x18001da80: // orphan
         // CODE XREF from fcn.18001d190 @ 0x18001da5f(x)
         v = dil & dil
         if (!v) 
         goto loc_0x18001da85;
    loc_0x18001da85: // orphan
         v = qword [0x180101b38] - 0 // [0x180101b38:8]=-1
         if (!v) 
         goto loc_0x18001da8f;
    loc_0x18001da8f: // orphan
         v = qword [0x180101b40] - 0 // [0x180101b40:8]=-1
         if (!v) 
         goto loc_0x18001da99;
    loc_0x18001da99: // orphan
         v = qword [0x180101b48] - 0 // [0x180101b48:8]=-1
         if (!v) 
         goto loc_0x18001daa3;
    loc_0x18001daa3: // orphan
         v = qword [0x180101b50] - 0 // [0x180101b50:8]=-1
         if (!v) 
         goto loc_0x18001daad;
    loc_0x18001daad: // orphan
         v = qword [0x180101b58] - 0 // [0x180101b58:8]=-1
         if (!v) 
         goto loc_0x18001dab7;
    loc_0x18001dab7: // orphan
         v = qword [0x180101b60] - 0 // [0x180101b60:8]=-1
         if (!v) 
         goto loc_0x18001dac1;
    loc_0x18001dac1: // orphan
         v = qword [0x180101b68] - 0 // [0x180101b68:8]=-1
         if (!v) 
         goto loc_0x18001dacb;
    loc_0x18001dacb: // orphan
         v = qword [0x180101b70] - 0 // [0x180101b70:8]=-1
         if (!v) 
         goto loc_0x18001dad5;
    loc_0x18001dad5: // orphan
         v = qword [0x180101b78] - 0 // [0x180101b78:8]=-1
         if (!v) 
         goto loc_0x18001dadf;
    loc_0x18001dadf: // orphan
         v = qword [0x180101b80] - 0 // [0x180101b80:8]=-1
         if (!v) 
         goto loc_0x18001dae9;
    loc_0x18001dae9: // orphan
         v = qword [0x180101b88] - 0 // [0x180101b88:8]=-1
         if (!v) 
         goto loc_0x18001daf7;
    loc_0x18001daf7: // orphan
         v = qword [0x180101b90] - 0 // [0x180101b90:8]=-1
         if (!v) 
         goto loc_0x18001db05;
    loc_0x18001db05: // orphan
         v = qword [0x180101b98] - 0 // [0x180101b98:8]=-1
         if (!v) 
         goto loc_0x18001db13;
    loc_0x18001db13: // orphan
         v = qword [0x180101ba0] - 0 // [0x180101ba0:8]=-1
         if (!v) 
         goto loc_0x18001db21;
    loc_0x18001db21: // orphan
         v = qword [0x180101ba8] - 0 // [0x180101ba8:8]=-1
         if (!v) 
         goto loc_0x18001db2f;
    loc_0x18001db2f: // orphan
         v = qword [0x180101bb0] - 0 // [0x180101bb0:8]=-1
         if (!v) 
         goto loc_0x18001db3d;
    loc_0x18001db3d: // orphan
         v = qword [0x180101bb8] - 0 // [0x180101bb8:8]=-1
         if (!v) 
         goto loc_0x18001db4b;
    loc_0x18001db4b: // orphan
         v = qword [0x180101bc0] - 0 // [0x180101bc0:8]=-1
         if (!v) 
         goto loc_0x18001db59;
    loc_0x18001db59: // orphan
         v = qword [0x180101bc8] - 0 // [0x180101bc8:8]=-1
         if (!v) 
         return rax;
    loc_0x18001db67: // orphan
         rdi = qword [var_38h]
         al = 1
         byte [0x180101ad0] = al  // [0x180101ad0:1]=0
         rsp += 0x20
         rbx = pop ()
         return

}

