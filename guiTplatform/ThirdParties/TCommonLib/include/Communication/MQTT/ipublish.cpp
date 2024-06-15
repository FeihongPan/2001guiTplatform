#include "ipublish.h"

#include "Logger/loggermanager.h"

using NS_Log::LoggerManager;

IPublish::IPublish(const QString &name)
    : m_Name(name)
{

}

bool IPublish::LinkToPublishClient(MqttClient *client, const QString &prefix, const QString &topic)
{
    if(m_Publisher.LinkToClient(client, prefix, m_Name) == 0)
    {
        this->m_Prefix = prefix;
        this->m_Topic = topic;
        qDebug() << "IPublish::LinkToClient" << m_Name + ": " + this->m_Prefix + "_" + this->m_Topic;
        initialize();
        return true;
    }
    return false;
}

void IPublish::Publish(const QString &cmd, bool result, const QByteArray &ba, const QByteArray &errMsg)
{
    m_Publisher.Publish(this->m_Topic, cmd, result, ba, errMsg);
}
