#ifndef TIMESETTING_H
#define TIMESETTING_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

class SR_TimeSetting;

class GUIFRAMEWORK_EXPORT S_TimeSetting : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, axisEnableTimeout);
    QS_FIELD(double, axisMoveTimeOut);
    QS_FIELD(double, axisMoveStableTime);
    QS_FIELD(double, flsTimeout);
    QS_FIELD(double, lightTimeout);
    QS_FIELD(double, visionTimeout);
    QS_FIELD(double, ioStableTime);
    QS_FIELD(double, suckerCheckTime);
    QS_FIELD(double, cylinderTimeout);
    QS_FIELD(double, cylinderStableTime);

public:
    S_TimeSetting();
    S_TimeSetting(const S_TimeSetting &time);
    S_TimeSetting(const SR_TimeSetting &time);
    S_TimeSetting &operator=(const S_TimeSetting &time);
    S_TimeSetting &operator=(const SR_TimeSetting &time);
};

class GUIFRAMEWORK_EXPORT SR_TimeSetting : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TDouble, axisEnableTimeout);
    QS_OBJECT(TDouble, axisMoveTimeOut);
    QS_OBJECT(TDouble, axisMoveStableTime);
    QS_OBJECT(TDouble, flsTimeout);
    QS_OBJECT(TDouble, lightTimeout);
    QS_OBJECT(TDouble, visionTimeout);
    QS_OBJECT(TDouble, ioStableTime);
    QS_OBJECT(TDouble, suckerCheckTime);

public:
    SR_TimeSetting();
    SR_TimeSetting(const SR_TimeSetting &time);
    SR_TimeSetting(const S_TimeSetting &time);
    SR_TimeSetting &operator=(const SR_TimeSetting &time);
    SR_TimeSetting &operator=(const S_TimeSetting &time);
};

#endif // TIMESETTING_H
