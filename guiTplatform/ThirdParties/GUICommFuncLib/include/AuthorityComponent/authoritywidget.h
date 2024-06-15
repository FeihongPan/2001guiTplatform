#ifndef AUTHORITYWIDGET_H
#define AUTHORITYWIDGET_H

#include "navibutton.h"
#include "GUICommFuncLib_global.h"
#include "AuthorityManage/WidgetManage/authoritywdginfo.h"
#include "BindableComponent/bindablewidget.h"
#include "Communication/MQTT/publisher.h"
#include "Communication/MQTT/ipublish.h"

#include <QStackedWidget>
#include <QHBoxLayout>

class GUICOMMFUNCLIB_EXPORT AuthorityWidget : public BindableWidget
{
    Q_OBJECT

public:
    explicit AuthorityWidget(QString name, QWidget *parent = nullptr);

    void SetWdgStatus(ViewStatus::Status status);
    void ItemInitialize(bool left);
    void ItemInitialize();
    void SetMachineState(int state);
    void PublisherInitialize();

signals:
    void ViewStatusChanged(ViewStatus::Status status);
    void MachineStateChanged(int state);
    void Signal_ConstructFinished();
    void Signal_MachineControllerLoadFinished();

public slots:
    void RecivedViewStatus(ViewStatus::Status status);

    /// 所有View构建完成后会调用该方法
    virtual void ConstructFinished() {};
    virtual void MachineControllerLoadFinished() {};

    /// 接收到控制层状态机状态发生变化时会调用该方法
    virtual void RecivedMachineState(int state) {};

    virtual void UserChanged(S_UserInfo &user) {};

protected:
    void setLayoutWidgets(QHBoxLayout *layout, QStackedWidget *stackWidget, QFrame *frame_SubNavi);

    /// 设置页面自动生成的控件及布局等，该方法会在页面构建时调用
    virtual void setWidgets() {};

    /// 设置页面各控件的样式表，该方法会在页面构建时调用
    virtual void setWidgetStyleSheet() {};

    /// 设置语言翻译，该方法会在页面构建时调用
    virtual void setLanguageKeys() {};

    /// 建立信号和槽，该方法会在页面构建时调用
    virtual void setConnections() {};

private:
    void layoutInitial(bool leftSide = false);

public:
    AuthorityWdgInfo *wdgInfo;
    AuthorityWidget *parentWidget;
    QList<AuthorityWidget *> lst_SubWidget;
    QMap<int, QPushButton *> dic_SubButtons;
    QStackedWidget *stackWidget = NULL;
    QFrame *frame_SubNavi = NULL;
    QHBoxLayout *layout = NULL;
    NaviButton *btn;
    S_UserInfo user;
    ViewStatus::Status status = ViewStatus::Status::Idle;
    int m_MachineState;
    Publisher m_Publisher;
};

#endif // AUTHORITYWIDGET_H
