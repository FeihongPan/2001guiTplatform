#ifndef STD_CONSTANT_TF_H
#define STD_CONSTANT_TF_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

class SR_STD_Constant_iCsTF;

class GUIFRAMEWORK_EXPORT S_STD_Constant_iCsTF : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, double, origin)
    QS_COLLECTION(QList, double, orthogonality)

public:
    S_STD_Constant_iCsTF();
    S_STD_Constant_iCsTF(const S_STD_Constant_iCsTF &instance);
    S_STD_Constant_iCsTF(const SR_STD_Constant_iCsTF &instance);
    S_STD_Constant_iCsTF &operator=(const S_STD_Constant_iCsTF &instance);
    S_STD_Constant_iCsTF &operator=(const SR_STD_Constant_iCsTF &instance);
};

class GUIFRAMEWORK_EXPORT SR_STD_Constant_iCsTF : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, TDouble, origin)
    QS_COLLECTION_OBJECTS(QList, TDouble, orthogonality)

public:
    SR_STD_Constant_iCsTF();
    SR_STD_Constant_iCsTF(const S_STD_Constant_iCsTF &instance);
    SR_STD_Constant_iCsTF(const SR_STD_Constant_iCsTF &instance);
    SR_STD_Constant_iCsTF &operator=(const S_STD_Constant_iCsTF &instance);
    SR_STD_Constant_iCsTF &operator=(const SR_STD_Constant_iCsTF &instance);
};


class SR_STD_Constant_vCsTF;

class GUIFRAMEWORK_EXPORT S_STD_Constant_vCsTF : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, double, tfMatrix)

public:
    S_STD_Constant_vCsTF();
    S_STD_Constant_vCsTF(const S_STD_Constant_vCsTF &instance);
    S_STD_Constant_vCsTF(const SR_STD_Constant_vCsTF &instance);
    S_STD_Constant_vCsTF &operator=(const S_STD_Constant_vCsTF &instance);
    S_STD_Constant_vCsTF &operator=(const SR_STD_Constant_vCsTF &instance);
};

class GUIFRAMEWORK_EXPORT SR_STD_Constant_vCsTF : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, TDouble, tfMatrix)

public:
    SR_STD_Constant_vCsTF();
    SR_STD_Constant_vCsTF(const S_STD_Constant_vCsTF &instance);
    SR_STD_Constant_vCsTF(const SR_STD_Constant_vCsTF &instance);
    SR_STD_Constant_vCsTF &operator=(const S_STD_Constant_vCsTF &instance);
    SR_STD_Constant_vCsTF &operator=(const SR_STD_Constant_vCsTF &instance);
};

#endif // STD_CONSTANT_TF_H
