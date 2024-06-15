#ifndef UVLAMP_H
#define UVLAMP_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

class SR_LampSpec;

class GUIFRAMEWORK_EXPORT S_LampSpec : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, power)
    QS_FIELD(double, life)

public:
    S_LampSpec();
    S_LampSpec(const S_LampSpec &instance);
    S_LampSpec(const SR_LampSpec &instance);
    S_LampSpec &operator=(const S_LampSpec &instance);
    S_LampSpec &operator=(const SR_LampSpec &instance);
};

class GUIFRAMEWORK_EXPORT SR_LampSpec : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TDouble, power)
    QS_OBJECT(TDouble, life)

public:
    SR_LampSpec();
    SR_LampSpec(const S_LampSpec &instance);
    SR_LampSpec(const SR_LampSpec &instance);
    SR_LampSpec &operator=(const S_LampSpec &instance);
    SR_LampSpec &operator=(const SR_LampSpec &instance);
};


class SR_Interlock;

class GUIFRAMEWORK_EXPORT S_Interlock : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, CDAWngLmt)
    QS_FIELD(double, CDAErrLmt)
    QS_FIELD(double, TempWngLmt)
    QS_FIELD(double, TempErrLmt)

public:
    S_Interlock();
    S_Interlock(const S_Interlock &instance);
    S_Interlock(const SR_Interlock &instance);
    S_Interlock &operator=(const S_Interlock &instance);
    S_Interlock &operator=(const SR_Interlock &instance);
};

class GUIFRAMEWORK_EXPORT SR_Interlock : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TDouble, CDAWngLmt)
    QS_OBJECT(TDouble, CDAErrLmt)
    QS_OBJECT(TDouble, TempWngLmt)
    QS_OBJECT(TDouble, TempErrLmt)

public:
    SR_Interlock();
    SR_Interlock(const S_Interlock &instance);
    SR_Interlock(const SR_Interlock &instance);
    SR_Interlock &operator=(const S_Interlock &instance);
    SR_Interlock &operator=(const SR_Interlock &instance);
};


class SR_UVLamp;

class GUIFRAMEWORK_EXPORT S_UVLamp : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_LampSpec, lampSpec)
    QS_OBJECT(S_Interlock, interlock)

public:
    S_UVLamp();
    S_UVLamp(const S_UVLamp &instance);
    S_UVLamp(const SR_UVLamp &instance);
    S_UVLamp &operator=(const S_UVLamp &instance);
    S_UVLamp &operator=(const SR_UVLamp &instance);
};

class GUIFRAMEWORK_EXPORT SR_UVLamp : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_LampSpec, lampSpec)
    QS_OBJECT(SR_Interlock, interlock)

public:
    SR_UVLamp();
    SR_UVLamp(const S_UVLamp &instance);
    SR_UVLamp(const SR_UVLamp &instance);
    SR_UVLamp &operator=(const S_UVLamp &instance);
    SR_UVLamp &operator=(const SR_UVLamp &instance);
};

#endif // UVLAMP_H
