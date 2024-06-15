#include "std_constant_air.h"

S_STD_Constant_Air::S_STD_Constant_Air()
{

}

S_STD_Constant_Air::S_STD_Constant_Air(const S_STD_Constant_Air &air)
{
    this->CDAWngLmt = air.CDAWngLmt;
    this->CDAErrLmt = air.CDAErrLmt;
    this->VACWngLmt = air.VACWngLmt;
    this->VACErrLmt = air.VACErrLmt;
}

S_STD_Constant_Air::S_STD_Constant_Air(const SR_STD_Constant_Air &air)
{
    this->CDAWngLmt.clear();
    this->CDAErrLmt.clear();
    this->VACWngLmt.clear();
    this->VACErrLmt.clear();
    for(int i = 0; i < air.CDAWngLmt.count(); i++)
    {
        this->CDAWngLmt.append(air.CDAWngLmt[i].value);
    }
    for(int i = 0; i < air.CDAErrLmt.count(); i++)
    {
        this->CDAErrLmt.append(air.CDAErrLmt[i].value);
    }
    for(int i = 0; i < air.VACWngLmt.count(); i++)
    {
        this->VACWngLmt.append(air.VACWngLmt[i].value);
    }
    for(int i = 0; i < air.VACErrLmt.count(); i++)
    {
        this->VACErrLmt.append(air.VACErrLmt[i].value);
    }
}

S_STD_Constant_Air &S_STD_Constant_Air::operator=(const S_STD_Constant_Air &air)
{
    this->CDAWngLmt = air.CDAWngLmt;
    this->CDAErrLmt = air.CDAErrLmt;
    this->VACWngLmt = air.VACWngLmt;
    this->VACErrLmt = air.VACErrLmt;
    return *this;
}

S_STD_Constant_Air &S_STD_Constant_Air::operator=(const SR_STD_Constant_Air &air)
{
    this->CDAWngLmt.clear();
    this->CDAErrLmt.clear();
    this->VACWngLmt.clear();
    this->VACErrLmt.clear();
    for(int i = 0; i < air.CDAWngLmt.count(); i++)
    {
        this->CDAWngLmt.append(air.CDAWngLmt[i].value);
    }
    for(int i = 0; i < air.CDAErrLmt.count(); i++)
    {
        this->CDAErrLmt.append(air.CDAErrLmt[i].value);
    }
    for(int i = 0; i < air.VACWngLmt.count(); i++)
    {
        this->VACWngLmt.append(air.VACWngLmt[i].value);
    }
    for(int i = 0; i < air.VACErrLmt.count(); i++)
    {
        this->VACErrLmt.append(air.VACErrLmt[i].value);
    }
    return *this;
}

SR_STD_Constant_Air::SR_STD_Constant_Air() : TValueBase()
{

}

SR_STD_Constant_Air::SR_STD_Constant_Air(const S_STD_Constant_Air &air) : TValueBase()
{
    this->CDAWngLmt.clear();
    this->CDAErrLmt.clear();
    this->VACWngLmt.clear();
    this->VACErrLmt.clear();
    for(int i = 0; i < air.CDAWngLmt.count(); i++)
    {
        this->CDAWngLmt.append(air.CDAWngLmt[i]);
    }
    for(int i = 0; i < air.CDAErrLmt.count(); i++)
    {
        this->CDAErrLmt.append(air.CDAErrLmt[i]);
    }
    for(int i = 0; i < air.VACWngLmt.count(); i++)
    {
        this->VACWngLmt.append(air.VACWngLmt[i]);
    }
    for(int i = 0; i < air.VACErrLmt.count(); i++)
    {
        this->VACErrLmt.append(air.VACErrLmt[i]);
    }
}

SR_STD_Constant_Air::SR_STD_Constant_Air(const SR_STD_Constant_Air &air) : TValueBase(air)
{
    this->CDAWngLmt = air.CDAWngLmt;
    this->CDAErrLmt = air.CDAErrLmt;
    this->VACWngLmt = air.VACWngLmt;
    this->VACErrLmt = air.VACErrLmt;
}

SR_STD_Constant_Air &SR_STD_Constant_Air::operator=(const S_STD_Constant_Air &air)
{
    this->CDAWngLmt.clear();
    this->CDAErrLmt.clear();
    this->VACWngLmt.clear();
    this->VACErrLmt.clear();
    for(int i = 0; i < air.CDAWngLmt.count(); i++)
    {
        this->CDAWngLmt.append(air.CDAWngLmt[i]);
    }
    for(int i = 0; i < air.CDAErrLmt.count(); i++)
    {
        this->CDAErrLmt.append(air.CDAErrLmt[i]);
    }
    for(int i = 0; i < air.VACWngLmt.count(); i++)
    {
        this->VACWngLmt.append(air.VACWngLmt[i]);
    }
    for(int i = 0; i < air.VACErrLmt.count(); i++)
    {
        this->VACErrLmt.append(air.VACErrLmt[i]);
    }
    return *this;
}


SR_STD_Constant_Air &SR_STD_Constant_Air::operator=(const SR_STD_Constant_Air &air)
{
    TValueBase::operator=(air);
    this->CDAWngLmt = air.CDAWngLmt;
    this->CDAErrLmt = air.CDAErrLmt;
    this->VACWngLmt = air.VACWngLmt;
    this->VACErrLmt = air.VACErrLmt;
    return *this;
}
