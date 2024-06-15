#ifndef STD_CONSTANT_ACSAXIS_H
#define STD_CONSTANT_ACSAXIS_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "BasicValue/serializablelist.h"
#include "IMachineConstant/Data/STDConstant/std_constant_air.h"
#include "Serializer/QSerializer"

class SR_STD_Constant_AcsAxis;

class GUIFRAMEWORK_EXPORT S_STD_Constant_AcsAxis : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, vel)
    QS_FIELD(double, acc)
    QS_FIELD(double, dec)
    QS_FIELD(double, jerk)
    QS_FIELD(double, trajectory)
    QS_FIELD(double, homeOffset)
    QS_COLLECTION(QList, double, swLimit)
    QS_COLLECTION(QList, double, dynLimit)
    QS_FIELD(double, MntMotionLmt)

public:
    S_STD_Constant_AcsAxis();
    S_STD_Constant_AcsAxis(const S_STD_Constant_AcsAxis &axis);
    S_STD_Constant_AcsAxis(const SR_STD_Constant_AcsAxis &axis);
    S_STD_Constant_AcsAxis &operator=(const S_STD_Constant_AcsAxis &axis);
    S_STD_Constant_AcsAxis &operator=(const SR_STD_Constant_AcsAxis &axis);
};

class GUIFRAMEWORK_EXPORT SR_STD_Constant_AcsAxis : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TDouble, vel)
    QS_OBJECT(TDouble, acc)
    QS_OBJECT(TDouble, dec)
    QS_OBJECT(TDouble, jerk)
    QS_OBJECT(TDouble, trajectory)
    QS_OBJECT(TDouble, homeOffset)
    QS_COLLECTION_OBJECTS(QList, TDouble, swLimit)
    QS_COLLECTION_OBJECTS(QList, TDouble, dynLimit)
    QS_OBJECT(TDouble, MntMotionLmt)

public:
    SR_STD_Constant_AcsAxis();
    SR_STD_Constant_AcsAxis(const SR_STD_Constant_AcsAxis &axis);
    SR_STD_Constant_AcsAxis(const S_STD_Constant_AcsAxis &axis);
    SR_STD_Constant_AcsAxis &operator=(const SR_STD_Constant_AcsAxis &axis);
    SR_STD_Constant_AcsAxis &operator=(const S_STD_Constant_AcsAxis &axis);
};


class SR_STD_Constant_AirAxis;

class GUIFRAMEWORK_EXPORT S_STD_Constant_AirAxis : public S_STD_Constant_AcsAxis
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_STD_Constant_Air, airBearing)

public:
    S_STD_Constant_AirAxis();
    S_STD_Constant_AirAxis(const S_STD_Constant_AirAxis &axis);
    S_STD_Constant_AirAxis(const SR_STD_Constant_AirAxis &axis);
    S_STD_Constant_AirAxis &operator=(const S_STD_Constant_AirAxis &axis);
    S_STD_Constant_AirAxis &operator=(const SR_STD_Constant_AirAxis &axis);
};

class GUIFRAMEWORK_EXPORT SR_STD_Constant_AirAxis : public SR_STD_Constant_AcsAxis
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_STD_Constant_Air, airBearing)

public:
    SR_STD_Constant_AirAxis();
    SR_STD_Constant_AirAxis(const S_STD_Constant_AirAxis &axis);
    SR_STD_Constant_AirAxis(const SR_STD_Constant_AirAxis &axis);
    SR_STD_Constant_AirAxis &operator=(const S_STD_Constant_AirAxis &axis);
    SR_STD_Constant_AirAxis &operator=(const SR_STD_Constant_AirAxis &axis);
};


class SR_STD_Constant_ScaleAxis;

class GUIFRAMEWORK_EXPORT S_STD_Constant_ScaleAxis : public S_STD_Constant_AcsAxis
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, S_List_Double, apertureScaling)

public:
    S_STD_Constant_ScaleAxis();
    S_STD_Constant_ScaleAxis(const S_STD_Constant_ScaleAxis &axis);
    S_STD_Constant_ScaleAxis(const SR_STD_Constant_ScaleAxis &axis);
    S_STD_Constant_ScaleAxis &operator=(const S_STD_Constant_ScaleAxis &axis);
    S_STD_Constant_ScaleAxis &operator=(const SR_STD_Constant_ScaleAxis &axis);
};

class GUIFRAMEWORK_EXPORT SR_STD_Constant_ScaleAxis : public SR_STD_Constant_AcsAxis
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, SR_List_Double, apertureScaling)

public:
    SR_STD_Constant_ScaleAxis();
    SR_STD_Constant_ScaleAxis(const S_STD_Constant_ScaleAxis &axis);
    SR_STD_Constant_ScaleAxis(const SR_STD_Constant_ScaleAxis &axis);
    SR_STD_Constant_ScaleAxis &operator=(const S_STD_Constant_ScaleAxis &axis);
    SR_STD_Constant_ScaleAxis &operator=(const SR_STD_Constant_ScaleAxis &axis);
};

#endif // STD_CONSTANT_ACSAXIS_H
