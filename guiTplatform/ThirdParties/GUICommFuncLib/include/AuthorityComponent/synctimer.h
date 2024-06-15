#ifndef SYNCTIMER_H
#define SYNCTIMER_H

#include "GUICommFuncLib_global.h"

#include <QObject>
#include <QTime>
#include <QFuture>

class GUICOMMFUNCLIB_EXPORT SyncTimer : public QObject
{
    Q_OBJECT
public:
    explicit SyncTimer(QObject *parent = nullptr);
    ~SyncTimer();

    void start(int interval);
    void stop();
    bool isActive();
    void singleShot(int time);

    int GetTotoalSpan();

private:
    void start();

signals:
    void timeout();

private:
    QTime time;
    bool isRuning = false;
    QFuture<void> future;
    int interval = 10;
    int totalSpan = 0;
    bool bSingleShot = false;
};

#endif // SYNCTIMER_H
