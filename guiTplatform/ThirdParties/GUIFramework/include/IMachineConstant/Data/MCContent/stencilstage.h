#ifndef STENCILSTAGE_H
#define STENCILSTAGE_H

#include "GUIFramework_global.h"
#include "IMachineConstant/Data/STDConstant/std_constant_stage.h"
#include "IMachineConstant/Data/STDConstant/std_constant_tf.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

class GUIFRAMEWORK_EXPORT SR_StencilStage;

class S_StencilStage : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_STD_Constant_VStage, verticalStage)
    QS_OBJECT(S_STD_Constant_HStage, horizontalStage)
    QS_OBJECT(S_STD_Constant_iCsTF, iCsTF)
    QS_OBJECT(S_STD_Constant_vCsTF, vCsTF)

public:
    S_StencilStage();
    S_StencilStage(const S_StencilStage &instance);
    S_StencilStage(const SR_StencilStage &instance);
    S_StencilStage &operator=(const S_StencilStage &instance);
    S_StencilStage &operator=(const SR_StencilStage &instance);
};

class GUIFRAMEWORK_EXPORT SR_StencilStage : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_STD_Constant_VStage, verticalStage)
    QS_OBJECT(SR_STD_Constant_HStage, horizontalStage)
    QS_OBJECT(SR_STD_Constant_iCsTF, iCsTF)
    QS_OBJECT(SR_STD_Constant_vCsTF, vCsTF)

public:
    SR_StencilStage();
    SR_StencilStage(const S_StencilStage &instance);
    SR_StencilStage(const SR_StencilStage &instance);
    SR_StencilStage &operator=(const S_StencilStage &instance);
    SR_StencilStage &operator=(const SR_StencilStage &instance);
};

#endif // STENCILSTAGE_H
