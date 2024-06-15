/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        appconfigmanager.h
* Description:      AppConfigManager继续初始化读取配置文件，提供返回AppConfig数据的接口
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-2-19
* Modify Record：
***********************************************************************/

#ifndef APPCONFIGMANAGER_H
#define APPCONFIGMANAGER_H

#include "GUICommFuncLib_global.h"
#include "AppConfig/Data/appconfig.h"
#include "Communication/MQTT/ipublish.h"
#include "FileSystem/ifileoperator.h"

#include <QObject>

class GUICOMMFUNCLIB_EXPORT AppConfigManager : public QObject, public IPublish, public IFileOperator
{
    Q_OBJECT
public:
    /// <summary>
    /// 析构函数
    /// </summary>
    ~AppConfigManager();

    /// <summary>
    /// 单例
    /// </summary>
    static AppConfigManager *getInstance();

    /// <summary>
    /// AppConfigManager是否初始化完成
    /// </summary>
    /// <returns>返回AppConfigManager初始化状态</returns>
    inline const bool &IsInitialized() const;

    /// <summary>
    /// 获取AppConfig
    /// </summary>
    /// <returns>返回AppConfig数据</returns>
    inline const AppConfig &GetAppConfig() const;

    /// <summary>
    /// AppConfigManager进行初始化，读取配置文件等
    /// </summary>
    /// <returns>返回AppConfigManager初始化状态</returns>
    const bool &Initialize();

    /// <summary>
    /// 写入AppConfig配置文件
    /// </summary>
    /// <param name="config">UI修改的AppConfig配置文件</param>
    /// <returns>AppConfig文件写入是否成功</returns>
    bool WriteToFile(AppConfig &config);

private:
    /// <summary>
    /// 构造函数
    /// </summary>
    explicit AppConfigManager(QString name, QObject *parent = nullptr);

    /// <summary>
    /// 饿汉式单例模式删除拷贝构造函数和赋值构造函数
    /// </summary>
    AppConfigManager(const AppConfigManager &) = delete;
    AppConfigManager &operator=(const AppConfigManager &) = delete;

    virtual void StartPublish() override;

    virtual void SaveCommandInfo() override;

private:
    static AppConfigManager *self;

    AppConfig m_AppConfig;

    QString m_strFilePath;

    bool m_bInitialized = false;
};

inline const bool &AppConfigManager::IsInitialized() const
{
    return m_bInitialized;
}

inline const AppConfig &AppConfigManager::GetAppConfig() const
{
    return m_AppConfig;
}

#endif // APPCONFIGMANAGER_H
