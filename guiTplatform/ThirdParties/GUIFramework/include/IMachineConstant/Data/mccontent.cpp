#include "mccontent.h"


S_MCContent::S_MCContent()
{

}

S_MCContent::S_MCContent(const S_MCContent &mcContent)
{
    this->scanningStage = mcContent.scanningStage;
    this->substrateStage = mcContent.substrateStage;
    this->stencilStage = mcContent.stencilStage;
    this->opticalLens = mcContent.opticalLens;
    this->illumination = mcContent.illumination;
    this->uvLamp = mcContent.uvLamp;
    this->hmSys = mcContent.hmSys;
    this->vmSys = mcContent.vmSys;
    this->stencilManagement = mcContent.stencilManagement;
    this->efem = mcContent.efem;
    this->environmentCtrl = mcContent.environmentCtrl;
    this->vibrationIsolation = mcContent.vibrationIsolation;
    this->timeSetting = mcContent.timeSetting;
    this->motionPose = mcContent.motionPose;
    this->fls = mcContent.fls;
    this->exposure = mcContent.exposure;
    this->leftBack = mcContent.leftBack;
    this->rightBack = mcContent.rightBack;
    this->ccdAxis = mcContent.ccdAxis;
    this->concentric = mcContent.concentric;
    this->maskTransfer = mcContent.maskTransfer;
    this->vision = mcContent.vision;
}

S_MCContent::S_MCContent(const SR_MCContent &mcContent)
{
    this->scanningStage = mcContent.scanningStage;
    this->substrateStage = mcContent.substrateStage;
    this->stencilStage = mcContent.stencilStage;
    this->opticalLens = mcContent.opticalLens;
    this->illumination = mcContent.illumination;
    this->uvLamp = mcContent.uvLamp;
    this->hmSys = mcContent.hmSys;
    this->vmSys = mcContent.vmSys;
    this->stencilManagement = mcContent.stencilManagement;
    this->efem = mcContent.efem;
    this->environmentCtrl = mcContent.environmentCtrl;
    this->vibrationIsolation = mcContent.vibrationIsolation;
    this->timeSetting = mcContent.timeSetting;
    this->motionPose = mcContent.motionPose;
    this->fls = mcContent.fls;
    this->exposure = mcContent.exposure;
    this->leftBack = mcContent.leftBack;
    this->rightBack = mcContent.rightBack;
    this->ccdAxis = mcContent.ccdAxis;
    this->concentric = mcContent.concentric;
    this->maskTransfer = mcContent.maskTransfer;
    this->vision = mcContent.vision;
}

S_MCContent &S_MCContent::operator=(const S_MCContent &mcContent)
{
    this->scanningStage = mcContent.scanningStage;
    this->substrateStage = mcContent.substrateStage;
    this->stencilStage = mcContent.stencilStage;
    this->opticalLens = mcContent.opticalLens;
    this->illumination = mcContent.illumination;
    this->uvLamp = mcContent.uvLamp;
    this->hmSys = mcContent.hmSys;
    this->vmSys = mcContent.vmSys;
    this->stencilManagement = mcContent.stencilManagement;
    this->efem = mcContent.efem;
    this->environmentCtrl = mcContent.environmentCtrl;
    this->vibrationIsolation = mcContent.vibrationIsolation;
    this->timeSetting = mcContent.timeSetting;
    this->motionPose = mcContent.motionPose;
    this->fls = mcContent.fls;
    this->exposure = mcContent.exposure;
    this->leftBack = mcContent.leftBack;
    this->rightBack = mcContent.rightBack;
    this->ccdAxis = mcContent.ccdAxis;
    this->concentric = mcContent.concentric;
    this->maskTransfer = mcContent.maskTransfer;
    this->vision = mcContent.vision;
    return *this;
}

S_MCContent &S_MCContent::operator=(const SR_MCContent &mcContent)
{
    this->scanningStage = mcContent.scanningStage;
    this->substrateStage = mcContent.substrateStage;
    this->stencilStage = mcContent.stencilStage;
    this->opticalLens = mcContent.opticalLens;
    this->illumination = mcContent.illumination;
    this->uvLamp = mcContent.uvLamp;
    this->hmSys = mcContent.hmSys;
    this->vmSys = mcContent.vmSys;
    this->stencilManagement = mcContent.stencilManagement;
    this->efem = mcContent.efem;
    this->environmentCtrl = mcContent.environmentCtrl;
    this->vibrationIsolation = mcContent.vibrationIsolation;
    this->timeSetting = mcContent.timeSetting;
    this->motionPose = mcContent.motionPose;
    this->fls = mcContent.fls;
    this->exposure = mcContent.exposure;
    this->leftBack = mcContent.leftBack;
    this->rightBack = mcContent.rightBack;
    this->ccdAxis = mcContent.ccdAxis;
    this->concentric = mcContent.concentric;
    this->maskTransfer = mcContent.maskTransfer;
    this->vision = mcContent.vision;
    return *this;
}

