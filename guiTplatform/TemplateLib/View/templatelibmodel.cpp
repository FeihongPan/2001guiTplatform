#include "templatelibmodel.h"
#include <QDebug>

TemplateLibModel::TemplateLibModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    header << "Index" << "Templates";
}

void TemplateLibModel::SetModel(const QStringList Templates)
{
    this->TemplateLibNames = Templates;
}

void TemplateLibModel::resetModel(QStringList Templates)
{
    beginResetModel();
    this->TemplateLibNames = Templates;
    endResetModel();
}

QVariant TemplateLibModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
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

int TemplateLibModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return TemplateLibNames.count();
}

int TemplateLibModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 2;
}

QVariant TemplateLibModel::data(const QModelIndex &index, int role) const
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
            case 1: return TemplateLibNames.at(row);
        }
    }

    if (role == Qt::UserRole)
    {
        const int row = index.row();
        return TemplateLibNames.at(row);
    }
    return QVariant();
}
