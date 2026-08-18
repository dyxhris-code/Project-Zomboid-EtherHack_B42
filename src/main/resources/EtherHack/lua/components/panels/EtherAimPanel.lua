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

    self.showTarget = UICheckbox:new(15, 95, getTranslate("UI_AimPanel_ShowTarget"), isAutoAimShowTarget(), function(isChecked)
        toggleAutoAimShowTarget(isChecked)
    end)
    self.showTarget:initialise();
    self:addChild(self.showTarget)

    local label = ISLabel:new(15, 140, 24, getTranslate("UI_AimPanel_TargetPart"), 1, 1, 1, 1, UIFont.Small, true)
    label:initialise();
    self:addChild(label)

    self.targetPart = ISComboBox:new(180, 136, 220, 26, self, EtherAimPanel.onPartChanged)
    self.targetPart:initialise();
    self.targetPart:addOptionWithData(getTranslate("UI_AimPanel_Head"), "head")
    self.targetPart:addOptionWithData(getTranslate("UI_AimPanel_Torso"), "torso")
    self.targetPart:addOptionWithData(getTranslate("UI_AimPanel_Legs"), "legs")
    self.targetPart:setSelectedData(getAutoAimTargetPart())
    self:addChild(self.targetPart)

    self.lockedTarget = ISLabel:new(15, 185, 24, "", 1, 1, 1, 1, UIFont.Small, true)
    self.lockedTarget:initialise();
    self:addChild(self.lockedTarget)
end

function EtherAimPanel.onPartChanged(target, combo)
    setAutoAimTargetPart(combo:getSelectedData())
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
