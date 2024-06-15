/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name: 		     // AlarmEditView
* Description:  	     // 异常报警信息配置界面
* Version:  		     // V1.0.000
* Author:  		         // WRS
* Date:  	             // 2024-1-22
* Modify Record：        // 无
***********************************************************************/

#ifndef ALARMEDITVIEW_H
#define ALARMEDITVIEW_H

#include "GUIFramework_global.h"
#include "AuthorityComponent/authoritywidget.h"
#include "Alarms/Views/alarmeditmodel.h"

#include <QWidget>

namespace Ui
{
    class AlarmEditView;
}

class GUIFRAMEWORK_EXPORT AlarmEditView : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit AlarmEditView(const QString &name, QWidget *parent = nullptr);
    ~AlarmEditView();

    /// <summary>
    /// 获取UI界面指针
    /// </summary>
    /// <returns>UI界面指针</returns>
    Ui::AlarmEditView *GetUI();

    /// <summary>
    /// 类构建完成动作
    /// </summary>
    /// <returns>无</returns>
    virtual void ConstructFinished() override;

public slots:
    /// <summary>
    /// 写入文件是否成功弹窗提示
    /// </summary>
    /// <param name="bResult">写入文件结果</param>
    /// <returns>无</returns>
    void on_WriteToFileResult(const bool &bResult);

    /// <summary>
    /// 更新报警配置信息列表
    /// </summary>
    /// <param name="alarmsInfo">报警配置信息</param>
    /// <param name="result">结果</param>
    /// <returns>无</returns>
    void on_UpdateView(const S_AlarmsInfo &alarmsInfo, const bool &result);

private:
    virtual void setWidgets() override;
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;
    virtual void setConnections() override;

    /// <summary>
    /// 数据模型初始化
    /// </summary>
    /// <returns>无</returns>
    void modelInitialize();

private slots:
    /// <summary>
    /// 异常信息列表筛选
    /// </summary>
    /// <param name="strText">筛选字符内容</param>
    /// <returns>无</returns>
    void on_Filter(const QString &strText);

    /// <summary>
    /// 添加异常信息
    /// </summary>
    /// <returns>无</returns>
    void on_CreateNew();

    /// <summary>
    /// 删除异常信息
    /// </summary>
    /// <returns>无</returns>
    void on_Delete();

    /// <summary>
    /// 取消操作，返回当前保存的状态
    /// </summary>
    /// <returns>填写返回值的说明</returns>
    void on_Abandon();

    /// <summary>
    /// 保存当前操作
    /// </summary>
    /// <returns>无</returns>
    void on_Save();

private:
    Ui::AlarmEditView *ui;
    AlarmEditModel *p_AlarmEditModel{nullptr};   ///报警配置信息数据模型指针
    S_AlarmsInfo m_AlarmsInfo;                   ///报警信息列表
    S_AlarmsInfo m_AlarmsInfoBack;               ///报警信息列表备份

};

#endif // ALARMEDITVIEW_H
