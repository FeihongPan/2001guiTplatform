#include "environmentctrl.h"

S_EnvironmentCtrl::S_EnvironmentCtrl()
{

}

S_EnvironmentCtrl::S_EnvironmentCtrl(const S_EnvironmentCtrl &instance)
{
    this->tempCtrl = instance.tempCtrl;
    this->TCWUnit = instance.TCWUnit;
    this->FanUnit = instance.FanUnit;
    this->flowRateSensor = instance.flowRateSensor;
    this->facilities = instance.facilities;
    this->maintenance = instance.maintenance;
}

S_EnvironmentCtrl::S_EnvironmentCtrl(const SR_EnvironmentCtrl &instance)
{
    this->tempCtrl = instance.tempCtrl;
    this->TCWUnit = instance.TCWUnit;
    this->FanUnit = instance.FanUnit;

    this->flowRateSensor.clear();
    for(int i = 0; i < instance.flowRateSensor.count(); i++)
    {
        this->flowRateSensor.append(instance.flowRateSensor[i]);
    }

    this->facilities = instance.facilities;
    this->maintenance = instance.maintenance;
}

S_EnvironmentCtrl &S_EnvironmentCtrl::operator=(const S_EnvironmentCtrl &instance)
{
    this->tempCtrl = instance.tempCtrl;
    this->TCWUnit = instance.TCWUnit;
    this->FanUnit = instance.FanUnit;
    this->flowRateSensor = instance.flowRateSensor;
    this->facilities = instance.facilities;
    this->maintenance = instance.maintenance;
    return *this;
}

S_EnvironmentCtrl &S_EnvironmentCtrl::operator=(const SR_EnvironmentCtrl &instance)
{
    this->tempCtrl = instance.tempCtrl;
    this->TCWUnit = instance.TCWUnit;
    this->FanUnit = instance.FanUnit;

    this->flowRateSensor.clear();
    for(int i = 0; i < instance.flowRateSensor.count(); i++)
    {
        this->flowRateSensor.append(instance.flowRateSensor[i]);
    }

    this->facilities = instance.facilities;
    this->maintenance = instance.maintenance;
    return *this;
}

SR_EnvironmentCtrl::SR_EnvironmentCtrl() : TValueBase()
{

}

SR_EnvironmentCtrl::SR_EnvironmentCtrl(const S_EnvironmentCtrl &instance) : TValueBase()
{
    this->tempCtrl = instance.tempCtrl;
    this->TCWUnit = instance.TCWUnit;
    this->FanUnit = instance.FanUnit;

    this->flowRateSensor.clear();
    for(int i = 0; i < instance.flowRateSensor.count(); i++)
    {
        this->flowRateSensor.append(instance.flowRateSensor[i]);
    }

    this->facilities = instance.facilities;
    this->maintenance = instance.maintenance;
}

SR_EnvironmentCtrl::SR_EnvironmentCtrl(const SR_EnvironmentCtrl &instance) : TValueBase(instance)
{
    this->tempCtrl = instance.tempCtrl;
    this->TCWUnit = instance.TCWUnit;
    this->FanUnit = instance.FanUnit;
    this->flowRateSensor = instance.flowRateSensor;
    this->facilities = instance.facilities;
    this->maintenance = instance.maintenance;
}

SR_EnvironmentCtrl &SR_EnvironmentCtrl::operator=(const S_EnvironmentCtrl &instance)
{
    this->tempCtrl = instance.tempCtrl;
    this->TCWUnit = instance.TCWUnit;
    this->FanUnit = instance.FanUnit;

    this->flowRateSensor.clear();
    for(int i = 0; i < instance.flowRateSensor.count(); i++)
    {
        this->flowRateSensor.append(instance.flowRateSensor[i]);
    }

    this->facilities = instance.facilities;
    this->maintenance = instance.maintenance;
    return *this;
}

SR_EnvironmentCtrl &SR_EnvironmentCtrl::operator=(const SR_EnvironmentCtrl &instance)
{
    TValueBase::operator=(instance);
    this->tempCtrl = instance.tempCtrl;
    this->TCWUnit = instance.TCWUnit;
    this->FanUnit = instance.FanUnit;
    this->flowRateSensor = instance.flowRateSensor;
    this->facilities = instance.facilities;
    this->maintenance = instance.maintenance;
    return *this;
}


S_TStableCriterion::S_TStableCriterion()
{

}

