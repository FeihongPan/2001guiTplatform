#include "threadprocsubscriber.h"
#include "ThreadProc/Data/processdata.h"
#include "ThreadProc/Command/cmd_threadproc.h"
#include "Converter/enumconverter.h"

#include <QMutex>

ThreadProcSubscriber *ThreadProcSubscriber::self = nullptr;
ThreadProcSubscriber::ThreadProcSubscriber(QString name, QObject *parent) : ISubscriber(name, parent)
{
    qRegisterMetaType<ProcListBasicInfo>("ProcListBasicInfo");
    qRegisterMetaType<ProcListBasicInfo>("ProcListBasicInfo&");
    qRegisterMetaType<S_ProcListData>("S_ProcListData");
    qRegisterMetaType<S_ProcListData>("S_ProcListData&");
}

ThreadProcSubscriber::~ThreadProcSubscriber()
{

}

ThreadProcSubscriber *ThreadProcSubscriber::getInstance()
{
    if(self == nullptr)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == nullptr)
        {
            self = new ThreadProcSubscriber("ThreadProcSubscriber");
        }
    }
    return self;
}

void ThreadProcSubscriber::decoding(const QString &topic, const QByteArray &message)
{
    //    qDebug() << "ThreadProcSubscriber::decoding" << topic << message;
    TaskInfo task_Recived;
    task_Recived.fromJson(message);
    CMD_ThreadProc::Command cmd = EnumConverter::ConvertStringToEnum<CMD_ThreadProc::Command>(task_Recived.task);
    //qDebug() << "ThreadProcSubscriber::decoding" << task_Recived.task;
    switch (cmd)
    {
        case CMD_ThreadProc::CMD_AllProcInfo:
            {
                ProcListBasicInfo info;
                info.fromJson(task_Recived.context);
                emit sig_AllProcSingalInfo(info, task_Recived.result);
            }
            break;

        case CMD_ThreadProc::CMD_InitialProcInfo:
            {
                ProcListBasicInfo info;
                info.fromJson(task_Recived.context);
                emit sig_InitialProcSingalInfo(info, task_Recived.result);
            }
            break;

        case CMD_ThreadProc::CMD_MonitorProcInfo:
            {
                ProcListBasicInfo info;
                info.fromJson(task_Recived.context);
                emit sig_MonitorProcSingalInfo(info, task_Recived.result);
            }
            break;

        case CMD_ThreadProc::CMD_AutoRunProcInfo:
            {
                ProcListBasicInfo info;
                info.fromJson(task_Recived.context);
                emit sig_AutoRunProcSingalInfo(info, task_Recived.result);
            }
            break;

        case CMD_ThreadProc::CMD_ProcStates:
            {
                S_ProcListData lst_ProcData;
                lst_ProcData.fromJson(task_Recived.context);
                emit sig_ProcessStates(lst_ProcData, task_Recived.result);
            }
            break;

        default:
            break;
    }
}

