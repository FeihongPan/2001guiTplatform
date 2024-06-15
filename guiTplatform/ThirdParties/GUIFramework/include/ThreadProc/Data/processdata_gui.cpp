#include "processdata_gui.h"

SR_SingleProcData::SR_SingleProcData()
{

}

SR_SingleProcData::SR_SingleProcData(const S_SingleProcData &data)
{
    this->processName = data.processName;
    this->startIndex = data.startIndex;
    this->endIndex = data.endIndex;
    this->stepIndex = data.stepIndex;
    this->jumpOutIndex = data.jumpOutIndex;
    this->isInitialized = data.isInitialized;
    this->isContinousRunning = data.isContinousRunning;
    this->isStepRunning = data.isStepRunning;
    this->isNextStepAction = data.isNextStepAction;
    this->selectedSignal = data.selectedSignal;
    this->selectedSignalTargetState = data.selectedSignalTargetState;
    this->dic_ProcessSignal = data.dic_ProcessSignal;
    this->task = data.task;
    this->taskIndex = data.taskIndex;
}

SR_SingleProcData::SR_SingleProcData(const SR_SingleProcData &data)
{
    this->processName = data.processName;
    this->startIndex = data.startIndex;
    this->endIndex = data.endIndex;
    this->stepIndex = data.stepIndex;
    this->jumpOutIndex = data.jumpOutIndex;
    this->isInitialized = data.isInitialized;
    this->isContinousRunning = data.isContinousRunning;
    this->isStepRunning = data.isStepRunning;
    this->isNextStepAction = data.isNextStepAction;
    this->selectedSignal = data.selectedSignal;
    this->selectedSignalTargetState = data.selectedSignalTargetState;
    this->dic_ProcessSignal = data.dic_ProcessSignal;
    this->task = data.task;
    this->taskIndex = data.taskIndex;
}

SR_SingleProcData &SR_SingleProcData::operator=(const S_SingleProcData &data)
{
    this->processName = data.processName;
    this->startIndex = data.startIndex;
    this->endIndex = data.endIndex;
    this->stepIndex = data.stepIndex;
    this->jumpOutIndex = data.jumpOutIndex;
    this->isInitialized = data.isInitialized;
    this->isContinousRunning = data.isContinousRunning;
    this->isStepRunning = data.isStepRunning;
    this->isNextStepAction = data.isNextStepAction;
    this->selectedSignal = data.selectedSignal;
    this->selectedSignalTargetState = data.selectedSignalTargetState;
    this->dic_ProcessSignal = data.dic_ProcessSignal;
    this->task = data.task;
    this->taskIndex = data.taskIndex;
    return *this;
}

SR_SingleProcData &SR_SingleProcData::operator=(const SR_SingleProcData &data)
{
    this->processName = data.processName;
    this->startIndex = data.startIndex;
    this->endIndex = data.endIndex;
    this->stepIndex = data.stepIndex;
    this->jumpOutIndex = data.jumpOutIndex;
    this->isInitialized = data.isInitialized;
    this->isContinousRunning = data.isContinousRunning;
    this->isStepRunning = data.isStepRunning;
    this->isNextStepAction = data.isNextStepAction;
    this->selectedSignal = data.selectedSignal;
    this->selectedSignalTargetState = data.selectedSignalTargetState;
    this->dic_ProcessSignal = data.dic_ProcessSignal;
    this->task = data.task;
    this->taskIndex = data.taskIndex;
    return *this;
}