S_TStableCriterion::S_TStableCriterion(const S_TStableCriterion &instance)
{
    this->stage = instance.stage;
    this->dwellTime = instance.dwellTime;
    this->timeout = instance.timeout;
}

S_TStableCriterion::S_TStableCriterion(const SR_TStableCriterion &instance)
{
    this->stage = instance.stage.value;
    this->dwellTime = instance.dwellTime.value;
    this->timeout = instance.timeout.value;
}

S_TStableCriterion &S_TStableCriterion::operator=(const S_TStableCriterion &instance)
{
    this->stage = instance.stage;
    this->dwellTime = instance.dwellTime;
    this->timeout = instance.timeout;
    return *this;
}

S_TStableCriterion &S_TStableCriterion::operator=(const SR_TStableCriterion &instance)
{
    this->stage = instance.stage.value;
    this->dwellTime = instance.dwellTime.value;
    this->timeout = instance.timeout.value;
    return *this;
}

SR_TStableCriterion::SR_TStableCriterion() : TValueBase()
{

}

SR_TStableCriterion::SR_TStableCriterion(const S_TStableCriterion &instance) : TValueBase()
{
    this->stage = instance.stage;
    this->dwellTime = instance.dwellTime;
    this->timeout = instance.timeout;
}

SR_TStableCriterion::SR_TStableCriterion(const SR_TStableCriterion &instance) : TValueBase(instance)
{
    this->stage = instance.stage;
    this->dwellTime = instance.dwellTime;
    this->timeout = instance.timeout;
}

SR_TStableCriterion &SR_TStableCriterion::operator=(const S_TStableCriterion &instance)
{
    this->stage = instance.stage;
    this->dwellTime = instance.dwellTime;
    this->timeout = instance.timeout;
    return *this;
}

SR_TStableCriterion &SR_TStableCriterion::operator=(const SR_TStableCriterion &instance)
{
    TValueBase::operator=(instance);
    this->stage = instance.stage;
    this->dwellTime = instance.dwellTime;
    this->timeout = instance.timeout;
    return *this;
}

S_TCStage::S_TCStage()
{

}

S_TCStage::S_TCStage(const S_TCStage &instance)
{
    this->controlType = instance.controlType;
    this->ctrlCoef = instance.ctrlCoef;
    this->targetTempOffset = instance.targetTempOffset;
    this->errWindow = instance.errWindow;
    this->dwellTime = instance.dwellTime;
}

S_TCStage::S_TCStage(const SR_TCStage &instance)
{
    this->controlType = instance.controlType.value;

    this->ctrlCoef.clear();
    for(int i = 0; i < instance.ctrlCoef.count(); i++)
    {
        this->ctrlCoef.append(instance.ctrlCoef[i].value);
    }

    this->targetTempOffset = instance.targetTempOffset.value;

    this->errWindow.clear();
    for(int i = 0; i < instance.errWindow.count(); i++)
    {
        this->errWindow.append(instance.errWindow[i].value);
    }

    this->dwellTime = instance.dwellTime.value;
}

S_TCStage &S_TCStage::operator=(const S_TCStage &instance)
{
    this->controlType = instance.controlType;
    this->ctrlCoef = instance.ctrlCoef;
    this->targetTempOffset = instance.targetTempOffset;
    this->errWindow = instance.errWindow;
    this->dwellTime = instance.dwellTime;
    return *this;
}

S_TCStage &S_TCStage::operator=(const SR_TCStage &instance)
{
    this->controlType = instance.controlType.value;

    this->ctrlCoef.clear();
    for(int i = 0; i < instance.ctrlCoef.count(); i++)
    {
        this->ctrlCoef.append(instance.ctrlCoef[i].value);
    }

    this->targetTempOffset = instance.targetTempOffset.value;

    this->errWindow.clear();
    for(int i = 0; i < instance.errWindow.count(); i++)
    {
        this->errWindow.append(instance.errWindow[i].value);
    }

    this->dwellTime = instance.dwellTime.value;
    return *this;
}


SR_TCStage::SR_TCStage() : TValueBase()
{

}

SR_TCStage::SR_TCStage(const S_TCStage &instance) : TValueBase()
{
    this->controlType = instance.controlType;

    this->ctrlCoef.clear();
    for(int i = 0; i < instance.ctrlCoef.count(); i++)
    {
        this->ctrlCoef.append(instance.ctrlCoef[i]);
    }

    this->targetTempOffset = instance.targetTempOffset;

    this->errWindow.clear();
    for(int i = 0; i < instance.errWindow.count(); i++)
    {
        this->errWindow.append(instance.errWindow[i]);
    }

    this->dwellTime = instance.dwellTime;
}

