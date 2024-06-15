#include "alarmeditmodel.h"

AlarmEditModel::AlarmEditModel(QObject *parent) : QAbstractTableModel(parent)
{

}

void AlarmEditModel::SetModel(S_AlarmsInfo *pAlarms)
{
    this->m_AlarmsInfo = pAlarms;
}

void AlarmEditModel::SetHeader(const QStringList &lst_Header)
{
    this->m_lst_Header = lst_Header;
}

int AlarmEditModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_AlarmsInfo->lst_AlarmsData.count();
}

int AlarmEditModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_lst_Header.count();
}

QVariant AlarmEditModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }

    if(role == Qt::TextAlignmentRole)
    {
        if(index.column() == 0)
        {
            return Qt::AlignCenter;
        }
        return Qt::AlignVCenter;
    }

    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        const int row = index.row();
        if(index.column() == 0)
        {
            return m_AlarmsInfo->lst_AlarmsData[row].alarmCode;
        }
        else if (index.column() == 5)
        {
            return m_AlarmsInfo->lst_AlarmsData[row].message;
        }
        else if(index.column() == 6)
        {
            return m_AlarmsInfo->lst_AlarmsData[row].brief;
        }
    }

    if(role == Qt::CheckStateRole)
    {
        const int row = index.row();
        if(index.column() == 1)
        {
            return m_AlarmsInfo->lst_AlarmsData[row].dic_Methodvalidity[S_AlarmData::Retry] ? Qt::Checked : Qt::Unchecked;
        }
        else if (index.column() == 2)
        {
            return m_AlarmsInfo->lst_AlarmsData[row].dic_Methodvalidity[S_AlarmData::Skip] ? Qt::Checked : Qt::Unchecked;
        }
        else if(index.column() == 3)
        {
            return m_AlarmsInfo->lst_AlarmsData[row].dic_Methodvalidity[S_AlarmData::Continue] ? Qt::Checked : Qt::Unchecked;
        }
        else if(index.column() == 4)
        {
            return m_AlarmsInfo->lst_AlarmsData[row].dic_Methodvalidity[S_AlarmData::Reset] ? Qt::Checked : Qt::Unchecked;
        }
    }

    if (role == Qt::UserRole)
    {
        const int row = index.row();
        return QVariant::fromValue(m_AlarmsInfo->lst_AlarmsData[row].alarmCode);
    }
    return QVariant();
}

QVariant AlarmEditModel::headerData(int section, Qt::Orientation orientation, int role) const
{
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
        return m_lst_Header.at(section);
    }
    return QVariant();
}

bool AlarmEditModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
    {
        return false;
    }

    else if(role == Qt::EditRole && (index.column() == 0 || index.column() > 4))
    {
        const int row = index.row();

        switch(index.column())
        {

            case 0:
                if(value.toUInt() >= 0 && value.toUInt() <= 99999999)
                {
                    m_AlarmsInfo->lst_AlarmsData[row].alarmCode = value.toString();
                }
                break;

            case 5:
                m_AlarmsInfo->lst_AlarmsData[row].message = value.toString();
                break;

            case 6:
                m_AlarmsInfo->lst_AlarmsData[row].brief = value.toString();
                break;
        }
        emit dataChanged(index, index);
        return true;
    }
    else if(role == Qt::CheckStateRole && index.column() >= 1 && index.column() <= 4)
    {
        const int row = index.row();

        switch (index.column())
        {

            case 1:
                m_AlarmsInfo->lst_AlarmsData[row].dic_Methodvalidity[S_AlarmData::Retry] = value == Qt::Checked;
                break;

            case 2:
                m_AlarmsInfo->lst_AlarmsData[row].dic_Methodvalidity[S_AlarmData::Skip] = value == Qt::Checked;
                break;

            case 3:
                m_AlarmsInfo->lst_AlarmsData[row].dic_Methodvalidity[S_AlarmData::Continue] = value == Qt::Checked;
                break;

            case 4:
                m_AlarmsInfo->lst_AlarmsData[row].dic_Methodvalidity[S_AlarmData::Reset] = value == Qt::Checked;
                break;

            default:
                break;
        }
        emit dataChanged(index, index);
    }
    return true;
}

bool AlarmEditModel::AddModelData(const int &nRow, const S_AlarmData &alarm)
{
    if(nRow < 0 || nRow > rowCount())
    {
        return false;
    }
    beginInsertRows(QModelIndex(), nRow, nRow);
    m_AlarmsInfo->lst_AlarmsData.append(alarm);
    endInsertRows();
    return true;
}

bool AlarmEditModel::DeleteModelData(const int &nRow)
{
    if(nRow < 0 || nRow > rowCount())
    {
        return false;
    }
    beginRemoveRows(QModelIndex(), nRow, nRow);
    m_AlarmsInfo->lst_AlarmsData.removeAt(nRow);
    endRemoveRows();
    return true;
}

void AlarmEditModel::ResetModel(S_AlarmsInfo *pAlarms)
{
    beginResetModel();
    m_AlarmsInfo = pAlarms;
    endResetModel();
}

Qt::ItemFlags AlarmEditModel::flags(const QModelIndex &index) const
{
    const int col = index.column();
    if(col > 0 && col <= 4)
    {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
    }
    else
    {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable  | Qt::ItemIsDropEnabled;
    }
}
