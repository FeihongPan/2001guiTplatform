#include "Component/MachineConstant/Data/machineconstant_gui.h"
#include "Component/MachineConstant/Data/machineconstant.h"

SR_MachineConstant::SR_MachineConstant()
{

}

SR_MachineConstant::SR_MachineConstant(const SR_MachineConstant &mc)
{
    this->constantInfo = mc.constantInfo;
}

SR_MachineConstant &SR_MachineConstant::operator=(const SR_MachineConstant &mc)
{
    this->constantInfo = mc.constantInfo;
    return *this;
}

S_MachineConstant SR_MachineConstant::toS()
{
    S_MachineConstant mcs;
    mcs = *this;
    return mcs;
}

SR_MachineConstant &SR_MachineConstant::operator=(const S_MachineConstant &mc)
{
    this->constantInfo = mc.constantInfo;
    return *this;
}

