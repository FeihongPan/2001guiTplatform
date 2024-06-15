#ifndef SGTCONSTANTSUBSCRIBER_H
#define SGTCONSTANTSUBSCRIBER_H

#include "GUIFramework_global.h"
#include "Communication/MQTT/isubscriber.h"
#include "SGT/Data/sgtconstant.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT SGTConstantSubscriber : public ISubscriber
{
    Q_OBJECT
public:
    explicit SGTConstantSubscriber(QString name, QObject *parent = nullptr);
    static SGTConstantSubscriber *getInstance();
    ~SGTConstantSubscriber();

signals:
    void Send_SGTConstant(S_SGTConstant &sgt);
    void Send_SaveResult(bool r);

protected slots:
    virtual void decoding(const QString &topic, const QByteArray &message) override;

private:
    static SGTConstantSubscriber *self;
};

#endif // SGTCONSTANTSUBSCRIBER_H
