#ifndef TIMESYNC_H
#define TIMESYNC_H

#include "TCommonLib_global.h"
#include "Communication/MQTT/ipublish.h"

#include <QObject>
#include <QDateTime>

#define Time() TimeSync::getInstance()

class TCOMMONLIB_EXPORT TimeSync : public QObject, public IPublish
{
    Q_OBJECT

public:
    ~TimeSync();

    static TimeSync *getInstance();

    void SetHost(bool host);

    void SetTimeFromMSecsSinceEpoch(const qint64 msecs);

    void SetTimeFromString(const QString &s);

    qint64 TimeToMSecsSinceEpoch();

    QString TimeToString(const QString &format = "yyyy/MM/dd hh:mm:ss zzz");

    /// <summary>
    /// 根据时间字符串获取毫秒时间差
    /// </summary>
    /// <param name="strFromTime">起始时间</param>
    /// <param name="strToTime">结束时间</param>
    /// <param name="strFromTimeFormat">起始时间格式</param>
    /// <param name="strFromTimeFormat">结束时间格式</param>
    /// <returns>时间差，单位：ms</returns>
    qint64 GetDeltaMSecs(const QString &strFromTime,
                         const QString &strToTime,
                         const QString &strFromTimeFormat = "yyyy/MM/dd hh:mm:ss zzz",
                         const QString &strToTimeFormat = "yyyy/MM/dd hh:mm:ss zzz");

    /// <summary>
    /// 根据时间字符串获取时间差
    /// </summary>
    /// <param name="strFromTime">起始时间</param>
    /// <param name="strToTime">结束时间</param>
    /// <param name="nDays">时间差-天数，函数内赋值</param>
    /// <param name="nHours">时间差-小时数，函数内赋值</param>
    /// <param name="nMins">时间差-分钟数，函数内赋值</param>
    /// <param name="nSecs">时间差-秒数，函数内赋值</param>
    /// <param name="nMSecs">时间差-毫秒数，函数内赋值</param>
    /// <param name="strFromTimeFormat">起始时间格式</param>
    /// <param name="strFromTimeFormat">结束时间格式</param>
    void GetDeltaMSecs(const QString &strFromTime,
                       const QString &strToTime,
                       short &nDays, short &nHours, short &nMins, short &nSecs, short &nMSecs,
                       const QString &strFromTimeFormat = "yyyy/MM/dd hh:mm:ss zzz",
                       const QString &strToTimeFormat = "yyyy/MM/dd hh:mm:ss zzz");

private:
    TimeSync(const QString &name, QObject *parent = nullptr);
    TimeSync(const TimeSync &) = delete;
    TimeSync operator=(const TimeSync &) = delete;

    virtual void SetPeriodPublish() override;

    QByteArray timeToByteArray(bool &r);

private:
    static TimeSync *self;

    qint64 m_TimeOffset = 0;
    bool m_bHost = false;
};

#endif // TIMESYNC_H
