/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        networkequipmentsubscriber.h
* Description:      接收GUI层发来的命令，并且传给NetworkEquipmentManager进行处理
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-1-16
* Modify Record：
***********************************************************************/

#ifndef NETWORKEQUIPMENTSUBSCRIBER_H
#define NETWORKEQUIPMENTSUBSCRIBER_H

#include "TCommonLib_global.h"

#include "Communication/MQTT/isubscriber.h"

class TCOMMONLIB_EXPORT NetworkEquipmentSubscriber : public ISubscriber
{
    Q_OBJECT

public:
    ~NetworkEquipmentSubscriber();
    /// <summary>
    /// 单例
    /// </summary>
    static NetworkEquipmentSubscriber *getInstance();

private slots:
    /// <summary>
    /// 将指令解析并且发给Manager
    /// </summary>
    virtual void decoding(const QString &topic, const QByteArray &message) override;

private:
    explicit NetworkEquipmentSubscriber(const QString &name, QObject *parent = nullptr);
    NetworkEquipmentSubscriber(const NetworkEquipmentSubscriber &) = delete;
    NetworkEquipmentSubscriber &operator=(const NetworkEquipmentSubscriber &) = delete;

private:
    static NetworkEquipmentSubscriber *self;
};

#endif // NETWORKEQUIPMENTSUBSCRIBER_H
