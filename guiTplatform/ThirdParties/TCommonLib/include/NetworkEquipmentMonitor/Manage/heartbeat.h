/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        heartbeat.h
* Description:      周期性发送心跳检测信号,需要设置Topic的前缀
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-1-16
* Modify Record：
***********************************************************************/

#ifndef HEARTBEAT_H
#define HEARTBEAT_H

#include "TCommonLib_global.h"

#include "Communication/MQTT/ipublish.h"

class TCOMMONLIB_EXPORT HeartBeat : public QObject, public IPublish
{
    Q_OBJECT

public:
    ~HeartBeat();

    /// <summary>
    /// 单例
    /// </summary>
    static HeartBeat *getInstance();

    /// <summary>
    /// 订阅以App名字为Topic前缀发出心跳检测信号
    /// </summary>
    /// <param name="pClient">订阅的client</param>
    /// <param name="strPublishPrefix">Topic前缀</param>
    void LinkHeartBeatToPublishClient(MqttClient *pClient, const QString &strPublishPrefix);

    /// <summary>
    /// 周期性发出心跳检测信号
    /// </summary>
    virtual void SetPeriodPublish() override;

private:
    HeartBeat(const QString &name, QObject *parent = nullptr);
    HeartBeat(const HeartBeat &) = delete;
    HeartBeat &operator=(const HeartBeat &) = delete;

    /// <summary>
    /// Topic前缀类型转换
    /// </summary>
    /// <returns>返回App名字的QByteArray类型</returns>
    QByteArray getAppNameValue(bool &bGetAppName) const;

private:
    static HeartBeat *self;

    QString m_strAppName;
};

#endif // HEARTBEAT_H
