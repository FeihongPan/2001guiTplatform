#ifndef TEMPLATELIBMODEL_H
#define TEMPLATELIBMODEL_H

#include "GUIFramework_global.h"
#include "ITemplateLib/Data/templateinfo.h"

#include <QAbstractTableModel>

class GUIFRAMEWORK_EXPORT TemplateLibModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TemplateLibModel(QObject *parent = nullptr);

    void SetModel(const QStringList Templates);
    void resetModel(QStringList Templates);
    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QStringList TemplateLibNames;
    QStringList header;
};

#endif // TEMPLATELIBMODEL_H
