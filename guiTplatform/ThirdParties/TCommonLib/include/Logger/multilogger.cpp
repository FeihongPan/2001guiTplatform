#include "multilogger.h"

using namespace std;

NS_Log::MultiLogger::MultiLogger(const QString &folderPath, qint64 timeSinceEpoch)
    : Logger(folderPath, timeSinceEpoch)
{
    auto fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(m_LogFullName.toStdString().c_str(), true);
    fileSink->set_level(LOG_LEVEL_TRACE);
    fileSink->set_pattern("[%Y-%m-%d %T][%l]%v");

    auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    consoleSink->set_level(LOG_LEVEL_TRACE);
    consoleSink->set_pattern("%+");

    std::vector<spdlog::sink_ptr> sinks;
    sinks.emplace_back(consoleSink);
    sinks.emplace_back(fileSink);
    p_Logger = std::make_shared<spdlog::logger>("multi-sink", begin(sinks), end(sinks));
    p_Logger->set_level(LOG_LEVEL_TRACE);
    p_Logger->flush_on(LOG_LEVEL_TRACE);
}
