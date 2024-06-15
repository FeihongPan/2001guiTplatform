#ifndef MACHINECONSTANT_H
#define MACHINECONSTANT_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "mccontent.h"
#include "constantinfo.h"
#include "Serializer/QSerializer"

#include <QObject>

class GUIFRAMEWORK_EXPORT MCFileByteArray : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(QString, recipeFileName)
    QS_FIELD(QByteArray, recipeAll)
public:
    MCFileByteArray();
    MCFileByteArray &operator=(const MCFileByteArray &fileByteArray);
};


class SR_MachineConstant;

class GUIFRAMEWORK_EXPORT S_MachineConstant : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_ConstantInfo, mcInfo)
    QS_OBJECT(S_MCContent, mcContent)

public:
    S_MachineConstant();
    S_MachineConstant(const S_MachineConstant &mc);
    S_MachineConstant(const SR_MachineConstant &mc);
    S_MachineConstant &operator=(const S_MachineConstant &mc);
    S_MachineConstant &operator=(const SR_MachineConstant &mc);
};

class GUIFRAMEWORK_EXPORT SR_MachineConstant : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_ConstantInfo, mcInfo)
    QS_OBJECT(SR_MCContent, mcContent)

public:
    SR_MachineConstant();
    SR_MachineConstant(const SR_MachineConstant &mc);
    SR_MachineConstant(const S_MachineConstant &mc);
    SR_MachineConstant &operator=(const SR_MachineConstant &sr_mc);
    SR_MachineConstant &operator=(const S_MachineConstant &s_mc);
};

#endif // MACHINECONSTANT_H
