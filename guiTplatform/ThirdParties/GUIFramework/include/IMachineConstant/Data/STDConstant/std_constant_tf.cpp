#include "std_constant_tf.h"

S_STD_Constant_iCsTF::S_STD_Constant_iCsTF()
{

}

S_STD_Constant_iCsTF::S_STD_Constant_iCsTF(const S_STD_Constant_iCsTF &instance)
{
    this->origin = instance.origin;
    this->orthogonality = instance.orthogonality;
}

S_STD_Constant_iCsTF::S_STD_Constant_iCsTF(const SR_STD_Constant_iCsTF &instance)
{
    this->origin.clear();
    for(int i = 0; i < instance.origin.count(); i++)
    {
        this->origin.append(instance.origin[i].value);
    }
}

S_STD_Constant_iCsTF &S_STD_Constant_iCsTF::operator=(const S_STD_Constant_iCsTF &instance)
{
    this->origin = instance.origin;
    this->orthogonality = instance.orthogonality;
    return *this;
}

S_STD_Constant_iCsTF &S_STD_Constant_iCsTF::operator=(const SR_STD_Constant_iCsTF &instance)
{
    this->origin.clear();
    for(int i = 0; i < instance.origin.count(); i++)
    {
        this->origin.append(instance.origin[i].value);
    }
    return *this;
}

SR_STD_Constant_iCsTF::SR_STD_Constant_iCsTF() : TValueBase()
{

}

SR_STD_Constant_iCsTF::SR_STD_Constant_iCsTF(const S_STD_Constant_iCsTF &instance) : TValueBase()
{
    this->origin.clear();
    for(int i = 0; i < instance.origin.count(); i++)
    {
        this->origin.append(instance.origin[i]);
    }
}

SR_STD_Constant_iCsTF::SR_STD_Constant_iCsTF(const SR_STD_Constant_iCsTF &instance) : TValueBase(instance)
{
    this->origin = instance.origin;
    this->orthogonality = instance.orthogonality;
}

SR_STD_Constant_iCsTF &SR_STD_Constant_iCsTF::operator=(const S_STD_Constant_iCsTF &instance)
{
    this->origin.clear();
    for(int i = 0; i < instance.origin.count(); i++)
    {
        this->origin.append(instance.origin[i]);
    }
    return *this;
}

SR_STD_Constant_iCsTF &SR_STD_Constant_iCsTF::operator=(const SR_STD_Constant_iCsTF &instance)
{
    TValueBase::operator=(instance);
    this->origin = instance.origin;
    this->orthogonality = instance.orthogonality;
    return *this;
}


S_STD_Constant_vCsTF::S_STD_Constant_vCsTF()
{

}

S_STD_Constant_vCsTF::S_STD_Constant_vCsTF(const S_STD_Constant_vCsTF &instance)
{
    this->tfMatrix = instance.tfMatrix;
}

S_STD_Constant_vCsTF::S_STD_Constant_vCsTF(const SR_STD_Constant_vCsTF &instance)
{
    this->tfMatrix.clear();
    for(int i = 0; i < instance.tfMatrix.count(); i++)
    {
        this->tfMatrix.append(instance.tfMatrix[i].value);
    }
}

S_STD_Constant_vCsTF &S_STD_Constant_vCsTF::operator=(const S_STD_Constant_vCsTF &instance)
{
    this->tfMatrix = instance.tfMatrix;
    return *this;
}

S_STD_Constant_vCsTF &S_STD_Constant_vCsTF::operator=(const SR_STD_Constant_vCsTF &instance)
{
    this->tfMatrix.clear();
    for(int i = 0; i < instance.tfMatrix.count(); i++)
    {
        this->tfMatrix.append(instance.tfMatrix[i].value);
    }
    return *this;
}


SR_STD_Constant_vCsTF::SR_STD_Constant_vCsTF() : TValueBase()
{

}

SR_STD_Constant_vCsTF::SR_STD_Constant_vCsTF(const S_STD_Constant_vCsTF &instance) : TValueBase()
{
    this->tfMatrix.clear();
    for(int i = 0; i < instance.tfMatrix.count(); i++)
    {
        this->tfMatrix.append(instance.tfMatrix[i]);
    }
}

SR_STD_Constant_vCsTF::SR_STD_Constant_vCsTF(const SR_STD_Constant_vCsTF &instance) : TValueBase(instance)
{
    this->tfMatrix = instance.tfMatrix;
}

SR_STD_Constant_vCsTF &SR_STD_Constant_vCsTF::operator=(const S_STD_Constant_vCsTF &instance)
{
    this->tfMatrix.clear();
    for(int i = 0; i < instance.tfMatrix.count(); i++)
    {
        this->tfMatrix.append(instance.tfMatrix[i]);
    }
    return *this;
}

SR_STD_Constant_vCsTF &SR_STD_Constant_vCsTF::operator=(const SR_STD_Constant_vCsTF &instance)
{
    TValueBase::operator=(instance);
    this->tfMatrix = instance.tfMatrix;
    return *this;
}
