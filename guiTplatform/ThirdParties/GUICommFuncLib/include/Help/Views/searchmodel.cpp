#include "searchmodel.h"

SearchModel::SearchModel(QObject *parent)
    : QPdfSearchModel(parent)
{

}

QVariant SearchModel::data(const QModelIndex &index, int role) const
{
    auto ret = QPdfSearchModel::data(index, role);

    if (Qt::DisplayRole == role)
    {
        auto result = resultAtIndex(index.row());
        auto str = ret.toString();
        ret = QString::number(result.page() + 1) + "." + QString::number(data(index, int(Role::IndexOnPage)).toInt() + 1) + "." + str.replace(result.contextBefore(), "");
    }

    return ret;
}
