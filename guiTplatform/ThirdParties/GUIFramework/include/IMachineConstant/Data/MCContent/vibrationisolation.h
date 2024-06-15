#ifndef VIBRATIONISOLATION_H
#define VIBRATIONISOLATION_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

class SR_VibrationIsolation;

class GUIFRAMEWORK_EXPORT S_VibrationIsolation : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, stableSignalSampleRate)

public:
    S_VibrationIsolation();
    S_VibrationIsolation(const S_VibrationIsolation &instance);
    S_VibrationIsolation(const SR_VibrationIsolation &instance);
    S_VibrationIsolation &operator=(const S_VibrationIsolation &instance);
    S_VibrationIsolation &operator=(const SR_VibrationIsolation &instance);
};

class GUIFRAMEWORK_EXPORT SR_VibrationIsolation : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TDouble, stableSignalSampleRate)

public:
    SR_VibrationIsolation();
    SR_VibrationIsolation(const S_VibrationIsolation &instance);
    SR_VibrationIsolation(const SR_VibrationIsolation &instance);
    SR_VibrationIsolation &operator=(const S_VibrationIsolation &instance);
    SR_VibrationIsolation &operator=(const SR_VibrationIsolation &instance);
};

#endif // VIBRATIONISOLATION_H
