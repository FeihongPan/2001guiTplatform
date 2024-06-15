#include "uvlamp.h"

S_UVLamp::S_UVLamp()
{

}

S_UVLamp::S_UVLamp(const S_UVLamp &instance)
{
    this->lampSpec = instance.lampSpec;
    this->interlock = instance.interlock;
}

S_UVLamp::S_UVLamp(const SR_UVLamp &instance)
{
    this->lampSpec = instance.lampSpec;
    this->interlock = instance.interlock;
}

S_UVLamp &S_UVLamp::operator=(const S_UVLamp &instance)
{
    this->lampSpec = instance.lampSpec;
    this->interlock = instance.interlock;
    return *this;
}

S_UVLamp &S_UVLamp::operator=(const SR_UVLamp &instance)
{
    this->lampSpec = instance.lampSpec;
    this->interlock = instance.interlock;
    return *this;
}

SR_UVLamp::SR_UVLamp() : TValueBase()
{

}

SR_UVLamp::SR_UVLamp(const S_UVLamp &instance) : TValueBase()
{
    this->lampSpec = instance.lampSpec;
    this->interlock = instance.interlock;
}

SR_UVLamp::SR_UVLamp(const SR_UVLamp &instance) : TValueBase(instance)
{
    this->lampSpec = instance.lampSpec;
    this->interlock = instance.interlock;
}

SR_UVLamp &SR_UVLamp::operator=(const S_UVLamp &instance)
{
    this->lampSpec = instance.lampSpec;
    this->interlock = instance.interlock;
    return *this;
}

SR_UVLamp &SR_UVLamp::operator=(const SR_UVLamp &instance)
{
    TValueBase::operator=(instance);
    this->lampSpec = instance.lampSpec;
    this->interlock = instance.interlock;
    return *this;
}

S_LampSpec::S_LampSpec()
{

}

S_LampSpec::S_LampSpec(const S_LampSpec &instance)
{
    this->power = instance.power;
    this->life = instance.life;
}

S_LampSpec::S_LampSpec(const SR_LampSpec &instance)
{
    this->power = instance.power.value;
    this->life = instance.life.value;
}

S_LampSpec &S_LampSpec::operator=(const S_LampSpec &instance)
{
    this->power = instance.power;
    this->life = instance.life;
    return *this;
}

S_LampSpec &S_LampSpec::operator=(const SR_LampSpec &instance)
{
    this->power = instance.power.value;
    this->life = instance.life.value;
    return *this;
}

SR_LampSpec::SR_LampSpec() : TValueBase()
{

}

SR_LampSpec::SR_LampSpec(const S_LampSpec &instance) : TValueBase()
{
    this->power = instance.power;
    this->life = instance.life;
}

SR_LampSpec::SR_LampSpec(const SR_LampSpec &instance) : TValueBase(instance)
{
    this->power = instance.power;
    this->life = instance.life;
}

SR_LampSpec &SR_LampSpec::operator=(const S_LampSpec &instance)
{
    this->power = instance.power;
    this->life = instance.life;
    return *this;
}

SR_LampSpec &SR_LampSpec::operator=(const SR_LampSpec &instance)
{
    TValueBase::operator=(instance);
    this->power = instance.power;
    this->life = instance.life;
    return *this;
}

S_Interlock::S_Interlock()
{

}

S_Interlock::S_Interlock(const S_Interlock &instance)
{
    this->CDAWngLmt = instance.CDAWngLmt;
    this->CDAErrLmt = instance.CDAErrLmt;
    this->TempWngLmt = instance.TempWngLmt;
    this->TempErrLmt = instance.TempErrLmt;
}

S_Interlock::S_Interlock(const SR_Interlock &instance)
{
    this->CDAWngLmt = instance.CDAWngLmt.value;
    this->CDAErrLmt = instance.CDAErrLmt.value;
    this->TempWngLmt = instance.TempWngLmt.value;
    this->TempErrLmt = instance.TempErrLmt.value;
}

S_Interlock &S_Interlock::operator=(const S_Interlock &instance)
{
    this->CDAWngLmt = instance.CDAWngLmt;
    this->CDAErrLmt = instance.CDAErrLmt;
    this->TempWngLmt = instance.TempWngLmt;
    this->TempErrLmt = instance.TempErrLmt;
    return *this;
}

S_Interlock &S_Interlock::operator=(const SR_Interlock &instance)
{
    this->CDAWngLmt = instance.CDAWngLmt.value;
    this->CDAErrLmt = instance.CDAErrLmt.value;
    this->TempWngLmt = instance.TempWngLmt.value;
    this->TempErrLmt = instance.TempErrLmt.value;
    return *this;
}

SR_Interlock::SR_Interlock() : TValueBase()
{

}

SR_Interlock::SR_Interlock(const S_Interlock &instance) : TValueBase()
{
    this->CDAWngLmt = instance.CDAWngLmt;
    this->CDAErrLmt = instance.CDAErrLmt;
    this->TempWngLmt = instance.TempWngLmt;
    this->TempErrLmt = instance.TempErrLmt;
}

SR_Interlock::SR_Interlock(const SR_Interlock &instance) : TValueBase(instance)
{
    this->CDAWngLmt = instance.CDAWngLmt;
    this->CDAErrLmt = instance.CDAErrLmt;
    this->TempWngLmt = instance.TempWngLmt;
    this->TempErrLmt = instance.TempErrLmt;
}

SR_Interlock &SR_Interlock::operator=(const S_Interlock &instance)
{
    this->CDAWngLmt = instance.CDAWngLmt;
    this->CDAErrLmt = instance.CDAErrLmt;
    this->TempWngLmt = instance.TempWngLmt;
    this->TempErrLmt = instance.TempErrLmt;
    return *this;
}

SR_Interlock &SR_Interlock::operator=(const SR_Interlock &instance)
{
    TValueBase::operator=(instance);
    this->CDAWngLmt = instance.CDAWngLmt;
    this->CDAErrLmt = instance.CDAErrLmt;
    this->TempWngLmt = instance.TempWngLmt;
    this->TempErrLmt = instance.TempErrLmt;
    return *this;
}


