require "ISUI/ISPanel"

--*********************************************************
--* Глобальные установки UI
--*********************************************************
UIButtonsPanel = ISPanel:derive("UIButtonsPanel"); -- Наследование от ISPanel

--*********************************************************
--* Prerender
--*********************************************************
function UIButtonsPanel:prerender()
    ISPanel.prerender(self);
    
    for id = 1, #self.buttons do
        local button = self.buttons[id]
        if (button.id == self.currentTabID) then
            local buttonHighlightPosY = button:getY();
            self:drawRect(0, buttonHighlightPosY, 4, button:getHeight(), 1.0, EtherMain.accentColor.r, EtherMain.accentColor.g, EtherMain.accentColor.b);
            button:setTextureRGBA(EtherMain.accentColor.r, EtherMain.accentColor.g, EtherMain.accentColor.b, 1.0)
            button.textColor = {r = EtherMain.accentColor.r, g = EtherMain.accentColor.g, b = EtherMain.accentColor.b, a = 1.0}
        else
            button:setTextureRGBA(1.0, 1.0, 1.0, 1.0)
            button.textColor = UITheme.colors.text
        end
    end
end


--*********************************************************
--* Открытие вкладки по ID
--*********************************************************
function UIButtonsPanel:openPanel(id)
    if #self.buttons <= 0 then return end
    if id == nil or id < 1 or id > #self.buttons then return end

    local panelById = self.buttons[id].panelTag;
    self.currentTabID = id;

    if self.currentPanel ~= nil then
        UITheme.hideTooltips(self.currentPanel);
        self.currentPanel:setVisible(false);
    end

    local panel = self.panels[id];
    if panel == nil then
        panel = panelById:new(self.x + self.width, self.y, self.parent.width - self.x - self.width,
            self.parent.height - self.y);
        panel:initialise();
        panel:instantiate();
        panel:setAnchorLeft(false);
        panel:setAnchorRight(false);
        panel:setAnchorTop(false);
        panel:setAnchorBottom(false);
        self.parent:addChild(panel);
        self.panels[id] = panel;
    end

    self:layoutPanel(panel);
    panel:setVisible(true);
    self.currentPanel = panel;
    EtherMain.currentTabID = id;
    if self.parent.closeButton ~= nil then self.parent.closeButton:bringToTop() end
    if self.parent.resizeWidget ~= nil then self.parent.resizeWidget:bringToTop() end
end

function UIButtonsPanel:layoutPanel(panel)
    if panel == nil then return end
    panel:setX(self.x + self.width)
    panel:setY(self.y)
    local width = self.parent.width - self.x - self.width
    local height = self.parent.height - self.y
    panel:setWidth(width)
    panel:setHeight(height)
    if panel.onResize ~= nil then
        panel:onResize(width, height)
    end
end

function UIButtonsPanel:layoutPanels()
    for _, panel in pairs(self.panels) do
        self:layoutPanel(panel)
    end
end

function UIButtonsPanel:getCurrentTitle()
    local button = self.buttons[self.currentTabID]
    return button ~= nil and button.title or "EtherTrainer"
end

--*********************************************************
--* Обработка нажатий кнопки
--*********************************************************
function UIButtonsPanel:onButtonClick(button)
    self:openPanel(button.id);
end


--*********************************************************
--* Добавление кнопки на панель
--*********************************************************
function UIButtonsPanel:addButton(iconPath, title, tooltip, panelTag)
    local amountButtons = #self.buttons;
    local id = #self.buttons + 1;
    local posY = UITheme.spacing.small + amountButtons * UITheme.metrics.navigationRowHeight;

    local button = ISButton:new(UITheme.spacing.small, posY, self.width - UITheme.spacing.large,
        UITheme.metrics.navigationRowHeight - UITheme.spacing.xsmall, title, self, self.onButtonClick);
    button:setAnchorRight(true);
    button:setAnchorLeft(true);
    button:initialise();
    button.borderColor.a = 0.0;
    button.backgroundColor.a = 0;
    button.backgroundColorMouseOver.a = 0;
    button.id = id;
    button.panelTag = panelTag;
    button.tooltip = tooltip;
    button.iconTexture = getExtraTexture(iconPath);
    button.joypadTextureWH = self.buttonSize.width;
    self:addChild(button);
    button:setVisible(true);

    table.insert( self.buttons, button );
end

--*********************************************************
--* Создание нового экземпляра меню
--*********************************************************
function UIButtonsPanel:new(posX, posY, width, height, parent, accentColor)
    local menuTableData = {};

    menuTableData = ISPanel:new(posX, posY, width, height);
    setmetatable(menuTableData, self);
    menuTableData.background = true;
	menuTableData.backgroundColor = UITheme.colors.surface;
	menuTableData.borderColor = {r=0, g=0, b=0, a=0};
    menuTableData.moveWithMouse = false;
    self.__index = self;

    menuTableData.parent = parent;
    menuTableData.buttons = {};
    menuTableData.panels = {};
    menuTableData.buttonSize = {width = 32, height = 32};
    menuTableData.currentTabID = 1;
    menuTableData.currentPanel = nil;

    return menuTableData;
end
