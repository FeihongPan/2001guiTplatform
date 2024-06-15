#include "alarmSubscriber.h"
#include "Converter/enumconverter.h"

#include <QMutex>
#include <QDebug>

AlarmSubscriber *AlarmSubscriber::self = nullptr;
AlarmSubscriber::AlarmSubscriber(const QString &name, QObject *parent) : ISubscriber(name, parent)
{

}

AlarmSubscriber::~AlarmSubscriber()
{

}

AlarmSubscriber *AlarmSubscriber::getInstance()
{
    if(self == nullptr)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == nullptr)
        {
            self = new AlarmSubscriber("AlarmSubscriber");
        }
    }
    return self;
}

void AlarmSubscriber::decoding(const QString &topic, const QByteArray &message)
{
    TaskInfo task_Recived;
    task_Recived.fromJson(message);
    CMD_Alarm::Command cmd = EnumConverter::ConvertStringToEnum<CMD_Alarm::Command>(task_Recived.task);
    switch (cmd)
    {
        case CMD_Alarm::CMD_AlarmReport:
        {
            S_ReportedAlarms reportedAlarms;
            reportedAlarms.fromJson(task_Recived.context);
            emit sig_AlarmReport(reportedAlarms);
        }
        break;

        case CMD_Alarm::CMD_AlarmHandle:
        {
            S_ReportedAlarms reportedAlarms;
            reportedAlarms.fromJson(task_Recived.context);
            emit sig_AlarmReport(reportedAlarms);
        }
        break;

        case CMD_Alarm::CMD_SaveAlarmsInfo:
        {
            emit sig_WriteToFileResult(task_Recived.result);
        }
        break;

        case CMD_Alarm::CMD_AlarmsInfo:
        {
            S_AlarmsInfo alarmsInfo;
            alarmsInfo.fromJson(task_Recived.context);
            emit sig_SendAlarmsInfo(alarmsInfo, task_Recived.result);
        }
        break;

        case CMD_Alarm::CMD_AlarmsHistory:
        {
            S_ReportedAlarms alarms;
            alarms.fromJson(task_Recived.context);;
            emit sig_HistoryAlarms(alarms);
        }
        break;

        default:
            break;
    }
}
