#include "backaligner.h"

S_BackAligner::S_BackAligner()
{

}

S_BackAligner::S_BackAligner(const S_BackAligner &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
}

S_BackAligner::S_BackAligner(const SR_BackAligner &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
}

S_BackAligner &S_BackAligner::operator=(const S_BackAligner &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    return *this;
}

S_BackAligner &S_BackAligner::operator=(const SR_BackAligner &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    return *this;
}

SR_BackAligner::SR_BackAligner()
{
    this->xAxis.valueName = toStr(xAxis);
    this->yAxis.valueName = toStr(yAxis);
}

SR_BackAligner::SR_BackAligner(const SR_BackAligner &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
}

SR_BackAligner::SR_BackAligner(const S_BackAligner &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
}

SR_BackAligner &SR_BackAligner::operator=(const SR_BackAligner &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    return *this;
}

SR_BackAligner &SR_BackAligner::operator=(const S_BackAligner &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    return *this;
}
