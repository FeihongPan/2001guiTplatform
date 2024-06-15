#include "node.h"

TValueBase::TValueBase()
{

}

TValueBase::TValueBase(const TValueBase &tv)
{
    this->valueName = tv.valueName;
    this->brief = tv.brief;
    this->unit = tv.unit;
    this->valueType = tv.valueType;
    this->PropertyChanged = true;
}

TValueBase::TValueBase(TValueBase *parent)
{
    SetParent(parent);
}

void TValueBase::SetParent(TValueBase *parent)
{
    this->parent = parent;
    parent->children.append(this);
}

void TValueBase::SetPropertyChanged(bool r)
{
    this->PropertyChanged = r;
}
