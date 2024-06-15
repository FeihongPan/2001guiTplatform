#include "threadprocboard.h"
#include "ui_threadprocboard.h"
#include "Language/language.h"
#include "ThreadProc/Command/cmd_threadproc.h"

#include <QLayout>
#include <QLabel>
#include <QPushButton>

ThreadProcBoard::ThreadProcBoard(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::ThreadProcBoard)
{
    ui->setupUi(this);

    Binding(&bIsActive, ui->btn_Active);
    ui->gpb_MonitorProc->setEnabled(false);
}

ThreadProcBoard::~ThreadProcBoard()
{
    delete ui;
}

void ThreadProcBoard::ConstructFinished()
{
    m_Publisher.Publish("ThreadProc", EnumConverter::ConvertToString(CMD_ThreadProc::CMD_InitialProcInfo));
    m_Publisher.Publish("ThreadProc", EnumConverter::ConvertToString(CMD_ThreadProc::CMD_MonitorProcInfo));
    m_Publisher.Publish("ThreadProc", EnumConverter::ConvertToString(CMD_ThreadProc::CMD_AutoRunProcInfo));
}

void ThreadProcBoard::RecivedMachineState(int state)
{
    if(bIsActive.value)
    {
        if(state == MachineState::State::UNKNOWN)
        {
            ui->btn_Active->setEnabled(false);
            ui->btn_SetInitializingState->setEnabled(false);
            ui->btn_SetRunningState->setEnabled(true);
            ui->btn_SetStopState->setEnabled(false);
            ui->gpb_InitialProc->setEnabled(false);
            ui->gpb_AutoRunProc->setEnabled(false);
        }
        else if(state == MachineState::State::LOAD_OK)
        {
            ui->btn_Active->setEnabled(true);
            ui->btn_SetInitializingState->setEnabled(true);
            ui->btn_SetRunningState->setEnabled(true);
            ui->btn_SetStopState->setEnabled(false);
            ui->gpb_InitialProc->setEnabled(false);
            ui->gpb_AutoRunProc->setEnabled(false);
        }
        else if(state == MachineState::State::LOAD_FAIL)
        {
            ui->btn_Active->setEnabled(false);
            ui->btn_SetInitializingState->setEnabled(false);
            ui->btn_SetRunningState->setEnabled(false);
            ui->btn_SetStopState->setEnabled(false);
            ui->gpb_InitialProc->setEnabled(false);
            ui->gpb_AutoRunProc->setEnabled(false);
        }
        else if(state == MachineState::State::INITIALIZING)
        {
            ui->btn_Active->setEnabled(false);
            ui->btn_SetInitializingState->setEnabled(false);
            ui->btn_SetRunningState->setEnabled(false);
            ui->btn_SetStopState->setEnabled(true);
            ui->gpb_InitialProc->setEnabled(true);
            ui->gpb_AutoRunProc->setEnabled(false);
        }
        else if(state == MachineState::State::INI_STOPPED)
        {
            ui->btn_Active->setEnabled(true);
            ui->btn_SetInitializingState->setEnabled(true);
            ui->btn_SetRunningState->setEnabled(false);
            ui->btn_SetStopState->setEnabled(false);
            ui->gpb_InitialProc->setEnabled(false);
            ui->gpb_AutoRunProc->setEnabled(false);
        }
        else if(state == MachineState::State::INI_OK)
        {
            ui->btn_Active->setEnabled(true);
            ui->btn_SetInitializingState->setEnabled(true);
            ui->btn_SetRunningState->setEnabled(true);
            ui->btn_SetStopState->setEnabled(false);
            ui->gpb_InitialProc->setEnabled(false);
            ui->gpb_AutoRunProc->setEnabled(false);
        }
        else if(state == MachineState::State::INI_FAIL)
        {
            ui->btn_Active->setEnabled(true);
            ui->btn_SetInitializingState->setEnabled(true);
            ui->btn_SetRunningState->setEnabled(false);
            ui->btn_SetStopState->setEnabled(false);
            ui->gpb_InitialProc->setEnabled(false);
            ui->gpb_AutoRunProc->setEnabled(false);
        }
        else if(state == MachineState::State::RUNNING)
        {
            ui->btn_Active->setEnabled(false);
            ui->btn_SetInitializingState->setEnabled(false);
            ui->btn_SetRunningState->setEnabled(false);
            ui->btn_SetStopState->setEnabled(true);
            ui->gpb_InitialProc->setEnabled(false);
            ui->gpb_AutoRunProc->setEnabled(true);
        }
        else if(state == MachineState::State::PAUSE
                || state == MachineState::State::CONTINUING
                || state == MachineState::State::IDLE)
        {
            ui->btn_Active->setEnabled(false);
            ui->btn_SetInitializingState->setEnabled(false);
            ui->btn_SetRunningState->setEnabled(false);
            ui->btn_SetStopState->setEnabled(false);
            ui->gpb_InitialProc->setEnabled(false);
            ui->gpb_AutoRunProc->setEnabled(false);
        }
        else if(state == MachineState::State::STOPPED)
        {
            ui->btn_Active->setEnabled(true);
            ui->btn_SetInitializingState->setEnabled(true);
            ui->btn_SetRunningState->setEnabled(false);
            ui->btn_SetStopState->setEnabled(false);
            ui->gpb_InitialProc->setEnabled(false);
            ui->gpb_AutoRunProc->setEnabled(false);
        }
        else if(state == MachineState::State::TERMINATE)
        {
            ui->btn_Active->setEnabled(false);
            ui->btn_SetInitializingState->setEnabled(false);
            ui->btn_SetRunningState->setEnabled(false);
            ui->btn_SetStopState->setEnabled(false);
            ui->gpb_InitialProc->setEnabled(false);
            ui->gpb_AutoRunProc->setEnabled(false);
        }
    }
    else
    {
        ui->btn_Active->setEnabled(true);
        ui->btn_SetInitializingState->setEnabled(false);
        ui->btn_SetRunningState->setEnabled(false);
        ui->btn_SetStopState->setEnabled(false);
        ui->gpb_InitialProc->setEnabled(false);
        ui->gpb_AutoRunProc->setEnabled(false);
    }
}

