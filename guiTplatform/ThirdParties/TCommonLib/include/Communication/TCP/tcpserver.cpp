#include "tcpserver.h"

#include "Logger/loggermanager.h"

#include <QThread>
#include <QTcpSocket>

using NS_Log::LoggerManager;

TcpServer::TcpServer(QObject *parent)
    : QTcpServer(parent)
    , m_nMtu(TCP_MAX_MTU)
{

}

TcpServer::~TcpServer()
{
    StopAllSession();
}

void TcpServer::SetPort(quint16 port)
{
    this->m_nPort = port;
}

void TcpServer::SetMTU(quint16 mtu)
{
    m_nMtu = mtu;
}

bool TcpServer::Listen()
{
    return this->listen(QHostAddress::Any, this->m_nPort);
}

void TcpServer::StopAllSession()
{
    foreach(QTcpSocket *client, m_lstClient)
    {
        client->close();
        delete client;
        client = nullptr;
    }
    m_lstClient.clear();
}

QList<QTcpSocket *> TcpServer::GetAllSession()
{
    return m_lstClient;
}

void TcpServer::on_AcceptError(QAbstractSocket::SocketError err)
{
    Q_UNUSED(err)
    this->errorString();
}

void TcpServer::on_Disconnect()
{
    QTcpSocket *client = static_cast<QTcpSocket *>(sender());

    m_lstClient.removeOne(client);
    //    client->thread()->quit();
    //    client->thread()->deleteLater();
    client->close();
    client->deleteLater();
}

void TcpServer::on_ReadyRead()
{
    QTcpSocket *client = static_cast<QTcpSocket *>(sender());
    QByteArray cache = client->readAll();

    emit sig_ReadDatas(cache, client);
}

void TcpServer::incomingConnection(qintptr handle)
{
    LOG()->Log_Debug(("in coming = " + QString::number(handle)).toStdString());
    QTcpSocket *client = new QTcpSocket();

    if (client->setSocketDescriptor(handle) == false)
    {
        LOG()->Log_Debug("setSocketDescriptor failed");
        return;
    }

    //    client->setReadBufferSize(m_nMtu);

    LOG()->Log_Debug(("incomingConnection peerAddress : " + client->peerAddress().toString() + "; localAddress : " + client->localAddress().toString()).toStdString());
    connect(client, &QTcpSocket::disconnected, this, &TcpServer::on_Disconnect);
    connect(client, &QTcpSocket::readyRead, this, &TcpServer::on_ReadyRead);

    m_lstClient.push_back(client);
}
