require "ISUI/ISPanel"

UISection = ISPanel:derive("UISection")

function UISection:prerender()
    ISPanel.prerender(self)
    local colors = UITheme.colors
    self:drawRect(0, 0, self.width, UITheme.metrics.sectionHeaderHeight, 1.0,
        colors.surface.r, colors.surface.g, colors.surface.b)
    self:drawText(self.title, UITheme.spacing.medium, 6,
        colors.text.r, colors.text.g, colors.text.b, colors.text.a, UIFont.Small)
    self:drawRect(0, UITheme.metrics.sectionHeaderHeight - 1, self.width, 1, 1.0,
        colors.border.r, colors.border.g, colors.border.b)
end

function UISection:new(x, y, width, height, title)
    local panel = ISPanel:new(x, y, width, height)
    setmetatable(panel, self)
    self.__index = self
    panel.title = title or ""
    panel.background = false
    panel.borderColor = UITheme.colors.border
    return panel
end
