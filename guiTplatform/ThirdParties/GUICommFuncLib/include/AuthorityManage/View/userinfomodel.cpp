#include "userinfomodel.h"
#include "Converter/enumconverter.h"

UserInfoModel::UserInfoModel(QObject *parent) : QAbstractTableModel(parent)
{
    header << "UserName"  << "AccessLevel";
}

void UserInfoModel::SetModel(S_UsersInfo *users)
{
    this->usersInfo = users;
}

int UserInfoModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return usersInfo->lstUsersInfo.count();
}

int UserInfoModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant UserInfoModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }

    if(role == Qt::TextAlignmentRole)
    {
        return Qt::AlignCenter;
    }

    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        const int row = index.row();
        switch (index.column())
        {
            case 0: return usersInfo->lstUsersInfo.at(row).userName;
            case 1: return EnumConverter::ConvertToString(usersInfo->lstUsersInfo.at(row).accessLevel);
        }
    }

    if (role == Qt::UserRole)
    {
        const int row = index.row();
        return QVariant::fromValue(usersInfo->lstUsersInfo[row]);
    }
    return QVariant();
}

QVariant UserInfoModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role!=Qt::DisplayRole)
        return QVariant();
    if(role==Qt::TextAlignmentRole)
        return Qt::AlignCenter;
    if(orientation==Qt::Horizontal)
    {
        return header.at(section);
    }
    return QVariant();
}

void UserInfoModel::resetModel(S_UsersInfo *usersInfo)
{
    beginResetModel();
    this->usersInfo = usersInfo;
    endResetModel();
}
