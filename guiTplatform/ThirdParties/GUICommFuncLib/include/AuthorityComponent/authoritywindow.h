#ifndef AUTHORITYWINDOW_H
#define AUTHORITYWINDOW_H

#include "GUICommFuncLib_global.h"
#include "AuthorityManage/Data/userinfo.h"
#include "AuthorityManage/Subscriber/userSubscriber.h"
#include "Communication/MQTT/publisher.h"

#include <QMainWindow>
#include <QPushButton>

class GUICOMMFUNCLIB_EXPORT AuthorityWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AuthorityWindow(QWidget *parent = nullptr);

signals:
    void MainWindowIntialized();
    void MachineContollerLoadFinished();
    void MachineStateChanged(int state);

protected:
    virtual void userChanged(S_UserInfo &user) {};

public:
    S_UserInfo user;
    int state = 0;
    Publisher m_Publisher;
};

#endif // AUTHORITYWINDOW_H
