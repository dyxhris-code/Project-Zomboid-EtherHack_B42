require "ISUI/ISPanel"
require "TimedActions/ISTakeBricks"

--*********************************************************
--* Глобальные установки UI
--*********************************************************
UIItemTables = ISPanel:derive("UIItemTables");

local fontHeightSmall = getTextManager():getFontHeight(UIFont.Small)
local ITEM_GRANT_MODE_LOCAL_NATIVE = "local-native"
local ITEM_GRANT_MODE_ADMIN_COMMAND = "admin-command"
local ITEM_GRANT_MODE_SERVER_WORLD_ACTION = "server-world-action"
local pendingServerGrants = {}

local function findPendingGrantPallet(object)
    if object == nil or not instanceof(object, "IsoTrap") then return nil end

    local carrier = object:getItem()
    if carrier == nil then return nil end
    for _, request in pairs(pendingServerGrants) do
        local carrierIdMatches = request.carrierId >= 0 and carrier:getID() == request.carrierId
        local markerMatches = carrier:getRemoteControlID() == request.marker
            and carrier:getFullType() == request.carrierType
        if carrierIdMatches or markerMatches then
            return request
        end
    end
    return nil
end

local function takePendingServerGrant(pallet)
    local request = findPendingGrantPallet(pallet)
    if request == nil then return end

    pendingServerGrants[request.carrierId] = nil
    local player = request.player
    local itemType = request.itemType
    local count = request.count
    ISTimedActionQueue.add(ISTakeBricks:new(player, pallet, pallet:getSquare(), nil, itemType, count))
end

local function onServerGrantObjectAdded(object)
    takePendingServerGrant(object)
end

Events.OnObjectAdded.Add(onServerGrantObjectAdded)

local function grantItemThroughServerWorldAction(player, itemType, count)
    for _ in pairs(pendingServerGrants) do
        return true
    end

    local square = player:getCurrentSquare()
    if square == nil then return false end

    local pallet = createItemGrantPallet(player)
    if pallet == nil or pallet.carrierId == nil or pallet.carrierType == nil then return false end

    pendingServerGrants[pallet.carrierId] = {
        carrierId = pallet.carrierId,
        carrierType = pallet.carrierType,
        marker = pallet.marker,
        player = player,
        itemType = itemType,
        count = count,
        square = square,
        ticks = 0
    }
    return true
end

local function scanPendingServerGrants(player)
    for carrierId, request in pairs(pendingServerGrants) do
        if request.player == player then
            request.ticks = request.ticks + 1
            local objects = request.square:getObjects()
            for i = 0, objects:size() - 1 do
                takePendingServerGrant(objects:get(i))
                if pendingServerGrants[carrierId] == nil then break end
            end
            if request.ticks > 600 then
                pendingServerGrants[carrierId] = nil
            end
        end
    end
end

Events.OnPlayerUpdate.Add(scanPendingServerGrants)

local function setButtonEnabled(button, enabled)
    if button.setEnabled then
        button:setEnabled(enabled)
    else
        button:setEnable(enabled)
    end
end

local function giveEtherItem(itemType, count)
    local player = getPlayer()
    if player == nil then return end

    local mode = getItemGrantMode()
    if isClient() then
        if mode == ITEM_GRANT_MODE_LOCAL_NATIVE then
            giveItem(itemType, count)
            return
        end

        if mode == ITEM_GRANT_MODE_ADMIN_COMMAND then
            SendCommandToServer("/additem \"" .. player:getUsername() .. "\" \"" .. itemType .. "\" " .. tostring(count))
            return
        end

        if mode == ITEM_GRANT_MODE_SERVER_WORLD_ACTION then
            if type(createItemGrantPallet) ~= "function" then
                giveItem(itemType, count)
                return
            end
            if not grantItemThroughServerWorldAction(player, itemType, count) then
                giveItem(itemType, count)
            end
            return
        end

        giveItem(itemType, count)
        return
    end

    giveItem(itemType, count)
end

--*********************************************************
--* Обработка render
--*********************************************************
function UIItemTables:render()
    ISPanel.render(self);
    
    local y = self.datas.y + self.datas.height + 5
    self:drawText(getText("IGUI_DbViewer_TotalResult") .. self.totalResult, 0, y, 1,1,1,1,UIFont.Small)
end

