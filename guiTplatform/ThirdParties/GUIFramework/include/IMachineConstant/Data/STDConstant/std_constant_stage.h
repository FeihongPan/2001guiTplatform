#ifndef STD_CONSTANT_STAGE_H
#define STD_CONSTANT_STAGE_H

#include "GUIFramework_global.h"
#include "IMachineConstant/Data/STDConstant/std_constant_acsaxis.h"
#include "Serializer/QSerializer"

class SR_STD_Constant_VStage;

class GUIFRAMEWORK_EXPORT S_STD_Constant_VStage : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_STD_Constant_AcsAxis, rxAxis)
    QS_OBJECT(S_STD_Constant_AcsAxis, ryAxis)
    QS_OBJECT(S_STD_Constant_AcsAxis, zAxis)
    QS_FIELD(QString, matrix)

public:
    S_STD_Constant_VStage();
    S_STD_Constant_VStage(const S_STD_Constant_VStage &stage);
    S_STD_Constant_VStage(const SR_STD_Constant_VStage &stage);
    S_STD_Constant_VStage &operator=(const S_STD_Constant_VStage &stage);
    S_STD_Constant_VStage &operator=(const SR_STD_Constant_VStage &stage);
};

class GUIFRAMEWORK_EXPORT SR_STD_Constant_VStage : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_STD_Constant_AcsAxis, rxAxis)
    QS_OBJECT(SR_STD_Constant_AcsAxis, ryAxis)
    QS_OBJECT(SR_STD_Constant_AcsAxis, zAxis)
    QS_OBJECT(TString, matrix)

public:
    SR_STD_Constant_VStage();
    SR_STD_Constant_VStage(const SR_STD_Constant_VStage &stage);
    SR_STD_Constant_VStage(const S_STD_Constant_VStage &stage);
    SR_STD_Constant_VStage &operator=(const SR_STD_Constant_VStage &stage);
    SR_STD_Constant_VStage &operator=(const S_STD_Constant_VStage &stage);
};


class SR_STD_Constant_HStage;

class GUIFRAMEWORK_EXPORT S_STD_Constant_HStage : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_STD_Constant_AcsAxis, xAxis)
    QS_OBJECT(S_STD_Constant_AcsAxis, yAxis)
    QS_OBJECT(S_STD_Constant_AcsAxis, rzAxis)
    QS_FIELD(QString, matrix)

public:
    S_STD_Constant_HStage();
    S_STD_Constant_HStage(const S_STD_Constant_HStage &stage);
    S_STD_Constant_HStage(const SR_STD_Constant_HStage &stage);
    S_STD_Constant_HStage &operator=(const S_STD_Constant_HStage &stage);
    S_STD_Constant_HStage &operator=(const SR_STD_Constant_HStage &stage);
};

class GUIFRAMEWORK_EXPORT SR_STD_Constant_HStage : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_STD_Constant_AcsAxis, xAxis)
    QS_OBJECT(SR_STD_Constant_AcsAxis, yAxis)
    QS_OBJECT(SR_STD_Constant_AcsAxis, rzAxis)
    QS_OBJECT(TString, matrix)

public:
    SR_STD_Constant_HStage();
    SR_STD_Constant_HStage(const SR_STD_Constant_HStage &stage);
    SR_STD_Constant_HStage(const S_STD_Constant_HStage &stage);
    SR_STD_Constant_HStage &operator=(const SR_STD_Constant_HStage &stage);
    SR_STD_Constant_HStage &operator=(const S_STD_Constant_HStage &stage);
};

#endif // STD_CONSTANT_STAGE_H
