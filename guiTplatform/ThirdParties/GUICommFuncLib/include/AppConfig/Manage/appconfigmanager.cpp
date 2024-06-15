/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        appconfigmanager.cpp
* Description:      AppConfigManager继续初始化读取配置文件，提供返回AppConfig数据的接口
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-2-19
* Modify Record：
***********************************************************************/

#include "appconfigmanager.h"
#include "FileSystem/filesystem.h"
#include "AppConfig/Command/cmd_appconfig.h"
#include <QMutex>

AppConfigManager *AppConfigManager::self = nullptr;

AppConfigManager::AppConfigManager(QString name, QObject *parent) : QObject(parent), IPublish(name), IFileOperator(name)
{

}

AppConfigManager::~AppConfigManager()
{

}

AppConfigManager *AppConfigManager::getInstance()
{
    if(nullptr == self)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(nullptr == self)
        {
            self = new AppConfigManager("AppConfigManager");
        }
    }
    return self;
}

const bool &AppConfigManager::Initialize()
{
    m_bInitialized = false;
    QByteArray arr;
    m_strFilePath = m_FolderPath + "/" + m_FileName;
    if(FileSystem::Read(m_strFilePath, arr))
    {
        m_AppConfig.fromJson(arr);
        m_bInitialized = true;
    }
    return m_bInitialized;
}

bool AppConfigManager::WriteToFile(AppConfig &config)
{
    m_AppConfig = config;
    return FileSystem::Write(m_FolderPath, m_FileName, m_AppConfig.toRawJson());
}

void AppConfigManager::StartPublish()
{
    Publish(EnumConverter::ConvertToString(CMD_AppConfig::CMD_Config), true, GetAppConfig().toRawJson());
}

void AppConfigManager::SaveCommandInfo()
{
    QByteArray resultMsg;
    QByteArray msg;
    msg = GetAppConfig().toRawJson();
    resultMsg += m_Publisher.GetPublishData(this->m_Topic, EnumConverter::ConvertToString(CMD_AppConfig::CMD_Config), true, msg);
    writeCmdSampleToFile(GetTopic(), resultMsg);
}
