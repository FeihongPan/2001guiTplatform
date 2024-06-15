#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include "TCommonLib_global.h"
#include "Logger/loggermanager.h"

#include <QObject>
#include <QMutex>
#include <QTimer>
#include <QtDebug>
#include <QUdpSocket>
#include <QHostAddress>

class TCOMMONLIB_EXPORT UdpClient : public QObject
{
    Q_OBJECT

public:
    explicit UdpClient(QObject *parent = nullptr);
    ~UdpClient();

    /// 绑定端口号
    bool BindToPort(const QString &strAddress, const quint16 &port, int nTimeOut = 5000);
    void UnBind(void);

    /// 发送数据报
    bool SendDatagram(const QString &strAddress, const quint16 &port, const QByteArray &ba);
    bool Async_SendDatagram(const QString &strAddress, const quint16 &port, const QByteArray &ba);

signals:
    bool sig_binding(const QString &strAddress, const quint16 &port);
    void sig_readyRead(const QString &strAddress, const quint16 &port, const QByteArray &ba);
    void sig_errorOccurred(const QAbstractSocket::SocketError &error);
    void sig_bindSuccess(void);
    void sig_bindFailure(void);

private slots:
    bool on_bindBeforeTimeout(const QString &strAddress, const quint16 &port);
    void on_readPendingDatagrams(void);

private:
    QUdpSocket *p_udpSocket = nullptr;
    QMutex m_mutex;
    bool m_bBindResult;
};

#endif // UDPCLIENT_H
