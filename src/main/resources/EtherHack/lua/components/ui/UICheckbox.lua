require "ISUI/ISPanel"

UICheckbox = ISPanel:derive("UICheckbox");

--************************************************************************--
--** Инициализация чекбокса
--************************************************************************--
function UICheckbox:initialise()
	ISPanel.initialise(self);
end

--************************************************************************--
--** Установка состояния чекбокса
--************************************************************************--
function UICheckbox:setChecked(checked, notify)
	local changed = self.checked ~= (checked == true);
    self.checked = checked == true;
    if changed and notify == true and self.onCheckedMethod ~= nil then
        self.onCheckedMethod(self.checked);
    end
end

--************************************************************************--
--** Получение состояние чекбокса
--************************************************************************--
function UICheckbox:getChecked()
	return self.checked == true;
end

function UICheckbox:isChecked()
	return self:getChecked();
end

--************************************************************************--
--** Отрисовка чекбокса
--************************************************************************--
function UICheckbox:render()
	if self.mouseOver and self:isEnabled() then
        local hover = UITheme.colors.surfaceHover;
        self:drawRect(0, 0, self.width, self.height, 0.45, hover.r, hover.g, hover.b);
    end

	local textureY = (self.height - self.textureHeight) / 2;
	local tint = self:isEnabled() and 1.0 or 0.45;
	if not self:getChecked() then
		self:drawTextureScaled(self.uncheckedTexture, 0, textureY, self.textureWidth, self.textureHeight, tint, 1.0, 1.0, 1.0);
	else
		self:drawTextureScaled(self.checkedTexture, 0, textureY, self.textureWidth, self.textureHeight, tint, EtherMain.accentColor.r, EtherMain.accentColor.g, EtherMain.accentColor.b);
	end

	local textAlpha = self:isEnabled() and 1.0 or 0.4;
	self:drawText(self.title, self.textureWidth + self.marginTexture, self.height / 2 - self.fontHeight / 2, 1.0, 1.0, 1.0, textAlpha, self.font);
    UITheme.updateTooltip(self);
end

function UICheckbox:onMouseMove(x, y)
    self.mouseOver = true;
end

function UICheckbox:onMouseMoveOutside(x, y)
    self.mouseOver = false;
end

--************************************************************************--
--** Включение или отключение чекбокса
--************************************************************************--
function UICheckbox:setEnabled(enabled, reason)
    self.enable = enabled == true;
    self.disabledReason = self.enable and nil or reason;
    self.tooltip = self.disabledReason or self.defaultTooltip;
end

function UICheckbox:isEnabled()
    return self.enable == true;
end

function UICheckbox:setEnable(isEnable)
    self:setEnabled(isEnable);
end

function UICheckbox:setTooltip(text)
    self.defaultTooltip = text;
    if self:isEnabled() or self.disabledReason == nil then self.tooltip = text; end
end

--************************************************************************--
--** Обработка клика мыши по чекбоксу
--************************************************************************--
function UICheckbox:onMouseUp(x, y)
    if self:isEnabled() and x >= 0 and y >= 0 and x <= self.width and y <= self.height then
        getSoundManager():playUISound("UIToggleTickBox");
        self:setChecked(not self:getChecked(), true);
        return true;
    end

    return false;
end

--************************************************************************--
--** Создание нового чекбокса
--************************************************************************--
function UICheckbox:new (x, y, title, isChecked, onChecked)
	local uiTableData = ISPanel:new(x, y, 1, 1)
	setmetatable(uiTableData, self)
	self.__index = self
	uiTableData.x = x;
	uiTableData.y = y;
	uiTableData.checkedTexture = getExtraTexture("EtherHack/media/ui/checkbox_checked.png");
	uiTableData.uncheckedTexture = getExtraTexture("EtherHack/media/ui/checkbox_unchecked.png");
	uiTableData.textureWidth = 32;
	uiTableData.textureHeight = 16
	uiTableData.marginTexture = 10;
	uiTableData.borderColor = {r=0, g=0, b=0, a=0.0};
	uiTableData.backgroundColor = {r=0, g=0, b=0, a=0.0};
	uiTableData.anchorLeft = true;
	uiTableData.anchorRight = false;
	uiTableData.anchorTop = true;
	uiTableData.anchorBottom = false;
	uiTableData.title = title;
	uiTableData.checked = isChecked == true;
	uiTableData.font = UIFont.Small;
    uiTableData.fontHeight = getTextManager():getFontHeight(uiTableData.font);
    uiTableData.textWidth = getTextManager():MeasureStringX(uiTableData.font, uiTableData.title);
	uiTableData.onCheckedMethod = onChecked;
	uiTableData.enable = true;
	uiTableData.tooltip = nil;
	uiTableData.defaultTooltip = nil;
	uiTableData.disabledReason = nil;
	uiTableData.mouseOver = false;

	uiTableData.width = uiTableData.textureWidth;
	uiTableData.width = uiTableData.width + uiTableData.marginTexture + uiTableData.textWidth + 20;
	uiTableData.height = math.max(uiTableData.textureHeight, UITheme.metrics.controlHeight);
	return uiTableData;
end

