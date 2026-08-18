/*
 * Semantic name: initializePalletGrantBridge
 * Address: 0x18001a3e0
 * Module: item-grant
 * Confidence: high
 * Summary: Caches the classes, fields, and methods used by the disposable pallet route.
 * Ghidra function: initializePalletGrantBridge
 * Callers:
 *   - beginPalletItemGrant @ 0x18001b510
 *   - pollPalletItemGrant @ 0x18001bc80
 * Callees:
 *   - findGlobalJniClass @ 0x180009cc0
 * Referenced strings:
 *   - zombie/inventory/InventoryItemFactory
 *   - zombie/inventory/InventoryItem
 *   - zombie/inventory/types/HandWeapon
 *   - java/lang/Object
 *   - zombie/iso/objects/IsoTrap
 *   - java/util/List
 *   - java/lang/Double
 *   - zombie/network/packets/AddExplosiveTrapPacket
 *   - zombie/network/packets/NetTimedActionPacket
 *   - zombie/network/PacketTypes$PacketType
 *   - Lzombie/network/PacketTypes$PacketType;
 *   - AddExplosiveTrap
 *   - (Ljava/lang/String;)Lzombie/inventory/InventoryItem;
 *   - CreateItem
 *   - getID
 *   - ()Ljava/lang/String;
 *   - getFullType
 *   - setRemoteControlID
 *   - getRemoteControlID
 *   - getExplosionRange
 *   - getExplosionPower
 *   - getFireRange
 *   - getFireStartingEnergy
 *   - getFireStartingChance
 *   - getSmokeRange
 *   - getNoiseRange
 *   - getSensorRange
 *   - (I)Ljava/lang/Object;
 *   - ()Lzombie/inventory/InventoryItem;
 *   - getItem
 *   - (D)Ljava/lang/Double;
 *   - valueOf
 */


/* Caches the classes, fields, and methods used by the disposable pallet route. */

undefined8 initializePalletGrantBridge(longlong *param_1)

