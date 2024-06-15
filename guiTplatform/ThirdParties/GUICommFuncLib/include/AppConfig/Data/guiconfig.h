#ifndef GUICONFIG_H
#define GUICONFIG_H

#include "GUICommFuncLib_global.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

class GUICOMMFUNCLIB_EXPORT SR_GUIConfig : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TString, serverIp)
    QS_OBJECT(TInt, serverPort)
    QS_OBJECT(TBool, naviPanelLeft)
    QS_OBJECT(TEnum, language)

public:
    SR_GUIConfig();
};



#endif // GUICONFIG_H
