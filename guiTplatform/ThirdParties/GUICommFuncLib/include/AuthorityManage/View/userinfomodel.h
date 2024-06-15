#ifndef USERINFOMODEL_H
#define USERINFOMODEL_H

#include "GUICommFuncLib_global.h"

#include "AuthorityManage/Data/userinfo.h"

#include <QAbstractTableModel>

class GUICOMMFUNCLIB_EXPORT UserInfoModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit UserInfoModel(QObject *parent = nullptr);

    void SetModel(S_UsersInfo *users);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    void resetModel(S_UsersInfo *usersInfo);
private:
    S_UsersInfo *usersInfo;
    QStringList header;
};

#endif // USERINFOMODEL_H
