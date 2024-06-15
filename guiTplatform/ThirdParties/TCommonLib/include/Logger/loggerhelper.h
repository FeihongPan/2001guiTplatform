#ifndef LOGGERHELPER_H
#define LOGGERHELPER_H

#include "TCommonLib_global.h"
#include "filelogger.h"

#include <QObject>

//#define TIME_INTERVAL 1  // generate log file per 1 hour

class QTimer;

namespace NS_Log
{
    class TCOMMONLIB_EXPORT LoggerHelper: public QObject
    {
        Q_OBJECT

    public:
        enum LogType
        {
            File = 0,
            Console,
            Both
        };
        Q_ENUM(LogType)

    public:
        explicit LoggerHelper(QObject *parent = nullptr);

        ~LoggerHelper();

        int LogInit(const QString &logPath, LogType outType, quint64 timeInterval = 1000 * 3600);

        //        Logger *selectLogger(QString sOutType);

        Logger *CreateLogger(LogType outType, qint64 timeOffset);

        template<typename... Args>
        inline void print(const QString &usrtime, const formatString &fmt, const Args &... args)
        {
            emit sig_Print(usrtime, QString::fromStdString(std::string(fmt.data(), fmt.size())));
            //            try
            //            {
            //                QDir dir(m_LogPath);
            //                if(!dir.exists())
            //                {
            //                    if(!dir.mkpath(m_LogPath))
            //                    {
            //                        return;
            //                    }
            //                }

            //                //                qDebug() << "p_ActivedLogger" << (p_ActivedLogger == nullptr);
            //                if(p_ActivedLogger != nullptr)
            //                {
            //                    p_ActivedLogger->printInfo(usrtime, fmt, args...);
            //                }
            //            }
            //            catch (...)
            //            {
            //                qDebug() << "An exception occurred: " + QString::fromUtf8(typeid(this).name()) + __FUNCTION__;
            //                qDebug() << Time()->TimeToString();
            //            }
        }

    signals:
        void sig_Print(const QString &usrtime, const QString &fmt);

        void sig_Delete();

    public slots:
        void onTimeout();

        void on_Print(const QString &usrtime, const QString &fmt);

        void on_Delete();

    private:
        QList<Logger *> p_lst_Logger;
        Logger *p_ActivedLogger;
        QTimer *timer;
        QString m_LogPath;
        LogType m_OutType;
        qint64 m_TimeToMSecsSinceEpoch;
        int m_TimeInterval;
    };
}

#endif // LOGGERHELPER_H
