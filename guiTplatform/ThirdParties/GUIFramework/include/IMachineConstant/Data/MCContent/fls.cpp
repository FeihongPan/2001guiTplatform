#include "fls.h"

S_FLSParameter::S_FLSParameter()
{

}

S_FLSParameter::S_FLSParameter(const S_FLSParameter &instance)
{
    this->sensorId = instance.sensorId;
    this->sampleNumbers = instance.sampleNumbers;
    this->gain = instance.gain;
    this->exposureTime = instance.exposureTime;
    this->sampleFrequency = instance.sampleFrequency;
}

S_FLSParameter::S_FLSParameter(const SR_FLSParameter &instance)
{
    this->sensorId = instance.sensorId.value;
    this->sampleNumbers = instance.sampleNumbers.value;
    this->gain = instance.gain.value;
    this->exposureTime = instance.exposureTime.value;
    this->sampleFrequency = instance.sampleFrequency.value;
}

S_FLSParameter &S_FLSParameter::operator=(const S_FLSParameter &instance)
{
    this->sensorId = instance.sensorId;
    this->sampleNumbers = instance.sampleNumbers;
    this->gain = instance.gain;
    this->exposureTime = instance.exposureTime;
    this->sampleFrequency = instance.sampleFrequency;
    return *this;
}

S_FLSParameter &S_FLSParameter::operator=(const SR_FLSParameter &instance)
{
    this->sensorId = instance.sensorId.value;
    this->sampleNumbers = instance.sampleNumbers.value;
    this->gain = instance.gain.value;
    this->exposureTime = instance.exposureTime.value;
    this->sampleFrequency = instance.sampleFrequency.value;
    return *this;
}

SR_FLSParameter::SR_FLSParameter() : TValueBase()
{

}

SR_FLSParameter::SR_FLSParameter(const S_FLSParameter &instance) : TValueBase()
{
    this->sensorId = instance.sensorId;
    this->sampleNumbers = instance.sampleNumbers;
    this->gain = instance.gain;
    this->exposureTime = instance.exposureTime;
    this->sampleFrequency = instance.sampleFrequency;
}

SR_FLSParameter::SR_FLSParameter(const SR_FLSParameter &instance) : TValueBase(instance)
{
    this->sensorId = instance.sensorId;
    this->sampleNumbers = instance.sampleNumbers;
    this->gain = instance.gain;
    this->exposureTime = instance.exposureTime;
    this->sampleFrequency = instance.sampleFrequency;
}

SR_FLSParameter &SR_FLSParameter::operator=(const S_FLSParameter &instance)
{
    this->sensorId = instance.sensorId;
    this->sampleNumbers = instance.sampleNumbers;
    this->gain = instance.gain;
    this->exposureTime = instance.exposureTime;
    this->sampleFrequency = instance.sampleFrequency;
    return *this;
}

SR_FLSParameter &SR_FLSParameter::operator=(const SR_FLSParameter &instance)
{
    TValueBase::operator=(instance);
    this->sensorId = instance.sensorId;
    this->sampleNumbers = instance.sampleNumbers;
    this->gain = instance.gain;
    this->exposureTime = instance.exposureTime;
    this->sampleFrequency = instance.sampleFrequency;
    return *this;
}

S_FLS::S_FLS()
{

}

S_FLS::S_FLS(const S_FLS &instance)
{
    this->flsForMask = instance.flsForMask;
    this->flsForWafer = instance.flsForWafer;
}

S_FLS::S_FLS(const SR_FLS &instance)
{
    this->flsForMask = instance.flsForMask;
    this->flsForWafer = instance.flsForWafer;
}

S_FLS &S_FLS::operator=(const S_FLS &instance)
{
    this->flsForMask = instance.flsForMask;
    this->flsForWafer = instance.flsForWafer;
    return *this;
}

S_FLS &S_FLS::operator=(const SR_FLS &instance)
{
    this->flsForMask = instance.flsForMask;
    this->flsForWafer = instance.flsForWafer;
    return *this;
}

SR_FLS::SR_FLS() : TValueBase()
{

}

SR_FLS::SR_FLS(const S_FLS &instance) : TValueBase()
{
    this->flsForMask = instance.flsForMask;
    this->flsForWafer = instance.flsForWafer;
}

SR_FLS::SR_FLS(const SR_FLS &instance) : TValueBase(instance)
{
    this->flsForMask = instance.flsForMask;
    this->flsForWafer = instance.flsForWafer;
}

SR_FLS &SR_FLS::operator=(const S_FLS &instance)
{
    this->flsForMask = instance.flsForMask;
    this->flsForWafer = instance.flsForWafer;
    return *this;
}

SR_FLS &SR_FLS::operator=(const SR_FLS &instance)
{
    TValueBase::operator=(instance);
    this->flsForMask = instance.flsForMask;
    this->flsForWafer = instance.flsForWafer;
    return *this;
}
