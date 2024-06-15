#include "alarmsinfo.h"


S_AlarmData::S_AlarmData()
{
    dic_Methodvalidity.insert(Retry, true);
    dic_Methodvalidity.insert(Skip, true);
    dic_Methodvalidity.insert(Continue, true);
    dic_Methodvalidity.insert(Reset, true);
}

S_AlarmData::S_AlarmData(const S_AlarmData &alarm)
{
    QList<ErrorHandlingMethod> lst = alarm.dic_Methodvalidity.keys();
    for(int i = 0; i < lst.count(); i++)
    {
        this->dic_Methodvalidity[lst[i]] = alarm.dic_Methodvalidity[lst[i]];
    }
    this->alarmCode = alarm.alarmCode;
    this->message = alarm.message;
    this->brief = alarm.brief;
}

S_AlarmData &S_AlarmData::operator=(const S_AlarmData &alarm)
{
    QList<ErrorHandlingMethod> lst = alarm.dic_Methodvalidity.keys();
    for(int i = 0; i < lst.count(); i++)
    {
        this->dic_Methodvalidity[lst[i]] = alarm.dic_Methodvalidity[lst[i]];
    }
    this->alarmCode = alarm.alarmCode;
    this->message = alarm.message;
    this->brief = alarm.brief;
    return *this;
}


bool S_AlarmData::operator==(S_AlarmData &alarm)
{
    return this->alarmCode == alarm.alarmCode;
}

S_AlarmsInfo::S_AlarmsInfo()
{

}

S_AlarmsInfo::S_AlarmsInfo(const S_AlarmsInfo &alarm)
{
    this->lst_AlarmsData = alarm.lst_AlarmsData;
}

S_AlarmsInfo &S_AlarmsInfo::operator=(const S_AlarmsInfo &alarm)
{
    this->lst_AlarmsData = alarm.lst_AlarmsData;
    return *this;
}

S_ReportedAlarm::S_ReportedAlarm()
{
    this->alarmData.alarmCode = "-1";
}

S_ReportedAlarm::S_ReportedAlarm(const S_ReportedAlarm &alarm)
{
    this->alarmData = alarm.alarmData;
    this->handlingMethod = alarm.handlingMethod;
    this->reportTime = alarm.reportTime;
    this->releaseUser = alarm.releaseUser;
    this->releaseTime = alarm.releaseTime;
    this->addtionalNotes = alarm.addtionalNotes;
}

S_ReportedAlarm &S_ReportedAlarm::operator=(const S_ReportedAlarm &alarm)
{
    this->alarmData = alarm.alarmData;
    this->handlingMethod = alarm.handlingMethod;
    this->reportTime = alarm.reportTime;
    this->releaseUser = alarm.releaseUser;
    this->releaseTime = alarm.releaseTime;
    this->addtionalNotes = alarm.addtionalNotes;
    return *this;
}

bool S_ReportedAlarm::operator<(const S_ReportedAlarm &alarm) const
{
    return this->alarmData.alarmCode < alarm.alarmData.alarmCode;
}

bool S_ReportedAlarm::operator==(const S_ReportedAlarm &alarm)
{
    return this->alarmData.alarmCode == alarm.alarmData.alarmCode;
}

bool S_ReportedAlarm::operator!=(const S_ReportedAlarm &alarm)
{
    return this->alarmData.alarmCode != alarm.alarmData.alarmCode;
}

S_ReportedAlarms::S_ReportedAlarms()
{
}

S_ReportedAlarms::S_ReportedAlarms(const S_ReportedAlarms &alarm)
{
    this->lst_ReportedAlarms = alarm.lst_ReportedAlarms;
}

S_ReportedAlarms &S_ReportedAlarms::operator=(const S_ReportedAlarms &alarm)
{
    this->lst_ReportedAlarms = alarm.lst_ReportedAlarms;
    return *this;
}
