require "ISUI/ISPanel"
require "ISUI/ISResizeWidget"
require "ISUI/ISLayoutManager"

--*********************************************************
--* Подключение модулей
--*********************************************************
local etherModules = {
    "EtherHack/lua/components/ui/UITheme.lua",
    "EtherHack/lua/components/ui/UISection.lua",
    "EtherHack/lua/components/ui/UIFeedback.lua",
    "EtherHack/lua/components/override/EtherEditInventoryItem.lua",
    "EtherHack/lua/components/override/EtherEditWorldObjects.lua",
    "EtherHack/lua/components/ui/UIButtonsPanel.lua",
    "EtherHack/lua/components/ui/UICheckbox.lua",
    "EtherHack/lua/components/ui/UIButton.lua",
    "EtherHack/lua/components/ui/UISlider.lua",
    "EtherHack/lua/components/ui/UIMechanics.lua",
    "EtherHack/lua/components/ui/UIModalAddXP.lua",
    "EtherHack/lua/components/ui/UIMovableMiniMap.lua",
    "EtherHack/lua/components/ui/UIModalAddTrait.lua",
    "EtherHack/lua/components/ui/UIHealth.lua",
    "EtherHack/lua/components/ui/UIItemTables.lua",
    "EtherHack/lua/components/ui/UIMap.lua",
    "EtherHack/lua/components/ui/UISkillTable.lua",
    "EtherHack/lua/components/ui/UITraitsTable.lua",
    "EtherHack/lua/components/panels/EtherInfoPanel.lua",
    "EtherHack/lua/components/panels/EtherCharacterPanel.lua",
    "EtherHack/lua/components/panels/EtherItemCreator.lua",
    "EtherHack/lua/components/panels/EtherPlayerEditor.lua",
    "EtherHack/lua/components/panels/EtherOverlayPanel.lua",
    "EtherHack/lua/components/panels/EtherVisualsPanel.lua",
    "EtherHack/lua/components/panels/EtherMapPanel.lua",
    "EtherHack/lua/components/panels/EtherExploitPanel.lua",
    "EtherHack/lua/components/panels/EtherSettingsPanel.lua"
}

for _, module in ipairs(etherModules) do
    requireExtra(module);
end

--*********************************************************
--* Глобальные установки UI
--*********************************************************
EtherMain                   = ISPanel:derive("EtherMain"); -- Наследование от ISPanel
EtherMain.instance          = nil; --Экземпляр окна
EtherMain.menuKeyID         = 210; -- Клавиша открытия окна - Insert (210)
EtherMain.defaultWidth      = 760; -- Стандартная ширина окна
EtherMain.defaultHeight     = 520; -- Стандартная высота окна
EtherMain.minimumWidth      = 760;
EtherMain.minimumHeight     = 520;
EtherMain.currentTabID      = 1; -- Последняя открытая вкладка
EtherMain.accentColor       = {r = getAccentUIColor():getR(), g = getAccentUIColor():getG(), b = getAccentUIColor():getB(), a = 1.0}; -- Акцентный цвет

--*********************************************************
--* Закрытие окна по нажатию кнопки UI
--*********************************************************
function EtherMain:close()
	UITheme.hideTooltips(EtherMain.instance);
	EtherMain.instance:setVisible(false);
    EtherMain.instance:removeFromUIManager();
    EtherMain.instance = nil;
end

function EtherMain:resizeTo(width, height)
    local availableWidth = getCore():getScreenWidth() - self:getX();
    local availableHeight = getCore():getScreenHeight() - self:getY();
    width = math.min(math.max(width, EtherMain.minimumWidth), math.max(availableWidth, EtherMain.minimumWidth));
    height = math.min(math.max(height, EtherMain.minimumHeight), math.max(availableHeight, EtherMain.minimumHeight));

    self:setWidth(width);
    self:setHeight(height);
    EtherMain.defaultWidth = width;
    EtherMain.defaultHeight = height;

    if self.buttonsPanel ~= nil then
        self.buttonsPanel:setHeight(height - UITheme.metrics.titleBarHeight);
        self.buttonsPanel:layoutPanels();
    end

    if self.closeButton ~= nil then
        self.closeButton:setX(width - self.closeButton:getWidth() - UITheme.spacing.small);
    end

    if self.resizeWidget ~= nil then
        local resizeSize = UITheme.metrics.resizeHandleSize;
        self.resizeWidget:setX(width - resizeSize);
        self.resizeWidget:setY(height - resizeSize);
    end
end

function EtherMain.resizeWindow(target, width, height)
    target:resizeTo(width, height);
end

function EtherMain:RestoreLayout(name, layout)
    ISLayoutManager.DefaultRestoreWindow(self, layout);
    self:resizeTo(self:getWidth(), self:getHeight());
end

function EtherMain:SaveLayout(name, layout)
    ISLayoutManager.DefaultSaveWindow(self, layout);
end

