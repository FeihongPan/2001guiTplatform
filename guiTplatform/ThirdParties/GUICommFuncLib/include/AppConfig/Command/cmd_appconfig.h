/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        cmd_appconfig.h
* Description:      AppConfig模块指令
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-2-19
* Modify Record：
***********************************************************************/

#ifndef CMD_APPCONFIG_H
#define CMD_APPCONFIG_H

#include "GUICommFuncLib_global.h"

#include <QObject>

class GUICOMMFUNCLIB_EXPORT CMD_AppConfig : public QObject
{
    Q_OBJECT

public:
    enum Command
    {
        CMD_Config,      // 发出当前AppConfig数据结构
        CMD_SaveConfig,  // 保存当前AppConfig数据结构
    };
    Q_ENUM(Command)

    explicit CMD_AppConfig(QObject *parent = nullptr);

signals:

};

#endif // CMD_APPCONFIG_H
