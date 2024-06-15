#include "recipecontext.h"


RecipeContext::RecipeContext()
{
    this->substrates.append(Substrate());
    this->substrates.append(Substrate());
}

RecipeContext::RecipeContext(const RecipeContext &recipeContext)
{
    this->substrates = recipeContext.substrates;
    this->focAndLev = recipeContext.focAndLev;
    this->align = recipeContext.align;
    this->bonding = recipeContext.bonding;
}

RecipeContext &RecipeContext::operator=(const RecipeContext &recipeContext)
{
    this->substrates = recipeContext.substrates;
    this->focAndLev = recipeContext.focAndLev;
    this->align = recipeContext.align;
    this->bonding = recipeContext.bonding;
    return *this;
}
