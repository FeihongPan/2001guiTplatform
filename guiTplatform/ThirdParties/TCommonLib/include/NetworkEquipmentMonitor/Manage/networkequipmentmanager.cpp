/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        networkequipmentmanager.cpp
* Description:      注册并且处理从每个IP对应的Client传来的实时状态并且打包发给GUI，从NetworkEquipmentSubscriber获取从GUI发来的指令并且下达指令给Client
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-1-16
* Modify Record：
***********************************************************************/

#include "networkequipmentmanager.h"

#include "Logger/loggermanager.h"
#include "Converter/enumconverter.h"
#include "Communication/MQTT/publishermanager.h"
#include "NetworkEquipmentMonitor/Command/cmd_netmonitor.h"
#include "NetworkEquipmentMonitor/Client/networkequipmentclient.h"

using namespace NS_Log;

NetworkEquipmentManager *NetworkEquipmentManager::self = nullptr;

NetworkEquipmentManager::NetworkEquipmentManager(const QString &name, QObject *parent)
    : QObject(parent)
    , IPublish(name)
    , IFileOperator(name)
{

}

NetworkEquipmentManager::~NetworkEquipmentManager()
{

}

NetworkEquipmentManager *NetworkEquipmentManager::getInstance()
{
    if (nullptr == self)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if (nullptr == self)
        {
            self = new NetworkEquipmentManager("NetworkEquipmentManager");
        }
    }
    return self;
}

bool NetworkEquipmentManager::Initialize()
{
    if (!m_bInitialized)
    {
        m_bInitialized = registerNetworkEquipment();
    }
    return m_bInitialized;
}

bool NetworkEquipmentManager::registerNetworkEquipment()
{
    auto bReadIpConfig = false;
    m_lst_IP = readIPConfig(bReadIpConfig);

    foreach (auto &strIp, m_lst_IP)
    {
        m_dic_NetMonitorClient.insert(strIp, new NetworkEquipmentClient("NetMonitorClient_" + strIp));

        connect(m_dic_NetMonitorClient[strIp], &NetworkEquipmentClient::sig_SendAppState, this, [ = ](S_Dic_StringBool & dic_AppState, bool res)
        {
            if (m_dic_AllAppState.values.contains(strIp))
            {
                m_dic_AllAppState.values[strIp] = dic_AppState;
            }
            else
            {
                m_dic_AllAppState.values.insert(strIp, dic_AppState);
            }
        });
    }
    //    LOG()->Log_Debug(m_dic_AppStateInfo.toRawJson().toStdString());
    return bReadIpConfig;
}

QList<QString> NetworkEquipmentManager::readIPConfig(bool &bReadIpConfig)
{
    S_List_String lst_IpInfo;
    QByteArray ConfigData;
    bReadIpConfig = ReadFromFile(ConfigData);
    lst_IpInfo.fromJson(ConfigData);
    return lst_IpInfo.values;
}

QByteArray NetworkEquipmentManager::getDicAppStateValue(bool &bGetDicAppState)
{
    bGetDicAppState = true;
    auto dic_AllAppState = m_dic_AllAppState.toRawJson();
    m_dic_AllAppState.values.clear();
    return dic_AllAppState;
}


QList<NetworkEquipmentClient *> NetworkEquipmentManager::GetNetMonitorClients() const
{
    return m_dic_NetMonitorClient.values();
}

void NetworkEquipmentManager::LinkNetMonitorToClient(MqttClient *pClient, const QString &str_pub_Prefix, const QString &str_sub_Prefix)
{
    foreach (auto &strIp, m_lst_IP)
    {
        m_dic_NetMonitorClient[strIp]->LinkToPublishClient(pClient, str_pub_Prefix, strIp);
        m_dic_NetMonitorClient[strIp]->LinkToSubscribeClient(pClient);
        m_dic_NetMonitorClient[strIp]->Subscribe(str_sub_Prefix + strIp);
    }
}

void NetworkEquipmentManager::Open(const QString &strIp, const QString &strAppName) const
{
    m_dic_NetMonitorClient[strIp]->OpenApp(strAppName);
}

void NetworkEquipmentManager::Close(const QString &strIp, const QString &strAppName) const
{
    m_dic_NetMonitorClient[strIp]->CloseApp(strAppName);
}

void NetworkEquipmentManager::Restart(const QString &strIp, const QString &strAppName) const
{
    m_dic_NetMonitorClient[strIp]->RestartApp(strAppName);
}

void NetworkEquipmentManager::SetPeriodPublish()   // to GUI_NetworkEquipment
{
    bool r = false;
    m_Publisher.PublishPeriodically(this->m_Topic, EnumConverter::ConvertToString(CMD_NetMonitor::CMD_AppState), r, std::bind(&NetworkEquipmentManager::getDicAppStateValue, this, std::placeholders::_1), 500);
}

void NetworkEquipmentManager::SaveCommandInfo()
{
    bool bGetDicAppState;
    QByteArray msg = getDicAppStateValue(bGetDicAppState);
    QByteArray resultMsg = m_Publisher.GetPublishData(this->m_Topic, EnumConverter::ConvertToString(CMD_NetMonitor::CMD_AppState), true, msg);
    writeCmdSampleToFile(GetTopic(), resultMsg);
}
