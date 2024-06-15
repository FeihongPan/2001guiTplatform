#include "machineconstant.h"

MCFileByteArray::MCFileByteArray()
{

}

MCFileByteArray &MCFileByteArray::operator=(const MCFileByteArray &fileByteArray)
{
    this->recipeFileName = fileByteArray.recipeFileName;
    this->recipeAll = fileByteArray.recipeAll;
    return *this;
}

S_MachineConstant::S_MachineConstant()
{

}

S_MachineConstant::S_MachineConstant(const S_MachineConstant &mc)
{
    this->mcInfo = mc.mcInfo;
    this->mcContent = mc.mcContent;
}

S_MachineConstant::S_MachineConstant(const SR_MachineConstant &mc)
{
    this->mcInfo = mc.mcInfo;
    this->mcContent = mc.mcContent;
}

S_MachineConstant &S_MachineConstant::operator=(const S_MachineConstant &mc)
{
    this->mcInfo = mc.mcInfo;
    this->mcContent = mc.mcContent;
    return *this;
}

S_MachineConstant &S_MachineConstant::operator=(const SR_MachineConstant &mc)
{
    this->mcInfo = mc.mcInfo;
    this->mcContent = mc.mcContent;
    return *this;
}

SR_MachineConstant::SR_MachineConstant()
{
    this->mcInfo.valueName = toStr(mcInfo);
    this->mcContent.valueName = toStr(mcContent);
}

SR_MachineConstant::SR_MachineConstant(const SR_MachineConstant &mc)
{
    this->mcInfo = mc.mcInfo;
    this->mcContent = mc.mcContent;
}

SR_MachineConstant::SR_MachineConstant(const S_MachineConstant &mc)
{
    this->mcInfo = mc.mcInfo;
    this->mcContent = mc.mcContent;
}

SR_MachineConstant &SR_MachineConstant::operator=(const SR_MachineConstant &mc)
{
    this->mcInfo = mc.mcInfo;
    this->mcContent = mc.mcContent;
    return *this;
}

SR_MachineConstant &SR_MachineConstant::operator=(const S_MachineConstant &mc)
{
    this->mcInfo = mc.mcInfo;
    this->mcContent = mc.mcContent;
    return *this;
}