SR_TCStage::SR_TCStage(const SR_TCStage &instance) : TValueBase(instance)
{
    this->controlType = instance.controlType;
    this->ctrlCoef = instance.ctrlCoef;
    this->targetTempOffset = instance.targetTempOffset;
    this->errWindow = instance.errWindow;
    this->dwellTime = instance.dwellTime;
}

SR_TCStage &SR_TCStage::operator=(const S_TCStage &instance)
{
    this->controlType = instance.controlType;

    this->ctrlCoef.clear();
    for(int i = 0; i < instance.ctrlCoef.count(); i++)
    {
        this->ctrlCoef.append(instance.ctrlCoef[i]);
    }

    this->targetTempOffset = instance.targetTempOffset;

    this->errWindow.clear();
    for(int i = 0; i < instance.errWindow.count(); i++)
    {
        this->errWindow.append(instance.errWindow[i]);
    }

    this->dwellTime = instance.dwellTime;
    return *this;
}

SR_TCStage &SR_TCStage::operator=(const SR_TCStage &instance)
{
    TValueBase::operator=(instance);
    this->controlType = instance.controlType;
    this->ctrlCoef = instance.ctrlCoef;
    this->targetTempOffset = instance.targetTempOffset;
    this->errWindow = instance.errWindow;
    this->dwellTime = instance.dwellTime;
    return *this;
}

S_TempSensor::S_TempSensor()
{

}

S_TempSensor::S_TempSensor(const S_TempSensor &instance)
{
    this->sensorType = instance.sensorType;
    this->temp_WarningDelayTime = instance.temp_WarningDelayTime;
    this->warningLmt = instance.warningLmt;
    this->filterType = instance.filterType;
    this->samplingRate = instance.samplingRate;
    this->sensorCoef = instance.sensorCoef;
}

S_TempSensor::S_TempSensor(const SR_TempSensor &instance)
{
    this->sensorType = instance.sensorType.value;
    this->temp_WarningDelayTime = instance.temp_WarningDelayTime.value;

    this->warningLmt.clear();
    for(int i = 0; i < instance.warningLmt.count(); i++)
    {
        this->warningLmt.append(instance.warningLmt[i].value);
    }

    this->filterType = instance.filterType.value;
    this->samplingRate = instance.samplingRate.value;

    this->sensorCoef.clear();
    for(int i = 0; i < instance.sensorCoef.count(); i++)
    {
        this->sensorCoef.append(instance.sensorCoef[i].value);
    }
}

S_TempSensor &S_TempSensor::operator=(const S_TempSensor &instance)
{
    this->sensorType = instance.sensorType;
    this->temp_WarningDelayTime = instance.temp_WarningDelayTime;
    this->warningLmt = instance.warningLmt;
    this->filterType = instance.filterType;
    this->samplingRate = instance.samplingRate;
    this->sensorCoef = instance.sensorCoef;
    return *this;
}

S_TempSensor &S_TempSensor::operator=(const SR_TempSensor &instance)
{
    this->sensorType = instance.sensorType.value;
    this->temp_WarningDelayTime = instance.temp_WarningDelayTime.value;

    this->warningLmt.clear();
    for(int i = 0; i < instance.warningLmt.count(); i++)
    {
        this->warningLmt.append(instance.warningLmt[i].value);
    }

    this->filterType = instance.filterType.value;
    this->samplingRate = instance.samplingRate.value;

    this->sensorCoef.clear();
    for(int i = 0; i < instance.sensorCoef.count(); i++)
    {
        this->sensorCoef.append(instance.sensorCoef[i].value);
    }
    return *this;
}

SR_TempSensor::SR_TempSensor()
{

}

SR_TempSensor::SR_TempSensor(const S_TempSensor &instance)
{
    this->sensorType = instance.sensorType;
    this->temp_WarningDelayTime = instance.temp_WarningDelayTime;

    this->warningLmt.clear();
    for(int i = 0; i < instance.warningLmt.count(); i++)
    {
        this->warningLmt.append(instance.warningLmt[i]);
    }

    this->filterType = instance.filterType;
    this->samplingRate = instance.samplingRate;

    this->sensorCoef.clear();
    for(int i = 0; i < instance.sensorCoef.count(); i++)
    {
        this->sensorCoef.append(instance.sensorCoef[i]);
    }
}

