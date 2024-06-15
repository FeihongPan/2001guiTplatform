#include "historyalarmsmodel.h"

HistoryAlarmsModel::HistoryAlarmsModel(QObject *parent) : QAbstractTableModel(parent)
{
    m_dic_Method[S_AlarmData::Retry] = "Retry";
    m_dic_Method[S_AlarmData::Skip] = "Skip";
    m_dic_Method[S_AlarmData::Continue] = "Continue";
    m_dic_Method[S_AlarmData::Reset] = "Reset";
}

void HistoryAlarmsModel::SetHeader(const QStringList &lst_Header)
{
    this->m_lst_Header = lst_Header;
}

void HistoryAlarmsModel::SetModel(S_ReportedAlarms *pAlarms)
{
    this->p_HistoryAlarms = pAlarms;
}

void HistoryAlarmsModel::ResetModel(S_ReportedAlarms *pAlarms)
{
    beginResetModel();
    this->p_HistoryAlarms = pAlarms;
    endResetModel();
}

S_ReportedAlarms *HistoryAlarmsModel::GetData()
{
    return p_HistoryAlarms;
}

QVariant HistoryAlarmsModel::headerData(int section, Qt::Orientation orientation, int role) const
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

int HistoryAlarmsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return p_HistoryAlarms->lst_ReportedAlarms.count();
}

int HistoryAlarmsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_lst_Header.count();
}

QVariant HistoryAlarmsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if(role == Qt::TextAlignmentRole)
    {
        return Qt::AlignCenter;
    }

    if(role == Qt::DisplayRole)
    {
        const int row = index.row();
        switch (index.column())
        {
            case 0:
                return p_HistoryAlarms->lst_ReportedAlarms.at(row).alarmData.alarmCode;
            case 1:
                return p_HistoryAlarms->lst_ReportedAlarms.at(row).reportTime;
            case 2:
                return p_HistoryAlarms->lst_ReportedAlarms.at(row).alarmData.message;
            case 3:
                return p_HistoryAlarms->lst_ReportedAlarms.at(row).alarmData.brief;
            case 4:
            {
                QMap<S_AlarmData::ErrorHandlingMethod, bool> dic_Method = p_HistoryAlarms->lst_ReportedAlarms.at(row).alarmData.dic_Methodvalidity;
                QList<S_AlarmData::ErrorHandlingMethod> lst_keys = dic_Method.keys();
                for(auto &key : lst_keys)
                {
                    if(dic_Method[key])
                    {
                        return m_dic_Method[key];
                    }
                }
                return "";
            }
            case 5:
                return p_HistoryAlarms->lst_ReportedAlarms.at(row).releaseUser;
            case 6:
                return p_HistoryAlarms->lst_ReportedAlarms.at(row).releaseTime;
            case 7:
                return p_HistoryAlarms->lst_ReportedAlarms.at(row).addtionalNotes;
                break;
        }
    }
    if (role == Qt::UserRole)
    {
        const int nRow = index.row();
        return QVariant::fromValue(&p_HistoryAlarms->lst_ReportedAlarms[nRow]);
    }
    return QVariant();
}
