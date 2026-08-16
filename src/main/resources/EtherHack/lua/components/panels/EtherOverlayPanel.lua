require "ISUI/ISPanel"

EtherOverlayPanel = ISPanel:derive("EtherOverlayPanel")

function EtherOverlayPanel:prerender()
    self:setStencilRect(0, 0, self:getWidth(), self:getHeight())
    ISPanel.prerender(self)
end

function EtherOverlayPanel:render()
    ISPanel.render(self)
    self:clearStencilRect()

    local player = getPlayer()
    local status = player ~= nil and getTranslate("UI_OverlayPanel_Ready") or getTranslate("UI_OverlayPanel_NoPlayer")
    self:drawText(getTranslate("UI_OverlayPanel_Status") .. ": " .. status, 15, 12, 1, 1, 1, 1, UIFont.Small)
end

function EtherOverlayPanel:addSection(title)
    if self.yRowPosition > 10 then
        self.yRowPosition = self.yRowPosition + 10
    end

    local label = ISLabel:new(15, self.yRowPosition, getTextManager():getFontHeight(UIFont.Medium), title,
        EtherMain.accentColor.r, EtherMain.accentColor.g, EtherMain.accentColor.b, 1, UIFont.Medium, true)
    label:setAnchorLeft(true)
    label:setAnchorRight(false)
    label:setAnchorTop(true)
    label:setAnchorBottom(false)
    self:addChild(label)
    self.yRowPosition = self.yRowPosition + label.height + 8
end

function EtherOverlayPanel:addCheckBox(title, method, selected)
    local checkbox = UICheckbox:new(15, self.yRowPosition, title, selected, method)
    checkbox:initialise()
    checkbox:instantiate()
    checkbox:setAnchorLeft(true)
    checkbox:setAnchorRight(false)
    checkbox:setAnchorTop(true)
    checkbox:setAnchorBottom(false)
    self:addChild(checkbox)
    self.yRowPosition = self.yRowPosition + checkbox.height + 6
    self:setScrollHeight(self.yRowPosition + 12)
end

function EtherOverlayPanel:createChildren()
    ISPanel.createChildren(self)
    self:setScrollChildren(true)
    self:setScrollHeight(0)
    self:addScrollBars()

    self:addSection(getTranslate("UI_OverlaySection_Status"))
    self:addCheckBox(getTranslate("UI_OverlayPanel_Status"), function(isChecked)
        toggleOverlayStatus(isChecked)
    end, isOverlayStatusEnable())
    self:addCheckBox(getTranslate("UI_OverlayPanel_Weapon"), function(isChecked)
        toggleOverlayWeaponInfo(isChecked)
    end, isOverlayWeaponInfo())
    self:addCheckBox(getTranslate("UI_OverlayPanel_Entities"), function(isChecked)
        toggleOverlayEntityCounts(isChecked)
    end, isOverlayEntityCounts())

    self:addSection(getTranslate("UI_OverlaySection_Integration"))
    local note = ISLabel:new(15, self.yRowPosition, getTextManager():getFontHeight(UIFont.Small),
        getTranslate("UI_OverlayPanel_Note"), 1, 1, 1, 0.7, UIFont.Small, true)
    note:setAnchorLeft(true)
    note:setAnchorRight(true)
    note:setAnchorTop(true)
    note:setAnchorBottom(false)
    self:addChild(note)
    self.yRowPosition = self.yRowPosition + note.height + 12
    self:setScrollHeight(self.yRowPosition)
end

function EtherOverlayPanel:new(posX, posY, width, height)
    local panel = ISPanel:new(posX, posY, width, height)
    setmetatable(panel, self)
    self.__index = self
    panel.background = false
    panel.borderColor = {r = 0, g = 0, b = 0, a = 0}
    panel.moveWithMouse = true
    panel.yRowPosition = 38
    return panel
end
