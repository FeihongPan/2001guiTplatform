#include "mqttclient.h"

MqttClient::MqttClient(QObject *parent)
    : QMqttClient(parent)
    , m_Port(0)
{

}

void MqttClient::Connect(const QString &ip, quint16 port)
{
    this->m_Ip = ip;
    this->m_Port = port;
    this->setHostname(ip);
    this->setPort(port);
    this->connectToHost();
}

void MqttClient::Reconnect()
{
    if(this->m_Ip != QString())
    {
        this->setHostname(this->m_Ip);
        this->setPort(this->m_Port);
        this->connectToHost();
    }
}

bool MqttClient::IsConnected()
{
    return this->state() == QMqttClient::Connected;
}

void MqttClient::Subscribe()
{

}

void MqttClient::DisConnect()
{

}
