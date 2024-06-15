#ifndef RECIPE_H
#define RECIPE_H

#include "IRecipe/Data/recipeinfo.h"
#include "recipecontent.h"
#include "Serializer/QSerializer"

#include <QObject>

class S_Recipe : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_RecipeInfo, recipeInfo)
    QS_OBJECT(S_RecipeContent, recipeContent)

public:
    S_Recipe();
    S_Recipe(const S_Recipe &rcp);
    S_Recipe &operator=(const S_Recipe &rcp);
};

#endif // RECIPE_H
