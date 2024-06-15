#include "masktransfer.h"

S_MaskTransfer::S_MaskTransfer()
{

}

S_MaskTransfer::S_MaskTransfer(const S_MaskTransfer &stage)
{
    this->xAxis = stage.xAxis;
    this->zAxis = stage.zAxis;
}

S_MaskTransfer::S_MaskTransfer(const SR_MaskTransfer &stage)
{
    this->xAxis = stage.xAxis;
    this->zAxis = stage.zAxis;
}

S_MaskTransfer &S_MaskTransfer::operator=(const S_MaskTransfer &stage)
{
    this->xAxis = stage.xAxis;
    this->zAxis = stage.zAxis;
    return *this;
}

S_MaskTransfer &S_MaskTransfer::operator=(const SR_MaskTransfer &stage)
{
    this->xAxis = stage.xAxis;
    this->zAxis = stage.zAxis;
    return *this;
}

SR_MaskTransfer::SR_MaskTransfer()
{
    this->xAxis.valueName = toStr(xAxis);
    this->zAxis.valueName = toStr(zAxis);
}

SR_MaskTransfer::SR_MaskTransfer(const SR_MaskTransfer &stage)
{
    this->xAxis = stage.xAxis;
    this->zAxis = stage.zAxis;
}

SR_MaskTransfer::SR_MaskTransfer(const S_MaskTransfer &stage)
{
    this->xAxis = stage.xAxis;
    this->zAxis = stage.zAxis;
}

SR_MaskTransfer &SR_MaskTransfer::operator=(const SR_MaskTransfer &stage)
{
    this->xAxis = stage.xAxis;
    this->zAxis = stage.zAxis;
    return *this;
}

SR_MaskTransfer &SR_MaskTransfer::operator=(const S_MaskTransfer &stage)
{
    this->xAxis = stage.xAxis;
    this->zAxis = stage.zAxis;
    return *this;
}
