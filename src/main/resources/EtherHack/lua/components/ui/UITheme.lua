require "ISUI/ISToolTip"

UITheme = UITheme or {}

UITheme.colors = {
    window = {r = 0.045, g = 0.045, b = 0.05, a = 0.98},
    surface = {r = 0.085, g = 0.085, b = 0.095, a = 1.0},
    surfaceHover = {r = 0.14, g = 0.14, b = 0.15, a = 1.0},
    surfacePressed = {r = 0.19, g = 0.19, b = 0.20, a = 1.0},
    border = {r = 0.22, g = 0.22, b = 0.24, a = 1.0},
    text = {r = 0.94, g = 0.94, b = 0.95, a = 1.0},
    textMuted = {r = 0.62, g = 0.62, b = 0.66, a = 1.0},
    disabled = {r = 0.30, g = 0.30, b = 0.32, a = 1.0},
    success = {r = 0.30, g = 0.72, b = 0.42, a = 1.0},
    warning = {r = 0.92, g = 0.68, b = 0.24, a = 1.0},
    error = {r = 0.88, g = 0.30, b = 0.30, a = 1.0}
}

UITheme.spacing = {
    xsmall = 4,
    small = 8,
    medium = 12,
    large = 16,
    xlarge = 24
}

UITheme.metrics = {
    titleBarHeight = 36,
    navigationWidth = 176,
    navigationRowHeight = 44,
    controlHeight = 30,
    sectionHeaderHeight = 28,
    resizeHandleSize = 16
}

function UITheme.resolveAccent()
    if EtherMain ~= nil and EtherMain.accentColor ~= nil then
        return EtherMain.accentColor
    end

    local accent = getAccentUIColor()
    return {r = accent:getR(), g = accent:getG(), b = accent:getB(), a = 1.0}
end

function UITheme.updateTooltip(control)
    if control:isMouseOver() and control.tooltip ~= nil and control.tooltip ~= "" then
        if control.tooltipUI == nil then
            control.tooltipUI = ISToolTip:new()
            control.tooltipUI:setOwner(control)
            control.tooltipUI:setVisible(false)
            control.tooltipUI:setAlwaysOnTop(true)
        end
        if not control.tooltipUI:getIsVisible() then
            control.tooltipUI.maxLineWidth = 300
            control.tooltipUI:addToUIManager()
            control.tooltipUI:setVisible(true)
        end
        control.tooltipUI.description = control.tooltip
        control.tooltipUI:setDesiredPosition(getMouseX(), control:getAbsoluteY() + control:getHeight() + 8)
    elseif control.tooltipUI ~= nil and control.tooltipUI:getIsVisible() then
        control.tooltipUI:setVisible(false)
        control.tooltipUI:removeFromUIManager()
    end
end

function UITheme.hideTooltip(control)
    if control.tooltipUI ~= nil and control.tooltipUI:getIsVisible() then
        control.tooltipUI:setVisible(false)
        control.tooltipUI:removeFromUIManager()
    end
end

function UITheme.hideTooltips(root)
    if root == nil then return end
    UITheme.hideTooltip(root)
    if root.children == nil then return end
    for _, child in pairs(root.children) do
        UITheme.hideTooltips(child)
    end
end
