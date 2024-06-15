#ifndef SUBSTRATESTAGE_H
#define SUBSTRATESTAGE_H

#include "GUIFramework_global.h"
#include "IMachineConstant/Data/STDConstant/std_constant_stage.h"
#include "IMachineConstant/Data/STDConstant/std_constant_tf.h"
#include "IMachineConstant/Data/STDConstant/std_constant_chunk.h"

#include "Serializer/QSerializer"

class SR_Fiducial;

class GUIFRAMEWORK_EXPORT S_Fiducial : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, double, center)
    QS_COLLECTION(QList, double, orthogonality)
    QS_COLLECTION(QList, double, pos)

public:
    S_Fiducial();
    S_Fiducial(const S_Fiducial &instance);
    S_Fiducial(const SR_Fiducial &instance);
    S_Fiducial &operator=(const S_Fiducial &instance);
    S_Fiducial &operator=(const SR_Fiducial &instance);
};

class GUIFRAMEWORK_EXPORT SR_Fiducial : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, TDouble, center)
    QS_COLLECTION_OBJECTS(QList, TDouble, orthogonality)
    QS_COLLECTION_OBJECTS(QList, TDouble, pos)

public:
    SR_Fiducial();
    SR_Fiducial(const S_Fiducial &instance);
    SR_Fiducial(const SR_Fiducial &instance);
    SR_Fiducial &operator=(const S_Fiducial &instance);
    SR_Fiducial &operator=(const SR_Fiducial &instance);
};


class SR_ESS;

class GUIFRAMEWORK_EXPORT S_ESS : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, double, center)

public:
    S_ESS();
    S_ESS(const S_ESS &instance);
    S_ESS(const SR_ESS &instance);
    S_ESS &operator=(const S_ESS &instance);
    S_ESS &operator=(const SR_ESS &instance);
};


class GUIFRAMEWORK_EXPORT SR_ESS : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, TDouble, center)

public:
    SR_ESS();
    SR_ESS(const S_ESS &instance);
    SR_ESS(const SR_ESS &instance);
    SR_ESS &operator=(const S_ESS &instance);
    SR_ESS &operator=(const SR_ESS &instance);
};


class SR_SubstrateStage;

class GUIFRAMEWORK_EXPORT S_SubstrateStage : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_STD_Constant_VStage, verticalStage)
    QS_OBJECT(S_STD_Constant_HStage, horizontalStage)
    QS_OBJECT(S_STD_Constant_AcsAxis, epin)
    QS_OBJECT(S_STD_Constant_AcsAxis, rz)
    QS_OBJECT(S_Fiducial, fiducial)
    QS_OBJECT(S_ESS, ESS)
    QS_OBJECT(S_STD_Constant_iCsTF, iCsTF)
    QS_OBJECT(S_STD_Constant_vCsTF, vCsTF)
    QS_OBJECT(S_STD_Constant_Chunk, chunk)
    QS_FIELD(QString, matrix)

public:
    S_SubstrateStage();
    S_SubstrateStage(const S_SubstrateStage &stage);
    S_SubstrateStage(const SR_SubstrateStage &stage);
    S_SubstrateStage &operator=(const S_SubstrateStage &stage);
    S_SubstrateStage &operator=(const SR_SubstrateStage &stage);
};

class GUIFRAMEWORK_EXPORT SR_SubstrateStage : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_STD_Constant_VStage, verticalStage)
    QS_OBJECT(SR_STD_Constant_HStage, horizontalStage)
    QS_OBJECT(SR_STD_Constant_AcsAxis, epin)
    QS_OBJECT(SR_STD_Constant_AcsAxis, rz)
    QS_OBJECT(SR_Fiducial, fiducial)
    QS_OBJECT(SR_ESS, ESS)
    QS_OBJECT(SR_STD_Constant_iCsTF, iCsTF)
    QS_OBJECT(SR_STD_Constant_vCsTF, vCsTF)
    QS_OBJECT(SR_STD_Constant_Chunk, chunk)
    QS_OBJECT(TString, matrix)

public:
    SR_SubstrateStage();
    SR_SubstrateStage(const SR_SubstrateStage &stage);
    SR_SubstrateStage(const S_SubstrateStage &stage);
    SR_SubstrateStage &operator=(const SR_SubstrateStage &stage);
    SR_SubstrateStage &operator=(const S_SubstrateStage &stage);
};

#endif // SUBSTRATESTAGE_H
