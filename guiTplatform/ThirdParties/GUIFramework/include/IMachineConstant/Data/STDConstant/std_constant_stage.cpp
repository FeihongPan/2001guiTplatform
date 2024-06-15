#include "std_constant_stage.h"

S_STD_Constant_VStage::S_STD_Constant_VStage()
{

}

S_STD_Constant_VStage::S_STD_Constant_VStage(const S_STD_Constant_VStage &stage)
{
    this->rxAxis = stage.rxAxis;
    this->ryAxis = stage.ryAxis;
    this->zAxis = stage.zAxis;
    this->matrix = stage.matrix;
}

S_STD_Constant_VStage::S_STD_Constant_VStage(const SR_STD_Constant_VStage &stage)
{
    this->rxAxis = stage.rxAxis;
    this->ryAxis = stage.ryAxis;
    this->zAxis = stage.zAxis;
    this->matrix = stage.matrix.value;
}

S_STD_Constant_VStage &S_STD_Constant_VStage::operator=(const S_STD_Constant_VStage &stage)
{
    this->rxAxis = stage.rxAxis;
    this->ryAxis = stage.ryAxis;
    this->zAxis = stage.zAxis;
    this->matrix = stage.matrix;
    return *this;
}

S_STD_Constant_VStage &S_STD_Constant_VStage::operator=(const SR_STD_Constant_VStage &stage)
{
    this->rxAxis = stage.rxAxis;
    this->ryAxis = stage.ryAxis;
    this->zAxis = stage.zAxis;
    this->matrix = stage.matrix.value;
    return *this;
}

SR_STD_Constant_VStage::SR_STD_Constant_VStage() : TValueBase()
{
    this->rxAxis.valueName = toStr(rxAxis);
    this->ryAxis.valueName = toStr(ryAxis);
    this->zAxis.valueName = toStr(zAxis);
    this->matrix.valueName = toStr(matrix);
}

SR_STD_Constant_VStage::SR_STD_Constant_VStage(const SR_STD_Constant_VStage &stage) : TValueBase(stage)
{
    this->rxAxis = stage.rxAxis;
    this->ryAxis = stage.ryAxis;
    this->zAxis = stage.zAxis;
    this->matrix = stage.matrix;
}

SR_STD_Constant_VStage::SR_STD_Constant_VStage(const S_STD_Constant_VStage &stage) : TValueBase()
{
    this->rxAxis = stage.rxAxis;
    this->ryAxis = stage.ryAxis;
    this->zAxis = stage.zAxis;
    this->matrix = stage.matrix;
}

SR_STD_Constant_VStage &SR_STD_Constant_VStage::operator=(const SR_STD_Constant_VStage &stage)
{
    TValueBase::operator=(stage);
    this->rxAxis = stage.rxAxis;
    this->ryAxis = stage.ryAxis;
    this->zAxis = stage.zAxis;
    this->matrix = stage.matrix;
    return *this;
}

SR_STD_Constant_VStage &SR_STD_Constant_VStage::operator=(const S_STD_Constant_VStage &stage)
{
    this->rxAxis = stage.rxAxis;
    this->ryAxis = stage.ryAxis;
    this->zAxis = stage.zAxis;
    this->matrix = stage.matrix;
    return *this;
}

S_STD_Constant_HStage::S_STD_Constant_HStage()
{

}

S_STD_Constant_HStage::S_STD_Constant_HStage(const S_STD_Constant_HStage &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->rzAxis = stage.rzAxis;
    this->matrix = stage.matrix;
}

S_STD_Constant_HStage::S_STD_Constant_HStage(const SR_STD_Constant_HStage &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->rzAxis = stage.rzAxis;
    this->matrix = stage.matrix.value;
}

S_STD_Constant_HStage &S_STD_Constant_HStage::operator=(const S_STD_Constant_HStage &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->rzAxis = stage.rzAxis;
    this->matrix = stage.matrix;
    return *this;
}

S_STD_Constant_HStage &S_STD_Constant_HStage::operator=(const SR_STD_Constant_HStage &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->rzAxis = stage.rzAxis;
    this->matrix = stage.matrix.value;
    return *this;
}

SR_STD_Constant_HStage::SR_STD_Constant_HStage() : TValueBase()
{
    this->xAxis.valueName = toStr(xAxis);
    this->yAxis.valueName = toStr(yAxis);
    this->rzAxis.valueName = toStr(rzAxis);
    this->matrix = toStr(matrix);
}

SR_STD_Constant_HStage::SR_STD_Constant_HStage(const SR_STD_Constant_HStage &stage) : TValueBase(stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->rzAxis = stage.rzAxis;
    this->matrix = stage.matrix;
}

SR_STD_Constant_HStage::SR_STD_Constant_HStage(const S_STD_Constant_HStage &stage) : TValueBase()
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->rzAxis = stage.rzAxis;
    this->matrix = stage.matrix;
}

SR_STD_Constant_HStage &SR_STD_Constant_HStage::operator=(const SR_STD_Constant_HStage &stage)
{
    TValueBase::operator=(stage);
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->rzAxis = stage.rzAxis;
    this->matrix = stage.matrix;
    return *this;
}

SR_STD_Constant_HStage &SR_STD_Constant_HStage::operator=(const S_STD_Constant_HStage &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->rzAxis = stage.rzAxis;
    this->matrix = stage.matrix;
    return *this;
}
