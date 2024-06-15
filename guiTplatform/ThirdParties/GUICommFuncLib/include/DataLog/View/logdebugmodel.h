#ifndef LOGDEBUGMODEL_H
#define LOGDEBUGMODEL_H

#include "GUICommFuncLib_global.h"
#include "DataLog/Data/loginfo.h"

#include <QAbstractTableModel>

class GUICOMMFUNCLIB_EXPORT LogDebugModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit LogDebugModel(QObject *parent = nullptr);

    void setModel(S_LogInfo_Debugs *messages);
    void resetModel(S_LogInfo_Debugs *messages);
    S_LogInfo_Debugs *getData();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

private:
    QStringList header;
    S_LogInfo_Debugs *m_Messages;
};

#endif // LOGDEBUGMODEL_H
