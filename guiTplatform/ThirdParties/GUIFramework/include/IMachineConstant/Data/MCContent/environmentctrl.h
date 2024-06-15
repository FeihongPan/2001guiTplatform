#ifndef ENVIRONMENTCTRL_H
#define ENVIRONMENTCTRL_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "BasicValue/serializablelist.h"
#include "IMachineConstant/Data/STDConstant/std_constant_air.h"
#include "Serializer/QSerializer"

class SR_TStableCriterion;

class S_TStableCriterion: public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(int, stage)
    QS_FIELD(int, dwellTime)
    QS_FIELD(int, timeout)

public:
    S_TStableCriterion();
    S_TStableCriterion(const S_TStableCriterion &instance);
    S_TStableCriterion(const SR_TStableCriterion &instance);
    S_TStableCriterion &operator=(const S_TStableCriterion &instance);
    S_TStableCriterion &operator=(const SR_TStableCriterion &instance);
};

class SR_TStableCriterion: public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TInt, stage)
    QS_OBJECT(TInt, dwellTime)
    QS_OBJECT(TInt, timeout)

public:
    SR_TStableCriterion();
    SR_TStableCriterion(const S_TStableCriterion &instance);
    SR_TStableCriterion(const SR_TStableCriterion &instance);
    SR_TStableCriterion &operator=(const S_TStableCriterion &instance);
    SR_TStableCriterion &operator=(const SR_TStableCriterion &instance);
};

class SR_TCStage;

class S_TCStage : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(int, controlType)
    QS_COLLECTION(QList, double, ctrlCoef)
    QS_FIELD(double, targetTempOffset)
    QS_COLLECTION(QList, double, errWindow)
    QS_FIELD(int, dwellTime)

public:
    S_TCStage();
    S_TCStage(const S_TCStage &instance);
    S_TCStage(const SR_TCStage &instance);
    S_TCStage &operator=(const S_TCStage &instance);
    S_TCStage &operator=(const SR_TCStage &instance);
};

class SR_TCStage : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TInt, controlType)
    QS_COLLECTION_OBJECTS(QList, TDouble, ctrlCoef)
    QS_OBJECT(TDouble, targetTempOffset)
    QS_COLLECTION_OBJECTS(QList, TDouble, errWindow)
    QS_OBJECT(TInt, dwellTime)

public:
    SR_TCStage();
    SR_TCStage(const S_TCStage &instance);
    SR_TCStage(const SR_TCStage &instance);
    SR_TCStage &operator=(const S_TCStage &instance);
    SR_TCStage &operator=(const SR_TCStage &instance);
};


class SR_TempSensor;

class S_TempSensor : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(int, sensorType)
    QS_FIELD(int, temp_WarningDelayTime)
    QS_COLLECTION(QList, double, warningLmt)
    QS_FIELD(int, filterType)
    QS_FIELD(double, samplingRate)
    QS_COLLECTION(QList, double, sensorCoef)

public:
    S_TempSensor();
    S_TempSensor(const S_TempSensor &instance);
    S_TempSensor(const SR_TempSensor &instance);
    S_TempSensor &operator=(const S_TempSensor &instance);
    S_TempSensor &operator=(const SR_TempSensor &instance);
};

class SR_TempSensor : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TInt, sensorType)
    QS_OBJECT(TInt, temp_WarningDelayTime)
    QS_COLLECTION_OBJECTS(QList, TDouble, warningLmt)
    QS_OBJECT(TInt, filterType)
    QS_OBJECT(TDouble, samplingRate)
    QS_COLLECTION_OBJECTS(QList, TDouble, sensorCoef)

public:
    SR_TempSensor();
    SR_TempSensor(const S_TempSensor &instance);
    SR_TempSensor(const SR_TempSensor &instance);
    SR_TempSensor &operator=(const S_TempSensor &instance);
    SR_TempSensor &operator=(const SR_TempSensor &instance);
};


class SR_TempCtrl;

class S_TempCtrl : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(QString, primaryTSensorID)
    QS_FIELD(double, tempSetpoint)
    QS_OBJECT(S_TStableCriterion, tStableCriterion)
    QS_OBJECT(S_TCStage, TCStage)
    QS_COLLECTION_OBJECTS(QList, S_TempSensor, tempSensors)

public:
    S_TempCtrl();
    S_TempCtrl(const S_TempCtrl &instance);
    S_TempCtrl(const SR_TempCtrl &instance);
    S_TempCtrl &operator=(const S_TempCtrl &instance);
    S_TempCtrl &operator=(const SR_TempCtrl &instance);
};

class SR_TempCtrl : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TString, primaryTSensorID)
    QS_OBJECT(TDouble, tempSetpoint)
    QS_OBJECT(SR_TStableCriterion, tStableCriterion)
    QS_OBJECT(SR_TCStage, TCStage)
    QS_COLLECTION_OBJECTS(QList, SR_TempSensor, tempSensors)

public:
    SR_TempCtrl();
    SR_TempCtrl(const S_TempCtrl &instance);
    SR_TempCtrl(const SR_TempCtrl &instance);
    SR_TempCtrl &operator=(const S_TempCtrl &instance);
    SR_TempCtrl &operator=(const SR_TempCtrl &instance);
};


class SR_TCWUnit;

class S_TCWUnit : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, S_List_Double, tempWngLmt)
    QS_FIELD(double, TCWReplacePeroid)
    QS_FIELD(double, filterReplacePeroid)

public:
    S_TCWUnit();
    S_TCWUnit(const S_TCWUnit &instance);
    S_TCWUnit(const SR_TCWUnit &instance);
    S_TCWUnit &operator=(const S_TCWUnit &instance);
    S_TCWUnit &operator=(const SR_TCWUnit &instance);
};

