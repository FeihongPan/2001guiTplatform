#include "recipemodel.h"

#include <QDebug>

RecipeModel::RecipeModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    header << "Index" << "Recipes";
}

void RecipeModel::SetModel(const QStringList recipes)
{
    this->recipeNames = recipes;
}

void RecipeModel::resetModel(QStringList recipes)
{
    beginResetModel();
    this->recipeNames = recipes;
    endResetModel();
}

QVariant RecipeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }
    if(role == Qt::TextAlignmentRole)
    {
        return Qt::AlignCenter;
    }
    if(orientation == Qt::Horizontal)
    {
        return header.at(section);
    }
    return QVariant();
}

int RecipeModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
    {
        return 0;
    }

    // FIXME: Implement me!
    return recipeNames.count();
}

int RecipeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
    {
        return 0;
    }

    // FIXME: Implement me!
    return 2;
}

QVariant RecipeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

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
            case 0:
                return row + 1;
            case 1:
                return recipeNames.at(row);
        }
    }

    if (role == Qt::UserRole)
    {
        const int row = index.row();
        return recipeNames.at(row);
    }
    return QVariant();
}
