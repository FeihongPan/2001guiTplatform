/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        networkequipmentsubscriber.cpp
* Description:      接收GUI层发来的命令，并且传给NetworkEquipmentManager进行处理
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-1-16
* Modify Record：
***********************************************************************/

#include "networkequipmentsubscriber.h"

#include "Logger/loggermanager.h"
#include "Converter/enumconverter.h"
#include "NetworkEquipmentMonitor/Data/s_netmonitor.h"
#include "NetworkEquipmentMonitor/Command/cmd_netmonitor.h"
#include "NetworkEquipmentMonitor/Manage/networkequipmentmanager.h"

using namespace NS_Log;

NetworkEquipmentSubscriber *NetworkEquipmentSubscriber::self = nullptr;

NetworkEquipmentSubscriber::NetworkEquipmentSubscriber(const QString &name, QObject *parent)
    : ISubscriber(name, parent)
{

}

NetworkEquipmentSubscriber::~NetworkEquipmentSubscriber()
{

}

NetworkEquipmentSubscriber *NetworkEquipmentSubscriber::getInstance()
{
    if(nullptr == self)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(nullptr == self)
        {
            self = new NetworkEquipmentSubscriber("NetworkEquipmentSubscriber");
        }
    }
    return self;
}

void NetworkEquipmentSubscriber::decoding(const QString &topic, const QByteArray &message)
{
    TaskInfo task_Recived;
    task_Recived.fromJson(message);
    CMD_NetMonitor::Command cmd = EnumConverter::ConvertStringToEnum<CMD_NetMonitor::Command>(task_Recived.task);

    S_AppOperator dic_AppNameInfo;
    dic_AppNameInfo.fromJson(task_Recived.context);

    switch (cmd)
    {
        case CMD_NetMonitor::CMD_AppOpen:
            NetworkEquipmentManager::getInstance()->Open(dic_AppNameInfo.IP, dic_AppNameInfo.appName);
            break;
        case CMD_NetMonitor::CMD_AppClose:
            NetworkEquipmentManager::getInstance()->Close(dic_AppNameInfo.IP, dic_AppNameInfo.appName);
            break;
        case CMD_NetMonitor::CMD_AppRestart:
            NetworkEquipmentManager::getInstance()->Restart(dic_AppNameInfo.IP, dic_AppNameInfo.appName);
            break;
        case CMD_NetMonitor::CMD_AppState:
            break;
        case CMD_NetMonitor::CMD_HeartBeat:
            break;
        default:
            break;
    }
}
