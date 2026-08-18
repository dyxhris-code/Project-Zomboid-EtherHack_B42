/*
 * Semantic name: initializeClimateBridge
 * Address: 0x180022ed0
 * Module: climate
 * Confidence: medium
 * Summary: Caches climate and weather JNI methods.
 * Ghidra function: initializeClimateBridge
 * Callers:
 *   - FUN_180024860 @ 0x180024860
 * Callees:
 *   - findGlobalJniClass @ 0x180009cc0
 * Referenced strings:
 *   - zombie/iso/weather/ClimateManager
 *   - zombie/iso/weather/ClimateManager$ClimateFloat
 *   - zombie/iso/weather/ClimateManager$ClimateBool
 *   - zombie/iso/weather/ClimateManager$ClimateColor
 *   - zombie/iso/weather/ClimateColorInfo
 *   - zombie/characters/IsoPlayer
 *   - zombie/iso/IsoWorld
 *   - zombie/iso/IsoCell
 *   - zombie/iso/IsoLightSource
 *   - zombie/iso/LightingJNI
 *   - FLOAT_DESATURATION
 *   - FLOAT_GLOBAL_LIGHT_INTENSITY
 *   - FLOAT_NIGHT_STRENGTH
 *   - FLOAT_AMBIENT
 *   - FLOAT_DAYLIGHT_STRENGTH
 *   - COLOR_GLOBAL_LIGHT
 *   - FLOAT_FOG_INTENSITY
 *   - FLOAT_PRECIPITATION_INTENSITY
 *   - BOOL_IS_SNOW
 *   - isOverrideValue
 *   - overrideInternal
 *   - Lzombie/iso/IsoWorld;
 *   - instance
 *   - ()Lzombie/iso/weather/ClimateManager;
 *   - getInstance
 *   - (I)Lzombie/iso/weather/ClimateManager$ClimateFloat;
 *   - getClimateFloat
 *   - (I)Lzombie/iso/weather/ClimateManager$ClimateColor;
 *   - getClimateColor
 *   - (I)Lzombie/iso/weather/ClimateManager$ClimateBool;
 *   - getClimateBool
 *   - getOverride
 *   - getOverrideInterpolate
 *   - (FF)V
 *   - setOverride
 *   - setEnableOverride
 *   - isEnableOverride
 *   - ()Lzombie/iso/weather/ClimateColorInfo;
 *   - (Lzombie/iso/weather/ClimateColorInfo;F)V
 *   - (FFFFFFFF)V
 *   - <init>
 *   - (Lzombie/iso/weather/ClimateColorInfo;)V
 *   - setTo
 *   - ()Lzombie/characters/IsoPlayer;
 *   - ()Lzombie/iso/IsoCell;
 *   - getCell
 *   - (IIIFFFI)V
 *   - (Lzombie/iso/IsoLightSource;)V
 *   - addLamppost
 *   - removeLamppost
 *   - visionConeLerp
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Caches climate and weather JNI methods. */

undefined8 initializeClimateBridge(longlong *param_1)

