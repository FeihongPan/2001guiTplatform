#include "udpsocket.h"

#include <QTime>
#include <QThread>
#include <QUdpSocket>

UdpSocket::UdpSocket(QObject *parent)
    : QObject(parent)
    , m_udpSocket(new QUdpSocket(nullptr))
    , m_bBindResult(false)
{
    QThread *t = new QThread(this);

    this->moveToThread(t);
    m_udpSocket->moveToThread(t);

    connect(m_udpSocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
    connect(this, &UdpSocket::sig_Binding, this, &UdpSocket::bind);

    t->start();
}

bool UdpSocket::Bind(const QString &address, quint16 port, int timeOut)
{
    m_Mutex_BindResult.lock();

    m_bBindResult = false;
    emit sig_Binding(address, port);
    QTime time;
    time.start();
    while(!m_bBindResult)
    {
        QThread::msleep(100);
        if(time.elapsed() > timeOut)
        {
            return false;
        }
    }

    m_Mutex_BindResult.unlock();
    return true;
}

void UdpSocket::Send(const QString &address, quint16 port, const QByteArray &data)
{
    QHostAddress hostAddress(address);
    if (hostAddress.isNull())
    {
        return;
    }
    m_udpSocket->writeDatagram(data, hostAddress, port);
}

void UdpSocket::readPendingDatagrams()
{
    while (m_udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(m_udpSocket->pendingDatagramSize());
        QHostAddress senderAddress;
        quint16 senderPort;
        m_udpSocket->readDatagram(datagram.data(), datagram.size(), &senderAddress, &senderPort);
        emit sig_Received(senderAddress.toString(), senderPort, datagram);
    }
}

bool UdpSocket::bind(const QString &address, quint16 port)
{
    QHostAddress hostAddress(address);
    if (hostAddress.isNull())
    {
        return m_bBindResult;
    }

    if (!m_udpSocket->bind(hostAddress, port))
    {
        return m_bBindResult;
    }

    m_bBindResult = true;
    return m_bBindResult;
}