--*********************************************************
--* Создание дочерних элементов
--*********************************************************
function EtherMain:createChildren()
    ISPanel.createChildren(self);

    local titleBarHeight = UITheme.metrics.titleBarHeight;
    self.buttonsPanel = UIButtonsPanel:new(0, titleBarHeight, UITheme.metrics.navigationWidth,
        self.height - titleBarHeight, self, EtherMain.accentColor);
    self.buttonsPanel:initialise();
    self.buttonsPanel:instantiate();
    self.buttonsPanel:setVisible(true);
    self:addChild(self.buttonsPanel);

    self.buttonsPanel:addButton("EtherHack/media/ui/info.png", getTranslate("UI_Navigation_Overview"), getTranslate("UI_Navigation_Overview_Tooltip"), EtherInfoPanel);
    self.buttonsPanel:addButton("EtherHack/media/ui/character.png", getTranslate("UI_Navigation_Character"), getTranslate("UI_Navigation_Character_Tooltip"), EtherCharacterPanel);
    self.buttonsPanel:addButton("EtherHack/media/ui/itemCreator.png", getTranslate("UI_Navigation_Items"), getTranslate("UI_Navigation_Items_Tooltip"), EtherItemCreator);
    self.buttonsPanel:addButton("EtherHack/media/ui/playerEditor.png", getTranslate("UI_Navigation_Player"), getTranslate("UI_Navigation_Player_Tooltip"), EtherPlayerEditor);
    self.buttonsPanel:addButton("EtherHack/media/ui/visuals.png", getTranslate("UI_Navigation_Overlay"), getTranslate("UI_Navigation_Overlay_Tooltip"), EtherOverlayPanel);
    self.buttonsPanel:addButton("EtherHack/media/ui/visuals.png", getTranslate("UI_Navigation_Visuals"), getTranslate("UI_Navigation_Visuals_Tooltip"), EtherVisualsPanel);
    self.buttonsPanel:addButton("EtherHack/media/ui/teleport.png", getTranslate("UI_Navigation_Map"), getTranslate("UI_Navigation_Map_Tooltip"), EtherMapPanel);
    self.buttonsPanel:addButton("EtherHack/media/ui/exploit.png", getTranslate("UI_Navigation_Tools"), getTranslate("UI_Navigation_Tools_Tooltip"), EtherExploitPanel);
    self.buttonsPanel:addButton("EtherHack/media/ui/settings.png", getTranslate("UI_Navigation_Settings"), getTranslate("UI_Navigation_Settings_Tooltip"), EtherSettingsPanel);

    self.closeButton = ISButton:new(self.width - 36, 5, 28, 26, "X", self, EtherMain.close);
    self.closeButton:initialise();
    self.closeButton:setAnchorLeft(false);
    self.closeButton:setAnchorRight(true);
    self.closeButton:setAnchorTop(true);
    self.closeButton:setAnchorBottom(false);
    self.closeButton.tooltip = getTranslate("UI_Common_Close");
    self:addChild(self.closeButton);

    self.buttonsPanel:openPanel(EtherMain.currentTabID);

    self.resizeWidget = ISResizeWidget:new(self.width - 16, self.height - 16, 16, 16, self);
    self.resizeWidget.resizeFunction = EtherMain.resizeWindow;
    self.resizeWidget:initialise();
    self.resizeWidget:setAnchorLeft(false);
    self.resizeWidget:setAnchorRight(true);
    self.resizeWidget:setAnchorTop(false);
    self.resizeWidget:setAnchorBottom(true);
    self.resizeWidget:setVisible(true);
    self:addChild(self.resizeWidget);
end

function EtherMain:prerender()
    ISPanel.prerender(self);
    local colors = UITheme.colors;
    self:drawRect(0, 0, self.width, UITheme.metrics.titleBarHeight, 1.0,
        colors.surface.r, colors.surface.g, colors.surface.b);
    self:drawRect(0, UITheme.metrics.titleBarHeight - 1, self.width, 1, 1.0,
        colors.border.r, colors.border.g, colors.border.b);
    local currentPageTitle = self.buttonsPanel ~= nil and self.buttonsPanel:getCurrentTitle() or "EtherTrainer";
    self:drawText(currentPageTitle, UITheme.spacing.medium, 10,
        colors.text.r, colors.text.g, colors.text.b, colors.text.a, UIFont.Small);
end

function EtherMain:render()
    ISPanel.render(self);
    self:drawTextureScaled(self.resizeTexture, self.width - 16, self.height - 16, 16, 16, 1, 1, 1, 1);
end

--*********************************************************
--* Логика открытия и закрытия меню по нажатию клавиши
--*********************************************************
function EtherMain.OnOpenPanel(key)
    if key == EtherMain.menuKeyID then
        -- Если панель уже существует, закрываем окно
        if EtherMain.instance ~= nil then
            EtherMain.instance:close();
            return
        end

        -- Создаем новую панель
        EtherMain.instance  = EtherMain:new();
        EtherMain.instance:initialise();
        EtherMain.instance:instantiate();
        EtherMain.instance:addToUIManager();
        EtherMain.instance:setVisible(true);
        EtherMain.instance:setAlwaysOnTop(false);
        ISLayoutManager.RegisterWindow("EtherHackMain", EtherMain, EtherMain.instance);
        EtherMain.instance:setVisible(true);
    end
end

--*********************************************************
--* Создание нового экземпляра меню
--*********************************************************
function EtherMain:new()
    local menuTableData = {};

    local positionX = getCore():getScreenWidth() / 2 - EtherMain.defaultWidth / 2;
    local positionY = getCore():getScreenHeight() / 2 - EtherMain.defaultHeight / 2;

    menuTableData = ISPanel:new(positionX, positionY, EtherMain.defaultWidth, EtherMain.defaultHeight);
    setmetatable(menuTableData, self);
    menuTableData.background = true;
	menuTableData.backgroundColor = UITheme.colors.window;
	menuTableData.borderColor = {r=0, g=0, b=0, a=0};
	menuTableData.moveWithMouse = true;
    menuTableData.minimumWidth = EtherMain.minimumWidth;
    menuTableData.minimumHeight = EtherMain.minimumHeight;
    menuTableData.resizeTexture = getTexture("media/ui/ResizeIcon.png");
    self.__index = self;

    return menuTableData;
end

Events.OnKeyPressed.Add(EtherMain.OnOpenPanel);
