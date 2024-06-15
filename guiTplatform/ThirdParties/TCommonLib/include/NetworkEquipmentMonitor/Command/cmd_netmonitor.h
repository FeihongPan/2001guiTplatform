/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        cmd_netmonitor.h
* Description:      NET模块指令
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-1-16
* Modify Record：
***********************************************************************/

#ifndef CMD_NETMONITOR_H
#define CMD_NETMONITOR_H

#include "TCommonLib_global.h"

#include <QObject>

class TCOMMONLIB_EXPORT CMD_NetMonitor : public QObject
{
    Q_OBJECT

public:
    enum Command
    {
        CMD_HeartBeat, // 心跳检测的指令
        CMD_AppState, // 接收App状态的指令
        CMD_AppOpen, // 打开App状态的指令
        CMD_AppClose, // 关闭App状态的指令
        CMD_AppRestart, // 重启App状态的指令
        CMD_AppOpenMC, // 打开MC的指令
    };
    Q_ENUM(Command)
};

#endif // CMD_NETMONITOR_H
