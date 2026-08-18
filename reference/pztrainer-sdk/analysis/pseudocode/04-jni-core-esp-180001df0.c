// callconv: rax ms (rcx, rdx, r8, r9, stack);
void fcn.180001df0 (int64_t arg1) {
        // CALL XREF from fcn.180003ad0 @ 0x180003c71(x)
        push (rbx)
        rsp -= 0x20
        v = byte [0x180100d88] - 0 // [0x180100d88:1]=0
        rbx = rcx    // arg1
        if (!v) goto loc_0x180001e0a // likely
        return rax;
    loc_0x180001e0a:
        // CODE XREF from fcn.180001df0 @ 0x180001e00(x)
        rax = qword [rcx] // arg1
        rdx = rip + str.java_lang_ClassLoader // 0x1800d73b8 // "java/lang/ClassLoader"
        qword [var_38h] = rdi
        qword [rax + 0x30] () // 48 // 0x30(0x0, 0x0, 0x1800d73b8, 0x0)
        rdi = rax
        v = rax & rax
        if (!v) goto loc_0x1800037dc // unlikely
        goto loc_0x180001e28;
    loc_0x1800037dc:
        // CODE XREF from fcn.180001df0 @ 0x180001e22(x)
        rdi = qword [var_38h]
        rax = rip + str._ClassLoader // 0x1800d73d0 // "\u5f15\u5bfc\u7c7b ClassLoader"
        qword [0x1800ff968] = rax // [0x1800ff968:8]=0x1800d7378 str._JNI_
        al = 0
        rsp += 0x20
        rbx = pop ()
        return
        goto loc_0x180001e3f;
    loc_0x180001e02: // orphan
         al = 1
         rsp += 0x20
         rbx = pop ()
         return

    loc_0x180001e28: // orphan
         rdx = qword [rbx]
         rcx = rbx
         qword [rdx + 0x720] ()   // 1824 // 0x720(0x0, 0x0, -1, 0x0)
         rcx = rbx
         v = al & al
         if (v) 
         goto loc_0x180001e3f;
    loc_0x180001e3f: // orphan
         r10 = qword [rbx]
         r9 = rip + str.__Ljava_lang_ClassLoader_ // 0x1800d73e8 // "()Ljava/lang/ClassLoader;"
         r8 = rip + str.getSystemClassLoader // 0x1800d7408 // "getSystemClassLoader"
         qword [var_30h] = rsi
         rdx = rdi
         qword [r10 + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         r10 = qword [rbx]
         r9 = rip + str._Ljava_lang_String__Ljava_lang_Class_ // 0x1800d7420 // "(Ljava/lang/String;)Ljava/lang/Class;"
         r8 = rip + str.loadClass // 0x1800d7448 // "loadClass"
         rdx = rdi
         rcx = rbx
         rsi = rax
         qword [r10 + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x180100d98] = rax // [0x180100d98:8]=0
         v = rsi & rsi
         if (!v) 
         goto loc_0x180001e8c;
    loc_0x180001e8c: // orphan
         r8 = rsi
         rdx = rdi
         rcx = rbx
         fcn.180001930 ()         // fcn.180001930(0x0, 0x0, 0x0)
         rsi = rax
         v = rax & rax
         if (!v) 
         goto loc_0x180001ea2;
    loc_0x180001ea2: // orphan
         rdx = qword [rbx]
         rcx = rbx
         qword [rdx + 0x720] ()   // 1824 // 0x720(0x0, 0x0, -1, 0x0)
         rcx = rbx
         v = al & al
         if (v) 
         goto loc_0x180001eb5;
    loc_0x180001eb5: // orphan
         r8 = qword [rbx]
         rdx = rsi
         qword [r8 + 0xa8] ()     // 168 // 0xa8(0x0, 0x0, 0x0, 0x0)
         qword [0x180100d90] = rax // [0x180100d90:8]=0
         rdx = rsi
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0xb8] ()    // 184 // 0xb8(0x0, 0x0, 0x0, 0x0)
         
         goto loc_0x180001eda;
    loc_0x180001eda: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180001eb3(x)
         rax = qword [rbx]
         qword [rax + 0x88] ()    // 136 // 0x88(0x0, 0x0, 0x0, 0x0)

    loc_0x180001ee3: // orphan
         // CODE XREFS from fcn.180001df0 @ 0x180001e8a(x), 0x180001ea0(x), 0x180001ed8(x)
         rax = qword [rbx]
         rdx = rdi
         rcx = rbx
         qword [rax + 0xb8] ()    // 184 // 0xb8(0x0, 0x0, 0x0, 0x0)
         v = qword [0x180100d90] - 0 // [0x180100d90:8]=0
         if (!v) 
         goto loc_0x180001f00;
    loc_0x180001f00: // orphan
         v = qword [0x180100d98] - 0 // [0x180100d98:8]=0
         if (!v) 
         goto loc_0x180001f0e;
    loc_0x180001f0e: // orphan
         rdx = rip + str.zombie_network_GameClient // 0x1800d7470 // "zombie/network/GameClient"
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_network_GameServer // 0x1800d7490 // "zombie/network/GameServer"
         qword [0x180100da0] = rax // [0x180100da0:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_characters_IsoPlayer // 0x1800d74b0 // "zombie/characters/IsoPlayer"
         qword [0x180100da8] = rax // [0x180100da8:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_characters_animals_IsoAnimal // 0x1800d74d0 // "zombie/characters/animals/IsoAnimal"
         qword [0x180100db0] = rax // [0x180100db0:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_vehicles_BaseVehicle // 0x1800d74f8 // "zombie/vehicles/BaseVehicle"
         qword [0x180100db8] = rax // [0x180100db8:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_inventory_ItemContainer // 0x1800d7518 // "zombie/inventory/ItemContainer"
         qword [0x180100dc0] = rax // [0x180100dc0:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_iso_IsoWorld // 0x1800d7538 // "zombie/iso/IsoWorld"
         qword [0x180100dc8] = rax // [0x180100dc8:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_iso_IsoCell // 0x1800d7550 // "zombie/iso/IsoCell"
         qword [0x180100dd0] = rax // [0x180100dd0:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.java_util_ArrayList // 0x1800d7568 // "java/util/ArrayList"
         qword [0x180100dd8] = rax // [0x180100dd8:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.java_util_Set // 0x1800d7580 // "java/util/Set"
         qword [0x180100de0] = rax // [0x180100de0:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.java_util_Iterator // 0x1800d7590 // "java/util/Iterator"
         qword [0x180100de8] = rax // [0x180100de8:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_iso_IsoMovingObject // 0x1800d75a8 // "zombie/iso/IsoMovingObject"
         qword [0x180100df0] = rax // [0x180100df0:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_iso_IsoUtils // 0x1800d75c8 // "zombie/iso/IsoUtils"
         qword [0x180100df8] = rax // [0x180100df8:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_core_Core // 0x1800d75e0 // "zombie/core/Core"
         qword [0x180100e00] = rax // [0x180100e00:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_core_skinnedmodel_animation_AnimationPlayer // 0x1800d75f8 // "zombie/core/skinnedmodel/animation/AnimationPlayer"
         qword [0x180100e08] = rax // [0x180100e08:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.org_lwjgl_util_vector_Matrix4f // 0x1800d7630 // "org/lwjgl/util/vector/Matrix4f"
         qword [0x180100e10] = rax // [0x180100e10:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_core_skinnedmodel_model_SkinningData // 0x1800d7650 // "zombie/core/skinnedmodel/model/SkinningData"
         qword [0x180100e18] = rax // [0x180100e18:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_core_skinnedmodel_model_SkinningBone // 0x1800d7680 // "zombie/core/skinnedmodel/model/SkinningBone"
         qword [0x180100e20] = rax // [0x180100e20:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.org_lwjgl_util_vector_Vector3f // 0x1800d76b0 // "org/lwjgl/util/vector/Vector3f"
         qword [0x180100e28] = rax // [0x180100e28:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_core_skinnedmodel_model_SkeletonBone // 0x1800d76d0 // "zombie/core/skinnedmodel/model/SkeletonBone"
         qword [0x180100e30] = rax // [0x180100e30:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         qword [0x180100e38] = rax // [0x180100e38:8]=0
         rdx = rip + str.zombie_characters_IsoGameCharacter // 0x1800d7700 // "zombie/characters/IsoGameCharacter"
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_characters_Safety // 0x1800d7728 // "zombie/characters/Safety"
         qword [0x180100e40] = rax // [0x180100e40:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_CombatManager // 0x1800d7748 // "zombie/CombatManager"
         qword [0x180100e48] = rax // [0x180100e48:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_iso_LosUtil // 0x1800d7760 // "zombie/iso/LosUtil"
         qword [0x180100e50] = rax // [0x180100e50:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.zombie_iso_LosUtil_TestResults // 0x1800d7778 // "zombie/iso/LosUtil$TestResults"
         qword [0x180100e58] = rax // [0x180100e58:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = rip + str.java_lang_System // 0x1800d7798 // "java/lang/System"
         qword [0x180100e60] = rax // [0x180100e60:8]=0
         rcx = rbx
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdx = qword [0x180100da0] // [0x180100da0:8]=0
         qword [0x180100e68] = rax // [0x180100e68:8]=0
         v = rdx & rdx
         if (!v) 
         goto loc_0x18000215a;
    loc_0x18000215a: // orphan
         v = qword [0x180100da8] - 0 // [0x180100da8:8]=0
         r8 = qword [0x180100e50] // [0x180100e50:8]=0
         r9 = qword [0x180100e48] // [0x180100e48:8]=0
         rax = qword [0x180100df8] // [0x180100df8:8]=0
         rcx = qword [0x180100de0] // [0x180100de0:8]=0
         r11 = qword [0x180100dd8] // [0x180100dd8:8]=0
         rsi = qword [0x180100dd0] // [0x180100dd0:8]=0
         rdi = qword [0x180100db8] // [0x180100db8:8]=0
         r10 = qword [0x180100db0] // [0x180100db0:8]=0
         if (!v) 
         goto loc_0x1800021a0;
    loc_0x1800021a0: // orphan
         v = r10 & r10
         if (!v) 
         goto loc_0x1800021a9;
    loc_0x1800021a9: // orphan
         v = rdi & rdi
         if (!v) 
         goto loc_0x1800021b2;
    loc_0x1800021b2: // orphan
         v = qword [0x180100dc0] - 0 // [0x180100dc0:8]=0
         if (!v) 
         goto loc_0x1800021c0;
    loc_0x1800021c0: // orphan
         v = qword [0x180100dc8] - 0 // [0x180100dc8:8]=0
         if (!v) 
         goto loc_0x1800021ce;
    loc_0x1800021ce: // orphan
         v = rsi & rsi
         if (!v) 
         goto loc_0x1800021d7;
    loc_0x1800021d7: // orphan
         v = r11 & r11
         if (!v) 
         goto loc_0x1800021e0;
    loc_0x1800021e0: // orphan
         v = rcx & rcx
         if (!v) 
         goto loc_0x1800021e9;
    loc_0x1800021e9: // orphan
         v = qword [0x180100de8] - 0 // [0x180100de8:8]=0
         if (!v) 
         goto loc_0x1800021f7;
    loc_0x1800021f7: // orphan
         v = qword [0x180100df0] - 0 // [0x180100df0:8]=0
         if (!v) 
         goto loc_0x180002205;
    loc_0x180002205: // orphan
         v = rax & rax
         if (!v) 
         goto loc_0x18000220e;
    loc_0x18000220e: // orphan
         v = qword [0x180100e00] - 0 // [0x180100e00:8]=0
         if (!v) 
         goto loc_0x18000221c;
    loc_0x18000221c: // orphan
         v = qword [0x180100e08] - 0 // [0x180100e08:8]=0
         if (!v) 
         goto loc_0x18000222a;
    loc_0x18000222a: // orphan
         v = qword [0x180100e10] - 0 // [0x180100e10:8]=0
         if (!v) 
         goto loc_0x180002238;
    loc_0x180002238: // orphan
         v = qword [0x180100e18] - 0 // [0x180100e18:8]=0
         if (!v) 
         goto loc_0x180002246;
    loc_0x180002246: // orphan
         v = qword [0x180100e20] - 0 // [0x180100e20:8]=0
         if (!v) 
         goto loc_0x180002254;
    loc_0x180002254: // orphan
         v = qword [0x180100e28] - 0 // [0x180100e28:8]=0
         if (!v) 
         goto loc_0x180002262;
    loc_0x180002262: // orphan
         v = qword [0x180100e30] - 0 // [0x180100e30:8]=0
         if (!v) 
         goto loc_0x180002270;
    loc_0x180002270: // orphan
         v = qword [0x180100e38] - 0 // [0x180100e38:8]=0
         if (!v) 
         goto loc_0x18000227e;
    loc_0x18000227e: // orphan
         v = qword [0x180100e40] - 0 // [0x180100e40:8]=0
         if (!v) 
         goto loc_0x18000228c;
    loc_0x18000228c: // orphan
         v = r9 & r9
         if (!v) 
         goto loc_0x180002295;
    loc_0x180002295: // orphan
         v = r8 & r8
         if (!v) 
         goto loc_0x18000229e;
    loc_0x18000229e: // orphan
         rax = qword [rbx]
         r9 = rip + 0xd55e4       // "Z" // 0x1800d788c
         r8 = rip + str.client    // 0x1800d7890 // "client"
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100da8] // [0x180100da8:8]=0
         r9 = rip + 0xd55c6       // "Z" // 0x1800d788c
         qword [0x180100e70] = rax // [0x180100e70:8]=0
         r8 = rip + str.server    // 0x1800d7898 // "server"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100dd0] // [0x180100dd0:8]=0
         r9 = rip + str.Lzombie_iso_IsoWorld_ // 0x1800d78a0 // "Lzombie/iso/IsoWorld;"
         qword [0x180100e78] = rax // [0x180100e78:8]=0
         r8 = rip + str.instance  // 0x1800d78b8 // "instance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100db0] // [0x180100db0:8]=0
         r9 = rip + str.__Lzombie_characters_IsoPlayer_ // 0x1800d78c8 // "()Lzombie/characters/IsoPlayer;"
         qword [0x180100e80] = rax // [0x180100e80:8]=0
         r8 = rip + str.getInstance // 0x1800d78e8 // "getInstance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100dd0] // [0x180100dd0:8]=0
         r9 = rip + str.__Lzombie_iso_IsoCell_ // 0x1800d78f8 // "()Lzombie/iso/IsoCell;"
         qword [0x180100e98] = rax // [0x180100e98:8]=0
         r8 = rip + str.getCell   // 0x1800d7910 // "getCell"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100dd8] // [0x180100dd8:8]=0
         r9 = rip + str.__Ljava_util_ArrayList_ // 0x1800d7918 // "()Ljava/util/ArrayList;"
         qword [0x180100ea0] = rax // [0x180100ea0:8]=0
         r8 = rip + str.getZombieList // 0x1800d7930 // "getZombieList"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100dd8] // [0x180100dd8:8]=0
         r9 = rip + str.__Ljava_util_Set_ // 0x1800d7940 // "()Ljava/util/Set;"
         qword [0x180100ea8] = rax // [0x180100ea8:8]=0
         r8 = rip + str.getObjectList // 0x1800d7958 // "getObjectList"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100dd8] // [0x180100dd8:8]=0
         r9 = rip + str.__Ljava_util_Set_ // 0x1800d7940 // "()Ljava/util/Set;"
         qword [0x180100eb0] = rax // [0x180100eb0:8]=0
         r8 = rip + str.getVehicles // 0x1800d7968 // "getVehicles"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100de0] // [0x180100de0:8]=0
         r9 = rip + 0xd5596       // "()I" // 0x1800d7974
         qword [0x180100eb8] = rax // [0x180100eb8:8]=0
         r8 = rip + str.size      // 0x1800d7978 // "size"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100de0] // [0x180100de0:8]=0
         r9 = rip + str._I_Ljava_lang_Object_ // 0x1800d7980 // "(I)Ljava/lang/Object;"
         qword [0x180100ec0] = rax // [0x180100ec0:8]=0
         r8 = rip + 0xd5584       // "get" // 0x1800d7998
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100de8] // [0x180100de8:8]=0
         r9 = rip + str.__Ljava_util_Iterator_ // 0x1800d79a0 // "()Ljava/util/Iterator;"
         qword [0x180100ec8] = rax // [0x180100ec8:8]=0
         r8 = rip + str.iterator  // 0x1800d79b8 // "iterator"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100df0] // [0x180100df0:8]=0
         r9 = rip + 0xd556e       // "()Z" // 0x1800d79c4
         qword [0x180100ed0] = rax // [0x180100ed0:8]=0
         r8 = rip + str.hasNext   // 0x1800d79c8 // "hasNext"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100df0] // [0x180100df0:8]=0
         r9 = rip + str.__Ljava_lang_Object_ // 0x1800d79d0 // "()Ljava/lang/Object;"
         qword [0x180100ed8] = rax // [0x180100ed8:8]=0
         r8 = rip + str.next      // 0x1800d79e8 // "next"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "% " // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100df8] // [0x180100df8:8]=0
         r9 = rip + 0xd554a       // "()F" // 0x1800d79f0
         qword [0x180100ee0] = rax // [0x180100ee0:8]=0
         r8 = rip + str.getX      // 0x1800d79f4 // "getX"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "; " // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100df8] // [0x180100df8:8]=0
         r9 = rip + 0xd5522       // "()F" // 0x1800d79f0
         qword [0x180100ee8] = rax // [0x180100ee8:8]=0
         r8 = rip + str.getY      // 0x1800d79fc // "getY"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "Q " // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100df8] // [0x180100df8:8]=0
         r9 = rip + 0xd54fa       // "()F" // 0x1800d79f0
         qword [0x180100ef0] = rax // [0x180100ef0:8]=0
         r8 = rip + str.getZ      // 0x1800d7a04 // "getZ"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "g " // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e40] // [0x180100e40:8]=0
         r9 = rip + 0xd5456       // "()I" // 0x1800d7974
         qword [0x180100ef8] = rax // [0x180100ef8:8]=0
         r8 = rip + str.getID     // 0x1800d7a0c // "getID"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "} " // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e68] // [0x180100e68:8]=0
         qword [0x180100f00] = rax // [0x180100f00:8]=0
         v = rdx & rdx
         if (!v) 
         goto loc_0x18000254b;
    loc_0x18000254b: // orphan
         rax = qword [rbx]
         r9 = rip + str._Ljava_lang_Object__I // 0x1800d7a18 // "(Ljava/lang/Object;)I"
         r8 = rip + str.identityHashCode // 0x1800d7a30 // "identityHashCode"
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         qword [0x1801010b0] = rax // [0x1801010b0:8]=0

    loc_0x18000256c: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180002549(x)
         rdx = qword [0x180100e40] // [0x180100e40:8]=0
         v = rdx & rdx
         if (!v) 
         goto loc_0x18000257c;
    loc_0x18000257c: // orphan
         rax = qword [rbx]
         r9 = rip + 0xd546a       // "()F" // 0x1800d79f0
         r8 = rip + str.getHealth // 0x1800d7a48 // "getHealth"
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "e%" // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e40] // [0x180100e40:8]=0
         r9 = rip + 0xd5420       // "()Z" // 0x1800d79c4
         qword [0x180100fc0] = rax // [0x180100fc0:8]=0
         r8 = rip + str.isAlive   // 0x1800d7a58 // "isAlive"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e40] // [0x180100e40:8]=0
         r9 = rip + str.__Lzombie_core_skinnedmodel_animation_AnimationPlayer_ // 0x1800d7a60 // "()Lzombie/core/skinnedmodel/animation/AnimationPlayer;"
         qword [0x180100fc8] = rax // [0x180100fc8:8]=0
         r8 = rip + str.getAnimationPlayer // 0x1800d7a98 // "getAnimationPlayer"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e40] // [0x180100e40:8]=0
         r9 = rip + 0xd53fc       // "()F" // 0x1800d79f0
         qword [0x180101020] = rax // [0x180101020:8]=0
         r8 = rip + str.getForwardDirectionX // 0x1800d7ab0 // "getForwardDirectionX"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "0#" // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e40] // [0x180100e40:8]=0
         r9 = rip + 0xd53d4       // "()F" // 0x1800d79f0
         qword [0x180101088] = rax // [0x180101088:8]=0
         r8 = rip + str.getForwardDirectionY // 0x1800d7ac8 // "getForwardDirectionY"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "X#" // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e40] // [0x180100e40:8]=0
         r9 = rip + 0xd5380       // "()Z" // 0x1800d79c4
         qword [0x180101090] = rax // [0x180101090:8]=0
         r8 = rip + str.isFallOnFront // 0x1800d7ae0 // "isFallOnFront"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e40] // [0x180100e40:8]=0
         r9 = rip + 0xd5358       // "()Z" // 0x1800d79c4
         qword [0x180100ff0] = rax // [0x180100ff0:8]=0
         r8 = rip + str.isFalling // 0x1800d7af0 // "isFalling"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e40] // [0x180100e40:8]=0
         r9 = rip + 0xd5330       // "()Z" // 0x1800d79c4
         qword [0x180100fe0] = rax // [0x180100fe0:8]=0
         r8 = rip + str.isKnockedDown // 0x1800d7b00 // "isKnockedDown"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e40] // [0x180100e40:8]=0
         r9 = rip + str._F_V      // 0x1800d7b10 // "(F)V"
         qword [0x180100fe8] = rax // [0x180100fe8:8]=0
         r8 = rip + str.setAlphaAndTarget // 0x1800d7b18 // "setAlphaAndTarget"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x180100ff8] = rax // [0x180100ff8:8]=0

    loc_0x1800026dd: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180002576(x)
         rax = qword [rbx]
         r9 = rip + 0xd5445       // "()S" // 0x1800d7b2c
         rdx = qword [0x180100db0] // [0x180100db0:8]=0
         r8 = rip + str.getOnlineID // 0x1800d7b30 // "getOnlineID"
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100db0] // [0x180100db0:8]=0
         r9 = rip + str.__Ljava_lang_String_ // 0x1800d7b40 // "()Ljava/lang/String;"
         qword [0x180100f10] = rax // [0x180100f10:8]=0
         r8 = rip + str.getUsername // 0x1800d7b58 // "getUsername"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100db0] // [0x180100db0:8]=0
         r9 = rip + str.__Lzombie_characters_Safety_ // 0x1800d7b68 // "()Lzombie/characters/Safety;"
         qword [0x180100f18] = rax // [0x180100f18:8]=0
         r8 = rip + str.getSafety // 0x1800d7b88 // "getSafety"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e48] // [0x180100e48:8]=0
         qword [0x180100f20] = rax // [0x180100f20:8]=0
         v = rdx & rdx
         if (!v) 
         goto loc_0x180002761;
    loc_0x180002761: // orphan
         rax = qword [rbx]
         r9 = rip + 0xd5259       // "()Z" // 0x1800d79c4
         r8 = rip + str.isEnabled // 0x1800d7b98 // "isEnabled"
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x180100f28] = rax // [0x180100f28:8]=0

    loc_0x180002782: // orphan
         // CODE XREF from fcn.180001df0 @ 0x18000275f(x)
         rdx = qword [0x180100e50] // [0x180100e50:8]=0
         v = rdx & rdx
         if (!v) 
         goto loc_0x18000278e;
    loc_0x18000278e: // orphan
         rax = qword [rbx]
         r9 = rip + str._Lzombie_iso_IsoMovingObject_Lzombie_iso_IsoMovingObject_Z_Z // 0x1800d7ba8 // "(Lzombie/iso/IsoMovingObject;Lzombie/iso/IsoMovingObject;Z)Z"
         r8 = rip + str.checkPVP  // 0x1800d7be8 // "checkPVP"
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // "{'" // 0x388(0x0, 0x0, 0x0, 0x0)
         qword [0x180100f30] = rax // [0x180100f30:8]=0

    loc_0x1800027af: // orphan
         // CODE XREF from fcn.180001df0 @ 0x18000278c(x)
         rax = qword [rbx]
         r9 = rip + str.__Ljava_lang_String_ // 0x1800d7b40 // "()Ljava/lang/String;"
         rdx = qword [0x180100db8] // [0x180100db8:8]=0
         r8 = rip + str.getCustomName // 0x1800d7bf8 // "getCustomName"
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100db8] // [0x180100db8:8]=0
         r9 = rip + str.__Ljava_lang_String_ // 0x1800d7b40 // "()Ljava/lang/String;"
         qword [0x180100f38] = rax // [0x180100f38:8]=0
         r8 = rip + str.getFullName // 0x1800d7c08 // "getFullName"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "&'" // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100db8] // [0x180100db8:8]=0
         r9 = rip + str.__Ljava_lang_String_ // 0x1800d7b40 // "()Ljava/lang/String;"
         qword [0x180100f40] = rax // [0x180100f40:8]=0
         r8 = rip + str.getAnimalType // 0x1800d7c18 // "getAnimalType"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "N'" // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100db8] // [0x180100db8:8]=0
         r9 = rip + 0xd51c2       // "()F" // 0x1800d79f0
         qword [0x180100f48] = rax // [0x180100f48:8]=0
         r8 = rip + str.getAnimalSize // 0x1800d7c28 // "getAnimalSize"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100db8] // [0x180100db8:8]=0
         r9 = rip + 0xd516e       // "()Z" // 0x1800d79c4
         qword [0x180100f50] = rax // [0x180100f50:8]=0
         r8 = rip + str.isBaby    // 0x1800d7c38 // "isBaby"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "6&" // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100dc0] // [0x180100dc0:8]=0
         r9 = rip + 0xd52ae       // "()S" // 0x1800d7b2c
         qword [0x180100f58] = rax // [0x180100f58:8]=0
         r8 = rip + str.getId     // 0x1800d7c40 // "getId"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "^&" // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100dc0] // [0x180100dc0:8]=0
         r9 = rip + str.__Ljava_lang_String_ // 0x1800d7b40 // "()Ljava/lang/String;"
         qword [0x180100f60] = rax // [0x180100f60:8]=0
         r8 = rip + str.getScriptName // 0x1800d7c48 // "getScriptName"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100dc0] // [0x180100dc0:8]=0
         r9 = rip + 0xd50a6       // "()I" // 0x1800d7974
         qword [0x180100f68] = rax // [0x180100f68:8]=0
         r8 = rip + str.getEngineCondition // 0x1800d7c58 // "getEngineCondition"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100dc0] // [0x180100dc0:8]=0
         r9 = rip + 0xd50ce       // "()Z" // 0x1800d79c4
         qword [0x180100f70] = rax // [0x180100f70:8]=0
         r8 = rip + str.isEngineRunning // 0x1800d7c70 // "isEngineRunning"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100dc0] // [0x180100dc0:8]=0
         r9 = rip + 0xd50a6       // "()Z" // 0x1800d79c4
         qword [0x180100f78] = rax // [0x180100f78:8]=0
         r8 = rip + str.areAllDoorsLocked // 0x1800d7c80 // "areAllDoorsLocked"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // " $" // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100dc0] // [0x180100dc0:8]=0
         r9 = rip + 0xd507e       // "()Z" // 0x1800d79c4
         qword [0x180100f80] = rax // [0x180100f80:8]=0
         r8 = rip + str.isAnyDoorLocked // 0x1800d7c98 // "isAnyDoorLocked"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "H$" // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100dc0] // [0x180100dc0:8]=0
         r9 = rip + 0xd5056       // "()Z" // 0x1800d79c4
         qword [0x180100f88] = rax // [0x180100f88:8]=0
         r8 = rip + str.isHotwired // 0x1800d7ca8 // "isHotwired"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "p$" // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100dc0] // [0x180100dc0:8]=0
         r9 = rip + 0xd502e       // "()Z" // 0x1800d79c4
         qword [0x180100f90] = rax // [0x180100f90:8]=0
         r8 = rip + str.isHotwiredBroken // 0x1800d7cb8 // "isHotwiredBroken"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100dc0] // [0x180100dc0:8]=0
         r9 = rip + 0xd5006       // "()Z" // 0x1800d79c4
         qword [0x180100f98] = rax // [0x180100f98:8]=0
         r8 = rip + str.isKeysInIgnition // 0x1800d7cd0 // "isKeysInIgnition"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100dc0] // [0x180100dc0:8]=0
         r9 = rip + 0xd4f8e       // "()I" // 0x1800d7974
         qword [0x180100fa0] = rax // [0x180100fa0:8]=0
         r8 = rip + str.getKeyId  // 0x1800d7ce8 // "getKeyId"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100db0] // [0x180100db0:8]=0
         r9 = rip + str.__Lzombie_inventory_ItemContainer_ // 0x1800d7cf8 // "()Lzombie/inventory/ItemContainer;"
         qword [0x180100fa8] = rax // [0x180100fa8:8]=0
         r8 = rip + str.getInventory // 0x1800d7d20 // "getInventory"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100dc8] // [0x180100dc8:8]=0
         r9 = rip + str._I_Lzombie_inventory_InventoryItem_ // 0x1800d7d30 // "(I)Lzombie/inventory/InventoryItem;"
         qword [0x180100fb0] = rax // [0x180100fb0:8]=0
         r8 = rip + str.haveThisKeyId // 0x1800d7d58 // "haveThisKeyId"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "8%" // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = rip + str.zombie_characters_IsoZombie // 0x1800d7d68 // "zombie/characters/IsoZombie"
         rcx = rbx
         qword [0x180100fb8] = rax // [0x180100fb8:8]=0
         fcn.180001b80 ()         // fcn.180001b80(0x0, 0x0)
         rdi = rax
         v = rax & rax
         if (!v) 
         goto loc_0x180002a6e;
    loc_0x180002a6e: // orphan
         r10 = qword [rbx]
         r9 = rip + 0xd50b4       // "()S" // 0x1800d7b2c
         r8 = rip + str.getOnlineID // 0x1800d7b30 // "getOnlineID"
         rdx = rax
         rcx = rbx
         qword [r10 + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x180100f08] = rax // [0x180100f08:8]=0
         r9 = rip + 0xd4f2a       // "()Z" // 0x1800d79c4
         r10 = qword [rbx]
         rdx = rdi
         r8 = rip + str.isCrawling // 0x1800d7d88 // "isCrawling"
         rcx = rbx
         qword [r10 + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x180100fd0] = rax // [0x180100fd0:8]=0
         r9 = rip + 0xd4f05       // "()Z" // 0x1800d79c4
         rax = qword [rbx]
         rdx = rdi
         r8 = rip + str.isProne   // 0x1800d7d98 // "isProne"
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // " (" // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x180100fd8] = rax // [0x180100fd8:8]=0
         rdx = rdi
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0xb0] ()    // 176 // "H(" // 0xb0(0x0, 0x0, 0x0, 0x0)

    loc_0x180002aeb: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180002a6c(x)
         rax = qword [rbx]
         r9 = rip + str._FFFI_F   // 0x1800d7da0 // "(FFFI)F"
         rdx = qword [0x180100e00] // [0x180100e00:8]=0
         r8 = rip + str.XToScreenExact // 0x1800d7da8 // "XToScreenExact"
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e00] // [0x180100e00:8]=0
         r9 = rip + str._FFFI_F   // 0x1800d7da0 // "(FFFI)F"
         qword [0x180101000] = rax // [0x180101000:8]=0
         r8 = rip + str.YToScreenExact // 0x1800d7db8 // "YToScreenExact"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e08] // [0x180100e08:8]=0
         r9 = rip + str.__Lzombie_core_Core_ // 0x1800d7dc8 // "()Lzombie/core/Core;"
         qword [0x180101008] = rax // [0x180101008:8]=0
         r8 = rip + str.getInstance // 0x1800d78e8 // "getInstance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e08] // [0x180100e08:8]=0
         r9 = rip + str._I_F      // 0x1800d7de0 // "(I)F"
         qword [0x180101010] = rax // [0x180101010:8]=0
         r8 = rip + str.getZoom   // 0x1800d7de8 // "getZoom"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e40] // [0x180100e40:8]=0
         qword [0x180101018] = rax // [0x180101018:8]=0
         v = rdx & rdx
         if (!v) 
         goto loc_0x180002b9b;
    loc_0x180002b9b: // orphan
         v = qword [0x180100e58] - 0 // [0x180100e58:8]=0
         if (!v) 
         goto loc_0x180002ba9;
    loc_0x180002ba9: // orphan
         v = qword [0x180100e60] - 0 // [0x180100e60:8]=0
         if (!v) 
         goto loc_0x180002bb7;
    loc_0x180002bb7: // orphan
         rax = qword [rbx]
         r9 = rip + 0xd4e2f       // "()F" // 0x1800d79f0
         r8 = rip + str.getForwardDirectionX // 0x1800d7ab0 // "getForwardDirectionX"
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e40] // [0x180100e40:8]=0
         r9 = rip + 0xd4e11       // "()F" // 0x1800d79f0
         qword [0x180101098] = rax // [0x180101098:8]=0
         r8 = rip + str.getForwardDirectionY // 0x1800d7ac8 // "getForwardDirectionY"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "4+" // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e58] // [0x180100e58:8]=0
         r9 = rip + str._Lzombie_iso_IsoCell_IIIIIIZ_Lzombie_iso_LosUtil_TestResults_ // 0x1800d7df0 // "(Lzombie/iso/IsoCell;IIIIIIZ)Lzombie/iso/LosUtil$TestResults;"
         qword [0x1801010a0] = rax // [0x1801010a0:8]=0
         r8 = rip + str.lineClear // 0x1800d7e30 // "lineClear"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // "\+" // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e60] // [0x180100e60:8]=0
         r9 = rip + str.Lzombie_iso_LosUtil_TestResults_ // 0x1800d7e40 // "Lzombie/iso/LosUtil$TestResults;"
         qword [0x1801010a8] = rax // [0x1801010a8:8]=0
         r8 = rip + str.Blocked   // 0x1800d7e68 // "Blocked"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         r10 = qword [rbx]
         r9 = rip + str.Lzombie_iso_LosUtil_TestResults_ // 0x1800d7e40 // "Lzombie/iso/LosUtil$TestResults;"
         rdx = qword [0x180100e60] // [0x180100e60:8]=0
         r8 = rip + str.ClearThroughClosedDoor // 0x1800d7e70 // "ClearThroughClosedDoor"
         rcx = rbx
         rsi = rax
         qword [r10 + 0x480] ()   // 1152 // "p(" // 0x480(0x0, -1, 0x0, 0x0)
         rdi = rax
         v = rsi & rsi
         if (!v) 
         goto loc_0x180002c76;
    loc_0x180002c76: // orphan
         rax = qword [rbx]
         r8 = rsi
         rdx = qword [0x180100e60] // [0x180100e60:8]=0
         rcx = rbx
         qword [rax + 0x488] ()   // 1160 // 0x488(0x0, 0x0, 0x0, 0x0)
         rsi = rax

    loc_0x180002c8f: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180002c74(x)
         v = rdi & rdi
         if (!v) 
         goto loc_0x180002c94;
    loc_0x180002c94: // orphan
         rax = qword [rbx]
         r8 = rdi
         rdx = qword [0x180100e60] // [0x180100e60:8]=0
         rcx = rbx
         qword [rax + 0x488] ()   // 1160 // 0x488(0x0, 0x0, 0x0, 0x0)
         rdi = rax

    loc_0x180002cad: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180002c92(x)
         rdx = qword [rbx]
         rcx = rbx
         qword [rdx + 0x720] ()   // 1824 // 0x720(0x0, 0x0, -1, 0x0)
         v = al & al
         if (v) 
         goto loc_0x180002cbd;
    loc_0x180002cbd: // orphan
         v = qword [0x180101098] - 0 // [0x180101098:8]=-1
         if (!v) 
         goto loc_0x180002cc7;
    loc_0x180002cc7: // orphan
         v = qword [0x1801010a0] - 0 // [0x1801010a0:8]=-1
         if (!v) 
         goto loc_0x180002cd1;
    loc_0x180002cd1: // orphan
         v = qword [0x1801010a8] - 0 // [0x1801010a8:8]=-1
         if (!v) 
         goto loc_0x180002cdb;
    loc_0x180002cdb: // orphan
         v = rsi & rsi
         if (!v) 
         goto loc_0x180002ce0;
    loc_0x180002ce0: // orphan
         v = rdi & rdi
         if (!v) 
         goto loc_0x180002ce5;
    loc_0x180002ce5: // orphan
         rax = qword [rbx]
         rdx = rsi
         rcx = rbx
         qword [rax + 0xa8] ()    // 168 // 0xa8(0x0, 0x0, 0x0, 0x0)
         qword [0x180100e88] = rax // [0x180100e88:8]=0
         rdx = rdi
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0xa8] ()    // 168 // 0xa8(0x0, 0x0, 0x0, 0x0)
         v = qword [0x180100e88] - 0 // [0x180100e88:8]=-1
         qword [0x180100e90] = rax // [0x180100e90:8]=0
         if (!v) 
         goto loc_0x180002d1b;
    loc_0x180002d1b: // orphan
         v = rax & rax
         if (!v) 
         goto loc_0x180002d20;
    loc_0x180002d20: // orphan
         byte [0x180101181] = 1   // [0x180101181:1]=0
         
         goto loc_0x180002d29;
    loc_0x180002d29: // orphan
         // CODE XREFS from fcn.180001df0 @ 0x180002d19(x), 0x180002d1e(x)
         byte [0x180101181] = 0   // [0x180101181:1]=1
         
         goto loc_0x180002d32;
    loc_0x180002d32: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180002cbb(x)
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x88] ()    // 136 // 0x88(0x0, 0x0, 0x0, 0x0)

    loc_0x180002d3e: // orphan
         // CODE XREFS from fcn.180001df0 @ 0x180002cc5(x), 0x180002ccf(x), 0x180002cd9(x)
         v = rsi & rsi
         if (!v) 
         goto loc_0x180002d43;
    loc_0x180002d43: // orphan
         // CODE XREFS from fcn.180001df0 @ 0x180002ce3(x), 0x180002d27(x), 0x180002d30(x)
         rax = qword [rbx]
         rdx = rsi
         rcx = rbx
         qword [rax + 0xb8] ()    // 184 // ">-" // 0xb8(0x0, 0x0, 0x0, 0x0)

    loc_0x180002d52: // orphan
         // CODE XREFS from fcn.180001df0 @ 0x180002cde(x), 0x180002d41(x)
         v = rdi & rdi
         if (!v) 
         goto loc_0x180002d57;
    loc_0x180002d57: // orphan
         rax = qword [rbx]
         rdx = rdi
         rcx = rbx
         qword [rax + 0xb8] ()    // 184 // "R-" // 0xb8(0x0, 0x0, 0x0, 0x0)

    loc_0x180002d66: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180002d55(x)
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x720] ()   // 1824 // "f-" // 0x720(0x0, 0x0, 0x0, 0x0)
         v = al & al
         if (!v) 
         goto loc_0x180002d76;
    loc_0x180002d76: // orphan
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x88] ()    // 136 // "r-" // 0x88(0x0, 0x0, 0x0, 0x0)

    loc_0x180002d82: // orphan
         // CODE XREFS from fcn.180001df0 @ 0x180002b95(x), 0x180002ba3(x), 0x180002bb1(x), 0x180002d74(x)
         rax = qword [rbx]
         r9 = rip + 0xd4c38       // "()Z" // 0x1800d79c4
         rdx = qword [0x180100e10] // [0x180100e10:8]=0
         r8 = rip + str.isReady   // 0x1800d7e88 // "isReady"
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e10] // [0x180100e10:8]=0
         r9 = rip + str._Ljava_lang_String_I_I // 0x1800d7e90 // "(Ljava/lang/String;I)I"
         qword [0x180101028] = rax // [0x180101028:8]=0
         r8 = rip + str.getSkinningBoneIndex // 0x1800d7ea8 // "getSkinningBoneIndex"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "\n-" // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e10] // [0x180100e10:8]=0
         r9 = rip + str._ILorg_lwjgl_util_vector_Matrix4f__Lorg_lwjgl_util_vector_Matrix4f_ // 0x1800d7ec0 // "(ILorg/lwjgl/util/vector/Matrix4f;)Lorg/lwjgl/util/vector/Matrix4f;"
         qword [0x180101030] = rax // [0x180101030:8]=0
         r8 = rip + str.getBoneModelTransform // 0x1800d7f08 // "getBoneModelTransform"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "!," // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e10] // [0x180100e10:8]=0
         r9 = rip + str._I_Lorg_lwjgl_util_vector_Matrix4f_ // 0x1800d7f20 // "(I)Lorg/lwjgl/util/vector/Matrix4f;"
         qword [0x180101038] = rax // [0x180101038:8]=0
         r8 = rip + str.getModelTransformAt // 0x1800d7f48 // "getModelTransformAt"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "I," // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e10] // [0x180100e10:8]=0
         r9 = rip + str.__Lzombie_core_skinnedmodel_model_SkinningData_ // 0x1800d7f60 // "()Lzombie/core/skinnedmodel/model/SkinningData;"
         qword [0x180101040] = rax // [0x180101040:8]=0
         r8 = rip + str.getSkinningData // 0x1800d7f90 // "getSkinningData"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // "n," // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e20] // [0x180100e20:8]=0
         r9 = rip + str._Ljava_lang_String__Lzombie_core_skinnedmodel_model_SkinningBone_ // 0x1800d7fa0 // "(Ljava/lang/String;)Lzombie/core/skinnedmodel/model/SkinningBone;"
         qword [0x180101048] = rax // [0x180101048:8]=0
         r8 = rip + str.getBone   // 0x1800d7fe8 // "getBone"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e10] // [0x180100e10:8]=0
         r9 = rip + str._Lzombie_core_skinnedmodel_model_SkeletonBone_Lorg_lwjgl_util_vector_Vector3f__Lorg_lwjgl_util_vector_Vector3f_ // 0x1800d7ff0 // "(Lzombie/core/skinnedmodel/model/SkeletonBone;Lorg/lwjgl/util/vector/Vector3f;)Lorg/lwjgl/util/vector/Vector3f;"
         qword [0x180101050] = rax // [0x180101050:8]=0
         r8 = rip + str.getBoneWorldPosition // 0x1800d8060 // "getBoneWorldPosition"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e30] // [0x180100e30:8]=0
         r9 = rip + 0xd51d7       // "()V" // 0x1800d8078
         qword [0x180101058] = rax // [0x180101058:8]=0
         r8 = rip + str._init_    // 0x1800d807c // "<init>"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e30] // [0x180100e30:8]=0
         r9 = rip + str.Fxyz      // 0x1800d8084 // "Fxyz"
         qword [0x180101060] = rax // [0x180101060:8]=0
         r8 = rip + 0xd51b1       // "xyz" // 0x1800d8088
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x2f0] ()   // 752 // 0x2f0(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e30] // [0x180100e30:8]=0
         r9 = rip + str.Fxyz      // 0x1800d8084 // "Fxyz"
         qword [0x180101068] = rax // [0x180101068:8]=0
         r8 = rip + 0xd518d       // "yz" // 0x1800d808c
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x2f0] ()   // 752 // "8)" // 0x2f0(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e30] // [0x180100e30:8]=0
         r9 = rip + str.Fxyz      // 0x1800d8084 // "Fxyz"
         qword [0x180101070] = rax // [0x180101070:8]=0
         r8 = rip + 0xd5169       // "z" // 0x1800d8090
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x2f0] ()   // 752 // "`)" // 0x2f0(0x0, 0x0, 0x0, 0x0)
         v = qword [0x180101058] - 0 // [0x180101058:8]=-1
         qword [0x180101078] = rax // [0x180101078:8]=0
         if (!v) 
         goto loc_0x180002f48;
    loc_0x180002f48: // orphan
         v = qword [0x180101060] - 0 // [0x180101060:8]=-1
         if (!v) 
         goto loc_0x180002f56;
    loc_0x180002f56: // orphan
         v = qword [0x180101068] - 0 // [0x180101068:8]=-1
         if (!v) 
         goto loc_0x180002f64;
    loc_0x180002f64: // orphan
         v = qword [0x180101070] - 0 // [0x180101070:8]=-1
         if (!v) 
         goto loc_0x180002f72;
    loc_0x180002f72: // orphan
         v = rax & rax
         if (!v) 
         goto loc_0x180002f7b;
    loc_0x180002f7b: // orphan
         byte [0x180101180] = 1   // [0x180101180:1]=0
         rsi = rip - 0x2f89       // 0x180000000
         edi = 0

    loc_0x180002f90: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180002fee(x)
         v = rdi - 0x13           // 19
         jae 0x180003002          // unlikely

         goto loc_0x180002f96;
    loc_0x180002f96: // orphan
         rax = qword [rbx]
         r9 = rip + str.Lzombie_core_skinnedmodel_model_SkeletonBone_ // 0x1800d8098 // "Lzombie/core/skinnedmodel/model/SkeletonBone;"
         r8 = qword [rsi + rdi*8 + 0xd8520]
         rcx = rbx
         rdx = qword [0x180100e38] // [0x180100e38:8]=0
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         qword [rsi + rdi*8 + 0x1010e8] = rax // [0x1010e8:8]=0
         v = rax & rax
         if (!v) 
         goto loc_0x180002fc5;
    loc_0x180002fc5: // orphan
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x720] ()   // 1824 // 0x720(0x0, 0x0, 0x0, 0x0)
         v = al & al
         if (!v) 
         goto loc_0x180002fd5;
    loc_0x180002fd5: // orphan
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x88] ()    // 136 // 0x88(0x0, 0x0, 0x0, 0x0)

    loc_0x180002fe1: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180002fc3(x)
         al = 0
         byte [0x180101180] = al  // [0x180101180:1]=1

    loc_0x180002fe9: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180002ff9(x)
         rdi++
         v = al & al
         if (v) 
         goto loc_0x180002ff0;
    loc_0x180002ff2: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180002fd3(x)
         eax = byte [0x180101180] // [0x180101180:1]=0
         
         goto loc_0x180002ffb;
    loc_0x180002ffb: // orphan
         // CODE XREFS from fcn.180001df0 @ 0x180002f42(x), 0x180002f50(x), 0x180002f5e(x), 0x180002f6c(x), 0x180002f75(x)
         byte [0x180101180] = 0   // [0x180101180:1]=0

    loc_0x180003002: // orphan
         // CODE XREFS from fcn.180001df0 @ 0x180002f94(x), 0x180002ff0(x)
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x720] ()   // 1824 // 0x720(0x0, 0x0, 0x0, 0x0)
         v = al & al
         if (!v) 
         goto loc_0x180003012;
    loc_0x180003012: // orphan
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x88] ()    // 136 // 0x88(0x0, 0x0, 0x0, 0x0)

    loc_0x18000301e: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003010(x)
         rax = qword [rbx]
         r9 = rip + 0xd5050       // "()V" // 0x1800d8078
         rdx = qword [0x180100e18] // [0x180100e18:8]=0
         r8 = rip + str._init_    // 0x1800d807c // "<init>"
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e18] // [0x180100e18:8]=0
         r9 = rip + str.Fxyz      // 0x1800d8084 // "Fxyz"
         qword [0x180101080] = rax // [0x180101080:8]=0
         r8 = rip + 0xd506d       // "m30" // 0x1800d80c8
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x2f0] ()   // 752 // 0x2f0(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e18] // [0x180100e18:8]=0
         r9 = rip + str.Fxyz      // 0x1800d8084 // "Fxyz"
         qword [0x1801010b8] = rax // [0x1801010b8:8]=0
         r8 = rip + 0xd5049       // "m31" // 0x1800d80cc
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x2f0] ()   // 752 // 0x2f0(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e18] // [0x180100e18:8]=0
         r9 = rip + str.Fxyz      // 0x1800d8084 // "Fxyz"
         qword [0x1801010c0] = rax // [0x1801010c0:8]=0
         r8 = rip + 0xd5025       // "m32" // 0x1800d80d0
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x2f0] ()   // 752 // 0x2f0(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e18] // [0x180100e18:8]=0
         r9 = rip + str.Fxyz      // 0x1800d8084 // "Fxyz"
         qword [0x1801010c8] = rax // [0x1801010c8:8]=0
         r8 = rip + 0xd5001       // "m03" // 0x1800d80d4
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x2f0] ()   // 752 // "C." // 0x2f0(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e18] // [0x180100e18:8]=0
         r9 = rip + str.Fxyz      // 0x1800d8084 // "Fxyz"
         qword [0x1801010d0] = rax // [0x1801010d0:8]=0
         r8 = rip + 0xd4fdd       // "m13" // 0x1800d80d8
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x2f0] ()   // 752 // "k." // 0x2f0(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180100e18] // [0x180100e18:8]=0
         r9 = rip + str.Fxyz      // 0x1800d8084 // "Fxyz"
         qword [0x1801010d8] = rax // [0x1801010d8:8]=0
         r8 = rip + 0xd4fb9       // "m23" // 0x1800d80dc
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x2f0] ()   // 752 // 0x2f0(0x0, 0x0, 0x0, 0x0)
         qword [0x1801010e0] = rax // [0x1801010e0:8]=0
         rcx = rbx
         rax = qword [rbx]
         qword [rax + 0x720] ()   // 1824 // 0x720(0x0, 0x0, 0x0, 0x0)
         v = al & al
         if (v) 
         goto loc_0x18000314a;
    loc_0x18000314a: // orphan
         rax = qword [0x180100e70] // [0x180100e70:8]=-1
         v = rax & rax
         if (!v) 
         goto loc_0x18000315a;
    loc_0x18000315a: // orphan
         rcx = qword [0x180100e78] // [0x180100e78:8]=-1
         v = rcx & rcx
         if (!v) 
         goto loc_0x18000316a;
    loc_0x18000316a: // orphan
         v = qword [0x180100e80] - 0 // [0x180100e80:8]=-1
         if (!v) 
         goto loc_0x180003178;
    loc_0x180003178: // orphan
         v = qword [0x180100e98] - 0 // [0x180100e98:8]=-1
         if (!v) 
         goto loc_0x180003186;
    loc_0x180003186: // orphan
         v = qword [0x180100ea0] - 0 // [0x180100ea0:8]=-1
         if (!v) 
         goto loc_0x180003194;
    loc_0x180003194: // orphan
         v = qword [0x180100ea8] - 0 // [0x180100ea8:8]=-1
         if (!v) 
         goto loc_0x1800031a2;
    loc_0x1800031a2: // orphan
         v = qword [0x180100eb0] - 0 // [0x180100eb0:8]=-1
         if (!v) 
         goto loc_0x1800031b0;
    loc_0x1800031b0: // orphan
         v = qword [0x180100eb8] - 0 // [0x180100eb8:8]=-1
         if (!v) 
         goto loc_0x1800031be;
    loc_0x1800031be: // orphan
         v = qword [0x180100ec0] - 0 // [0x180100ec0:8]=-1
         if (!v) 
         goto loc_0x1800031cc;
    loc_0x1800031cc: // orphan
         v = qword [0x180100ec8] - 0 // [0x180100ec8:8]=-1
         if (!v) 
         goto loc_0x1800031da;
    loc_0x1800031da: // orphan
         v = qword [0x180100ed0] - 0 // [0x180100ed0:8]=-1
         if (!v) 
         goto loc_0x1800031e8;
    loc_0x1800031e8: // orphan
         v = qword [0x180100ed8] - 0 // [0x180100ed8:8]=-1
         if (!v) 
         goto loc_0x1800031f6;
    loc_0x1800031f6: // orphan
         v = qword [0x180100ee0] - 0 // [0x180100ee0:8]=-1
         if (!v) 
         goto loc_0x180003204;
    loc_0x180003204: // orphan
         v = qword [0x180100ee8] - 0 // [0x180100ee8:8]=-1
         if (!v) 
         goto loc_0x180003212;
    loc_0x180003212: // orphan
         v = qword [0x180100ef0] - 0 // [0x180100ef0:8]=-1
         if (!v) 
         goto loc_0x180003220;
    loc_0x180003220: // orphan
         v = qword [0x180100ef8] - 0 // [0x180100ef8:8]=-1
         if (!v) 
         goto loc_0x18000322e;
    loc_0x18000322e: // orphan
         v = qword [0x180100f00] - 0 // [0x180100f00:8]=-1
         if (!v) 
         goto loc_0x18000323c;
    loc_0x18000323c: // orphan
         v = qword [0x180100f08] - 0 // [0x180100f08:8]=0
         if (!v) 
         goto loc_0x18000324a;
    loc_0x18000324a: // orphan
         v = qword [0x180100f10] - 0 // [0x180100f10:8]=-1
         if (!v) 
         goto loc_0x180003258;
    loc_0x180003258: // orphan
         v = qword [0x180100f18] - 0 // [0x180100f18:8]=-1
         if (!v) 
         goto loc_0x180003266;
    loc_0x180003266: // orphan
         v = qword [0x180100f20] - 0 // [0x180100f20:8]=-1
         if (!v) 
         goto loc_0x180003274;
    loc_0x180003274: // orphan
         v = qword [0x180100f28] - 0 // [0x180100f28:8]=-1
         if (!v) 
         goto loc_0x180003282;
    loc_0x180003282: // orphan
         v = qword [0x180100f30] - 0 // [0x180100f30:8]=-1
         if (!v) 
         goto loc_0x180003290;
    loc_0x180003290: // orphan
         v = qword [0x180100f38] - 0 // [0x180100f38:8]=-1
         if (!v) 
         goto loc_0x18000329e;
    loc_0x18000329e: // orphan
         v = qword [0x180100f40] - 0 // [0x180100f40:8]=-1
         if (!v) 
         goto loc_0x1800032ac;
    loc_0x1800032ac: // orphan
         v = qword [0x180100f48] - 0 // [0x180100f48:8]=-1
         if (!v) 
         goto loc_0x1800032ba;
    loc_0x1800032ba: // orphan
         v = qword [0x180100f50] - 0 // [0x180100f50:8]=-1
         if (!v) 
         goto loc_0x1800032c8;
    loc_0x1800032c8: // orphan
         v = qword [0x180100f58] - 0 // [0x180100f58:8]=-1
         if (!v) 
         goto loc_0x1800032d6;
    loc_0x1800032d6: // orphan
         v = qword [0x180100f60] - 0 // [0x180100f60:8]=-1
         if (!v) 
         goto loc_0x1800032e4;
    loc_0x1800032e4: // orphan
         v = qword [0x180100f68] - 0 // [0x180100f68:8]=-1
         if (!v) 
         goto loc_0x1800032f2;
    loc_0x1800032f2: // orphan
         v = qword [0x180100f70] - 0 // [0x180100f70:8]=-1
         if (!v) 
         goto loc_0x180003300;
    loc_0x180003300: // orphan
         v = qword [0x180100f78] - 0 // [0x180100f78:8]=-1
         if (!v) 
         goto loc_0x18000330e;
    loc_0x18000330e: // orphan
         v = qword [0x180100f80] - 0 // [0x180100f80:8]=-1
         if (!v) 
         goto loc_0x18000331c;
    loc_0x18000331c: // orphan
         v = qword [0x180100f88] - 0 // [0x180100f88:8]=-1
         if (!v) 
         goto loc_0x18000332a;
    loc_0x18000332a: // orphan
         v = qword [0x180100f90] - 0 // [0x180100f90:8]=-1
         if (!v) 
         goto loc_0x180003338;
    loc_0x180003338: // orphan
         v = qword [0x180100f98] - 0 // [0x180100f98:8]=-1
         if (!v) 
         goto loc_0x180003346;
    loc_0x180003346: // orphan
         v = qword [0x180100fa0] - 0 // [0x180100fa0:8]=-1
         if (!v) 
         goto loc_0x180003354;
    loc_0x180003354: // orphan
         v = qword [0x180100fa8] - 0 // [0x180100fa8:8]=-1
         if (!v) 
         goto loc_0x180003362;
    loc_0x180003362: // orphan
         v = qword [0x180100fb0] - 0 // [0x180100fb0:8]=-1
         if (!v) 
         goto loc_0x180003370;
    loc_0x180003370: // orphan
         v = qword [0x180100fb8] - 0 // [0x180100fb8:8]=-1
         if (!v) 
         goto loc_0x18000337e;
    loc_0x18000337e: // orphan
         v = qword [0x180100fc0] - 0 // [0x180100fc0:8]=-1
         if (!v) 
         goto loc_0x18000338c;
    loc_0x18000338c: // orphan
         v = qword [0x180100fc8] - 0 // [0x180100fc8:8]=-1
         if (!v) 
         goto loc_0x18000339a;
    loc_0x18000339a: // orphan
         v = qword [0x1801010b0] - 0 // [0x1801010b0:8]=-1
         if (!v) 
         goto loc_0x1800033a8;
    loc_0x1800033a8: // orphan
         v = qword [0x180100fd0] - 0 // [0x180100fd0:8]=0
         if (!v) 
         goto loc_0x1800033b6;
    loc_0x1800033b6: // orphan
         v = qword [0x180100fd8] - 0 // [0x180100fd8:8]=-1
         if (!v) 
         goto loc_0x1800033c4;
    loc_0x1800033c4: // orphan
         v = qword [0x180100fe0] - 0 // [0x180100fe0:8]=-1
         if (!v) 
         goto loc_0x1800033d2;
    loc_0x1800033d2: // orphan
         v = qword [0x180100fe8] - 0 // [0x180100fe8:8]=-1
         if (!v) 
         goto loc_0x1800033e0;
    loc_0x1800033e0: // orphan
         v = qword [0x180100ff0] - 0 // [0x180100ff0:8]=-1
         if (!v) 
         goto loc_0x1800033ee;
    loc_0x1800033ee: // orphan
         v = qword [0x180101000] - 0 // [0x180101000:8]=-1
         if (!v) 
         goto loc_0x1800033fc;
    loc_0x1800033fc: // orphan
         v = qword [0x180101008] - 0 // [0x180101008:8]=-1
         if (!v) 
         goto loc_0x18000340a;
    loc_0x18000340a: // orphan
         v = qword [0x180101010] - 0 // [0x180101010:8]=-1
         if (!v) 
         goto loc_0x180003418;
    loc_0x180003418: // orphan
         v = qword [0x180101018] - 0 // [0x180101018:8]=-1
         if (!v) 
         goto loc_0x180003426;
    loc_0x180003426: // orphan
         v = qword [0x180101020] - 0 // [0x180101020:8]=-1
         if (!v) 
         goto loc_0x180003434;
    loc_0x180003434: // orphan
         v = qword [0x180101088] - 0 // [0x180101088:8]=-1
         if (!v) 
         goto loc_0x180003442;
    loc_0x180003442: // orphan
         v = qword [0x180101090] - 0 // [0x180101090:8]=-1
         if (!v) 
         goto loc_0x180003450;
    loc_0x180003450: // orphan
         v = qword [0x180101028] - 0 // [0x180101028:8]=-1
         if (!v) 
         goto loc_0x18000345e;
    loc_0x18000345e: // orphan
         v = qword [0x180101030] - 0 // [0x180101030:8]=-1
         if (!v) 
         goto loc_0x18000346c;
    loc_0x18000346c: // orphan
         v = qword [0x180101038] - 0 // [0x180101038:8]=-1
         if (!v) 
         goto loc_0x18000347a;
    loc_0x18000347a: // orphan
         v = qword [0x180101080] - 0 // [0x180101080:8]=-1
         if (!v) 
         goto loc_0x180003484;
    loc_0x180003484: // orphan
         v = qword [0x180101040] - 0 // [0x180101040:8]=-1
         if (!v) 
         goto loc_0x18000348e;
    loc_0x18000348e: // orphan
         v = qword [0x1801010b8] - 0 // [0x1801010b8:8]=-1
         if (!v) 
         goto loc_0x180003498;
    loc_0x180003498: // orphan
         v = qword [0x1801010c0] - 0 // [0x1801010c0:8]=-1
         if (!v) 
         goto loc_0x1800034a2;
    loc_0x1800034a2: // orphan
         v = qword [0x1801010c8] - 0 // [0x1801010c8:8]=-1
         if (!v) 
         goto loc_0x1800034ac;
    loc_0x1800034ac: // orphan
         v = qword [0x1801010d0] - 0 // [0x1801010d0:8]=-1
         if (!v) 
         goto loc_0x1800034b6;
    loc_0x1800034b6: // orphan
         v = qword [0x1801010d8] - 0 // [0x1801010d8:8]=-1
         if (!v) 
         goto loc_0x1800034c0;
    loc_0x1800034c0: // orphan
         v = qword [0x1801010e0] - 0 // [0x1801010e0:8]=-1
         if (!v) 
         return rax;
    loc_0x1800034ca: // orphan
         rsi = qword [var_30h]
         al = 1
         rdi = qword [var_38h]
         byte [0x180100d88] = 1   // [0x180100d88:1]=0
         rsp += 0x20
         rbx = pop ()
         return

    loc_0x1800034e3: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003144(x)
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x88] ()    // 136 // "?0" // 0x88(0x0, 0x0, 0x0, 0x0)
         rcx = qword [0x180100e78] // [0x180100e78:8]=-1
         rax = qword [0x180100e70] // [0x180100e70:8]=-1

    loc_0x1800034fd: // orphan
         // XREFS(65)
         v = rax & rax
         if (v) 
         goto loc_0x180003502;
    loc_0x180003502: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003154(x)
         rax = rip + str._GameClient.client // 0x1800d80e0 // "\u5b57\u6bb5 GameClient.client"
         
         goto loc_0x18000350e;
    loc_0x18000350e: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003500(x)
         v = rcx & rcx
         if (v) 
         goto loc_0x180003513;
    loc_0x180003513: // orphan
         rax = rip + str._GameServer.server // 0x1800d8100 // "\u5b57\u6bb5 GameServer.server"
         
         goto loc_0x18000351f;
    loc_0x18000351f: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003511(x)
         v = qword [0x180100e80] - 0 // [0x180100e80:8]=-1
         if (v) 
         goto loc_0x180003529;
    loc_0x180003529: // orphan
         rax = rip + str._IsoWorld.instance // 0x1800d8120 // "\u5b57\u6bb5 IsoWorld.instance"
         
         goto loc_0x180003535;
    loc_0x180003535: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003527(x)
         v = qword [0x180100e98] - 0 // [0x180100e98:8]=-1
         if (v) 
         goto loc_0x18000353f;
    loc_0x18000353f: // orphan
         rax = rip + str._IsoPlayer.getInstance // 0x1800d8140 // "\u65b9\u6cd5 IsoPlayer.getInstance"
         
         goto loc_0x18000354b;
    loc_0x18000354b: // orphan
         // CODE XREF from fcn.180001df0 @ 0x18000353d(x)
         v = qword [0x180100ea0] - 0 // [0x180100ea0:8]=-1
         if (v) 
         goto loc_0x180003555;
    loc_0x180003555: // orphan
         rax = rip + str._IsoWorld.getCell // 0x1800d8160 // "\u65b9\u6cd5 IsoWorld.getCell"
         
         goto loc_0x180003561;
    loc_0x180003561: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003553(x)
         v = qword [0x180100ea8] - 0 // [0x180100ea8:8]=-1
         if (v) 
         goto loc_0x18000356b;
    loc_0x18000356b: // orphan
         rax = rip + str._IsoCell.getZombieList // 0x1800d8178 // "\u65b9\u6cd5 IsoCell.getZombieList"
         
         goto loc_0x180003577;
    loc_0x180003577: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003569(x)
         v = qword [0x180100ec0] - 0 // [0x180100ec0:8]=-1
         if (v) 
         goto loc_0x180003581;
    loc_0x180003581: // orphan
         rax = rip + str._ArrayList.size // 0x1800d8198 // "\u65b9\u6cd5 ArrayList.size"
         
         goto loc_0x18000358d;
    loc_0x18000358d: // orphan
         // CODE XREF from fcn.180001df0 @ 0x18000357f(x)
         v = qword [0x180100ec8] - 0 // [0x180100ec8:8]=-1
         if (v) 
         goto loc_0x180003597;
    loc_0x180003597: // orphan
         rax = rip + str._ArrayList.get // 0x1800d81b0 // "\u65b9\u6cd5 ArrayList.get"
         
         goto loc_0x1800035a3;
    loc_0x1800035a3: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003595(x)
         v = qword [0x180100ee8] - 0 // [0x180100ee8:8]=-1
         if (v) 
         goto loc_0x1800035ad;
    loc_0x1800035ad: // orphan
         rax = rip + str._IsoMovingObject.getX // 0x1800d81c8 // "\u65b9\u6cd5 IsoMovingObject.getX"
         
         goto loc_0x1800035b9;
    loc_0x1800035b9: // orphan
         // CODE XREF from fcn.180001df0 @ 0x1800035ab(x)
         v = qword [0x180100ef0] - 0 // [0x180100ef0:8]=-1
         if (v) 
         goto loc_0x1800035c3;
    loc_0x1800035c3: // orphan
         rax = rip + str._IsoMovingObject.getY // 0x1800d81e8 // "\u65b9\u6cd5 IsoMovingObject.getY"
         
         goto loc_0x1800035cf;
    loc_0x1800035cf: // orphan
         // CODE XREF from fcn.180001df0 @ 0x1800035c1(x)
         v = qword [0x180100ef8] - 0 // [0x180100ef8:8]=-1
         if (v) 
         goto loc_0x1800035d9;
    loc_0x1800035d9: // orphan
         rax = rip + str._IsoMovingObject.getZ // 0x1800d8208 // "\u65b9\u6cd5 IsoMovingObject.getZ"
         
         goto loc_0x1800035e5;
    loc_0x1800035e5: // orphan
         // CODE XREF from fcn.180001df0 @ 0x1800035d7(x)
         v = qword [0x180100f00] - 0 // [0x180100f00:8]=-1
         if (v) 
         goto loc_0x1800035ef;
    loc_0x1800035ef: // orphan
         rax = rip + str._IsoGameCharacter.getID // 0x1800d8228 // "\u65b9\u6cd5 IsoGameCharacter.getID"
         
         goto loc_0x1800035fb;
    loc_0x1800035fb: // orphan
         // CODE XREF from fcn.180001df0 @ 0x1800035ed(x)
         v = qword [0x180100f08] - 0 // [0x180100f08:8]=0
         if (v) 
         goto loc_0x180003605;
    loc_0x180003605: // orphan
         rax = rip + str._IsoZombie.getOnlineID // 0x1800d8248 // "\u65b9\u6cd5 IsoZombie.getOnlineID"
         
         goto loc_0x180003611;
    loc_0x180003611: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003603(x)
         v = qword [0x180100fc0] - 0 // [0x180100fc0:8]=-1
         if (v) 
         goto loc_0x18000361b;
    loc_0x18000361b: // orphan
         rax = rip + str._IsoZombie.getHealth // 0x1800d8268 // "\u65b9\u6cd5 IsoZombie.getHealth"
         
         goto loc_0x180003627;
    loc_0x180003627: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003619(x)
         v = qword [0x1801010b0] - 0 // [0x1801010b0:8]=-1
         if (v) 
         goto loc_0x180003631;
    loc_0x180003631: // orphan
         rax = rip + str._System.identityHashCode // 0x1800d8288 // "\u65b9\u6cd5 System.identityHashCode"
         
         goto loc_0x18000363d;
    loc_0x18000363d: // orphan
         // CODE XREF from fcn.180001df0 @ 0x18000362f(x)
         v = qword [0x180100fd0] - 0 // [0x180100fd0:8]=0
         if (v) 
         goto loc_0x180003647;
    loc_0x180003647: // orphan
         rax = rip + str._IsoZombie.isCrawling // 0x1800d82a8 // "\u65b9\u6cd5 IsoZombie.isCrawling"
         
         goto loc_0x180003650;
    loc_0x180003650: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003645(x)
         v = qword [0x180100fd8] - 0 // [0x180100fd8:8]=-1
         if (v) 
         goto loc_0x18000365a;
    loc_0x18000365a: // orphan
         rax = rip + str._IsoZombie.isProne // 0x1800d82c8 // "\u65b9\u6cd5 IsoZombie.isProne"
         
         goto loc_0x180003663;
    loc_0x180003663: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003658(x)
         v = qword [0x180100fe0] - 0 // [0x180100fe0:8]=-1
         if (v) 
         goto loc_0x18000366d;
    loc_0x18000366d: // orphan
         rax = rip + str._IsoGameCharacter.isFalling // 0x1800d82e8 // "\u65b9\u6cd5 IsoGameCharacter.isFalling"
         
         goto loc_0x180003676;
    loc_0x180003676: // orphan
         // CODE XREF from fcn.180001df0 @ 0x18000366b(x)
         v = qword [0x180100fe8] - 0 // [0x180100fe8:8]=-1
         if (v) 
         goto loc_0x180003680;
    loc_0x180003680: // orphan
         rax = rip + str._IsoGameCharacter.isKnockedDown // 0x1800d8310 // "\u65b9\u6cd5 IsoGameCharacter.isKnockedDown"
         
         goto loc_0x180003689;
    loc_0x180003689: // orphan
         // CODE XREF from fcn.180001df0 @ 0x18000367e(x)
         v = qword [0x180101000] - 0 // [0x180101000:8]=-1
         if (v) 
         goto loc_0x180003693;
    loc_0x180003693: // orphan
         rax = rip + str._IsoUtils.XToScreenExact // 0x1800d8338 // "\u65b9\u6cd5 IsoUtils.XToScreenExact"
         
         goto loc_0x18000369c;
    loc_0x18000369c: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003691(x)
         v = qword [0x180101008] - 0 // [0x180101008:8]=-1
         if (v) 
         goto loc_0x1800036a6;
    loc_0x1800036a6: // orphan
         rax = rip + str._IsoUtils.YToScreenExact // 0x1800d8358 // "\u65b9\u6cd5 IsoUtils.YToScreenExact"
         
         goto loc_0x1800036af;
    loc_0x1800036af: // orphan
         // CODE XREF from fcn.180001df0 @ 0x1800036a4(x)
         v = qword [0x180101010] - 0 // [0x180101010:8]=-1
         rax = rip + str._Core.getInstance // 0x1800d8378 // "\u65b9\u6cd5 Core.getInstance"
         rcx = rip + str._Core.getZoom // 0x1800d8390 // "\u65b9\u6cd5 Core.getZoom"

    loc_0x1800036c5: // orphan
         // CODE XREF from fcn.180001df0 @ 0x18000379a(x)
         if (!zf) rax = rcx

    loc_0x1800036c9: // orphan
         // XREFS(33)
         rsi = qword [var_30h]
         rdi = qword [var_38h]
         qword [0x1800ff968] = rax // [0x1800ff968:8]=0x1800d73d0 str._ClassLoader
         al = 0
         rsp += 0x20
         rbx = pop ()
         return

    loc_0x1800036e2: // orphan
         // XREFS(21)
         v = qword [0x180100da8] - 0 // [0x180100da8:8]=0
         if (v) 
         goto loc_0x1800036ec;
    loc_0x1800036ec: // orphan
         // CODE XREF from fcn.180001df0 @ 0x18000219a(x)
         rax = rip + str._GameServer // 0x1800d77c0 // "\u7c7b GameServer"
         
         goto loc_0x1800036f5;
    loc_0x1800036f5: // orphan
         // CODE XREF from fcn.180001df0 @ 0x1800036ea(x)
         v = r10 & r10
         if (v) 
         goto loc_0x1800036fa;
    loc_0x1800036fa: // orphan
         rax = rip + str._IsoPlayer // 0x1800d77d0 // "\u7c7b IsoPlayer"
         
         goto loc_0x180003703;
    loc_0x180003703: // orphan
         // CODE XREF from fcn.180001df0 @ 0x1800036f8(x)
         v = rdi & rdi
         if (v) 
         goto loc_0x180003708;
    loc_0x180003708: // orphan
         rax = rip + str._IsoAnimal // 0x1800d77e0 // "\u7c7b IsoAnimal"
         
         goto loc_0x180003711;
    loc_0x180003711: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003706(x)
         v = qword [0x180100dc0] - 0 // [0x180100dc0:8]=0
         if (v) 
         goto loc_0x18000371b;
    loc_0x18000371b: // orphan
         rax = rip + str._BaseVehicle // 0x1800d77f0 // "\u7c7b BaseVehicle"
         
         goto loc_0x180003724;
    loc_0x180003724: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003719(x)
         v = rsi & rsi
         if (v) 
         goto loc_0x180003729;
    loc_0x180003729: // orphan
         rax = rip + str._IsoWorld // 0x1800d7800 // "\u7c7b IsoWorld"
         
         goto loc_0x180003732;
    loc_0x180003732: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003727(x)
         v = r11 & r11
         if (v) 
         goto loc_0x180003737;
    loc_0x180003737: // orphan
         rax = rip + str._IsoCell // 0x1800d7810 // "\u7c7b IsoCell"
         
         goto loc_0x180003740;
    loc_0x180003740: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003735(x)
         v = r9 & r9
         if (v) 
         goto loc_0x180003745;
    loc_0x180003745: // orphan
         rax = rip + str._Safety  // 0x1800d7820 // "\u7c7b Safety"
         
         goto loc_0x180003751;
    loc_0x180003751: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003743(x)
         v = r8 & r8
         if (v) 
         goto loc_0x180003756;
    loc_0x180003756: // orphan
         rax = rip + str._CombatManager // 0x1800d7830 // "\u7c7b CombatManager"
         
         goto loc_0x180003762;
    loc_0x180003762: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003754(x)
         v = rcx & rcx
         if (v) 
         goto loc_0x180003767;
    loc_0x180003767: // orphan
         rax = rip + str._ArrayList // 0x1800d7848 // "\u7c7b ArrayList"
         
         goto loc_0x180003773;
    loc_0x180003773: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003765(x)
         v = rax & rax
         if (v) 
         goto loc_0x180003778;
    loc_0x180003778: // orphan
         rax = rip + str._IsoMovingObject // 0x1800d7858 // "\u7c7b IsoMovingObject"
         
         goto loc_0x180003784;
    loc_0x180003784: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180003776(x)
         v = qword [0x180100e00] - 0 // [0x180100e00:8]=0
         rax = rip + str._IsoUtils // 0x1800d7870 // "\u7c7b IsoUtils"
         rcx = rip + str._Core    // 0x1800d7880 // "\u7c7b Core"
         
         goto loc_0x18000379f;
    loc_0x18000379f: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180002154(x)
         rax = rip + str._GameClient // 0x1800d77b0 // "\u7c7b GameClient"
         
         goto loc_0x1800037ab;
    loc_0x1800037ab: // orphan
         // CODE XREFS from fcn.180001df0 @ 0x180001efa(x), 0x180001f08(x)
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x720] ()   // 1824 // 0x720(0x0, 0x0, 0x0, 0x0)
         v = al & al
         if (!v) 
         goto loc_0x1800037bb;
    loc_0x1800037bb: // orphan
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x88] ()    // 136 // 0x88(0x0, 0x0, 0x0, 0x0)

    loc_0x1800037c7: // orphan
         // CODE XREF from fcn.180001df0 @ 0x1800037b9(x)
         rax = rip + str.JVM_system_class_loader // 0x1800d7458 // "JVM system class loader"
         
         goto loc_0x1800037d3;
    loc_0x1800037d3: // orphan
         // CODE XREF from fcn.180001df0 @ 0x180001e39(x)
         rax = qword [rbx]
         qword [rax + 0x88] ()    // 136 // 0x88(0x0, 0x0, 0x0, 0x0)

}

