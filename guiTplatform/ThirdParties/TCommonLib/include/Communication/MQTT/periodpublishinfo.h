#ifndef PERIODPUBLISHINFO_H
#define PERIODPUBLISHINFO_H

#include "TCommonLib_global.h"
#include "Task.h"

#include <functional>

struct TCOMMONLIB_EXPORT PeriodPublishInfo
{
    QString topic;
    TaskInfo taskInfo;
    std::function<QByteArray(bool &)> deleObj;
    int elapsed;
    int period;
};

#endif // PERIODPUBLISHINFO_H
