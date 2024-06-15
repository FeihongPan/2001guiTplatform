#ifndef CMD_USER_H
#define CMD_USER_H

#include "GUICommFuncLib_global.h"

#include <QObject>

class GUICOMMFUNCLIB_EXPORT CMD_User : public QObject
{
    Q_OBJECT
public:
    enum Command
    {
        CMD_Login,
        CMD_Logout,
        CMD_CurrentUser,
        CMD_UsersInfo,
        CMD_SaveUsersInfo,
    };
    Q_ENUM(Command)

    explicit CMD_User(QObject *parent = nullptr);

signals:

};

#endif // CMD_USER_H
