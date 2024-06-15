#ifndef THREADPROCBOARD_H
#define THREADPROCBOARD_H

#include "GUIFramework_global.h"
#include "AuthorityComponent/authoritywidget.h"
#include "ThreadProc/Subscriber/threadprocsubscriber.h"
#include "procctrlwidget.h"

#include <QWidget>
#include <QGroupBox>

namespace Ui
{
    class ThreadProcBoard;
}

class GUIFRAMEWORK_EXPORT CMD_MachineState : public QObject
{
    Q_OBJECT
public:
    enum Command
    {
        CMD_State,
        CMD_Reload,
        CMD_Initialize,
        CMD_AutoInitialize,
        CMD_Run,
        CMD_AutoRun,
        CMD_Pause,
        CMD_Stop,
        CMD_Continue,
        CMD_Terminate,
    };
    Q_ENUM(Command)

    explicit CMD_MachineState(QObject *parent = nullptr) {};
};
class GUIFRAMEWORK_EXPORT MachineState : public QObject
{
    Q_OBJECT
public:
    enum State
    {
        UNKNOWN,
        LOAD_OK,
        LOAD_FAIL,
        INITIALIZING,
        INI_STOPPED,
        INI_OK,
        INI_FAIL,
        RUNNING,
        PAUSE,
        CONTINUING,
        IDLE,
        MET_RUNING,
        MET_FINISHED,
        STOPPED,
        TERMINATE,
    };
    Q_ENUM(State)

    explicit MachineState(QObject *parent = nullptr) {};
};

class GUIFRAMEWORK_EXPORT ThreadProcBoard : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit ThreadProcBoard(QString name, QWidget *parent = nullptr);
    ~ThreadProcBoard() override;

public slots:
    virtual void ConstructFinished() override;
    virtual void RecivedMachineState(int state) override;
protected:
    virtual void setWidgets() override;
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;
    virtual void setConnections() override;

private:
    void setProcessControlWidget(ProcListBasicInfo &info, QGroupBox *parent);

private:
    Ui::ThreadProcBoard *ui;
    QMap<QString, ProcCtrlWidget *> dic_ProcCtrlWidget;
    int wdgWidth = 120;
    int wdgHeight = 30;
    QString style_btn = StyleSheet::getInstance()->ButtonStyle_Back;
    QString style_spb = StyleSheet::getInstance()->SpinBox_Dark;
    TBool bIsActive = false;
};

#endif // THREADPROCBOARD_H
