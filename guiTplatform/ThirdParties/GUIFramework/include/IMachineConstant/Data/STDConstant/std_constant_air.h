#ifndef STD_CONSTANT_AIR_H
#define STD_CONSTANT_AIR_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

class SR_STD_Constant_Air;

class GUIFRAMEWORK_EXPORT S_STD_Constant_Air : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, double, CDAWngLmt)
    QS_COLLECTION(QList, double, CDAErrLmt)
    QS_COLLECTION(QList, double, VACWngLmt)
    QS_COLLECTION(QList, double, VACErrLmt)

public:
    S_STD_Constant_Air();
    S_STD_Constant_Air(const S_STD_Constant_Air &air);
    S_STD_Constant_Air(const SR_STD_Constant_Air &air);
    S_STD_Constant_Air &operator=(const S_STD_Constant_Air &air);
    S_STD_Constant_Air &operator=(const SR_STD_Constant_Air &air);
};

class GUIFRAMEWORK_EXPORT SR_STD_Constant_Air : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, TDouble, CDAWngLmt)
    QS_COLLECTION_OBJECTS(QList, TDouble, CDAErrLmt)
    QS_COLLECTION_OBJECTS(QList, TDouble, VACWngLmt)
    QS_COLLECTION_OBJECTS(QList, TDouble, VACErrLmt)

public:
    SR_STD_Constant_Air();
    SR_STD_Constant_Air(const S_STD_Constant_Air &air);
    SR_STD_Constant_Air(const SR_STD_Constant_Air &air);
    SR_STD_Constant_Air &operator=(const S_STD_Constant_Air &air);
    SR_STD_Constant_Air &operator=(const SR_STD_Constant_Air &air);
};

#endif // STD_CONSTANT_AIR_H
