#ifndef LOGGERMANAGER_H
#define LOGGERMANAGER_H

#include "TCommonLib_global.h"
#include "loggerhelper.h"
#include "TimeSynchronization/Manage/timesync.h"

#define LOG() LoggerManager::getInstance()

namespace NS_Log
{
    class TCOMMONLIB_EXPORT LoggerManager : public QObject
    {
        Q_OBJECT

    public:
        ~LoggerManager();

        static LoggerManager *getInstance();

        void LoggerDeleter();

        void Initialize_LogDeleter(const QString &folderPath);

        void Stop_LogDeleter();


        void Initialize_DebugLogger(const QString &folderPath);

        template<typename... Args>
        void Log_Debug(const formatString &fmt, const Args &... args);


        void Initialize_AlarmLogger(const QString &loggerName, const QString &folderPath);

        template<typename... Args>
        void Log_Alarm(const formatString &fmt, const QString &loggerName, const Args &... args);


        void Initialize_ProcessLogger(const QString &loggerName, const QString &folderPath);

        template<typename... Args>
        void Log_Process(const formatString &fmt, const QString &loggerName, const Args &... args);


        void Initialize_Publish(const QString &loggerName, const QString &folderPath, bool used = false);

        template<typename... Args>
        void Log_Publish(const formatString &fmt, const QString &loggerName, const Args &... args);


        void Initialize_Subscribe(const QString &loggerName, const QString &folderPath, bool used = false);

        template<typename... Args>
        void Log_Subscribe(const formatString &fmt, const QString &loggerName, const Args &... args);


        void Initialize_ExceptionLogger(const QString &folderPath);

        template<typename... Args>
        void Log_Exception(const formatString &fmt, const Args &... args);


        template<typename... Args>
        void spdConsole(const formatString &fmt, const Args &... args) {};

    private:
        explicit LoggerManager(QObject *parent = nullptr);
        LoggerManager(const LoggerManager &) = delete;
        LoggerManager &operator=(const LoggerManager &) = delete;

    private:
        static LoggerManager *self;
        LoggerHelper *pDebugLogger;
        QMap<QString, LoggerHelper *> p_dic_AlarmLogger;
        QMap<QString, LoggerHelper *> p_dic_ProcessLogger;
        QMap<QString, LoggerHelper *> p_dic_PublishLogger;
        QMap<QString, LoggerHelper *> p_dic_SubscribeLogger;
        LoggerHelper *p_ExceptionLogger;
        QString m_deleterSentry;
    };

    template<typename... Args>
    void LoggerManager::Log_Debug(const formatString &fmt, const Args &... args)
    {
        if(pDebugLogger)
        {
            pDebugLogger->print(Time()->TimeToString(), fmt, args...);
        }
    }

    template<typename... Args>
    void LoggerManager::Log_Alarm(const formatString &fmt, const QString &loggerName, const Args &... args)
    {
        if(p_dic_AlarmLogger.contains(loggerName))
        {
            p_dic_AlarmLogger[loggerName]->print(Time()->TimeToString(), fmt, args...);
        }
    }

    template<typename... Args>
    void LoggerManager::Log_Process(const formatString &fmt, const QString &loggerName, const Args &... args)
    {
        if(p_dic_ProcessLogger.contains(loggerName))
        {
            p_dic_ProcessLogger[loggerName]->print(Time()->TimeToString(), fmt, args...);
        }
    }

    template<typename... Args>
    void LoggerManager::Log_Publish(const formatString &fmt, const QString &loggerName, const Args &... args)
    {
        if(p_dic_PublishLogger.contains(loggerName))
        {
            p_dic_PublishLogger[loggerName]->print(Time()->TimeToString(), fmt, args...);
        }
    }

    template<typename... Args>
    void LoggerManager::Log_Subscribe(const formatString &fmt, const QString &loggerName, const Args &... args)
    {
        if(p_dic_SubscribeLogger.contains(loggerName))
        {
            p_dic_SubscribeLogger[loggerName]->print(Time()->TimeToString(), fmt, args...);
        }
    }

    template<typename... Args>
    void LoggerManager::Log_Exception(const formatString &fmt, const Args &... args)
    {
        if(p_ExceptionLogger)
        {
            p_ExceptionLogger->print(Time()->TimeToString(), fmt, args...);
        }
    }
}

#endif // LOGGERMANAGER_H
