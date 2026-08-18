require "ISUI/ISPanel"
require "ISUI/ISComboBox"

EtherAimPanel = ISPanel:derive("EtherAimPanel")

function EtherAimPanel:createChildren()
    ISPanel.createChildren(self)

    local title = ISLabel:new(15, 15, 24, getTranslate("UI_AimPanel_Title"), 1, 1, 1, 1, UIFont.Medium, true)
    title:initialise();
    self:addChild(title)

    self.enabled = UICheckbox:new(15, 55, getTranslate("UI_AimPanel_Enabled"), isAutoAimEnabled(), function(isChecked)
        toggleAutoAim(isChecked)
    end)
    self.enabled:initialise();
    self:addChild(self.enabled)

    local modeLabel = ISLabel:new(15, 95, 24, getTranslate("UI_AimPanel_Mode"), 1, 1, 1, 1, UIFont.Small, true)
    modeLabel:initialise();
    self:addChild(modeLabel)

    self.mode = ISComboBox:new(180, 91, 260, 26, self, EtherAimPanel.onModeChanged)
    self.mode:initialise()
    self.mode:addOptionWithData(getTranslate("UI_AimPanel_ModeTraditional"), "traditional")
    self.mode:addOptionWithData(getTranslate("UI_AimPanel_ModeBullet"), "bullet")
    self.mode:setSelectedData(getAutoAimMode())
    self:addChild(self.mode)

    self.showTarget = UICheckbox:new(15, 135, getTranslate("UI_AimPanel_ShowTarget"), isAutoAimShowTarget(), function(isChecked)
        toggleAutoAimShowTarget(isChecked)
    end)
    self.showTarget:initialise();
    self:addChild(self.showTarget)

    self.instantKill = UICheckbox:new(15, 175, getTranslate("UI_AimPanel_InstantKill"), isExtraDamage(), function(isChecked)
        toggleExtraDamage(isChecked)
        if not isChecked then resetWeaponsStats() end
    end)
    self.instantKill:initialise();
    self:addChild(self.instantKill)

    self.unlimitedAmmo = UICheckbox:new(15, 215, getTranslate("UI_AimPanel_UnlimitedAmmo"), isUnlimitedAmmo(), function(isChecked)
        toggleUnlimitedAmmo(isChecked)
    end)
    self.unlimitedAmmo:initialise();
    self:addChild(self.unlimitedAmmo)

    self.noRecoil = UICheckbox:new(15, 255, getTranslate("UI_AimPanel_NoRecoil"), isNoRecoil(), function(isChecked)
        toggleNoRecoil(isChecked)
    end)
    self.noRecoil:initialise();
    self:addChild(self.noRecoil)

    self.noSpread = UICheckbox:new(15, 295, getTranslate("UI_AimPanel_NoSpread"), isNoSpread(), function(isChecked)
        toggleNoSpread(isChecked)
    end)
    self.noSpread:initialise();
    self:addChild(self.noSpread)

    local label = ISLabel:new(15, 340, 24, getTranslate("UI_AimPanel_TargetPart"), 1, 1, 1, 1, UIFont.Small, true)
    label:initialise();
    self:addChild(label)

    self.targetPart = ISComboBox:new(180, 336, 260, 26, self, EtherAimPanel.onPartChanged)
    self.targetPart:initialise();
    self.targetPart:addOptionWithData(getTranslate("UI_AimPanel_Head"), "head")
    self.targetPart:addOptionWithData(getTranslate("UI_AimPanel_Torso"), "torso")
    self.targetPart:addOptionWithData(getTranslate("UI_AimPanel_Legs"), "legs")
    self.targetPart:setSelectedData(getAutoAimTargetPart())
    self:addChild(self.targetPart)

    self.lockedTarget = ISLabel:new(15, 385, 24, "", 1, 1, 1, 1, UIFont.Small, true)
    self.lockedTarget:initialise();
    self:addChild(self.lockedTarget)
end

function EtherAimPanel.onPartChanged(target, combo)
    setAutoAimTargetPart(combo:getSelectedData())
end

function EtherAimPanel.onModeChanged(target, combo)
    setAutoAimMode(combo:getSelectedData())
end

function EtherAimPanel:update()
    if self.lockedTarget ~= nil then
        local target = getAutoAimLockedTarget()
        self.lockedTarget:setName(getTranslate("UI_AimPanel_LockedTarget") .. ": " .. (target == "" and getTranslate("UI_AimPanel_None") or target))
    end
end

function EtherAimPanel:new(posX, posY, width, height)
    local panel = ISPanel:new(posX, posY, width, height)
    setmetatable(panel, self)
    self.__index = self
    panel.background = false
    panel.moveWithMouse = false
    return panel
end
