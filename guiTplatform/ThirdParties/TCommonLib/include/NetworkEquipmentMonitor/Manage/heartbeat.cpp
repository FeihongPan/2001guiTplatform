/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        heartbeat.cpp
* Description:      心跳检测
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-1-16
* Modify Record：
***********************************************************************/

#include "heartbeat.h"

#include "Converter/enumconverter.h"
#include "NetworkEquipmentMonitor/Command/cmd_netmonitor.h"

HeartBeat *HeartBeat::self = nullptr;

HeartBeat::HeartBeat(const QString &name, QObject *parent)
    : QObject(parent)
    , IPublish(name)
{

}

HeartBeat::~HeartBeat()
{

}

HeartBeat *HeartBeat::getInstance()
{
    if(nullptr == self)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(nullptr == self)
        {
            self = new HeartBeat("HeartBeat");
        }
    }
    return self;
}

void HeartBeat::LinkHeartBeatToPublishClient(MqttClient *pClient, const QString &strPublishPrefix)
{
    m_strAppName = strPublishPrefix;
    LinkToPublishClient(pClient, strPublishPrefix, "HeartBeat");
}

QByteArray HeartBeat::getAppNameValue(bool &bGetAppName) const
{
    bGetAppName = true;
    return m_strAppName.toLatin1();
}

void HeartBeat::SetPeriodPublish()
{
    bool r = false;
    m_Publisher.PublishPeriodically(this->m_Topic, EnumConverter::ConvertToString(CMD_NetMonitor::CMD_HeartBeat), r, std::bind(&HeartBeat::getAppNameValue, this, std::placeholders::_1), 500);
}
