#ifndef SERIALPORT_H
#define SERIALPORT_H

#include "TCommonLib_global.h"
#include "Logger/loggermanager.h"

#include <QObject>
#include <QtDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

using namespace NS_Log;

using QSPError = QSerialPort::SerialPortError;

class TCOMMONLIB_EXPORT SerialPort : public QObject
{
    Q_OBJECT

public:
    explicit SerialPort(const QString &strPortName, QObject *parent = nullptr);
    ~SerialPort();

    /// 设置串口参数
    inline void SetBaudRate(const QSerialPort::BaudRate &baudrate);
    inline void SetDataBits(const QSerialPort::DataBits &dataBits);
    inline void SetParity(const QSerialPort::Parity &parity);
    inline void SetStopBits(const QSerialPort::StopBits &stopBits);
    inline void SetFlowControl(const QSerialPort::FlowControl &flowControl);

    /// 串口操作
    bool OpenPort(void);
    void ClosePort(void);
    bool IsPortOpen(void) const;
    void ErrorOccurred(const QSPError &error);

    /// 文件传输
    qint64 WriteData(const QByteArray &ba);
    qint64 Async_WriteData(const QByteArray &ba);
    QByteArray ReadData(void) const;
    QByteArray Async_ReadData(void) const;

    void SetAutoReconnectEnabled(bool &&bEnable);

signals:
    void sig_readyRead(const QByteArray &ba);
    void sig_portOpened(void);
    void sig_portClosed(void);
    void sig_dataWritten(const qint64 &bytes);
    void sig_errorHandled(const QSPError &error);

private slots:
    void on_handleReadyRead(void);
    void on_handleError(const QSPError &error);
    void on_reconnectTimeout(void);

private:
    QSerialPort *p_serialPort;
    QTimer *p_timer;
    QString m_strPortName;
    int m_nTimeOutInterval;
    bool m_bAutoReconnect;
};

inline void SerialPort::SetBaudRate(const QSerialPort::BaudRate &baudrate)
{
    p_serialPort->setBaudRate(baudrate);
}

inline void SerialPort::SetDataBits(const QSerialPort::DataBits &dataBits)
{
    p_serialPort->setDataBits(dataBits);
}

inline void SerialPort::SetParity(const QSerialPort::Parity &parity)
{
    p_serialPort->setParity(parity);
}

inline void SerialPort::SetStopBits(const QSerialPort::StopBits &stopBits)
{
    p_serialPort->setStopBits(stopBits);
}

inline void SerialPort::SetFlowControl(const QSerialPort::FlowControl &flowControl)
{
    p_serialPort->setFlowControl(flowControl);
}

#endif // SERIALPORT_H
