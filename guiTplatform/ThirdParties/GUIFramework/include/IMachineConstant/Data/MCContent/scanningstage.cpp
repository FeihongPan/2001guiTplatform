#include "scanningstage.h"

S_ScanningStage::S_ScanningStage()
{

}

S_ScanningStage::S_ScanningStage(const S_ScanningStage &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->iCsTF = stage.iCsTF;
    this->airFoot = stage.airFoot;
    this->matrix = stage.matrix;
}

S_ScanningStage::S_ScanningStage(const SR_ScanningStage &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->iCsTF = stage.iCsTF;
    this->airFoot = stage.airFoot;
    this->matrix = stage.matrix.value;
}

S_ScanningStage &S_ScanningStage::operator=(const S_ScanningStage &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->iCsTF = stage.iCsTF;
    this->airFoot = stage.airFoot;
    this->matrix = stage.matrix;
    return *this;
}

S_ScanningStage &S_ScanningStage::operator=(const SR_ScanningStage &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->iCsTF = stage.iCsTF;
    this->airFoot = stage.airFoot;
    this->matrix = stage.matrix.value;
    return *this;
}

SR_ScanningStage::SR_ScanningStage()
{
    this->xAxis.valueName = toStr(xAxis);
    this->yAxis.valueName = toStr(yAxis);
    this->iCsTF.valueName = toStr(iCsTF);
    this->airFoot.valueName = toStr(airFoot);
    this->matrix.valueName = toStr(matrix);
}

SR_ScanningStage::SR_ScanningStage(const SR_ScanningStage &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->iCsTF = stage.iCsTF;
    this->airFoot = stage.airFoot;
    this->matrix = stage.matrix;
}

SR_ScanningStage::SR_ScanningStage(const S_ScanningStage &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->iCsTF = stage.iCsTF;
    this->airFoot = stage.airFoot;
    this->matrix = stage.matrix;
}

SR_ScanningStage &SR_ScanningStage::operator=(const SR_ScanningStage &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->iCsTF = stage.iCsTF;
    this->airFoot = stage.airFoot;
    this->matrix = stage.matrix;
    return *this;
}

SR_ScanningStage &SR_ScanningStage::operator=(const S_ScanningStage &stage)
{
    this->xAxis = stage.xAxis;
    this->yAxis = stage.yAxis;
    this->iCsTF = stage.iCsTF;
    this->airFoot = stage.airFoot;
    this->matrix = stage.matrix;
    return *this;
}
