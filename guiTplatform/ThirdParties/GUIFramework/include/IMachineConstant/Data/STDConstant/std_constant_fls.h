#ifndef STD_CONSTANT_FLS_H
#define STD_CONSTANT_FLS_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

class SR_STD_Constant_FLS;

class GUIFRAMEWORK_EXPORT S_STD_Constant_FLS : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, samplingRate)
    QS_FIELD(int, ecpoTime)
    QS_FIELD(int, filterType)
    QS_FIELD(int, gain)
    QS_FIELD(double, scaling)
    QS_COLLECTION(QList, double, optAxisPos)
    QS_FIELD(double, zeroOffset)

public:
    S_STD_Constant_FLS();
    S_STD_Constant_FLS(const S_STD_Constant_FLS &instance);
    S_STD_Constant_FLS(const SR_STD_Constant_FLS &instance);
    S_STD_Constant_FLS &operator=(const S_STD_Constant_FLS &instance);
    S_STD_Constant_FLS &operator=(const SR_STD_Constant_FLS &instance);
};

class GUIFRAMEWORK_EXPORT SR_STD_Constant_FLS : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TDouble, samplingRate)
    QS_OBJECT(TInt, ecpoTime)
    QS_OBJECT(TInt, filterType)
    QS_OBJECT(TInt, gain)
    QS_OBJECT(TDouble, scaling)
    QS_COLLECTION_OBJECTS(QList, TDouble, optAxisPos)
    QS_OBJECT(TDouble, zeroOffset)

public:
    SR_STD_Constant_FLS();
    SR_STD_Constant_FLS(const S_STD_Constant_FLS &instance);
    SR_STD_Constant_FLS(const SR_STD_Constant_FLS &instance);
    SR_STD_Constant_FLS &operator=(const S_STD_Constant_FLS &instance);
    SR_STD_Constant_FLS &operator=(const SR_STD_Constant_FLS &instance);
};


#endif // STD_CONSTANT_FLS_H
