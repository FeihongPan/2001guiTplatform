#include "efem.h"

S_Robot::S_Robot()
{

}

S_Robot::S_Robot(const S_Robot &instance)
{
    this->zAxis = instance.zAxis;
    this->rAxis = instance.rAxis;
    this->thetaAxis = instance.thetaAxis;
}

S_Robot::S_Robot(const SR_Robot &instance)
{
    this->zAxis = instance.zAxis;
    this->rAxis = instance.rAxis;
    this->thetaAxis = instance.thetaAxis;
}

S_Robot &S_Robot::operator=(const S_Robot &instance)
{
    this->zAxis = instance.zAxis;
    this->rAxis = instance.rAxis;
    this->thetaAxis = instance.thetaAxis;
    return *this;
}

S_Robot &S_Robot::operator=(const SR_Robot &instance)
{
    this->zAxis = instance.zAxis;
    this->rAxis = instance.rAxis;
    this->thetaAxis = instance.thetaAxis;
    return *this;
}

SR_Robot::SR_Robot() : TValueBase()
{

}

SR_Robot::SR_Robot(const S_Robot &instance) : TValueBase()
{
    this->zAxis = instance.zAxis;
    this->rAxis = instance.rAxis;
    this->thetaAxis = instance.thetaAxis;
}

SR_Robot::SR_Robot(const SR_Robot &instance) : TValueBase(instance)
{
    this->zAxis = instance.zAxis;
    this->rAxis = instance.rAxis;
    this->thetaAxis = instance.thetaAxis;
}

SR_Robot &SR_Robot::operator=(const S_Robot &instance)
{
    this->zAxis = instance.zAxis;
    this->rAxis = instance.rAxis;
    this->thetaAxis = instance.thetaAxis;
    return *this;
}

SR_Robot &SR_Robot::operator=(const SR_Robot &instance)
{
    TValueBase::operator=(instance);
    this->zAxis = instance.zAxis;
    this->rAxis = instance.rAxis;
    this->thetaAxis = instance.thetaAxis;
    return *this;
}

S_PreAlgner::S_PreAlgner()
{

}

S_PreAlgner::S_PreAlgner(const S_PreAlgner &instance)
{
    this->zAxis = instance.zAxis;
    this->thetaAxis = instance.thetaAxis;
}

S_PreAlgner::S_PreAlgner(const SR_PreAlgner &instance)
{
    this->zAxis = instance.zAxis;
    this->thetaAxis = instance.thetaAxis;
}

S_PreAlgner &S_PreAlgner::operator=(const S_PreAlgner &instance)
{
    this->zAxis = instance.zAxis;
    this->thetaAxis = instance.thetaAxis;
    return *this;
}

S_PreAlgner &S_PreAlgner::operator=(const SR_PreAlgner &instance)
{
    this->zAxis = instance.zAxis;
    this->thetaAxis = instance.thetaAxis;
    return *this;
}

SR_PreAlgner::SR_PreAlgner() : TValueBase()
{

}

SR_PreAlgner::SR_PreAlgner(const S_PreAlgner &instance) : TValueBase()
{
    this->zAxis = instance.zAxis;
    this->thetaAxis = instance.thetaAxis;
}

SR_PreAlgner::SR_PreAlgner(const SR_PreAlgner &instance) : TValueBase(instance)
{
    this->zAxis = instance.zAxis;
    this->thetaAxis = instance.thetaAxis;
}

SR_PreAlgner &SR_PreAlgner::operator=(const S_PreAlgner &instance)
{
    this->zAxis = instance.zAxis;
    this->thetaAxis = instance.thetaAxis;
    return *this;
}

SR_PreAlgner &SR_PreAlgner::operator=(const SR_PreAlgner &instance)
{
    TValueBase::operator=(instance);
    this->zAxis = instance.zAxis;
    this->thetaAxis = instance.thetaAxis;
    return *this;
}

S_LoadPort::S_LoadPort()
{

}

S_LoadPort::S_LoadPort(const S_LoadPort &instance)
{

}

S_LoadPort::S_LoadPort(const SR_LoadPort &instance)
{

}

S_LoadPort &S_LoadPort::operator=(const S_LoadPort &instance)
{
    return *this;
}

S_LoadPort &S_LoadPort::operator=(const SR_LoadPort &instance)
{
    return *this;
}

SR_LoadPort::SR_LoadPort() : TValueBase()
{

}

SR_LoadPort::SR_LoadPort(const S_LoadPort &instance) : TValueBase()
{

}

SR_LoadPort::SR_LoadPort(const SR_LoadPort &instance) : TValueBase(instance)
{

}

SR_LoadPort &SR_LoadPort::operator=(const S_LoadPort &instance)
{
    return *this;
}

SR_LoadPort &SR_LoadPort::operator=(const SR_LoadPort &instance)
{
    TValueBase::operator=(instance);
    return *this;
}

S_EFEM::S_EFEM()
{

}

S_EFEM::S_EFEM(const S_EFEM &instance)
{
    this->robot = instance.robot;
    this->preAligner = instance.preAligner;
    this->loadport = instance.loadport;
}

S_EFEM::S_EFEM(const SR_EFEM &instance)
{
    this->robot = instance.robot;
    this->preAligner = instance.preAligner;
    this->loadport = instance.loadport;
}

S_EFEM &S_EFEM::operator=(const S_EFEM &instance)
{
    this->robot = instance.robot;
    this->preAligner = instance.preAligner;
    this->loadport = instance.loadport;
    return *this;
}

S_EFEM &S_EFEM::operator=(const SR_EFEM &instance)
{
    this->robot = instance.robot;
    this->preAligner = instance.preAligner;
    this->loadport = instance.loadport;
    return *this;
}

SR_EFEM::SR_EFEM() : TValueBase()
{

}

SR_EFEM::SR_EFEM(const S_EFEM &instance) : TValueBase()
{
    this->robot = instance.robot;
    this->preAligner = instance.preAligner;
    this->loadport = instance.loadport;
}

SR_EFEM::SR_EFEM(const SR_EFEM &instance) : TValueBase(instance)
{
    this->robot = instance.robot;
    this->preAligner = instance.preAligner;
    this->loadport = instance.loadport;
}

SR_EFEM &SR_EFEM::operator=(const S_EFEM &instance)
{
    this->robot = instance.robot;
    this->preAligner = instance.preAligner;
    this->loadport = instance.loadport;
    return *this;
}

SR_EFEM &SR_EFEM::operator=(const SR_EFEM &instance)
{
    TValueBase::operator=(instance);
    this->robot = instance.robot;
    this->preAligner = instance.preAligner;
    this->loadport = instance.loadport;
    return *this;
}
