#ifndef GUICONFIGMANAGER_H
#define GUICONFIGMANAGER_H

#include "GUICommFuncLib_global.h"
#include "AppConfig/Data/guiconfig.h"
#include "AppConfig/AppParameter.h"

#include <QObject>

class GUICOMMFUNCLIB_EXPORT GUIConfigManager : public QObject
{
    Q_OBJECT
public:
    explicit GUIConfigManager(QObject *parent = nullptr);
    static GUIConfigManager *getInstance();

    bool Initialize();
    bool IsInitialized();

    bool WriteToFile(SR_GUIConfig &uiPara);

    const SR_GUIConfig &GetUIParameter();
    const SR_GUIConfig &GetUIParameter(bool &res);
    SR_GUIConfig m_UIPara;

private:
    bool readFormFile();

private:
    static GUIConfigManager *self;
    bool m_bInitialized = false;
    QString folderPath = DataPath + "guiParameter";
    QString fileName = "parameter.json";
    QString filePath = folderPath + "/" + fileName;
};

#endif // GUICONFIGMANAGER_H
