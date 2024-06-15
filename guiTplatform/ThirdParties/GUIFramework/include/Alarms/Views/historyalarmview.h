/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name: 		     // HistoryAlarmView
* Description:  	     // 异常报警历史记录查询界面
* Version:  		     // V1.0.000
* Author:  		         // WRS
* Date:  	             // 2024-1-22
* Modify Record：        // 无
***********************************************************************/

#ifndef HISTORYALARMVIEW_H
#define HISTORYALARMVIEW_H

#include "GUIFramework_global.h"
#include "AuthorityComponent/authoritywidget.h"
#include "historyalarmsmodel.h"
#include "reportedalarmsmodel.h"

#include <QTableView>
#include <QWidget>

namespace Ui
{
    class HistoryAlarmView;
}

class GUIFRAMEWORK_EXPORT HistoryAlarmView : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit HistoryAlarmView(const QString &strName, QWidget *parent = nullptr);
    ~HistoryAlarmView();

public slots:
    /// <summary>
    /// 更新显示异常报警记录
    /// </summary>
    /// <param name="alarms">异常报警记录列表</param>
    /// <returns>无</returns>
    void on_UpdateView(const S_ReportedAlarms &alarms);

private:
    virtual void setWidgets() override;
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;
    virtual void setConnections() override;

    /// <summary>
    /// 初始化表格
    /// </summary>
    /// <returns>无</returns>
    void initTable(QTableView *pTable);

private slots:
    /// <summary>
    /// 记录查询
    /// </summary>
    /// <returns>无</returns>
    void on_Search();

    /// <summary>
    /// 起始日期变化
    /// </summary>
    /// <param name="date">起始日期</param>
    /// <returns>无</returns>
    void on_DateStart(const QDate &date);

    /// <summary>
    /// 终止日期变化
    /// </summary>
    /// <param name="alarms">终止日期</param>
    /// <returns>无</returns>
    void on_DateEnd(const QDate &date);

    /// <summary>
    /// 筛选内容变化
    /// </summary>
    /// <param name="strText">当前筛选内容</param>
    /// <returns>无</returns>
    void on_Filter(const QString &strText);

private:
    Ui::HistoryAlarmView *ui;
    HistoryAlarmsModel *p_HistoryModel{nullptr};    ///报警记录模型
    S_ReportedAlarms m_ReportedAlarms;              ///报警记录数据
};

#endif // HISTORYALARMVIEW_H
