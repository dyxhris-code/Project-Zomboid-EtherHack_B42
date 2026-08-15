require "ISUI/ISPanel"

--*********************************************************
--* Глобальные установки UI
--*********************************************************
EtherInfoPanel = ISPanel:derive("EtherInfoPanel"); -- Наследование от ISPanel

--*********************************************************
--* Отрисовка текста
--*********************************************************
function EtherInfoPanel:render()
    local y = 30
    local marginTitle = 25;
    local marginText = 15;
    self:drawTextCentre(getTranslate("UI_InformationPanel_General_Title"), self.width / 2, y, 1, 1, 1, 1, UIFont.Medium)

    y = y + marginTitle

    local generalTexts = {
        "UI_InformationPanel_General_Text1",
        "UI_InformationPanel_General_Text2",
        "UI_InformationPanel_General_Text3",
        "UI_InformationPanel_General_Text4",
        "UI_InformationPanel_General_Text5",
    }
    for i, textKey in ipairs(generalTexts) do
        self:drawTextCentre(getTranslate(textKey), self.width / 2, y, 1, 1, 1, 1, UIFont.Small)
        y = y + marginText
    end

    y = y + marginText

    self:drawTextCentre(getTranslate("UI_InformationPanel_Disclaimer_Title"), self.width / 2, y, 1, 1, 1, 1, UIFont.Medium)

    y = y + marginTitle

    local disclaimerTexts = {
        "UI_InformationPanel_Disclaimer_Text1",
        "UI_InformationPanel_Disclaimer_Text2",
        "UI_InformationPanel_Disclaimer_Text3",
        "UI_InformationPanel_Disclaimer_Text4",
        "UI_InformationPanel_Disclaimer_Text5",
    }
    for i, textKey in ipairs(disclaimerTexts) do
        self:drawTextCentre(getTranslate(textKey), self.width / 2, y, 1, 1, 1, 1, UIFont.Small)
        y = y + marginText
    end

    y = y + marginText
    
    self:drawTextCentre(getTranslate("UI_InformationPanel_Contacts_Title"), self.width / 2, y, 1, 1, 1, 1, UIFont.Medium)

    y = y + marginTitle

    local contactTexts = {
        "GitHub: https://github.com/Yeet-Masta/",
        "YouTube: https://www.youtube.com/@yeetmaster5161",
        "Discord: Shuffler5101 (shuffler5101)",
        "Email: spaceguy234@gmail.com",
        getTranslate("UI_InformationPanel_Contacts_Donation") .. "https://www.donationalerts.com/r/quzile",
    }
    for i, text in ipairs(contactTexts) do
        self:drawTextCentre(text, self.width / 2, y, 1, 1, 1, 1, UIFont.Small)
        y = y + marginText
    end
end

--*********************************************************
--* Создание нового экземпляра меню
--*********************************************************
function EtherInfoPanel:new(posX, posY, width, height)
    local menuTableData = {};

    menuTableData = ISPanel:new(posX, posY, width, height);
    setmetatable(menuTableData, self);
    menuTableData.background = true;
	menuTableData.backgroundColor = {r=0.0, g=0.0, b=0.0, a=0.0};
	menuTableData.borderColor = {r=0.0, g=0.0, b=0.0, a=0.0};
    menuTableData.moveWithMouse = true;
    menuTableData.localPlayer = getPlayer();
    self.__index = self;

    return menuTableData;
end
