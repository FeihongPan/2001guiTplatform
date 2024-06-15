#ifndef THREADPROCSUBSCRIBER_H
#define THREADPROCSUBSCRIBER_H

#include "GUIFramework_global.h"
#include "BasicValue/serializablelist.h"
#include "Communication/MQTT/isubscriber.h"
#include "ThreadProc/Data/processdata.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT ThreadProcSubscriber : public ISubscriber
{
    Q_OBJECT
public:
    explicit ThreadProcSubscriber(QString name, QObject *parent = nullptr);
    ~ThreadProcSubscriber() override;

    static ThreadProcSubscriber *getInstance();

signals:
    void sig_AllProcSingalInfo(ProcListBasicInfo &info, bool result);
    void sig_InitialProcSingalInfo(ProcListBasicInfo &info, bool result);
    void sig_MonitorProcSingalInfo(ProcListBasicInfo &info, bool result);
    void sig_AutoRunProcSingalInfo(ProcListBasicInfo &info, bool result);
    void sig_ProcessStates(S_ProcListData &lst_ProcData, bool result);

private:
    virtual void decoding(const QString &topic, const QByteArray &message) override;

private:
    static ThreadProcSubscriber *self;
};

#endif // THREADPROCSUBSCRIBER_H
