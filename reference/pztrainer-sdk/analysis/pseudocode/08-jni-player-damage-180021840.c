// callconv: rax ms (rcx, rdx, r8, r9, stack);
void fcn.180021840 (int64_t arg1) {
        // CALL XREF from fcn.180021c30 @ 0x180021c58(x)
        push (rbx)
        rsp -= 0x20
        v = byte [0x180101d60] - 0 // [0x180101d60:1]=0
        rbx = rcx    // arg1
        if (!v) goto loc_0x18002185a // likely
        return rax;
    loc_0x18002185a:
        // CODE XREF from fcn.180021840 @ 0x180021850(x)
        rdx = rip + str.zombie_network_GameClient // 0x1800d7470 // "zombie/network/GameClient"
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_network_GameServer // 0x1800d7490 // "zombie/network/GameServer"
        qword [0x180101d68] = rax // [0x180101d68:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_characters_IsoPlayer // 0x1800d74b0 // "zombie/characters/IsoPlayer"
        qword [0x180101d70] = rax // [0x180101d70:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_characters_BodyDamage_BodyDamage // 0x1800e17e8 // "zombie/characters/BodyDamage/BodyDamage"
        qword [0x180101d78] = rax // [0x180101d78:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_characters_BodyDamage_BodyPart // 0x1800e1810 // "zombie/characters/BodyDamage/BodyPart"
        qword [0x180101d80] = rax // [0x180101d80:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.java_util_ArrayList // 0x1800d7568 // "java/util/ArrayList"
        qword [0x180101d88] = rax // [0x180101d88:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = qword [0x180101d68] // [0x180101d68:8]=0
        qword [0x180101d90] = rax // [0x180101d90:8]=0
        v = rdx & rdx
        if (!v) goto loc_0x180021c25 // likely
        goto loc_0x1800218eb;
    loc_0x180021c25:
        // XREFS: CODE 0x1800218e5  CODE 0x1800218f3  CODE 0x180021901
        // XREFS: CODE 0x18002190f  CODE 0x18002191d  CODE 0x180021926
        al = 0
        rsp += 0x20
        rbx = pop ()
        return
        goto loc_0x1800218f9;
    loc_0x180021852: // orphan
         al = 1
         rsp += 0x20
         rbx = pop ()
         return

    loc_0x1800218eb: // orphan
         v = qword [0x180101d70] - 0 // [0x180101d70:8]=0
         if (!v) 
         goto loc_0x1800218f9;
    loc_0x1800218f9: // orphan
         v = qword [0x180101d78] - 0 // [0x180101d78:8]=0
         if (!v) 
         goto loc_0x180021907;
    loc_0x180021907: // orphan
         v = qword [0x180101d80] - 0 // [0x180101d80:8]=0
         if (!v) 
         goto loc_0x180021915;
    loc_0x180021915: // orphan
         v = qword [0x180101d88] - 0 // [0x180101d88:8]=0
         if (!v) 
         goto loc_0x180021923;
    loc_0x180021923: // orphan
         v = rax & rax
         if (!v) 
         goto loc_0x18002192c;
    loc_0x18002192c: // orphan
         rax = qword [rbx]
         r9 = rip + 0xb5f56       // "Z" // 0x1800d788c
         r8 = rip + str.client    // 0x1800d7890 // "client"
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101d70] // [0x180101d70:8]=0
         r9 = rip + 0xb5f38       // "Z" // 0x1800d788c
         qword [0x180101d98] = rax // [0x180101d98:8]=0
         r8 = rip + str.server    // 0x1800d7898 // "server"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101d78] // [0x180101d78:8]=0
         r9 = rip + str.__Lzombie_characters_IsoPlayer_ // 0x1800d78c8 // "()Lzombie/characters/IsoPlayer;"
         qword [0x180101da0] = rax // [0x180101da0:8]=0
         r8 = rip + str.getInstance // 0x1800d78e8 // "getInstance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101d78] // [0x180101d78:8]=0
         r9 = rip + str.__Lzombie_characters_BodyDamage_BodyDamage_ // 0x1800e1838 // "()Lzombie/characters/BodyDamage/BodyDamage;"
         qword [0x180101da8] = rax // [0x180101da8:8]=0
         r8 = rip + str.getBodyDamage // 0x1800e1868 // "getBodyDamage"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101d80] // [0x180101d80:8]=0
         r9 = rip + str.__Ljava_util_ArrayList_ // 0x1800d7918 // "()Ljava/util/ArrayList;"
         qword [0x180101db0] = rax // [0x180101db0:8]=0
         r8 = rip + str.getBodyParts // 0x1800e1878 // "getBodyParts"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101d90] // [0x180101d90:8]=0
         r9 = rip + 0xb5f80       // "()I" // 0x1800d7974
         qword [0x180101db8] = rax // [0x180101db8:8]=0
         r8 = rip + str.size      // 0x1800d7978 // "size"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101d90] // [0x180101d90:8]=0
         r9 = rip + str._I_Ljava_lang_Object_ // 0x1800d7980 // "(I)Ljava/lang/Object;"
         qword [0x180101dc0] = rax // [0x180101dc0:8]=0
         r8 = rip + 0xb5f6e       // "get" // 0x1800d7998
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101d88] // [0x180101d88:8]=0
         r9 = rip + 0xb5fac       // "()F" // 0x1800d79f0
         qword [0x180101dc8] = rax // [0x180101dc8:8]=0
         r8 = rip + str.getHealth // 0x1800d7a48 // "getHealth"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101d80] // [0x180101d80:8]=0
         r9 = rip + 0xb660c       // "()V" // 0x1800d8078
         qword [0x180101dd0] = rax // [0x180101dd0:8]=0
         r8 = rip + str.RestoreToFullHealth // 0x1800e1888 // "RestoreToFullHealth"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101d68] // [0x180101d68:8]=0
         r9 = rip + str._Lzombie_characters_IsoPlayer__V // 0x1800e18a0 // "(Lzombie/characters/IsoPlayer;)V"
         qword [0x180101dd8] = rax // [0x180101dd8:8]=0
         r8 = rip + str.sendPlayerDamage // 0x1800e18c8 // "sendPlayerDamage"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101d78] // [0x180101d78:8]=0
         r9 = rip + 0xb5f08       // "()Z" // 0x1800d79c4
         qword [0x180101de0] = rax // [0x180101de0:8]=0
         r8 = rip + str.isGodMod  // 0x1800e18e0 // "isGodMod"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101d78] // [0x180101d78:8]=0
         r9 = rip + 0xb5ee0       // "()Z" // 0x1800d79c4
         qword [0x180101de8] = rax // [0x180101de8:8]=0
         r8 = rip + str.avoidDamage // 0x1800e18f0 // "avoidDamage"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101d78] // [0x180101d78:8]=0
         r9 = rip + str._ZZ_V     // 0x1800e18fc // "(ZZ)V"
         qword [0x180101df0] = rax // [0x180101df0:8]=0
         r8 = rip + str.setGodMod // 0x1800e1908 // "setGodMod"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101d78] // [0x180101d78:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         qword [0x180101df8] = rax // [0x180101df8:8]=0
         r8 = rip + str.setAvoidDamage // 0x1800e1918 // "setAvoidDamage"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x180101e00] = rax // [0x180101e00:8]=0
         rcx = rbx
         rax = qword [rbx]
         qword [rax + 0x720] ()   // 1824 // 0x720(0x0, 0x0, 0x0, 0x0)
         v = al & al
         if (!v) 
         goto loc_0x180021b65;
    loc_0x180021b65: // orphan
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x88] ()    // 136 // 0x88(0x0, 0x0, 0x0, 0x0)

    loc_0x180021b71: // orphan
         // XREFS: CODE 0x180021b87  CODE 0x180021b91  CODE 0x180021b9b   // XREFS: CODE 0x180021ba5  CODE 0x180021baf  CODE 0x180021bb9   // XREFS: CODE 0x180021bc3  CODE 0x180021bcd  CODE 0x180021bd7   // XREFS: CODE 0x180021be1  CODE 0x180021beb  CODE 0x180021bf5   // XREFS: CODE 0x180021c03  CODE 0x180021c11  
         al = 0
         byte [0x180101d60] = al  // [0x180101d60:1]=0
         rsp += 0x20
         rbx = pop ()
         return

    loc_0x180021b7f: // orphan
         // CODE XREF from fcn.180021840 @ 0x180021b63(x)
         v = qword [0x180101d98] - 0 // [0x180101d98:8]=-1
         if (!v) 
         goto loc_0x180021b89;
    loc_0x180021b89: // orphan
         v = qword [0x180101da0] - 0 // [0x180101da0:8]=-1
         if (!v) 
         goto loc_0x180021b93;
    loc_0x180021b93: // orphan
         v = qword [0x180101da8] - 0 // [0x180101da8:8]=-1
         if (!v) 
         goto loc_0x180021b9d;
    loc_0x180021b9d: // orphan
         v = qword [0x180101db0] - 0 // [0x180101db0:8]=-1
         if (!v) 
         goto loc_0x180021ba7;
    loc_0x180021ba7: // orphan
         v = qword [0x180101db8] - 0 // [0x180101db8:8]=-1
         if (!v) 
         goto loc_0x180021bb1;
    loc_0x180021bb1: // orphan
         v = qword [0x180101dc0] - 0 // [0x180101dc0:8]=-1
         if (!v) 
         goto loc_0x180021bbb;
    loc_0x180021bbb: // orphan
         v = qword [0x180101dc8] - 0 // [0x180101dc8:8]=-1
         if (!v) 
         goto loc_0x180021bc5;
    loc_0x180021bc5: // orphan
         v = qword [0x180101dd0] - 0 // [0x180101dd0:8]=-1
         if (!v) 
         goto loc_0x180021bcf;
    loc_0x180021bcf: // orphan
         v = qword [0x180101dd8] - 0 // [0x180101dd8:8]=-1
         if (!v) 
         goto loc_0x180021bd9;
    loc_0x180021bd9: // orphan
         v = qword [0x180101de0] - 0 // [0x180101de0:8]=-1
         if (!v) 
         goto loc_0x180021be3;
    loc_0x180021be3: // orphan
         v = qword [0x180101de8] - 0 // [0x180101de8:8]=-1
         if (!v) 
         goto loc_0x180021bed;
    loc_0x180021bed: // orphan
         v = qword [0x180101df0] - 0 // [0x180101df0:8]=-1
         if (!v) 
         goto loc_0x180021bfb;
    loc_0x180021bfb: // orphan
         v = qword [0x180101df8] - 0 // [0x180101df8:8]=-1
         if (!v) 
         goto loc_0x180021c09;
    loc_0x180021c09: // orphan
         v = qword [0x180101e00] - 0 // [0x180101e00:8]=-1
         if (!v) 
         return rax;
    loc_0x180021c17: // orphan
         al = 1
         byte [0x180101d60] = al  // [0x180101d60:1]=0
         rsp += 0x20
         rbx = pop ()
         return

}