SR_TempSensor::SR_TempSensor(const SR_TempSensor &instance)
{
    this->sensorType = instance.sensorType;
    this->temp_WarningDelayTime = instance.temp_WarningDelayTime;
    this->warningLmt = instance.warningLmt;
    this->filterType = instance.filterType;
    this->samplingRate = instance.samplingRate;
    this->sensorCoef = instance.sensorCoef;
}

SR_TempSensor &SR_TempSensor::operator=(const S_TempSensor &instance)
{
    this->sensorType = instance.sensorType;
    this->temp_WarningDelayTime = instance.temp_WarningDelayTime;

    this->warningLmt.clear();
    for(int i = 0; i < instance.warningLmt.count(); i++)
    {
        this->warningLmt.append(instance.warningLmt[i]);
    }

    this->filterType = instance.filterType;
    this->samplingRate = instance.samplingRate;

    this->sensorCoef.clear();
    for(int i = 0; i < instance.sensorCoef.count(); i++)
    {
        this->sensorCoef.append(instance.sensorCoef[i]);
    }
    return *this;
}

SR_TempSensor &SR_TempSensor::operator=(const SR_TempSensor &instance)
{
    this->sensorType = instance.sensorType;
    this->temp_WarningDelayTime = instance.temp_WarningDelayTime;
    this->warningLmt = instance.warningLmt;
    this->filterType = instance.filterType;
    this->samplingRate = instance.samplingRate;
    this->sensorCoef = instance.sensorCoef;
    return *this;
}

S_TempCtrl::S_TempCtrl()
{

}

S_TempCtrl::S_TempCtrl(const S_TempCtrl &instance)
{
    this->primaryTSensorID = instance.primaryTSensorID;
    this->tempSetpoint = instance.tempSetpoint;
    this->tStableCriterion = instance.tStableCriterion;
    this->TCStage = instance.TCStage;
    this->tempSensors = instance.tempSensors;
}

S_TempCtrl::S_TempCtrl(const SR_TempCtrl &instance)
{
    this->primaryTSensorID = instance.primaryTSensorID.value;
    this->tempSetpoint = instance.tempSetpoint.value;
    this->tStableCriterion = instance.tStableCriterion;
    this->TCStage = instance.TCStage;

    this->tempSensors.clear();
    for(int i = 0; i < instance.tempSensors.count(); i++)
    {
        this->tempSensors.append(instance.tempSensors[i]);
    }
}

S_TempCtrl &S_TempCtrl::operator=(const S_TempCtrl &instance)
{
    this->primaryTSensorID = instance.primaryTSensorID;
    this->tempSetpoint = instance.tempSetpoint;
    this->tStableCriterion = instance.tStableCriterion;
    this->TCStage = instance.TCStage;
    this->tempSensors = instance.tempSensors;
    return *this;
}

S_TempCtrl &S_TempCtrl::operator=(const SR_TempCtrl &instance)
{
    this->primaryTSensorID = instance.primaryTSensorID.value;
    this->tempSetpoint = instance.tempSetpoint.value;
    this->tStableCriterion = instance.tStableCriterion;
    this->TCStage = instance.TCStage;

    this->tempSensors.clear();
    for(int i = 0; i < instance.tempSensors.count(); i++)
    {
        this->tempSensors.append(instance.tempSensors[i]);
    }
    return *this;
}

SR_TempCtrl::SR_TempCtrl() : TValueBase()
{

}

SR_TempCtrl::SR_TempCtrl(const S_TempCtrl &instance) : TValueBase()
{
    this->primaryTSensorID = instance.primaryTSensorID;
    this->tempSetpoint = instance.tempSetpoint;
    this->tStableCriterion = instance.tStableCriterion;
    this->TCStage = instance.TCStage;

    this->tempSensors.clear();
    for(int i = 0; i < instance.tempSensors.count(); i++)
    {
        this->tempSensors.append(instance.tempSensors[i]);
    }
}

SR_TempCtrl::SR_TempCtrl(const SR_TempCtrl &instance) : TValueBase(instance)
{
    this->primaryTSensorID = instance.primaryTSensorID;
    this->tempSetpoint = instance.tempSetpoint;
    this->tStableCriterion = instance.tStableCriterion;
    this->TCStage = instance.TCStage;
    this->tempSensors = instance.tempSensors;
}

