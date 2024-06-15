/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        s_netmonitor.cpp
* Description:      NET模块数据类型
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-1-16
* Modify Record：
***********************************************************************/

#include "s_netmonitor.h"

S_Dic_AppState::S_Dic_AppState()
{

}

S_Dic_AppState::S_Dic_AppState(const S_Dic_AppState &dic_AllAppState)
{
    values = dic_AllAppState.values;
}

S_Dic_AppState &S_Dic_AppState::operator=(const S_Dic_AppState &dic_AllAppState)
{
    values = dic_AllAppState.values;
    return *this;
}

S_AppOperator::S_AppOperator()
{

}

S_AppOperator::S_AppOperator(const S_AppOperator &dic_AppNameInfo)
{
    IP = dic_AppNameInfo.IP;
    appName = dic_AppNameInfo.appName;
}

S_AppOperator &S_AppOperator::operator=(const S_AppOperator &dic_AppNameInfo)
{
    IP = dic_AppNameInfo.IP;
    appName = dic_AppNameInfo.appName;
    return *this;
}
