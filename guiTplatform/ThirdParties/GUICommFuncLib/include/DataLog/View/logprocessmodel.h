#ifndef LOGPROCESSMODEL_H
#define LOGPROCESSMODEL_H

#include "GUICommFuncLib_global.h"
#include "DataLog/Data/loginfo.h"

#include <QStandardItemModel>
#include <QObject>
#include <QAbstractTableModel>

class GUICOMMFUNCLIB_EXPORT LogProcessModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit LogProcessModel(QObject *parent = nullptr);

    void setModel(S_LogInfo_Process *messages);
    void resetModel(S_LogInfo_Process *messages);
    S_LogInfo_Process *getData();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

private:
    QStringList header;
    S_LogInfo_Process *m_Messages;
};


#endif // LOGPROCESSMODEL_H
