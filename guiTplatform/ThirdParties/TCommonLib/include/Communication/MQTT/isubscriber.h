#ifndef ISUBSCRIBER_H
#define ISUBSCRIBER_H

#include "TCommonLib_global.h"
#include "Task.h"
#include "mqttclient.h"

class TCOMMONLIB_EXPORT ISubscriber : public QObject
{
    Q_OBJECT

public:
    explicit ISubscriber(const QString &name, QObject *parent = nullptr);

    ~ISubscriber();

    /// 绑定QMqttClient，由Manager类统一调用
    /// client 需要被绑定的QMqttClient
    int LinkToSubscribeClient(MqttClient *client);

    /// 订阅topic
    /// topic 被订阅的topic
    int Subscribe(const QString &topic);

    /// 反订阅topic
    /// topic 被反订阅的topic
    bool Unsubscribe(const QString &topic);

    /// 获取已经订阅的topic
    QStringList SubscribedTopics();

    bool IsClientConnected();

public slots:
    void on_MessageReceived(const QByteArray &message, const QMqttTopicName &topic);

    void on_Subscribe();

    void on_Disconnnect();

protected:
    /// 对收到的消息进行解析，会根据子类所订阅的topic调用该方法
    virtual void decoding(const QString &topic, const QByteArray &message) {};

private:
    QString m_Name;
    QStringList m_lstTopic_Subscribed;
    QStringList m_lstTopic_Temp;
    QMqttClient *p_Client;
};

#endif // ISUBSCRIBER_H