function UIItemTables:onResize()
    ISPanel.onResize(self);
    if self.filterByName == nil or self.filterById == nil then return end;

    local halfWidth = math.floor(self.width / 2);
    local listHeight = math.max(80, self.height - 150)
    local actionY = self.height - 80
    local labelY = self.height - 40
    local filterY = self.height - 20
    local gap = 6
    local buttonWidth = math.floor((self.width - gap * 3) / 4)

    self.datas:setWidth(self.width)
    self.datas:setHeight(listHeight)
    self.addItemX1:setX(0); self.addItemX1:setY(actionY); self.addItemX1:setWidth(buttonWidth)
    self.addItemX2:setX(buttonWidth + gap); self.addItemX2:setY(actionY); self.addItemX2:setWidth(buttonWidth)
    self.addItemX5:setX((buttonWidth + gap) * 2); self.addItemX5:setY(actionY); self.addItemX5:setWidth(buttonWidth)
    self.addItemX10:setX((buttonWidth + gap) * 3); self.addItemX10:setY(actionY); self.addItemX10:setWidth(buttonWidth)
    self.filterByNameTitle:setY(labelY)
    self.filterByName:setWidth(halfWidth - 10);
    self.filterByName:setY(filterY)
    self.filterByIdTitle:setX(halfWidth);
    self.filterByIdTitle:setY(labelY)
    self.filterById:setX(halfWidth);
    self.filterById:setY(filterY)
    self.filterById:setWidth(halfWidth);
end

function UIItemTables:getSelectedItem()
    if self.datas == nil or self.datas.selected == nil or self.datas.selected < 1 then return nil end

    local selectedRow = self.datas.items[self.datas.selected]
    if selectedRow == nil then return nil end
    return selectedRow.item
end

