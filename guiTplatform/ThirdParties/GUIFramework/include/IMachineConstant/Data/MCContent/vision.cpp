#include "vision.h"

S_Vision::S_Vision()
{

}

S_Vision::S_Vision(const S_Vision &vision)
{
    this->matrixInternal = vision.matrixInternal;
    this->matrixExternal = vision.matrixExternal;
}

S_Vision::S_Vision(const SR_Vision &vision)
{
    this->matrixInternal = vision.matrixInternal.value;
    this->matrixExternal = vision.matrixExternal.value;
}

S_Vision &S_Vision::operator=(const S_Vision &vision)
{
    this->matrixInternal = vision.matrixInternal;
    this->matrixExternal = vision.matrixExternal;
    return *this;
}

S_Vision &S_Vision::operator=(const SR_Vision &vision)
{
    this->matrixInternal = vision.matrixInternal.value;
    this->matrixExternal = vision.matrixExternal.value;
    return *this;
}




SR_Vision::SR_Vision() : TValueBase()
{
}

SR_Vision::SR_Vision(const S_Vision &vision) : TValueBase()
{
    this->matrixInternal = vision.matrixInternal;
    this->matrixExternal = vision.matrixExternal;
}

SR_Vision::SR_Vision(const SR_Vision &vision) : TValueBase(vision)
{
    this->matrixInternal = vision.matrixInternal;
    this->matrixExternal = vision.matrixExternal;
}

SR_Vision &SR_Vision::operator=(const S_Vision &vision)
{
    this->matrixInternal = vision.matrixInternal;
    this->matrixExternal = vision.matrixExternal;
    return *this;
}

SR_Vision &SR_Vision::operator=(const SR_Vision &vision)
{
    TValueBase::operator=(vision);
    this->matrixInternal = vision.matrixInternal;
    this->matrixExternal = vision.matrixExternal;
    return *this;
}
