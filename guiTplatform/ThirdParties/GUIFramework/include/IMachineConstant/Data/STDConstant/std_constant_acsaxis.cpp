#include "std_constant_acsaxis.h"

S_STD_Constant_AcsAxis::S_STD_Constant_AcsAxis()
{
    this->vel = 10;
    this->acc = 100;
    this->dec = 100;
    this->jerk = 1000;
    this->trajectory = 10000;
    this->homeOffset = 0;
    this->swLimit = {-1000};
    this->dynLimit = {1000};
    this->MntMotionLmt = 0.3;
}

S_STD_Constant_AcsAxis::S_STD_Constant_AcsAxis(const S_STD_Constant_AcsAxis &axis)
{
    this->vel = axis.vel;
    this->acc = axis.acc;
    this->dec = axis.dec;
    this->jerk = axis.jerk;
    this->trajectory = axis.trajectory;
    this->homeOffset = axis.homeOffset;
    this->swLimit = axis.swLimit;
    this->dynLimit = axis.dynLimit;
    this->MntMotionLmt = axis.MntMotionLmt;
}

S_STD_Constant_AcsAxis::S_STD_Constant_AcsAxis(const SR_STD_Constant_AcsAxis &axis)
{
    this->vel = axis.vel.value;
    this->acc = axis.acc.value;
    this->dec = axis.dec.value;
    this->jerk = axis.jerk.value;
    this->trajectory = axis.trajectory.value;
    this->homeOffset = axis.homeOffset.value;
    this->swLimit.clear();
    for(int i = 0; i < axis.swLimit.count(); i++)
    {
        this->swLimit.append(axis.swLimit[i].value);
    }
    this->dynLimit.clear();
    for(int i = 0; i < axis.dynLimit.count(); i++)
    {
        this->dynLimit.append(axis.dynLimit[i].value);
    }
    this->MntMotionLmt = axis.MntMotionLmt.value;
}

S_STD_Constant_AcsAxis &S_STD_Constant_AcsAxis::operator=(const S_STD_Constant_AcsAxis &axis)
{
    this->vel = axis.vel;
    this->acc = axis.acc;
    this->dec = axis.dec;
    this->jerk = axis.jerk;
    this->trajectory = axis.trajectory;
    this->homeOffset = axis.homeOffset;
    this->swLimit = axis.swLimit;
    this->dynLimit = axis.dynLimit;
    this->MntMotionLmt = axis.MntMotionLmt;
    return *this;
}

S_STD_Constant_AcsAxis &S_STD_Constant_AcsAxis::operator=(const SR_STD_Constant_AcsAxis &axis)
{
    this->vel = axis.vel.value;
    this->acc = axis.acc.value;
    this->dec = axis.dec.value;
    this->jerk = axis.jerk.value;
    this->trajectory = axis.trajectory.value;
    this->homeOffset = axis.homeOffset.value;
    this->swLimit.clear();
    for(int i = 0; i < axis.swLimit.count(); i++)
    {
        this->swLimit.append(axis.swLimit[i].value);
    }
    this->dynLimit.clear();
    for(int i = 0; i < axis.dynLimit.count(); i++)
    {
        this->dynLimit.append(axis.dynLimit[i].value);
    }
    this->MntMotionLmt = axis.MntMotionLmt.value;
    return *this;
}

SR_STD_Constant_AcsAxis::SR_STD_Constant_AcsAxis() : TValueBase()
{
    this->vel.valueName = toStr(vel);
    this->acc.valueName = toStr(acc);
    this->dec.valueName = toStr(dec);
    this->jerk.valueName = toStr(jerk);
    this->trajectory.valueName = toStr(trajectory);
    this->homeOffset.valueName = toStr(homeOffset);
    this->MntMotionLmt.valueName = toStr(MntMotionLmt);
}