--*********************************************************
--* Создание дочерних элементов
--*********************************************************
function UIItemTables:createChildren()
    ISPanel.createChildren(self);

    self.datas = ISScrollingListBox:new(0, 25, self.width, self.height - 150);
    self.datas:initialise();
    self.datas:instantiate();
    self.datas:setAnchorLeft(true);
    self.datas:setAnchorRight(true);
    self.datas:setAnchorTop(true);
    self.datas:setAnchorBottom(true);
    self.datas.itemheight = fontHeightSmall + 4 * 2
    self.datas.selected = 0;
    self.datas.joypadParent = self;
    self.datas.font = UIFont.NewSmall;
    self.datas.doDrawItem = self.drawDatas;
    self.datas.drawBorder = true;
    self.datas:addColumn(getTranslate("UI_ItemCreator_Title_ItemName"), 0);
    self.datas:addColumn(getTranslate("UI_ItemCreator_Title_ItemCategory"), 250)
    self:addChild(self.datas);

    self.filterByNameTitle = ISLabel:new(0, self.height - 40, 20, getTranslate("UI_ItemCreator_Title_FilterByName"), 1, 1, 1, 1, UIFont.Medium, true)
    self.filterByNameTitle:initialise()
    self.filterByNameTitle:instantiate()
    self.filterByNameTitle:setAnchorTop(false)
    self.filterByNameTitle:setAnchorBottom(true)
    self:addChild(self.filterByNameTitle)

    self.filterByName = ISTextEntryBox:new("", 0, self.height - 20, self.width / 2 - 10, 20);
    self.filterByName.font = UIFont.Small;
    self.filterByName:initialise();
    self.filterByName:instantiate();
    self.filterByName:setAnchorTop(false)
    self.filterByName:setAnchorBottom(true)
    self.filterByName.target = self;
    self.filterByName.itemsListFilter = self.filterName;
    self.filterByName.onTextChange = UIItemTables.onFilterChange;
    self.filterByName:setClearButton(true)
    self:addChild(self.filterByName);
    table.insert(self.filterWidgets, self.filterByName);

    self.filterByIdTitle = ISLabel:new(self.width / 2, self.height - 40, 20, getTranslate("UI_ItemCreator_Title_FilterById"), 1, 1, 1, 1, UIFont.Medium, true)
    self.filterByIdTitle:initialise()
    self.filterByIdTitle:instantiate()
    self.filterByIdTitle:setAnchorTop(false)
    self.filterByIdTitle:setAnchorBottom(true)
    self:addChild(self.filterByIdTitle)

    self.filterById = ISTextEntryBox:new("", self.width / 2, self.height - 20, self.width / 2, 20);
    self.filterById.font = UIFont.Small;
    self.filterById:initialise();
    self.filterById:instantiate();
    self.filterById:setAnchorTop(false)
    self.filterById:setAnchorBottom(true)
    self.filterById:setClearButton(true)
    self.filterById.target = self;
    self.filterById.itemsListFilter = self.filterType;
    self.filterById.onTextChange = UIItemTables.onFilterChange;
    self:addChild(self.filterById);
    table.insert(self.filterWidgets, self.filterById);

    self.addItemX1 = UIButton:new(0, self.height - 80, 100, 24, getTranslate("UI_ItemCreator_Button_AddItemX1"), 
    function() 
        local selectedItem = self:getSelectedItem()
        if selectedItem == nil then return end
        giveEtherItem(selectedItem:getFullName(), 1);
    end)
    self.addItemX1:initialise();
    self.addItemX1:instantiate();
    self.addItemX1:setAnchorLeft(true);
    self.addItemX1:setAnchorRight(false);
    self.addItemX1:setAnchorTop(false);
    self.addItemX1:setAnchorBottom(true);
    self.addItemX1.isOnlyInGame = true;
    self:addChild(self.addItemX1);
    table.insert(self.buttonList, self.addItemX1);

    self.addItemX2 = UIButton:new(self.addItemX1:getX() + self.addItemX1.width + 10, self.height - 80, 100, 24, getTranslate("UI_ItemCreator_Button_AddItemX2"), 
    function() 
        local selectedItem = self:getSelectedItem()
        if selectedItem == nil then return end
        giveEtherItem(selectedItem:getFullName(), 2);
    end)
    self.addItemX2:initialise();
    self.addItemX2:instantiate();
    self.addItemX2:setAnchorLeft(true);
    self.addItemX2:setAnchorRight(false);
    self.addItemX2:setAnchorTop(false);
    self.addItemX2:setAnchorBottom(true);
    self.addItemX2.isOnlyInGame = true;
    self:addChild(self.addItemX2);
    table.insert(self.buttonList, self.addItemX2);

    self.addItemX5 = UIButton:new(self.addItemX2:getX() + self.addItemX2.width + 10, self.height - 80, 100, 24, getTranslate("UI_ItemCreator_Button_AddItemX5"), 
    function() 
        local selectedItem = self:getSelectedItem()
        if selectedItem == nil then return end
        giveEtherItem(selectedItem:getFullName(), 5);
    end)
    self.addItemX5:initialise();
    self.addItemX5:instantiate();
    self.addItemX5:setAnchorLeft(true);
    self.addItemX5:setAnchorRight(false);
    self.addItemX5:setAnchorTop(false);
    self.addItemX5:setAnchorBottom(true);
    self.addItemX5.isOnlyInGame = true;
    self:addChild(self.addItemX5);
    table.insert(self.buttonList, self.addItemX5);

    self.addItemX10 = UIButton:new(self.addItemX5:getX() + self.addItemX5.width + 10, self.height - 80, 100, 24, getTranslate("UI_ItemCreator_Button_AddItemX10"), 
    function() 
        local selectedItem = self:getSelectedItem()
        if selectedItem == nil then return end
        giveEtherItem(selectedItem:getFullName(), 10);
    end)
    self.addItemX10:initialise();
    self.addItemX10:instantiate();
    self.addItemX10:setAnchorLeft(true);
    self.addItemX10:setAnchorRight(false);
    self.addItemX10:setAnchorTop(false);
    self.addItemX10:setAnchorBottom(true);
    self.addItemX10.isOnlyInGame = true;
    self:addChild(self.addItemX10);
    table.insert(self.buttonList, self.addItemX10);

    self:updatePanel();
end

--*********************************************************
--* Обновление панели
--*********************************************************
function UIItemTables:updatePanel()
    local player = getPlayer()
    local canGiveItem = player ~= nil and not player:isDead() and self:getSelectedItem() ~= nil
    for i=1, #self.buttonList do
        local button = self.buttonList[i];
        setButtonEnabled(button, not button.isOnlyInGame or canGiveItem)
    end
end


--*********************************************************
--* Инициализация списков
--*********************************************************
function UIItemTables:initList(module)
    self.totalResult = 0;
    self.datas:clear()
    self.datas.fullList = nil
    for _, v in ipairs(module) do
        self.datas:addItem(v:getDisplayName(), v);
        self.totalResult = self.totalResult + 1;
    end
    table.sort(self.datas.items, function(a,b) return not string.sort(a.item:getDisplayName(), b.item:getDisplayName()); end);
    self.datas.selected = 0
    self:updatePanel()
end

--*********************************************************
--* Обновление таблицы
--*********************************************************
function UIItemTables:update()
    self.datas.doDrawItem = self.drawDatas;
    self:updatePanel()
