require "ISUI/ISPanel"

UIModalMediaXP = ISPanel:derive("UIModalMediaXP")
UIModalMediaXP.instance = nil

function UIModalMediaXP:close()
    self:setVisible(false)
    self:removeFromUIManager()
    UIModalMediaXP.instance = nil
end

function UIModalMediaXP:createChildren()
    ISPanel.createChildren(self)
    local perkName = PerkFactory.getPerkName(self.perk)
    self.skillLabel = ISLabel:new(10, 10, 24, perkName, 1, 1, 1, 1, UIFont.Small, true)
    self.skillLabel:initialise(); self:addChild(self.skillLabel)

    self.entry = ISTextEntryBox:new("100", 10, 42, self.width - 20, 26)
    self.entry:initialise(); self.entry:instantiate(); self.entry:setOnlyNumbers(true)
    self:addChild(self.entry)

    self.countLabel = ISLabel:new(10, 74, 20, getTranslate("UI_PlayerEditor_PlayerSkills_MediaXPCount"), 1, 1, 1, 1, UIFont.Small, true)
    self.countLabel:initialise(); self:addChild(self.countLabel)
    self.countEntry = ISTextEntryBox:new("1", 10, 96, self.width - 20, 26)
    self.countEntry:initialise(); self.countEntry:instantiate(); self.countEntry:setOnlyNumbers(true)
    self:addChild(self.countEntry)

    self.submitButton = UIButton:new(10, self.height - 36, 160, 26, getTranslate("UI_PlayerEditor_PlayerSkills_AddMediaXP"), function()
        local amount = tonumber(self.entry:getText())
        local count = math.floor(tonumber(self.countEntry:getText()) or 1)
        count = math.max(1, math.min(count, 100))
        local successCount = 0
        if amount ~= nil and amount > 0 then
            for _ = 1, count do
                if not addXpFromNearbyBroadcast(self.perk, amount) then break end
                successCount = successCount + 1
            end
        end
        if successCount > 0 then
            self:close()
            return
        end
        local reason = getMediaXpFailureReason()
        if reason == nil or reason == "" then reason = getTranslate("UI_PlayerEditor_PlayerSkills_MediaXPUnavailable") end
        self.submitButton:setTooltip(reason)
    end)
    self.submitButton:initialise(); self.submitButton:instantiate(); self:addChild(self.submitButton)

    self.cancelButton = UIButton:new(self.width - 110, self.height - 36, 100, 26, getTranslate("UI_PlayerEditor_PlayerSkills_ModalClose"), function()
        self:close()
    end)
    self.cancelButton:initialise(); self.cancelButton:instantiate(); self:addChild(self.cancelButton)
end

function UIModalMediaXP:new(perk)
    local width, height = 340, 180
    local panel = ISPanel:new(getCore():getScreenWidth() / 2 - width / 2, getCore():getScreenHeight() / 2 - height / 2, width, height)
    setmetatable(panel, self)
    self.__index = self
    panel.perk = perk
    panel.moveWithMouse = true
    panel.backgroundColor = UITheme.colors.window
    panel.borderColor = UITheme.colors.border
    UIModalMediaXP.instance = panel
    return panel
end
