/*
 * Semantic name: initializeItemWeaponBridge
 * Address: 0x18000d220
 * Module: items
 * Confidence: medium
 * Summary: Caches item, weapon, inventory, and transaction JNI methods.
 * Ghidra function: initializeItemWeaponBridge
 * Callers:
 *   - FUN_180010480 @ 0x180010480
 *   - FUN_1800113d0 @ 0x1800113d0
 *   - FUN_180011650 @ 0x180011650
 *   - FUN_180069ed0 @ 0x180069ed0
 * Callees:
 *   - findGlobalJniClass @ 0x180009cc0
 * Referenced strings:
 *   - zombie/network/GameClient
 *   - zombie/network/GameServer
 *   - zombie/characters/IsoPlayer
 *   - zombie/scripting/ScriptManager
 *   - java/util/ArrayList
 *   - zombie/scripting/objects/Item
 *   - zombie/core/textures/Texture
 *   - zombie/inventory/InventoryItemFactory
 *   - zombie/network/packets/ItemTransactionPacket
 *   - zombie/core/TransactionManager
 *   - zombie/iso/IsoDirections
 *   - zombie/inventory/InventoryItem
 *   - zombie/inventory/ItemContainer
 *   - zombie/inventory/types/InventoryContainer
 *   - zombie/inventory/types/Food
 *   - zombie/inventory/types/HandWeapon
 *   - zombie/inventory/types/WeaponPart
 *   - zombie/scripting/objects/AmmoType
 *   - zombie/network/PacketTypes$PacketType
 *   - client
 *   - server
 *   - Lzombie/network/PacketTypes$PacketType;
 *   - ItemTransaction
 *   - Lzombie/iso/IsoDirections;
 *   - Lzombie/scripting/ScriptManager;
 *   - instance
 *   - ()Lzombie/characters/IsoPlayer;
 *   - getInstance
 *   - ()Ljava/util/ArrayList;
 *   - getAllItems
 *   - (I)Ljava/lang/Object;
 *   - isHidden
 *   - getObsolete
 *   - ()Ljava/lang/String;
 *   - getFullName
 *   - getDisplayName
 *   - getDisplayCategory
 *   - ()Lzombie/core/textures/Texture;
 *   - getNormalTexture
 *   - (Ljava/lang/String;)Lzombie/inventory/InventoryItem;
 *   - CreateItem
 *   - ()Lzombie/core/skinnedmodel/visual/ItemVisual;
 *   - getVisual
 *   - isFavorite
 *   - getFullType
 *   - (Lzombie/inventory/InventoryItem;)Z
 *   - isEquipped
 *   - (Lzombie/core/Transaction;)V
 *   - setDrawDirty
 *   - getID
 *   - getXStart
 *   - getYStart
 *   - getXEnd
 *   - getYEnd
 *   - getWidth
 *   - getHeight
 *   - getBaseHunger
 *   - ()Lzombie/scripting/objects/AmmoType;
 *   - getAmmoType
 *   - getItemKey
 *   - getMagazineType
 *   - usesExternalMagazine
 *   - ()Ljava/util/List;
 *   - getMountOn
 *   - getExplosionRange
 *   - getExplosionPower
 *   - getFireRange
 *   - getFireStartingEnergy
 *   - getFireStartingChance
 *   - getSmokeRange
 *   - getNoiseRange
 *   - getSensorRange
 */


/* Caches item, weapon, inventory, and transaction JNI methods. */

undefined8 initializeItemWeaponBridge(longlong *param_1)