SR_STD_Constant_AcsAxis::SR_STD_Constant_AcsAxis(const SR_STD_Constant_AcsAxis &axis) : TValueBase(axis)
{
    this->vel = axis.vel;
    this->acc = axis.acc;
    this->dec = axis.dec;
    this->jerk = axis.jerk;
    this->trajectory = axis.trajectory;
    this->homeOffset = axis.homeOffset;
    this->swLimit = axis.swLimit;
    this->dynLimit = axis.dynLimit;
    this->MntMotionLmt = axis.MntMotionLmt;
}

SR_STD_Constant_AcsAxis::SR_STD_Constant_AcsAxis(const S_STD_Constant_AcsAxis &axis) : TValueBase()
{
    this->vel = axis.vel;
    this->acc = axis.acc;
    this->dec = axis.dec;
    this->jerk = axis.jerk;
    this->trajectory = axis.trajectory;
    this->homeOffset = axis.homeOffset;
    this->swLimit.clear();
    for(int i = 0; i < axis.swLimit.count(); i++)
    {
        this->swLimit.append(axis.swLimit[i]);
    }
    this->dynLimit.clear();
    for(int i = 0; i < axis.dynLimit.count(); i++)
    {
        this->dynLimit.append(axis.dynLimit[i]);
    }
    this->MntMotionLmt = axis.MntMotionLmt;
}

SR_STD_Constant_AcsAxis &SR_STD_Constant_AcsAxis::operator=(const SR_STD_Constant_AcsAxis &axis)
{
    TValueBase::operator=(axis);
    this->vel = axis.vel;
    this->acc = axis.acc;
    this->dec = axis.dec;
    this->jerk = axis.jerk;
    this->trajectory = axis.trajectory;
    this->homeOffset = axis.homeOffset;
    this->swLimit = axis.swLimit;
    this->dynLimit = axis.dynLimit;
    this->MntMotionLmt = axis.MntMotionLmt;
    return *this;
}

SR_STD_Constant_AcsAxis &SR_STD_Constant_AcsAxis::operator=(const S_STD_Constant_AcsAxis &axis)
{
    this->vel = axis.vel;
    this->acc = axis.acc;
    this->dec = axis.dec;
    this->jerk = axis.jerk;
    this->trajectory = axis.trajectory;
    this->homeOffset = axis.homeOffset;
    this->swLimit.clear();
    for(int i = 0; i < axis.swLimit.count(); i++)
    {
        this->swLimit.append(axis.swLimit[i]);
    }
    this->dynLimit.clear();
    for(int i = 0; i < axis.dynLimit.count(); i++)
    {
        this->dynLimit.append(axis.dynLimit[i]);
    }
    this->MntMotionLmt = axis.MntMotionLmt;
    return *this;
}



S_STD_Constant_AirAxis::S_STD_Constant_AirAxis() : S_STD_Constant_AcsAxis()
{

}

S_STD_Constant_AirAxis::S_STD_Constant_AirAxis(const S_STD_Constant_AirAxis &axis) : S_STD_Constant_AcsAxis(axis)
{
    this->airBearing = axis.airBearing;
}

S_STD_Constant_AirAxis::S_STD_Constant_AirAxis(const SR_STD_Constant_AirAxis &axis) : S_STD_Constant_AcsAxis(axis)
{
    this->airBearing = axis.airBearing;
}

S_STD_Constant_AirAxis &S_STD_Constant_AirAxis::operator=(const S_STD_Constant_AirAxis &axis)
{
    S_STD_Constant_AcsAxis::operator=(axis);
    this->airBearing = axis.airBearing;
    return *this;
}

S_STD_Constant_AirAxis &S_STD_Constant_AirAxis::operator=(const SR_STD_Constant_AirAxis &axis)
{
    S_STD_Constant_AcsAxis::operator=(axis);
    this->airBearing = axis.airBearing;
    return *this;
}
//

SR_STD_Constant_AirAxis::SR_STD_Constant_AirAxis() : SR_STD_Constant_AcsAxis()
{
    this->airBearing.valueName = toStr(airBearing);
}

SR_STD_Constant_AirAxis::SR_STD_Constant_AirAxis(const S_STD_Constant_AirAxis &axis) : SR_STD_Constant_AcsAxis(axis)
{
    this->airBearing = axis.airBearing;
}

