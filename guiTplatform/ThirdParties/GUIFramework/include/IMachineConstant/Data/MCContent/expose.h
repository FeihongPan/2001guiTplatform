#ifndef EXPOSE_H
#define EXPOSE_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

class SR_Expose;

class GUIFRAMEWORK_EXPORT S_Expose : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, power)

public:
    S_Expose();
    S_Expose(const S_Expose &instance);
    S_Expose(const SR_Expose &instance);
    S_Expose &operator=(const S_Expose &instance);
    S_Expose &operator=(const SR_Expose &instance);
};

class GUIFRAMEWORK_EXPORT SR_Expose : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TDouble, power)

public:
    SR_Expose();
    SR_Expose(const S_Expose &instance);
    SR_Expose(const SR_Expose &instance);
    SR_Expose &operator=(const S_Expose &instance);
    SR_Expose &operator=(const SR_Expose &instance);
};

#endif // EXPOSE_H
