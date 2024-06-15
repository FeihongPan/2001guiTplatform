#ifndef CONSTANTMODEL_H
#define CONSTANTMODEL_H

#include "GUIFramework_global.h"

#include <QAbstractTableModel>

class GUIFRAMEWORK_EXPORT ConstantModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ConstantModel(QObject *parent = nullptr);
    void SetModel(const QStringList constants);
    void resetModel(QStringList constants);
    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QStringList constantNames;
    QStringList header;
};

#endif // CONSTANTMODEL_H