{
  undefined8 in_RAX;
  ulonglong uVar1;
  
  if (palletGrantBridgeInitialized != '\0') {
    return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
  }
  classInventoryItemFactory = findGlobalJniClass(param_1,"zombie/inventory/InventoryItemFactory");
  classInventoryItem = findGlobalJniClass(param_1,"zombie/inventory/InventoryItem");
  classHandWeapon = findGlobalJniClass(param_1,"zombie/inventory/types/HandWeapon");
  classJavaObject = findGlobalJniClass(param_1,"java/lang/Object");
  classIsoTrap = findGlobalJniClass(param_1,"zombie/iso/objects/IsoTrap");
  classJavaList = findGlobalJniClass(param_1,"java/util/List");
  classJavaDouble = findGlobalJniClass(param_1,"java/lang/Double");
  classAddExplosiveTrapPacket =
       findGlobalJniClass(param_1,"zombie/network/packets/AddExplosiveTrapPacket");
  classNetTimedActionPacket =
       findGlobalJniClass(param_1,"zombie/network/packets/NetTimedActionPacket");
  classPacketType = findGlobalJniClass(param_1,"zombie/network/PacketTypes$PacketType");
  if ((((((classInventoryItemFactory != 0) && (classInventoryItem != 0)) && (classHandWeapon != 0))
       && ((classJavaObject != 0 && (classIsoTrap != 0)))) && (classJavaList != 0)) &&
     (((classJavaDouble != 0 && (classAddExplosiveTrapPacket != 0)) &&
      ((classNetTimedActionPacket != 0 && (classPacketType != 0)))))) {
    fieldPacketTypeAddExplosiveTrap =
         (**(code **)(*param_1 + 0x480))
                   (param_1,classPacketType,"AddExplosiveTrap",
                    "Lzombie/network/PacketTypes$PacketType;");
    methodCreateInventoryItem =
         (**(code **)(*param_1 + 0x388))
                   (param_1,classInventoryItemFactory,"CreateItem",
                    "(Ljava/lang/String;)Lzombie/inventory/InventoryItem;");
    methodGetItemId =
         (**(code **)(*param_1 + 0x108))(param_1,classInventoryItem,"getID",&DAT_1800d7974);
    methodGetFullItemType =
         (**(code **)(*param_1 + 0x108))
                   (param_1,classInventoryItem,"getFullType","()Ljava/lang/String;");
    methodSetRemoteControlId =
         (**(code **)(*param_1 + 0x108))
                   (param_1,classInventoryItem,"setRemoteControlID",&DAT_1800df59c);
    methodGetRemoteControlId =
         (**(code **)(*param_1 + 0x108))
                   (param_1,classInventoryItem,"getRemoteControlID",&DAT_1800d7974);
    methodGetExplosionRange =
         (**(code **)(*param_1 + 0x108))(param_1,classHandWeapon,"getExplosionRange",&DAT_1800d7974)
    ;
    methodGetExplosionPower =
         (**(code **)(*param_1 + 0x108))(param_1,classHandWeapon,"getExplosionPower",&DAT_1800d7974)
    ;
    methodGetFireRange =
         (**(code **)(*param_1 + 0x108))(param_1,classHandWeapon,"getFireRange",&DAT_1800d7974);
    methodGetFireStartingEnergy =
         (**(code **)(*param_1 + 0x108))
                   (param_1,classHandWeapon,"getFireStartingEnergy",&DAT_1800d7974);
    methodGetFireStartingChance =
         (**(code **)(*param_1 + 0x108))
                   (param_1,classHandWeapon,"getFireStartingChance",&DAT_1800d7974);
    methodGetSmokeRange =
         (**(code **)(*param_1 + 0x108))(param_1,classHandWeapon,"getSmokeRange",&DAT_1800d7974);
    methodGetNoiseRange =
         (**(code **)(*param_1 + 0x108))(param_1,classHandWeapon,"getNoiseRange",&DAT_1800d7974);
    methodGetSensorRange =
         (**(code **)(*param_1 + 0x108))(param_1,classHandWeapon,"getSensorRange",&DAT_1800d7974);
    methodListSize =
         (**(code **)(*param_1 + 0x108))(param_1,classJavaList,&DAT_1800d7978,&DAT_1800d7974);
    methodListGet =
         (**(code **)(*param_1 + 0x108))
                   (param_1,classJavaList,&DAT_1800d7998,"(I)Ljava/lang/Object;");
    methodIsoTrapGetItem =
         (**(code **)(*param_1 + 0x108))
                   (param_1,classIsoTrap,"getItem","()Lzombie/inventory/InventoryItem;");
    methodDoubleValueOf =
         (**(code **)(*param_1 + 0x388))(param_1,classJavaDouble,"valueOf","(D)Ljava/lang/Double;");
    uVar1 = (**(code **)(*param_1 + 0x720))(param_1);
    if ((char)uVar1 == '\0') {
      if (((((fieldPacketTypeAddExplosiveTrap != 0) && (methodCreateInventoryItem != 0)) &&
           (methodGetItemId != 0)) &&
          (((methodGetFullItemType != 0 && (methodSetRemoteControlId != 0)) &&
           ((((methodGetRemoteControlId != 0 &&
              ((methodGetExplosionRange != 0 && (methodGetExplosionPower != 0)))) &&
             (methodGetFireRange != 0)) &&
            ((((methodGetFireStartingEnergy != 0 && (methodGetFireStartingChance != 0)) &&
              (methodGetSmokeRange != 0)) &&
             (((methodGetNoiseRange != 0 && (methodGetSensorRange != 0)) &&
              ((methodListSize != 0 && ((methodListGet != 0 && (methodIsoTrapGetItem != 0)))))))))))
           ))) && (methodDoubleValueOf != 0)) {
        palletGrantBridgeInitialized = 1;
        return CONCAT71((int7)(uVar1 >> 8),1);
      }
    }
    else {
      uVar1 = (**(code **)(*param_1 + 0x88))(param_1);
    }
    palletGrantBridgeInitialized = 0;
    return uVar1 & 0xffffffffffffff00;
  }
  return classPacketType & 0xffffffffffffff00;
}

