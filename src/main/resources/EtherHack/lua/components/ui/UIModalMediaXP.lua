require "ISUI/ISPanel"

UIModalMediaXP = ISPanel:derive("UIModalMediaXP")
UIModalMediaXP.instance = nil

local function sortedPerks()
    local perks = {}
    for i = 1, Perks.getMaxIndex() do
        local perk = PerkFactory.getPerk(Perks.fromIndex(i - 1))
        if perk ~= nil and perk:getParent() ~= Perks.None then
            table.insert(perks, perk)
        end
    end
    table.sort(perks, function(a, b) return string.lower(a:getName()) < string.lower(b:getName()) end)
    return perks
end

function UIModalMediaXP:close()
    self:setVisible(false)
    self:removeFromUIManager()
    UIModalMediaXP.instance = nil
end

function UIModalMediaXP:togglePerk(perk)
    if perk == nil then return end
    local key = tostring(perk:getType())
    self.selectedPerks[key] = not self.selectedPerks[key]
    self.perkList.selected = 0
end

function UIModalMediaXP:drawPerkRow(y, item, alt)
    local modal = self.modal
    local perk = item.item
    local selected = modal.selectedPerks[tostring(perk:getType())] == true
    local rowHeight = self.itemheight
    if alt then
        self:drawRect(0, y, self.width, rowHeight, 0.16, 0.35, 0.35, 0.38)
    end
    if selected then
        self:drawRect(0, y, self.width, rowHeight, 0.35,
            EtherMain.accentColor.r, EtherMain.accentColor.g, EtherMain.accentColor.b)
    end
    self:drawRectBorder(0, y, self.width, rowHeight, 0.8,
        UITheme.colors.border.r, UITheme.colors.border.g, UITheme.colors.border.b)
    local mark = selected and "[x]" or "[ ]"
    self:drawText(mark .. " " .. perk:getName(), 8, y + 5,
        UITheme.colors.text.r, UITheme.colors.text.g, UITheme.colors.text.b, 1, self.font)
    return y + rowHeight
end

function UIModalMediaXP:createChildren()
    ISPanel.createChildren(self)

    self.selectedPerks = {}
    self.skillLabel = ISLabel:new(14, 10, 24, getTranslate("UI_PlayerEditor_PlayerSkills_MediaXPSelectSkills"),
        1, 1, 1, 1, UIFont.Small, true)
    self.skillLabel:initialise(); self:addChild(self.skillLabel)

    self.perkList = ISScrollingListBox:new(14, 38, self.width - 28, 292)
    self.perkList:initialise(); self.perkList:instantiate()
    self.perkList.itemheight = getTextManager():getFontHeight(UIFont.Small) + 12
    self.perkList.font = UIFont.Small
    self.perkList.modal = self
    self.perkList.drawBorder = true
    self.perkList.doDrawItem = self.drawPerkRow
    self.perkList.backgroundColor = UITheme.colors.surface
    self.perkList.target = self
    self.perkList.onmousedown = function(target, item)
        local perk = item and (item.item or item) or nil
        target:togglePerk(perk)
    end
    self:addChild(self.perkList)

    self.perks = sortedPerks()
    for _, perk in ipairs(self.perks) do
        self.perkList:addItem(perk:getName(), perk)
    end
    local initialPerk = self.perk ~= nil and PerkFactory.getPerk(self.perk) or nil
    if initialPerk ~= nil then
        self.selectedPerks[tostring(initialPerk:getType())] = true
    end

    self.selectAllButton = UIButton:new(14, 338, 120, 26, getTranslate("UI_PlayerEditor_PlayerSkills_MediaXPSelectAll"), function()
        for _, perk in ipairs(self.perks) do self.selectedPerks[tostring(perk:getType())] = true end
        self.perkList.selected = 0
    end)
    self.selectAllButton:initialise(); self.selectAllButton:instantiate(); self:addChild(self.selectAllButton)

    self.clearButton = UIButton:new(142, 338, 120, 26, getTranslate("UI_PlayerEditor_PlayerSkills_MediaXPClear"), function()
        self.selectedPerks = {}
        self.perkList.selected = 0
    end)
    self.clearButton:initialise(); self.clearButton:instantiate(); self:addChild(self.clearButton)

    self.amountLabel = ISLabel:new(14, 378, 20,
        getTranslate("UI_PlayerEditor_PlayerSkills_MediaXPAmount"), 1, 1, 1, 1, UIFont.Small, true)
    self.amountLabel:initialise(); self:addChild(self.amountLabel)
    self.entry = ISTextEntryBox:new("100", 14, 400, self.width - 28, 26)
    self.entry:initialise(); self.entry:instantiate(); self.entry:setOnlyNumbers(true)
    self:addChild(self.entry)

    self.submitButton = UIButton:new(14, self.height - 36, 210, 26,
        getTranslate("UI_PlayerEditor_PlayerSkills_AddMediaXP"), function()
        local amount = tonumber(self.entry:getText())
        local successCount = 0
        if amount ~= nil and amount > 0 then
            for _, perk in ipairs(self.perks) do
                if self.selectedPerks[tostring(perk:getType())] then
                    if addXpFromNearbyBroadcast(perk:getType(), amount) then
                        successCount = successCount + 1
                    end
                end
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

    self.cancelButton = UIButton:new(self.width - 114, self.height - 36, 100, 26,
        getTranslate("UI_PlayerEditor_PlayerSkills_ModalClose"), function() self:close() end)
    self.cancelButton:initialise(); self.cancelButton:instantiate(); self:addChild(self.cancelButton)
end

function UIModalMediaXP:new(perk)
    local width, height = 520, 470
    local panel = ISPanel:new(getCore():getScreenWidth() / 2 - width / 2,
        getCore():getScreenHeight() / 2 - height / 2, width, height)
    setmetatable(panel, self)
    self.__index = self
    panel.perk = perk
    panel.moveWithMouse = true
    panel.backgroundColor = UITheme.colors.window
    panel.borderColor = UITheme.colors.border
    UIModalMediaXP.instance = panel
    return panel
end
