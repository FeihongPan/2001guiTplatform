#ifndef RECIPEMODEL_H
#define RECIPEMODEL_H

#include <QAbstractTableModel>

class RecipeModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit RecipeModel(QObject *parent = nullptr);

    void SetModel(const QStringList recipes);
    void resetModel(QStringList recipes);
    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QStringList recipeNames;
    QStringList header;
};

#endif // RECIPEMODEL_H
