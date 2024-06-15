#include "reportedalarmsmodel.h"

ReportedAlarmsModel::ReportedAlarmsModel(QObject *parent) : QAbstractTableModel(parent)
{
}

void ReportedAlarmsModel::SetHeader(const QStringList &lst_Header)
{
    this->m_lst_Header = lst_Header;
}

void ReportedAlarmsModel::SetModel(S_ReportedAlarms *pAlarms)
{
    this->p_reportedAlarms = pAlarms;
}

int ReportedAlarmsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return p_reportedAlarms->lst_ReportedAlarms.count();
}

int ReportedAlarmsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}

QVariant ReportedAlarmsModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }

    if(role == Qt::TextAlignmentRole)
    {
        if(index.column() == 2)
        {
            return Qt::AlignVCenter;
        }
        return Qt::AlignCenter;
    }

    if(role == Qt::DisplayRole)
    {
        const int row = index.row();
        switch (index.column())
        {
            case 0:
                return p_reportedAlarms->lst_ReportedAlarms.at(row).alarmData.alarmCode;
            case 1:
                return p_reportedAlarms->lst_ReportedAlarms.at(row).reportTime;
            case 2:
                return p_reportedAlarms->lst_ReportedAlarms.at(row).alarmData.message + p_reportedAlarms->lst_ReportedAlarms.at(row).addtionalNotes;
        }
    }

    if (role == Qt::UserRole)
    {
        const int row = index.row();
        return QVariant::fromValue(&p_reportedAlarms->lst_ReportedAlarms[row]);
    }
    return QVariant();
}

QVariant ReportedAlarmsModel::headerData(int section, Qt::Orientation orientation, int role) const
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

S_ReportedAlarms *ReportedAlarmsModel::GetData()
{
    return p_reportedAlarms;
}

void ReportedAlarmsModel::ResetModel(S_ReportedAlarms *pAlarms)
{
    beginResetModel();
    p_reportedAlarms = pAlarms;
    endResetModel();
}


