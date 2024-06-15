#ifndef MACHINECONSTANT_GUI_H
#define MACHINECONSTANT_GUI_H

#include "BasicValue/tvalue.h"
//#include "Component/Motion/View/axisinfo_gui.h"
#include "Component/MachineConstant/Data/constantinfo_gui.h"
//#include "Component/Alignment/mc_align.h"
#include <QObject>

class S_MachineConstant;
class SR_MachineConstant : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_ConstantInfo, constantInfo)
//    QS_OBJECT(MC_Align, align)


public:
    SR_MachineConstant();

    SR_MachineConstant(const SR_MachineConstant &mc);
    SR_MachineConstant &operator=(const SR_MachineConstant &sr_mc);
    SR_MachineConstant &operator=(const S_MachineConstant &s_mc);
    S_MachineConstant toS();



//    SR_Constant_AxisGroup ACS;
};

#endif // MACHINECONSTANT_H