SR_TempCtrl &SR_TempCtrl::operator=(const S_TempCtrl &instance)
{
    this->primaryTSensorID = instance.primaryTSensorID;
    this->tempSetpoint = instance.tempSetpoint;
    this->tStableCriterion = instance.tStableCriterion;
    this->TCStage = instance.TCStage;

    this->tempSensors.clear();
    for(int i = 0; i < instance.tempSensors.count(); i++)
    {
        this->tempSensors.append(instance.tempSensors[i]);
    }
    return *this;
}

SR_TempCtrl &SR_TempCtrl::operator=(const SR_TempCtrl &instance)
{
    this->primaryTSensorID = instance.primaryTSensorID;
    this->tempSetpoint = instance.tempSetpoint;
    this->tStableCriterion = instance.tStableCriterion;
    this->TCStage = instance.TCStage;
    this->tempSensors = instance.tempSensors;
    return *this;
}

S_TCWUnit::S_TCWUnit()
{

}

S_TCWUnit::S_TCWUnit(const S_TCWUnit &instance)
{
    this->tempWngLmt = instance.tempWngLmt;
    this->TCWReplacePeroid = instance.TCWReplacePeroid;
    this->filterReplacePeroid = instance.filterReplacePeroid;
}

S_TCWUnit::S_TCWUnit(const SR_TCWUnit &instance)
{
    this->tempWngLmt.clear();
    for(int i = 0; i < instance.tempWngLmt.count(); i++)
    {
        this->tempWngLmt.append(instance.tempWngLmt[i]);
    }
    this->TCWReplacePeroid = instance.TCWReplacePeroid.value;
    this->filterReplacePeroid = instance.filterReplacePeroid.value;
}

S_TCWUnit &S_TCWUnit::operator=(const S_TCWUnit &instance)
{
    this->tempWngLmt = instance.tempWngLmt;
    this->TCWReplacePeroid = instance.TCWReplacePeroid;
    this->filterReplacePeroid = instance.filterReplacePeroid;
    return *this;
}

S_TCWUnit &S_TCWUnit::operator=(const SR_TCWUnit &instance)
{
    this->tempWngLmt.clear();
    for(int i = 0; i < instance.tempWngLmt.count(); i++)
    {
        this->tempWngLmt.append(instance.tempWngLmt[i]);
    }
    this->TCWReplacePeroid = instance.TCWReplacePeroid.value;
    this->filterReplacePeroid = instance.filterReplacePeroid.value;
    return *this;
}

SR_TCWUnit::SR_TCWUnit()
{

}

SR_TCWUnit::SR_TCWUnit(const S_TCWUnit &instance)
{
    this->tempWngLmt.clear();
    for(int i = 0; i < instance.tempWngLmt.count(); i++)
    {
        this->tempWngLmt.append(instance.tempWngLmt[i]);
    }
    this->TCWReplacePeroid = instance.TCWReplacePeroid;
    this->filterReplacePeroid = instance.filterReplacePeroid;
}

SR_TCWUnit::SR_TCWUnit(const SR_TCWUnit &instance)
{
    this->tempWngLmt = instance.tempWngLmt;
    this->TCWReplacePeroid = instance.TCWReplacePeroid;
    this->filterReplacePeroid = instance.filterReplacePeroid;
}

SR_TCWUnit &SR_TCWUnit::operator=(const S_TCWUnit &instance)
{
    this->tempWngLmt.clear();
    for(int i = 0; i < instance.tempWngLmt.count(); i++)
    {
        this->tempWngLmt.append(instance.tempWngLmt[i]);
    }
    this->TCWReplacePeroid = instance.TCWReplacePeroid;
    this->filterReplacePeroid = instance.filterReplacePeroid;
    return *this;
}

SR_TCWUnit &SR_TCWUnit::operator=(const SR_TCWUnit &instance)
{
    this->tempWngLmt = instance.tempWngLmt;
    this->TCWReplacePeroid = instance.TCWReplacePeroid;
    this->filterReplacePeroid = instance.filterReplacePeroid;
    return *this;
}

S_FanUnit::S_FanUnit()
{

}

