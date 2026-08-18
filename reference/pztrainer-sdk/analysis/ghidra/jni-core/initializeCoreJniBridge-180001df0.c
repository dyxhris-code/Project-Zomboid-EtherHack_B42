/*
 * Semantic name: initializeCoreJniBridge
 * Address: 0x180001df0
 * Module: jni-core
 * Confidence: medium
 * Summary: Caches the core player, entity, world, and rendering JNI surface.
 * Ghidra function: initializeCoreJniBridge
 * Callers:
 *   - FUN_180003ad0 @ 0x180003ad0
 * Callees:
 *   - jniCallStaticObjectMethodOneArg @ 0x180001930
 *   - FUN_180001b80 @ 0x180001b80
 * Referenced strings:
 *   - java/lang/ClassLoader
 *   - ()Ljava/lang/ClassLoader;
 *   - getSystemClassLoader
 *   - (Ljava/lang/String;)Ljava/lang/Class;
 *   - loadClass
 *   - zombie/network/GameClient
 *   - zombie/network/GameServer
 *   - zombie/characters/IsoPlayer
 *   - zombie/characters/animals/IsoAnimal
 *   - zombie/vehicles/BaseVehicle
 *   - zombie/inventory/ItemContainer
 *   - zombie/iso/IsoWorld
 *   - zombie/iso/IsoCell
 *   - java/util/ArrayList
 *   - java/util/Set
 *   - java/util/Iterator
 *   - zombie/iso/IsoMovingObject
 *   - zombie/iso/IsoUtils
 *   - zombie/core/Core
 *   - zombie/core/skinnedmodel/animation/AnimationPlayer
 *   - org/lwjgl/util/vector/Matrix4f
 *   - zombie/core/skinnedmodel/model/SkinningData
 *   - zombie/core/skinnedmodel/model/SkinningBone
 *   - org/lwjgl/util/vector/Vector3f
 *   - zombie/core/skinnedmodel/model/SkeletonBone
 *   - zombie/characters/IsoGameCharacter
 *   - zombie/characters/Safety
 *   - zombie/CombatManager
 *   - zombie/iso/LosUtil
 *   - zombie/iso/LosUtil$TestResults
 *   - java/lang/System
 *   - client
 *   - server
 *   - Lzombie/iso/IsoWorld;
 *   - instance
 *   - ()Lzombie/characters/IsoPlayer;
 *   - getInstance
 *   - ()Lzombie/iso/IsoCell;
 *   - getCell
 *   - ()Ljava/util/ArrayList;
 *   - getZombieList
 *   - ()Ljava/util/Set;
 *   - getObjectList
 *   - getVehicles
 *   - (I)Ljava/lang/Object;
 *   - ()Ljava/util/Iterator;
 *   - iterator
 *   - hasNext
 *   - ()Ljava/lang/Object;
 *   - getID
 *   - (Ljava/lang/Object;)I
 *   - identityHashCode
 *   - getHealth
 *   - isAlive
 *   - ()Lzombie/core/skinnedmodel/animation/AnimationPlayer;
 *   - getAnimationPlayer
 *   - getForwardDirectionX
 *   - getForwardDirectionY
 *   - isFallOnFront
 *   - isFalling
 *   - isKnockedDown
 *   - setAlphaAndTarget
 *   - getOnlineID
 *   - ()Ljava/lang/String;
 *   - getUsername
 *   - ()Lzombie/characters/Safety;
 *   - getSafety
 *   - isEnabled
 *   - (Lzombie/iso/IsoMovingObject;Lzombie/iso/IsoMovingObject;Z)Z
 *   - checkPVP
 *   - getCustomName
 *   - getFullName
 *   - getAnimalType
 *   - getAnimalSize
 *   - isBaby
 *   - getId
 *   - getScriptName
 *   - getEngineCondition
 *   - isEngineRunning
 *   - areAllDoorsLocked
 *   - isAnyDoorLocked
 *   - isHotwired
 *   - isHotwiredBroken
 *   - isKeysInIgnition
 *   - getKeyId
 *   - ()Lzombie/inventory/ItemContainer;
 *   - getInventory
 *   - (I)Lzombie/inventory/InventoryItem;
 *   - haveThisKeyId
 *   - zombie/characters/IsoZombie
 *   - isCrawling
 *   - isProne
 *   - (FFFI)F
 *   - XToScreenExact
 *   - YToScreenExact
 *   - ()Lzombie/core/Core;
 *   - getZoom
 *   - (Lzombie/iso/IsoCell;IIIIIIZ)Lzombie/iso/LosUtil$TestResults;
 *   - lineClear
 *   - Lzombie/iso/LosUtil$TestResults;
 *   - Blocked
 *   - ClearThroughClosedDoor
 *   - isReady
 *   - (Ljava/lang/String;I)I
 *   - getSkinningBoneIndex
 *   - (ILorg/lwjgl/util/vector/Matrix4f;)Lorg/lwjgl/util/vector/Matrix4f;
 *   - getBoneModelTransform
 *   - (I)Lorg/lwjgl/util/vector/Matrix4f;
 *   - getModelTransformAt
 *   - ()Lzombie/core/skinnedmodel/model/SkinningData;
 *   - getSkinningData
 *   - (Ljava/lang/String;)Lzombie/core/skinnedmodel/model/SkinningBone;
 *   - getBone
 *   - (Lzombie/core/skinnedmodel/model/SkeletonBone;Lorg/lwjgl/util/vector/Vector3f;)Lorg/lwjgl/util/vector/Vector3f;
 *   - getBoneWorldPosition
 *   - <init>
 *   - Lzombie/core/skinnedmodel/model/SkeletonBone;
 *   - JVM system class loader
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Caches the core player, entity, world, and rendering JNI surface. */

