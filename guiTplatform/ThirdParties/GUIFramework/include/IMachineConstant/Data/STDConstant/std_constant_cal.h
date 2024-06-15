#ifndef STD_CONSTANT_CAL_H
#define STD_CONSTANT_CAL_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

class SR_STD_Constant_Cal_IntrinsicParams;

class GUIFRAMEWORK_EXPORT S_STD_Constant_Cal_IntrinsicParams : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, double, cameraMatrix)
    QS_COLLECTION(QList, double, DistortionCoeff)

public:
    S_STD_Constant_Cal_IntrinsicParams();
    S_STD_Constant_Cal_IntrinsicParams(const S_STD_Constant_Cal_IntrinsicParams &instance);
    S_STD_Constant_Cal_IntrinsicParams(const SR_STD_Constant_Cal_IntrinsicParams &instance);
    S_STD_Constant_Cal_IntrinsicParams &operator=(const S_STD_Constant_Cal_IntrinsicParams &instance);
    S_STD_Constant_Cal_IntrinsicParams &operator=(const SR_STD_Constant_Cal_IntrinsicParams &instance);
};

class GUIFRAMEWORK_EXPORT SR_STD_Constant_Cal_IntrinsicParams : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, TDouble, cameraMatrix)
    QS_COLLECTION_OBJECTS(QList, TDouble, DistortionCoeff)

public:
    SR_STD_Constant_Cal_IntrinsicParams();
    SR_STD_Constant_Cal_IntrinsicParams(const S_STD_Constant_Cal_IntrinsicParams &instance);
    SR_STD_Constant_Cal_IntrinsicParams(const SR_STD_Constant_Cal_IntrinsicParams &instance);
    SR_STD_Constant_Cal_IntrinsicParams &operator=(const S_STD_Constant_Cal_IntrinsicParams &instance);
    SR_STD_Constant_Cal_IntrinsicParams &operator=(const SR_STD_Constant_Cal_IntrinsicParams &instance);
};


class SR_STD_Constant_Cal_ExtrinsicParams;

class GUIFRAMEWORK_EXPORT S_STD_Constant_Cal_ExtrinsicParams : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, double, rotationVector)
    QS_COLLECTION(QList, double, translationVector)

public:
    S_STD_Constant_Cal_ExtrinsicParams();
    S_STD_Constant_Cal_ExtrinsicParams(const S_STD_Constant_Cal_ExtrinsicParams &instance);
    S_STD_Constant_Cal_ExtrinsicParams(const SR_STD_Constant_Cal_ExtrinsicParams &instance);
    S_STD_Constant_Cal_ExtrinsicParams &operator=(const S_STD_Constant_Cal_ExtrinsicParams &instance);
    S_STD_Constant_Cal_ExtrinsicParams &operator=(const SR_STD_Constant_Cal_ExtrinsicParams &instance);
};

class GUIFRAMEWORK_EXPORT SR_STD_Constant_Cal_ExtrinsicParams : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, TDouble, rotationVector)
    QS_COLLECTION_OBJECTS(QList, TDouble, translationVector)

public:
    SR_STD_Constant_Cal_ExtrinsicParams();
    SR_STD_Constant_Cal_ExtrinsicParams(const S_STD_Constant_Cal_ExtrinsicParams &instance);
    SR_STD_Constant_Cal_ExtrinsicParams(const SR_STD_Constant_Cal_ExtrinsicParams &instance);
    SR_STD_Constant_Cal_ExtrinsicParams &operator=(const S_STD_Constant_Cal_ExtrinsicParams &instance);
    SR_STD_Constant_Cal_ExtrinsicParams &operator=(const SR_STD_Constant_Cal_ExtrinsicParams &instance);
};


class SR_STD_Constant_Cal;

class GUIFRAMEWORK_EXPORT S_STD_Constant_Cal : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, double, fov)
    QS_FIELD(double, focus)
    QS_COLLECTION(QList, double, fovCenterPos)
    QS_OBJECT(S_STD_Constant_Cal_IntrinsicParams, intrinsicParams)
    QS_OBJECT(S_STD_Constant_Cal_ExtrinsicParams, extrinsicParams)

public:
    S_STD_Constant_Cal();
    S_STD_Constant_Cal(const S_STD_Constant_Cal &instance);
    S_STD_Constant_Cal(const SR_STD_Constant_Cal &instance);
    S_STD_Constant_Cal &operator=(const S_STD_Constant_Cal &instance);
    S_STD_Constant_Cal &operator=(const SR_STD_Constant_Cal &instance);
};

class GUIFRAMEWORK_EXPORT SR_STD_Constant_Cal : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, TDouble, fov)
    QS_OBJECT(TDouble, focus)
    QS_COLLECTION_OBJECTS(QList, TDouble, fovCenterPos)
    QS_OBJECT(S_STD_Constant_Cal_IntrinsicParams, intrinsicParams)
    QS_OBJECT(S_STD_Constant_Cal_ExtrinsicParams, extrinsicParams)

public:
    SR_STD_Constant_Cal();
    SR_STD_Constant_Cal(const S_STD_Constant_Cal &instance);
    SR_STD_Constant_Cal(const SR_STD_Constant_Cal &instance);
    SR_STD_Constant_Cal &operator=(const S_STD_Constant_Cal &instance);
    SR_STD_Constant_Cal &operator=(const SR_STD_Constant_Cal &instance);
};

#endif // STD_CONSTANT_CAL_H
