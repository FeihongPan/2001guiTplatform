#ifndef PROCESSDATA_H
#define PROCESSDATA_H

#include "GUIFramework_global.h"
#include "BasicValue/serializablelist.h"
#include "Serializer/QSerializer"

class GUIFRAMEWORK_EXPORT ProcListBasicInfo : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_QT_DICT_OBJECTS(QMap, QString, S_List_String, dic_ProcInfo)

public:
    ProcListBasicInfo();
};

class SR_SingleProcData;
class GUIFRAMEWORK_EXPORT S_SingleProcData : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(QString, processName)
    QS_FIELD(int, startIndex)
    QS_FIELD(int, endIndex)
    QS_FIELD(int, stepIndex)
    QS_FIELD(int, jumpOutIndex)
    QS_FIELD(bool, isInitialized)
    QS_FIELD(bool, isContinousRunning)
    QS_FIELD(bool, isStepRunning)
    QS_FIELD(bool, isNextStepAction)
    QS_FIELD(QString, selectedSignal)
    QS_FIELD(bool, selectedSignalTargetState)
    QS_QT_DICT(QMap, QString, bool, dic_ProcessSignal)
    QS_FIELD(QString, task)
    QS_FIELD(int, taskIndex)

public:
    S_SingleProcData();
    S_SingleProcData(QString name);
    S_SingleProcData(const S_SingleProcData &procData);
    S_SingleProcData(const SR_SingleProcData &procData);
    S_SingleProcData &operator=(const S_SingleProcData &procData);
    S_SingleProcData &operator=(const SR_SingleProcData &procData);

};

class GUIFRAMEWORK_EXPORT S_ProcListData : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_QT_DICT_OBJECTS(QMap, QString, S_SingleProcData, dic_PorcListData)

public:
    S_ProcListData();
    S_ProcListData(const S_ProcListData &procListData);
};

#endif // PROCESSDATA_H
