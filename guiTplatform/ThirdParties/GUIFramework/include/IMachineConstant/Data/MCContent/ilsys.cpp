#include "ilsys.h"

S_Illumination::S_Illumination()
{

}

S_Illumination::S_Illumination(const S_Illumination &instance)
{
    this->intensityOffset = instance.intensityOffset;
    this->shutter = instance.shutter;
    this->filter = instance.filter;
    this->VA = instance.VA;
}

S_Illumination::S_Illumination(const SR_Illumination &instance)
{
    this->intensityOffset.clear();
    for(int i = 0; i < instance.intensityOffset.count(); i++)
    {
        this->intensityOffset.append(instance.intensityOffset[i].value);
    }

    this->shutter = instance.shutter;
    this->filter = instance.filter;
    this->VA = instance.VA;
}

S_Illumination &S_Illumination::operator=(const S_Illumination &instance)
{
    this->intensityOffset = instance.intensityOffset;
    this->shutter = instance.shutter;
    this->filter = instance.filter;
    this->VA = instance.VA;
    return *this;
}

S_Illumination &S_Illumination::operator=(const SR_Illumination &instance)
{
    this->intensityOffset.clear();
    for(int i = 0; i < instance.intensityOffset.count(); i++)
    {
        this->intensityOffset.append(instance.intensityOffset[i].value);
    }

    this->shutter = instance.shutter;
    this->filter = instance.filter;
    this->VA = instance.VA;
    return *this;
}

SR_Illumination::SR_Illumination() : TValueBase()
{

}

SR_Illumination::SR_Illumination(const S_Illumination &instance) : TValueBase()
{
    this->intensityOffset.clear();
    for(int i = 0; i < instance.intensityOffset.count(); i++)
    {
        this->intensityOffset.append(instance.intensityOffset[i]);
    }

    this->shutter = instance.shutter;
    this->filter = instance.filter;
    this->VA = instance.VA;
}

SR_Illumination::SR_Illumination(const SR_Illumination &instance) : TValueBase(instance)
{
    this->intensityOffset = instance.intensityOffset;
    this->shutter = instance.shutter;
    this->filter = instance.filter;
    this->VA = instance.VA;
}

SR_Illumination &SR_Illumination::operator=(const S_Illumination &instance)
{
    this->intensityOffset.clear();
    for(int i = 0; i < instance.intensityOffset.count(); i++)
    {
        this->intensityOffset.append(instance.intensityOffset[i]);
    }

    this->shutter = instance.shutter;
    this->filter = instance.filter;
    this->VA = instance.VA;
    return *this;
}

SR_Illumination &SR_Illumination::operator=(const SR_Illumination &instance)
{
    TValueBase::operator=(instance);
    this->intensityOffset = instance.intensityOffset;
    this->shutter = instance.shutter;
    this->filter = instance.filter;
    this->VA = instance.VA;
    return *this;
}
