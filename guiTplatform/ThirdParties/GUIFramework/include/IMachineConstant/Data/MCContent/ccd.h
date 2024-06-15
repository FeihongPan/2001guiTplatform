#ifndef CCD_H
#define CCD_H

#include "GUIFramework_global.h"
#include "IMachineConstant/Data/STDConstant/std_constant_plcaxis.h"
#include "IMachineConstant/Data/STDConstant/std_constant_tf.h"
#include "Serializer/QSerializer"

class SR_CCD;

class GUIFRAMEWORK_EXPORT S_CCD : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE
    QS_OBJECT(S_STD_Constant_PlcAxis, yAxis)

public:
    S_CCD();
    S_CCD(const S_CCD &stage);
    S_CCD(const SR_CCD &stage);
    S_CCD &operator=(const S_CCD &stage);
    S_CCD &operator=(const SR_CCD &stage);
};

class GUIFRAMEWORK_EXPORT SR_CCD : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE
    QS_OBJECT(SR_STD_Constant_PlcAxis, yAxis)

public:
    SR_CCD();
    SR_CCD(const SR_CCD &stage);
    SR_CCD(const S_CCD &stage);
    SR_CCD &operator=(const SR_CCD &stage);
    SR_CCD &operator=(const S_CCD &stage);
};

#endif // CCD_H
