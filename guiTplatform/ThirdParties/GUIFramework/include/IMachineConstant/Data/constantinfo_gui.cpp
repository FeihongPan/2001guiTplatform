#include "constantinfo_gui.h"
#include "Component/MachineConstant/Data/constantinfo.h"

SR_ConstantInfo::SR_ConstantInfo()
{
    constantName.valueName = toStr(constantName);
    createdTime.valueName = toStr(createdTime);
    creator.valueName = toStr(creator);
    description.valueName = toStr(description);
    modifiedTime.valueName = toStr(modifiedTime);
    modifier.valueName = toStr(modifier);
    isCurrentConstant.valueName = toStr(isCurrentConstant);
}

SR_ConstantInfo::SR_ConstantInfo(const SR_ConstantInfo &cst)
{
    this->constantName = cst.constantName;
    this->createdTime = cst.createdTime;
    this->creator = cst.creator;
    this->description = cst.description;
    this->modifiedTime = cst.modifiedTime;
    this->modifier = cst.modifier;
    this->isCurrentConstant = cst.isCurrentConstant;
}

SR_ConstantInfo &SR_ConstantInfo::operator=(const SR_ConstantInfo &cst)
{
    this->constantName = cst.constantName;
    this->createdTime = cst.createdTime;
    this->creator = cst.creator;
    this->description = cst.description;
    this->modifiedTime = cst.modifiedTime;
    this->modifier = cst.modifier;
    this->isCurrentConstant = cst.isCurrentConstant;
    return *this;
}

S_ConstantInfo SR_ConstantInfo::toS()
{
    S_ConstantInfo cs;
    cs = *this;
    return cs;
}

SR_ConstantInfo &SR_ConstantInfo::operator=(const S_ConstantInfo &cst)
{
    this->constantName = cst.constantName;
    this->createdTime = cst.createdTime;
    this->creator = cst.creator;
    this->description = cst.description;
    this->modifiedTime = cst.modifiedTime;
    this->modifier = cst.modifier;
    this->isCurrentConstant = cst.isCurrentConstant;
    return *this;
}


void SR_ConstantInfo::clear()
{
    constantName.value.clear();
    createdTime.value.clear();
    creator.value.clear();
    description.value.clear();
    modifiedTime.value.clear();
    modifier.value.clear();
    isCurrentConstant.SetValue(false);
}
