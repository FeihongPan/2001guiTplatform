#include "motionpose.h"

S_MotionPose::S_MotionPose()
{

}

S_MotionPose::S_MotionPose(const S_MotionPose &pose)
{
    this->posStencilSwapRoughMoveStage = pose.posStencilSwapRoughMoveStage;
    this->posStencilSwapVertStage = pose.posStencilSwapVertStage;
    this->posStencilSwapHorzStage = pose.posStencilSwapHorzStage;
    this->offsetStencilUpload = pose.offsetStencilUpload;

    this->posStencilLevelingHorzPrepare = pose.posStencilLevelingHorzPrepare;
    this->posStencilLevelingVertPrepare = pose.posStencilLevelingVertPrepare;
    this->posStencilLevelingCenterCoord = pose.posStencilLevelingCenterCoord;

    this->posWaferLevelingHorzPrepare = pose.posWaferLevelingHorzPrepare;
    this->posWaferLevelingVertPrepare = pose.posWaferLevelingVertPrepare;
    this->posWaferLevelingCenterCoord = pose.posWaferLevelingCenterCoord;

    this->posStencilAlignHorzPrepare = pose.posStencilAlignHorzPrepare;
    this->posStencilAlignVertPrepare = pose.posStencilAlignVertPrepare;
    this->posStencilAlignCenterCoord = pose.posStencilAlignCenterCoord;

    this->posWaferCoarseAlignHorzPrepare = pose.posWaferCoarseAlignHorzPrepare;
    this->posWaferCoarseAlignVertPrepare = pose.posWaferCoarseAlignVertPrepare;
    this->posWaferCoarseAlignCenterCoord = pose.posWaferCoarseAlignCenterCoord;

    this->posWaferSwapRoughStage = pose.posWaferSwapRoughStage;

    this->posWaferLevelingRotatePrepare = pose.posWaferLevelingRotatePrepare;
}

S_MotionPose::S_MotionPose(const SR_MotionPose &pose)
{
    this->posStencilSwapRoughMoveStage = pose.posStencilSwapRoughMoveStage;
    this->posStencilSwapVertStage = pose.posStencilSwapVertStage;
    this->posStencilSwapHorzStage = pose.posStencilSwapHorzStage;
    this->offsetStencilUpload = pose.offsetStencilUpload;

    this->posStencilLevelingHorzPrepare = pose.posStencilLevelingHorzPrepare;
    this->posStencilLevelingVertPrepare = pose.posStencilLevelingVertPrepare;
    this->posStencilLevelingCenterCoord = pose.posStencilLevelingCenterCoord;

    this->posWaferLevelingHorzPrepare = pose.posWaferLevelingHorzPrepare;
    this->posWaferLevelingVertPrepare = pose.posWaferLevelingVertPrepare;
    this->posWaferLevelingCenterCoord = pose.posWaferLevelingCenterCoord;

    this->posStencilAlignHorzPrepare = pose.posStencilAlignHorzPrepare;
    this->posStencilAlignVertPrepare = pose.posStencilAlignVertPrepare;
    this->posStencilAlignCenterCoord = pose.posStencilAlignCenterCoord;

    this->posWaferCoarseAlignHorzPrepare = pose.posWaferCoarseAlignHorzPrepare;
    this->posWaferCoarseAlignVertPrepare = pose.posWaferCoarseAlignVertPrepare;
    this->posWaferCoarseAlignCenterCoord = pose.posWaferCoarseAlignCenterCoord;

    this->posWaferSwapRoughStage = pose.posWaferSwapRoughStage;

    this->posWaferLevelingRotatePrepare = pose.posWaferLevelingRotatePrepare;
}

S_MotionPose &S_MotionPose::operator=(const S_MotionPose &pose)
{
    this->posStencilSwapRoughMoveStage = pose.posStencilSwapRoughMoveStage;
    this->posStencilSwapVertStage = pose.posStencilSwapVertStage;
    this->posStencilSwapHorzStage = pose.posStencilSwapHorzStage;
    this->offsetStencilUpload = pose.offsetStencilUpload;

    this->posStencilLevelingHorzPrepare = pose.posStencilLevelingHorzPrepare;
    this->posStencilLevelingVertPrepare = pose.posStencilLevelingVertPrepare;
    this->posStencilLevelingCenterCoord = pose.posStencilLevelingCenterCoord;

    this->posWaferLevelingHorzPrepare = pose.posWaferLevelingHorzPrepare;
    this->posWaferLevelingVertPrepare = pose.posWaferLevelingVertPrepare;
    this->posWaferLevelingCenterCoord = pose.posWaferLevelingCenterCoord;

    this->posStencilAlignHorzPrepare = pose.posStencilAlignHorzPrepare;
    this->posStencilAlignVertPrepare = pose.posStencilAlignVertPrepare;
    this->posStencilAlignCenterCoord = pose.posStencilAlignCenterCoord;

    this->posWaferCoarseAlignHorzPrepare = pose.posWaferCoarseAlignHorzPrepare;
    this->posWaferCoarseAlignVertPrepare = pose.posWaferCoarseAlignVertPrepare;
    this->posWaferCoarseAlignCenterCoord = pose.posWaferCoarseAlignCenterCoord;

    this->posWaferSwapRoughStage = pose.posWaferSwapRoughStage;

    this->posWaferLevelingRotatePrepare = pose.posWaferLevelingRotatePrepare;
    return *this;
}

