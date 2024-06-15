#include "std_constant_fls.h"

S_STD_Constant_FLS::S_STD_Constant_FLS()
{

}

S_STD_Constant_FLS::S_STD_Constant_FLS(const S_STD_Constant_FLS &instance)
{
    this->samplingRate = instance.samplingRate;
    this->ecpoTime = instance.ecpoTime;
    this->filterType = instance.filterType;
    this->gain = instance.gain;
    this->scaling = instance.scaling;
    this->optAxisPos = instance.optAxisPos;
    this->zeroOffset = instance.zeroOffset;
}

S_STD_Constant_FLS::S_STD_Constant_FLS(const SR_STD_Constant_FLS &instance)
{
    this->samplingRate = instance.samplingRate.value;
    this->ecpoTime = instance.ecpoTime.value;
    this->filterType = instance.filterType.value;
    this->gain = instance.gain.value;
    this->scaling = instance.scaling.value;
    this->optAxisPos.clear();
    for(int i = 0; i < instance.optAxisPos.count(); i++)
    {
        this->optAxisPos.append(instance.optAxisPos[i].value);
    }
    this->zeroOffset = instance.zeroOffset.value;
}

S_STD_Constant_FLS &S_STD_Constant_FLS::operator=(const S_STD_Constant_FLS &instance)
{
    this->samplingRate = instance.samplingRate;
    this->ecpoTime = instance.ecpoTime;
    this->filterType = instance.filterType;
    this->gain = instance.gain;
    this->scaling = instance.scaling;
    this->optAxisPos = instance.optAxisPos;
    this->zeroOffset = instance.zeroOffset;
    return *this;
}

S_STD_Constant_FLS &S_STD_Constant_FLS::operator=(const SR_STD_Constant_FLS &instance)
{
    this->samplingRate = instance.samplingRate.value;
    this->ecpoTime = instance.ecpoTime.value;
    this->filterType = instance.filterType.value;
    this->gain = instance.gain.value;
    this->scaling = instance.scaling.value;
    this->optAxisPos.clear();
    for(int i = 0; i < instance.optAxisPos.count(); i++)
    {
        this->optAxisPos.append(instance.optAxisPos[i].value);
    }
    this->zeroOffset = instance.zeroOffset.value;
    return *this;
}


SR_STD_Constant_FLS::SR_STD_Constant_FLS()
{

}

SR_STD_Constant_FLS::SR_STD_Constant_FLS(const S_STD_Constant_FLS &instance)
{
    this->samplingRate = instance.samplingRate;
    this->ecpoTime = instance.ecpoTime;
    this->filterType = instance.filterType;
    this->gain = instance.gain;
    this->scaling = instance.scaling;
    this->optAxisPos.clear();
    for(int i = 0; i < instance.optAxisPos.count(); i++)
    {
        this->optAxisPos.append(instance.optAxisPos[i]);
    }
    this->zeroOffset = instance.zeroOffset;
}

SR_STD_Constant_FLS::SR_STD_Constant_FLS(const SR_STD_Constant_FLS &instance)
{
    this->samplingRate = instance.samplingRate;
    this->ecpoTime = instance.ecpoTime;
    this->filterType = instance.filterType;
    this->gain = instance.gain;
    this->scaling = instance.scaling;
    this->optAxisPos = instance.optAxisPos;
    this->zeroOffset = instance.zeroOffset;
}

SR_STD_Constant_FLS &SR_STD_Constant_FLS::operator=(const S_STD_Constant_FLS &instance)
{
    this->samplingRate = instance.samplingRate;
    this->ecpoTime = instance.ecpoTime;
    this->filterType = instance.filterType;
    this->gain = instance.gain;
    this->scaling = instance.scaling;
    this->optAxisPos.clear();
    for(int i = 0; i < instance.optAxisPos.count(); i++)
    {
        this->optAxisPos.append(instance.optAxisPos[i]);
    }
    this->zeroOffset = instance.zeroOffset;
    return *this;
}

SR_STD_Constant_FLS &SR_STD_Constant_FLS::operator=(const SR_STD_Constant_FLS &instance)
{
    this->samplingRate = instance.samplingRate;
    this->ecpoTime = instance.ecpoTime;
    this->filterType = instance.filterType;
    this->gain = instance.gain;
    this->scaling = instance.scaling;
    this->optAxisPos = instance.optAxisPos;
    this->zeroOffset = instance.zeroOffset;
    return *this;
}
