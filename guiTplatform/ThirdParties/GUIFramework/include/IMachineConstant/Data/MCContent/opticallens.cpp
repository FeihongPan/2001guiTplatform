#include "opticallens.h"

S_OpticalLens::S_OpticalLens()
{

}

S_OpticalLens::S_OpticalLens(const S_OpticalLens &instance)
{
    this->fieldSize = instance.fieldSize;
    this->numberOfFields = instance.numberOfFields;
    this->fieldCenter = instance.fieldCenter;
    this->focus = instance.focus;
}

S_OpticalLens::S_OpticalLens(const SR_OpticalLens &instance)
{
    this->fieldSize.clear();
    for(int i = 0; i < this->fieldSize.count(); i++)
    {
        this->fieldSize.append(instance.fieldSize[i].value);
    }

    this->numberOfFields = instance.numberOfFields.value;

    this->fieldCenter.clear();
    for(int i = 0; i < this->fieldCenter.count(); i++)
    {
        this->fieldCenter.append(instance.fieldCenter[i].value);
    }

    this->focus.clear();
    for(int i = 0; i < this->focus.count(); i++)
    {
        this->focus.append(instance.focus[i].value);
    }
}

S_OpticalLens &S_OpticalLens::operator=(const S_OpticalLens &instance)
{
    this->fieldSize = instance.fieldSize;
    this->numberOfFields = instance.numberOfFields;
    this->fieldCenter = instance.fieldCenter;
    this->focus = instance.focus;
    return *this;
}

S_OpticalLens &S_OpticalLens::operator=(const SR_OpticalLens &instance)
{
    this->fieldSize.clear();
    for(int i = 0; i < this->fieldSize.count(); i++)
    {
        this->fieldSize.append(instance.fieldSize[i].value);
    }

    this->numberOfFields = instance.numberOfFields.value;

    this->fieldCenter.clear();
    for(int i = 0; i < this->fieldCenter.count(); i++)
    {
        this->fieldCenter.append(instance.fieldCenter[i].value);
    }

    this->focus.clear();
    for(int i = 0; i < this->focus.count(); i++)
    {
        this->focus.append(instance.focus[i].value);
    }
    return *this;
}


SR_OpticalLens::SR_OpticalLens() : TValueBase()
{

}

SR_OpticalLens::SR_OpticalLens(const S_OpticalLens &instance) : TValueBase()
{
    this->fieldSize.clear();
    for(int i = 0; i < this->fieldSize.count(); i++)
    {
        this->fieldSize.append(instance.fieldSize[i]);
    }

    this->numberOfFields = instance.numberOfFields;

    this->fieldCenter.clear();
    for(int i = 0; i < this->fieldCenter.count(); i++)
    {
        this->fieldCenter.append(instance.fieldCenter[i]);
    }

    this->focus.clear();
    for(int i = 0; i < this->focus.count(); i++)
    {
        this->focus.append(instance.focus[i]);
    }
}

SR_OpticalLens::SR_OpticalLens(const SR_OpticalLens &instance) : TValueBase(instance)
{
    this->fieldSize = instance.fieldSize;
    this->numberOfFields = instance.numberOfFields;
    this->fieldCenter = instance.fieldCenter;
    this->focus = instance.focus;
}

SR_OpticalLens &SR_OpticalLens::operator=(const S_OpticalLens &instance)
{
    this->fieldSize.clear();
    for(int i = 0; i < this->fieldSize.count(); i++)
    {
        this->fieldSize.append(instance.fieldSize[i]);
    }

    this->numberOfFields = instance.numberOfFields;

    this->fieldCenter.clear();
    for(int i = 0; i < this->fieldCenter.count(); i++)
    {
        this->fieldCenter.append(instance.fieldCenter[i]);
    }

    this->focus.clear();
    for(int i = 0; i < this->focus.count(); i++)
    {
        this->focus.append(instance.focus[i]);
    }
    return *this;
}

SR_OpticalLens &SR_OpticalLens::operator=(const SR_OpticalLens &instance)
{
    TValueBase::operator=(instance);
    this->fieldSize = instance.fieldSize;
    this->numberOfFields = instance.numberOfFields;
    this->fieldCenter = instance.fieldCenter;
    this->focus = instance.focus;
    return *this;
}
