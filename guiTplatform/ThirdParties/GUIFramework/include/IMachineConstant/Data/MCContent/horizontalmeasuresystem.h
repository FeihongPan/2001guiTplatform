#ifndef HORIZONTALMEASURESYSTEM_H
#define HORIZONTALMEASURESYSTEM_H

#include "GUIFramework_global.h"
#include "IMachineConstant/Data/STDConstant/std_constant_cal.h"
#include "IMachineConstant/Data/STDConstant/std_constant_acsaxis.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

class SR_HMSys;

class GUIFRAMEWORK_EXPORT S_HMSys : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_STD_Constant_Cal, OAL)
    QS_OBJECT(S_STD_Constant_Cal, BAL)
    QS_OBJECT(S_STD_Constant_AcsAxis, BAL_xAxis)
    QS_OBJECT(S_STD_Constant_AcsAxis, BAL_yAxis)
    QS_OBJECT(S_STD_Constant_Cal, CAL)
    QS_OBJECT(S_STD_Constant_AcsAxis, CAL_xAxis)
    QS_OBJECT(S_STD_Constant_AcsAxis, CAL_yAxis)
    QS_OBJECT(S_STD_Constant_AcsAxis, CAL_zAxis)

public:
    S_HMSys();
    S_HMSys(const S_HMSys &instance);
    S_HMSys(const SR_HMSys &instance);
    S_HMSys &operator=(const S_HMSys &instance);
    S_HMSys &operator=(const SR_HMSys &instance);
};

class GUIFRAMEWORK_EXPORT SR_HMSys : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_STD_Constant_Cal, OAL)
    QS_OBJECT(SR_STD_Constant_Cal, BAL)
    QS_OBJECT(SR_STD_Constant_AcsAxis, BAL_xAxis)
    QS_OBJECT(SR_STD_Constant_AcsAxis, BAL_yAxis)
    QS_OBJECT(SR_STD_Constant_Cal, CAL)
    QS_OBJECT(SR_STD_Constant_AcsAxis, CAL_xAxis)
    QS_OBJECT(SR_STD_Constant_AcsAxis, CAL_yAxis)
    QS_OBJECT(SR_STD_Constant_AcsAxis, CAL_zAxis)

public:
    SR_HMSys();
    SR_HMSys(const S_HMSys &instance);
    SR_HMSys(const SR_HMSys &instance);
    SR_HMSys &operator=(const S_HMSys &instance);
    SR_HMSys &operator=(const SR_HMSys &instance);
};

#endif // HORIZONTALMEASURESYSTEM_H
