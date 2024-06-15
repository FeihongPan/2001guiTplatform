#include "tcpclient.h"

#include "Logger/loggermanager.h"

#include <QTimer>
#include <QEventLoop>
#include <QTcpSocket>

#define CONNECT_TIMEOUT         3000
#define WRITEBYTES_TIMEOUT      2000
#define READREADY_TIMEOUT       1000

using NS_Log::LoggerManager;

TcpClient::TcpClient()
    : m_sock(new QTcpSocket(this))
    , m_bConnected(false)
{

}

TcpClient::~TcpClient()
{
    Close();

    if (m_sock != nullptr)
    {
        m_sock->deleteLater();
        m_sock = nullptr;
    }
}

bool TcpClient::Connect(const QString &ip, uint16_t port)
{
    m_sock->connectToHost(ip, port);

    if (wait(SIGNAL(connected()), CONNECT_TIMEOUT) == true)
    {
        LOG()->Log_Debug(("connect to host, ip : " + ip + "; port : " + QString::number(port)).toStdString());
        m_bConnected = true;
    }

    /// Set the MTU to solve the sticky packet problem
    //    m_sock->setReadBufferSize(NET_MTU);
    this->connect(m_sock, &QTcpSocket::readyRead, this, &TcpClient::readData);
    return m_bConnected;
}

bool TcpClient::Send(const char *data, uint16_t length)
{
    if (m_bConnected == true)
    {
        m_sock->write(data, length);
        return wait(SIGNAL(bytesWritten(qint64 )), WRITEBYTES_TIMEOUT);
    }
    else
    {
        LOG()->Log_Debug("TCP has not connected");
    }

    return false;
}

bool TcpClient::Send(const QByteArray &data)
{
    return Send(data.data(), data.length());
}

QByteArray TcpClient::SendRead(const char *datas, uint16_t length)
{
    if (datas == NULL)
    {
        return QByteArray();
    }

    if (Send(datas, length) <= 0)
    {
        LOG()->Log_Debug("SerialPort send failure");
        return QByteArray();
    }

    if (wait(SIGNAL(readData()), READREADY_TIMEOUT) == true)
    {
        return m_sock->readAll();
    }

    return QByteArray();
}

void TcpClient::Close()
{
    if (m_bConnected == true)
    {
        m_sock->close();
    }

    m_bConnected = false;
}

void TcpClient::readData()
{
    QByteArray datas = m_sock->readAll();

    if (datas.isEmpty() == false)
    {
        emit sig_Recived(datas);
    }
}

bool TcpClient::wait(const char *asignal, uint32_t ms)
{
    /// Use EventLoop to wait for the data to be sent
    static QEventLoop eventloop;
    static QTimer timer;
    timer.setInterval(ms);

    connect(m_sock, asignal, &eventloop, SLOT(quit()));
    connect(&timer, &QTimer::timeout, &eventloop, [ = ]()
    {
        timer.stop();
        eventloop.quit();
    });

    /// Starting the Timeout Timer
    timer.start();
    eventloop.exec();

    bool result = false;
    if (timer.isActive() == true)
    {
        timer.stop();
        result = true;
    }
    disconnect(m_sock, asignal, &eventloop, SLOT(quit()));

    return result;
}