undefined8 initializeCoreJniBridge(longlong *param_1)

{
  char cVar1;
  undefined8 in_RAX;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  char *pcVar6;
  ulonglong uVar7;
  
  if (DAT_180100d88 != '\0') {
    return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
  }
  lVar2 = (**(code **)(*param_1 + 0x30))(param_1,"java/lang/ClassLoader");
  if (lVar2 == 0) {
LAB_1800037dc:
    PTR_DAT_1800ff968 = &DAT_1800d73d0;
    return "Forearm";
  }
  cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x88))(param_1);
    goto LAB_1800037dc;
  }
  lVar3 = (**(code **)(*param_1 + 0x388))
                    (param_1,lVar2,"getSystemClassLoader","()Ljava/lang/ClassLoader;");
  DAT_180100d98 =
       (**(code **)(*param_1 + 0x108))
                 (param_1,lVar2,"loadClass","(Ljava/lang/String;)Ljava/lang/Class;");
  if ((lVar3 != 0) && (lVar3 = jniCallStaticObjectMethodOneArg(param_1), lVar3 != 0)) {
    cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
    if (cVar1 == '\0') {
      DAT_180100d90 = (**(code **)(*param_1 + 0xa8))(param_1,lVar3);
      (**(code **)(*param_1 + 0xb8))(param_1,lVar3);
    }
    else {
      (**(code **)(*param_1 + 0x88))(param_1);
    }
  }
  (**(code **)(*param_1 + 0xb8))(param_1,lVar2);
  if ((DAT_180100d90 == 0) || (DAT_180100d98 == 0)) {
    cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 0x88))(param_1);
    }
    pcVar5 = "JVM system class loader";
    goto LAB_1800036c9;
  }
  DAT_180100da0 = FUN_180001b80(param_1,"zombie/network/GameClient");
  DAT_180100da8 = FUN_180001b80(param_1,"zombie/network/GameServer");
  DAT_180100db0 = FUN_180001b80(param_1,"zombie/characters/IsoPlayer");
  DAT_180100db8 = FUN_180001b80(param_1,"zombie/characters/animals/IsoAnimal");
  DAT_180100dc0 = FUN_180001b80(param_1,"zombie/vehicles/BaseVehicle");
  DAT_180100dc8 = FUN_180001b80(param_1,"zombie/inventory/ItemContainer");
  DAT_180100dd0 = FUN_180001b80(param_1,"zombie/iso/IsoWorld");
  DAT_180100dd8 = FUN_180001b80(param_1,"zombie/iso/IsoCell");
  DAT_180100de0 = FUN_180001b80(param_1,"java/util/ArrayList");
  DAT_180100de8 = FUN_180001b80(param_1,"java/util/Set");
  DAT_180100df0 = FUN_180001b80(param_1,"java/util/Iterator");
  DAT_180100df8 = FUN_180001b80(param_1,"zombie/iso/IsoMovingObject");
  DAT_180100e00 = FUN_180001b80(param_1,"zombie/iso/IsoUtils");
  DAT_180100e08 = FUN_180001b80(param_1,"zombie/core/Core");
  DAT_180100e10 = FUN_180001b80(param_1,"zombie/core/skinnedmodel/animation/AnimationPlayer");
  DAT_180100e18 = FUN_180001b80(param_1,"org/lwjgl/util/vector/Matrix4f");
  DAT_180100e20 = FUN_180001b80(param_1,"zombie/core/skinnedmodel/model/SkinningData");
  DAT_180100e28 = FUN_180001b80(param_1,"zombie/core/skinnedmodel/model/SkinningBone");
  DAT_180100e30 = FUN_180001b80(param_1,"org/lwjgl/util/vector/Vector3f");
  DAT_180100e38 = FUN_180001b80(param_1,"zombie/core/skinnedmodel/model/SkeletonBone");
  DAT_180100e40 = FUN_180001b80(param_1,"zombie/characters/IsoGameCharacter");
  DAT_180100e48 = FUN_180001b80(param_1,"zombie/characters/Safety");
  DAT_180100e50 = FUN_180001b80(param_1,"zombie/CombatManager");
  DAT_180100e58 = FUN_180001b80(param_1,"zombie/iso/LosUtil");
  DAT_180100e60 = FUN_180001b80(param_1,"zombie/iso/LosUtil$TestResults");
  DAT_180100e68 = FUN_180001b80(param_1,"java/lang/System");
  if (DAT_180100da0 == 0) {
    pcVar5 = &DAT_1800d77b0;
    goto LAB_1800036c9;
  }
  if (DAT_180100da8 == 0) {
LAB_1800036ec:
    pcVar5 = &DAT_1800d77c0;
    goto LAB_1800036c9;
  }
  if (((((DAT_180100db0 == 0) || (DAT_180100db8 == 0)) || (DAT_180100dc0 == 0)) ||
      ((DAT_180100dc8 == 0 || (DAT_180100dd0 == 0)))) ||
     ((((DAT_180100dd8 == 0 || ((DAT_180100de0 == 0 || (DAT_180100de8 == 0)))) ||
       ((DAT_180100df0 == 0 ||
        (((DAT_180100df8 == 0 || (DAT_180100e00 == 0)) || (DAT_180100e08 == 0)))))) ||
      ((((DAT_180100e10 == 0 || (DAT_180100e18 == 0)) ||
        ((DAT_180100e20 == 0 || ((DAT_180100e28 == 0 || (DAT_180100e30 == 0)))))) ||
       ((DAT_180100e38 == 0 ||
        (((DAT_180100e40 == 0 || (DAT_180100e48 == 0)) || (DAT_180100e50 == 0)))))))))) {
    if (DAT_180100da8 == 0) goto LAB_1800036ec;
    if (DAT_180100db0 == 0) {
      pcVar5 = &DAT_1800d77d0;
      goto LAB_1800036c9;
    }
    if (DAT_180100db8 == 0) {
      pcVar5 = &DAT_1800d77e0;
      goto LAB_1800036c9;
    }
    if (DAT_180100dc0 == 0) {
      pcVar5 = &DAT_1800d77f0;
      goto LAB_1800036c9;
    }
    if (DAT_180100dd0 == 0) {
      pcVar5 = &DAT_1800d7800;
      goto LAB_1800036c9;
    }
    if (DAT_180100dd8 == 0) {
      pcVar5 = &DAT_1800d7810;
      goto LAB_1800036c9;
    }
    if (DAT_180100e48 == 0) {
      pcVar5 = &DAT_1800d7820;
      goto LAB_1800036c9;
    }
    if (DAT_180100e50 == 0) {
      pcVar5 = &DAT_1800d7830;
      goto LAB_1800036c9;
    }
    if (DAT_180100de0 == 0) {
      pcVar5 = &DAT_1800d7848;
      goto LAB_1800036c9;
    }
    if (DAT_180100df8 == 0) {
      pcVar5 = &DAT_1800d7858;
      goto LAB_1800036c9;
    }
    pcVar5 = &DAT_1800d7870;
    pcVar6 = &DAT_1800d7880;
    lVar2 = DAT_180100e00;
LAB_1800036c5:
    if (lVar2 != 0) {
      pcVar5 = pcVar6;
    }
  }
  else {
    DAT_180100e70 = (**(code **)(*param_1 + 0x480))(param_1,DAT_180100da0,"client",&DAT_1800d788c);
    DAT_180100e78 = (**(code **)(*param_1 + 0x480))(param_1,DAT_180100da8,"server",&DAT_1800d788c);
    DAT_180100e80 =
         (**(code **)(*param_1 + 0x480))(param_1,DAT_180100dd0,"instance","Lzombie/iso/IsoWorld;");
    DAT_180100e98 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_180100db0,"getInstance","()Lzombie/characters/IsoPlayer;");
    DAT_180100ea0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100dd0,"getCell","()Lzombie/iso/IsoCell;");
    DAT_180100ea8 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180100dd8,"getZombieList","()Ljava/util/ArrayList;");
    DAT_180100eb0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100dd8,"getObjectList","()Ljava/util/Set;");
    DAT_180100eb8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100dd8,"getVehicles","()Ljava/util/Set;");
    DAT_180100ec0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100de0,&DAT_1800d7978,&DAT_1800d7974);
    DAT_180100ec8 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180100de0,&DAT_1800d7998,"(I)Ljava/lang/Object;");
    DAT_180100ed0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100de8,"iterator","()Ljava/util/Iterator;");
    DAT_180100ed8 = (**(code **)(*param_1 + 0x108))(param_1,DAT_180100df0,"hasNext",&DAT_1800d79c4);
    DAT_180100ee0 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180100df0,&DAT_1800d79e8,"()Ljava/lang/Object;");
    DAT_180100ee8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100df8,&DAT_1800d79f4,&DAT_1800d79f0);
    DAT_180100ef0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100df8,&DAT_1800d79fc,&DAT_1800d79f0);
    DAT_180100ef8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100df8,&DAT_1800d7a04,&DAT_1800d79f0);
    DAT_180100f00 = (**(code **)(*param_1 + 0x108))(param_1,DAT_180100e40,"getID",&DAT_1800d7974);
    if (DAT_180100e68 != 0) {
      DAT_1801010b0 =
           (**(code **)(*param_1 + 0x388))
                     (param_1,DAT_180100e68,"identityHashCode","(Ljava/lang/Object;)I");
    }
    if (DAT_180100e40 != 0) {
      DAT_180100fc0 =
           (**(code **)(*param_1 + 0x108))(param_1,DAT_180100e40,"getHealth",&DAT_1800d79f0);
      DAT_180100fc8 =
           (**(code **)(*param_1 + 0x108))(param_1,DAT_180100e40,"isAlive",&DAT_1800d79c4);
      DAT_180101020 =
           (**(code **)(*param_1 + 0x108))
                     (param_1,DAT_180100e40,"getAnimationPlayer",
                      "()Lzombie/core/skinnedmodel/animation/AnimationPlayer;");
      DAT_180101088 =
           (**(code **)(*param_1 + 0x108))
                     (param_1,DAT_180100e40,"getForwardDirectionX",&DAT_1800d79f0);
      DAT_180101090 =
           (**(code **)(*param_1 + 0x108))
                     (param_1,DAT_180100e40,"getForwardDirectionY",&DAT_1800d79f0);
      DAT_180100ff0 =
           (**(code **)(*param_1 + 0x108))(param_1,DAT_180100e40,"isFallOnFront",&DAT_1800d79c4);
      DAT_180100fe0 =
           (**(code **)(*param_1 + 0x108))(param_1,DAT_180100e40,"isFalling",&DAT_1800d79c4);
      DAT_180100fe8 =
           (**(code **)(*param_1 + 0x108))(param_1,DAT_180100e40,"isKnockedDown",&DAT_1800d79c4);
      DAT_180100ff8 =
           (**(code **)(*param_1 + 0x108))(param_1,DAT_180100e40,"setAlphaAndTarget",&DAT_1800d7b10)
      ;
    }
    DAT_180100f10 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100db0,"getOnlineID",&DAT_1800d7b2c);
    DAT_180100f18 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100db0,"getUsername","()Ljava/lang/String;")
    ;
    DAT_180100f20 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180100db0,"getSafety","()Lzombie/characters/Safety;");
    if (DAT_180100e48 != 0) {
      DAT_180100f28 =
           (**(code **)(*param_1 + 0x108))(param_1,DAT_180100e48,"isEnabled",&DAT_1800d79c4);
    }
    if (DAT_180100e50 != 0) {
      DAT_180100f30 =
           (**(code **)(*param_1 + 0x388))
                     (param_1,DAT_180100e50,"checkPVP",
                      "(Lzombie/iso/IsoMovingObject;Lzombie/iso/IsoMovingObject;Z)Z");
    }
    DAT_180100f38 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180100db8,"getCustomName","()Ljava/lang/String;");
    DAT_180100f40 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100db8,"getFullName","()Ljava/lang/String;")
    ;
    DAT_180100f48 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180100db8,"getAnimalType","()Ljava/lang/String;");
    DAT_180100f50 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100db8,"getAnimalSize",&DAT_1800d79f0);
    DAT_180100f58 = (**(code **)(*param_1 + 0x108))(param_1,DAT_180100db8,"isBaby",&DAT_1800d79c4);
    DAT_180100f60 = (**(code **)(*param_1 + 0x108))(param_1,DAT_180100dc0,"getId",&DAT_1800d7b2c);
    DAT_180100f68 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180100dc0,"getScriptName","()Ljava/lang/String;");
    DAT_180100f70 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100dc0,"getEngineCondition",&DAT_1800d7974);
    DAT_180100f78 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100dc0,"isEngineRunning",&DAT_1800d79c4);
    DAT_180100f80 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100dc0,"areAllDoorsLocked",&DAT_1800d79c4);
    DAT_180100f88 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100dc0,"isAnyDoorLocked",&DAT_1800d79c4);
    DAT_180100f90 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100dc0,"isHotwired",&DAT_1800d79c4);
    DAT_180100f98 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100dc0,"isHotwiredBroken",&DAT_1800d79c4);
    DAT_180100fa0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180100dc0,"isKeysInIgnition",&DAT_1800d79c4);
    DAT_180100fa8 = (**(code **)(*param_1 + 0x108))(param_1,DAT_180100dc0,"getKeyId",&DAT_1800d7974)
    ;
    DAT_180100fb0 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180100db0,"getInventory","()Lzombie/inventory/ItemContainer;");
    DAT_180100fb8 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180100dc8,"haveThisKeyId","(I)Lzombie/inventory/InventoryItem;");
    lVar2 = FUN_180001b80(param_1,"zombie/characters/IsoZombie");
    if (lVar2 != 0) {
      DAT_180100f08 = (**(code **)(*param_1 + 0x108))(param_1,lVar2,"getOnlineID",&DAT_1800d7b2c);
      DAT_180100fd0 = (**(code **)(*param_1 + 0x108))(param_1,lVar2,"isCrawling",&DAT_1800d79c4);
      DAT_180100fd8 = (**(code **)(*param_1 + 0x108))(param_1,lVar2,"isProne",&DAT_1800d79c4);
      (**(code **)(*param_1 + 0xb0))(param_1,lVar2);
    }
    DAT_180101000 =
         (**(code **)(*param_1 + 0x388))(param_1,DAT_180100e00,"XToScreenExact","(FFFI)F");
    DAT_180101008 =
         (**(code **)(*param_1 + 0x388))(param_1,DAT_180100e00,"YToScreenExact","(FFFI)F");
    DAT_180101010 =
         (**(code **)(*param_1 + 0x388))(param_1,DAT_180100e08,"getInstance","()Lzombie/core/Core;")
    ;
    DAT_180101018 = (**(code **)(*param_1 + 0x108))(param_1,DAT_180100e08,"getZoom",&DAT_1800d7de0);
    if (((DAT_180100e40 != 0) && (DAT_180100e58 != 0)) && (DAT_180100e60 != 0)) {
      DAT_180101098 =
           (**(code **)(*param_1 + 0x108))
                     (param_1,DAT_180100e40,"getForwardDirectionX",&DAT_1800d79f0);
      DAT_1801010a0 =
           (**(code **)(*param_1 + 0x108))
                     (param_1,DAT_180100e40,"getForwardDirectionY",&DAT_1800d79f0);
      DAT_1801010a8 =
           (**(code **)(*param_1 + 0x388))
                     (param_1,DAT_180100e58,"lineClear",
                      "(Lzombie/iso/IsoCell;IIIIIIZ)Lzombie/iso/LosUtil$TestResults;");
      lVar3 = (**(code **)(*param_1 + 0x480))
                        (param_1,DAT_180100e60,"Blocked","Lzombie/iso/LosUtil$TestResults;");
      lVar4 = (**(code **)(*param_1 + 0x480))
                        (param_1,DAT_180100e60,"ClearThroughClosedDoor",
                         "Lzombie/iso/LosUtil$TestResults;");
      lVar2 = 0;
      if (lVar3 != 0) {
        lVar2 = (**(code **)(*param_1 + 0x488))(param_1,DAT_180100e60,lVar3);
      }
      lVar3 = 0;
      if (lVar4 != 0) {
        lVar3 = (**(code **)(*param_1 + 0x488))(param_1,DAT_180100e60,lVar4);
      }
      cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
      if (cVar1 == '\0') {
        if (((DAT_180101098 == 0) || (DAT_1801010a0 == 0)) || (DAT_1801010a8 == 0))
        goto LAB_180002d3e;
        if (lVar2 != 0) {
          if (lVar3 != 0) {
            DAT_180100e88 = (**(code **)(*param_1 + 0xa8))(param_1,lVar2);
            DAT_180100e90 = (**(code **)(*param_1 + 0xa8))(param_1,lVar3);
            if ((DAT_180100e88 == 0) || (DAT_180100e90 == 0)) {
              DAT_180101181 = 0;
            }
            else {
              DAT_180101181 = 1;
            }
          }
          goto LAB_180002d43;
        }
      }
      else {
        (**(code **)(*param_1 + 0x88))(param_1);
LAB_180002d3e:
        if (lVar2 != 0) {
LAB_180002d43:
          (**(code **)(*param_1 + 0xb8))(param_1,lVar2);
        }
      }
      if (lVar3 != 0) {
        (**(code **)(*param_1 + 0xb8))(param_1,lVar3);
      }
      cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
      if (cVar1 != '\0') {
        (**(code **)(*param_1 + 0x88))(param_1);
      }
    }
    DAT_180101028 = (**(code **)(*param_1 + 0x108))(param_1,DAT_180100e10,"isReady",&DAT_1800d79c4);
    DAT_180101030 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180100e10,"getSkinningBoneIndex","(Ljava/lang/String;I)I");
    DAT_180101038 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180100e10,"getBoneModelTransform",
                    "(ILorg/lwjgl/util/vector/Matrix4f;)Lorg/lwjgl/util/vector/Matrix4f;");
    DAT_180101040 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180100e10,"getModelTransformAt",
                    "(I)Lorg/lwjgl/util/vector/Matrix4f;");
    _DAT_180101048 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180100e10,"getSkinningData",
                    "()Lzombie/core/skinnedmodel/model/SkinningData;");
    _DAT_180101050 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180100e20,"getBone",
                    "(Ljava/lang/String;)Lzombie/core/skinnedmodel/model/SkinningBone;");
    DAT_180101058 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180100e10,"getBoneWorldPosition",
                    "(Lzombie/core/skinnedmodel/model/SkeletonBone;Lorg/lwjgl/util/vector/Vector3f;)Lorg/lwjgl/util/vector/Vector3f;"
                   );
    DAT_180101060 = (**(code **)(*param_1 + 0x108))(param_1,DAT_180100e30,"<init>",&DAT_1800d8078);
    DAT_180101068 =
         (**(code **)(*param_1 + 0x2f0))(param_1,DAT_180100e30,&DAT_1800d8088,&DAT_1800d8084);
    DAT_180101070 =
         (**(code **)(*param_1 + 0x2f0))(param_1,DAT_180100e30,&DAT_1800d808c,&DAT_1800d8084);
    DAT_180101078 =
         (**(code **)(*param_1 + 0x2f0))(param_1,DAT_180100e30,&DAT_1800d8090,&DAT_1800d8084);
    if ((((DAT_180101058 == 0) || (DAT_180101060 == 0)) || (DAT_180101068 == 0)) ||
       ((DAT_180101070 == 0 || (DAT_180101078 == 0)))) {
      DAT_180101180 = '\0';
    }
    else {
      DAT_180101180 = '\x01';
      uVar7 = 0;
      do {
        if (0x12 < uVar7) break;
        lVar2 = (**(code **)(*param_1 + 0x480))
                          (param_1,DAT_180100e38,(&PTR_s_Bip01_Head_1800d8520)[uVar7],
                           "Lzombie/core/skinnedmodel/model/SkeletonBone;");
        (&DAT_1801010e8)[uVar7] = lVar2;
        if (lVar2 == 0) {
LAB_180002fe1:
          DAT_180101180 = '\0';
        }
        else {
          cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
          if (cVar1 != '\0') {
            (**(code **)(*param_1 + 0x88))(param_1);
            goto LAB_180002fe1;
          }
        }
        uVar7 = uVar7 + 1;
      } while (DAT_180101180 != '\0');
    }
    cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 0x88))(param_1);
    }
    DAT_180101080 = (**(code **)(*param_1 + 0x108))(param_1,DAT_180100e18,"<init>",&DAT_1800d8078);
    DAT_1801010b8 =
         (**(code **)(*param_1 + 0x2f0))(param_1,DAT_180100e18,&DAT_1800d80c8,&DAT_1800d8084);
    DAT_1801010c0 =
         (**(code **)(*param_1 + 0x2f0))(param_1,DAT_180100e18,&DAT_1800d80cc,&DAT_1800d8084);
    DAT_1801010c8 =
         (**(code **)(*param_1 + 0x2f0))(param_1,DAT_180100e18,&DAT_1800d80d0,&DAT_1800d8084);
    DAT_1801010d0 =
         (**(code **)(*param_1 + 0x2f0))(param_1,DAT_180100e18,&DAT_1800d80d4,&DAT_1800d8084);
    DAT_1801010d8 =
         (**(code **)(*param_1 + 0x2f0))(param_1,DAT_180100e18,&DAT_1800d80d8,&DAT_1800d8084);
    DAT_1801010e0 =
         (**(code **)(*param_1 + 0x2f0))(param_1,DAT_180100e18,&DAT_1800d80dc,&DAT_1800d8084);
    cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
    if (cVar1 == '\0') {
      if (DAT_180100e70 != 0) {
        if (((((DAT_180100e78 != 0) && (DAT_180100e80 != 0)) &&
             (((DAT_180100e98 != 0 &&
               (((DAT_180100ea0 != 0 && (DAT_180100ea8 != 0)) && (DAT_180100eb0 != 0)))) &&
              (((DAT_180100eb8 != 0 && (DAT_180100ec0 != 0)) && (DAT_180100ec8 != 0)))))) &&
            ((((DAT_180100ed0 != 0 && (DAT_180100ed8 != 0)) &&
              ((DAT_180100ee0 != 0 &&
               (((DAT_180100ee8 != 0 && (DAT_180100ef0 != 0)) && (DAT_180100ef8 != 0)))))) &&
             ((DAT_180100f00 != 0 && (DAT_180100f08 != 0)))))) &&
           (((DAT_180100f10 != 0 &&
             (((((DAT_180100f18 != 0 && (DAT_180100f20 != 0)) &&
                ((DAT_180100f28 != 0 &&
                 (((((DAT_180100f30 != 0 && (DAT_180100f38 != 0)) && (DAT_180100f40 != 0)) &&
                   ((DAT_180100f48 != 0 && (DAT_180100f50 != 0)))) && (DAT_180100f58 != 0)))))) &&
               ((DAT_180100f60 != 0 && (DAT_180100f68 != 0)))) && (DAT_180100f70 != 0)))) &&
            (((((((DAT_180100f78 != 0 && (DAT_180100f80 != 0)) && (DAT_180100f88 != 0)) &&
                (((DAT_180100f90 != 0 && (DAT_180100f98 != 0)) &&
                 ((DAT_180100fa0 != 0 && ((DAT_180100fa8 != 0 && (DAT_180100fb0 != 0)))))))) &&
               (DAT_180100fb8 != 0)) &&
              ((((DAT_180100fc0 != 0 && (DAT_180100fc8 != 0)) && (DAT_1801010b0 != 0)) &&
               (((DAT_180100fd0 != 0 && (DAT_180100fd8 != 0)) &&
                (((DAT_180100fe0 != 0 && ((DAT_180100fe8 != 0 && (DAT_180100ff0 != 0)))) &&
                 (DAT_180101000 != 0)))))))) &&
             (((((((DAT_180101008 != 0 && (DAT_180101010 != 0)) && (DAT_180101018 != 0)) &&
                 ((DAT_180101020 != 0 && (DAT_180101088 != 0)))) &&
                ((DAT_180101090 != 0 && ((DAT_180101028 != 0 && (DAT_180101030 != 0)))))) &&
               (DAT_180101038 != 0)) &&
              ((((DAT_180101080 != 0 && (DAT_180101040 != 0)) && (DAT_1801010b8 != 0)) &&
               (((DAT_1801010c0 != 0 && (DAT_1801010c8 != 0)) &&
                ((DAT_1801010d0 != 0 && ((DAT_1801010d8 != 0 && (DAT_1801010e0 != 0))))))))))))))))
        {
          DAT_180100d88 = 1;
          return CONCAT71((int7)((ulonglong)DAT_180100e70 >> 8),1);
        }
        goto LAB_1800034fd;
      }
    }
    else {
      (**(code **)(*param_1 + 0x88))(param_1);
LAB_1800034fd:
      if (DAT_180100e70 != 0) {
        if (DAT_180100e78 == 0) {
          pcVar5 = &DAT_1800d8100;
          goto LAB_1800036c9;
        }
        if (DAT_180100e80 == 0) {
          pcVar5 = &DAT_1800d8120;
          goto LAB_1800036c9;
        }
        if (DAT_180100e98 == 0) {
          pcVar5 = &DAT_1800d8140;
          goto LAB_1800036c9;
        }
        if (DAT_180100ea0 == 0) {
          pcVar5 = &DAT_1800d8160;
          goto LAB_1800036c9;
        }
        if (DAT_180100ea8 == 0) {
          pcVar5 = &DAT_1800d8178;
          goto LAB_1800036c9;
        }
        if (DAT_180100ec0 == 0) {
          pcVar5 = &DAT_1800d8198;
          goto LAB_1800036c9;
        }
        if (DAT_180100ec8 == 0) {
          pcVar5 = &DAT_1800d81b0;
          goto LAB_1800036c9;
        }
        if (DAT_180100ee8 == 0) {
          pcVar5 = &DAT_1800d81c8;
          goto LAB_1800036c9;
        }
        if (DAT_180100ef0 == 0) {
          pcVar5 = &DAT_1800d81e8;
          goto LAB_1800036c9;
        }
        if (DAT_180100ef8 == 0) {
          pcVar5 = &DAT_1800d8208;
          goto LAB_1800036c9;
        }
        if (DAT_180100f00 == 0) {
          pcVar5 = &DAT_1800d8228;
          goto LAB_1800036c9;
        }
        if (DAT_180100f08 == 0) {
          pcVar5 = &DAT_1800d8248;
          goto LAB_1800036c9;
        }
        if (DAT_180100fc0 == 0) {
          pcVar5 = &DAT_1800d8268;
          goto LAB_1800036c9;
        }
        if (DAT_1801010b0 == 0) {
          pcVar5 = &DAT_1800d8288;
          goto LAB_1800036c9;
        }
        if (DAT_180100fd0 == 0) {
          pcVar5 = &DAT_1800d82a8;
          goto LAB_1800036c9;
        }
        if (DAT_180100fd8 == 0) {
          pcVar5 = &DAT_1800d82c8;
          goto LAB_1800036c9;
        }
        if (DAT_180100fe0 == 0) {
          pcVar5 = &DAT_1800d82e8;
          goto LAB_1800036c9;
        }
        if (DAT_180100fe8 == 0) {
          pcVar5 = &DAT_1800d8310;
          goto LAB_1800036c9;
        }
        if (DAT_180101000 == 0) {
          pcVar5 = &DAT_1800d8338;
          goto LAB_1800036c9;
        }
        if (DAT_180101008 == 0) {
          pcVar5 = &DAT_1800d8358;
          goto LAB_1800036c9;
        }
        pcVar5 = &DAT_1800d8378;
        pcVar6 = &DAT_1800d8390;
        lVar2 = DAT_180101010;
        goto LAB_1800036c5;
      }
    }
    pcVar5 = &DAT_1800d80e0;
  }
LAB_1800036c9:
  PTR_DAT_1800ff968 = pcVar5;
  return (ulonglong)pcVar5 & 0xffffffffffffff00;
}

