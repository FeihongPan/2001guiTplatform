#include "timesync.h"

#include "Converter/enumconverter.h"
#include "TimeSynchronization/Command/cmd_time.h"

#include <QMutex>

TimeSync *TimeSync::self = nullptr;

TimeSync::TimeSync(const QString &name, QObject *parent)
    : QObject(parent)
    , IPublish(name)
{

}

TimeSync::~TimeSync()
{

}

TimeSync *TimeSync::getInstance()
{
    if(self == nullptr)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == nullptr)
        {
            self = new TimeSync("TimeSync");
        }
    }
    return self;
}

void TimeSync::SetHost(bool host)
{
    this->m_bHost = host;
}

void TimeSync::SetTimeFromMSecsSinceEpoch(const qint64 msecs)
{
    if(!m_bHost)
    {
        m_TimeOffset = msecs - QDateTime::currentMSecsSinceEpoch();
    }
}

void TimeSync::SetTimeFromString(const QString &s)
{
    if(!m_bHost)
    {
        QDateTime dateTime;
        dateTime.fromString(s, "yyyy/MM/dd hh:mm:ss zzz");
        m_TimeOffset = dateTime.toMSecsSinceEpoch() - QDateTime::currentMSecsSinceEpoch();
    }
}

qint64 TimeSync::TimeToMSecsSinceEpoch()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    dateTime.addMSecs(m_TimeOffset);
    return dateTime.toMSecsSinceEpoch();
}

QString TimeSync::TimeToString(const QString &format)
{
    QDateTime dateTime = QDateTime::currentDateTime();
    dateTime.addMSecs(m_TimeOffset);
    return dateTime.toString(format);
}

qint64 TimeSync::GetDeltaMSecs(const QString &strFromTime, const QString &strToTime, const QString &strFromTimeFormat, const QString &strToTimeFormat)
{
    auto fromDt = QDateTime::fromString(strFromTime, strFromTimeFormat);
    auto toDt = QDateTime::fromString(strToTime, strToTimeFormat);

    return fromDt.msecsTo(toDt);
}

void TimeSync::GetDeltaMSecs(const QString &strFromTime, const QString &strToTime, short &nDays, short &nHours, short &nMins, short &nSecs, short &nMSecs, const QString &strFromTimeFormat, const QString &strToTimeFormat)
{
    auto nDeltaT = GetDeltaMSecs(strFromTime, strToTime, strFromTimeFormat, strToTimeFormat);

    nDays = nDeltaT / 86400000;
    nHours = nDeltaT % 86400000 / 3600000;
    nMins = nDeltaT % 3600000 / 60000;
    nSecs = nDeltaT % 60000 / 1000;
    nMSecs = nDeltaT % 1000;
}

void TimeSync::SetPeriodPublish()
{
    if(m_bHost)
    {
        bool r = false;
        m_Publisher.PublishPeriodically(this->m_Topic, EnumConverter::ConvertToString(CMD_Time::CMD_TimeBenchmark), r, std::bind(&TimeSync::timeToByteArray, this, std::placeholders::_1), 1000);
    }
}

QByteArray TimeSync::timeToByteArray(bool &r)
{
    r = true;
    return TimeToString().toLatin1();
}
