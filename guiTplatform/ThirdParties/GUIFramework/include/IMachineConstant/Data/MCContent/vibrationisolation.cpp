#include "vibrationisolation.h"

S_VibrationIsolation::S_VibrationIsolation()
{

}

S_VibrationIsolation::S_VibrationIsolation(const S_VibrationIsolation &instance)
{
    this->stableSignalSampleRate = instance.stableSignalSampleRate;
}

S_VibrationIsolation::S_VibrationIsolation(const SR_VibrationIsolation &instance)
{
    this->stableSignalSampleRate = instance.stableSignalSampleRate.value;
}

S_VibrationIsolation &S_VibrationIsolation::operator=(const S_VibrationIsolation &instance)
{
    this->stableSignalSampleRate = instance.stableSignalSampleRate;
    return *this;
}

S_VibrationIsolation &S_VibrationIsolation::operator=(const SR_VibrationIsolation &instance)
{
    this->stableSignalSampleRate = instance.stableSignalSampleRate.value;
    return *this;
}

SR_VibrationIsolation::SR_VibrationIsolation() : TValueBase()
{

}

SR_VibrationIsolation::SR_VibrationIsolation(const S_VibrationIsolation &instance) : TValueBase()
{
    this->stableSignalSampleRate = instance.stableSignalSampleRate;
}

SR_VibrationIsolation::SR_VibrationIsolation(const SR_VibrationIsolation &instance) : TValueBase(instance)
{
    this->stableSignalSampleRate = instance.stableSignalSampleRate;
}

SR_VibrationIsolation &SR_VibrationIsolation::operator=(const S_VibrationIsolation &instance)
{
    this->stableSignalSampleRate = instance.stableSignalSampleRate;
    return *this;
}

SR_VibrationIsolation &SR_VibrationIsolation::operator=(const SR_VibrationIsolation &instance)
{
    TValueBase::operator=(instance);
    this->stableSignalSampleRate = instance.stableSignalSampleRate;
    return *this;
}
