#ifndef IPUBLISH_H
#define IPUBLISH_H

#include "TCommonLib_global.h"
#include "publisher.h"

class TCOMMONLIB_EXPORT IPublish
{
public:
    explicit IPublish(const QString &name);

    inline bool IsClientConnected() const;

    inline QString GetTopic() const;

    inline const QString &GetName() const;

    inline Publisher *GetPublisher();

    /// QMqttClient的初始化
    /// client 需要绑定的QMqttClient
    /// prefix topic的前缀
    /// topic
    bool LinkToPublishClient(MqttClient *client, const QString &prefix, const QString &topic);

    /// 通过QMqttClient发布信息
    /// cmd 发送信息的命令
    /// result 当前指令的执行结果
    /// ba 当前指令的具体内容
    void Publish(const QString &cmd, bool result = true, const QByteArray &ba = QByteArray(), const QByteArray &errMsg = QByteArray());

    /// 需要周期性发送信息时重写,会在LinkClient()方法内调用
    virtual void SetPeriodPublish() {};

    /// 需要软件启动发送信息时重写，会在LinkClient()方法内调用
    virtual void StartPublish() {};

protected:
    /// 在LinkClient()方法内调用
    virtual void initialize() {};

protected:
    Publisher m_Publisher;
    QString m_Prefix;
    QString m_Topic;
    QString m_Name;
};

inline bool IPublish::IsClientConnected() const
{
    return m_Publisher.IsConnected();
}

inline QString IPublish::GetTopic() const
{
    return this->m_Prefix + "_" + this->m_Topic;
}

inline const QString &IPublish::GetName() const
{
    return this->m_Name;
}

inline Publisher *IPublish::GetPublisher()
{
    return &this->m_Publisher;
}

#endif // IPUBLISH_H
