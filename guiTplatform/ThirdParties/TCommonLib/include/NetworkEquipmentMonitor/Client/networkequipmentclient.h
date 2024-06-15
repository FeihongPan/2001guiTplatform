/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        networkequipmentclient.h
* Description:      接收来自对应IP监控软件的所有部署软件的实时状态，并且发给NetworkEquipmentManager
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-1-16
* Modify Record：
***********************************************************************/

#ifndef NETWORKEQUIPMENTCLIENT_H
#define NETWORKEQUIPMENTCLIENT_H

#include "TCommonLib_global.h"

#include "BasicValue/serializabledic.h"
#include "Communication/MQTT/imqttclient.h"

class TCOMMONLIB_EXPORT NetworkEquipmentClient : public IMqttClient
{
    Q_OBJECT

public:
    NetworkEquipmentClient(const QString &name, QObject *parent = nullptr);

    ~NetworkEquipmentClient();

    /// <summary>
    /// 向对应的IP发出打开app的指令
    /// </summary>
    /// <param name="strAppName">app名字</param>
    void OpenApp(const QString &strAppName);

    /// <summary>
    /// 向对应的IP发出关闭app的指令
    /// </summary>
    /// <param name="strAppName">app名字</param>
    void CloseApp(const QString &strAppName);

    /// <summary>
    /// 向对应的IP发出重启app的指令
    /// </summary>
    /// <param name="strAppName">app名字</param>
    void RestartApp(const QString &strAppName);

private:
    /// <summary>
    /// 接受来自相应IP监控软件的消息, Topic为NMS_IP
    /// </summary>
    virtual void decoding(const QString &task, bool result, const QByteArray &msg, const QByteArray &errMsg) override;

signals:
    /// <summary>
    /// 发送对应IP下的部署软件实时状态发给给NetworkEquipmentManager
    /// </summary>
    /// <param name="strAppName">app名字</param>
    void sig_SendAppState(S_Dic_StringBool &dic_AppState, bool res);
};

#endif // NETWORKEQUIPMENTCLIENT_H
