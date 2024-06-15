#include "materialinfo.h"

Substrate::Substrate()
{
    this->size.append(300);
    this->thickness = 0.35;
    this->orientation = 0;
}

Substrate::Substrate(const Substrate &substrate)
{
    this->size = substrate.size;
    this->thickness = substrate.thickness;
    this->orientation = substrate.orientation;
}

Substrate &Substrate::operator=(const Substrate &substrate)
{
    this->size = substrate.size;
    this->thickness = substrate.thickness;
    this->orientation = substrate.orientation;
    return *this;
}

//MaterialInfo::MaterialInfo()
//{

//}

//MaterialInfo::MaterialInfo(const MaterialInfo &materialInfo)
//{
//    this->substrates = materialInfo.substrates;
//}

//MaterialInfo &MaterialInfo::operator=(const MaterialInfo &materialInfo)
//{
//    this->substrates = materialInfo.substrates;
//    return *this;
//}