S_FanUnit::S_FanUnit(const S_FanUnit &instance)
{
    this->fan_WarningDelayTime = instance.fan_WarningDelayTime;
    this->fan_WarningMax = instance.fan_WarningMax;
    this->fan_WarningMin = instance.fan_WarningMin;
    this->fan_FilterType = instance.fan_FilterType;
    this->fan_StatsType = instance.fan_StatsType;
    this->fan_Freq = instance.fan_Freq;
}

S_FanUnit::S_FanUnit(const SR_FanUnit &instance)
{
    this->fan_WarningDelayTime = instance.fan_WarningDelayTime.value;
    this->fan_WarningMax = instance.fan_WarningMax.value;
    this->fan_WarningMin = instance.fan_WarningMin.value;
    this->fan_FilterType = instance.fan_FilterType.value;
    this->fan_StatsType = instance.fan_StatsType.value;
    this->fan_Freq = instance.fan_Freq.value;
}

S_FanUnit &S_FanUnit::operator=(const S_FanUnit &instance)
{
    this->fan_WarningDelayTime = instance.fan_WarningDelayTime;
    this->fan_WarningMax = instance.fan_WarningMax;
    this->fan_WarningMin = instance.fan_WarningMin;
    this->fan_FilterType = instance.fan_FilterType;
    this->fan_StatsType = instance.fan_StatsType;
    this->fan_Freq = instance.fan_Freq;
    return *this;
}

S_FanUnit &S_FanUnit::operator=(const SR_FanUnit &instance)
{
    this->fan_WarningDelayTime = instance.fan_WarningDelayTime.value;
    this->fan_WarningMax = instance.fan_WarningMax.value;
    this->fan_WarningMin = instance.fan_WarningMin.value;
    this->fan_FilterType = instance.fan_FilterType.value;
    this->fan_StatsType = instance.fan_StatsType.value;
    this->fan_Freq = instance.fan_Freq.value;
    return *this;
}

SR_FanUnit::SR_FanUnit() : TValueBase()
{

}

SR_FanUnit::SR_FanUnit(const S_FanUnit &instance) : TValueBase()
{
    this->fan_WarningDelayTime = instance.fan_WarningDelayTime;
    this->fan_WarningMax = instance.fan_WarningMax;
    this->fan_WarningMin = instance.fan_WarningMin;
    this->fan_FilterType = instance.fan_FilterType;
    this->fan_StatsType = instance.fan_StatsType;
    this->fan_Freq = instance.fan_Freq;
}

SR_FanUnit::SR_FanUnit(const SR_FanUnit &instance) : TValueBase(instance)
{
    this->fan_WarningDelayTime = instance.fan_WarningDelayTime;
    this->fan_WarningMax = instance.fan_WarningMax;
    this->fan_WarningMin = instance.fan_WarningMin;
    this->fan_FilterType = instance.fan_FilterType;
    this->fan_StatsType = instance.fan_StatsType;
    this->fan_Freq = instance.fan_Freq;
}

SR_FanUnit &SR_FanUnit::operator=(const S_FanUnit &instance)
{
    this->fan_WarningDelayTime = instance.fan_WarningDelayTime;
    this->fan_WarningMax = instance.fan_WarningMax;
    this->fan_WarningMin = instance.fan_WarningMin;
    this->fan_FilterType = instance.fan_FilterType;
    this->fan_StatsType = instance.fan_StatsType;
    this->fan_Freq = instance.fan_Freq;
    return *this;
}

SR_FanUnit &SR_FanUnit::operator=(const SR_FanUnit &instance)
{
    TValueBase::operator=(instance);
    this->fan_WarningDelayTime = instance.fan_WarningDelayTime;
    this->fan_WarningMax = instance.fan_WarningMax;
    this->fan_WarningMin = instance.fan_WarningMin;
    this->fan_FilterType = instance.fan_FilterType;
    this->fan_StatsType = instance.fan_StatsType;
    this->fan_Freq = instance.fan_Freq;
    return *this;
}

S_FlowRateSensor::S_FlowRateSensor()
{

}

S_FlowRateSensor::S_FlowRateSensor(const S_FlowRateSensor &instance)
{
    this->flow_WarningDelayTime = instance.flow_WarningDelayTime;
    this->warningLmt = instance.warningLmt;
    this->filterType = instance.filterType;
    this->samplingRate = instance.samplingRate;
}

S_FlowRateSensor::S_FlowRateSensor(const SR_FlowRateSensor &instance)
{
    this->flow_WarningDelayTime = instance.flow_WarningDelayTime.value;

    this->warningLmt.clear();
    for(int i = 0; i < instance.warningLmt.count(); i++)
    {
        this->warningLmt.append(instance.warningLmt[i].value);
    }

    this->filterType = instance.filterType.value;
    this->samplingRate = instance.samplingRate.value;
}

