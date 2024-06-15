#ifndef USERINFO_H
#define USERINFO_H

#include "GUICommFuncLib_global.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

class GUICOMMFUNCLIB_EXPORT AccessLevel : public QObject
{
    Q_OBJECT

public:
    enum Level
    {
        Visitor = 0,
        Operator,
        ProcessEngineer,
        EquipmentEngineer,
        Remote,
        Service,
        Admin,
        SuperAdmin,
    };
    Q_ENUM(Level)

    AccessLevel() {};
};

class SR_UserInfo;
class GUICOMMFUNCLIB_EXPORT S_UserInfo : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(QString, userName)
    QS_FIELD(QString, password)
    QS_FIELD(AccessLevel::Level, accessLevel)

public:
    S_UserInfo();
    S_UserInfo(QString name, QString pwd, AccessLevel::Level level);
    S_UserInfo(const SR_UserInfo &user);
    S_UserInfo &operator=(const SR_UserInfo &user);

    bool operator==(const S_UserInfo &user);
    bool operator!=(const S_UserInfo &user);
    bool operator==(const SR_UserInfo &user);
    bool operator!=(const SR_UserInfo &user);


    static QStringList ShowAccessLevelsToStringList(AccessLevel::Level accessLevel = AccessLevel::Level::Visitor);
};


class GUICOMMFUNCLIB_EXPORT S_UsersInfo : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, S_UserInfo, lstUsersInfo)

public:
    S_UsersInfo();
};

class GUICOMMFUNCLIB_EXPORT SR_UserInfo : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TString, userName)
    QS_OBJECT(TString, password)
    QS_OBJECT(TEnum, accessLevel)

public:
    SR_UserInfo();
    SR_UserInfo(const S_UserInfo &user);
    SR_UserInfo(const SR_UserInfo &user);

    SR_UserInfo &operator=(const S_UserInfo &user);
};

//class UserInfo : public TValueBase
//{
//    Q_GADGET
//    QS_SERIALIZABLE

//public:
//    enum AccessLevel
//    {
//        Visitor = 0,
//        Operator,
//        ProcessEngineer,
//        EquipmentEngineer,
//        Remote,
//        Service,
//        Admin,
//        SuperAdmin,
//    };
//    Q_ENUM(AccessLevel)

//    QS_OBJECT(TString, userName)
//    QS_OBJECT(TString, password)
//    QS_OBJECT(TEnum, accessLevel)

//public:
//    UserInfo();
//    UserInfo(QString name, QString pwd, AccessLevel level);

//    UserInfo Copy(const UserInfo &user);

//    bool operator==(const UserInfo &user);

//    UserInfo& operator=(const UserInfo &user);

//    static QStringList ShowAccessLevelsToStringList(UserInfo::AccessLevel accessLevel = UserInfo::AccessLevel::Visitor);
//};

//class UsersInfo : public TValueBase
//{
//    Q_GADGET
//    QS_SERIALIZABLE

//    QS_COLLECTION_OBJECTS(QList, UserInfo, lstUsersInfo)

//public:
//    UsersInfo();
//};

#endif // USERINFO_H
