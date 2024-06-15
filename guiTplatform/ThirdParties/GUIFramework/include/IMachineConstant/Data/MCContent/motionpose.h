#ifndef MOTIONPOSE_H
#define MOTIONPOSE_H

#include "GUIFramework_global.h"
#include "BasicValue/point.h"
#include "Serializer/QSerializer"

class SR_MotionPose;

class GUIFRAMEWORK_EXPORT S_MotionPose : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_Point2D, posStencilSwapRoughMoveStage)
    QS_OBJECT(S_Point3D, posStencilSwapVertStage)
    QS_OBJECT(S_Point3D, posStencilSwapHorzStage)
    QS_OBJECT(S_Point3D, offsetStencilUpload)

    QS_OBJECT(S_Point2D, posStencilLevelingHorzPrepare)
    QS_OBJECT(S_Point3D, posStencilLevelingVertPrepare)
    QS_OBJECT(S_Point2D, posStencilLevelingCenterCoord)

    QS_OBJECT(S_Point2D, posWaferLevelingHorzPrepare)
    QS_OBJECT(S_Point3D, posWaferLevelingVertPrepare)
    QS_OBJECT(S_Point2D, posWaferLevelingCenterCoord)

    QS_OBJECT(S_Point2D, posStencilAlignHorzPrepare)
    QS_OBJECT(S_Point3D, posStencilAlignVertPrepare)
    QS_OBJECT(S_Point2D, posStencilAlignCenterCoord)

    QS_OBJECT(S_Point2D, posWaferCoarseAlignHorzPrepare)
    QS_OBJECT(S_Point3D, posWaferCoarseAlignVertPrepare)
    QS_OBJECT(S_Point2D, posWaferCoarseAlignCenterCoord)

    QS_OBJECT(S_Point2D, posWaferSwapRoughStage)

    QS_FIELD(double, posWaferLevelingRotatePrepare)

public:
    S_MotionPose();
    S_MotionPose(const S_MotionPose &pose);
    S_MotionPose(const SR_MotionPose &pose);
    S_MotionPose &operator=(const S_MotionPose &pose);
    S_MotionPose &operator=(const SR_MotionPose &pose);
};

class GUIFRAMEWORK_EXPORT SR_MotionPose : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_Point2D, posStencilSwapRoughMoveStage)
    QS_OBJECT(SR_Point3D, posStencilSwapVertStage)
    QS_OBJECT(SR_Point3D, posStencilSwapHorzStage)
    QS_OBJECT(SR_Point3D, offsetStencilUpload)

    QS_OBJECT(SR_Point2D, posStencilLevelingHorzPrepare)
    QS_OBJECT(SR_Point3D, posStencilLevelingVertPrepare)
    QS_OBJECT(SR_Point2D, posStencilLevelingCenterCoord)

    QS_OBJECT(SR_Point2D, posWaferLevelingHorzPrepare)
    QS_OBJECT(SR_Point3D, posWaferLevelingVertPrepare)
    QS_OBJECT(SR_Point2D, posWaferLevelingCenterCoord)

    QS_OBJECT(SR_Point2D, posStencilAlignHorzPrepare)
    QS_OBJECT(SR_Point3D, posStencilAlignVertPrepare)
    QS_OBJECT(SR_Point2D, posStencilAlignCenterCoord)

    QS_OBJECT(SR_Point2D, posWaferCoarseAlignHorzPrepare)
    QS_OBJECT(SR_Point3D, posWaferCoarseAlignVertPrepare)
    QS_OBJECT(SR_Point2D, posWaferCoarseAlignCenterCoord)

    QS_OBJECT(SR_Point2D, posWaferSwapRoughStage)

    QS_FIELD(double, posWaferLevelingRotatePrepare)

public:
    SR_MotionPose();
    SR_MotionPose(const SR_MotionPose &stage);
    SR_MotionPose(const S_MotionPose &stage);
    SR_MotionPose &operator=(const SR_MotionPose &stage);
    SR_MotionPose &operator=(const S_MotionPose &stage);
};

#endif // MOTIONPOSE_H
