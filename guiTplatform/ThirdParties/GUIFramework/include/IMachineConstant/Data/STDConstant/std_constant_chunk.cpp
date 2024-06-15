#include "std_constant_chunk.h"

S_STD_Constant_Chunk::S_STD_Constant_Chunk()
{
    this->vacThreshold = 0.2;
    this->vacTimeout = 120000;
}

S_STD_Constant_Chunk::S_STD_Constant_Chunk(const S_STD_Constant_Chunk &chunk)
{
    this->vacThreshold = chunk.vacThreshold;
    this->vacTimeout = chunk.vacTimeout;
}

S_STD_Constant_Chunk::S_STD_Constant_Chunk(const SR_STD_Constant_Chunk &chunk)
{
    this->vacThreshold = chunk.vacThreshold.value;
    this->vacTimeout = chunk.vacTimeout.value;
}

S_STD_Constant_Chunk &S_STD_Constant_Chunk::operator=(const S_STD_Constant_Chunk &chunk)
{
    this->vacThreshold = chunk.vacThreshold;
    this->vacTimeout = chunk.vacTimeout;
    return *this;
}

S_STD_Constant_Chunk &S_STD_Constant_Chunk::operator=(const SR_STD_Constant_Chunk &chunk)
{
    this->vacThreshold = chunk.vacThreshold.value;
    this->vacTimeout = chunk.vacTimeout.value;
    return *this;
}

SR_STD_Constant_Chunk::SR_STD_Constant_Chunk() : TValueBase()
{
    this->vacThreshold.valueName = toStr(vacThreshold);
    this->vacTimeout.valueName = toStr(vacTimeout);
}

SR_STD_Constant_Chunk::SR_STD_Constant_Chunk(const SR_STD_Constant_Chunk &chunk)  : TValueBase(chunk)
{
    this->vacThreshold = chunk.vacThreshold;
    this->vacTimeout = chunk.vacTimeout;
}

SR_STD_Constant_Chunk::SR_STD_Constant_Chunk(const S_STD_Constant_Chunk &chunk) : TValueBase()
{
    this->vacThreshold = chunk.vacThreshold;
    this->vacTimeout = chunk.vacTimeout;
}

SR_STD_Constant_Chunk &SR_STD_Constant_Chunk::operator=(const SR_STD_Constant_Chunk &chunk)
{
    TValueBase::operator=(chunk);
    this->vacThreshold = chunk.vacThreshold;
    this->vacTimeout = chunk.vacTimeout;
    return *this;
}

SR_STD_Constant_Chunk &SR_STD_Constant_Chunk::operator=(const S_STD_Constant_Chunk &chunk)
{
    this->vacThreshold = chunk.vacThreshold;
    this->vacTimeout = chunk.vacTimeout;
    return *this;
}
