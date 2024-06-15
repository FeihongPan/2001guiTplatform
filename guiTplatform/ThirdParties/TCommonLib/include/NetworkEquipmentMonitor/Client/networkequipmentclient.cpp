/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        networkequipmentclient.cpp
* Description:      接收来自对应IP监控软件的所有部署软件的实时状态，并且发给NetworkEquipmentManager
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-1-16
* Modify Record：
***********************************************************************/

#include "networkequipmentclient.h"
#include "Logger/loggermanager.h"
#include "Converter/enumconverter.h"
#include "Communication/MQTT/ipublish.h"
#include "NetworkEquipmentMonitor/Manage/heartbeat.h"
#include "NetworkEquipmentMonitor/Data/s_netmonitor.h"
#include "NetworkEquipmentMonitor/Command/cmd_netmonitor.h"

#include <QMetaType>

using namespace NS_Log;

NetworkEquipmentClient::NetworkEquipmentClient(const QString &name, QObject *parent)
    : IMqttClient(name, parent)
{
    qRegisterMetaType<S_Dic_StringBool>("S_Dic_StringBool");
    qRegisterMetaType<S_Dic_StringBool>("S_Dic_StringBool&");
}

NetworkEquipmentClient::~NetworkEquipmentClient()
{

}

void NetworkEquipmentClient::OpenApp(const QString &strAppName)
{
    Publish(EnumConverter::ConvertToString(CMD_NetMonitor::CMD_AppOpen), true, strAppName.toLatin1());
}

void NetworkEquipmentClient::CloseApp(const QString &strAppName)
{
    Publish(EnumConverter::ConvertToString(CMD_NetMonitor::CMD_AppClose), true, strAppName.toLatin1());
}

void NetworkEquipmentClient::RestartApp(const QString &strAppName)
{
    Publish(EnumConverter::ConvertToString(CMD_NetMonitor::CMD_AppRestart), true, strAppName.toLatin1());
}

void NetworkEquipmentClient::decoding(const QString &task, bool result, const QByteArray &msg, const QByteArray &errMsg)
{
    S_Dic_StringBool dic_AppState;
    dic_AppState.fromJson(msg);
    CMD_NetMonitor::Command cmd = EnumConverter::ConvertStringToEnum<CMD_NetMonitor::Command>(task);

    switch (cmd)
    {
        case CMD_NetMonitor::Command::CMD_AppState:
            emit sig_SendAppState(dic_AppState, result); // to manager
            break;
        case CMD_NetMonitor::CMD_AppOpen:
            break;
        case CMD_NetMonitor::CMD_AppClose:
            break;
        case CMD_NetMonitor::CMD_AppRestart:
            break;
        case CMD_NetMonitor::CMD_HeartBeat:
            break;
        default:
            break;
    }
}
