#ifndef STD_CONSTANT_PLCAXIS_H
#define STD_CONSTANT_PLCAXIS_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "BasicValue/serializablelist.h"
#include "Serializer/QSerializer"

class SR_STD_Constant_PlcAxis;

class GUIFRAMEWORK_EXPORT S_STD_Constant_PlcAxis : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, vel)
    QS_FIELD(double, acc)
    QS_FIELD(double, homeOffset)
    QS_FIELD(int, homeMethod)
    QS_FIELD(double, paramVel)
    QS_FIELD(double, homeVel)

public:
    S_STD_Constant_PlcAxis();
    S_STD_Constant_PlcAxis(const S_STD_Constant_PlcAxis &axis);
    S_STD_Constant_PlcAxis(const SR_STD_Constant_PlcAxis &axis);
    S_STD_Constant_PlcAxis &operator=(const S_STD_Constant_PlcAxis &axis);
    S_STD_Constant_PlcAxis &operator=(const SR_STD_Constant_PlcAxis &axis);
};

class GUIFRAMEWORK_EXPORT SR_STD_Constant_PlcAxis : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TDouble, vel)
    QS_OBJECT(TDouble, acc)
    QS_OBJECT(TDouble, homeOffset)
    QS_OBJECT(TInt, homeMethod)
    QS_OBJECT(TDouble, paramVel)
    QS_OBJECT(TDouble, homeVel)

public:
    SR_STD_Constant_PlcAxis();
    SR_STD_Constant_PlcAxis(const SR_STD_Constant_PlcAxis &axis);
    SR_STD_Constant_PlcAxis(const S_STD_Constant_PlcAxis &axis);
    SR_STD_Constant_PlcAxis &operator=(const SR_STD_Constant_PlcAxis &axis);
    SR_STD_Constant_PlcAxis &operator=(const S_STD_Constant_PlcAxis &axis);
};

#endif // STD_CONSTANT_PLCAXIS_H
