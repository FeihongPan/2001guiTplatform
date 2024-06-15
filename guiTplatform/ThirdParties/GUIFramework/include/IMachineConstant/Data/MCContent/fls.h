#ifndef FLS_H
#define FLS_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

class SR_FLSParameter;

class GUIFRAMEWORK_EXPORT S_FLSParameter : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(int, sensorId)
    QS_FIELD(int, sampleNumbers)
    QS_FIELD(double, gain)                // Deafault: 2
    QS_FIELD(double, exposureTime)       // Deafault: 0.5
    QS_FIELD(double, sampleFrequency)    // Deafault: 800

public:
    S_FLSParameter();
    S_FLSParameter(const S_FLSParameter &instance);
    S_FLSParameter(const SR_FLSParameter &instance);
    S_FLSParameter &operator=(const S_FLSParameter &instance);
    S_FLSParameter &operator=(const SR_FLSParameter &instance);
};

class GUIFRAMEWORK_EXPORT SR_FLSParameter : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TInt, sensorId)
    QS_OBJECT(TInt, sampleNumbers)
    QS_OBJECT(TDouble, gain)                // Deafault: 2
    QS_OBJECT(TDouble, exposureTime)       // Deafault: 0.5
    QS_OBJECT(TDouble, sampleFrequency)    // Deafault: 800

public:
    SR_FLSParameter();
    SR_FLSParameter(const S_FLSParameter &instance);
    SR_FLSParameter(const SR_FLSParameter &instance);
    SR_FLSParameter &operator=(const S_FLSParameter &instance);
    SR_FLSParameter &operator=(const SR_FLSParameter &instance);
};

class SR_FLS;

class S_FLS : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_FLSParameter, flsForMask)
    QS_OBJECT(S_FLSParameter, flsForWafer)

public:
    S_FLS();
    S_FLS(const S_FLS &instance);
    S_FLS(const SR_FLS &instance);
    S_FLS &operator=(const S_FLS &instance);
    S_FLS &operator=(const SR_FLS &instance);
};

class SR_FLS : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_FLSParameter, flsForMask)
    QS_OBJECT(SR_FLSParameter, flsForWafer)

public:
    SR_FLS();
    SR_FLS(const S_FLS &instance);
    SR_FLS(const SR_FLS &instance);
    SR_FLS &operator=(const S_FLS &instance);
    SR_FLS &operator=(const SR_FLS &instance);
};

#endif // FLS_H
