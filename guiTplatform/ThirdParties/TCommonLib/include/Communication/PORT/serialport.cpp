#include "serialport.h"

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

SerialPort::SerialPort(const QString &strPortName, QObject *parent)
{
    p_serialPort = new QSerialPort(this);
    m_strPortName = strPortName;

    m_bAutoReconnect = false;
    m_nTimeOutInterval = 5000;

    /// 初始化串口参数
    p_serialPort->setBaudRate(QSerialPort::Baud9600);
    p_serialPort->setDataBits(QSerialPort::Data8);
    p_serialPort->setParity(QSerialPort::NoParity);
    p_serialPort->setStopBits(QSerialPort::OneStop);
    p_serialPort->setFlowControl(QSerialPort::NoFlowControl);

    /// 连接信号与槽
    connect(p_serialPort, &QSerialPort::readyRead, this, &SerialPort::on_handleReadyRead);
    connect(p_serialPort, &QSerialPort::errorOccurred, this, &SerialPort::on_handleError);
    connect(p_timer, &QTimer::timeout, this, &SerialPort::on_reconnectTimeout);
}

SerialPort::~SerialPort()
{
    ClosePort();
    delete p_serialPort;
}

bool SerialPort::OpenPort()
{
    p_serialPort->setPortName(m_strPortName);
    return p_serialPort->open(QIODevice::ReadWrite);
}

void SerialPort::ClosePort()
{
    if (p_serialPort->isOpen())
    {
        p_serialPort->close();
        emit sig_portClosed();
    }
}

bool SerialPort::IsPortOpen() const
{
    return p_serialPort->isOpen();
}

void SerialPort::ErrorOccurred(const QSPError &error)
{
    emit sig_errorHandled(error);
}

qint64 SerialPort::WriteData(const QByteArray &ba)
{
    if(!IsPortOpen())
    {
        return -1;
    }
    return p_serialPort->write(ba);
}

qint64 SerialPort::Async_WriteData(const QByteArray &ba)
{
    if(!IsPortOpen())
    {
        return -1;
    }
    QFuture<qint64> future = QtConcurrent::run([ & ]()
    {
        return p_serialPort->write(ba);
    });
    return future.result();
}

QByteArray SerialPort::ReadData() const
{
    return p_serialPort->readAll();
}

QByteArray SerialPort::Async_ReadData() const
{
    QFuture<QByteArray> future = QtConcurrent::run([ & ]()
    {
        return p_serialPort->readAll();
    });
    return future.result();
}

void SerialPort::SetAutoReconnectEnabled(bool &&bEnable)
{
    if(m_bAutoReconnect != bEnable)
    {
        m_bAutoReconnect = bEnable;
        if (bEnable)
        {
            connect(p_serialPort, &QSerialPort::errorOccurred, this, &SerialPort::on_handleError);
        }
        else
        {
            disconnect(p_serialPort, &QSerialPort::errorOccurred, this, &SerialPort::on_handleError);
        }
    }
}

void SerialPort::on_handleReadyRead()
{
    auto ba = Async_ReadData();
    emit sig_readyRead(ba);
}

void SerialPort::on_handleError(const QSPError &error)
{
    Q_UNUSED(error)

    if(m_bAutoReconnect)
    {
        p_timer->start(m_nTimeOutInterval);
    }

    emit sig_errorHandled(error);
}

void SerialPort::on_reconnectTimeout()
{
    OpenPort();
}