void ThreadProcBoard::setWidgets()
{

}

void ThreadProcBoard::setWidgetStyleSheet()
{
    ui->gpb_MonitorProc->SetheaderFontSize(16);
    ui->gpb_MonitorProc->SetHeaderText(Tr("Monitor Process"));

    ui->gpb_InitialProc->SetheaderFontSize(16);
    ui->gpb_InitialProc->SetHeaderText(Tr("Initial Process"));

    ui->gpb_AutoRunProc->SetheaderFontSize(16);
    ui->gpb_AutoRunProc->SetHeaderText(Tr("AutoRun Process"));

    ui->btn_Active->setStyleSheet(StyleSheet::getInstance()->ButtonStyle_Back);
    ui->btn_SetInitializingState->setStyleSheet(StyleSheet::getInstance()->ButtonStyle_Back);
    ui->btn_SetRunningState->setStyleSheet(StyleSheet::getInstance()->ButtonStyle_Back);
    ui->btn_SetStopState->setStyleSheet(StyleSheet::getInstance()->ButtonStyle_Back);
}

void ThreadProcBoard::setLanguageKeys()
{

}

void ThreadProcBoard::setConnections()
{
    connect(ThreadProcSubscriber::getInstance(), &ThreadProcSubscriber::sig_MonitorProcSingalInfo, this, [ = ](ProcListBasicInfo & info, bool result)
    {
        setProcessControlWidget(info, ui->gpb_MonitorProc);
    });

    connect(ThreadProcSubscriber::getInstance(), &ThreadProcSubscriber::sig_InitialProcSingalInfo, this, [ = ](ProcListBasicInfo & info, bool result)
    {
        setProcessControlWidget(info, ui->gpb_InitialProc);
    });

    connect(ThreadProcSubscriber::getInstance(), &ThreadProcSubscriber::sig_AutoRunProcSingalInfo, this, [ = ](ProcListBasicInfo & info, bool result)
    {
        setProcessControlWidget(info, ui->gpb_AutoRunProc);
    });

    connect(ThreadProcSubscriber::getInstance(), &ThreadProcSubscriber::sig_ProcessStates, this, [ = ](S_ProcListData & lst_ProcData, bool result)
    {
        QStringList lst_ProcNames = lst_ProcData.dic_PorcListData.keys();
        for(int i = 0; i < lst_ProcNames.count(); i++)
        {
            if(dic_ProcCtrlWidget.contains(lst_ProcNames[i]))
            {
                dic_ProcCtrlWidget[lst_ProcNames[i]]->SetProcData(lst_ProcData.dic_PorcListData[lst_ProcNames[i]]);
            }
        }
    });

    connect(ui->btn_Active, &QPushButton::clicked, this, [ = ]
    {
        RecivedMachineState(this->m_MachineState);
    });

    connect(ui->btn_SetInitializingState, &QPushButton::clicked, this, [ = ]
    {
        m_Publisher.Publish("MachineState", EnumConverter::ConvertToString(CMD_MachineState::CMD_Initialize));
    });

    connect(ui->btn_SetRunningState, &QPushButton::clicked, this, [ = ]
    {
        m_Publisher.Publish("MachineState", EnumConverter::ConvertToString(CMD_MachineState::CMD_Run));
    });

    connect(ui->btn_SetStopState, &QPushButton::clicked, this, [ = ]
    {
        m_Publisher.Publish("MachineState", EnumConverter::ConvertToString(CMD_MachineState::CMD_Stop));
    });
}

