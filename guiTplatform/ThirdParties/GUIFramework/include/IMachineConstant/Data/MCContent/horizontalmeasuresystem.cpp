#include "horizontalmeasuresystem.h"

S_HMSys::S_HMSys()
{

}

S_HMSys::S_HMSys(const S_HMSys &instance)
{
    this->OAL = instance.OAL;
    this->BAL = instance.BAL;
    this->BAL_xAxis = instance.BAL_xAxis;
    this->BAL_yAxis = instance.BAL_yAxis;
    this->CAL = instance.CAL;
    this->CAL_xAxis = instance.CAL_xAxis;
    this->CAL_yAxis = instance.CAL_yAxis;
    this->CAL_zAxis = instance.CAL_zAxis;
}

S_HMSys::S_HMSys(const SR_HMSys &instance)
{
    this->OAL = instance.OAL;
    this->BAL = instance.BAL;
    this->BAL_xAxis = instance.BAL_xAxis;
    this->BAL_yAxis = instance.BAL_yAxis;
    this->CAL = instance.CAL;
    this->CAL_xAxis = instance.CAL_xAxis;
    this->CAL_yAxis = instance.CAL_yAxis;
    this->CAL_zAxis = instance.CAL_zAxis;
}

S_HMSys &S_HMSys::operator=(const S_HMSys &instance)
{
    this->OAL = instance.OAL;
    this->BAL = instance.BAL;
    this->BAL_xAxis = instance.BAL_xAxis;
    this->BAL_yAxis = instance.BAL_yAxis;
    this->CAL = instance.CAL;
    this->CAL_xAxis = instance.CAL_xAxis;
    this->CAL_yAxis = instance.CAL_yAxis;
    this->CAL_zAxis = instance.CAL_zAxis;
    return *this;
}

S_HMSys &S_HMSys::operator=(const SR_HMSys &instance)
{
    this->OAL = instance.OAL;
    this->BAL = instance.BAL;
    this->BAL_xAxis = instance.BAL_xAxis;
    this->BAL_yAxis = instance.BAL_yAxis;
    this->CAL = instance.CAL;
    this->CAL_xAxis = instance.CAL_xAxis;
    this->CAL_yAxis = instance.CAL_yAxis;
    this->CAL_zAxis = instance.CAL_zAxis;
    return *this;
}


SR_HMSys::SR_HMSys() : TValueBase()
{

}

SR_HMSys::SR_HMSys(const S_HMSys &instance) : TValueBase()
{
    this->OAL = instance.OAL;
    this->BAL = instance.BAL;
    this->BAL_xAxis = instance.BAL_xAxis;
    this->BAL_yAxis = instance.BAL_yAxis;
    this->CAL = instance.CAL;
    this->CAL_xAxis = instance.CAL_xAxis;
    this->CAL_yAxis = instance.CAL_yAxis;
    this->CAL_zAxis = instance.CAL_zAxis;
}

SR_HMSys::SR_HMSys(const SR_HMSys &instance) : TValueBase(instance)
{
    this->OAL = instance.OAL;
    this->BAL = instance.BAL;
    this->BAL_xAxis = instance.BAL_xAxis;
    this->BAL_yAxis = instance.BAL_yAxis;
    this->CAL = instance.CAL;
    this->CAL_xAxis = instance.CAL_xAxis;
    this->CAL_yAxis = instance.CAL_yAxis;
    this->CAL_zAxis = instance.CAL_zAxis;
}

SR_HMSys &SR_HMSys::operator=(const S_HMSys &instance)
{
    this->OAL = instance.OAL;
    this->BAL = instance.BAL;
    this->BAL_xAxis = instance.BAL_xAxis;
    this->BAL_yAxis = instance.BAL_yAxis;
    this->CAL = instance.CAL;
    this->CAL_xAxis = instance.CAL_xAxis;
    this->CAL_yAxis = instance.CAL_yAxis;
    this->CAL_zAxis = instance.CAL_zAxis;
    return *this;
}

SR_HMSys &SR_HMSys::operator=(const SR_HMSys &instance)
{
    TValueBase::operator=(instance);
    this->OAL = instance.OAL;
    this->BAL = instance.BAL;
    this->BAL_xAxis = instance.BAL_xAxis;
    this->BAL_yAxis = instance.BAL_yAxis;
    this->CAL = instance.CAL;
    this->CAL_xAxis = instance.CAL_xAxis;
    this->CAL_yAxis = instance.CAL_yAxis;
    this->CAL_zAxis = instance.CAL_zAxis;
    return *this;
}
