#include "udpclient.h"

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

UdpClient::UdpClient(QObject *parent) : QObject(parent)
{
    p_udpSocket = new QUdpSocket(this);

    QThread *thread = new QThread(this);

    this->moveToThread(thread);
    p_udpSocket->moveToThread(thread);

    connect(p_udpSocket, &QUdpSocket::readyRead, this, &UdpClient::on_readPendingDatagrams);
    connect(this, &UdpClient::sig_binding, this, &UdpClient::on_bindBeforeTimeout);

    thread->start();
}

UdpClient::~UdpClient()
{
    if (p_udpSocket)
    {
        p_udpSocket->abort();
        delete p_udpSocket;
        p_udpSocket = nullptr;
    }
}

bool UdpClient::BindToPort(const QString &strAddress, const quint16 &port, int nTimeOut)
{
    m_mutex.lock();
    UnBind();

    m_bBindResult = false;
    emit sig_binding(strAddress, port);

    QTime time;
    QEventLoop loop;
    time.start();
    do
    {
        QTimer::singleShot(100, &loop, &QEventLoop::quit);
        loop.exec();
        if(time.elapsed() >= nTimeOut)
        {
            emit sig_bindFailure();
            break;
        }
    }
    while (!m_bBindResult);

    m_mutex.unlock();
    return m_bBindResult;
}

void UdpClient::UnBind()
{
    p_udpSocket->abort();
    p_udpSocket->close();
    m_bBindResult = false;
}

bool UdpClient::SendDatagram(const QString &strAddress, const quint16 &port, const QByteArray &ba)
{
    QHostAddress address(strAddress);
    if (address.isNull())
    {
        return false;
    }
    return p_udpSocket->writeDatagram(ba, address, port) != -1;
}

bool UdpClient::Async_SendDatagram(const QString &strAddress, const quint16 &port, const QByteArray &ba)
{
    QHostAddress address(strAddress);
    if (address.isNull())
    {
        return false;
    }
    QFuture<bool> future = QtConcurrent::run([&]()
    {
        return p_udpSocket->writeDatagram(ba, address, port) != -1;
    });

    return future.result();
}

bool UdpClient::on_bindBeforeTimeout(const QString &strAddress, const quint16 &port)
{
    QHostAddress address(strAddress);
    if (address.isNull())
    {
        return m_bBindResult;
    }

    if (!p_udpSocket->bind(address, port))
    {
        return m_bBindResult;
    }

    m_bBindResult = true;
    emit sig_bindSuccess();
    return m_bBindResult;
}

void UdpClient::on_readPendingDatagrams()
{
    QMutexLocker locker(&m_mutex);
    while (p_udpSocket->hasPendingDatagrams())
    {
        QHostAddress sender;
        quint16 senderPort;
        QByteArray ba;
        ba.resize(p_udpSocket->pendingDatagramSize());
        p_udpSocket->readDatagram(ba.data(), ba.size(), &sender, &senderPort);

        emit sig_readyRead(sender.toString(), senderPort, ba);
    }
}
