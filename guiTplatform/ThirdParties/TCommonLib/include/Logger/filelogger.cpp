#include "filelogger.h"

#include "spdlog/async.h"

#include <QUuid>

NS_Log::FileLogger::FileLogger(const QString &folderPath, qint64 timeSinceEpoch)
    : Logger(folderPath, timeSinceEpoch)
{
    std::string loggerName = "basic_logger_" + QUuid::createUuid().toString().toStdString() + m_LogFullName.toStdString();
    p_Logger = spdlog::basic_logger_mt(loggerName, m_LogFullName.toStdString().c_str());
    p_Logger->set_level(LOG_LEVEL_TRACE);
    p_Logger->flush_on(LOG_LEVEL_TRACE);
    spdlog::set_pattern("[%Y-%m-%d %T][%l]%v");
}
