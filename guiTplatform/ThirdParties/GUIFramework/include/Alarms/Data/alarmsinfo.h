/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name: 		     // AlarmsInfo
* Description:  	     // 异常信息模块数据结构
* Version:  		     // V1.0.000
* Author:  		         // WRS
* Date:  	             // 2024-1-22
* Modify Record：
***********************************************************************/

#ifndef ALARMSINFO_H
#define ALARMSINFO_H

#include "GUIFramework_global.h"
#include "Serializer/QSerializer"

#include <QMap>

class GUIFRAMEWORK_EXPORT S_AlarmData : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

public:
    enum ErrorHandlingMethod
    {
        Retry = 0,     ///重试
        Skip,          ///跳过
        Continue,      ///继续
        Reset,         ///重置
    };
    Q_ENUM(ErrorHandlingMethod)

    QS_QT_DICT(QMap, ErrorHandlingMethod, bool, dic_Methodvalidity)   ///处理方式
    QS_FIELD(QString, alarmCode)                                      ///异常代号
    QS_FIELD(QString, message)                                        ///信息
    QS_FIELD(QString, brief)                                          ///详情

public:
    S_AlarmData();
    S_AlarmData(const S_AlarmData &alarm);
    S_AlarmData &operator=(const S_AlarmData &alarm);
    bool operator==(S_AlarmData &alarm);
};

class GUIFRAMEWORK_EXPORT S_AlarmsInfo : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, S_AlarmData, lst_AlarmsData);    ///异常信息列表

public:
    S_AlarmsInfo();
    S_AlarmsInfo(const S_AlarmsInfo &alarm);
    S_AlarmsInfo &operator=(const S_AlarmsInfo &alarm);
};


class GUIFRAMEWORK_EXPORT S_ReportedAlarm : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_AlarmData, alarmData)                            ///异常信息
    QS_FIELD(S_AlarmData::ErrorHandlingMethod, handlingMethod)   ///异常处理方式
    QS_FIELD(QString, reportTime)                                ///异常发生时间
    QS_FIELD(QString, releaseUser)                               ///异常处理用户
    QS_FIELD(QString, releaseTime)                               ///异常处理时间
    QS_FIELD(QString, addtionalNotes)                            ///备注信息

public:
    S_ReportedAlarm();
    S_ReportedAlarm(const S_ReportedAlarm &alarm);
    S_ReportedAlarm &operator=(const S_ReportedAlarm &alarm);

    bool operator<(const S_ReportedAlarm &alarm) const;
    bool operator==(const S_ReportedAlarm &alarm);
    bool operator!=(const S_ReportedAlarm &alarm);
};

class GUIFRAMEWORK_EXPORT S_ReportedAlarms : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, S_ReportedAlarm, lst_ReportedAlarms);   ///异常记录信息列表

public:
    S_ReportedAlarms();
    S_ReportedAlarms(const S_ReportedAlarms &alarm);
    S_ReportedAlarms &operator=(const S_ReportedAlarms &alarm);
};

#endif // ALARMSINFO_H
