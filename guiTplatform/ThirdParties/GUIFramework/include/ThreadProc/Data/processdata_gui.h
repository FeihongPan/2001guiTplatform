#ifndef PROCESSDATA_GUI_H
#define PROCESSDATA_GUI_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "processdata.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT SR_SingleProcData : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TString, processName)
    QS_OBJECT(TInt, startIndex)
    QS_OBJECT(TInt, endIndex)
    QS_OBJECT(TInt, stepIndex)
    QS_OBJECT(TInt, jumpOutIndex)
    QS_OBJECT(TBool, isInitialized)
    QS_OBJECT(TBool, isContinousRunning)
    QS_OBJECT(TBool, isStepRunning)
    QS_OBJECT(TBool, isNextStepAction)
    QS_FIELD(QString, selectedSignal)
    QS_FIELD(bool, selectedSignalTargetState)
    QS_QT_DICT(QMap, QString, bool, dic_ProcessSignal)
    QS_OBJECT(TString, task)
    QS_OBJECT(TInt, taskIndex)

public:
    SR_SingleProcData();
    SR_SingleProcData(const S_SingleProcData &data);
    SR_SingleProcData(const SR_SingleProcData &data);
    SR_SingleProcData &operator=(const S_SingleProcData &data);
    SR_SingleProcData &operator=(const SR_SingleProcData &data);
};

#endif // PROCESSDATA_GUI_H
