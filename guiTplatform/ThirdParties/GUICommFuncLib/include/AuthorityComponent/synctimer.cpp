#include "synctimer.h"

#include <QtConcurrent/QtConcurrent>

SyncTimer::SyncTimer(QObject *parent) : QObject(parent)
{

}

SyncTimer::~SyncTimer()
{
    stop();
}

void SyncTimer::start()
{
    future = QtConcurrent::run([ = ]
    {
        QTime time;
        time.start();
        int timeSpan = 0;
        isRuning = true;
        while (isRuning)
        {
            if(timeSpan >= interval)
            {
                time.restart();
                emit timeout();
                if(bSingleShot)
                {
                    isRuning = false;
                    break;
                }
            }
            timeSpan = time.elapsed();
            totalSpan += timeSpan;
            //            QThread::msleep(1);
            QEventLoop loop;
            QTimer::singleShot(1, &loop, &QEventLoop::quit);
            loop.exec();
        }
    });
}

void SyncTimer::start(int interval)
{
    this->interval = interval;
    this->bSingleShot = false;
    start();
}

void SyncTimer::stop()
{
    isRuning = false;
    future.waitForFinished();
}

bool SyncTimer::isActive()
{
    return isRuning;
}

void SyncTimer::singleShot(int time)
{
    this->bSingleShot = true;
    this->interval = time;
    start();
}

int SyncTimer::GetTotoalSpan()
{
    return totalSpan;
}
