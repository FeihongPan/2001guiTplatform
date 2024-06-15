#include "exposure.h"

S_ExposureModel::S_ExposureModel()
{

}

S_ExposureModel::S_ExposureModel(const S_ExposureModel &model)
{
    this->waveLength = model.waveLength;
    this->isLocalAlign = model.isLocalAlign;
    this->isLocalFocus = model.isLocalFocus;
}

S_ExposureModel &S_ExposureModel::operator=(const S_ExposureModel &model)
{
    this->waveLength = model.waveLength;
    this->isLocalAlign = model.isLocalAlign;
    this->isLocalFocus = model.isLocalFocus;
    return *this;
}

S_ExposureCompensation::S_ExposureCompensation()
{
}
S_ExposureCompensation::S_ExposureCompensation(const S_ExposureCompensation &compensation)
{
    this->isMaskStageCompensation = compensation.isMaskStageCompensation;
    this->isMicroStageCompensation = compensation.isMicroStageCompensation;
    this->isAlignCompensation = compensation.isAlignCompensation;
    this->isDownFLSCompensation = compensation.isDownFLSCompensation;
    this->isOverlayCompensation = compensation.isOverlayCompensation;
}
S_ExposureCompensation &S_ExposureCompensation::operator=(const S_ExposureCompensation &compensation)
{
    this->isMaskStageCompensation = compensation.isMaskStageCompensation;
    this->isMicroStageCompensation = compensation.isMicroStageCompensation;
    this->isAlignCompensation = compensation.isAlignCompensation;
    this->isDownFLSCompensation = compensation.isDownFLSCompensation;
    this->isOverlayCompensation = compensation.isOverlayCompensation;
    return *this;
}


S_Exposure::S_Exposure()
{

}

S_Exposure::S_Exposure(const S_Exposure &exp)
{
    this->model = exp.model;
    this->compensation = exp.compensation;
    this->microStageCompensation = exp.microStageCompensation;
    this->compensationGrid = exp.compensationGrid;
    this->dose = exp.dose;
}

S_Exposure &S_Exposure::operator=(const S_Exposure &exp)
{
    this->model = exp.model;
    this->compensation = exp.compensation;
    this->microStageCompensation = exp.microStageCompensation;
    this->compensationGrid = exp.compensationGrid;
    this->dose = exp.dose;
    return *this;
}

S_MicroStageCompensation::S_MicroStageCompensation()
{

}

S_MicroStageCompensation::S_MicroStageCompensation(const S_MicroStageCompensation &microStageCompensation)
{
    this->x = microStageCompensation.x;
    this->y = microStageCompensation.y;
    this->Rz = microStageCompensation.Rz;
    this->zOffset = microStageCompensation.zOffset;
}

S_MicroStageCompensation &S_MicroStageCompensation::operator=(const S_MicroStageCompensation &microStageCompensation)
{
    this->x = microStageCompensation.x;
    this->y = microStageCompensation.y;
    this->Rz = microStageCompensation.Rz;
    this->zOffset = microStageCompensation.zOffset;
    return *this;
}
