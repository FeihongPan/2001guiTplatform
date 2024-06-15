#include "guiconfig.h"
#include "Language/language.h"

SR_GUIConfig::SR_GUIConfig()
{
    naviPanelLeft.SetValue(false);
    language.SetEnumValue<Language::LanguageType>(Language::LanguageType::Chinese);
}
