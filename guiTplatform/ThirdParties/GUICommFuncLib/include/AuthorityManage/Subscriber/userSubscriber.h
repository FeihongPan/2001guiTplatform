#ifndef USERSUBSCRIBER_H
#define USERSUBSCRIBER_H

#include "GUICommFuncLib_global.h"
#include "Communication/MQTT/isubscriber.h"
#include "AuthorityManage/Data/userinfo.h"

#include "AuthorityManage/Command/cmd_user.h"

#include <QObject>

class GUICOMMFUNCLIB_EXPORT UserSubscriber : public ISubscriber
{
    Q_OBJECT
public:
    explicit UserSubscriber(QString name, QObject *parent = nullptr);
    static UserSubscriber *getInstance();
    ~UserSubscriber();

signals:
    void userChanged(S_UserInfo &);
    void sendLoginResult(int);
    void sendUsersInfo(S_UsersInfo);
    void saveUsersInfoResult(bool res);


protected slots:
    virtual void decoding(const QString &topic, const QByteArray &message) override;

private:
    static UserSubscriber *self;
};

#endif // USERSUBSCRIBER_H
