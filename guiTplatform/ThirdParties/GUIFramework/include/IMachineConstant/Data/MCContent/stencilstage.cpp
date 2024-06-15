#include "stencilstage.h"

S_StencilStage::S_StencilStage()
{

}

S_StencilStage::S_StencilStage(const S_StencilStage &instance)
{
    this->verticalStage = instance.verticalStage;
    this->horizontalStage = instance.horizontalStage;
    this->iCsTF = instance.iCsTF;
    this->vCsTF = instance.vCsTF;
}

S_StencilStage::S_StencilStage(const SR_StencilStage &instance)
{
    this->verticalStage = instance.verticalStage;
    this->horizontalStage = instance.horizontalStage;
    this->iCsTF = instance.iCsTF;
    this->vCsTF = instance.vCsTF;
}

S_StencilStage &S_StencilStage::operator=(const S_StencilStage &instance)
{
    this->verticalStage = instance.verticalStage;
    this->horizontalStage = instance.horizontalStage;
    this->iCsTF = instance.iCsTF;
    this->vCsTF = instance.vCsTF;
    return *this;
}

S_StencilStage &S_StencilStage::operator=(const SR_StencilStage &instance)
{
    this->verticalStage = instance.verticalStage;
    this->horizontalStage = instance.horizontalStage;
    this->iCsTF = instance.iCsTF;
    this->vCsTF = instance.vCsTF;
    return *this;
}


SR_StencilStage::SR_StencilStage()
{

}

SR_StencilStage::SR_StencilStage(const S_StencilStage &instance)
{
    this->verticalStage = instance.verticalStage;
    this->horizontalStage = instance.horizontalStage;
    this->iCsTF = instance.iCsTF;
    this->vCsTF = instance.vCsTF;
}

SR_StencilStage::SR_StencilStage(const SR_StencilStage &instance)
{
    this->verticalStage = instance.verticalStage;
    this->horizontalStage = instance.horizontalStage;
    this->iCsTF = instance.iCsTF;
    this->vCsTF = instance.vCsTF;
}

SR_StencilStage &SR_StencilStage::operator=(const S_StencilStage &instance)
{
    this->verticalStage = instance.verticalStage;
    this->horizontalStage = instance.horizontalStage;
    this->iCsTF = instance.iCsTF;
    this->vCsTF = instance.vCsTF;
    return *this;
}

SR_StencilStage &SR_StencilStage::operator=(const SR_StencilStage &instance)
{
    this->verticalStage = instance.verticalStage;
    this->horizontalStage = instance.horizontalStage;
    this->iCsTF = instance.iCsTF;
    this->vCsTF = instance.vCsTF;
    return *this;
}
