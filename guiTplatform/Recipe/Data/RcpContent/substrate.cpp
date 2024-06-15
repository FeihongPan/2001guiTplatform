#include "substrate.h"

S_Substrate::S_Substrate()
{

}

S_Substrate::S_Substrate(const S_Substrate &sub)
{
    this->size = sub.size;
    this->thickness = sub.thickness;
    this->orientation = sub.orientation;
}

S_Substrate &S_Substrate::operator=(const S_Substrate &sub)
{
    this->size = sub.size;
    this->thickness = sub.thickness;
    this->orientation = sub.orientation;
    return *this;
}

S_Stencil::S_Stencil()
{

}

S_Stencil::S_Stencil(const S_Stencil &stl)
{
    this->id = stl.id;
}

S_Stencil &S_Stencil::operator=(const S_Stencil &stl)
{
    this->id = stl.id;
    return *this;
}
