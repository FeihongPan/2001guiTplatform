#ifndef CONCENTRIC_H
#define CONCENTRIC_H

#include "GUIFramework_global.h"
#include "IMachineConstant/Data/STDConstant/std_constant_plcaxis.h"
#include "IMachineConstant/Data/STDConstant/std_constant_tf.h"
#include "Serializer/QSerializer"

class SR_Concentric;

class GUIFRAMEWORK_EXPORT S_Concentric : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE
    QS_OBJECT(S_STD_Constant_PlcAxis, xAxis)
    QS_OBJECT(S_STD_Constant_PlcAxis, yAxis)
    QS_OBJECT(S_STD_Constant_PlcAxis, zAxis)

public:
    S_Concentric();
    S_Concentric(const S_Concentric &stage);
    S_Concentric(const SR_Concentric &stage);
    S_Concentric &operator=(const S_Concentric &stage);
    S_Concentric &operator=(const SR_Concentric &stage);
};

class GUIFRAMEWORK_EXPORT SR_Concentric : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE
    QS_OBJECT(SR_STD_Constant_PlcAxis, xAxis)
    QS_OBJECT(SR_STD_Constant_PlcAxis, yAxis)
    QS_OBJECT(SR_STD_Constant_PlcAxis, zAxis)

public:
    SR_Concentric();
    SR_Concentric(const SR_Concentric &stage);
    SR_Concentric(const S_Concentric &stage);
    SR_Concentric &operator=(const SR_Concentric &stage);
    SR_Concentric &operator=(const S_Concentric &stage);
};

#endif // CONCENTRIC_H
