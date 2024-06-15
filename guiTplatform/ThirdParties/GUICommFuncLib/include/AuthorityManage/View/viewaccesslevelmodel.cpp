#include "viewaccesslevelmodel.h"
#include "Language/language.h"
#include <QPushButton>
#include <QDebug>
ViewAccessLevelModel::ViewAccessLevelModel(QObject *parent) : QAbstractTableModel(parent)
{
    accessLevels = EnumConverter::ConvertToStringList<AccessLevel::Level>();
    if(accessLevels.contains("SuperAdmin"))
    {
        accessLevels.removeOne("SuperAdmin");
    }
    header << "MainFunc" << accessLevels;
}

void ViewAccessLevelModel::SetModel(QList<AuthorityWidget *> wdgs)
{
    this->lst_AuthorityWidget = wdgs;
}

int ViewAccessLevelModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return lst_AuthorityWidget.count();
}

int ViewAccessLevelModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return header.count();
}

QVariant ViewAccessLevelModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }

    if(role == Qt::TextAlignmentRole)
    {
        return Qt::AlignCenter;
    }

//    if (role == Qt::BackgroundRole)
//    {
//        const int col = index.column();
//        if(col == 1)
//        {
////            return QVariant(Qt::GlobalColor(Qt::red));
//            return QVariant::fromValue(QColor(100,200,200));
//        }
//    }

    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        const int row = index.row();
        if(index.column() == 0)
        {
            return  Tr(lst_AuthorityWidget.at(row)->wdgInfo->wdgName);
        }
    }      
    else if(role==Qt::CheckStateRole)
    {
        const int row = index.row();

        if(index.column() >= 1 && index.column() <= accessLevels.count())
        {
            return lst_AuthorityWidget.at(row)->wdgInfo->accessLevels.contains(EnumConverter::ConvertStringToEnum<AccessLevel::Level>(accessLevels.at(index.column()-1)))? Qt::Checked:Qt::Unchecked;
        }
    }

    if (role == Qt::UserRole)
    {
        const int row = index.row();
        return QVariant::fromValue(lst_AuthorityWidget.at(row));
    }
    return QVariant();
}

QVariant ViewAccessLevelModel::headerData(int section, Qt::Orientation orientation, int role) const
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

bool ViewAccessLevelModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
        return false;
//    if(index.isValid() && role==Qt::EditRole)
//    {
//        switch(index.column())
//        {
//        case 1:
//            vector[index.row()]->pointX=value;
//            break;
//        case 2:
//            vector[index.row()]->pointY=value;
//            break;
//        }
//        emit dataChanged(index,index);
//        return true;
//    }
    else if(role==Qt::CheckStateRole && index.column() >= 0)
    {
        if(value==Qt::Checked)
        {
            lst_AuthorityWidget[index.row()]->wdgInfo->accessLevels.append(EnumConverter::ConvertStringToEnum<AccessLevel::Level>(accessLevels.at(index.column()-1)));
        }
        else
        {
            lst_AuthorityWidget[index.row()]->wdgInfo->accessLevels.removeOne(EnumConverter::ConvertStringToEnum<AccessLevel::Level>(accessLevels.at(index.column()-1)));
        }
        emit dataChanged(index,index);
    }
    return true;
}

Qt::ItemFlags ViewAccessLevelModel::flags(const QModelIndex &index) const
{
    if (enable)
    {
        if(disableRow.contains(index.row()) || disableColumn.contains(index.column()))
        {
            return Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
        }
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
    }
    else
    {
        if(index.column() == 0)
        {
            return Qt::ItemIsEnabled| Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
        }
        else
        {
           return Qt::ItemIsSelectable;
        }        
    }
}

void ViewAccessLevelModel::resetModel(QList<AuthorityWidget *> wdgs)
{
    beginResetModel();
    this->lst_AuthorityWidget = wdgs;
    endResetModel();
}
