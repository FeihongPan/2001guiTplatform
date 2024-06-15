#include "isubscriber.h"
#include "Logger/loggermanager.h"

#include <QtConcurrent/QtConcurrent>

using NS_Log::LoggerManager;

ISubscriber::ISubscriber(const QString &name, QObject *parent)
    : QObject(parent)
    , m_Name(name)
    , p_Client(nullptr)
{

}

ISubscriber::~ISubscriber()
{
    if(nullptr != p_Client)
    {
        delete p_Client;
        p_Client = nullptr;
    }
}

int ISubscriber::LinkToSubscribeClient(MqttClient *client)
{
    if(nullptr == client)
    {
        return 1;
    }

    if(nullptr != p_Client)
    {
        return 2;
    }

    p_Client = client;
    connect(p_Client, &MqttClient::connected, this, &ISubscriber::on_Subscribe);
    connect(p_Client, &MqttClient::disconnected, this, &ISubscriber::on_Disconnnect);
    connect(p_Client, &MqttClient::messageReceived, this, &ISubscriber::on_MessageReceived, Qt::ConnectionType::QueuedConnection);

    return 0;
}

int ISubscriber::Subscribe(const QString &topic)
{
    if(nullptr != p_Client)
    {
        if(!m_lstTopic_Subscribed.contains(topic))
        {
            qDebug() << "ISubscriber::Subscribe" << topic;
            p_Client->subscribe(topic, 2);
            m_lstTopic_Subscribed.append(topic);
            return 0;
        }
        ///已经订阅
        return 1;
    }
    else
    {
        if(!m_lstTopic_Temp.contains(topic))
        {
            m_lstTopic_Temp.append(topic);
            return 0;
        }
        ///重复添加
        return 2;
    }
}

bool ISubscriber::Unsubscribe(const QString &topic)
{
    if(nullptr != p_Client)
    {
        for(int i = 0; i < m_lstTopic_Subscribed.count(); ++i)
        {
            p_Client->unsubscribe(topic);
        }
        m_lstTopic_Subscribed.clear();
        return true;
    }
    return false;
}

QStringList ISubscriber::SubscribedTopics()
{
    return this->m_lstTopic_Subscribed;
}

bool ISubscriber::IsClientConnected()
{
    if(nullptr != p_Client)
    {
        return p_Client->state() == QMqttClient::ClientState::Connected;
    }
    return false;
}

void ISubscriber::on_MessageReceived(const QByteArray &message, const QMqttTopicName &topic)
{
    try
    {
        if(this->m_lstTopic_Subscribed.contains(topic.name()))
        {
            QFuture<void> m_Future = QtConcurrent::run([&]
            {
                LOG()->Log_Subscribe((topic.name() + "\n" + message).toLatin1().data(), this->m_Name);
                decoding(topic.name(), message);
            });

            while(!m_Future.isFinished())
            {
                QEventLoop loop;
                QTimer::singleShot(1, &loop, &QEventLoop::quit);
                loop.exec();
            }
        }
    }
    catch (...)
    {
        QString msg = "An exception occurred: " + QString::fromUtf8(typeid(this).name()) + __FUNCTION__ + topic.name() + message;
        LOG()->Log_Exception(msg.toLatin1().data());
    }
}

void ISubscriber::on_Subscribe()
{
    for(int i = 0; i < m_lstTopic_Temp.count(); ++i)
    {
        if(!m_lstTopic_Subscribed.contains(m_lstTopic_Temp[i]))
        {
            this->p_Client->subscribe(m_lstTopic_Temp[i], 2);
            m_lstTopic_Subscribed.append(m_lstTopic_Temp[i]);
        }
    }
    m_lstTopic_Temp.clear();
}

void ISubscriber::on_Disconnnect()
{
    for(int i = 0; i < m_lstTopic_Subscribed.count(); ++i)
    {
        if(!m_lstTopic_Temp.contains(m_lstTopic_Subscribed[i]))
        {
            m_lstTopic_Temp.append(m_lstTopic_Subscribed[i]);
        }
    }
    m_lstTopic_Subscribed.clear();
}
