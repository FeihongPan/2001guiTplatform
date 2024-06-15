#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "TCommonLib_global.h"
#include "Task.h"
#include "mqttclient.h"
#include "periodpublishinfo.h"

#include <QMutex>
#include <QTimer>

class TCOMMONLIB_EXPORT Publisher : public QObject
{
    Q_OBJECT

public:
    explicit Publisher(QObject *parent = nullptr);

    /// 将该对象绑定到指定的QMqttClient，并设置topic的前缀
    /// client 指定的QMqttClient
    /// prefix topic的前缀
    int LinkToClient(MqttClient *client, const QString &prefix, const QString &name = QString());

    /// 通过QMqttClient发布信息
    /// topic 发送的主题
    /// cmd 发送信息的命令
    /// result 当前指令的执行结果
    /// ba 当前指令的具体内容
    void Publish(const QString &topic, const QString &cmd, bool result = true, const QByteArray &data = QByteArray(), const QByteArray &errMsg = QByteArray());

    /// 周期性发布
    /// topic 发送的主题
    /// cmd 发送信息的命令
    /// r 当前指令的执行结果
    /// deleObg 获取需要发布具体内容的函数
    /// time 发送周期
    void PublishPeriodically(const QString &topic, const QString &cmd, bool &r, std::function<QByteArray(bool &)> deleObg, int time = 1000);

    QByteArray GetPublishData(const QString &topic, const QString &cmd, bool result = true, const QByteArray &ba = QByteArray()) const;

    bool IsConnected() const;

signals:
    void sig_SendMsg(const QString &topic, const QByteArray &ba);

private:
    void publishing();

private:
    QMap<QString, PeriodPublishInfo> m_dic_PeriodCommand;

    MqttClient *p_Client;

    QTimer m_Timer;

    QString m_Prefix;
    QString m_Name;

    int m_Interval;
    bool m_bInitialized;
};

#endif // PUBLISHER_H