{
  bool bVar1;
  undefined8 in_RAX;
  longlong *plVar2;
  ulonglong uVar3;
  
  if (DAT_180101f60 != '\0') {
    return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
  }
  DAT_180101f68 = findGlobalJniClass(param_1,"zombie/iso/weather/ClimateManager");
  DAT_180101f70 = findGlobalJniClass(param_1,"zombie/iso/weather/ClimateManager$ClimateFloat");
  DAT_180101f78 = findGlobalJniClass(param_1,"zombie/iso/weather/ClimateManager$ClimateBool");
  DAT_180101f80 = findGlobalJniClass(param_1,"zombie/iso/weather/ClimateManager$ClimateColor");
  DAT_180101f88 = findGlobalJniClass(param_1,"zombie/iso/weather/ClimateColorInfo");
  DAT_180101f90 = findGlobalJniClass(param_1,"zombie/characters/IsoPlayer");
  DAT_180101f98 = findGlobalJniClass(param_1,"zombie/iso/IsoWorld");
  DAT_180101fa0 = findGlobalJniClass(param_1,"zombie/iso/IsoCell");
  DAT_180101fa8 = findGlobalJniClass(param_1,"zombie/iso/IsoLightSource");
  DAT_180101fb0 = findGlobalJniClass(param_1,"zombie/iso/LightingJNI");
  if (((((DAT_180101f68 != 0) && (DAT_180101f70 != 0)) && (DAT_180101f78 != 0)) &&
      (((DAT_180101f80 != 0 && (DAT_180101f88 != 0)) &&
       ((DAT_180101f90 != 0 && ((DAT_180101f98 != 0 && (DAT_180101fa0 != 0)))))))) &&
     ((DAT_180101fa8 != 0 && (DAT_180101fb0 != 0)))) {
    DAT_180101fb8 =
         (**(code **)(*param_1 + 0x480))(param_1,DAT_180101f68,"FLOAT_DESATURATION",&DAT_1800e1dc0);
    DAT_180101fc0 =
         (**(code **)(*param_1 + 0x480))
                   (param_1,DAT_180101f68,"FLOAT_GLOBAL_LIGHT_INTENSITY",&DAT_1800e1dc0);
    _DAT_180101fc8 =
         (**(code **)(*param_1 + 0x480))
                   (param_1,DAT_180101f68,"FLOAT_NIGHT_STRENGTH",&DAT_1800e1dc0);
    _DAT_180101fd0 =
         (**(code **)(*param_1 + 0x480))(param_1,DAT_180101f68,"FLOAT_AMBIENT",&DAT_1800e1dc0);
    _DAT_180101fd8 =
         (**(code **)(*param_1 + 0x480))
                   (param_1,DAT_180101f68,"FLOAT_DAYLIGHT_STRENGTH",&DAT_1800e1dc0);
    DAT_180101fe0 =
         (**(code **)(*param_1 + 0x480))(param_1,DAT_180101f68,"COLOR_GLOBAL_LIGHT",&DAT_1800e1dc0);
    DAT_180101fe8 =
         (**(code **)(*param_1 + 0x480))(param_1,DAT_180101f68,"FLOAT_FOG_INTENSITY",&DAT_1800e1dc0)
    ;
    DAT_180101ff0 =
         (**(code **)(*param_1 + 0x480))
                   (param_1,DAT_180101f68,"FLOAT_PRECIPITATION_INTENSITY",&DAT_1800e1dc0);
    DAT_180101ff8 =
         (**(code **)(*param_1 + 0x480))(param_1,DAT_180101f68,"BOOL_IS_SNOW",&DAT_1800e1dc0);
    DAT_180102000 =
         (**(code **)(*param_1 + 0x2f0))(param_1,DAT_180101f70,"isOverrideValue",&DAT_1800d788c);
    DAT_180102008 =
         (**(code **)(*param_1 + 0x2f0))(param_1,DAT_180101f70,"overrideInternal",&DAT_1800d8084);
    DAT_180102010 =
         (**(code **)(*param_1 + 0x480))(param_1,DAT_180101f98,"instance","Lzombie/iso/IsoWorld;");
    DAT_180102018 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_180101f68,"getInstance","()Lzombie/iso/weather/ClimateManager;");
    DAT_180102020 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101f68,"getClimateFloat",
                    "(I)Lzombie/iso/weather/ClimateManager$ClimateFloat;");
    DAT_180102028 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101f68,"getClimateColor",
                    "(I)Lzombie/iso/weather/ClimateManager$ClimateColor;");
    DAT_180102030 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101f68,"getClimateBool",
                    "(I)Lzombie/iso/weather/ClimateManager$ClimateBool;");
    DAT_180102038 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101f70,"getOverride",&DAT_1800d79f0);
    DAT_180102040 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101f70,"getOverrideInterpolate",&DAT_1800d79f0);
    DAT_180102048 = (**(code **)(*param_1 + 0x108))(param_1,DAT_180101f70,"setOverride","(FF)V");
    DAT_180102050 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101f70,"setEnableOverride",&DAT_1800de9e4);
    DAT_180102058 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101f70,"isEnableOverride",&DAT_1800d79c4);
    DAT_180102060 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101f78,"getOverride",&DAT_1800d79c4);
    DAT_180102068 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101f78,"setOverride",&DAT_1800de9e4);
    DAT_180102070 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101f78,"setEnableOverride",&DAT_1800de9e4);
    DAT_180102078 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101f78,"isEnableOverride",&DAT_1800d79c4);
    DAT_180102080 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101f80,"getOverride","()Lzombie/iso/weather/ClimateColorInfo;");
    DAT_180102088 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101f80,"getOverrideInterpolate",&DAT_1800d79f0);
    DAT_180102090 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101f80,"setOverride","(Lzombie/iso/weather/ClimateColorInfo;F)V")
    ;
    DAT_180102098 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101f80,"setEnableOverride",&DAT_1800de9e4);
    DAT_1801020a0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101f80,"isEnableOverride",&DAT_1800d79c4);
    DAT_1801020a8 = (**(code **)(*param_1 + 0x108))(param_1,DAT_180101f88,"<init>","(FFFFFFFF)V");
    DAT_1801020b0 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101f88,"setTo","(Lzombie/iso/weather/ClimateColorInfo;)V");
    DAT_1801020b8 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_180101f90,"getInstance","()Lzombie/characters/IsoPlayer;");
    DAT_1801020c0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101f90,&DAT_1800d79f4,&DAT_1800d79f0);
    DAT_1801020c8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101f90,&DAT_1800d79fc,&DAT_1800d79f0);
    DAT_1801020d0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101f90,&DAT_1800d7a04,&DAT_1800d79f0);
    DAT_1801020d8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101f98,"getCell","()Lzombie/iso/IsoCell;");
    DAT_1801020e0 = (**(code **)(*param_1 + 0x108))(param_1,DAT_180101fa8,"<init>","(IIIFFFI)V");
    DAT_1801020e8 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101fa0,"addLamppost","(Lzombie/iso/IsoLightSource;)V");
    DAT_1801020f0 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101fa0,"removeLamppost","(Lzombie/iso/IsoLightSource;)V");
    DAT_1801020f8 =
         (**(code **)(*param_1 + 0x480))(param_1,DAT_180101fb0,"visionConeLerp",&DAT_1800d8084);
    if ((((DAT_180101fe0 == 0) || (DAT_180101fe8 == 0)) || (DAT_180101ff0 == 0)) ||
       (DAT_180101ff8 == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    plVar2 = &DAT_180101fb8;
    do {
      if ((bVar1) && (*plVar2 != 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      plVar2 = plVar2 + 1;
    } while (plVar2 != &DAT_180101fe0);
    uVar3 = (**(code **)(*param_1 + 0x720))(param_1);
    if ((char)uVar3 == '\0') {
      if ((((((bVar1) && (DAT_180102000 != 0)) &&
            ((DAT_180102008 != 0 &&
             (((((DAT_180102010 != 0 && (DAT_180102018 != 0)) && (DAT_180102020 != 0)) &&
               ((DAT_180102028 != 0 && (DAT_180102030 != 0)))) && (DAT_180102038 != 0)))))) &&
           (((DAT_180102040 != 0 && (DAT_180102048 != 0)) &&
            ((DAT_180102050 != 0 &&
             (((((DAT_180102058 != 0 && (DAT_180102060 != 0)) && (DAT_180102068 != 0)) &&
               (((DAT_180102070 != 0 && (DAT_180102078 != 0)) &&
                ((DAT_180102080 != 0 && ((DAT_180102088 != 0 && (DAT_180102090 != 0)))))))) &&
              (DAT_180102098 != 0)))))))) &&
          (((DAT_1801020a0 != 0 && (DAT_1801020a8 != 0)) && (DAT_1801020b0 != 0)))) &&
         (((DAT_1801020b8 != 0 && (DAT_1801020c0 != 0)) &&
          ((((DAT_1801020c8 != 0 && ((DAT_1801020d0 != 0 && (DAT_1801020d8 != 0)))) &&
            (DAT_1801020e0 != 0)) &&
           (((DAT_1801020e8 != 0 && (DAT_1801020f0 != 0)) && (DAT_1801020f8 != 0)))))))) {
        DAT_180101f60 = 1;
        return CONCAT71((int7)(uVar3 >> 8),1);
      }
    }
    else {
      uVar3 = (**(code **)(*param_1 + 0x88))(param_1);
    }
    DAT_180101f60 = 0;
    return uVar3 & 0xffffffffffffff00;
  }
  return DAT_180101fb0 & 0xffffffffffffff00;
}

