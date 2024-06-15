#include "loggerhelper.h"

#include "multilogger.h"
#include "TimeSynchronization/Manage/timesync.h"

#include <QDir>
#include <QTimer>
#include <QException>
#include <QtConcurrent/QtConcurrent>

NS_Log::LoggerHelper::LoggerHelper(QObject *parent)
    : QObject(parent)
    , m_TimeInterval(1000 * 3600)
{
    qRegisterMetaType<QMqttTopicName>("formatString");
    qRegisterMetaType<QMqttTopicName>("formatString&");

    connect(this, &LoggerHelper::sig_Print, this, &LoggerHelper::on_Print);
    connect(this, &LoggerHelper::sig_Delete, this, &LoggerHelper::on_Delete);
}

NS_Log::LoggerHelper::~LoggerHelper()
{
    QList<Logger *>::iterator iter;
    for(iter = p_lst_Logger.begin(); iter != p_lst_Logger.end(); ++iter)
    {
        delete *iter;
        *iter = nullptr;
    }
    p_lst_Logger.clear();
}

int NS_Log::LoggerHelper::LogInit(const QString &logPath, LogType outType, quint64 timeInterval)
{
    this->m_LogPath = logPath;
    this->m_TimeInterval = timeInterval;
    this->m_OutType = outType;

    p_lst_Logger.clear();
    this->m_TimeToMSecsSinceEpoch = Time()->TimeToMSecsSinceEpoch();
    p_lst_Logger.append(CreateLogger(outType, this->m_TimeToMSecsSinceEpoch));
    p_ActivedLogger = p_lst_Logger[0];
    this->m_TimeToMSecsSinceEpoch += this->m_TimeInterval;
    p_lst_Logger.append(CreateLogger(outType, this->m_TimeToMSecsSinceEpoch));

    for(int i = 0; i < p_lst_Logger.count(); i++)
    {
        if(p_lst_Logger[i] == nullptr)
        {
            return 1;
        }
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &LoggerHelper::onTimeout);
    timer->start(this->m_TimeInterval);
    return 0;
}

NS_Log::Logger *NS_Log::LoggerHelper::CreateLogger(LogType outType, qint64 timeSinceEpoch)
{
    Logger *pLogger = nullptr;
    if (outType == LogType::File)
    {
        pLogger = new FileLogger(m_LogPath, timeSinceEpoch);
    }
    else if(outType == LogType::Both)
    {
        pLogger = new MultiLogger(m_LogPath, timeSinceEpoch);
    }
    return pLogger;
}

void NS_Log::LoggerHelper::onTimeout()
{
    if(!p_lst_Logger.isEmpty())
    {
        for(int i = 0; i < p_lst_Logger.count(); i++)
        {
            if(p_lst_Logger[i]->m_TimeSinceEpoch == this->m_TimeToMSecsSinceEpoch)
            {
                p_ActivedLogger = p_lst_Logger[i];
                break;
            }
        }

        if(p_lst_Logger[0]->m_TimeSinceEpoch <= this->m_TimeToMSecsSinceEpoch - m_TimeInterval)
        {
            emit sig_Delete();
        }

        if(p_lst_Logger.last()->m_TimeSinceEpoch >= this->m_TimeToMSecsSinceEpoch)
        {
            this->m_TimeToMSecsSinceEpoch += this->m_TimeInterval;
            p_lst_Logger.append(CreateLogger(this->m_OutType, this->m_TimeToMSecsSinceEpoch));
        }
    }
}

void NS_Log::LoggerHelper::on_Print(const QString &usrtime, const QString &fmt)
{
    try
    {
        QDir dir(m_LogPath);
        if(!dir.exists())
        {
            if(!dir.mkpath(m_LogPath))
            {
                return;
            }
        }

        if(p_ActivedLogger != nullptr)
        {
            p_ActivedLogger->PrintInfo(usrtime, fmt);
        }
    }
    catch (...)
    {
        qDebug() << "An exception occurred: " + QString::fromUtf8(typeid(this).name()) + __FUNCTION__;
        qDebug() << Time()->TimeToString();
    }
}

void NS_Log::LoggerHelper::on_Delete()
{
    QtConcurrent::run([&]
    {
        Logger *logger = p_lst_Logger.takeFirst();
        logger->DestroyLogger();
        delete logger;
        logger = nullptr;
    });
}
