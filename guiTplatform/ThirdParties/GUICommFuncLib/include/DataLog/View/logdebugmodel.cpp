#include "logdebugmodel.h"

LogDebugModel::LogDebugModel(QObject *parent) : QAbstractTableModel(parent)
{
    header << "DateTime" << "Message";
}

void LogDebugModel::setModel(S_LogInfo_Debugs *messages)
{
    this->m_Messages = messages;
}

void LogDebugModel::resetModel(S_LogInfo_Debugs *messages)
{
    beginResetModel();
    this->m_Messages = messages;
    endResetModel();
}

S_LogInfo_Debugs *LogDebugModel::getData()
{
    return this->m_Messages;
}

QVariant LogDebugModel::headerData(int section, Qt::Orientation orientation, int role) const
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
        return header.at(section);
    }
    return QVariant();
}

int LogDebugModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_Messages->dicMessage.keys().size();
}

int LogDebugModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return header.count();
}

QVariant LogDebugModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if(role == Qt::TextAlignmentRole)
    {
        if(index.column()==1)
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
                return m_Messages->dicMessage.keys().at(row);
            case 1:
                return m_Messages->dicMessage.values().at(row);
                break;
        }
    }
    return QVariant();
}
