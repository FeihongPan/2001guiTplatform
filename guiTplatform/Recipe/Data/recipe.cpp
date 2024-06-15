#include "recipe.h"

S_Recipe::S_Recipe()
{

}

S_Recipe::S_Recipe(const S_Recipe &rcp)
{
    this->recipeInfo = rcp.recipeInfo;
    this->recipeContent = rcp.recipeContent;
}

S_Recipe &S_Recipe::operator=(const S_Recipe &rcp)
{
    this->recipeInfo = rcp.recipeInfo;
    this->recipeContent = rcp.recipeContent;
    return *this;
}
