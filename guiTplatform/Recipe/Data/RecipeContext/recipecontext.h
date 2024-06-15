#ifndef RECIPECONTEXT_H
#define RECIPECONTEXT_H

#include "materialinfo.h"
#include "focandlev.h"
#include "align.h"
#include "bonding.h"
#include <QSerializer>

class RecipeContext : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, Substrate, substrates)
    QS_OBJECT(FocAndLev, focAndLev)
    QS_OBJECT(Alignm, align)
    QS_OBJECT(Bonding, bonding)

public:
    RecipeContext();
    RecipeContext(const RecipeContext &recipeContext);
    RecipeContext &operator=(const RecipeContext &recipeContext);
};

#endif // RECIPECONTEXT_H
