#ifndef LOGGER_H
#define LOGGER_H

#include "TCommonLib_global.h"
#include <time.h>
#include <sstream>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

#include "spdlog/spdlog.h"
#include "spdlog/logger.h"
#include "spdlog/common.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <QString>
#include <QDateTime>

#define LOG_LEVEL_TRACE spdlog::level::trace
#define LOG_LEVEL_DEBUG spdlog::level::debug
#define LOG_LEVEL_ERROR spdlog::level::error
#define LOG_LEVEL_INFO  spdlog::level::info
#define LOG_LEVEL_OFF   spdlog::level::off
#define LOG_LEVEL_CRITICAL spdlog::level::critical

using printLevel = spdlog::level::level_enum;
using formatString = spdlog::string_view_t;

template <typename T>
struct TCOMMONLIB_EXPORT fmt::formatter<QList<T>>: fmt::formatter<std::string>
{
    auto format(QList<T> list, format_context &ctx) -> decltype(ctx.out())
    {
        return format_to(ctx.out(), "[{}]", fmt::join(list, ","));
    }
};

template <>
struct TCOMMONLIB_EXPORT fmt::formatter<QString> : fmt::formatter<std::string>
{
    auto format(QString qstr, format_context &ctx) -> decltype(ctx.out())
    {
        return format_to(ctx.out(), "{}", qstr.toStdString());
    }
};

template <>
struct TCOMMONLIB_EXPORT fmt::formatter<QList<QString>>: fmt::formatter<std::string>
{
    auto format(QList<QString> list, format_context &ctx) -> decltype(ctx.out())
    {
        return format_to(ctx.out(), "[{}]", list.join(","));
    }
};

namespace NS_Log
{
    class TCOMMONLIB_EXPORT Logger
    {
    public:
        Logger(const QString &folderPath, qint64 timeSinceEpoch);

        virtual ~Logger();

        void SetSpecFileName(const QString &filename);

        void SetPrintLevel(printLevel level);

        void FlushOn(printLevel level);

        void PrintInfo(const QString &usrtime, const QString &msg);

        void DestroyLogger();

    protected:
        std::shared_ptr<spdlog::logger> p_Logger;

    private:
        void checkFilePath(QString sLogPath);
        void checkDirPath(QString sDirPath);

    public:
        QString m_LogFullName;
        QString m_FolderPath;
        qint64 m_TimeSinceEpoch;
    };
}

#endif // LOGGER_H
