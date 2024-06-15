#include "loggermanager.h"

#include "TimeSynchronization/Manage/timesync.h"

#include <QDir>
#include <QFile>
#include <QMutex>
#include <QProcess>
#include <QFileInfo>

NS_Log::LoggerManager *NS_Log::LoggerManager::self = nullptr;

NS_Log::LoggerManager::LoggerManager(QObject *parent)
    : QObject(parent)
    , pDebugLogger(nullptr)
    , p_ExceptionLogger(nullptr)
{

}

NS_Log::LoggerManager::~LoggerManager()
{
    if(pDebugLogger)
    {
        delete pDebugLogger;
        pDebugLogger = nullptr;
    }

    QMap<QString, LoggerHelper *>::iterator iter;
    for(iter = p_dic_ProcessLogger.begin(); iter != p_dic_ProcessLogger.end(); iter++)
    {
        delete iter.value();
        *iter = nullptr;
    }
    p_dic_ProcessLogger.clear();

    for(iter = p_dic_PublishLogger.begin(); iter != p_dic_PublishLogger.end(); iter++)
    {
        delete iter.value();
        *iter = nullptr;
    }
    p_dic_PublishLogger.clear();

    for(iter = p_dic_SubscribeLogger.begin(); iter != p_dic_SubscribeLogger.end(); iter++)
    {
        delete iter.value();
        *iter = nullptr;
    }
    p_dic_SubscribeLogger.clear();

    for(iter = p_dic_AlarmLogger.begin(); iter != p_dic_AlarmLogger.end(); iter++)
    {
        delete iter.value();
        *iter = nullptr;
    }
    p_dic_AlarmLogger.clear();

    QFileInfo fileInfo(m_deleterSentry);
    if (fileInfo.isFile())
    {
        QFile::remove(m_deleterSentry);
    }

    if(self)
    {
        delete self;
        self = nullptr;
    }
}

NS_Log::LoggerManager *NS_Log::LoggerManager::getInstance()
{
    if(self == NULL)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == NULL)
        {
            self = new LoggerManager();
        }
    }
    return self;
}

void NS_Log::LoggerManager::Initialize_LogDeleter(const QString &folderPath)
{
    m_deleterSentry = folderPath + "/Log/logdeleter.txt";
    QFileInfo fileInfo(m_deleterSentry);
    if (fileInfo.isFile())
    {
        QFile::remove(m_deleterSentry);
    }
    LoggerDeleter();
}

void NS_Log::LoggerManager::Stop_LogDeleter()
{
    QFileInfo fileInfo(m_deleterSentry);
    if (fileInfo.isFile())
    {
        QFile::remove(m_deleterSentry);
    }
}

void NS_Log::LoggerManager::Initialize_DebugLogger(const QString &folderPath)
{
    if(!pDebugLogger)
    {
        pDebugLogger = new LoggerHelper();
        QString path = folderPath + "/Log/Debug/";
        pDebugLogger->LogInit(path, LoggerHelper::LogType::Both);
    }
}

void NS_Log::LoggerManager::Initialize_AlarmLogger(const QString &loggerName, const QString &folderPath)
{
    if(!p_dic_AlarmLogger.contains(loggerName))
    {
        p_dic_AlarmLogger.insert(loggerName, new LoggerHelper());
        QString logPath = folderPath + "/Log/Alarm/" + loggerName + "/";
        p_dic_AlarmLogger[loggerName]->LogInit(logPath, LoggerHelper::LogType::File);
    }
}

void NS_Log::LoggerManager::Initialize_ProcessLogger(const QString &loggerName, const QString &folderPath)
{
    if(!p_dic_ProcessLogger.contains(loggerName))
    {
        p_dic_ProcessLogger.insert(loggerName, new LoggerHelper());
        QString logPath = folderPath + "/Log/Process/" + loggerName + "/";
        p_dic_ProcessLogger[loggerName]->LogInit(logPath, LoggerHelper::LogType::File);
    }
}

void NS_Log::LoggerManager::Initialize_Publish(const QString &loggerName, const QString &folderPath, bool used)
{
    if(used)
    {
        if(!p_dic_PublishLogger.contains(loggerName))
        {
            p_dic_PublishLogger.insert(loggerName, new LoggerHelper());
            QString logPath = folderPath + "/Log/Communication/Publish/" + loggerName + "/";
            p_dic_PublishLogger[loggerName]->LogInit(logPath, LoggerHelper::LogType::File);
        }
    }
}

void NS_Log::LoggerManager::Initialize_Subscribe(const QString &loggerName, const QString &folderPath, bool used)
{
    if(used)
    {
        if(!p_dic_SubscribeLogger.contains(loggerName))
        {
            p_dic_SubscribeLogger.insert(loggerName, new LoggerHelper());
            QString logPath = folderPath + "/Log/Communication/Subscribe/" + loggerName + "/";
            p_dic_SubscribeLogger[loggerName]->LogInit(logPath, LoggerHelper::LogType::File);
        }
    }
}

void NS_Log::LoggerManager::Initialize_ExceptionLogger(const QString &folderPath)
{
    if(!p_ExceptionLogger)
    {
        p_ExceptionLogger = new LoggerHelper();
        QString path = folderPath + "/Log/Exception/";
        p_ExceptionLogger->LogInit(path, LoggerHelper::LogType::Both);
    }
}

void NS_Log::LoggerManager::LoggerDeleter()
{
    QFileInfo fileInfo(m_deleterSentry);
    if (!fileInfo.isFile())
    {
        QProcess *deleterProcess = new QProcess();
        QDir exeDir = QDir::current();
        QString batch = exeDir.absoluteFilePath("scripts/logdeleter.bat");
        QString cmd = "start " + batch + " " + m_deleterSentry + "\n";
#if 0
        // 隐藏控制台
        deleterProcess->start(batch + " " + m_deleterSentry + "\n");
#else
        // 显示控制台
        deleterProcess->start("cmd.exe");
        deleterProcess->write(cmd.toLatin1());
#endif
        if (deleterProcess->waitForStarted())
        {
            deleterProcess->waitForFinished(5000);
            qDebug() << "Log Deleter Working ... ";
        }
        else
        {
            qDebug() << "Failed to Start Log Deleter!";
        }
        qDebug() << "Log Deleter Return" << deleterProcess->errorString();
    }
}
