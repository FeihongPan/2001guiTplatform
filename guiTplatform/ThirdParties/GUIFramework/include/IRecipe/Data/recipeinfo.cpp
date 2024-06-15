#include "recipeinfo.h"

S_RecipeInfo::S_RecipeInfo()
{
    recipeType = Recipe_Enum::Released;
}

S_RecipeInfo::S_RecipeInfo(const S_RecipeInfo &rcp)
{
    this->rcpName = rcp.rcpName;
    this->rcpVersion = rcp.rcpVersion;
    this->description = rcp.description;
    this->creator = rcp.creator;
    this->createdTime = rcp.createdTime;
    this->modifier = rcp.modifier;
    this->modifiedTime = rcp.modifiedTime;
    this->releaser = rcp.releaser;
    this->releasedTime = rcp.releasedTime;
    this->recipeType = rcp.recipeType;
}

S_RecipeInfo &S_RecipeInfo::operator=(const S_RecipeInfo &rcp)
{
    this->rcpName = rcp.rcpName;
    this->rcpVersion = rcp.rcpVersion;
    this->description = rcp.description;
    this->creator = rcp.creator;
    this->createdTime = rcp.createdTime;
    this->modifier = rcp.modifier;
    this->modifiedTime = rcp.modifiedTime;
    this->releaser = rcp.releaser;
    this->releasedTime = rcp.releasedTime;
    this->recipeType = rcp.recipeType;
    return *this;
}

S_RecipeNames::S_RecipeNames()
{

}

S_RecipeNames::S_RecipeNames(const S_RecipeNames &names)
{
    this->lst_Relesed = names.lst_Relesed;
    this->lst_UnRelesed = names.lst_UnRelesed;
}

S_RecipeNames &S_RecipeNames::operator=(const S_RecipeNames &names)
{
    this->lst_Relesed = names.lst_Relesed;
    this->lst_UnRelesed = names.lst_UnRelesed;
    return *this;
}
