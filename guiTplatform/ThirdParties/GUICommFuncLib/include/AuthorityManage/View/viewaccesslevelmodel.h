#ifndef mainFuncModel_H
#define mainFuncModel_H

#include "GUICommFuncLib_global.h"
#include "AuthorityComponent/authoritywidget.h"

#include <QAbstractTableModel>

class GUICOMMFUNCLIB_EXPORT ViewAccessLevelModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ViewAccessLevelModel(QObject *parent = nullptr);

    void SetModel(QList<AuthorityWidget *> wdgs);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    void resetModel(QList<AuthorityWidget *> wdgs);
    bool enable = false;
    QList<int> disableColumn;
    QList<int> disableRow;

private:
    QList<AuthorityWidget *> lst_AuthorityWidget;
    QStringList header;
    QStringList accessLevels;
};

#endif // mainFuncModel_H
