// callconv: rax ms (rcx, rdx, r8, r9, stack);
void fcn.180022ed0 (int64_t arg1) {
        // CALL XREF from fcn.180024860 @ 0x1800249bb(x)
        push (rbx)
        rsp -= 0x20
        v = byte [0x180101f60] - 0 // [0x180101f60:1]=0
        rbx = rcx    // arg1
        if (!v) goto loc_0x180022eea // likely
        return rax;
    loc_0x180022eea:
        // CODE XREF from fcn.180022ed0 @ 0x180022ee0(x)
        rdx = rip + str.zombie_iso_weather_ClimateManager // 0x1800e1c30 // "zombie/iso/weather/ClimateManager"
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_iso_weather_ClimateManager_ClimateFloat // 0x1800e1c58 // "zombie/iso/weather/ClimateManager$ClimateFloat"
        qword [0x180101f68] = rax // [0x180101f68:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_iso_weather_ClimateManager_ClimateBool // 0x1800e1c88 // "zombie/iso/weather/ClimateManager$ClimateBool"
        qword [0x180101f70] = rax // [0x180101f70:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_iso_weather_ClimateManager_ClimateColor // 0x1800e1cb8 // "zombie/iso/weather/ClimateManager$ClimateColor"
        qword [0x180101f78] = rax // [0x180101f78:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_iso_weather_ClimateColorInfo // 0x1800e1ce8 // "zombie/iso/weather/ClimateColorInfo"
        qword [0x180101f80] = rax // [0x180101f80:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_characters_IsoPlayer // 0x1800d74b0 // "zombie/characters/IsoPlayer"
        qword [0x180101f88] = rax // [0x180101f88:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_iso_IsoWorld // 0x1800d7538 // "zombie/iso/IsoWorld"
        qword [0x180101f90] = rax // [0x180101f90:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_iso_IsoCell // 0x1800d7550 // "zombie/iso/IsoCell"
        qword [0x180101f98] = rax // [0x180101f98:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_iso_IsoLightSource // 0x1800e1d10 // "zombie/iso/IsoLightSource"
        qword [0x180101fa0] = rax // [0x180101fa0:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = rip + str.zombie_iso_LightingJNI // 0x1800e1d30 // "zombie/iso/LightingJNI"
        qword [0x180101fa8] = rax // [0x180101fa8:8]=0
        rcx = rbx
        fcn.180009cc0 () // fcn.180009cc0(0x0, 0x0)
        rdx = qword [0x180101f68] // [0x180101f68:8]=0
        qword [0x180101fb0] = rax // [0x180101fb0:8]=0
        v = rdx & rdx
        if (!v) goto loc_0x1800238f3 // likely
        goto loc_0x180022fd3;
    loc_0x1800238f3:
        // XREFS: CODE 0x180022fcd  CODE 0x180022fdb  CODE 0x180022fe9
        // XREFS: CODE 0x180022ff7  CODE 0x180023005  CODE 0x180023013
        // XREFS: CODE 0x180023021  CODE 0x18002302f  CODE 0x18002303d
        // XREFS: CODE 0x180023046
        al = 0
        rsp += 0x20
        rbx = pop ()
        return
        goto loc_0x180022fe1;
    loc_0x180022ee2: // orphan
         al = 1
         rsp += 0x20
         rbx = pop ()
         return

    loc_0x180022fd3: // orphan
         v = qword [0x180101f70] - 0 // [0x180101f70:8]=0
         if (!v) 
         goto loc_0x180022fe1;
    loc_0x180022fe1: // orphan
         v = qword [0x180101f78] - 0 // [0x180101f78:8]=0
         if (!v) 
         goto loc_0x180022fef;
    loc_0x180022fef: // orphan
         v = qword [0x180101f80] - 0 // [0x180101f80:8]=0
         if (!v) 
         goto loc_0x180022ffd;
    loc_0x180022ffd: // orphan
         v = qword [0x180101f88] - 0 // [0x180101f88:8]=0
         if (!v) 
         goto loc_0x18002300b;
    loc_0x18002300b: // orphan
         v = qword [0x180101f90] - 0 // [0x180101f90:8]=0
         if (!v) 
         goto loc_0x180023019;
    loc_0x180023019: // orphan
         v = qword [0x180101f98] - 0 // [0x180101f98:8]=0
         if (!v) 
         goto loc_0x180023027;
    loc_0x180023027: // orphan
         v = qword [0x180101fa0] - 0 // [0x180101fa0:8]=0
         if (!v) 
         goto loc_0x180023035;
    loc_0x180023035: // orphan
         v = qword [0x180101fa8] - 0 // [0x180101fa8:8]=0
         if (!v) 
         goto loc_0x180023043;
    loc_0x180023043: // orphan
         v = rax & rax
         if (!v) 
         goto loc_0x18002304c;
    loc_0x18002304c: // orphan
         rax = qword [rbx]
         r9 = rip + 0xbed6a       // "I" // 0x1800e1dc0
         r8 = rip + str.FLOAT_DESATURATION // 0x1800e1d48 // "FLOAT_DESATURATION"
         qword [var_38h] = rdi
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f68] // [0x180101f68:8]=0
         r9 = rip + 0xbed47       // "I" // 0x1800e1dc0
         qword [0x180101fb8] = rax // [0x180101fb8:8]=0
         r8 = rip + str.FLOAT_GLOBAL_LIGHT_INTENSITY // 0x1800e1d60 // "FLOAT_GLOBAL_LIGHT_INTENSITY"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f68] // [0x180101f68:8]=0
         r9 = rip + 0xbed1f       // "I" // 0x1800e1dc0
         qword [0x180101fc0] = rax // [0x180101fc0:8]=0
         r8 = rip + str.FLOAT_NIGHT_STRENGTH // 0x1800e1d80 // "FLOAT_NIGHT_STRENGTH"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f68] // [0x180101f68:8]=0
         r9 = rip + 0xbecf7       // "I" // 0x1800e1dc0
         qword [0x180101fc8] = rax // [0x180101fc8:8]=0
         r8 = rip + str.FLOAT_AMBIENT // 0x1800e1d98 // "FLOAT_AMBIENT"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f68] // [0x180101f68:8]=0
         r9 = rip + 0xbeccf       // "I" // 0x1800e1dc0
         qword [0x180101fd0] = rax // [0x180101fd0:8]=0
         r8 = rip + str.FLOAT_DAYLIGHT_STRENGTH // 0x1800e1da8 // "FLOAT_DAYLIGHT_STRENGTH"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f68] // [0x180101f68:8]=0
         r9 = rip + 0xbeca7       // "I" // 0x1800e1dc0
         qword [0x180101fd8] = rax // [0x180101fd8:8]=0
         r8 = rip + str.COLOR_GLOBAL_LIGHT // 0x1800e1dc8 // "COLOR_GLOBAL_LIGHT"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f68] // [0x180101f68:8]=0
         r9 = rip + 0xbec7f       // "I" // 0x1800e1dc0
         qword [0x180101fe0] = rax // [0x180101fe0:8]=0
         r8 = rip + str.FLOAT_FOG_INTENSITY // 0x1800e1de0 // "FLOAT_FOG_INTENSITY"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f68] // [0x180101f68:8]=0
         r9 = rip + 0xbec57       // "I" // 0x1800e1dc0
         qword [0x180101fe8] = rax // [0x180101fe8:8]=0
         r8 = rip + str.FLOAT_PRECIPITATION_INTENSITY // 0x1800e1df8 // "FLOAT_PRECIPITATION_INTENSITY"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f68] // [0x180101f68:8]=0
         r9 = rip + 0xbec2f       // "I" // 0x1800e1dc0
         qword [0x180101ff0] = rax // [0x180101ff0:8]=0
         r8 = rip + str.BOOL_IS_SNOW // 0x1800e1e18 // "BOOL_IS_SNOW"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f70] // [0x180101f70:8]=0
         r9 = rip + 0xb46d3       // "Z" // 0x1800d788c
         qword [0x180101ff8] = rax // [0x180101ff8:8]=0
         r8 = rip + str.isOverrideValue // 0x1800e1e28 // "isOverrideValue"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x2f0] ()   // 752 // 0x2f0(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f70] // [0x180101f70:8]=0
         r9 = rip + str.Fxyz      // 0x1800d8084 // "Fxyz"
         qword [0x180102000] = rax // [0x180102000:8]=0
         r8 = rip + str.overrideInternal // 0x1800e1e38 // "overrideInternal"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x2f0] ()   // 752 // 0x2f0(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f98] // [0x180101f98:8]=0
         r9 = rip + str.Lzombie_iso_IsoWorld_ // 0x1800d78a0 // "Lzombie/iso/IsoWorld;"
         qword [0x180102008] = rax // [0x180102008:8]=0
         r8 = rip + str.instance  // 0x1800d78b8 // "instance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f68] // [0x180101f68:8]=0
         r9 = rip + str.__Lzombie_iso_weather_ClimateManager_ // 0x1800e1e50 // "()Lzombie/iso/weather/ClimateManager;"
         qword [0x180102010] = rax // [0x180102010:8]=0
         r8 = rip + str.getInstance // 0x1800d78e8 // "getInstance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f68] // [0x180101f68:8]=0
         r9 = rip + str._I_Lzombie_iso_weather_ClimateManager_ClimateFloat_ // 0x1800e1e78 // "(I)Lzombie/iso/weather/ClimateManager$ClimateFloat;"
         qword [0x180102018] = rax // [0x180102018:8]=0
         r8 = rip + str.getClimateFloat // 0x1800e1eb0 // "getClimateFloat"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f68] // [0x180101f68:8]=0
         r9 = rip + str._I_Lzombie_iso_weather_ClimateManager_ClimateColor_ // 0x1800e1ec0 // "(I)Lzombie/iso/weather/ClimateManager$ClimateColor;"
         qword [0x180102020] = rax // [0x180102020:8]=0
         r8 = rip + str.getClimateColor // 0x1800e1ef8 // "getClimateColor"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f68] // [0x180101f68:8]=0
         r9 = rip + str._I_Lzombie_iso_weather_ClimateManager_ClimateBool_ // 0x1800e1f08 // "(I)Lzombie/iso/weather/ClimateManager$ClimateBool;"
         qword [0x180102028] = rax // [0x180102028:8]=0
         r8 = rip + str.getClimateBool // 0x1800e1f40 // "getClimateBool"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f70] // [0x180101f70:8]=0
         r9 = rip + 0xb471f       // "()F" // 0x1800d79f0
         qword [0x180102030] = rax // [0x180102030:8]=0
         r8 = rip + str.getOverride // 0x1800e1f50 // "getOverride"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f70] // [0x180101f70:8]=0
         r9 = rip + 0xb46f7       // "()F" // 0x1800d79f0
         qword [0x180102038] = rax // [0x180102038:8]=0
         r8 = rip + str.getOverrideInterpolate // 0x1800e1f60 // "getOverrideInterpolate"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f70] // [0x180101f70:8]=0
         r9 = rip + str._FF_V     // 0x1800e1f78 // "(FF)V"
         qword [0x180102040] = rax // [0x180102040:8]=0
         r8 = rip + str.setOverride // 0x1800e1f80 // "setOverride"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f70] // [0x180101f70:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         qword [0x180102048] = rax // [0x180102048:8]=0
         r8 = rip + str.setEnableOverride // 0x1800e1f90 // "setEnableOverride"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f70] // [0x180101f70:8]=0
         r9 = rip + 0xb4653       // "()Z" // 0x1800d79c4
         qword [0x180102050] = rax // [0x180102050:8]=0
         r8 = rip + str.isEnableOverride // 0x1800e1fa8 // "isEnableOverride"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f78] // [0x180101f78:8]=0
         r9 = rip + 0xb462b       // "()Z" // 0x1800d79c4
         qword [0x180102058] = rax // [0x180102058:8]=0
         r8 = rip + str.getOverride // 0x1800e1f50 // "getOverride"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f78] // [0x180101f78:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         qword [0x180102060] = rax // [0x180102060:8]=0
         r8 = rip + str.setOverride // 0x1800e1f80 // "setOverride"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         qword [0x180102068] = rax // [0x180102068:8]=0
         rax = qword [rbx]
         rdx = qword [0x180101f78] // [0x180101f78:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         r8 = rip + str.setEnableOverride // 0x1800e1f90 // "setEnableOverride"
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f78] // [0x180101f78:8]=0
         r9 = rip + 0xb45b3       // "()Z" // 0x1800d79c4
         qword [0x180102070] = rax // [0x180102070:8]=0
         r8 = rip + str.isEnableOverride // 0x1800e1fa8 // "isEnableOverride"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f80] // [0x180101f80:8]=0
         r9 = rip + str.__Lzombie_iso_weather_ClimateColorInfo_ // 0x1800e1fc0 // "()Lzombie/iso/weather/ClimateColorInfo;"
         qword [0x180102078] = rax // [0x180102078:8]=0
         r8 = rip + str.getOverride // 0x1800e1f50 // "getOverride"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f80] // [0x180101f80:8]=0
         r9 = rip + 0xb458f       // "()F" // 0x1800d79f0
         qword [0x180102080] = rax // [0x180102080:8]=0
         r8 = rip + str.getOverrideInterpolate // 0x1800e1f60 // "getOverrideInterpolate"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f80] // [0x180101f80:8]=0
         r9 = rip + str._Lzombie_iso_weather_ClimateColorInfo_F_V // 0x1800e1fe8 // "(Lzombie/iso/weather/ClimateColorInfo;F)V"
         qword [0x180102088] = rax // [0x180102088:8]=0
         r8 = rip + str.setOverride // 0x1800e1f80 // "setOverride"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f80] // [0x180101f80:8]=0
         r9 = rip + str._Z_V      // 0x1800de9e4 // "(Z)V"
         qword [0x180102090] = rax // [0x180102090:8]=0
         r8 = rip + str.setEnableOverride // 0x1800e1f90 // "setEnableOverride"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f80] // [0x180101f80:8]=0
         r9 = rip + 0xb44eb       // "()Z" // 0x1800d79c4
         qword [0x180102098] = rax // [0x180102098:8]=0
         r8 = rip + str.isEnableOverride // 0x1800e1fa8 // "isEnableOverride"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f88] // [0x180101f88:8]=0
         r9 = rip + str._FFFFFFFF_V // 0x1800e2018 // "(FFFFFFFF)V"
         qword [0x1801020a0] = rax // [0x1801020a0:8]=0
         r8 = rip + str._init_    // 0x1800d807c // "<init>"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f88] // [0x180101f88:8]=0
         r9 = rip + str._Lzombie_iso_weather_ClimateColorInfo__V // 0x1800e2028 // "(Lzombie/iso/weather/ClimateColorInfo;)V"
         qword [0x1801020a8] = rax // [0x1801020a8:8]=0
         r8 = rip + str.setTo     // 0x1800e2054 // "setTo"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f90] // [0x180101f90:8]=0
         r9 = rip + str.__Lzombie_characters_IsoPlayer_ // 0x1800d78c8 // "()Lzombie/characters/IsoPlayer;"
         qword [0x1801020b0] = rax // [0x1801020b0:8]=0
         r8 = rip + str.getInstance // 0x1800d78e8 // "getInstance"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x388] ()   // 904 // 0x388(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f90] // [0x180101f90:8]=0
         r9 = rip + 0xb4477       // "()F" // 0x1800d79f0
         qword [0x1801020b8] = rax // [0x1801020b8:8]=0
         r8 = rip + str.getX      // 0x1800d79f4 // "getX"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f90] // [0x180101f90:8]=0
         r9 = rip + 0xb444f       // "()F" // 0x1800d79f0
         qword [0x1801020c0] = rax // [0x1801020c0:8]=0
         r8 = rip + str.getY      // 0x1800d79fc // "getY"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f90] // [0x180101f90:8]=0
         r9 = rip + 0xb4427       // "()F" // 0x1800d79f0
         qword [0x1801020c8] = rax // [0x1801020c8:8]=0
         r8 = rip + str.getZ      // 0x1800d7a04 // "getZ"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101f98] // [0x180101f98:8]=0
         r9 = rip + str.__Lzombie_iso_IsoCell_ // 0x1800d78f8 // "()Lzombie/iso/IsoCell;"
         qword [0x1801020d0] = rax // [0x1801020d0:8]=0
         r8 = rip + str.getCell   // 0x1800d7910 // "getCell"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101fa8] // [0x180101fa8:8]=0
         r9 = rip + str._IIIFFFI_V // 0x1800e2060 // "(IIIFFFI)V"
         qword [0x1801020d8] = rax // [0x1801020d8:8]=0
         r8 = rip + str._init_    // 0x1800d807c // "<init>"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101fa0] // [0x180101fa0:8]=0
         r9 = rip + str._Lzombie_iso_IsoLightSource__V // 0x1800e2070 // "(Lzombie/iso/IsoLightSource;)V"
         qword [0x1801020e0] = rax // [0x1801020e0:8]=0
         r8 = rip + str.addLamppost // 0x1800e2090 // "addLamppost"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101fa0] // [0x180101fa0:8]=0
         r9 = rip + str._Lzombie_iso_IsoLightSource__V // 0x1800e2070 // "(Lzombie/iso/IsoLightSource;)V"
         qword [0x1801020e8] = rax // [0x1801020e8:8]=0
         r8 = rip + str.removeLamppost // 0x1800e20a0 // "removeLamppost"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x108] ()   // 264 // 0x108(0x0, 0x0, 0x0, 0x0)
         rdx = qword [0x180101fb0] // [0x180101fb0:8]=0
         r9 = rip + str.Fxyz      // 0x1800d8084 // "Fxyz"
         qword [0x1801020f0] = rax // [0x1801020f0:8]=0
         r8 = rip + str.visionConeLerp // 0x1800e20b0 // "visionConeLerp"
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x480] ()   // 1152 // 0x480(0x0, 0x0, 0x0, 0x0)
         v = qword [0x180101fe0] - 0 // [0x180101fe0:8]=-1
         qword [0x1801020f8] = rax // [0x1801020f8:8]=0
         if (!v) 
         goto loc_0x1800236bc;
    loc_0x1800236bc: // orphan
         v = qword [0x180101fe8] - 0 // [0x180101fe8:8]=-1
         if (!v) 
         goto loc_0x1800236c6;
    loc_0x1800236c6: // orphan
         v = qword [0x180101ff0] - 0 // [0x180101ff0:8]=-1
         if (!v) 
         goto loc_0x1800236d0;
    loc_0x1800236d0: // orphan
         v = qword [0x180101ff8] - 0 // [0x180101ff8:8]=-1
         if (!v) 
         goto loc_0x1800236da;
    loc_0x1800236da: // orphan
         dil = 1
         
         goto loc_0x1800236df;
    loc_0x1800236df: // orphan
         // CODE XREFS from fcn.180022ed0 @ 0x1800236ba(x), 0x1800236c4(x), 0x1800236ce(x), 0x1800236d8(x)
         dil = 0

    loc_0x1800236e2: // orphan
         // CODE XREF from fcn.180022ed0 @ 0x1800236dd(x)
         rax = rip + 0xde8cf      // 0x180101fb8
         rcx = rip + 0xde8f0      // 0x180101fe0

    loc_0x1800236f0: // orphan
         // CODE XREF from fcn.180022ed0 @ 0x18002370a(x)
         v = dil & dil
         if (!v) 
         goto loc_0x1800236f5;
    loc_0x1800236f5: // orphan
         v = qword [rax] - 0
         if (!v) 
         goto loc_0x1800236fb;
    loc_0x1800236fb: // orphan
         dil = 1
         
         goto loc_0x180023700;
    loc_0x180023700: // orphan
         // CODE XREFS from fcn.180022ed0 @ 0x1800236f3(x), 0x1800236f9(x)
         dil = 0

    loc_0x180023703: // orphan
         // CODE XREF from fcn.180022ed0 @ 0x1800236fe(x)
         rax += 8
         v = rax - rcx
         if (v) 
         goto loc_0x18002370c;
    loc_0x18002370c: // orphan
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x720] ()   // 1824 // 0x720(0x0, 0x0, 0x0, 0x0)
         v = al & al
         if (v) 
         goto loc_0x180023720;
    loc_0x180023720: // orphan
         v = dil & dil
         if (!v) 
         goto loc_0x180023729;
    loc_0x180023729: // orphan
         v = qword [0x180102000] - 0 // [0x180102000:8]=-1
         if (!v) 
         goto loc_0x180023737;
    loc_0x180023737: // orphan
         v = qword [0x180102008] - 0 // [0x180102008:8]=-1
         if (!v) 
         goto loc_0x180023745;
    loc_0x180023745: // orphan
         v = qword [0x180102010] - 0 // [0x180102010:8]=-1
         if (!v) 
         goto loc_0x180023753;
    loc_0x180023753: // orphan
         v = qword [0x180102018] - 0 // [0x180102018:8]=-1
         if (!v) 
         goto loc_0x180023761;
    loc_0x180023761: // orphan
         v = qword [0x180102020] - 0 // [0x180102020:8]=-1
         if (!v) 
         goto loc_0x18002376f;
    loc_0x18002376f: // orphan
         v = qword [0x180102028] - 0 // [0x180102028:8]=-1
         if (!v) 
         goto loc_0x18002377d;
    loc_0x18002377d: // orphan
         v = qword [0x180102030] - 0 // [0x180102030:8]=-1
         if (!v) 
         goto loc_0x18002378b;
    loc_0x18002378b: // orphan
         v = qword [0x180102038] - 0 // [0x180102038:8]=-1
         if (!v) 
         goto loc_0x180023799;
    loc_0x180023799: // orphan
         v = qword [0x180102040] - 0 // [0x180102040:8]=-1
         if (!v) 
         goto loc_0x1800237a7;
    loc_0x1800237a7: // orphan
         v = qword [0x180102048] - 0 // [0x180102048:8]=-1
         if (!v) 
         goto loc_0x1800237b5;
    loc_0x1800237b5: // orphan
         v = qword [0x180102050] - 0 // [0x180102050:8]=-1
         if (!v) 
         goto loc_0x1800237c3;
    loc_0x1800237c3: // orphan
         v = qword [0x180102058] - 0 // [0x180102058:8]=-1
         if (!v) 
         goto loc_0x1800237d1;
    loc_0x1800237d1: // orphan
         v = qword [0x180102060] - 0 // [0x180102060:8]=-1
         if (!v) 
         goto loc_0x1800237df;
    loc_0x1800237df: // orphan
         v = qword [0x180102068] - 0 // [0x180102068:8]=-1
         if (!v) 
         goto loc_0x1800237ed;
    loc_0x1800237ed: // orphan
         v = qword [0x180102070] - 0 // [0x180102070:8]=-1
         if (!v) 
         goto loc_0x1800237fb;
    loc_0x1800237fb: // orphan
         v = qword [0x180102078] - 0 // [0x180102078:8]=-1
         if (!v) 
         goto loc_0x180023809;
    loc_0x180023809: // orphan
         v = qword [0x180102080] - 0 // [0x180102080:8]=-1
         if (!v) 
         goto loc_0x180023817;
    loc_0x180023817: // orphan
         v = qword [0x180102088] - 0 // [0x180102088:8]=-1
         if (!v) 
         goto loc_0x180023825;
    loc_0x180023825: // orphan
         v = qword [0x180102090] - 0 // [0x180102090:8]=-1
         if (!v) 
         goto loc_0x180023833;
    loc_0x180023833: // orphan
         v = qword [0x180102098] - 0 // [0x180102098:8]=-1
         if (!v) 
         goto loc_0x180023841;
    loc_0x180023841: // orphan
         v = qword [0x1801020a0] - 0 // [0x1801020a0:8]=-1
         if (!v) 
         goto loc_0x18002384f;
    loc_0x18002384f: // orphan
         v = qword [0x1801020a8] - 0 // [0x1801020a8:8]=-1
         if (!v) 
         goto loc_0x18002385d;
    loc_0x18002385d: // orphan
         v = qword [0x1801020b0] - 0 // [0x1801020b0:8]=-1
         if (!v) 
         goto loc_0x180023867;
    loc_0x180023867: // orphan
         v = qword [0x1801020b8] - 0 // [0x1801020b8:8]=-1
         if (!v) 
         goto loc_0x180023871;
    loc_0x180023871: // orphan
         v = qword [0x1801020c0] - 0 // [0x1801020c0:8]=-1
         if (!v) 
         goto loc_0x18002387b;
    loc_0x18002387b: // orphan
         v = qword [0x1801020c8] - 0 // [0x1801020c8:8]=-1
         if (!v) 
         goto loc_0x180023885;
    loc_0x180023885: // orphan
         v = qword [0x1801020d0] - 0 // [0x1801020d0:8]=-1
         if (!v) 
         goto loc_0x18002388f;
    loc_0x18002388f: // orphan
         v = qword [0x1801020d8] - 0 // [0x1801020d8:8]=-1
         if (!v) 
         goto loc_0x180023899;
    loc_0x180023899: // orphan
         v = qword [0x1801020e0] - 0 // [0x1801020e0:8]=-1
         if (!v) 
         goto loc_0x1800238a3;
    loc_0x1800238a3: // orphan
         v = qword [0x1801020e8] - 0 // [0x1801020e8:8]=-1
         if (!v) 
         goto loc_0x1800238ad;
    loc_0x1800238ad: // orphan
         v = qword [0x1801020f0] - 0 // [0x1801020f0:8]=-1
         if (!v) 
         goto loc_0x1800238b7;
    loc_0x1800238b7: // orphan
         v = qword [0x1801020f8] - 0 // [0x1801020f8:8]=-1
         if (!v) 
         return rax;
    loc_0x1800238c1: // orphan
         rdi = qword [var_38h]
         al = 1
         byte [0x180101f60] = al  // [0x180101f60:1]=0
         rsp += 0x20
         rbx = pop ()
         return

    loc_0x1800238d4: // orphan
         // CODE XREF from fcn.180022ed0 @ 0x18002371a(x)
         rax = qword [rbx]
         rcx = rbx
         qword [rax + 0x88] ()    // 136 // 0x88(0x0, 0x0, 0x0, 0x0)

    loc_0x1800238e0: // orphan
         // XREFS(33)
         rdi = qword [var_38h]
         al = 0
         byte [0x180101f60] = al  // [0x180101f60:1]=1
         rsp += 0x20
         rbx = pop ()
         return

}

