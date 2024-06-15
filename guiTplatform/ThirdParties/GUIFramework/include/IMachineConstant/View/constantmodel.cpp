#include "constantmodel.h"

ConstantModel::ConstantModel(QObject *parent) : QAbstractTableModel(parent)
{
    header << "Index" << "Constants";
}

void ConstantModel::SetModel(const QStringList constants)
{
    this->constantNames = constants;
}

void ConstantModel::resetModel(QStringList constants)
{
    beginResetModel();
    this->constantNames = constants;
    endResetModel();
}

QVariant ConstantModel::headerData(int section, Qt::Orientation orientation, int role) const
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

int ConstantModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return constantNames.count();
}

int ConstantModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 2;
}

QVariant ConstantModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    if(role == Qt::TextAlignmentRole)
    {
        return Qt::AlignCenter;
    }

    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        const int row = index.row();
        switch (index.column())
        {
            case 0: return row + 1;
            case 1: return constantNames.at(row);
        }
    }

    if (role == Qt::UserRole)
    {
        const int row = index.row();
        return constantNames.at(row);
    }
    return QVariant();
}
