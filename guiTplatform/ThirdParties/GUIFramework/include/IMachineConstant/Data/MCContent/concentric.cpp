#include "concentric.h"

S_Concentric::S_Concentric()
{

}

S_Concentric::S_Concentric(const S_Concentric &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->zAxis = stage.zAxis;
}

S_Concentric::S_Concentric(const SR_Concentric &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->zAxis = stage.zAxis;
}

S_Concentric &S_Concentric::operator=(const S_Concentric &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->zAxis = stage.zAxis;
    return *this;
}

S_Concentric &S_Concentric::operator=(const SR_Concentric &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->zAxis = stage.zAxis;
    return *this;
}

SR_Concentric::SR_Concentric()
{
    this->xAxis.valueName = toStr(xAxis);
    this->yAxis.valueName = toStr(yAxis);
    this->zAxis.valueName = toStr(zAxis);
}

SR_Concentric::SR_Concentric(const SR_Concentric &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->zAxis = stage.zAxis;
}

SR_Concentric::SR_Concentric(const S_Concentric &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->zAxis = stage.zAxis;
}

SR_Concentric &SR_Concentric::operator=(const SR_Concentric &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->zAxis = stage.zAxis;
    return *this;
}

SR_Concentric &SR_Concentric::operator=(const S_Concentric &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->zAxis = stage.zAxis;
    return *this;
}
