#ifndef IMQTTCLIENT_H
#define IMQTTCLIENT_H

#include "TCommonLib_global.h"
#include "Communication/MQTT/ipublish.h"
#include "Communication/MQTT/isubscriber.h"

#include <QMap>
#include <QTimer>

class TCOMMONLIB_EXPORT IMqttClient : public ISubscriber, public IPublish
{
    Q_OBJECT

public:
    explicit IMqttClient(const QString &name, QObject *parent = nullptr);

    inline void SetCommandTimeout(uint timeout);

signals:
    void sig_CommandTimeout(const QString &cmd);

protected:
    void conmmandSetInitialize(const QStringList &lst_CMD);

    int async_SendCommand(const QString &cmd, const QByteArray &msg);

    virtual void decoding(const QString &topic, const QByteArray &message) override;

    virtual void decoding(const QString &task, bool result, const QByteArray &msg, const QByteArray &errMsg) = 0;

protected:
    QMap<QString, bool> m_dic_CommandBusy;
    uint m_Timeout;
    uint m_TimerInterval;

private:
    QMap<QString, uint> m_dic_CommandTimeout;
    QTimer m_Timer;
};

#endif // IMQTTCLIENT_H
