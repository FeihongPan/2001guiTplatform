/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name: 		     // AlarmEditModel
* Description:  	     // 异常报警信息配置数据模型
* Version:  		     // V1.0.000
* Author:  		         // WRS
* Date:  	             // 2024-1-23
* Modify Record：        // 无
***********************************************************************/

#ifndef ALARMEDITMODEL_H
#define ALARMEDITMODEL_H

#include "GUIFramework_global.h"
#include "Alarms/Data/alarmsinfo.h"

#include <QAbstractTableModel>

class GUIFRAMEWORK_EXPORT AlarmEditModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit AlarmEditModel(QObject *parent = nullptr);

    /// <summary>
    /// 设置异常信息数据模型
    /// </summary>
    /// <param name="pAlarms">异常信息数据指针</param>
    /// <returns>无</returns>
    void SetModel(S_AlarmsInfo *pAlarms);

    /// <summary>
    /// 设置表头内容
    /// </summary>
    /// <param name="lst_Header">表头列表</param>
    /// <returns>无</returns>
    void SetHeader(const QStringList &lst_Header);

    /// <summary>
    /// 添加异常信息数据
    /// </summary>
    /// <param name="nRow">行</param>
    /// <param name="alarm">异常信息</param>
    /// <returns>无</returns>
    bool AddModelData(const int &nRow, const S_AlarmData &alarm);

    /// <summary>
    /// 删除异常信息数据
    /// </summary>
    /// <param name="nRow">行</param>
    /// <returns>无</returns>
    bool DeleteModelData(const int &nRow);

    /// <summary>
    /// 重置异常信息数据模型
    /// </summary>
    /// <param name="pAlarms">异常信息数据指针</param>
    /// <returns>无</returns>
    void ResetModel(S_AlarmsInfo *pAlarms);

public:
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    S_AlarmsInfo *m_AlarmsInfo{nullptr};   ///异常信息数据指针
    QStringList m_lst_Header;                  ///表头数据
};

#endif // ALARMEDITMODEL_H
