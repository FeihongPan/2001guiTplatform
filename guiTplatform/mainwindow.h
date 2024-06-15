#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "AuthorityComponent/authoritywindow.h"

#include <QGraphicsBlurEffect>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public AuthorityWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void CloseProgram();

    QGraphicsBlurEffect *blurEffect;

signals:
    void SendAuthorityCheckResult(int res);
    void Closing();
    void TestSignal();

protected:
    virtual void userChanged(S_UserInfo &user) override;

private:
    void setWindowStyle();
    void naviBtnInitial();
    void titleWidgetInitial();
    void subFormInitialize();

    void setTimer();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    TBool m_bServerConnected = false;
};
#endif // MAINWINDOW_H
