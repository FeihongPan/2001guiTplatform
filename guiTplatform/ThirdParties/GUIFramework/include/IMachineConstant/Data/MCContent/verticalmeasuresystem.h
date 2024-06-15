#ifndef VERTICALMEASURESYSTEM_H
#define VERTICALMEASURESYSTEM_H

#include "GUIFramework_global.h"
#include "IMachineConstant/Data/STDConstant/std_constant_fls.h"
#include "Serializer/QSerializer"

class SR_VMSys;

class GUIFRAMEWORK_EXPORT S_VMSys : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_STD_Constant_FLS, vmSubstrate);
    QS_OBJECT(S_STD_Constant_FLS, vmStencil);

public:
    S_VMSys();
    S_VMSys(const S_VMSys &vms);
    S_VMSys(const SR_VMSys &vms);
    S_VMSys &operator=(const S_VMSys &vms);
    S_VMSys &operator=(const SR_VMSys &vms);
};

class GUIFRAMEWORK_EXPORT SR_VMSys : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_STD_Constant_FLS, vmSubstrate);
    QS_OBJECT(SR_STD_Constant_FLS, vmStencil);

public:
    SR_VMSys();
    SR_VMSys(const SR_VMSys &vms);
    SR_VMSys(const S_VMSys &vms);
    SR_VMSys &operator=(const SR_VMSys &vms);
    SR_VMSys &operator=(const S_VMSys &vms);
};

#endif // VERTICALMEASURESYSTEM_H
