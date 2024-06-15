/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        appconfigview.h
* Description:      aAppConfig修改主界面
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-2-19
* Modify Record：
***********************************************************************/

#ifndef APPCONFIGVIEW_H
#define APPCONFIGVIEW_H

#include "GUICommFuncLib_global.h"

#include "AuthorityComponent/authoritywidget.h"
#include "AppConfig/Data/appconfig.h"

#include <QWidget>

namespace Ui
{
    class AppConfigView;
}

class GUICOMMFUNCLIB_EXPORT AppConfigView : public AuthorityWidget
{
    Q_OBJECT

public:
    /// <summary>
    /// 构造函数
    /// </summary>
    explicit AppConfigView(QString name, QWidget *parent = nullptr);

    /// <summary>
    /// 析构函数
    /// </summary>
    ~AppConfigView();

public:
    /// 所有View构建完成后会调用该方法
    virtual void ConstructFinished() override;

protected:
    virtual void setWidgets() override;
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;
    virtual void setConnections() override;

private:
    Ui::AppConfigView *ui;
    AppConfig m_AppConfig;
};



#endif // APPCONFIGVIEW_H