{
  undefined8 in_RAX;
  ulonglong uVar1;
  
  if (DAT_1801014b0 != '\0') {
    return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
  }
  DAT_1801014b8 = findGlobalJniClass(param_1,"zombie/network/GameClient");
  DAT_1801014c0 = findGlobalJniClass(param_1,"zombie/network/GameServer");
  DAT_1801014c8 = findGlobalJniClass(param_1,"zombie/characters/IsoPlayer");
  DAT_1801014d0 = findGlobalJniClass(param_1,"zombie/scripting/ScriptManager");
  DAT_1801014d8 = findGlobalJniClass(param_1,"java/util/ArrayList");
  DAT_1801014e0 = findGlobalJniClass(param_1,"zombie/scripting/objects/Item");
  DAT_1801014e8 = findGlobalJniClass(param_1,"zombie/core/textures/Texture");
  DAT_1801014f0 = findGlobalJniClass(param_1,"zombie/inventory/InventoryItemFactory");
  DAT_1801014f8 = findGlobalJniClass(param_1,"zombie/network/packets/ItemTransactionPacket");
  DAT_180101500 = findGlobalJniClass(param_1,"zombie/core/TransactionManager");
  DAT_180101508 = findGlobalJniClass(param_1,"zombie/iso/IsoDirections");
  DAT_180101510 = findGlobalJniClass(param_1,"zombie/inventory/InventoryItem");
  DAT_180101518 = findGlobalJniClass(param_1,"zombie/inventory/ItemContainer");
  DAT_180101520 = findGlobalJniClass(param_1,"zombie/inventory/types/InventoryContainer");
  DAT_180101528 = findGlobalJniClass(param_1,"zombie/inventory/types/Food");
  DAT_180101530 = findGlobalJniClass(param_1,"zombie/inventory/types/HandWeapon");
  DAT_180101538 = findGlobalJniClass(param_1,"zombie/inventory/types/WeaponPart");
  DAT_180101540 = findGlobalJniClass(param_1,"zombie/scripting/objects/AmmoType");
  DAT_180101548 = findGlobalJniClass(param_1,"zombie/network/PacketTypes$PacketType");
  if ((((((DAT_1801014b8 != 0) && (DAT_1801014c0 != 0)) && (DAT_1801014c8 != 0)) &&
       (((DAT_1801014d0 != 0 && (DAT_1801014d8 != 0)) &&
        ((DAT_1801014e0 != 0 && ((DAT_1801014e8 != 0 && (DAT_1801014f0 != 0)))))))) &&
      ((DAT_1801014f8 != 0 &&
       (((((DAT_180101500 != 0 && (DAT_180101508 != 0)) && (DAT_180101510 != 0)) &&
         ((DAT_180101518 != 0 && (DAT_180101520 != 0)))) && (DAT_180101528 != 0)))))) &&
     (((DAT_180101530 != 0 && (DAT_180101538 != 0)) &&
      ((DAT_180101540 != 0 && (DAT_180101548 != 0)))))) {
    DAT_180101550 = (**(code **)(*param_1 + 0x480))(param_1,DAT_1801014b8,"client",&DAT_1800d788c);
    DAT_180101558 = (**(code **)(*param_1 + 0x480))(param_1,DAT_1801014c0,"server",&DAT_1800d788c);
    DAT_180101560 =
         (**(code **)(*param_1 + 0x480))
                   (param_1,DAT_180101548,"ItemTransaction",
                    "Lzombie/network/PacketTypes$PacketType;");
    DAT_180101568 =
         (**(code **)(*param_1 + 0x480))
                   (param_1,DAT_180101508,&DAT_1800de81c,"Lzombie/iso/IsoDirections;");
    DAT_180101570 =
         (**(code **)(*param_1 + 0x480))
                   (param_1,DAT_1801014d0,"instance","Lzombie/scripting/ScriptManager;");
    DAT_180101578 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_1801014c8,"getInstance","()Lzombie/characters/IsoPlayer;");
    DAT_180101580 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_1801014d0,"getAllItems","()Ljava/util/ArrayList;");
    DAT_180101588 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801014d8,&DAT_1800d7978,&DAT_1800d7974);
    DAT_180101590 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_1801014d8,&DAT_1800d7998,"(I)Ljava/lang/Object;");
    DAT_180101598 = (**(code **)(*param_1 + 0x108))(param_1,DAT_1801014e0,"isHidden",&DAT_1800d79c4)
    ;
    DAT_1801015a0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801014e0,"getObsolete",&DAT_1800d79c4);
    DAT_1801015a8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801014e0,"getFullName","()Ljava/lang/String;")
    ;
    DAT_1801015b0 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_1801014e0,"getDisplayName","()Ljava/lang/String;");
    DAT_1801015b8 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_1801014e0,"getDisplayCategory","()Ljava/lang/String;");
    DAT_1801015c0 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_1801014e0,"getNormalTexture","()Lzombie/core/textures/Texture;");
    DAT_1801015c8 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_1801014f0,"CreateItem",
                    "(Ljava/lang/String;)Lzombie/inventory/InventoryItem;");
    DAT_1801015d0 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101510,"getVisual",
                    "()Lzombie/core/skinnedmodel/visual/ItemVisual;");
    DAT_1801015d8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101510,"isFavorite",&DAT_1800d79c4);
    DAT_1801015e0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101510,"getFullType","()Ljava/lang/String;")
    ;
    DAT_1801015e8 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_1801014c8,"isEquipped","(Lzombie/inventory/InventoryItem;)Z");
    DAT_1801015f0 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_180101500,&DAT_1800de9e0,"(Lzombie/core/Transaction;)V");
    DAT_1801015f8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101518,"setDrawDirty",&DAT_1800de9e4);
    DAT_180101600 = (**(code **)(*param_1 + 0x108))(param_1,DAT_1801014e8,"getID",&DAT_1800d7974);
    DAT_180101608 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801014e8,"getXStart",&DAT_1800d79f0);
    DAT_180101610 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801014e8,"getYStart",&DAT_1800d79f0);
    DAT_180101618 = (**(code **)(*param_1 + 0x108))(param_1,DAT_1801014e8,"getXEnd",&DAT_1800d79f0);
    DAT_180101620 = (**(code **)(*param_1 + 0x108))(param_1,DAT_1801014e8,"getYEnd",&DAT_1800d79f0);
    DAT_180101628 = (**(code **)(*param_1 + 0x108))(param_1,DAT_1801014e8,"getWidth",&DAT_1800d7974)
    ;
    DAT_180101630 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801014e8,"getHeight",&DAT_1800d7974);
    DAT_180101638 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101528,"getBaseHunger",&DAT_1800d79f0);
    DAT_180101640 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101530,"getAmmoType","()Lzombie/scripting/objects/AmmoType;");
    DAT_180101648 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101540,"getItemKey","()Ljava/lang/String;");
    DAT_180101650 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101530,"getMagazineType","()Ljava/lang/String;");
    DAT_180101658 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101530,"usesExternalMagazine",&DAT_1800d79c4);
    DAT_180101660 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101538,"getMountOn","()Ljava/util/List;");
    DAT_180101668 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101530,"getExplosionRange",&DAT_1800d7974);
    DAT_180101670 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101530,"getExplosionPower",&DAT_1800d7974);
    DAT_180101678 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101530,"getFireRange",&DAT_1800d7974);
    DAT_180101680 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101530,"getFireStartingEnergy",&DAT_1800d7974);
    DAT_180101688 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101530,"getFireStartingChance",&DAT_1800d7974);
    DAT_180101690 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101530,"getSmokeRange",&DAT_1800d7974);
    DAT_180101698 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101530,"getNoiseRange",&DAT_1800d7974);
    DAT_1801016a0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101530,"getSensorRange",&DAT_1800d7974);
    uVar1 = (**(code **)(*param_1 + 0x720))(param_1);
    if ((char)uVar1 == '\0') {
      if (((((((DAT_180101550 != 0) && (DAT_180101558 != 0)) && (DAT_180101560 != 0)) &&
            (((DAT_180101568 != 0 && (DAT_180101570 != 0)) &&
             ((DAT_180101578 != 0 && ((DAT_180101580 != 0 && (DAT_180101588 != 0)))))))) &&
           ((DAT_180101590 != 0 &&
            ((((DAT_180101598 != 0 && (DAT_1801015a0 != 0)) && (DAT_1801015a8 != 0)) &&
             ((DAT_1801015b0 != 0 && (DAT_1801015b8 != 0)))))))) &&
          (((DAT_1801015c0 != 0 && ((DAT_1801015c8 != 0 && (DAT_1801015d0 != 0)))) &&
           (DAT_1801015d8 != 0)))) &&
         (((((((((DAT_1801015e0 != 0 && (DAT_1801015e8 != 0)) && (DAT_1801015f0 != 0)) &&
               ((DAT_1801015f8 != 0 && (DAT_180101600 != 0)))) &&
              ((DAT_180101608 != 0 && ((DAT_180101610 != 0 && (DAT_180101618 != 0)))))) &&
             (DAT_180101620 != 0)) &&
            (((DAT_180101628 != 0 && (DAT_180101630 != 0)) && (DAT_180101638 != 0)))) &&
           (((((DAT_180101640 != 0 && (DAT_180101648 != 0)) &&
              ((DAT_180101650 != 0 && ((DAT_180101658 != 0 && (DAT_180101660 != 0)))))) &&
             (DAT_180101668 != 0)) &&
            (((DAT_180101670 != 0 && (DAT_180101678 != 0)) && (DAT_180101680 != 0)))))) &&
          (((DAT_180101688 != 0 && (DAT_180101690 != 0)) &&
           ((DAT_180101698 != 0 && (DAT_1801016a0 != 0)))))))) {
        DAT_1801014b0 = 1;
        return CONCAT71((int7)(uVar1 >> 8),1);
      }
    }
    else {
      uVar1 = (**(code **)(*param_1 + 0x88))(param_1);
    }
    DAT_1801014b0 = 0;
    return uVar1 & 0xffffffffffffff00;
  }
  return DAT_180101548 & 0xffffffffffffff00;
}

