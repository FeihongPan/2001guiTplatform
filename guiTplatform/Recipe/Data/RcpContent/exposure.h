#ifndef EXPOSURE_H
#define EXPOSURE_H

#include "BasicValue/point.h"
#include "Serializer/QSerializer"

class S_ExposureModel : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

public:
    enum WaveLength
    {
        ghi,
        gh,
        i,
    };
    Q_ENUM(WaveLength)

    QS_FIELD(WaveLength, waveLength)
    QS_FIELD(bool, isLocalAlign)
    QS_FIELD(bool, isLocalFocus)

public:
    S_ExposureModel();
    S_ExposureModel(const S_ExposureModel &model);
    S_ExposureModel &operator=(const S_ExposureModel &model);
};

class S_ExposureCompensation : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE
public:
    QS_FIELD(bool, isMaskStageCompensation)
    QS_FIELD(bool, isMicroStageCompensation)
    QS_FIELD(bool, isAlignCompensation)
    QS_FIELD(bool, isDownFLSCompensation)
    QS_FIELD(bool, isOverlayCompensation)
public:
    S_ExposureCompensation();
    S_ExposureCompensation(const S_ExposureCompensation &compensation);
    S_ExposureCompensation &operator=(const S_ExposureCompensation &compensation);
};

class S_MicroStageCompensation : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, x)
    QS_FIELD(double, y)
    QS_FIELD(double, Rz)
    QS_FIELD(double, zOffset)

public:
    S_MicroStageCompensation();
    S_MicroStageCompensation(const S_MicroStageCompensation &microStageCompensation);
    S_MicroStageCompensation &operator=(const S_MicroStageCompensation &microStageCompensation);
};

class S_Exposure : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_ExposureModel, model)
    QS_OBJECT(S_MicroStageCompensation, microStageCompensation)
    QS_OBJECT(S_ExposureCompensation, compensation)
    QS_OBJECT(S_Point2D, compensationGrid)
    QS_FIELD(double, dose)

public:
    S_Exposure();
    S_Exposure(const S_Exposure &exp);
    S_Exposure &operator=(const S_Exposure &exp);
};

#endif // EXPOSURE_H
