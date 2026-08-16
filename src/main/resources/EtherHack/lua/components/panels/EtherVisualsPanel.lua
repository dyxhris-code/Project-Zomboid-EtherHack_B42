require "ISUI/ISPanel"

--*********************************************************
--* Глобальные установки UI
--*********************************************************
EtherVisualsPanel = ISPanel:derive("EtherVisualsPanel"); -- Наследование от ISPanel

--*********************************************************
--* Обработка prerender
--*********************************************************
function EtherVisualsPanel:prerender()
    self:setStencilRect(0,10,self:getWidth(),self:getHeight() - 20);
    ISPanel.prerender(self);
end

--*********************************************************
--* Обработка render
--*********************************************************
function EtherVisualsPanel:render()
    ISPanel.render(self);
    self:clearStencilRect();
end

--*********************************************************
--* Обработка событий колесика мыши
--*********************************************************
function EtherVisualsPanel:onMouseWheel(del)
	self:setYScroll(self:getYScroll() - (del * 40));
	return true;
end

--*********************************************************
--* Добавление чекбоксов
--*********************************************************
function EtherVisualsPanel:addCheckBox(title, method, isSelected)
    local checkbox = UICheckbox:new(15, self.yRowPosition, title, isSelected, method);
    checkbox:initialise();
    checkbox:instantiate();
    checkbox:setAnchorLeft(true);
    checkbox:setAnchorRight(false);
    checkbox:setAnchorTop(true);
    checkbox:setAnchorBottom(false);
    self:addChild(checkbox);

    self.yRowPosition = self.yRowPosition + checkbox.height + 5;
    self:setScrollHeight(self.yRowPosition + 10);

    table.insert(self.uiElements, checkbox);
end

--*********************************************************
--* Создание метки
--*********************************************************
function EtherVisualsPanel:addLabel(posX, posY, title)
    local label = ISLabel:new(posX, posY + 3, getTextManager():getFontHeight(UIFont.Small), title, 1, 1, 1, 1, UIFont.Small, true)
	label:setAnchorLeft(true)
	label:setAnchorRight(false)
	label:setAnchorTop(true)
	label:setAnchorBottom(false)
	self:addChild(label)
    return label
end

--*********************************************************
--* Создание слайдера
--*********************************************************
function EtherVisualsPanel:addSlider(posX, posY, width, height, value, minValue, maxValue, method)
    local slider = UISlider:new(posX, posY, width, height, value, minValue, maxValue, method)
    slider:initialise();
    slider:instantiate();
    slider:setAnchorLeft(false);
    slider:setAnchorRight(true);
    slider:setAnchorTop(true);
    slider:setAnchorBottom(false);
    self:addChild(slider);
    return slider
end

--*********************************************************
--* Создание слайдера
--*********************************************************
function EtherVisualsPanel:addSliderWithLabel(title, value, minValue, maxValue, method)
    local yOffset = 10;
    if #self.uiElements == 0 then
        yOffset = 10;
    end

    local sliderHeight= 10;
    local sliderWidth = 100;

    self:addLabel(10, self.yRowPosition + yOffset, title);
    local slider = self:addSlider(self.width - sliderWidth - 50, self.yRowPosition + yOffset + 8, sliderWidth, sliderHeight, value, minValue, maxValue, method)
    
    self:setScrollHeight(self:getScrollHeight() + sliderHeight + 5);
    
    self.yRowPosition = self.yRowPosition + sliderHeight * 2 + 5 + yOffset;

    table.insert(self.uiElements, slider);

    return slider;
end

