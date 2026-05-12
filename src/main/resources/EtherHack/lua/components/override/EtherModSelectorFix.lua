require "OptionScreens/ModSelector/ModSelectorModel"
require "OptionScreens/ModSelector/ModLoadOrderPanel"

EtherModSelectorFix = EtherModSelectorFix or {}

local function etherModSelectorLog(message)
    print("[EtherHack]: " .. tostring(message))
end

local function emptyList()
    return nil
end

local function createMissingModInfo(modId)
    local modInfo = {}

    function modInfo:getId()
        return modId
    end

    function modInfo:getName()
        return modId .. " (missing metadata)"
    end

    function modInfo:getIcon()
        return ""
    end

    function modInfo:getCategory()
        return ""
    end

    function modInfo:getDescription()
        return ""
    end

    function modInfo:getModVersion()
        return ""
    end

    function modInfo:getAuthor()
        return ""
    end

    function modInfo:getPoster()
        return ""
    end

    function modInfo:getUrl()
        return ""
    end

    function modInfo:getWorkshopID()
        return nil
    end

    function modInfo:getSource()
        return ""
    end

    function modInfo:getDir()
        return ""
    end

    function modInfo:getVersionMin()
        return nil
    end

    function modInfo:getVersionMax()
        return nil
    end

    function modInfo:isAvailableSelf()
        return true
    end

    function modInfo:getRequire()
        return emptyList()
    end

    function modInfo:getLoadAfter()
        return emptyList()
    end

    function modInfo:getLoadBefore()
        return emptyList()
    end

    function modInfo:getIncompatible()
        return emptyList()
    end

    function modInfo:isAvailable()
        return true
    end

    return modInfo
end

function EtherModSelectorFix.ensureModData(model, modId)
    if model == nil or modId == nil or modId == "" then
        return nil
    end

    if model.mods[modId] ~= nil then
        return model.mods[modId]
    end

    local modInfo = createMissingModInfo(modId)
    local data = {
        modId = modId,
        modInfo = modInfo,
        name = modInfo:getName(),
        icon = "",
        category = "",
        defaultActive = true,
        defaultFav = model.favs and model.favs[modId],
        isActive = true,
        isIncompatible = false,
        incompatibleWith = {},
        requireMods = {},
        isEtherMissingMetadata = true
    }

    model.mods[modId] = data
    etherModSelectorLog("Mod selector metadata missing for active mod '" .. tostring(modId) .. "'. Using a safe placeholder.")

    return data
end

function EtherModSelectorFix.ensureActiveMods(model)
    if model == nil or model.getActiveMods == nil then
        return false
    end

    local activeMods = model:getActiveMods()
    if activeMods == nil or activeMods.getMods == nil then
        return false
    end

    local modArray = activeMods:getMods()
    if modArray == nil then
        return false
    end

    local added = false
    for i = 0, modArray:size() - 1 do
        local modId = modArray:get(i)
        if modId ~= nil and modId ~= "" and model.mods[modId] == nil then
            EtherModSelectorFix.ensureModData(model, modId)
            added = true
        end
    end

    return added
end

if ModSelector ~= nil and ModSelector.Model ~= nil and not ModSelector.Model.EtherMissingModPatch then
    ModSelector.Model.EtherMissingModPatch = true

    local originalReloadMods = ModSelector.Model.reloadMods
    function ModSelector.Model:reloadMods()
        originalReloadMods(self)

        if EtherModSelectorFix.ensureActiveMods(self) then
            self:refreshMods()
        end
    end

    function ModSelector.Model:correctAndSaveModOrder(data)
        local autoOrder = {}
        local added = {}

        for _, modId in ipairs(data) do
            local modData = EtherModSelectorFix.ensureModData(self, modId)
            if modData ~= nil then
                local loadAfter = modData.modInfo:getRequire()
                if loadAfter ~= nil then
                    for j = 0, loadAfter:size() - 1 do
                        local requiredId = loadAfter:get(j)
                        if requiredId ~= nil and requiredId ~= "" and added[requiredId] == nil then
                            EtherModSelectorFix.ensureModData(self, requiredId)
                            table.insert(autoOrder, requiredId)
                            added[requiredId] = true
                        end
                    end
                end

                if added[modId] == nil then
                    table.insert(autoOrder, modId)
                    added[modId] = true
                end
            end
        end

        local modArray = self:getActiveMods():getMods()
        modArray:clear()
        for _, modId in ipairs(autoOrder) do
            modArray:add(modId)
        end
    end
end

if ModSelector ~= nil and ModSelector.ModLoadOrderPanel ~= nil and not ModSelector.ModLoadOrderPanel.EtherMissingModPatch then
    ModSelector.ModLoadOrderPanel.EtherMissingModPatch = true

    local originalInstantiate = ModSelector.ModLoadOrderPanel.instantiate
    function ModSelector.ModLoadOrderPanel:instantiate()
        if self.model ~= nil and EtherModSelectorFix.ensureActiveMods(self.model) then
            self.model:refreshMods()
        end

        originalInstantiate(self)
    end

    function ModSelector.ModLoadOrderPanel:autoSort()
        local baseModOrder = {}
        local idToItem = {}
        for _, val in ipairs(self.modList.items) do
            table.insert(baseModOrder, { modInfo = val.item.modInfo, modId = val.item.modId })
            idToItem[val.item.modId] = val
        end

        table.sort(baseModOrder, function(a, b) return a.modId < b.modId end)

        local autoOrder = {}
        local added = {}
        for _, val in ipairs(baseModOrder) do
            local temp = {}

            local loadAfterAndRequire = self:getLoadAfterAndRequire(val.modInfo)
            for _, dependencyId in ipairs(loadAfterAndRequire) do
                if idToItem[dependencyId] ~= nil and added[dependencyId] == nil then
                    table.insert(temp, dependencyId)
                    added[dependencyId] = true
                elseif idToItem[dependencyId] == nil then
                    etherModSelectorLog("Skipping load-order dependency '" .. tostring(dependencyId) .. "' because it is not active in this list.")
                end
            end

            table.insert(temp, val.modId)
            local modIndex = #temp

            local loadBefore = val.modInfo:getLoadBefore()
            if loadBefore ~= nil then
                for j = 0, loadBefore:size() - 1 do
                    local beforeId = loadBefore:get(j)
                    if idToItem[beforeId] ~= nil and added[beforeId] == nil then
                        table.insert(temp, beforeId)
                        added[beforeId] = true
                    elseif idToItem[beforeId] == nil then
                        etherModSelectorLog("Skipping load-before dependency '" .. tostring(beforeId) .. "' because it is not active in this list.")
                    end
                end
            end

            if added[val.modId] then
                local index = -1
                for i, existingId in ipairs(autoOrder) do
                    if existingId == val.modId then
                        index = i
                        break
                    end
                end

                if index ~= -1 then
                    for j = modIndex + 1, #temp do
                        table.insert(autoOrder, index + 1, temp[j])
                    end
                    for j = 1, modIndex - 1 do
                        table.insert(autoOrder, index, temp[j])
                    end
                end
            else
                for j = 1, #temp do
                    table.insert(autoOrder, temp[j])
                end
                added[val.modId] = true
            end
        end

        local newItems = {}
        for _, modId in ipairs(autoOrder) do
            if idToItem[modId] ~= nil then
                table.insert(newItems, idToItem[modId])
            end
        end
        self.modList.items = newItems
    end
end
