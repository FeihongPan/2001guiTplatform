#include "constantinfo.h"

S_ConstantInfo::S_ConstantInfo()
{

}

S_ConstantInfo::S_ConstantInfo(const S_ConstantInfo &mcInfo)
{
    this->constantName = mcInfo.constantName;
    this->createdTime = mcInfo.createdTime;
    this->creator = mcInfo.creator;
    this->description = mcInfo.description;
    this->modifiedTime = mcInfo.modifiedTime;
    this->modifier = mcInfo.modifier;
    this->excuteTime = mcInfo.excuteTime;
    this->unexcuteTime = mcInfo.unexcuteTime;
}

S_ConstantInfo::S_ConstantInfo(const SR_ConstantInfo &mcInfo)
{
    this->constantName = mcInfo.constantName.value;
    this->createdTime = mcInfo.createdTime.value;
    this->creator = mcInfo.creator.value;
    this->description = mcInfo.description.value;
    this->modifiedTime = mcInfo.modifiedTime.value;
    this->modifier = mcInfo.modifier.value;
    this->excuteTime = mcInfo.excuteTime.value;
    this->unexcuteTime = mcInfo.unexcuteTime.value;
}


S_ConstantInfo &S_ConstantInfo::operator=(const S_ConstantInfo &mcInfo)
{
    this->constantName = mcInfo.constantName;
    this->createdTime = mcInfo.createdTime;
    this->creator = mcInfo.creator;
    this->description = mcInfo.description;
    this->modifiedTime = mcInfo.modifiedTime;
    this->modifier = mcInfo.modifier;
    this->excuteTime = mcInfo.excuteTime;
    this->unexcuteTime = mcInfo.unexcuteTime;
    return *this;
}

S_ConstantInfo &S_ConstantInfo::operator=(const SR_ConstantInfo &mcInfo)
{
    this->constantName = mcInfo.constantName.value;
    this->createdTime = mcInfo.createdTime.value;
    this->creator = mcInfo.creator.value;
    this->description = mcInfo.description.value;
    this->modifiedTime = mcInfo.modifiedTime.value;
    this->modifier = mcInfo.modifier.value;
    this->excuteTime = mcInfo.excuteTime.value;
    this->unexcuteTime = mcInfo.unexcuteTime.value;
    return *this;
}

SR_ConstantInfo::SR_ConstantInfo()
{
    this->constantName.valueName = toStr(constantName);
    this->createdTime.valueName = toStr(createdTime);
    this->creator.valueName = toStr(creator);
    this->description.valueName = toStr(description);
    this->modifiedTime.valueName = toStr(modifiedTime);
    this->modifier.valueName = toStr(modifier);
    this->excuteTime.valueName = toStr(excuteTime);
    this->unexcuteTime.valueName = toStr(unexcuteTime);
}

SR_ConstantInfo::SR_ConstantInfo(const SR_ConstantInfo &mcInfo)
{
    this->constantName = mcInfo.constantName;
    this->createdTime = mcInfo.createdTime;
    this->creator = mcInfo.creator;
    this->description = mcInfo.description;
    this->modifiedTime = mcInfo.modifiedTime;
    this->modifier = mcInfo.modifier;
    this->excuteTime = mcInfo.excuteTime;
    this->unexcuteTime = mcInfo.unexcuteTime;
}

SR_ConstantInfo::SR_ConstantInfo(const S_ConstantInfo &mcInfo)
{
    this->constantName = mcInfo.constantName;
    this->createdTime = mcInfo.createdTime;
    this->creator = mcInfo.creator;
    this->description = mcInfo.description;
    this->modifiedTime = mcInfo.modifiedTime;
    this->modifier = mcInfo.modifier;
    this->excuteTime = mcInfo.excuteTime;
    this->unexcuteTime = mcInfo.unexcuteTime;
}

SR_ConstantInfo &SR_ConstantInfo::operator=(const SR_ConstantInfo &mcInfo)
{
    this->constantName = mcInfo.constantName;
    this->createdTime = mcInfo.createdTime;
    this->creator = mcInfo.creator;
    this->description = mcInfo.description;
    this->modifiedTime = mcInfo.modifiedTime;
    this->modifier = mcInfo.modifier;
    this->excuteTime = mcInfo.excuteTime;
    this->unexcuteTime = mcInfo.unexcuteTime;
    return *this;
}

SR_ConstantInfo &SR_ConstantInfo::operator=(const S_ConstantInfo &mcInfo)
{
    this->constantName = mcInfo.constantName;
    this->createdTime = mcInfo.createdTime;
    this->creator = mcInfo.creator;
    this->description = mcInfo.description;
    this->modifiedTime = mcInfo.modifiedTime;
    this->modifier = mcInfo.modifier;
    this->excuteTime = mcInfo.excuteTime;
    this->unexcuteTime = mcInfo.unexcuteTime;
    return *this;
}

