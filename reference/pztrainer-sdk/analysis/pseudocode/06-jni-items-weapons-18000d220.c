// callconv: rax ms (rcx, rdx, r8, r9, stack);
void fcn.18000d220 (int64_t arg1) {
        // XREFS: CALL 0x1800104ca  CALL 0x1800113ee  CALL 0x18001148d
        // XREFS: CALL 0x18001157d  CALL 0x1800118ec  CALL 0x180069f3c
        push (rbx)
        rsp -= 0x20
        v = byte [0x1801014b0] - 0 // [0x1801014b0:1]=0
        rbx = rcx    // arg1
        if (!v) goto loc_0x18000d23a // likely
        return rax;
    loc_0x18000d23a:
        // CODE XREF from fcn.18000d220 @ 0x18000d230(x)
        rdx = rip + str.zombie_network_GameClient // 0x1800d7470 // "zombie/network/GameClient"
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_network_GameServer // 0x1800d7490 // "zombie/network/GameServer"
        qword [0x1801014b8] = rax // [0x1801014b8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_characters_IsoPlayer // 0x1800d74b0 // "zombie/characters/IsoPlayer"
        qword [0x1801014c0] = rax // [0x1801014c0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_scripting_ScriptManager // 0x1800de5e8 // "zombie/scripting/ScriptManager"
        qword [0x1801014c8] = rax // [0x1801014c8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.java_util_ArrayList // 0x1800d7568 // "java/util/ArrayList"
        qword [0x1801014d0] = rax // [0x1801014d0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_scripting_objects_Item // 0x1800de608 // "zombie/scripting/objects/Item"
        qword [0x1801014d8] = rax // [0x1801014d8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_core_textures_Texture // 0x1800de628 // "zombie/core/textures/Texture"
        qword [0x1801014e0] = rax // [0x1801014e0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_inventory_InventoryItemFactory // 0x1800de648 // "zombie/inventory/InventoryItemFactory"
        qword [0x1801014e8] = rax // [0x1801014e8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_network_packets_ItemTransactionPacket // 0x1800de670 // "zombie/network/packets/ItemTransactionPacket"
        qword [0x1801014f0] = rax // [0x1801014f0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_core_TransactionManager // 0x1800de6a0 // "zombie/core/TransactionManager"
        qword [0x1801014f8] = rax // [0x1801014f8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_iso_IsoDirections // 0x1800de6c0 // "zombie/iso/IsoDirections"
        qword [0x180101500] = rax // [0x180101500:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_inventory_InventoryItem // 0x1800de6e0 // "zombie/inventory/InventoryItem"
        qword [0x180101508] = rax // [0x180101508:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_inventory_ItemContainer // 0x1800d7518 // "zombie/inventory/ItemContainer"
        qword [0x180101510] = rax // [0x180101510:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_inventory_types_InventoryContainer // 0x1800de700 // "zombie/inventory/types/InventoryContainer"
        qword [0x180101518] = rax // [0x180101518:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_inventory_types_Food // 0x1800de730 // "zombie/inventory/types/Food"
        qword [0x180101520] = rax // [0x180101520:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_inventory_types_HandWeapon // 0x1800de350 // "zombie/inventory/types/HandWeapon"
        qword [0x180101528] = rax // [0x180101528:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_inventory_types_WeaponPart // 0x1800de750 // "zombie/inventory/types/WeaponPart"
        qword [0x180101530] = rax // [0x180101530:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_scripting_objects_AmmoType // 0x1800de778 // "zombie/scripting/objects/AmmoType"
        qword [0x180101538] = rax // [0x180101538:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_network_PacketTypes_PacketType // 0x1800de7a0 // "zombie/network/PacketTypes$PacketType"
        qword [0x180101540] = rax // [0x180101540:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = qword [0x1801014b8] // [0x1801014b8:8]=0
        qword [0x180101548] = rax // [0x180101548:8]=0
        v = rdx & rdx
        if (!v) goto loc_0x18000ddf7 // likely
        goto loc_0x18000d3e9;
    loc_0x18000ddf7:
        // XREFS: CODE 0x18000d3e3  CODE 0x18000d3f1  CODE 0x18000d3ff
        // XREFS: CODE 0x18000d40d  CODE 0x18000d41b  CODE 0x18000d429
        // XREFS: CODE 0x18000d437  CODE 0x18000d445  CODE 0x18000d453
        // XREFS: CODE 0x18000d461  CODE 0x18000d46f  CODE 0x18000d47d
        // XREFS: CODE 0x18000d48b  CODE 0x18000d499  CODE 0x18000d4a7
        // XREFS: CODE 0x18000d4b5  CODE 0x18000d4c3  CODE 0x18000d4d1
        // XREFS: CODE 0x18000d4da
        al = 0
        rsp += 0x20
        rbx = pop ()
        return
        goto loc_0x18000d3f7;
    loc_0x18000d232: // orphan
         al = 1
         rsp += 0x20
         rbx = pop ()
         return

    loc_0x18000d3e9: // orphan
         v = qword [0x1801014c0] - 0 // [0x1801014c0:8]=0
         if (!v) 
         goto loc_0x18000d3f7;
    loc_0x18000d3f7: // orphan
         v = qword [0x1801014c8] - 0 // [0x1801014c8:8]=0
         if (!v) 
         goto loc_0x18000d405;
    loc_0x18000d405: // orphan
         v = qword [0x1801014d0] - 0 // [0x1801014d0:8]=0
         if (!v) 
         goto loc_0x18000d413;
    loc_0x18000d413: // orphan
         v = qword [0x1801014d8] - 0 // [0x1801014d8:8]=0
         if (!v) 
         goto loc_0x18000d421;
    loc_0x18000d421: // orphan
         v = qword [0x1801014e0] - 0 // [0x1801014e0:8]=0
         if (!v) 
         goto loc_0x18000d42f;
    loc_0x18000d42f: // orphan
         v = qword [0x1801014e8] - 0 // [0x1801014e8:8]=0
         if (!v) 
         goto loc_0x18000d43d;
    loc_0x18000d43d: // orphan
         v = qword [0x1801014f0] - 0 // [0x1801014f0:8]=0
         if (!v) 
         goto loc_0x18000d44b;
    loc_0x18000d44b: // orphan
         v = qword [0x1801014f8] - 0 // [0x1801014f8:8]=0
         if (!v) 
         goto loc_0x18000d459;
    loc_0x18000d459: // orphan
         v = qword [0x180101500] - 0 // [0x180101500:8]=0
         if (!v) 
         goto loc_0x18000d467;
    loc_0x18000d467: // orphan
         v = qword [0x180101508] - 0 // [0x180101508:8]=0
         if (!v) 
         goto loc_0x18000d475;
    loc_0x18000d475: // orphan
         v = qword [0x180101510] - 0 // [0x180101510:8]=0
         if (!v) 
         goto loc_0x18000d483;
    loc_0x18000d483: // orphan
         v = qword [0x180101518] - 0 // [0x180101518:8]=0
         if (!v) 
         goto loc_0x18000d491;
    loc_0x18000d491: // orphan
         v = qword [0x180101520] - 0 // [0x180101520:8]=0
         if (!v) 
         goto loc_0x18000d49f;
    loc_0x18000d49f: // orphan
         v = qword [0x180101528] - 0 // [0x180101528:8]=0
         if (!v) 
         goto loc_0x18000d4ad;
    loc_0x18000d4ad: // orphan
         v = qword [0x180101530] - 0 // [0x180101530:8]=0
         if (!v) 
         goto loc_0x18000d4bb;
    loc_0x18000d4bb: // orphan
         v = qword [0x180101538] - 0 // [0x180101538:8]=0
         if (!v) 
         goto loc_0x18000d4c9;
    loc_0x18000d4c9: // orphan
         v = qword [0x180101540] - 0 // [0x180101540:8]=0
         if (!v) 
         goto loc_0x18000d4d7;
    loc_0x18000d4d7: // orphan
         v = rax & rax
         if (!v) 
         goto loc_0x18000d4e0;
    loc_0x18000d4e0: // orphan
         rax = qword [rbx]
         r9 = rip + 0xca3a2       // "Z" // 0x1800d788c
         r8 = rip + str.client    // 0x1800d7890 // "client"
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014c0] // [0x1801014c0:8]=0
         r9 = rip + 0xca384       // "Z" // 0x1800d788c
         qword [0x180101550] = rax // [0x180101550:8]=0
         r8 = rip + str.server    // 0x1800d7898 // "server"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101548] // [0x180101548:8]=0
         r9 = rip + str.Lzombie_network_PacketTypes_PacketType_ // 0x1800de7c8 // "Lzombie/network/PacketTypes$PacketType;"
         qword [0x180101558] = rax // [0x180101558:8]=0
         r8 = rip + str.ItemTransaction // 0x1800de7f0 // "ItemTransaction"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101508] // [0x180101508:8]=0
         r9 = rip + str.Lzombie_iso_IsoDirections_ // 0x1800de800 // "Lzombie/iso/IsoDirections;"
         qword [0x180101560] = rax // [0x180101560:8]=0
         r8 = rip + 0xd12b6       // "N" // 0x1800de81c
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014d0] // [0x1801014d0:8]=0
         r9 = rip + str.Lzombie_scripting_ScriptManager_ // 0x1800de820 // "Lzombie/scripting/ScriptManager;"
         qword [0x180101568] = rax // [0x180101568:8]=0
         r8 = rip + str.instance  // 0x1800d78b8 // "instance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014c8] // [0x1801014c8:8]=0
         r9 = rip + str.__Lzombie_characters_IsoPlayer_ // 0x1800d78c8 // "()Lzombie/characters/IsoPlayer;"
         qword [0x180101570] = rax // [0x180101570:8]=0
         r8 = rip + str.getInstance // 0x1800d78e8 // "getInstance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014d0] // [0x1801014d0:8]=0
         r9 = rip + str.__Ljava_util_ArrayList_ // 0x1800d7918 // "()Ljava/util/ArrayList;"
         qword [0x180101578] = rax // [0x180101578:8]=0
         r8 = rip + str.getAllItems // 0x1800de848 // "getAllItems"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014d8] // [0x1801014d8:8]=0
         r9 = rip + 0xca37c       // "()I" // 0x1800d7974
         qword [0x180101580] = rax // [0x180101580:8]=0
         r8 = rip + str.size      // 0x1800d7978 // "size"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014d8] // [0x1801014d8:8]=0
         r9 = rip + str._I_Ljava_lang_Object_ // 0x1800d7980 // "(I)Ljava/lang/Object;"
         qword [0x180101588] = rax // [0x180101588:8]=0
         r8 = rip + 0xca36a       // "get" // 0x1800d7998
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014e0] // [0x1801014e0:8]=0
         r9 = rip + 0xca37c       // "()Z" // 0x1800d79c4
         qword [0x180101590] = rax // [0x180101590:8]=0
         r8 = rip + str.isHidden  // 0x1800de858 // "isHidden"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014e0] // [0x1801014e0:8]=0
         r9 = rip + 0xca354       // "()Z" // 0x1800d79c4
         qword [0x180101598] = rax // [0x180101598:8]=0
         r8 = rip + str.getObsolete // 0x1800de868 // "getObsolete"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014e0] // [0x1801014e0:8]=0
         r9 = rip + str.__Ljava_lang_String_ // 0x1800d7b40 // "()Ljava/lang/String;"
         qword [0x1801015a0] = rax // [0x1801015a0:8]=0
         r8 = rip + str.getFullName // 0x1800d7c08 // "getFullName"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014e0] // [0x1801014e0:8]=0
         r9 = rip + str.__Ljava_lang_String_ // 0x1800d7b40 // "()Ljava/lang/String;"
         qword [0x1801015a8] = rax // [0x1801015a8:8]=0
         r8 = rip + str.getDisplayName // 0x1800de878 // "getDisplayName"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014e0] // [0x1801014e0:8]=0
         r9 = rip + str.__Ljava_lang_String_ // 0x1800d7b40 // "()Ljava/lang/String;"
         qword [0x1801015b0] = rax // [0x1801015b0:8]=0
         r8 = rip + str.getDisplayCategory // 0x1800de888 // "getDisplayCategory"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014e0] // [0x1801014e0:8]=0
         r9 = rip + str.__Lzombie_core_textures_Texture_ // 0x1800de8a0 // "()Lzombie/core/textures/Texture;"
         qword [0x1801015b8] = rax // [0x1801015b8:8]=0
         r8 = rip + str.getNormalTexture // 0x1800de8c8 // "getNormalTexture"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014f0] // [0x1801014f0:8]=0
         r9 = rip + str._Ljava_lang_String__Lzombie_inventory_InventoryItem_ // 0x1800de8e0 // "(Ljava/lang/String;)Lzombie/inventory/InventoryItem;"
         qword [0x1801015c0] = rax // [0x1801015c0:8]=0
         r8 = rip + str.CreateItem // 0x1800de918 // "CreateItem"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101510] // [0x180101510:8]=0
         r9 = rip + str.__Lzombie_core_skinnedmodel_visual_ItemVisual_ // 0x1800de928 // "()Lzombie/core/skinnedmodel/visual/ItemVisual;"
         qword [0x1801015c8] = rax // [0x1801015c8:8]=0
         r8 = rip + str.getVisual // 0x1800de958 // "getVisual"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101510] // [0x180101510:8]=0
         r9 = rip + 0xca23c       // "()Z" // 0x1800d79c4
         qword [0x1801015d0] = rax // [0x1801015d0:8]=0
         r8 = rip + str.isFavorite // 0x1800de968 // "isFavorite"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101510] // [0x180101510:8]=0
         r9 = rip + str.__Ljava_lang_String_ // 0x1800d7b40 // "()Ljava/lang/String;"
         qword [0x1801015d8] = rax // [0x1801015d8:8]=0
         r8 = rip + str.getFullType // 0x1800de978 // "getFullType"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014c8] // [0x1801014c8:8]=0
         r9 = rip + str._Lzombie_inventory_InventoryItem__Z // 0x1800de988 // "(Lzombie/inventory/InventoryItem;)Z"
         qword [0x1801015e0] = rax // [0x1801015e0:8]=0
         r8 = rip + str.isEquipped // 0x1800de9b0 // "isEquipped"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101500] // [0x180101500:8]=0
         r9 = rip + str._Lzombie_core_Transaction__V // 0x1800de9c0 // "(Lzombie/core/Transaction;)V"
         qword [0x1801015e8] = rax // [0x1801015e8:8]=0
         r8 = rip + 0xd11d2       // "add" // 0x1800de9e0
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101518] // [0x180101518:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         qword [0x1801015f0] = rax // [0x1801015f0:8]=0
         r8 = rip + str.setDrawDirty // 0x1800de9f0 // "setDrawDirty"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014e8] // [0x1801014e8:8]=0
         r9 = rip + 0xca124       // "()I" // 0x1800d7974
         qword [0x1801015f8] = rax // [0x1801015f8:8]=0
         r8 = rip + str.getID     // 0x1800d7a0c // "getID"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x180101600] = rax // [0x180101600:8]=0
         r9 = rip + 0xca178       // "()F" // 0x1800d79f0
         rax = qword [rbx]
         rdx = qword [0x1801014e8] // [0x1801014e8:8]=0
         r8 = rip + str.getXStart // 0x1800dea00 // "getXStart"
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014e8] // [0x1801014e8:8]=0
         r9 = rip + 0xca150       // "()F" // 0x1800d79f0
         qword [0x180101608] = rax // [0x180101608:8]=0
         r8 = rip + str.getYStart // 0x1800dea10 // "getYStart"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014e8] // [0x1801014e8:8]=0
         r9 = rip + 0xca128       // "()F" // 0x1800d79f0
         qword [0x180101610] = rax // [0x180101610:8]=0
         r8 = rip + str.getXEnd   // 0x1800dea20 // "getXEnd"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014e8] // [0x1801014e8:8]=0
         r9 = rip + 0xca100       // "()F" // 0x1800d79f0
         qword [0x180101618] = rax // [0x180101618:8]=0
         r8 = rip + str.getYEnd   // 0x1800dea28 // "getYEnd"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014e8] // [0x1801014e8:8]=0
         r9 = rip + 0xca05c       // "()I" // 0x1800d7974
         qword [0x180101620] = rax // [0x180101620:8]=0
         r8 = rip + str.getWidth  // 0x1800dea30 // "getWidth"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x1801014e8] // [0x1801014e8:8]=0
         r9 = rip + 0xca034       // "()I" // 0x1800d7974
         qword [0x180101628] = rax // [0x180101628:8]=0
         r8 = rip + str.getHeight // 0x1800dea40 // "getHeight"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101528] // [0x180101528:8]=0
         r9 = rip + 0xca088       // "()F" // 0x1800d79f0
         qword [0x180101630] = rax // [0x180101630:8]=0
         r8 = rip + str.getBaseHunger // 0x1800dea50 // "getBaseHunger"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101530] // [0x180101530:8]=0
         r9 = rip + str.__Lzombie_scripting_objects_AmmoType_ // 0x1800dea60 // "()Lzombie/scripting/objects/AmmoType;"
         qword [0x180101638] = rax // [0x180101638:8]=0
         r8 = rip + str.getAmmoType // 0x1800dea88 // "getAmmoType"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101540] // [0x180101540:8]=0
         r9 = rip + str.__Ljava_lang_String_ // 0x1800d7b40 // "()Ljava/lang/String;"
         qword [0x180101640] = rax // [0x180101640:8]=0
         r8 = rip + str.getItemKey // 0x1800dea98 // "getItemKey"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101530] // [0x180101530:8]=0
         r9 = rip + str.__Ljava_lang_String_ // 0x1800d7b40 // "()Ljava/lang/String;"
         qword [0x180101648] = rax // [0x180101648:8]=0
         r8 = rip + str.getMagazineType // 0x1800deaa8 // "getMagazineType"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101530] // [0x180101530:8]=0
         r9 = rip + 0xc9fbc       // "()Z" // 0x1800d79c4
         qword [0x180101650] = rax // [0x180101650:8]=0
         r8 = rip + str.usesExternalMagazine // 0x1800deab8 // "usesExternalMagazine"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101538] // [0x180101538:8]=0
         r9 = rip + str.__Ljava_util_List_ // 0x1800dead0 // "()Ljava/util/List;"
         qword [0x180101658] = rax // [0x180101658:8]=0
         r8 = rip + str.getMountOn // 0x1800deae8 // "getMountOn"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101530] // [0x180101530:8]=0
         r9 = rip + 0xc9f1c       // "()I" // 0x1800d7974
         qword [0x180101660] = rax // [0x180101660:8]=0
         r8 = rip + str.getExplosionRange // 0x1800deaf8 // "getExplosionRange"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101530] // [0x180101530:8]=0
         r9 = rip + 0xc9ef4       // "()I" // 0x1800d7974
         qword [0x180101668] = rax // [0x180101668:8]=0
         r8 = rip + str.getExplosionPower // 0x1800deb10 // "getExplosionPower"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101530] // [0x180101530:8]=0
         r9 = rip + 0xc9ecc       // "()I" // 0x1800d7974
         qword [0x180101670] = rax // [0x180101670:8]=0
         r8 = rip + str.getFireRange // 0x1800deb28 // "getFireRange"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101530] // [0x180101530:8]=0
         r9 = rip + 0xc9ea4       // "()I" // 0x1800d7974
         qword [0x180101678] = rax // [0x180101678:8]=0
         r8 = rip + str.getFireStartingEnergy // 0x1800deb38 // "getFireStartingEnergy"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101530] // [0x180101530:8]=0
         r9 = rip + 0xc9e7c       // "()I" // 0x1800d7974
         qword [0x180101680] = rax // [0x180101680:8]=0
         r8 = rip + str.getFireStartingChance // 0x1800deb50 // "getFireStartingChance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101530] // [0x180101530:8]=0
         r9 = rip + 0xc9e54       // "()I" // 0x1800d7974
         qword [0x180101688] = rax // [0x180101688:8]=0
         r8 = rip + str.getSmokeRange // 0x1800deb68 // "getSmokeRange"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101530] // [0x180101530:8]=0
         r9 = rip + 0xc9e2c       // "()I" // 0x1800d7974
         qword [0x180101690] = rax // [0x180101690:8]=0
         r8 = rip + str.getNoiseRange // 0x1800deb78 // "getNoiseRange"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101530] // [0x180101530:8]=0
         r9 = rip + 0xc9e04       // "()I" // 0x1800d7974
         qword [0x180101698] = rax // [0x180101698:8]=0
         r8 = rip + str.getSensorRange // 0x1800deb88 // "getSensorRange"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x1801016a0] = rax // [0x1801016a0:8]=0
         rcx = rbx
         rax = qword [rbx]
         qword [rax + 0x720] ()   // 1824 // 0x720(0x0, 0x0, 0x0, 0x0)
         v = al & al
         if (!v) 
         goto loc_0x18000dba1;
    loc_0x18000dba1: // orphan
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x88] ()    // 136 // 0x88(0x0, 0x0, 0x0, 0x0)

    loc_0x18000dbad: // orphan
         // XREFS(43)
         al = 0
         byte [0x1801014b0] = al  // [0x1801014b0:1]=0
         rsp += 0x20
         rbx = pop ()
         return

    loc_0x18000dbbb: // orphan
         // CODE XREF from fcn.18000d220 @ 0x18000db9f(x)
         v = qword [0x180101550] - 0 // [0x180101550:8]=-1
         if (!v) 
         goto loc_0x18000dbc5;
    loc_0x18000dbc5: // orphan
         v = qword [0x180101558] - 0 // [0x180101558:8]=-1
         if (!v) 
         goto loc_0x18000dbcf;
    loc_0x18000dbcf: // orphan
         v = qword [0x180101560] - 0 // [0x180101560:8]=-1
         if (!v) 
         goto loc_0x18000dbd9;
    loc_0x18000dbd9: // orphan
         v = qword [0x180101568] - 0 // [0x180101568:8]=-1
         if (!v) 
         goto loc_0x18000dbe3;
    loc_0x18000dbe3: // orphan
         v = qword [0x180101570] - 0 // [0x180101570:8]=-1
         if (!v) 
         goto loc_0x18000dbed;
    loc_0x18000dbed: // orphan
         v = qword [0x180101578] - 0 // [0x180101578:8]=-1
         if (!v) 
         goto loc_0x18000dbf7;
    loc_0x18000dbf7: // orphan
         v = qword [0x180101580] - 0 // [0x180101580:8]=-1
         if (!v) 
         goto loc_0x18000dc01;
    loc_0x18000dc01: // orphan
         v = qword [0x180101588] - 0 // [0x180101588:8]=-1
         if (!v) 
         goto loc_0x18000dc0b;
    loc_0x18000dc0b: // orphan
         v = qword [0x180101590] - 0 // [0x180101590:8]=-1
         if (!v) 
         goto loc_0x18000dc15;
    loc_0x18000dc15: // orphan
         v = qword [0x180101598] - 0 // [0x180101598:8]=-1
         if (!v) 
         goto loc_0x18000dc1f;
    loc_0x18000dc1f: // orphan
         v = qword [0x1801015a0] - 0 // [0x1801015a0:8]=-1
         if (!v) 
         goto loc_0x18000dc29;
    loc_0x18000dc29: // orphan
         v = qword [0x1801015a8] - 0 // [0x1801015a8:8]=-1
         if (!v) 
         goto loc_0x18000dc37;
    loc_0x18000dc37: // orphan
         v = qword [0x1801015b0] - 0 // [0x1801015b0:8]=-1
         if (!v) 
         goto loc_0x18000dc45;
    loc_0x18000dc45: // orphan
         v = qword [0x1801015b8] - 0 // [0x1801015b8:8]=-1
         if (!v) 
         goto loc_0x18000dc53;
    loc_0x18000dc53: // orphan
         v = qword [0x1801015c0] - 0 // [0x1801015c0:8]=-1
         if (!v) 
         goto loc_0x18000dc61;
    loc_0x18000dc61: // orphan
         v = qword [0x1801015c8] - 0 // [0x1801015c8:8]=-1
         if (!v) 
         goto loc_0x18000dc6f;
    loc_0x18000dc6f: // orphan
         v = qword [0x1801015d0] - 0 // [0x1801015d0:8]=-1
         if (!v) 
         goto loc_0x18000dc7d;
    loc_0x18000dc7d: // orphan
         v = qword [0x1801015d8] - 0 // [0x1801015d8:8]=-1
         if (!v) 
         goto loc_0x18000dc8b;
    loc_0x18000dc8b: // orphan
         v = qword [0x1801015e0] - 0 // [0x1801015e0:8]=-1
         if (!v) 
         goto loc_0x18000dc99;
    loc_0x18000dc99: // orphan
         v = qword [0x1801015e8] - 0 // [0x1801015e8:8]=-1
         if (!v) 
         goto loc_0x18000dca7;
    loc_0x18000dca7: // orphan
         v = qword [0x1801015f0] - 0 // [0x1801015f0:8]=-1
         if (!v) 
         goto loc_0x18000dcb5;
    loc_0x18000dcb5: // orphan
         v = qword [0x1801015f8] - 0 // [0x1801015f8:8]=-1
         if (!v) 
         goto loc_0x18000dcc3;
    loc_0x18000dcc3: // orphan
         v = qword [0x180101600] - 0 // [0x180101600:8]=-1
         if (!v) 
         goto loc_0x18000dcd1;
    loc_0x18000dcd1: // orphan
         v = qword [0x180101608] - 0 // [0x180101608:8]=-1
         if (!v) 
         goto loc_0x18000dcdf;
    loc_0x18000dcdf: // orphan
         v = qword [0x180101610] - 0 // [0x180101610:8]=-1
         if (!v) 
         goto loc_0x18000dced;
    loc_0x18000dced: // orphan
         v = qword [0x180101618] - 0 // [0x180101618:8]=-1
         if (!v) 
         goto loc_0x18000dcfb;
    loc_0x18000dcfb: // orphan
         v = qword [0x180101620] - 0 // [0x180101620:8]=-1
         if (!v) 
         goto loc_0x18000dd09;
    loc_0x18000dd09: // orphan
         v = qword [0x180101628] - 0 // [0x180101628:8]=-1
         if (!v) 
         goto loc_0x18000dd17;
    loc_0x18000dd17: // orphan
         v = qword [0x180101630] - 0 // [0x180101630:8]=-1
         if (!v) 
         goto loc_0x18000dd25;
    loc_0x18000dd25: // orphan
         v = qword [0x180101638] - 0 // [0x180101638:8]=-1
         if (!v) 
         goto loc_0x18000dd33;
    loc_0x18000dd33: // orphan
         v = qword [0x180101640] - 0 // [0x180101640:8]=-1
         if (!v) 
         goto loc_0x18000dd41;
    loc_0x18000dd41: // orphan
         v = qword [0x180101648] - 0 // [0x180101648:8]=-1
         if (!v) 
         goto loc_0x18000dd4f;
    loc_0x18000dd4f: // orphan
         v = qword [0x180101650] - 0 // [0x180101650:8]=-1
         if (!v) 
         goto loc_0x18000dd5d;
    loc_0x18000dd5d: // orphan
         v = qword [0x180101658] - 0 // [0x180101658:8]=-1
         if (!v) 
         goto loc_0x18000dd6b;
    loc_0x18000dd6b: // orphan
         v = qword [0x180101660] - 0 // [0x180101660:8]=-1
         if (!v) 
         goto loc_0x18000dd79;
    loc_0x18000dd79: // orphan
         v = qword [0x180101668] - 0 // [0x180101668:8]=-1
         if (!v) 
         goto loc_0x18000dd87;
    loc_0x18000dd87: // orphan
         v = qword [0x180101670] - 0 // [0x180101670:8]=-1
         if (!v) 
         goto loc_0x18000dd95;
    loc_0x18000dd95: // orphan
         v = qword [0x180101678] - 0 // [0x180101678:8]=-1
         if (!v) 
         goto loc_0x18000dda3;
    loc_0x18000dda3: // orphan
         v = qword [0x180101680] - 0 // [0x180101680:8]=-1
         if (!v) 
         goto loc_0x18000ddb1;
    loc_0x18000ddb1: // orphan
         v = qword [0x180101688] - 0 // [0x180101688:8]=-1
         if (!v) 
         goto loc_0x18000ddbf;
    loc_0x18000ddbf: // orphan
         v = qword [0x180101690] - 0 // [0x180101690:8]=-1
         if (!v) 
         goto loc_0x18000ddcd;
    loc_0x18000ddcd: // orphan
         v = qword [0x180101698] - 0 // [0x180101698:8]=-1
         if (!v) 
         goto loc_0x18000dddb;
    loc_0x18000dddb: // orphan
         v = qword [0x1801016a0] - 0 // [0x1801016a0:8]=-1
         if (!v) 
         return rax;
    loc_0x18000dde9: // orphan
         al = 1
         byte [0x1801014b0] = al  // [0x1801014b0:1]=0
         rsp += 0x20
         rbx = pop ()
         return

}

