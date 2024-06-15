#ifndef EFEM_H
#define EFEM_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "IMachineConstant/Data/STDConstant/std_constant_acsaxis.h"
#include "Serializer/QSerializer"

class SR_Robot;

class GUIFRAMEWORK_EXPORT S_Robot : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_STD_Constant_AcsAxis, zAxis)
    QS_OBJECT(S_STD_Constant_AcsAxis, rAxis)
    QS_OBJECT(S_STD_Constant_AcsAxis, thetaAxis)

public:
    S_Robot();
    S_Robot(const S_Robot &instance);
    S_Robot(const SR_Robot &instance);
    S_Robot &operator=(const S_Robot &instance);
    S_Robot &operator=(const SR_Robot &instance);
};

class GUIFRAMEWORK_EXPORT SR_Robot : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_STD_Constant_AcsAxis, zAxis)
    QS_OBJECT(SR_STD_Constant_AcsAxis, rAxis)
    QS_OBJECT(SR_STD_Constant_AcsAxis, thetaAxis)

public:
    SR_Robot();
    SR_Robot(const S_Robot &instance);
    SR_Robot(const SR_Robot &instance);
    SR_Robot &operator=(const S_Robot &instance);
    SR_Robot &operator=(const SR_Robot &instance);
};


class SR_PreAlgner;

class S_PreAlgner : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_STD_Constant_AcsAxis, zAxis)
    QS_OBJECT(S_STD_Constant_AcsAxis, thetaAxis)

public:
    S_PreAlgner();
    S_PreAlgner(const S_PreAlgner &instance);
    S_PreAlgner(const SR_PreAlgner &instance);
    S_PreAlgner &operator=(const S_PreAlgner &instance);
    S_PreAlgner &operator=(const SR_PreAlgner &instance);
};

class SR_PreAlgner : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_STD_Constant_AcsAxis, zAxis)
    QS_OBJECT(S_STD_Constant_AcsAxis, thetaAxis)

public:
    SR_PreAlgner();
    SR_PreAlgner(const S_PreAlgner &instance);
    SR_PreAlgner(const SR_PreAlgner &instance);
    SR_PreAlgner &operator=(const S_PreAlgner &instance);
    SR_PreAlgner &operator=(const SR_PreAlgner &instance);
};

class SR_LoadPort;

class S_LoadPort : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

public:
    S_LoadPort();
    S_LoadPort(const S_LoadPort &instance);
    S_LoadPort(const SR_LoadPort &instance);
    S_LoadPort &operator=(const S_LoadPort &instance);
    S_LoadPort &operator=(const SR_LoadPort &instance);
};

class SR_LoadPort : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

public:
    SR_LoadPort();
    SR_LoadPort(const S_LoadPort &instance);
    SR_LoadPort(const SR_LoadPort &instance);
    SR_LoadPort &operator=(const S_LoadPort &instance);
    SR_LoadPort &operator=(const SR_LoadPort &instance);
};


class SR_EFEM;

class S_EFEM : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_Robot, robot)
    QS_OBJECT(S_PreAlgner, preAligner)
    QS_OBJECT(S_LoadPort, loadport)

public:
    S_EFEM();
    S_EFEM(const S_EFEM &instance);
    S_EFEM(const SR_EFEM &instance);
    S_EFEM &operator=(const S_EFEM &instance);
    S_EFEM &operator=(const SR_EFEM &instance);
};

class SR_EFEM : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_Robot, robot)
    QS_OBJECT(SR_PreAlgner, preAligner)
    QS_OBJECT(SR_LoadPort, loadport)

public:
    SR_EFEM();
    SR_EFEM(const S_EFEM &instance);
    SR_EFEM(const SR_EFEM &instance);
    SR_EFEM &operator=(const S_EFEM &instance);
    SR_EFEM &operator=(const SR_EFEM &instance);
};

#endif // EFEM_H
