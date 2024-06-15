#include "std_constant_plcaxis.h"

S_STD_Constant_PlcAxis::S_STD_Constant_PlcAxis()
{
    this->vel = 10;
    this->acc = 100;
    this->homeOffset = 0.0;
    this->homeMethod = 0.0;
    this->paramVel = 0.0;
    this->homeVel = 0.0;
}

S_STD_Constant_PlcAxis::S_STD_Constant_PlcAxis(const S_STD_Constant_PlcAxis &axis)
{
    this->vel = axis.vel;
    this->acc = axis.acc;
    this->homeOffset = axis.homeOffset;
    this->homeMethod = axis.homeMethod;
    this->paramVel = axis.paramVel;
    this->homeVel = axis.homeVel;
}

S_STD_Constant_PlcAxis::S_STD_Constant_PlcAxis(const SR_STD_Constant_PlcAxis &axis)
{
    this->vel = axis.vel.value;
    this->acc = axis.acc.value;
    this->homeOffset = axis.homeOffset.value;
    this->homeMethod = axis.homeMethod.value;
    this->paramVel = axis.paramVel.value;
    this->homeVel = axis.homeVel.value;
}

S_STD_Constant_PlcAxis &S_STD_Constant_PlcAxis::operator=(const S_STD_Constant_PlcAxis &axis)
{
    this->vel = axis.vel;
    this->acc = axis.acc;
    this->homeOffset = axis.homeOffset;
    this->homeMethod = axis.homeMethod;
    this->paramVel = axis.paramVel;
    this->homeVel = axis.homeVel;
    return *this;
}

S_STD_Constant_PlcAxis &S_STD_Constant_PlcAxis::operator=(const SR_STD_Constant_PlcAxis &axis)
{
    this->vel = axis.vel.value;
    this->acc = axis.acc.value;
    this->homeOffset = axis.homeOffset.value;
    this->homeMethod = axis.homeMethod.value;
    this->paramVel = axis.paramVel.value;
    this->homeVel = axis.homeVel.value;
    return *this;
}

SR_STD_Constant_PlcAxis::SR_STD_Constant_PlcAxis() : TValueBase()
{
    this->vel.valueName = toStr(vel);
    this->acc.valueName = toStr(acc);
    this->homeOffset.valueName = toStr(homeOffset);
    this->homeMethod.valueName = toStr(homeMethod);
    this->paramVel.valueName = toStr(paramVel);
    this->homeVel.valueName = toStr(homeVel);
}

SR_STD_Constant_PlcAxis::SR_STD_Constant_PlcAxis(const SR_STD_Constant_PlcAxis &axis) : TValueBase(axis)
{
    this->vel = axis.vel;
    this->acc = axis.acc;
    this->homeOffset = axis.homeOffset;
    this->homeMethod = axis.homeMethod;
    this->paramVel = axis.paramVel;
    this->homeVel = axis.homeVel;
}

SR_STD_Constant_PlcAxis::SR_STD_Constant_PlcAxis(const S_STD_Constant_PlcAxis &axis) : TValueBase()
{
    this->vel = axis.vel;
    this->acc = axis.acc;
    this->homeOffset = axis.homeOffset;
    this->homeMethod = axis.homeMethod;
    this->paramVel = axis.paramVel;
    this->homeVel = axis.homeVel;
}

SR_STD_Constant_PlcAxis &SR_STD_Constant_PlcAxis::operator=(const SR_STD_Constant_PlcAxis &axis)
{
    TValueBase::operator=(axis);
    this->vel = axis.vel;
    this->acc = axis.acc;
    this->homeOffset = axis.homeOffset;
    this->homeMethod = axis.homeMethod;
    this->paramVel = axis.paramVel;
    this->homeVel = axis.homeVel;
    return *this;
}

SR_STD_Constant_PlcAxis &SR_STD_Constant_PlcAxis::operator=(const S_STD_Constant_PlcAxis &axis)
{
    this->vel = axis.vel;
    this->acc = axis.acc;
    this->homeOffset = axis.homeOffset;
    this->homeMethod = axis.homeMethod;
    this->paramVel = axis.paramVel;
    this->homeVel = axis.homeVel;
    return *this;
}
