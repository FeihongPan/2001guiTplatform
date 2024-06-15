#ifndef OPTICALLENS_H
#define OPTICALLENS_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

class SR_OpticalLens;

class GUIFRAMEWORK_EXPORT S_OpticalLens : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, double, fieldSize)
    QS_FIELD(int, numberOfFields)
    QS_COLLECTION(QList, double, fieldCenter)
    QS_COLLECTION(QList, double, focus)

public:
    S_OpticalLens();
    S_OpticalLens(const S_OpticalLens &instance);
    S_OpticalLens(const SR_OpticalLens &instance);
    S_OpticalLens &operator=(const S_OpticalLens &instance);
    S_OpticalLens &operator=(const SR_OpticalLens &instance);
};

class GUIFRAMEWORK_EXPORT SR_OpticalLens : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, TDouble, fieldSize)
    QS_OBJECT(TInt, numberOfFields)
    QS_COLLECTION_OBJECTS(QList, TDouble, fieldCenter)
    QS_COLLECTION_OBJECTS(QList, TDouble, focus)

public:
    SR_OpticalLens();
    SR_OpticalLens(const S_OpticalLens &instance);
    SR_OpticalLens(const SR_OpticalLens &instance);
    SR_OpticalLens &operator=(const S_OpticalLens &instance);
    SR_OpticalLens &operator=(const SR_OpticalLens &instance);
};

#endif // OPTICALLENS_H
