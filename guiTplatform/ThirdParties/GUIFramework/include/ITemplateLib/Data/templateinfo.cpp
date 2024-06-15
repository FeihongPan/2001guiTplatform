#include "templateinfo.h"

S_TemplateInfo::S_TemplateInfo()
{

}

S_TemplateInfo::S_TemplateInfo(const S_TemplateInfo &info)
{
    this->templateType = info.templateType;
    this->creator = info.creator;
    this->createdTime = info.createdTime;
    this->modifier = info.modifier;
    this->modifiedTime = info.modifiedTime;
    this->description = info.description;
}

S_TemplateInfo &S_TemplateInfo::operator=(const S_TemplateInfo &info)
{
    this->templateType = info.templateType;
    this->creator = info.creator;
    this->createdTime = info.createdTime;
    this->modifier = info.modifier;
    this->modifiedTime = info.modifiedTime;
    this->description = info.description;
    return *this;
}

bool S_TemplateInfo::operator==(const S_TemplateInfo &info)
{
    return this->templateType == info.templateType;
}

bool S_TemplateInfo::operator!=(const S_TemplateInfo &info)
{
    return !(*this == info);
}

S_TemplateNames::S_TemplateNames()
{

}

S_TemplateNames::S_TemplateNames(const S_TemplateNames &names)
{
    this->lst_Names = names.lst_Names;
}

S_TemplateNames &S_TemplateNames::operator=(const S_TemplateNames &names)
{
    this->lst_Names = names.lst_Names;
    return *this;
}

