#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "TCommonLib_global.h"

#include <QTcpServer>

#define TCP_MAX_MTU 1460

class TCOMMONLIB_EXPORT TcpServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit TcpServer(QObject *parent = nullptr);

    ~TcpServer();

    void SetPort(quint16 port);

    void SetMTU(quint16 mtu);

    bool Listen();

    void StopAllSession();

    QList<QTcpSocket *> GetAllSession();

signals:
    void sig_ReadDatas(const QByteArray &datas, QTcpSocket *cli);

private slots:
    void on_AcceptError(QAbstractSocket::SocketError err);

    void on_Disconnect();

    void on_ReadyRead();

protected:
    virtual void incomingConnection(qintptr handle) override;

private:
    quint16 m_nPort;
    quint16 m_nMtu;
    QList<QTcpSocket *> m_lstClient;
};

#endif // TCPSERVER_H
