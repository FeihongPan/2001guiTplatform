/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        s_netmonitor.h
* Description:      NET模块数据类型
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-1-16
* Modify Record：
***********************************************************************/

#ifndef S_NETMONITOR_H
#define S_NETMONITOR_H

#include "TCommonLib_global.h"

#include "BasicValue/serializabledic.h"
#include "BasicValue/serializablelist.h"

/// 所有IP监控软件下所有部署软件的实时状态的合集数据结构
class TCOMMONLIB_EXPORT S_Dic_AppState : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_QT_DICT_OBJECTS(QMap, QString, S_Dic_StringBool, values); // m_dic_AllAppState

public:
    S_Dic_AppState();
    S_Dic_AppState(const S_Dic_AppState &dic_AllAppState);
    S_Dic_AppState &operator=(const S_Dic_AppState &dic_AllAppState);
};

/// 接受GUI层对相应IP和部署软件操作命令所需数据类型
class TCOMMONLIB_EXPORT S_AppOperator : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(QString, IP);
    QS_FIELD(QString, appName);

public:
    S_AppOperator();
    S_AppOperator(const S_AppOperator &dic_AppNameInfo);
    S_AppOperator &operator=(const S_AppOperator &dic_AppNameInfo);
};

#endif // S_NETMONITOR_H
