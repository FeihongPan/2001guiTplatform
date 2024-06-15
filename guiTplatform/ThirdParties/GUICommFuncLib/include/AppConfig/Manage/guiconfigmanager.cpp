#include "guiconfigmanager.h"
#include "FileSystem/filesystem.h"
#include <QMutex>

GUIConfigManager *GUIConfigManager::self = nullptr;

GUIConfigManager::GUIConfigManager(QObject *parent) : QObject(parent)
{

}

GUIConfigManager *GUIConfigManager::getInstance()
{
    if (self == nullptr)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if (self == nullptr)
        {
            self = new GUIConfigManager;
        }
    }
    return self;
}

bool GUIConfigManager::Initialize()
{
    if(!this->m_bInitialized)
    {
        this->m_bInitialized = readFormFile();
    }
    return this->m_bInitialized;
}

bool GUIConfigManager::IsInitialized()
{
    return this->m_bInitialized;
}

bool GUIConfigManager::WriteToFile(SR_GUIConfig &uiPara)
{
    this->m_UIPara = uiPara;
    return FileSystem::Write(folderPath, fileName, this->m_UIPara.toRawJson());
}

const SR_GUIConfig &GUIConfigManager::GetUIParameter()
{
    return this->m_UIPara;
}

const SR_GUIConfig &GUIConfigManager::GetUIParameter(bool &res)
{
    res = this->m_bInitialized;
    return this->m_UIPara;
}

bool GUIConfigManager::readFormFile()
{
    QByteArray arr;
    if(FileSystem::Read(filePath, arr))
    {
        m_UIPara.fromJson(arr);
        return true;
    }
    return false;
}