--*********************************************************
--* Создание дочерних элементов
--*********************************************************
function EtherVisualsPanel:createChildren()
    ISPanel.createChildren(self);

    self:setScrollChildren(true);
    self:setScrollHeight(0);
    self:addScrollBars();

    self:addSection(getTranslate("UI_VisualsSection_Global"));
    self:addCheckBox(getTranslate("UI_VisualsPanel_DrawCheatCredits"), function(isChecked)
        toggleVisualDrawCredits(isChecked);
    end, isVisualDrawCredits());

    self:addCheckBox(getTranslate("UI_VisualsPanel_IsVisualsEnable"), function(isChecked)
        toggleVisualsEnable(isChecked);
    end, isVisualsEnable());

    self:addCheckBox(getTranslate("UI_VisualsPanel_360Vision"), function(isChecked)
        toggleVisualEnable360Vision(isChecked);
    end, isVisualEnable360Vision());

    self:addSection(getTranslate("UI_VisualsSection_Entities"));
    self:addCheckBox(getTranslate("UI_VisualsPanel_IsVisualsVehiclesEnable"), function(isChecked)
        toggleVisualsVehiclesEnable(isChecked);
    end, isVisualsVehiclesEnable());

    self:addCheckBox(getTranslate("UI_VisualsPanel_DrawLineToVehicles"), function(isChecked)
        toggleVisualDrawLineToVehicle(isChecked);
    end, isVisualDrawLineToVehicle());



    self:addCheckBox(getTranslate("UI_VisualsPanel_IsVisualsZombiesEnable"), function(isChecked)
        toggleVisualsZombiesEnable(isChecked);
    end, isVisualsZombiesEnable());



    self:addCheckBox(getTranslate("UI_VisualsPanel_IsVisualsPlayersEnable"), function(isChecked)
        toggleVisualsPlayersEnable(isChecked);
    end, isVisualsPlayersEnable());

    self:addSection(getTranslate("UI_VisualsSection_Labels"));
    self:addCheckBox(getTranslate("UI_VisualsPanel_DrawToLocalPlayer"), function(isChecked)
        toggleVisualDrawToLocalPlayer(isChecked);
    end, isVisualDrawToLocalPlayer());

    self:addCheckBox(getTranslate("UI_VisualsPanel_DrawLineToPlayers"), function(isChecked)
         toggleVisualDrawLineToPlayers(isChecked);
    end, isVisualDrawLineToPlayers());

    self:addCheckBox(getTranslate("UI_VisualsPanel_DrawPlayerName"), function(isChecked)
        toggleVisualDrawPlayerNickname(isChecked) ;
    end, isVisualDrawPlayerNickname());

    self:addCheckBox(getTranslate("UI_VisualsPanel_DrawPlayerInfo"), function(isChecked)
        toggleVisualDrawPlayerInfo(isChecked) ;
    end, isVisualDrawPlayerInfo());
end
--*********************************************************
--* Создание нового экземпляра меню
--*********************************************************
function EtherVisualsPanel:new(posX, posY, width, height)
    local menuTableData = {};

    menuTableData = ISPanel:new(posX, posY, width, height);
    setmetatable(menuTableData, self);
    menuTableData.background = true;
	menuTableData.backgroundColor = {r=0.0, g=0.0, b=0.0, a=0.0};
	menuTableData.borderColor = {r=0.0, g=0.0, b=0.0, a=0.0};
    menuTableData.moveWithMouse = true;
    menuTableData.yRowPosition = 10;
    self.__index = self;

    menuTableData.uiElements = {}; -- Список всех элементов

    return menuTableData;
end

function EtherVisualsPanel:addSection(title)
    if self.yRowPosition > 10 then
        self.yRowPosition = self.yRowPosition + 10;
    end

    local label = ISLabel:new(15, self.yRowPosition, getTextManager():getFontHeight(UIFont.Medium), title,
        EtherMain.accentColor.r, EtherMain.accentColor.g, EtherMain.accentColor.b, 1, UIFont.Medium, true);
    label:setAnchorLeft(true);
    label:setAnchorRight(false);
    label:setAnchorTop(true);
    label:setAnchorBottom(false);
    self:addChild(label);

    self.yRowPosition = self.yRowPosition + label.height + 8;
    self:setScrollHeight(self.yRowPosition + 10);
end
