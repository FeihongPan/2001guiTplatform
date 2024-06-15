#include "timesyncsubscriber.h"

#include "Converter/enumconverter.h"
#include "TimeSynchronization/Manage/timesync.h"
#include "TimeSynchronization/Command/cmd_time.h"

#include <QMutex>

TimeSyncSubscriber *TimeSyncSubscriber::self = nullptr;

TimeSyncSubscriber::TimeSyncSubscriber(const QString &name, QObject *parent)
    : ISubscriber(name, parent)
{

}

TimeSyncSubscriber::~TimeSyncSubscriber()
{

}

TimeSyncSubscriber *TimeSyncSubscriber::getInstance()
{
    if(self == NULL)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == NULL)
        {
            self = new TimeSyncSubscriber("TimeSyncSubscriber");
        }
    }
    return self;
}

void TimeSyncSubscriber::decoding(const QString &topic, const QByteArray &message)
{
    TaskInfo task_Recived;
    task_Recived.fromJson(message);
    CMD_Time::Command cmd = EnumConverter::ConvertStringToEnum<CMD_Time::Command>(task_Recived.task);
    switch (cmd)
    {
        case CMD_Time::CMD_SetTime:
            {
                bool res = false;
                qint64 epoch = task_Recived.context.toLongLong(&res);
                if(res)
                {
                    TimeSync::getInstance()->SetTimeFromMSecsSinceEpoch(epoch);
                }
                TimeSync::getInstance()->Publish(EnumConverter::ConvertToString(cmd), res);
            }
            break;

        default:
            break;
    }
}