S_MotionPose &S_MotionPose::operator=(const SR_MotionPose &pose)
{
    this->posStencilSwapRoughMoveStage = pose.posStencilSwapRoughMoveStage;
    this->posStencilSwapVertStage = pose.posStencilSwapVertStage;
    this->posStencilSwapHorzStage = pose.posStencilSwapHorzStage;
    this->offsetStencilUpload = pose.offsetStencilUpload;

    this->posStencilLevelingHorzPrepare = pose.posStencilLevelingHorzPrepare;
    this->posStencilLevelingVertPrepare = pose.posStencilLevelingVertPrepare;
    this->posStencilLevelingCenterCoord = pose.posStencilLevelingCenterCoord;

    this->posWaferLevelingHorzPrepare = pose.posWaferLevelingHorzPrepare;
    this->posWaferLevelingVertPrepare = pose.posWaferLevelingVertPrepare;
    this->posWaferLevelingCenterCoord = pose.posWaferLevelingCenterCoord;

    this->posStencilAlignHorzPrepare = pose.posStencilAlignHorzPrepare;
    this->posStencilAlignVertPrepare = pose.posStencilAlignVertPrepare;
    this->posStencilAlignCenterCoord = pose.posStencilAlignCenterCoord;

    this->posWaferCoarseAlignHorzPrepare = pose.posWaferCoarseAlignHorzPrepare;
    this->posWaferCoarseAlignVertPrepare = pose.posWaferCoarseAlignVertPrepare;
    this->posWaferCoarseAlignCenterCoord = pose.posWaferCoarseAlignCenterCoord;

    this->posWaferSwapRoughStage = pose.posWaferSwapRoughStage;

    this->posWaferLevelingRotatePrepare = pose.posWaferLevelingRotatePrepare;
    return *this;
}

SR_MotionPose::SR_MotionPose()
{

}

SR_MotionPose::SR_MotionPose(const SR_MotionPose &pose)
{
    this->posStencilSwapRoughMoveStage = pose.posStencilSwapRoughMoveStage;
    this->posStencilSwapVertStage = pose.posStencilSwapVertStage;
    this->posStencilSwapHorzStage = pose.posStencilSwapHorzStage;
    this->offsetStencilUpload = pose.offsetStencilUpload;

    this->posStencilLevelingHorzPrepare = pose.posStencilLevelingHorzPrepare;
    this->posStencilLevelingVertPrepare = pose.posStencilLevelingVertPrepare;
    this->posStencilLevelingCenterCoord = pose.posStencilLevelingCenterCoord;

    this->posWaferLevelingHorzPrepare = pose.posWaferLevelingHorzPrepare;
    this->posWaferLevelingVertPrepare = pose.posWaferLevelingVertPrepare;
    this->posWaferLevelingCenterCoord = pose.posWaferLevelingCenterCoord;

    this->posStencilAlignHorzPrepare = pose.posStencilAlignHorzPrepare;
    this->posStencilAlignVertPrepare = pose.posStencilAlignVertPrepare;
    this->posStencilAlignCenterCoord = pose.posStencilAlignCenterCoord;

    this->posWaferCoarseAlignHorzPrepare = pose.posWaferCoarseAlignHorzPrepare;
    this->posWaferCoarseAlignVertPrepare = pose.posWaferCoarseAlignVertPrepare;
    this->posWaferCoarseAlignCenterCoord = pose.posWaferCoarseAlignCenterCoord;

    this->posWaferSwapRoughStage = pose.posWaferSwapRoughStage;

    this->posWaferLevelingRotatePrepare = pose.posWaferLevelingRotatePrepare;
}