void ThreadProcBoard::setProcessControlWidget(ProcListBasicInfo &info, QGroupBox *parent)
{

    QStringList lst_Names = info.dic_ProcInfo.keys();
    for(int i = 0; i < lst_Names.count(); i++)
    {
        if(dic_ProcCtrlWidget.contains(lst_Names[i]))
        {
            return;
        }
    }

    QVBoxLayout *layout = new QVBoxLayout(parent);
    for(int i = 0; i < lst_Names.count(); i++)
    {
        ProcCtrlWidget *wdg = new ProcCtrlWidget(lst_Names[i]);
        wdg->ItemInitialize();
        wdg->SetSignalItem(info.dic_ProcInfo[lst_Names[i]].values);

        connect(wdg, &ProcCtrlWidget::Start, this, [ = ](S_SingleProcData & procData)
        {
            S_ProcListData procListData;
            procListData.dic_PorcListData.insert(procData.processName, procData);
            m_Publisher.Publish("ThreadProc", EnumConverter::ConvertToString(CMD_ThreadProc::CMD_Start), false, procListData.toRawJson());
        });

        connect(wdg, &ProcCtrlWidget::Stop, this, [ = ](S_SingleProcData & procData)
        {
            S_ProcListData procListData;
            procListData.dic_PorcListData.insert(procData.processName, procData);
            m_Publisher.Publish("ThreadProc", EnumConverter::ConvertToString(CMD_ThreadProc::CMD_Stop), false, procListData.toRawJson());
        });

        connect(wdg, &ProcCtrlWidget::Reset, this, [ = ](S_SingleProcData & procData)
        {
            S_ProcListData procListData;
            procListData.dic_PorcListData.insert(procData.processName, procData);
            m_Publisher.Publish("ThreadProc", EnumConverter::ConvertToString(CMD_ThreadProc::CMD_Reset), false, procListData.toRawJson());
        });

        connect(wdg, &ProcCtrlWidget::SetSingleStepModel, this, [ = ](S_SingleProcData & procData)
        {
            S_ProcListData procListData;
            procListData.dic_PorcListData.insert(procData.processName, procData);
            m_Publisher.Publish("ThreadProc", EnumConverter::ConvertToString(CMD_ThreadProc::CMD_SetSingleStepModel), false, procListData.toRawJson());
        });

        connect(wdg, &ProcCtrlWidget::NextStep, this, [ = ](S_SingleProcData & procData)
        {
            S_ProcListData procListData;
            procListData.dic_PorcListData.insert(procData.processName, procData);
            m_Publisher.Publish("ThreadProc", EnumConverter::ConvertToString(CMD_ThreadProc::CMD_NextStep), false, procListData.toRawJson());
        });

        connect(wdg, &ProcCtrlWidget::SetSignal, this, [ = ](S_SingleProcData & procData)
        {
            S_ProcListData procListData;
            procListData.dic_PorcListData.insert(procData.processName, procData);
            qDebug() << "ProcCtrlWidget::SetSignal" << procListData.toRawJson();
            m_Publisher.Publish("ThreadProc", EnumConverter::ConvertToString(CMD_ThreadProc::CMD_SetInputSignal), false, procListData.toRawJson());
        });

        layout->addWidget(wdg);
        dic_ProcCtrlWidget.insert(lst_Names[i], wdg);
    }
    layout->setMargin(50);
    layout->setSpacing(20);
    layout->addStretch();
}
