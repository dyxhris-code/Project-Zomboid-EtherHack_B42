require "ISUI/ISPanel"

EtherItemCreator = ISPanel:derive("EtherItemCreator")

local function sortedKeys(map)
    local keys = {}
    for key, _ in pairs(map) do table.insert(keys, key) end
    table.sort(keys, function(a, b) return a < b end)
    return keys
end

local function setupIndexList(list, target, callback)
    list:initialise()
    list:instantiate()
    list.itemheight = getTextManager():getFontHeight(UIFont.Small) + 10
    list.font = UIFont.Small
    list.selected = 0
    list.drawBorder = true
    list.target = target
    list.onmousedown = callback
end

function EtherItemCreator:createChildren()
    ISPanel.createChildren(self)
    if self.localPlayer == nil then return end

    self.moduleTitle = ISLabel:new(0, 0, 24, getTranslate("UI_ItemCreator_Modules"), 1, 1, 1, 1, UIFont.Small, true)
    self.moduleTitle:initialise(); self:addChild(self.moduleTitle)
    self.categoryTitle = ISLabel:new(0, 0, 24, getTranslate("UI_ItemCreator_Categories"), 1, 1, 1, 1, UIFont.Small, true)
    self.categoryTitle:initialise(); self:addChild(self.categoryTitle)
    self.itemTitle = ISLabel:new(0, 0, 24, getTranslate("UI_Navigation_Items"), 1, 1, 1, 1, UIFont.Small, true)
    self.itemTitle:initialise(); self:addChild(self.itemTitle)

    self.moduleList = ISScrollingListBox:new(0, 0, 120, 100)
    setupIndexList(self.moduleList, self, EtherItemCreator.onModuleSelected)
    self:addChild(self.moduleList)

    self.categoryList = ISScrollingListBox:new(0, 0, 150, 100)
    setupIndexList(self.categoryList, self, EtherItemCreator.onCategorySelected)
    self:addChild(self.categoryList)

    self.itemTable = UIItemTables:new(0, 0, 300, 100)
    self.itemTable:initialise()
    self:addChild(self.itemTable)

    self:loadItems()
    self:populateModules()
    self:layoutChildren()
end

function EtherItemCreator:loadItems()
    self.itemsByModule = {}
    local allItems = getAllItems()
    for i = 0, allItems:size() - 1 do
        local item = allItems:get(i)
        if not item:getObsolete() and not item:isHidden() and item:getModuleName() ~= "Moveables" then
            local moduleName = item:getModuleName()
            local categoryName = item:getDisplayCategory() or getTranslate("UI_ItemCreator_Other")
            self.itemsByModule[moduleName] = self.itemsByModule[moduleName] or {}
            self.itemsByModule[moduleName][categoryName] = self.itemsByModule[moduleName][categoryName] or {}
            table.insert(self.itemsByModule[moduleName][categoryName], item)
        end
    end
end

function EtherItemCreator:populateModules()
    self.moduleList:clear()
    for _, moduleName in ipairs(sortedKeys(self.itemsByModule)) do
        self.moduleList:addItem(moduleName, {name = moduleName})
    end
    if #self.moduleList.items > 0 then
        self.moduleList.selected = 1
        self:onModuleSelected(self.moduleList.items[1].item)
    end
end

function EtherItemCreator:onModuleSelected(moduleEntry)
    if moduleEntry == nil then return end
    self.selectedModule = moduleEntry.name
    self.categoryList:clear()
    for _, categoryName in ipairs(sortedKeys(self.itemsByModule[self.selectedModule])) do
        self.categoryList:addItem(categoryName, {name = categoryName})
    end
    if #self.categoryList.items > 0 then
        self.categoryList.selected = 1
        self:onCategorySelected(self.categoryList.items[1].item)
    else
        self.itemTable:initList({})
    end
end

function EtherItemCreator:onCategorySelected(categoryEntry)
    if categoryEntry == nil or self.selectedModule == nil then return end
    self.selectedCategory = categoryEntry.name
    self.itemTable:initList(self.itemsByModule[self.selectedModule][self.selectedCategory])
end

function EtherItemCreator:layoutChildren()
    if self.moduleList == nil then return end
    local gap = 8
    local titleHeight = 24
    local contentHeight = math.max(100, self.height - titleHeight - gap)
    local moduleWidth = math.max(150, math.min(220, math.floor(self.width * 0.22)))
    local categoryWidth = math.max(180, math.min(250, math.floor(self.width * 0.24)))
    local itemX = moduleWidth + categoryWidth + gap * 2
    local itemWidth = math.max(360, self.width - itemX)

    self.moduleTitle:setX(0); self.moduleTitle:setY(0)
    self.categoryTitle:setX(moduleWidth + gap); self.categoryTitle:setY(0)
    self.itemTitle:setX(itemX); self.itemTitle:setY(0)

    self.moduleList:setX(0); self.moduleList:setY(titleHeight)
    self.moduleList:setWidth(moduleWidth); self.moduleList:setHeight(contentHeight)
    self.categoryList:setX(moduleWidth + gap); self.categoryList:setY(titleHeight)
    self.categoryList:setWidth(categoryWidth); self.categoryList:setHeight(contentHeight)
    self.itemTable:setX(itemX); self.itemTable:setY(titleHeight)
    self.itemTable:setWidth(itemWidth); self.itemTable:setHeight(contentHeight)
    self.itemTable:onResize()
end

function EtherItemCreator:onResize(width, height)
    ISPanel.onResize(self, width, height)
    self:layoutChildren()
end

function EtherItemCreator:render()
    ISPanel.render(self)
    if self.localPlayer == nil then
        self:drawTextCentre(self.workInGameText, self.width / 2, self.height / 2, 1, 1, 1, 1, UIFont.Large)
    end
end

function EtherItemCreator:new(posX, posY, width, height)
    local panel = ISPanel:new(posX, posY, width, height)
    setmetatable(panel, self)
    self.__index = self
    panel.background = false
    panel.moveWithMouse = false
    panel.workInGameText = getTranslate("UI_ItemCreator_PanelWorkOnlyInGame")
    panel.localPlayer = getPlayer()
    return panel
end