SR_MotionPose::SR_MotionPose(const S_MotionPose &pose)
{
    this->posStencilSwapRoughMoveStage = pose.posStencilSwapRoughMoveStage;
    this->posStencilSwapVertStage = pose.posStencilSwapVertStage;
    this->posStencilSwapHorzStage = pose.posStencilSwapHorzStage;
    this->offsetStencilUpload = pose.offsetStencilUpload;

    this->posStencilLevelingHorzPrepare = pose.posStencilLevelingHorzPrepare;
    this->posStencilLevelingVertPrepare = pose.posStencilLevelingVertPrepare;
    this->posStencilLevelingCenterCoord = pose.posStencilLevelingCenterCoord;

    this->posWaferLevelingHorzPrepare = pose.posWaferLevelingHorzPrepare;
    this->posWaferLevelingVertPrepare = pose.posWaferLevelingVertPrepare;
    this->posWaferLevelingCenterCoord = pose.posWaferLevelingCenterCoord;

    this->posStencilAlignHorzPrepare = pose.posStencilAlignHorzPrepare;
    this->posStencilAlignVertPrepare = pose.posStencilAlignVertPrepare;
    this->posStencilAlignCenterCoord = pose.posStencilAlignCenterCoord;

    this->posWaferCoarseAlignHorzPrepare = pose.posWaferCoarseAlignHorzPrepare;
    this->posWaferCoarseAlignVertPrepare = pose.posWaferCoarseAlignVertPrepare;
    this->posWaferCoarseAlignCenterCoord = pose.posWaferCoarseAlignCenterCoord;

    this->posWaferSwapRoughStage = pose.posWaferSwapRoughStage;

    this->posWaferLevelingRotatePrepare = pose.posWaferLevelingRotatePrepare;
}

SR_MotionPose &SR_MotionPose::operator=(const SR_MotionPose &pose)
{
    this->posStencilSwapRoughMoveStage = pose.posStencilSwapRoughMoveStage;
    this->posStencilSwapVertStage = pose.posStencilSwapVertStage;
    this->posStencilSwapHorzStage = pose.posStencilSwapHorzStage;
    this->offsetStencilUpload = pose.offsetStencilUpload;

    this->posStencilLevelingHorzPrepare = pose.posStencilLevelingHorzPrepare;
    this->posStencilLevelingVertPrepare = pose.posStencilLevelingVertPrepare;
    this->posStencilLevelingCenterCoord = pose.posStencilLevelingCenterCoord;

    this->posWaferLevelingHorzPrepare = pose.posWaferLevelingHorzPrepare;
    this->posWaferLevelingVertPrepare = pose.posWaferLevelingVertPrepare;
    this->posWaferLevelingCenterCoord = pose.posWaferLevelingCenterCoord;

    this->posStencilAlignHorzPrepare = pose.posStencilAlignHorzPrepare;
    this->posStencilAlignVertPrepare = pose.posStencilAlignVertPrepare;
    this->posStencilAlignCenterCoord = pose.posStencilAlignCenterCoord;

    this->posWaferCoarseAlignHorzPrepare = pose.posWaferCoarseAlignHorzPrepare;
    this->posWaferCoarseAlignVertPrepare = pose.posWaferCoarseAlignVertPrepare;
    this->posWaferCoarseAlignCenterCoord = pose.posWaferCoarseAlignCenterCoord;

    this->posWaferSwapRoughStage = pose.posWaferSwapRoughStage;

    this->posWaferLevelingRotatePrepare = pose.posWaferLevelingRotatePrepare;
    return *this;
}

SR_MotionPose &SR_MotionPose::operator=(const S_MotionPose &pose)
{
    this->posStencilSwapRoughMoveStage = pose.posStencilSwapRoughMoveStage;
    this->posStencilSwapVertStage = pose.posStencilSwapVertStage;
    this->posStencilSwapHorzStage = pose.posStencilSwapHorzStage;
    this->offsetStencilUpload = pose.offsetStencilUpload;

    this->posStencilLevelingHorzPrepare = pose.posStencilLevelingHorzPrepare;
    this->posStencilLevelingVertPrepare = pose.posStencilLevelingVertPrepare;
    this->posStencilLevelingCenterCoord = pose.posStencilLevelingCenterCoord;

    this->posWaferLevelingHorzPrepare = pose.posWaferLevelingHorzPrepare;
    this->posWaferLevelingVertPrepare = pose.posWaferLevelingVertPrepare;
    this->posWaferLevelingCenterCoord = pose.posWaferLevelingCenterCoord;

    this->posStencilAlignHorzPrepare = pose.posStencilAlignHorzPrepare;
    this->posStencilAlignVertPrepare = pose.posStencilAlignVertPrepare;
    this->posStencilAlignCenterCoord = pose.posStencilAlignCenterCoord;

    this->posWaferCoarseAlignHorzPrepare = pose.posWaferCoarseAlignHorzPrepare;
    this->posWaferCoarseAlignVertPrepare = pose.posWaferCoarseAlignVertPrepare;
    this->posWaferCoarseAlignCenterCoord = pose.posWaferCoarseAlignCenterCoord;

    this->posWaferSwapRoughStage = pose.posWaferSwapRoughStage;

    this->posWaferLevelingRotatePrepare = pose.posWaferLevelingRotatePrepare;
    return *this;
}
