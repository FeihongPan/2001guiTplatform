#include "logprocessmodel.h"

LogProcessModel::LogProcessModel(QObject *parent) : QAbstractTableModel(parent)
{
}

void LogProcessModel::setModel(S_LogInfo_Process *messages)
{
    this->m_Messages = messages;
}

void LogProcessModel::resetModel(S_LogInfo_Process *messages)
{
    if(messages)
    {
        beginResetModel();
        this->m_Messages = messages;
        endResetModel();
    }
}

S_LogInfo_Process *LogProcessModel::getData()
{
    return this->m_Messages;
}

int LogProcessModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_Messages->dic_ProcessInfo.keys().size();
}

int LogProcessModel::columnCount(const QModelIndex &parent) const
{
    return m_Messages->lst_Header.values.size() + 1;
}

QVariant LogProcessModel::data(const QModelIndex &index, int role) const
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
                return m_Messages->dic_ProcessInfo.keys().at(row);
                break;
            default:
                QString key = m_Messages->dic_ProcessInfo.keys().at(row);
                QString name = m_Messages->lst_Header.values.at(index.column() - 1);
                return m_Messages->dic_ProcessInfo.value(key).dic_ProcessData.value(name);
                break;
        }
    }
    return QVariant();
}
