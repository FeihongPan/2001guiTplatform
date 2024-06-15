#include "mqttclientmanager.h"

#include <QUuid>
#include <QTime>
#include <QMutex>
#include <QEventLoop>

MqttClientManager *MqttClientManager::self = nullptr;

MqttClientManager::MqttClientManager(QObject *parent)
    : QObject(parent)
    , m_bAutoReconnect(true)
{
    qRegisterMetaType<QMqttTopicName>("QMqttTopicName");
    qRegisterMetaType<QMqttTopicName>("QMqttTopicName&");
    qRegisterMetaType<QByteArray>("QByteArray");
    qRegisterMetaType<QByteArray>("QByteArray&");

    connect(&m_Timer, &QTimer::timeout, this, &MqttClientManager::on_Reconnect);
}

MqttClientManager::~MqttClientManager()
{

}

MqttClientManager *MqttClientManager::getInstance()
{
    if(self == NULL)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == NULL)
        {
            self = new MqttClientManager;
        }
    }
    return self;
}

bool MqttClientManager::AddClient(int name, const QString &prefix)
{
    if(!p_dic_MqttClient.contains(name))
    {
        MqttClient *client = new MqttClient();
        client->setClientId(prefix + "_" + QUuid::createUuid().toString());
        p_dic_MqttClient.insert(name, client);
        return true;
    }
    return false;
}

bool MqttClientManager::Connect(int client, const QString &ip, quint16 port, int timeout)
{
    m_Timer.stop();
    if(!p_dic_MqttClient.contains(client))
    {
        return false;
    }

    if(p_dic_MqttClient[client]->state() == QMqttClient::ClientState::Disconnected)
    {
        p_dic_MqttClient[client]->Connect(ip, port);

        QTime time;
        QEventLoop loop;
        time.start();
        do
        {
            QTimer::singleShot(100, &loop, &QEventLoop::quit);
            loop.exec();
            if(time.elapsed() >= timeout)
            {
                break;
            }
        }
        while (p_dic_MqttClient[client]->state() != QMqttClient::ClientState::Connected);
    }
    m_Timer.start(100);
    return p_dic_MqttClient[client]->state() == QMqttClient::ClientState::Connected;
}

void MqttClientManager::SetAutoReconnect(bool autoReconnect)
{
    this->m_bAutoReconnect = autoReconnect;
}

int MqttClientManager::IsConnected(int client)
{
    if(p_dic_MqttClient.contains(client))
    {
        return p_dic_MqttClient[client]->IsConnected() ? 0 : 1;
    }
    return 2;
}

MqttClient *MqttClientManager::GetClient(int client)
{
    return p_dic_MqttClient[client];
}

QList<int> MqttClientManager::GetClientID()
{
    return p_dic_MqttClient.keys();
}

void MqttClientManager::on_Reconnect()
{
    QList<int> lst_Client = p_dic_MqttClient.keys();
    for(int i = 0; i < lst_Client.count(); ++i)
    {
        if(!p_dic_MqttClient[lst_Client[i]]->IsConnected())
        {
            p_dic_MqttClient[lst_Client[i]]->Reconnect();
        }
    }
}
