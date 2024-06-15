#ifndef MCCONTENT_H
#define MCCONTENT_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "IMachineConstant/Data/MCContent/vision.h"
#include "IMachineConstant/Data/MCContent/scanningstage.h"
#include "IMachineConstant/Data/MCContent/substratestage.h"
#include "IMachineConstant/Data/MCContent/stencilstage.h"
#include "IMachineConstant/Data/MCContent/opticallens.h"
#include "IMachineConstant/Data/MCContent/ilsys.h"
#include "IMachineConstant/Data/MCContent/uvlamp.h"
#include "IMachineConstant/Data/MCContent/horizontalmeasuresystem.h"
#include "IMachineConstant/Data/MCContent/verticalmeasuresystem.h"
#include "IMachineConstant/Data/MCContent/efem.h"
#include "IMachineConstant/Data/MCContent/environmentctrl.h"
#include "IMachineConstant/Data/MCContent/vibrationisolation.h"

#include "IMachineConstant/Data/MCContent/timesetting.h"
#include "IMachineConstant/Data/MCContent/verticalmeasuresystem.h"
#include "IMachineConstant/Data/MCContent/stenciltransfer.h"
#include "IMachineConstant/Data/STDConstant/std_constant_stage.h"
#include "IMachineConstant/Data/MCContent/motionpose.h"
#include "IMachineConstant/Data/MCContent/fls.h"
#include "IMachineConstant/Data/MCContent/expose.h"
#include "IMachineConstant/Data/MCContent/backaligner.h"
#include "IMachineConstant/Data/MCContent/ccd.h"
#include "IMachineConstant/Data/MCContent/concentric.h"
#include "IMachineConstant/Data/MCContent/masktransfer.h"
#include "Serializer/QSerializer"

class SR_MCContent;

class GUIFRAMEWORK_EXPORT S_MCContent : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_ScanningStage, scanningStage)
    QS_OBJECT(S_SubstrateStage, substrateStage)
    QS_OBJECT(S_StencilStage, stencilStage)
    QS_OBJECT(S_OpticalLens, opticalLens)
    QS_OBJECT(S_Illumination, illumination)
    QS_OBJECT(S_UVLamp, uvLamp)
    QS_OBJECT(S_HMSys, hmSys)
    QS_OBJECT(S_VMSys, vmSys)
    QS_OBJECT(S_StencilManagement, stencilManagement)
    QS_OBJECT(S_EFEM, efem)
    QS_OBJECT(S_EnvironmentCtrl, environmentCtrl)
    QS_OBJECT(S_VibrationIsolation, vibrationIsolation)
    QS_OBJECT(S_TimeSetting, timeSetting)
    QS_OBJECT(S_MotionPose, motionPose)
    QS_OBJECT(S_FLS, fls)
    QS_OBJECT(S_Expose, exposure)
    QS_OBJECT(S_BackAligner, leftBack)
    QS_OBJECT(S_BackAligner, rightBack)
    QS_OBJECT(S_CCD, ccdAxis)
    QS_OBJECT(S_Concentric, concentric)
    QS_OBJECT(S_MaskTransfer, maskTransfer)
    QS_OBJECT(S_Vision, vision)

public:
    S_MCContent();
    S_MCContent(const S_MCContent &mcContent);
    S_MCContent(const SR_MCContent &mcContent);
    S_MCContent &operator=(const S_MCContent &mcContent);
    S_MCContent &operator=(const SR_MCContent &mcContent);
};

class GUIFRAMEWORK_EXPORT SR_MCContent : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_ScanningStage, scanningStage)
    QS_OBJECT(SR_SubstrateStage, substrateStage)
    QS_OBJECT(SR_StencilStage, stencilStage)
    QS_OBJECT(SR_OpticalLens, opticalLens)
    QS_OBJECT(SR_Illumination, illumination)
    QS_OBJECT(SR_UVLamp, uvLamp)
    QS_OBJECT(SR_HMSys, hmSys)
    QS_OBJECT(SR_VMSys, vmSys)
    QS_OBJECT(SR_StencilManagement, stencilManagement)
    QS_OBJECT(SR_EFEM, efem)
    QS_OBJECT(SR_EnvironmentCtrl, environmentCtrl)
    QS_OBJECT(SR_VibrationIsolation, vibrationIsolation)
    QS_OBJECT(SR_TimeSetting, timeSetting)
    QS_OBJECT(SR_MotionPose, motionPose)
    QS_OBJECT(SR_FLS, fls)
    QS_OBJECT(SR_Expose, exposure)
    QS_OBJECT(SR_BackAligner, leftBack)
    QS_OBJECT(SR_BackAligner, rightBack)
    QS_OBJECT(SR_CCD, ccdAxis)
    QS_OBJECT(SR_Concentric, concentric)
    QS_OBJECT(SR_MaskTransfer, maskTransfer)
    QS_OBJECT(SR_Vision, vision)

public:
    SR_MCContent();
    SR_MCContent(const SR_MCContent &mcContent);
    SR_MCContent(const S_MCContent &mcContent);
    SR_MCContent &operator=(const SR_MCContent &mcContent);
    SR_MCContent &operator=(const S_MCContent &mcContent);
};

#endif // MCCONTENT_H
