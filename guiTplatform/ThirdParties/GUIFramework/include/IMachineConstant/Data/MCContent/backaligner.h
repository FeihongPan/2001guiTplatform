#ifndef BACKALIGNER_H
#define BACKALIGNER_H

#include "GUIFramework_global.h"
#include "IMachineConstant/Data/STDConstant/std_constant_plcaxis.h"
#include "IMachineConstant/Data/STDConstant/std_constant_tf.h"
#include "Serializer/QSerializer"

class SR_BackAligner;

class GUIFRAMEWORK_EXPORT S_BackAligner : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE
    QS_OBJECT(S_STD_Constant_PlcAxis, xAxis)
    QS_OBJECT(S_STD_Constant_PlcAxis, yAxis)

public:
    S_BackAligner();
    S_BackAligner(const S_BackAligner &stage);
    S_BackAligner(const SR_BackAligner &stage);
    S_BackAligner &operator=(const S_BackAligner &stage);
    S_BackAligner &operator=(const SR_BackAligner &stage);
};

class GUIFRAMEWORK_EXPORT SR_BackAligner : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE
    QS_OBJECT(SR_STD_Constant_PlcAxis, xAxis)
    QS_OBJECT(SR_STD_Constant_PlcAxis, yAxis)

public:
    SR_BackAligner();
    SR_BackAligner(const SR_BackAligner &stage);
    SR_BackAligner(const S_BackAligner &stage);
    SR_BackAligner &operator=(const SR_BackAligner &stage);
    SR_BackAligner &operator=(const S_BackAligner &stage);
};

#endif // BACKALIGNER_H
