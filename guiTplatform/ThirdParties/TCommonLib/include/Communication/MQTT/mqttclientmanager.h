#ifndef MQTTCLIENTMANAGER_H
#define MQTTCLIENTMANAGER_H

#include "TCommonLib_global.h"
#include "mqttclient.h"
#include "isubscriber.h"

#include <QObject>
#include <QTimer>

class TCOMMONLIB_EXPORT MqttClientManager : public QObject
{
    Q_OBJECT

public:
    ~MqttClientManager();

    static MqttClientManager *getInstance();

    ///枚举需要从1开始
    bool AddClient(int name, const QString &prefix = QString());

    bool Connect(int client, const QString &ip, quint16 port, int timeout = 3000);

    void SetAutoReconnect(bool autoReconnect);

    int IsConnected(int client);

    MqttClient *GetClient(int client);

    QList<int> GetClientID();

private slots:
    void on_Reconnect();

private:
    explicit MqttClientManager(QObject *parent = nullptr);
    MqttClientManager(const MqttClientManager &) = delete;
    MqttClientManager &operator=(const MqttClientManager &) = delete;

private:
    static MqttClientManager *self;
    QString m_PublichPrefix;
    bool m_bAutoReconnect;
    QTimer m_Timer;
    QMap<int, MqttClient *> p_dic_MqttClient;
};

#endif // MQTTCLIENTMANAGER_H
