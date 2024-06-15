#ifndef LOGSUBSCRIBER_H
#define LOGSUBSCRIBER_H

#include "GUICommFuncLib_global.h"
#include "Communication/MQTT/isubscriber.h"
#include "DataLog/Data/loginfo.h"
#include "DataLog/Command/cmd_log.h"

#include <QObject>

class GUICOMMFUNCLIB_EXPORT LogSubscriber : public ISubscriber
{
    Q_OBJECT
public:
    static LogSubscriber *getInstance();

protected slots:
    virtual void decoding(const QString &topic, const QByteArray &message) override;

private:
    explicit LogSubscriber(QString name, QObject *parent = nullptr);

private:
    static LogSubscriber *self;

signals:
    void Sig_LogInfo(S_LogInfo_Debugs &, bool);
    void Sig_LogInfo_Process(S_LogInfo_Process &, bool);
};



#endif // LOGSUBSCRIBER_H