S_FlowRateSensor &S_FlowRateSensor::operator=(const S_FlowRateSensor &instance)
{
    this->flow_WarningDelayTime = instance.flow_WarningDelayTime;
    this->warningLmt = instance.warningLmt;
    this->filterType = instance.filterType;
    this->samplingRate = instance.samplingRate;
    return *this;
}

S_FlowRateSensor &S_FlowRateSensor::operator=(const SR_FlowRateSensor &instance)
{
    this->flow_WarningDelayTime = instance.flow_WarningDelayTime.value;

    this->warningLmt.clear();
    for(int i = 0; i < instance.warningLmt.count(); i++)
    {
        this->warningLmt.append(instance.warningLmt[i].value);
    }

    this->filterType = instance.filterType.value;
    this->samplingRate = instance.samplingRate.value;
    return *this;
}

SR_FlowRateSensor::SR_FlowRateSensor() : TValueBase()
{

}

SR_FlowRateSensor::SR_FlowRateSensor(const S_FlowRateSensor &instance) : TValueBase()
{
    this->flow_WarningDelayTime = instance.flow_WarningDelayTime;

    this->warningLmt.clear();
    for(int i = 0; i < instance.warningLmt.count(); i++)
    {
        this->warningLmt.append(instance.warningLmt[i]);
    }

    this->filterType = instance.filterType;
    this->samplingRate = instance.samplingRate;
}

SR_FlowRateSensor::SR_FlowRateSensor(const SR_FlowRateSensor &instance) : TValueBase(instance)
{
    this->flow_WarningDelayTime = instance.flow_WarningDelayTime;
    this->warningLmt = instance.warningLmt;
    this->filterType = instance.filterType;
    this->samplingRate = instance.samplingRate;
}

SR_FlowRateSensor &SR_FlowRateSensor::operator=(const S_FlowRateSensor &instance)
{
    this->flow_WarningDelayTime = instance.flow_WarningDelayTime;

    this->warningLmt.clear();
    for(int i = 0; i < instance.warningLmt.count(); i++)
    {
        this->warningLmt.append(instance.warningLmt[i]);
    }

    this->filterType = instance.filterType;
    this->samplingRate = instance.samplingRate;
    return *this;
}

SR_FlowRateSensor &SR_FlowRateSensor::operator=(const SR_FlowRateSensor &instance)
{
    this->flow_WarningDelayTime = instance.flow_WarningDelayTime;
    this->warningLmt = instance.warningLmt;
    this->filterType = instance.filterType;
    this->samplingRate = instance.samplingRate;
    return *this;
}

S_Maintenance::S_Maintenance()
{

}

S_Maintenance::S_Maintenance(const S_Maintenance &instance)
{
    this->stableSignalSampleRate = instance.stableSignalSampleRate;
}

S_Maintenance::S_Maintenance(const SR_Maintenance &instance)
{
    this->stableSignalSampleRate = instance.stableSignalSampleRate.value;
}

S_Maintenance &S_Maintenance::operator=(const S_Maintenance &instance)
{
    this->stableSignalSampleRate = instance.stableSignalSampleRate;
    return *this;
}

S_Maintenance &S_Maintenance::operator=(const SR_Maintenance &instance)
{
    this->stableSignalSampleRate = instance.stableSignalSampleRate.value;
    return *this;
}

SR_Maintenance::SR_Maintenance() : TValueBase()
{

}

SR_Maintenance::SR_Maintenance(const S_Maintenance &instance) : TValueBase()
{
    this->stableSignalSampleRate = instance.stableSignalSampleRate;
}

SR_Maintenance::SR_Maintenance(const SR_Maintenance &instance) : TValueBase(instance)
{
    this->stableSignalSampleRate = instance.stableSignalSampleRate.value;
}

SR_Maintenance &SR_Maintenance::operator=(const S_Maintenance &instance)
{
    this->stableSignalSampleRate = instance.stableSignalSampleRate;
    return *this;
}

SR_Maintenance &SR_Maintenance::operator=(const SR_Maintenance &instance)
{
    TValueBase::operator=(instance);
    this->stableSignalSampleRate = instance.stableSignalSampleRate.value;
    return *this;
}
