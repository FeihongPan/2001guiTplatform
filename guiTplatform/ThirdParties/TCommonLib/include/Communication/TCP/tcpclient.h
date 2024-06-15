#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include "TCommonLib_global.h"

#include <QObject>

#define NET_MTU 1460

class QTcpSocket;

class TCOMMONLIB_EXPORT TcpClient : public QObject
{
    Q_OBJECT

public:
    TcpClient();

    ~TcpClient();

    bool Connect(const QString &ip, uint16_t port);

    void Close();

    bool Send(const char *data, uint16_t length);

    bool Send(const QByteArray &data);

    QByteArray SendRead(const char *datas, uint16_t length);

signals:
    void sig_Recived(const QByteArray &datas);

private:
    void readData();

    bool wait(const char *asignal, uint32_t ms);

private:
    QTcpSocket *m_sock;
    bool m_bConnected;
};

#endif // TCPCLIENT_H
