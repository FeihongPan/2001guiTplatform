#ifndef SGTCTRLSUBSCRIBER_H
#define SGTCTRLSUBSCRIBER_H

#include "GUIFramework_global.h"
#include "Communication/MQTT/isubscriber.h"
#include "SGT/Data/sgtconstant.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT SGTCtrlSubscriber : public ISubscriber
{
    Q_OBJECT
public:
    explicit SGTCtrlSubscriber(QString name, QObject *parent = nullptr);
    static SGTCtrlSubscriber *getInstance();
    ~SGTCtrlSubscriber();

signals:
    void Send_SGTSystemState(SGTSystem::State state);
    void Send_SGTComponentState(S_SGTTwinkleData &twinkelData);

protected slots:
    virtual void decoding(const QString &topic, const QByteArray &message) override;

private:
    static SGTCtrlSubscriber *self;
};

#endif // SGTCTRLSUBSCRIBER_H