class SR_TCWUnit : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, SR_List_Double, tempWngLmt)
    QS_OBJECT(TDouble, TCWReplacePeroid)
    QS_OBJECT(TDouble, filterReplacePeroid)

public:
    SR_TCWUnit();
    SR_TCWUnit(const S_TCWUnit &instance);
    SR_TCWUnit(const SR_TCWUnit &instance);
    SR_TCWUnit &operator=(const S_TCWUnit &instance);
    SR_TCWUnit &operator=(const SR_TCWUnit &instance);
};


class SR_FanUnit;

class S_FanUnit : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, fan_WarningDelayTime)
    QS_FIELD(double, fan_WarningMax)
    QS_FIELD(double, fan_WarningMin)
    QS_FIELD(double, fan_FilterType)
    QS_FIELD(double, fan_StatsType)
    QS_FIELD(double, fan_Freq)

public:
    S_FanUnit();
    S_FanUnit(const S_FanUnit &instance);
    S_FanUnit(const SR_FanUnit &instance);
    S_FanUnit &operator=(const S_FanUnit &instance);
    S_FanUnit &operator=(const SR_FanUnit &instance);
};

class SR_FanUnit : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TDouble, fan_WarningDelayTime)
    QS_OBJECT(TDouble, fan_WarningMax)
    QS_OBJECT(TDouble, fan_WarningMin)
    QS_OBJECT(TDouble, fan_FilterType)
    QS_OBJECT(TDouble, fan_StatsType)
    QS_OBJECT(TDouble, fan_Freq)

public:
    SR_FanUnit();
    SR_FanUnit(const S_FanUnit &instance);
    SR_FanUnit(const SR_FanUnit &instance);
    SR_FanUnit &operator=(const S_FanUnit &instance);
    SR_FanUnit &operator=(const SR_FanUnit &instance);
};


class SR_FlowRateSensor;

class S_FlowRateSensor : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, flow_WarningDelayTime)
    QS_COLLECTION(QList, double, warningLmt)
    QS_FIELD(int, filterType)
    QS_FIELD(double, samplingRate)

public:
    S_FlowRateSensor();
    S_FlowRateSensor(const S_FlowRateSensor &instance);
    S_FlowRateSensor(const SR_FlowRateSensor &instance);
    S_FlowRateSensor &operator=(const S_FlowRateSensor &instance);
    S_FlowRateSensor &operator=(const SR_FlowRateSensor &instance);
};

class SR_FlowRateSensor : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TDouble, flow_WarningDelayTime)
    QS_COLLECTION_OBJECTS(QList, TDouble, warningLmt)
    QS_OBJECT(TInt, filterType)
    QS_OBJECT(TDouble, samplingRate)

public:
    SR_FlowRateSensor();
    SR_FlowRateSensor(const S_FlowRateSensor &instance);
    SR_FlowRateSensor(const SR_FlowRateSensor &instance);
    SR_FlowRateSensor &operator=(const S_FlowRateSensor &instance);
    SR_FlowRateSensor &operator=(const SR_FlowRateSensor &instance);
};


class SR_Maintenance;

class S_Maintenance : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, stableSignalSampleRate)

public:
    S_Maintenance();
    S_Maintenance(const S_Maintenance &instance);
    S_Maintenance(const SR_Maintenance &instance);
    S_Maintenance &operator=(const S_Maintenance &instance);
    S_Maintenance &operator=(const SR_Maintenance &instance);
};

class SR_Maintenance : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TDouble, stableSignalSampleRate)

public:
    SR_Maintenance();
    SR_Maintenance(const S_Maintenance &instance);
    SR_Maintenance(const SR_Maintenance &instance);
    SR_Maintenance &operator=(const S_Maintenance &instance);
    SR_Maintenance &operator=(const SR_Maintenance &instance);
};


class SR_EnvironmentCtrl;

class S_EnvironmentCtrl : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_TempCtrl, tempCtrl)
    QS_OBJECT(S_TCWUnit, TCWUnit)
    QS_OBJECT(S_FanUnit, FanUnit)
    QS_COLLECTION_OBJECTS(QList, S_FlowRateSensor, flowRateSensor)
    QS_OBJECT(S_STD_Constant_Air, facilities)
    QS_OBJECT(S_Maintenance, maintenance)

public:
    S_EnvironmentCtrl();
    S_EnvironmentCtrl(const S_EnvironmentCtrl &instance);
    S_EnvironmentCtrl(const SR_EnvironmentCtrl &instance);
    S_EnvironmentCtrl &operator=(const S_EnvironmentCtrl &instance);
    S_EnvironmentCtrl &operator=(const SR_EnvironmentCtrl &instance);
};

class SR_EnvironmentCtrl : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_TempCtrl, tempCtrl)
    QS_OBJECT(SR_TCWUnit, TCWUnit)
    QS_OBJECT(SR_FanUnit, FanUnit)
    QS_COLLECTION_OBJECTS(QList, SR_FlowRateSensor, flowRateSensor)
    QS_OBJECT(SR_STD_Constant_Air, facilities)
    QS_OBJECT(SR_Maintenance, maintenance)

public:
    SR_EnvironmentCtrl();
    SR_EnvironmentCtrl(const S_EnvironmentCtrl &instance);
    SR_EnvironmentCtrl(const SR_EnvironmentCtrl &instance);
    SR_EnvironmentCtrl &operator=(const S_EnvironmentCtrl &instance);
    SR_EnvironmentCtrl &operator=(const SR_EnvironmentCtrl &instance);
};

#endif // ENVIRONMENTCTRL_H
