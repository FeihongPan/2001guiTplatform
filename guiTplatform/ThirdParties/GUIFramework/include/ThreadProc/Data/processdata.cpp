#include "processdata.h"
#include "processdata_gui.h"

S_SingleProcData::S_SingleProcData()
{
    this->startIndex = 0;
    this->endIndex = 999000;
    this->stepIndex = 0;
    this->jumpOutIndex = 0;
    this->isInitialized = false;
    this->isContinousRunning = false;
    this->isStepRunning = false;
    this->isNextStepAction = false;
    this->selectedSignalTargetState = false;
}

S_SingleProcData::S_SingleProcData(QString name)
{
    this->processName = name;
    this->startIndex = 0;
    this->endIndex = 999000;
    this->stepIndex = 0;
    this->jumpOutIndex = 0;
    this->isInitialized = false;
    this->isContinousRunning = false;
    this->isStepRunning = false;
    this->isNextStepAction = false;
    this->selectedSignalTargetState = false;
}

S_SingleProcData::S_SingleProcData(const S_SingleProcData &procData)
{
    this->processName = procData.processName;
    this->startIndex = procData.startIndex;
    this->endIndex = procData.endIndex;
    this->stepIndex = procData.stepIndex;
    this->jumpOutIndex = procData.jumpOutIndex;
    this->isInitialized = procData.isInitialized;
    this->isContinousRunning = procData.isContinousRunning;
    this->isStepRunning = procData.isStepRunning;
    this->isNextStepAction = procData.isNextStepAction;
    this->selectedSignal = procData.selectedSignal;
    this->selectedSignalTargetState = procData.selectedSignalTargetState;
    this->dic_ProcessSignal = procData.dic_ProcessSignal;
    this->task = procData.task;
    this->taskIndex = procData.taskIndex;
}

S_SingleProcData::S_SingleProcData(const SR_SingleProcData &procData)
{
    this->processName = procData.processName.value;
    this->startIndex = procData.startIndex.value;
    this->endIndex = procData.endIndex.value;
    this->stepIndex = procData.stepIndex.value;
    this->jumpOutIndex = procData.jumpOutIndex.value;
    this->isInitialized = procData.isInitialized.value;
    this->isContinousRunning = procData.isContinousRunning.value;
    this->isStepRunning = procData.isStepRunning.value;
    this->isNextStepAction = procData.isNextStepAction.value;
    this->selectedSignal = procData.selectedSignal;
    this->selectedSignalTargetState = procData.selectedSignalTargetState;
    this->dic_ProcessSignal = procData.dic_ProcessSignal;
    this->task = procData.task.value;
    this->taskIndex = procData.taskIndex.value;
}

S_SingleProcData &S_SingleProcData::operator=(const S_SingleProcData &procData)
{
    this->processName = procData.processName;
    this->startIndex = procData.startIndex;
    this->endIndex = procData.endIndex;
    this->stepIndex = procData.stepIndex;
    this->jumpOutIndex = procData.jumpOutIndex;
    this->isInitialized = procData.isInitialized;
    this->isContinousRunning = procData.isContinousRunning;
    this->isStepRunning = procData.isStepRunning;
    this->isNextStepAction = procData.isNextStepAction;
    this->selectedSignal = procData.selectedSignal;
    this->selectedSignalTargetState = procData.selectedSignalTargetState;
    this->dic_ProcessSignal = procData.dic_ProcessSignal;
    this->task = procData.task;
    this->taskIndex = procData.taskIndex;
    return *this;
}

S_SingleProcData &S_SingleProcData::operator=(const SR_SingleProcData &procData)
{
    this->processName = procData.processName.value;
    this->startIndex = procData.startIndex.value;
    this->endIndex = procData.endIndex.value;
    this->stepIndex = procData.stepIndex.value;
    this->jumpOutIndex = procData.jumpOutIndex.value;
    this->isInitialized = procData.isInitialized.value;
    this->isContinousRunning = procData.isContinousRunning.value;
    this->isStepRunning = procData.isStepRunning.value;
    this->isNextStepAction = procData.isNextStepAction.value;
    this->selectedSignal = procData.selectedSignal;
    this->selectedSignalTargetState = procData.selectedSignalTargetState;
    this->dic_ProcessSignal = procData.dic_ProcessSignal;
    this->task = procData.task.value;
    this->taskIndex = procData.taskIndex.value;
    return *this;
}

S_ProcListData::S_ProcListData()
{

}

S_ProcListData::S_ProcListData(const S_ProcListData &procListData)
{
    this->dic_PorcListData.clear();
    QStringList lst_ProcNames = procListData.dic_PorcListData.keys();
    for(int i = 0; i < lst_ProcNames.count(); i++)
    {
        this->dic_PorcListData.insert(lst_ProcNames[i], procListData.dic_PorcListData[lst_ProcNames[i]]);
    }
}

ProcListBasicInfo::ProcListBasicInfo()
{

}
