/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name: 		     // ReportAlarmView
* Description:  	     // 异常报警显示处理界面
* Version:  		     // V1.0.000
* Author:  		         // WRS
* Date:  	             // 2024-1-22
* Modify Record：        // 无
***********************************************************************/

#ifndef REPORTALARMVIEW_H
#define REPORTALARMVIEW_H

#include "GUIFramework_global.h"
#include "AuthorityComponent/authoritywidget.h"
#include "CustomerWidget/Button/effectbutton.h"
#include "Alarms/Views/reportedalarmsmodel.h"

#include <QWidget>
#include <QWaitCondition>
#include <QMutex>

namespace Ui
{
    class ReportAlarmView;
}

class GUIFRAMEWORK_EXPORT ReportAlarmView : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit ReportAlarmView(const QString &name, QWidget *parent = nullptr);
    ~ReportAlarmView();

    /// <summary>
    /// 获取UI界面指针
    /// </summary>
    /// <returns>无</returns>
    Ui::ReportAlarmView *GetUI();

    /// <summary>
    /// 处理报警
    /// </summary>
    /// <param name="alarmCode">报警Code</param>
    /// <param name="method">处理方式</param>
    /// <returns>无</returns>
    void ReleaseAlarm(const QString &strAlarmCode, const int &nMethod);

public slots:
    /// <summary>
    /// 更新报警记录
    /// </summary>
    /// <param name="alarms">报警列表</param>
    /// <returns>无</returns>
    void on_AlarmReport(const S_ReportedAlarms &alarms);

private:
    virtual void setWidgets() override;
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;
    virtual void setConnections() override;

    /// <summary>
    /// 初始化报警模型数据
    /// </summary>
    /// <returns>无</returns>
    void modelInitialize();

    /// <summary>
    /// 更新按钮状态
    /// </summary>
    /// <returns>无</returns>
    void refreshViewInfo();

    /// <summary>
    /// 重置发送处理报警后各参数
    /// </summary>
    /// <returns>无</returns>
    void alarmTableHandled();

    /// <summary>
    /// 发送的处理报警
    /// </summary>
    /// <returns>无</returns>
    void sendHandleCommand(const S_AlarmData::ErrorHandlingMethod &method);

private slots:
    /// <summary>
    /// 表格行点击动作
    /// </summary>
    /// <param name="QModelIndex">点击的表格索引</param>
    /// <returns>无</returns>
    void on_CellClicked(const QModelIndex &index);

private:
    Ui::ReportAlarmView *ui;
    ReportedAlarmsModel *p_ReportedAlarmsModel{nullptr};  ///报警数据模型
    S_ReportedAlarm *p_SelectedAlarm{nullptr};            ///选中行数据
    S_ReportedAlarms m_ReportedAlarms;                    ///报警显示数据
    QMutex m_Mutex;                                       ///数据锁
};

#endif // REPORTALARMVIEW_H