SR_STD_Constant_AirAxis::SR_STD_Constant_AirAxis(const SR_STD_Constant_AirAxis &axis) : SR_STD_Constant_AcsAxis(axis)
{
    this->airBearing = axis.airBearing;
}

SR_STD_Constant_AirAxis &SR_STD_Constant_AirAxis::operator=(const S_STD_Constant_AirAxis &axis)
{
    SR_STD_Constant_AcsAxis::operator=(axis);
    this->airBearing = axis.airBearing;
    return *this;
}

SR_STD_Constant_AirAxis &SR_STD_Constant_AirAxis::operator=(const SR_STD_Constant_AirAxis &axis)
{
    SR_STD_Constant_AcsAxis::operator=(axis);
    this->airBearing = axis.airBearing;
    return *this;
}

S_STD_Constant_ScaleAxis::S_STD_Constant_ScaleAxis() : S_STD_Constant_AcsAxis()
{

}

S_STD_Constant_ScaleAxis::S_STD_Constant_ScaleAxis(const S_STD_Constant_ScaleAxis &axis) : S_STD_Constant_AcsAxis()
{
    this->apertureScaling = axis.apertureScaling;
}

S_STD_Constant_ScaleAxis::S_STD_Constant_ScaleAxis(const SR_STD_Constant_ScaleAxis &axis) : S_STD_Constant_AcsAxis(axis)
{
    this->apertureScaling.clear();
    for(int i = 0; i < axis.apertureScaling.count(); i++)
    {
        this->apertureScaling.append(axis.apertureScaling[i]);
    }
}

S_STD_Constant_ScaleAxis &S_STD_Constant_ScaleAxis::operator=(const S_STD_Constant_ScaleAxis &axis)
{
    S_STD_Constant_AcsAxis::operator=(axis);
    this->apertureScaling.clear();
    for(int i = 0; i < axis.apertureScaling.count(); i++)
    {
        this->apertureScaling.append(axis.apertureScaling[i]);
    }
    return *this;
}

S_STD_Constant_ScaleAxis &S_STD_Constant_ScaleAxis::operator=(const SR_STD_Constant_ScaleAxis &axis)
{
    S_STD_Constant_AcsAxis::operator=(axis);
    this->apertureScaling.clear();
    for(int i = 0; i < axis.apertureScaling.count(); i++)
    {
        this->apertureScaling.append(axis.apertureScaling[i]);
    }
    return *this;
}

SR_STD_Constant_ScaleAxis::SR_STD_Constant_ScaleAxis() : SR_STD_Constant_AcsAxis()
{

}

SR_STD_Constant_ScaleAxis::SR_STD_Constant_ScaleAxis(const S_STD_Constant_ScaleAxis &axis) : SR_STD_Constant_AcsAxis()
{
    this->apertureScaling.clear();
    for(int i = 0; i < axis.apertureScaling.count(); i++)
    {
        this->apertureScaling.append(axis.apertureScaling[i]);
    }
}

SR_STD_Constant_ScaleAxis::SR_STD_Constant_ScaleAxis(const SR_STD_Constant_ScaleAxis &axis) : SR_STD_Constant_AcsAxis(axis)
{
    this->apertureScaling = axis.apertureScaling;
}

SR_STD_Constant_ScaleAxis &SR_STD_Constant_ScaleAxis::operator=(const S_STD_Constant_ScaleAxis &axis)
{
    SR_STD_Constant_AcsAxis::operator=(axis);
    this->apertureScaling.clear();
    for(int i = 0; i < axis.apertureScaling.count(); i++)
    {
        this->apertureScaling.append(axis.apertureScaling[i]);
    }
    return *this;
}

SR_STD_Constant_ScaleAxis &SR_STD_Constant_ScaleAxis::operator=(const SR_STD_Constant_ScaleAxis &axis)
{
    SR_STD_Constant_AcsAxis::operator=(axis);
    this->apertureScaling.clear();
    for(int i = 0; i < axis.apertureScaling.count(); i++)
    {
        this->apertureScaling.append(axis.apertureScaling[i]);
    }
    return *this;
}
