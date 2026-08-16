UIFeedback = UIFeedback or {}
UIFeedback.current = nil

function UIFeedback.show(message, kind)
    UIFeedback.current = {
        message = message or "",
        kind = kind or "success",
        shownAt = getTimestampMs()
    }
    return UIFeedback.current
end

function UIFeedback.clear()
    UIFeedback.current = nil
end

function UIFeedback.getColor()
    if UIFeedback.current == nil then return UITheme.colors.textMuted end
    return UITheme.colors[UIFeedback.current.kind] or UITheme.colors.textMuted
end