end

--*********************************************************
--* Фильтр по названию
--*********************************************************
function UIItemTables:filterName(widget, scriptItem)
    local txtToCheck = string.lower(scriptItem:getDisplayName())
    local filterTxt = string.lower(widget:getInternalText())
    return checkStringPattern(filterTxt) and string.match(txtToCheck, filterTxt)
end

--*********************************************************
--* Фильтр по ID
--*********************************************************
function UIItemTables:filterType(widget, scriptItem)
    local txtToCheck = string.lower(scriptItem:getName())
    local filterTxt = string.lower(widget:getInternalText())
    return checkStringPattern(filterTxt) and string.match(txtToCheck, filterTxt)
end

--*********************************************************
--* Применение фильтра при написании текста
--*********************************************************
function UIItemTables.onFilterChange(widget)
    local datas = widget.parent.datas;
    if not datas.fullList then datas.fullList = datas.items; end
    widget.parent.totalResult = 0;
    datas:clear();
    for i,v in ipairs(datas.fullList) do -- check every items
        local add = true;
        for j,widget in ipairs(widget.parent.filterWidgets) do -- check every filters
            if not widget.itemsListFilter(self, widget, v.item) then
                add = false
                break
            end
        end
        if add then
            datas:addItem(i, v.item);
            widget.parent.totalResult = widget.parent.totalResult + 1;
        end
    end
end

--*********************************************************
--* Отрисовка данных
--*********************************************************
function UIItemTables:drawDatas(y, item, alt)
    if y + self:getYScroll() + self.itemheight < 0 or y + self:getYScroll() >= self.height then
        return y + self.itemheight
    end
    
    local a = 0.9;

    if self.selected == item.index then
        self:drawRect(0, y, self:getWidth(), self.itemheight, 0.3, EtherMain.accentColor.r, EtherMain.accentColor.g, EtherMain.accentColor.b);
    end

    if alt then
        self:drawRect(0, y, self:getWidth(), self.itemheight, 0.3, 0.3, 0.3, 0.3);
    end

    self:drawRectBorder(0, y, self:getWidth(), self.itemheight, a, self.borderColor.r, self.borderColor.g, self.borderColor.b);

    local iconX = 4
    local iconSize = fontHeightSmall;

    local clipX = self.columns[1].size
    local clipX2 = self.columns[2].size
    local clipY = math.max(0, y + self:getYScroll())
    local clipY2 = math.min(self.height, y + self:getYScroll() + self.itemheight)
    
    self:setStencilRect(clipX, clipY, clipX2 - clipX, clipY2 - clipY)
    self:drawText(item.item:getDisplayName(), 25, y + 4, 1, 1, 1, a, self.font);
    self:clearStencilRect()

    if item.item:getDisplayCategory() ~= nil then
        self:drawText(getText("IGUI_ItemCat_" .. item.item:getDisplayCategory()), self.columns[2].size + 10, y + 4, 1, 1, 1, a, self.font);
    else
        self:drawText("<NONE>", self.columns[2].size + 10, y + 4, 1, 1, 1, a, self.font);
    end
    
    self:repaintStencilRect(0, clipY, self.width - 20, clipY2 - clipY)

    local icon = item.item:getIcon()
    if item.item:getIconsForTexture() and not item.item:getIconsForTexture():isEmpty() then
        icon = item.item:getIconsForTexture():get(0)
    end
    if icon then
        local texture = getTexture("Item_" .. icon)
        if texture then
            self:drawTextureScaledAspect2(texture, self.columns[1].size + iconX, y + (self.itemheight - iconSize) / 2, iconSize, iconSize,  1, 1, 1, 1);
        end
    end
    
    return y + self.itemheight;
end

--*********************************************************
--* Создание нового экземпляра меню
--*********************************************************
function UIItemTables:new (x, y, width, height)
    local menuTableData = ISPanel:new(x, y, width, height);
    setmetatable(menuTableData, self);
    menuTableData.listHeaderColor = {r=0.4, g=0.4, b=0.4, a=0.0};
    menuTableData.borderColor = {r=0.4, g=0.4, b=0.4, a=0};
    menuTableData.backgroundColor = {r=0, g=0, b=0, a=0};
    menuTableData.buttonBorderColor = {r=0.7, g=0.7, b=0.7, a=0.0};
    menuTableData.totalResult = 0;
    menuTableData.filterWidgets = {};
    menuTableData.buttonList = {};
    UIItemTables.instance = menuTableData;
    return menuTableData;
end
