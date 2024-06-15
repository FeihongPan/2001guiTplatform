#ifndef ILSYS_H
#define ILSYS_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "IMachineConstant/Data/STDConstant/std_constant_acsaxis.h"
#include "Serializer/QSerializer"

class SR_Illumination;

class GUIFRAMEWORK_EXPORT S_Illumination : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, double, intensityOffset)
    QS_OBJECT(S_STD_Constant_ScaleAxis, shutter)
    QS_OBJECT(S_STD_Constant_ScaleAxis, filter)
    QS_OBJECT(S_STD_Constant_ScaleAxis, VA)

public:
    S_Illumination();
    S_Illumination(const S_Illumination &instance);
    S_Illumination(const SR_Illumination &instance);
    S_Illumination &operator=(const S_Illumination &instance);
    S_Illumination &operator=(const SR_Illumination &instance);
};

class GUIFRAMEWORK_EXPORT SR_Illumination : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, TDouble, intensityOffset)
    QS_OBJECT(SR_STD_Constant_ScaleAxis, shutter)
    QS_OBJECT(SR_STD_Constant_ScaleAxis, filter)
    QS_OBJECT(SR_STD_Constant_ScaleAxis, VA)

public:
    SR_Illumination();
    SR_Illumination(const S_Illumination &instance);
    SR_Illumination(const SR_Illumination &instance);
    SR_Illumination &operator=(const S_Illumination &instance);
    SR_Illumination &operator=(const SR_Illumination &instance);
};

#endif // ILSYS_H
