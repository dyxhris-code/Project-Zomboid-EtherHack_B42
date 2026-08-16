require "ISUI/ISPanel"

UIButton = ISPanel:derive("UIButton");

--************************************************************************--
--** Обработка поднятия клавиши нажатия
--************************************************************************--
function UIButton:onMouseUp(x, y)
    if not self:getIsVisible() or not self:isEnabled() or x < 0 or y < 0 or x > self.width or y > self.height then
		self.onPressed = false;
		return false;
	end

    local process = false;

    if self.onPressed == true then
        process = true;
    end

    self.onPressed = false;
    
	if self.onClickMethod == nil then
        return;
    end

    if process or self.allowMouseUpProcessing then
        getSoundManager():playUISound(self.activateSound)
        self.onClickMethod();
        return true;
    end

    return false;
end

--************************************************************************--
--** Обработка выхода мыши за границы кнопки
--************************************************************************--
function UIButton:onMouseUpOutside(x, y)
    self.onPressed = false;
end

--************************************************************************--
--** Обработка нажатия по кнопке
--************************************************************************--
function UIButton:onMouseDown(x, y)
	if not self:getIsVisible() or not self:isEnabled() or x < 0 or y < 0 or x > self.width or y > self.height then
		return false;
	end

    self.onPressed = true;
    return true;
end

function UIButton:onMouseMove(x, y)
    self.mouseOver = true;
end

function UIButton:onMouseMoveOutside(x, y)
    self.mouseOver = false;
    self.onPressed = false;
end

--************************************************************************--
--** Обработка двойного клика
--************************************************************************--
function UIButton:onMouseDoubleClick(x, y)
	return self:onMouseDown(x, y)
end


--************************************************************************--
--** Отрисовка кнопки
--************************************************************************--
function UIButton:render()
	if self:isEnabled() then
		if not self.onPressed then
			local alpha = self.mouseOver and 0.85 or 1.0;
			self:drawRect( 0, 0, self.width, self.height, alpha, EtherMain.accentColor.r, EtherMain.accentColor.g, EtherMain.accentColor.b)
		else
			self:drawRect( 0, 0, self.width, self.height, 0.8, EtherMain.accentColor.r, EtherMain.accentColor.g, EtherMain.accentColor.b)
		end
		self:drawTextCentre(self.title, self.width / 2, self.height / 2 - 8, 1.0, 1.0, 1.0, 1.0, self.font);
	else
		self:drawRect( 0, 0, self.width, self.height, 1.0, 0.1, 0.1, 0.1)
		self:drawTextCentre(self.title, self.width / 2, self.height / 2 - 8, 1.0, 1.0, 1.0, 0.3, self.font);
	end
    UITheme.updateTooltip(self);
end

--************************************************************************--
--** Включение или отключение кнопки
--************************************************************************--
function UIButton:setEnabled(enabled, reason)
	self.isEnable = enabled == true;
    self.disabledReason = self.isEnable and nil or reason;
    self.tooltip = self.disabledReason or self.defaultTooltip;
end

function UIButton:isEnabled()
    return self.isEnable == true;
end

function UIButton:setEnable(isEnable)
	self:setEnabled(isEnable);
end

function UIButton:setTooltip(text)
    self.defaultTooltip = text;
    if self:isEnabled() or self.disabledReason == nil then
        self.tooltip = text;
    end
end

--************************************************************************--
--** Создание новой кнопки
--************************************************************************--
function UIButton:new (x, y, width, height, title, onClickMethod)

	local uiTableData = {}
	uiTableData = ISPanel:new(x, y, width, height);
	setmetatable(uiTableData, self)
    self.__index = self

	if width < (getTextManager():MeasureStringX(UIFont.Small, title) + 20) then
        width = getTextManager():MeasureStringX(UIFont.Small, title) + 20;
    end
	uiTableData.x = x;
	uiTableData.y = y;
	uiTableData.font = UIFont.Small;
	uiTableData.textureWidth = width;
	uiTableData.textureHeight = height;
	uiTableData.borderColor = {r=0, g=0, b=0, a=0};
	uiTableData.backgroundColor = {r=0, g=0, b=0, a=0};
    uiTableData.textColor = {r=1.0, g=1.0, b=1.0, a=1.0};
    uiTableData.width = width;
    uiTableData.height = height;
	uiTableData.anchorLeft = true;
	uiTableData.anchorRight = false;
	uiTableData.anchorTop = true;
	uiTableData.anchorBottom = false;
	uiTableData.mouseOver = false;
	uiTableData.tooltip = nil;
	uiTableData.defaultTooltip = nil;
	uiTableData.disabledReason = nil;
	uiTableData.title = title;
	uiTableData.onClickMethod = onClickMethod;
	uiTableData.isEnable = true;
	uiTableData.onPressed = false;
    uiTableData.activateSound = "UIActivateButton"
   return uiTableData
end
