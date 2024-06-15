#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "TCommonLib_global.h"
#include "logger.h"

namespace NS_Log
{
    class TCOMMONLIB_EXPORT FileLogger : public Logger
    {
    public:
        explicit FileLogger(const QString &folderPath, qint64 timeSinceEpoch);
    };
}

#endif // FILELOGGER_H
