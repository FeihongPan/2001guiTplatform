#include "userSubscriber.h"

#include <QMutex>

UserSubscriber *UserSubscriber::self = NULL;
UserSubscriber::UserSubscriber(QString name, QObject *parent) : ISubscriber(name, parent)
{
    qRegisterMetaType<S_UserInfo>("S_UserInfo");
    qRegisterMetaType<S_UserInfo>("S_UserInfo&");
    qRegisterMetaType<S_UsersInfo>("S_UsersInfo");
    qRegisterMetaType<S_UsersInfo>("S_UsersInfo&");
}

UserSubscriber *UserSubscriber::getInstance()
{
    if(self == nullptr)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == nullptr)
        {
            self = new UserSubscriber("UserSubscriber");
        }
    }
    return self;
}

UserSubscriber::~UserSubscriber()
{

}

void UserSubscriber::decoding(const QString &topic, const QByteArray &message)
{
    qDebug() << "UserInterpreter::decoding " << message;
    TaskInfo task_Recived;
    task_Recived.fromJson(message);
    CMD_User::Command cmd = EnumConverter::ConvertStringToEnum<CMD_User::Command>(task_Recived.task);
    switch (cmd)
    {
        case CMD_User::CMD_Login:
            if(task_Recived.context != "1" && task_Recived.context != "2")
            {
                S_UserInfo user;
                user.fromJson(task_Recived.context);
                emit sendLoginResult(0);
                emit userChanged(user);
            }
            else
            {
                emit sendLoginResult(task_Recived.context.toInt());
            }
            break;

        case CMD_User::CMD_Logout:
        {
            S_UserInfo user;
            user.fromJson(task_Recived.context);
            emit userChanged(user);
        }
        break;

        case CMD_User::CMD_CurrentUser:
        {
            S_UserInfo user;
            user.fromJson(task_Recived.context);
            emit userChanged(user);
        }
        break;

        case CMD_User::CMD_UsersInfo:
            if(task_Recived.result)
            {
                S_UsersInfo users;
                users.fromJson(task_Recived.context);
                emit sendUsersInfo(users);
            }
            break;

        case CMD_User::CMD_SaveUsersInfo:
            emit saveUsersInfoResult(task_Recived.result);
            break;

        default:
            break;
    }
}
