/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name: 		     // AlarmSubscriber
* Description:  	     // 异常报警模块订阅
* Version:  		     // V1.0.000
* Author:  		         // WRS
* Date:  	             // 2024-1-23
* Modify Record：        // 无
***********************************************************************/

#ifndef ALARMSUBSCRIBER_H
#define ALARMSUBSCRIBER_H

#include "GUIFramework_global.h"
#include "Communication/MQTT/isubscriber.h"
#include "Alarms/Data/alarmsinfo.h"
#include "Alarms/Command/cmd_alarm.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT AlarmSubscriber : public ISubscriber
{
    Q_OBJECT
public:
    explicit AlarmSubscriber(const QString &name, QObject *parent = nullptr);
    ~AlarmSubscriber();

    /// <summary>
    /// 获取单例实例化对象
    /// </summary>
    /// <returns>实例化对象</returns>
    static AlarmSubscriber *getInstance();

signals:
    void sig_AlarmReport(const S_ReportedAlarms &alarms);                   ///异常信息显示信号
    void sig_WriteToFileResult(bool r);                                     ///是否写文本成功信号
    void sig_SendAlarmsInfo(const S_AlarmsInfo &alarmsInfo, bool result);   ///异常配置信息信号
    void sig_HistoryAlarms(const S_ReportedAlarms &);                       ///异常历史记录查询信号

protected slots:
    virtual void decoding(const QString &topic, const QByteArray &message) override;

private:
    static AlarmSubscriber *self;
};

#endif // ALARMSUBSCRIBER_H
