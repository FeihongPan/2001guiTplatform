#include "ccd.h"

S_CCD::S_CCD()
{

}

S_CCD::S_CCD(const S_CCD &stage)
{
    this->yAxis = stage.yAxis;
}

S_CCD::S_CCD(const SR_CCD &stage)
{
    this->yAxis = stage.yAxis;
}

S_CCD &S_CCD::operator=(const S_CCD &stage)
{
    this->yAxis = stage.yAxis;
    return *this;
}

S_CCD &S_CCD::operator=(const SR_CCD &stage)
{
    this->yAxis = stage.yAxis;
    return *this;
}

SR_CCD::SR_CCD()
{
    this->yAxis.valueName = toStr(yAxis);
}

SR_CCD::SR_CCD(const SR_CCD &stage)
{
    this->yAxis = stage.yAxis;
}

SR_CCD::SR_CCD(const S_CCD &stage)
{
    this->yAxis = stage.yAxis;
}

SR_CCD &SR_CCD::operator=(const SR_CCD &stage)
{
    this->yAxis = stage.yAxis;
    return *this;
}

SR_CCD &SR_CCD::operator=(const S_CCD &stage)
{
    this->yAxis = stage.yAxis;
    return *this;
}
