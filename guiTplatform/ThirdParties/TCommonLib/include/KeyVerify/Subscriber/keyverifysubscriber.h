#ifndef KEYVERIFYSUBSCRIBER_H
#define KEYVERIFYSUBSCRIBER_H

#include "TCommonLib_global.h"
#include "Communication/MQTT/isubscriber.h"

#include <QObject>

class TCOMMONLIB_EXPORT KeyVerifySubscriber : public ISubscriber
{
    Q_OBJECT
public:
    explicit KeyVerifySubscriber(QString name, QObject *parent = nullptr);
    static KeyVerifySubscriber *getInstance();

signals:
    void sig_CreateSuourceFileResult(bool r);
    void sig_LicenseExpirationDate(QString date);
    void sig_LicenseState(bool actived);

private:
    virtual void decoding(const QString &topic, const QByteArray &message) override;

private:
    static KeyVerifySubscriber *self;
};

#endif // KEYVERIFYSUBSCRIBER_H
