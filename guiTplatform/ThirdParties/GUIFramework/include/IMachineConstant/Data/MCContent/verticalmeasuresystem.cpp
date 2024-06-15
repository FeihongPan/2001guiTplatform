#include "verticalmeasuresystem.h"

S_VMSys::S_VMSys()
{

}

S_VMSys::S_VMSys(const S_VMSys &vms)
{
    this->vmSubstrate = vms.vmSubstrate;
    this->vmStencil = vms.vmStencil;
}

S_VMSys::S_VMSys(const SR_VMSys &vms)
{
    this->vmSubstrate = vms.vmSubstrate;
    this->vmStencil = vms.vmStencil;
}

S_VMSys &S_VMSys::operator=(const S_VMSys &vms)
{
    this->vmSubstrate = vms.vmSubstrate;
    this->vmStencil = vms.vmStencil;
    return *this;
}

S_VMSys &S_VMSys::operator=(const SR_VMSys &vms)
{
    this->vmSubstrate = vms.vmSubstrate;
    this->vmStencil = vms.vmStencil;
    return *this;
}

SR_VMSys::SR_VMSys() : TValueBase()
{

}

SR_VMSys::SR_VMSys(const SR_VMSys &vms) : TValueBase(vms)
{
    this->vmSubstrate = vms.vmSubstrate;
    this->vmStencil = vms.vmStencil;
}

SR_VMSys::SR_VMSys(const S_VMSys &vms) : TValueBase()
{
    this->vmSubstrate = vms.vmSubstrate;
    this->vmStencil = vms.vmStencil;
}

SR_VMSys &SR_VMSys::operator=(const SR_VMSys &vms)
{
    TValueBase::operator=(vms);
    this->vmSubstrate = vms.vmSubstrate;
    this->vmStencil = vms.vmStencil;
    return *this;
}

SR_VMSys &SR_VMSys::operator=(const S_VMSys &vms)
{
    this->vmSubstrate = vms.vmSubstrate;
    this->vmStencil = vms.vmStencil;
    return *this;
}
