#ifndef MASKTRANFER_H
#define MASKTRANFER_H

#include "GUIFramework_global.h"
#include "IMachineConstant/Data/STDConstant/std_constant_plcaxis.h"
#include "IMachineConstant/Data/STDConstant/std_constant_tf.h"
#include "Serializer/QSerializer"

class SR_MaskTransfer;

class GUIFRAMEWORK_EXPORT S_MaskTransfer : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE
    QS_OBJECT(S_STD_Constant_PlcAxis, xAxis)
    QS_OBJECT(S_STD_Constant_PlcAxis, zAxis)

public:
    S_MaskTransfer();
    S_MaskTransfer(const S_MaskTransfer &stage);
    S_MaskTransfer(const SR_MaskTransfer &stage);
    S_MaskTransfer &operator=(const S_MaskTransfer &stage);
    S_MaskTransfer &operator=(const SR_MaskTransfer &stage);
};

class GUIFRAMEWORK_EXPORT SR_MaskTransfer : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE
    QS_OBJECT(SR_STD_Constant_PlcAxis, xAxis)
    QS_OBJECT(SR_STD_Constant_PlcAxis, zAxis)

public:
    SR_MaskTransfer();
    SR_MaskTransfer(const SR_MaskTransfer &stage);
    SR_MaskTransfer(const S_MaskTransfer &stage);
    SR_MaskTransfer &operator=(const SR_MaskTransfer &stage);
    SR_MaskTransfer &operator=(const S_MaskTransfer &stage);
};

#endif // MASKTRANFER_H
