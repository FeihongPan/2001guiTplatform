#include "userinfo.h"

S_UserInfo::S_UserInfo()
{
    this->userName = "Visitor";
    this->accessLevel = AccessLevel::Visitor;
}

S_UserInfo::S_UserInfo(QString name, QString pwd, AccessLevel::Level level)
{
    this->userName = name;
    this->password = pwd;
    this->accessLevel = level;
}

S_UserInfo::S_UserInfo(const SR_UserInfo &user)
{
    this->userName = user.userName.value;
    this->accessLevel = (AccessLevel::Level)user.accessLevel.value;
    this->password = user.password.value;
}

S_UserInfo &S_UserInfo::operator=(const SR_UserInfo &user)
{
    this->userName = user.userName.value;
    this->accessLevel = (AccessLevel::Level)user.accessLevel.value;
    this->password = user.password.value;
    return *this;
}

bool S_UserInfo::operator==(const S_UserInfo &user)
{
    return this->userName == user.userName;
}

bool S_UserInfo::operator!=(const S_UserInfo &user)
{
    return !(*this == user);
}

bool S_UserInfo::operator==(const SR_UserInfo &user)
{
    return this->userName == user.userName.value;
}

bool S_UserInfo::operator!=(const SR_UserInfo &user)
{
    return !(*this == user);
}

QStringList S_UserInfo::ShowAccessLevelsToStringList(AccessLevel::Level accessLevel)
{
    QStringList lst;
    QMetaEnum metaEnum = QMetaEnum::fromType<AccessLevel::Level>();
    int max = 0;
    if(accessLevel == AccessLevel::Admin || accessLevel == AccessLevel::SuperAdmin)
    {
        max = AccessLevel::Admin;
    }
    else
    {
        max = AccessLevel::Admin - 1;
    }

    for(int i = 0; i <= max; i++)
    {
       lst.append(metaEnum.key(i));
    }
    return lst;
}


S_UsersInfo::S_UsersInfo()
{

}

SR_UserInfo::SR_UserInfo()
{
    this->userName.SetRange(3,16);
    this->password.SetRange(3,16);
    this->accessLevel.SetEnumValue<AccessLevel::Level>(AccessLevel::Visitor);
}

SR_UserInfo::SR_UserInfo(const S_UserInfo &user)
{
    this->userName = user.userName;
    this->accessLevel = user.accessLevel;
    this->password = user.password;

    this->userName.SetRange(3,16);
    this->password.SetRange(3,16);
    this->accessLevel.SetEnumValue<AccessLevel::Level>(AccessLevel::Visitor);
}

SR_UserInfo::SR_UserInfo(const SR_UserInfo &user)
{
    this->userName = user.userName;
    this->accessLevel = user.accessLevel;
    this->password = user.password;
}

SR_UserInfo &SR_UserInfo::operator=(const S_UserInfo &user)
{
    this->userName = user.userName;
    this->accessLevel = user.accessLevel;
    this->password = user.password;
    return *this;
}


//UserInfo::UserInfo()
//{
////    this->userName.SetRange(3,16);
////    this->password.SetRange(3,16);
//    this->userName.SetValue("Visitor");
//    this->accessLevel.SetEnumValue<AccessLevel>(AccessLevel::Visitor);
//}

//UserInfo::UserInfo(QString name, QString pwd, AccessLevel level)
//{
////    this->userName.SetValue(name, 3, 16);
////    this->password.SetValue(pwd, 3, 16);
//    this->userName.SetValue(name);
//    this->password.SetValue(pwd);
//    this->accessLevel.SetEnumValue<AccessLevel>(level);
//}

//UserInfo UserInfo::Copy(const UserInfo &user)
//{
//    UserInfo user_temp;
//    user_temp.userName = user.userName;
//    user_temp.password = user.password;
//    user_temp.accessLevel = user.accessLevel;
//    user_temp.PropertyChanged = true;
//    return user_temp;
//}

//bool UserInfo::operator==(const UserInfo &user)
//{
//    return this->userName.value == user.userName.value;
//}

//UserInfo& UserInfo::operator=(const UserInfo &user)
//{
//    if (this != &user)
//    {
//        this->userName = user.userName;
//        this->password = user.password;
//        this->accessLevel = user.accessLevel;
//        this->PropertyChanged = true;
//    }
//    return *this;
//}

//QStringList UserInfo::ShowAccessLevelsToStringList(AccessLevel accessLevel)
//{
//    QStringList lst;
//    QMetaEnum metaEnum = QMetaEnum::fromType<UserInfo::AccessLevel>();
//    int max = 0;
//    if(accessLevel == AccessLevel::Admin || accessLevel == AccessLevel::SuperAdmin)
//    {
//        max = AccessLevel::Admin;
//    }
//    else
//    {
//        max = AccessLevel::Admin - 1;
//    }

//    for(int i = 0; i <= max; i++)
//    {
//       lst.append(metaEnum.key(i));
//    }
//    return lst;
//}

//UsersInfo::UsersInfo()
//{

//}





