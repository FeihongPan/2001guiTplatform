#include "timesetting.h"

S_TimeSetting::S_TimeSetting()
{
    this->axisEnableTimeout = 10;
    this->axisMoveTimeOut = 120;
    this->axisMoveStableTime = 0.5;
    this->flsTimeout = 3;
    this->lightTimeout = 3;
    this->visionTimeout = 10;
    this->ioStableTime = 0.5;
    this->suckerCheckTime = 2;
}

S_TimeSetting::S_TimeSetting(const S_TimeSetting &time)
{
    this->axisEnableTimeout = time.axisEnableTimeout;
    this->axisMoveTimeOut = time.axisMoveTimeOut;
    this->axisMoveStableTime = time.axisMoveStableTime;
    this->flsTimeout = time.flsTimeout;
    this->lightTimeout = time.lightTimeout;
    this->visionTimeout = time.visionTimeout;
    this->ioStableTime = time.ioStableTime;
    this->suckerCheckTime = time.suckerCheckTime;
}

S_TimeSetting::S_TimeSetting(const SR_TimeSetting &time)
{
    this->axisEnableTimeout = time.axisEnableTimeout.value;
    this->axisMoveTimeOut = time.axisMoveTimeOut.value;
    this->axisMoveStableTime = time.axisMoveStableTime.value;
    this->flsTimeout = time.flsTimeout.value;
    this->lightTimeout = time.lightTimeout.value;
    this->visionTimeout = time.visionTimeout.value;
    this->ioStableTime = time.ioStableTime.value;
    this->suckerCheckTime = time.suckerCheckTime.value;
}

S_TimeSetting &S_TimeSetting::operator=(const S_TimeSetting &time)
{
    this->axisEnableTimeout = time.axisEnableTimeout;
    this->axisMoveTimeOut = time.axisMoveTimeOut;
    this->axisMoveStableTime = time.axisMoveStableTime;
    this->flsTimeout = time.flsTimeout;
    this->lightTimeout = time.lightTimeout;
    this->visionTimeout = time.visionTimeout;
    this->ioStableTime = time.ioStableTime;
    this->suckerCheckTime = time.suckerCheckTime;
    return *this;
}

S_TimeSetting &S_TimeSetting::operator=(const SR_TimeSetting &time)
{
    this->axisEnableTimeout = time.axisEnableTimeout.value;
    this->axisMoveTimeOut = time.axisMoveTimeOut.value;
    this->axisMoveStableTime = time.axisMoveStableTime.value;
    this->flsTimeout = time.flsTimeout.value;
    this->lightTimeout = time.lightTimeout.value;
    this->visionTimeout = time.visionTimeout.value;
    this->ioStableTime = time.ioStableTime.value;
    this->suckerCheckTime = time.suckerCheckTime.value;
    return *this;
}

SR_TimeSetting::SR_TimeSetting()
{
    this->axisEnableTimeout.valueName = toStr(axisEnableTimeout);
    this->axisMoveTimeOut.valueName = toStr(axisMoveTimeOut);
    this->axisMoveStableTime.valueName = toStr(axisMoveStableTime);
    this->flsTimeout.valueName = toStr(flsTimeout);
    this->lightTimeout.valueName = toStr(lightTimeout);
    this->visionTimeout.valueName = toStr(visionTimeout);
    this->ioStableTime.valueName = toStr(ioStableTime);
    this->suckerCheckTime.valueName = toStr(suckerCheckTime);
}

SR_TimeSetting::SR_TimeSetting(const SR_TimeSetting &time)
{
    this->axisEnableTimeout = time.axisEnableTimeout;
    this->axisMoveTimeOut = time.axisMoveTimeOut;
    this->axisMoveStableTime = time.axisMoveStableTime;
    this->flsTimeout = time.flsTimeout;
    this->lightTimeout = time.lightTimeout;
    this->visionTimeout = time.visionTimeout;
    this->ioStableTime = time.ioStableTime;
    this->suckerCheckTime = time.suckerCheckTime;
}

SR_TimeSetting::SR_TimeSetting(const S_TimeSetting &time)
{
    this->axisEnableTimeout = time.axisEnableTimeout;
    this->axisMoveTimeOut = time.axisMoveTimeOut;
    this->axisMoveStableTime = time.axisMoveStableTime;
    this->flsTimeout = time.flsTimeout;
    this->lightTimeout = time.lightTimeout;
    this->visionTimeout = time.visionTimeout;
    this->ioStableTime = time.ioStableTime;
    this->suckerCheckTime = time.suckerCheckTime;
}

SR_TimeSetting &SR_TimeSetting::operator=(const SR_TimeSetting &time)
{
    this->axisEnableTimeout = time.axisEnableTimeout;
    this->axisMoveTimeOut = time.axisMoveTimeOut;
    this->axisMoveStableTime = time.axisMoveStableTime;
    this->flsTimeout = time.flsTimeout;
    this->lightTimeout = time.lightTimeout;
    this->visionTimeout = time.visionTimeout;
    this->ioStableTime = time.ioStableTime;
    this->suckerCheckTime = time.suckerCheckTime;
    return *this;
}

SR_TimeSetting &SR_TimeSetting::operator=(const S_TimeSetting &time)
{
    this->axisEnableTimeout = time.axisEnableTimeout;
    this->axisMoveTimeOut = time.axisMoveTimeOut;
    this->axisMoveStableTime = time.axisMoveStableTime;
    this->flsTimeout = time.flsTimeout;
    this->lightTimeout = time.lightTimeout;
    this->visionTimeout = time.visionTimeout;
    this->ioStableTime = time.ioStableTime;
    this->suckerCheckTime = time.suckerCheckTime;
    return *this;
}
