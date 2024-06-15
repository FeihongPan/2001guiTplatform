#include "expose.h"

S_Expose::S_Expose()
{

}

S_Expose::S_Expose(const S_Expose &instance)
{
    this->power = instance.power;
}

S_Expose::S_Expose(const SR_Expose &instance)
{
    this->power = instance.power.value;
}

S_Expose &S_Expose::operator=(const S_Expose &instance)
{
    this->power = instance.power;
    return *this;
}

S_Expose &S_Expose::operator=(const SR_Expose &instance)
{
    this->power = instance.power.value;
    return *this;
}

SR_Expose::SR_Expose() : TValueBase()
{

}

SR_Expose::SR_Expose(const S_Expose &instance) : TValueBase()
{
    this->power = instance.power;
}

SR_Expose::SR_Expose(const SR_Expose &instance) : TValueBase(instance)
{
    this->power = instance.power;
}

SR_Expose &SR_Expose::operator=(const S_Expose &instance)
{
    this->power = instance.power;
    return *this;
}

SR_Expose &SR_Expose::operator=(const SR_Expose &instance)
{
    TValueBase::operator=(instance);
    this->power = instance.power;
    return *this;
}