SR_MCContent::SR_MCContent()
{
    //    this->scanningStage.valueName = toStr(scanningStage);
    //    this->substrateStage.valueName = toStr(substrateStage);
    //    this->stencilStage.valueName = toStr(stencilStage);
    //    this->stencilTransfer.valueName = toStr(stencilTransfer);
    //    this->vmSubstrate.valueName = toStr(vmSubstrate);
    //    this->vmStencil.valueName = toStr(vmStencil);
    //    this->timeSetting.valueName = toStr(timeSetting);
}

SR_MCContent::SR_MCContent(const SR_MCContent &mcContent)
{
    this->scanningStage = mcContent.scanningStage;
    this->substrateStage = mcContent.substrateStage;
    this->stencilStage = mcContent.stencilStage;
    this->opticalLens = mcContent.opticalLens;
    this->illumination = mcContent.illumination;
    this->uvLamp = mcContent.uvLamp;
    this->hmSys = mcContent.hmSys;
    this->vmSys = mcContent.vmSys;
    this->stencilManagement = mcContent.stencilManagement;
    this->efem = mcContent.efem;
    this->environmentCtrl = mcContent.environmentCtrl;
    this->vibrationIsolation = mcContent.vibrationIsolation;
    this->timeSetting = mcContent.timeSetting;
    this->motionPose = mcContent.motionPose;
    this->fls = mcContent.fls;
    this->exposure = mcContent.exposure;
    this->leftBack = mcContent.leftBack;
    this->rightBack = mcContent.rightBack;
    this->ccdAxis = mcContent.ccdAxis;
    this->concentric = mcContent.concentric;
    this->maskTransfer = mcContent.maskTransfer;
    this->vision = mcContent.vision;
}

SR_MCContent::SR_MCContent(const S_MCContent &mcContent)
{
    this->scanningStage = mcContent.scanningStage;
    this->substrateStage = mcContent.substrateStage;
    this->stencilStage = mcContent.stencilStage;
    this->opticalLens = mcContent.opticalLens;
    this->illumination = mcContent.illumination;
    this->uvLamp = mcContent.uvLamp;
    this->hmSys = mcContent.hmSys;
    this->vmSys = mcContent.vmSys;
    this->stencilManagement = mcContent.stencilManagement;
    this->efem = mcContent.efem;
    this->environmentCtrl = mcContent.environmentCtrl;
    this->vibrationIsolation = mcContent.vibrationIsolation;
    this->timeSetting = mcContent.timeSetting;
    this->motionPose = mcContent.motionPose;
    this->fls = mcContent.fls;
    this->exposure = mcContent.exposure;
    this->leftBack = mcContent.leftBack;
    this->rightBack = mcContent.rightBack;
    this->ccdAxis = mcContent.ccdAxis;
    this->concentric = mcContent.concentric;
    this->maskTransfer = mcContent.maskTransfer;
    this->vision = mcContent.vision;
}

SR_MCContent &SR_MCContent::operator=(const SR_MCContent &mcContent)
{
    this->scanningStage = mcContent.scanningStage;
    this->substrateStage = mcContent.substrateStage;
    this->stencilStage = mcContent.stencilStage;
    this->opticalLens = mcContent.opticalLens;
    this->illumination = mcContent.illumination;
    this->uvLamp = mcContent.uvLamp;
    this->hmSys = mcContent.hmSys;
    this->vmSys = mcContent.vmSys;
    this->stencilManagement = mcContent.stencilManagement;
    this->efem = mcContent.efem;
    this->environmentCtrl = mcContent.environmentCtrl;
    this->vibrationIsolation = mcContent.vibrationIsolation;
    this->timeSetting = mcContent.timeSetting;
    this->motionPose = mcContent.motionPose;
    this->fls = mcContent.fls;
    this->exposure = mcContent.exposure;
    this->leftBack = mcContent.leftBack;
    this->rightBack = mcContent.rightBack;
    this->ccdAxis = mcContent.ccdAxis;
    this->concentric = mcContent.concentric;
    this->maskTransfer = mcContent.maskTransfer;
    this->vision = mcContent.vision;
    return *this;
}

SR_MCContent &SR_MCContent::operator=(const S_MCContent &mcContent)
{
    this->scanningStage = mcContent.scanningStage;
    this->substrateStage = mcContent.substrateStage;
    this->stencilStage = mcContent.stencilStage;
    this->opticalLens = mcContent.opticalLens;
    this->illumination = mcContent.illumination;
    this->uvLamp = mcContent.uvLamp;
    this->hmSys = mcContent.hmSys;
    this->vmSys = mcContent.vmSys;
    this->stencilManagement = mcContent.stencilManagement;
    this->efem = mcContent.efem;
    this->environmentCtrl = mcContent.environmentCtrl;
    this->vibrationIsolation = mcContent.vibrationIsolation;
    this->timeSetting = mcContent.timeSetting;
    this->motionPose = mcContent.motionPose;
    this->fls = mcContent.fls;
    this->exposure = mcContent.exposure;
    this->leftBack = mcContent.leftBack;
    this->rightBack = mcContent.rightBack;
    this->ccdAxis = mcContent.ccdAxis;
    this->concentric = mcContent.concentric;
    this->maskTransfer = mcContent.maskTransfer;
    this->vision = mcContent.vision;
    return *this;
}
