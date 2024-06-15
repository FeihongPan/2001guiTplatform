/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name: 		     // HistoryAlarmsModel
* Description:  	     // 异常报警记录数据模型
* Version:  		     // V1.0.000
* Author:  		         // WRS
* Date:  	             // 2024-1-22
* Modify Record：        // 无
***********************************************************************/

#ifndef HISTORYALARMSMODEL_H
#define HISTORYALARMSMODEL_H

#include "GUIFramework_global.h"
#include "Alarms/Data/alarmsinfo.h"

#include <QAbstractTableModel>

class GUIFRAMEWORK_EXPORT HistoryAlarmsModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit HistoryAlarmsModel(QObject *parent = nullptr);

    /// <summary>
    /// 设置表头内容
    /// </summary>
    /// <param name="lst_Header">表头列表</param>
    /// <returns>无</returns>
    void SetHeader(const QStringList &lst_Header);

    /// <summary>
    /// 设置报警数据模型
    /// </summary>
    /// <param name="pAlarms">报警记录模型指针</param>
    /// <returns>无</returns>
    void SetModel(S_ReportedAlarms *pAlarms);

    /// <summary>
    /// 重置报警数据模型
    /// </summary>
    /// <param name="pAlarms">报警记录模型</param>
    /// <returns>无</returns>
    void ResetModel(S_ReportedAlarms *pAlarms);

    /// <summary>
    /// 获取报警记录数据
    /// </summary>
    /// <returns>S_ReportedAlarms</returns>
    S_ReportedAlarms *GetData();

public:
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private:
    S_ReportedAlarms *p_HistoryAlarms{nullptr};                      ///报警记录数据指针
    QHash<S_AlarmData::ErrorHandlingMethod, QString> m_dic_Method;   ///异常处理方式
    QStringList m_lst_Header;                                            ///表头数据
};

#endif // HISTORYALARMSMODEL_H
