#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include "TCommonLib_global.h"

#include <QMutex>
#include <QObject>

class QUdpSocket;

class TCOMMONLIB_EXPORT UdpSocket : public QObject
{
    Q_OBJECT

public:
    explicit UdpSocket(QObject *parent = nullptr);

    bool Bind(const QString &address, quint16 port, int timeOut = 3000);

    void Send(const QString &address, quint16 port, const QByteArray &data);

public:
    quint16 m_Port;
    QString m_Address;

signals:
    void sig_Received(const QString &address, quint16 port, const QByteArray &data);
    bool sig_Binding(const QString &address, quint16 port);

private slots:
    void readPendingDatagrams();

private:
    bool bind(const QString &address, quint16 port);

private:
    QUdpSocket *m_udpSocket;
    bool m_bBindResult;
    QMutex m_Mutex_BindResult;
};

#endif // UDPSOCKET_H
