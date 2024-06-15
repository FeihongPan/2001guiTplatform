#include "logsubscriber.h"
#include "Communication/MQTT/Task.h"
#include "Converter/enumconverter.h"

#include <QMutex>

LogSubscriber *LogSubscriber::self = nullptr;

LogSubscriber::LogSubscriber(QString name, QObject *parent) : ISubscriber(name, parent)
{

}

LogSubscriber *LogSubscriber::getInstance()
{
    if(self == NULL)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == NULL)
        {
            self = new LogSubscriber("LogSubscriber");
        }
    }
    return self;
}

void LogSubscriber::decoding(const QString &topic, const QByteArray &message)
{
    TaskInfo task_Recived;
    task_Recived.fromJson(message);
    CMD_Log::Command cmd = EnumConverter::ConvertStringToEnum<CMD_Log::Command>(task_Recived.task);
    switch (cmd)
    {
        case CMD_Log::CMD_LogDebug:
        case CMD_Log::CMD_LogException:
        {
            S_LogInfo_Debugs logsInfo;
            logsInfo.fromJson(task_Recived.context);
            emit Sig_LogInfo(logsInfo, task_Recived.result);
        }
        break;
        case CMD_Log::CMD_LogProcess:
        {
            S_LogInfo_Process logsProcess;
            logsProcess.fromJson(task_Recived.context);
            emit Sig_LogInfo_Process(logsProcess, task_Recived.result);
        }
        break;
        default:
            break;
    }
}
