require "ISUI/ISPanel"

UISlider = ISPanel:derive("UISlider");

--*********************************************************
--* Ограничение значений параметра
--*********************************************************
local function valueClamp(value, min, max)
    if (value < min) then
        return min;
    end
    if (value > max) then
        return max;
    end
    return value
end

--*********************************************************
--* Нажите клавиши мыши
--*********************************************************
function UISlider:onMouseDown(x, y)
    if not self:isEnabled() or x < 0 or y < 0 or x > self.width or y > self.height then
		return false;
	end

    self.isDragging = true;
    self:setValueFromPosition(x);
    return true;
end

--*********************************************************
--* Движение мыши вне слайдера
--*********************************************************
function UISlider:onMouseMoveOutside(x, y)
    self:onMouseMove(x, y);
    self.mouseOver = false;
end

function UISlider:onMouseMove(x, y)
    self.mouseOver = true;
    if not self.isDragging then return; end

    local absoluteX = self:getMouseX();
    self:setValueFromPosition(absoluteX);
end

--*********************************************************
--* Поднятие клавиши мыши вне слайдера
--*********************************************************
function UISlider:onMouseUpOutside(x, y)
    self.isDragging = false;
end

--*********************************************************
--* Поднятие клавиши мыши
--*********************************************************
function UISlider:onMouseUp(x, y)
    self.isDragging = false;
end

function UISlider:setValueFromPosition(x)
    if self.maxValue <= self.minValue then
        self:setValue(self.minValue, true);
        return;
    end

    local trackWidth = self.width - self.sliderThumbSize.width;
    if trackWidth <= 0 then return end
    local position = valueClamp(x - self.sliderThumbSize.width / 2, 0, trackWidth);
    local value = math.floor((position / trackWidth) * (self.maxValue - self.minValue) + self.minValue + 0.5);
    self:setValue(value, true);
end

function UISlider:setValue(value, notify)
    local nextValue = self.minValue;
    if self.maxValue > self.minValue then
        nextValue = valueClamp(value, self.minValue, self.maxValue);
    end
    local changed = self.currentValue ~= nextValue;
    self.currentValue = nextValue;
    if changed and notify == true and self.onChangeMethod ~= nil then
        self.onChangeMethod(self.currentValue);
    end
end

function UISlider:getValue()
    return self.currentValue;
end

function UISlider:setEnabled(enabled, reason)
    self.isEnable = enabled == true;
    self.disabledReason = self.isEnable and nil or reason;
    self.tooltip = self.disabledReason or self.defaultTooltip;
    if not self.isEnable then self.isDragging = false; end
end

function UISlider:isEnabled()
    return self.isEnable == true;
end

function UISlider:setEnable(isEnable)
    self:setEnabled(isEnable);
end

function UISlider:setTooltip(text)
    self.defaultTooltip = text;
    if self:isEnabled() or self.disabledReason == nil then self.tooltip = text; end
end

--*********************************************************
--* Отрисовка слайдера
--*********************************************************
function UISlider:render()
    ISPanel.render(self);

    -- Обновление позиции ползунка на слайдере
    local trackWidth = self.width - self.sliderThumbSize.width;
    local thumbPosX = 0;
    if self.maxValue <= self.minValue then
        thumbPosX = 0;
    else
        thumbPosX = (self.currentValue - self.minValue) / (self.maxValue - self.minValue) * trackWidth;
    end

    local thumbColor = self:isEnabled() and self.sliderThumbColor or UITheme.colors.disabled;
    if self.mouseOver and self:isEnabled() then
        self:drawRect(0, 0, self.width, self.sliderThumbSize.height, 0.20,
            thumbColor.r, thumbColor.g, thumbColor.b);
    end

    self:drawRect(0, self.sliderBarByThumbOffset / 2, self.sliderBarSize.width, self.sliderBarSize.height, self.sliderBarColor.a, self.sliderBarColor.r, self.sliderBarColor.g, self.sliderBarColor.b);
    self:drawRect(thumbPosX, 0, self.sliderThumbSize.width, self.sliderThumbSize.height, thumbColor.a, thumbColor.r, thumbColor.g, thumbColor.b);
    
    
    self:drawTextRight(tostring(self.minValue), - 5, self.sliderThumbSize.height / 2 - 7, 1.0, 1.0, 1.0, 0.3, UIFont.Small);
    self:drawText(tostring(self.maxValue),self.sliderBarSize.width + 5, self.sliderThumbSize.height / 2 - 7, 1.0, 1.0, 1.0, 0.3, UIFont.Small);
	
    self:drawTextCentre(tostring(self.currentValue), thumbPosX + self.sliderThumbSize.width / 2, self.sliderThumbSize.height + 5, thumbColor.r, thumbColor.g, thumbColor.b, thumbColor.a, UIFont.Small);
    UITheme.updateTooltip(self);
end


--*********************************************************
--* Создание нового экземпляра слайдера
--*********************************************************
function UISlider:new (x, y, width, height, value, minValue, maxValue, onChangeMethod)
    local uiTableData = ISPanel:new(x, y, width, height);
    setmetatable(uiTableData, self)
    self.__index = self
    uiTableData.x = x;
    uiTableData.y = y;
    uiTableData.isEnable = true;
    uiTableData.background = false;
    uiTableData.sliderBarByThumbOffset = 6;
    uiTableData.sliderBarColor = {r=1, g=1, b=1, a=0.1};
    uiTableData.sliderThumbColor = EtherMain.accentColor;
    uiTableData.sliderThumbSize = {width = 5, height = height};
    uiTableData.sliderBarSize = {width = width - uiTableData.sliderThumbSize.width, height = height - uiTableData.sliderBarByThumbOffset};
    uiTableData.width = width;
    uiTableData.height = height;
    uiTableData.anchorLeft = true;
    uiTableData.anchorRight = false;
    uiTableData.anchorTop = true;
    uiTableData.anchorBottom = false;
    
    uiTableData.minValue = minValue;
    uiTableData.maxValue = maxValue;
    uiTableData.currentValue = minValue;
    uiTableData.onChangeMethod = onChangeMethod;
    uiTableData.tooltip = nil;
    uiTableData.defaultTooltip = nil;
    uiTableData.disabledReason = nil;
    uiTableData.mouseOver = false;
    uiTableData:setValue(value, false);
    return uiTableData
end

