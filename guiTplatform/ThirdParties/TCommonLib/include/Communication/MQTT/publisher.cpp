#include "publisher.h"

#include <typeinfo>

#include "Logger/loggermanager.h"

using NS_Log::LoggerManager;

Publisher::Publisher(QObject *parent)
    : QObject(parent)
    , p_Client(nullptr)
    , m_bInitialized(false)
    , m_Interval(100)
{

}

int Publisher::LinkToClient(MqttClient *client, const QString &prefix, const QString &name)
{
    if(client == nullptr)
    {
        return 1;
    }
    if(p_Client != nullptr)
    {
        return 2;
    }

    this->p_Client = client;
    this->m_Prefix = prefix;
    this->m_Name = name;

    connect(this, &Publisher::sig_SendMsg, this->p_Client, [&](const QString & topic, const QByteArray & ba)
    {
        try
        {
            if(this->p_Client->IsConnected())
            {
                this->p_Client->publish(QMqttTopicName(topic), ba, 2);
            }
        }
        catch (...)
        {
            QString msg = "An exception occurred: " + QString::fromUtf8(typeid(this).name()) + __FUNCTION__
                          + " Name : " + m_Name + " Topic : " + topic + " Msg : " + ba;
            LOG()->Log_Exception(msg.toLatin1().data());
        }
    });

    connect(&m_Timer, &QTimer::timeout, this, &Publisher::publishing);
    m_Timer.start(m_Interval);
    LOG()->Log_Debug(("Publisher::Initialized " + QString::fromUtf8(typeid(this).name()) + " Name : " + m_Name + " result : " + QString::number(m_Timer.isActive())).toStdString());
    return 0;
}

void Publisher::Publish(const QString &topic, const QString &cmd, bool result, const QByteArray &data, const QByteArray &errMsg)
{
    TaskInfo taskInfo;
    taskInfo.task = cmd;
    taskInfo.result = result;
    taskInfo.context = data;
    taskInfo.errMsg = errMsg;
    QByteArray message = taskInfo.toRawJson();
    emit sig_SendMsg(m_Prefix + "_" + topic, message);
    LOG()->Log_Publish((m_Prefix + "_" + topic + "\n" + message).toStdString(), this->m_Name);
}

void Publisher::PublishPeriodically(const QString &topic, const QString &cmd, bool &r, std::function<QByteArray (bool &)> deleObg, int time)
{
    PeriodPublishInfo publishInfo;
    publishInfo.topic = topic;
    publishInfo.taskInfo.task = cmd;
    publishInfo.deleObj = deleObg;
    publishInfo.elapsed = 0;
    publishInfo.period = time;

    if(!m_dic_PeriodCommand.contains(cmd))
    {
        m_dic_PeriodCommand.insert(cmd, publishInfo);
    }
}

QByteArray Publisher::GetPublishData(const QString &topic, const QString &cmd, bool result, const QByteArray &ba) const
{
    TaskInfo taskInfo;
    taskInfo.task = cmd;
    taskInfo.result = result;
    taskInfo.context = ba;
    QByteArray message = taskInfo.toRawJson();
    QByteArray returnMsg;
    returnMsg += m_Prefix + "_" + topic + "\n";
    returnMsg += message;
    return returnMsg;
}

bool Publisher::IsConnected() const
{
    if(p_Client != nullptr)
    {
        return p_Client->state() == QMqttClient::ClientState::Connected;
    }
    return false;
}

void Publisher::publishing()
{
    try
    {
        QStringList lst_CMD = m_dic_PeriodCommand.keys();
        for(int i = 0; i < lst_CMD.count(); ++i)
        {
            m_dic_PeriodCommand[lst_CMD[i]].elapsed += m_Timer.interval();
            if(m_dic_PeriodCommand[lst_CMD[i]].elapsed >= m_dic_PeriodCommand[lst_CMD[i]].period)
            {
                bool r = false;
                m_dic_PeriodCommand[lst_CMD[i]].taskInfo.context = m_dic_PeriodCommand[lst_CMD[i]].deleObj(r);
                m_dic_PeriodCommand[lst_CMD[i]].taskInfo.result = r;
                QByteArray message = m_dic_PeriodCommand[lst_CMD[i]].taskInfo.toRawJson();
                emit sig_SendMsg(m_Prefix + "_" + m_dic_PeriodCommand[lst_CMD[i]].topic, message);
                LOG()->Log_Publish((m_Prefix + "_" + m_dic_PeriodCommand[lst_CMD[i]].topic + "\n" + message).toStdString(), this->m_Name);
                m_dic_PeriodCommand[lst_CMD[i]].elapsed = 0;
            }
        }
    }
    catch (...)
    {
        QString msg = "An exception occurred: " + QString::fromUtf8(typeid(this).name()) + __FUNCTION__;
        LOG()->Log_Exception(msg.toLatin1().data());
    }
}
