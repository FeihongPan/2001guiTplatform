#include "logger.h"

#include <QDir>
#include <QFile>
#include <QDebug>
#include <QException>

NS_Log::Logger::Logger(const QString &folderPath, qint64 timeSinceEpoch)
    : m_FolderPath(folderPath)
    , m_TimeSinceEpoch(timeSinceEpoch)
{
    QDateTime dateTime = QDateTime::fromMSecsSinceEpoch(this->m_TimeSinceEpoch);
    QString logFileName = dateTime.toString("yyyy-MM-dd_hh-mm-ss");
    QString logDir = logFileName.split('_')[0];
    checkFilePath(m_FolderPath + logDir);
    m_LogFullName = m_FolderPath + logDir + "/" + logFileName;
}

NS_Log::Logger::~Logger()
{
    DestroyLogger();
}

void NS_Log::Logger::SetSpecFileName(const QString &sFileName)
{
    checkFilePath(m_FolderPath);
    m_LogFullName = m_FolderPath + sFileName;
}

void NS_Log::Logger::SetPrintLevel(printLevel level)
{
    p_Logger->set_level(level);
}

void NS_Log::Logger::FlushOn(printLevel level)
{
    p_Logger->flush_on(level);
}

void NS_Log::Logger::PrintInfo(const QString &usrtime, const QString &msg)
{
    std::string pattern = "[" + usrtime.toStdString() + "] " + "[%^%l%$] [thread %t] %v";
    p_Logger->set_pattern(pattern);
    p_Logger->info(msg);
}

void NS_Log::Logger::DestroyLogger()
{
    if(p_Logger)
    {
        p_Logger->flush();
        spdlog::drop(p_Logger->name());
        p_Logger.reset();
    }
}

void NS_Log::Logger::checkFilePath(QString sLogPath)
{
    QString runPath = QDir::currentPath();
    QDir dir(runPath + sLogPath);
    if (!dir.exists())
    {
        try
        {
            dir.mkdir(runPath + sLogPath);
        }
        catch(const QException &ex)
        {
            qDebug() << "Faile to create log path: " << ex.what();
        }
    }
}

void NS_Log::Logger::checkDirPath(QString sDirPath)
{
    QString runPath = QDir::currentPath();
    QDir dir(runPath + sDirPath);
    if (!dir.exists())
    {
        try
        {
            dir.mkpath(".");
        }
        catch(const QException &ex)
        {
            qDebug() << "Faile to create dir path: " << ex.what();
        }
    }
}
