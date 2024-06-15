/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name: 		     // CMD_Alarm
* Description:  	     // 异常信息模块指令
* Version:  		     // V1.0.000
* Author:  		         // WRS
* Date:  	             // 2024-1-22
* Modify Record：
***********************************************************************/

#ifndef CMD_ALARM_H
#define CMD_ALARM_H

#include "GUIFramework_global.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT CMD_Alarm : public QObject
{
    Q_OBJECT
public:
    enum Command
    {
        CMD_AlarmReport,      ///更新报警记录信息
        CMD_AlarmHandle,      ///报警处理
        CMD_SaveAlarmsInfo,   ///报警配置保存
        CMD_AlarmsInfo,       ///更新报警配置信息
        CMD_AlarmsHistory,    ///历史数据查询
    };
    Q_ENUM(Command)

    explicit CMD_Alarm(QObject *parent = nullptr);
};

#endif // CMD_ALARM_H
