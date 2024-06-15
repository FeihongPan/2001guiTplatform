/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        networkequipmentmanager.h
* Description:      注册并且处理从每个IP对应的Client传来的实时状态并且打包发给GUI，从NetworkEquipmentSubscriber获取从GUI发来的指令并且下达指令给Client
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-1-16
* Modify Record：
***********************************************************************/

#ifndef NETWORKEQUIPMENTMANAGER_H
#define NETWORKEQUIPMENTMANAGER_H

#include "TCommonLib_global.h"

#include "FileSystem/ifileoperator.h"
#include "Communication/MQTT/ipublish.h"
#include "NetworkEquipmentMonitor/Data/s_netmonitor.h"

class NetworkEquipmentClient;

class TCOMMONLIB_EXPORT NetworkEquipmentManager : public QObject, public IPublish, public IFileOperator
{
    Q_OBJECT

public:
    ~NetworkEquipmentManager();

    static NetworkEquipmentManager *getInstance();

    /// <summary>
    /// 初始化，主要包括读取IP配置文件并且生成对应Client
    /// </summary>
    bool Initialize();

    /// <summary>
    /// 用于在iStarter中进行订阅等操作
    /// </summary>
    /// <returns>返回Client的列表</returns>
    QList<NetworkEquipmentClient *> GetNetMonitorClients() const;

    /// <summary>
    /// 为每个生成的Client进行订阅发布和接受的消息，其中发送的Topic为MC + IP，接受的为NMS + IP
    /// </summary>
    /// <param name="client">需要订阅的client</param>
    /// <param name="str_pub_Prefix">Topic前缀</param>
    /// <param name="str_sub_Prefix">Topic后缀</param>
    void LinkNetMonitorToClient(MqttClient *pClient, const QString &str_pub_Prefix, const QString &str_sub_Prefix);

    /// <summary>
    /// 相应IP的Client执行打开操作
    /// </summary>
    /// <param name="strIp">对应的ip</param>
    /// <param name="strAppName">app名字</param>
    void Open(const QString &strIp, const QString &strAppName) const;

    /// <summary>
    /// 相应IP的Client执行关闭操作
    /// </summary>
    /// <param name="strIp">对应的ip</param>
    /// <param name="strAppName">app名字</param>
    void Close(const QString &strIp, const QString &strAppName) const;

    /// <summary>
    /// 相应IP的Client执行重启操作
    /// </summary>
    /// <param name="strIp">对应的ip</param>
    /// <param name="strAppName">app名字</param>
    void Restart(const QString &strIp, const QString &strAppName) const;

    /// <summary>
    /// 周期性发送打包好的所有IP下的所有部署软件的实时状态给GUI
    /// </summary>
    virtual void SetPeriodPublish() override;

    virtual void SaveCommandInfo() override;

private:
    NetworkEquipmentManager(const QString &name, QObject *parent = nullptr);
    NetworkEquipmentManager(const NetworkEquipmentManager &) = delete;
    NetworkEquipmentManager &operator=(const NetworkEquipmentManager &) = delete;

    /// <summary>
    /// 初始化注册NetworkEquipment，包括读取配置文件等
    /// </summary>
    bool registerNetworkEquipment();

    /// <summary>
    /// 读取IP配置文件
    /// </summary>
    /// <returns>得到所有IP值的列表</returns>
    QList<QString> readIPConfig(bool &bReadIpConfig);

    /// <summary>
    /// 所有IP下的部署软件的实时状态数据的类型转换
    /// </summary>
    /// <returns>返回S_Dic_AppState的QByteArray类型</returns>
    QByteArray getDicAppStateValue(bool &bGetDicAppState);

private:
    static NetworkEquipmentManager *self;

    QList<QString> m_lst_IP;
    QMap<QString, NetworkEquipmentClient *> m_dic_NetMonitorClient;

    S_Dic_AppState m_dic_AllAppState;

    bool m_bInitialized = false;
};

#endif // NETWORKEQUIPMENTMANAGER_H
