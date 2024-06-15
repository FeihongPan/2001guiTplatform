#ifndef RECIPEINFO_H
#define RECIPEINFO_H

#include "GUIFramework_global.h"
#include "Serializer/QSerializer"
#include "recipe_enum.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT S_RecipeInfo : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

public:
    QS_FIELD(QString, rcpName)
    QS_FIELD(QString, rcpVersion)
    QS_FIELD(QString, description)
    QS_FIELD(QString, creator)
    QS_FIELD(QString, createdTime)
    QS_FIELD(QString, modifier)
    QS_FIELD(QString, modifiedTime)
    QS_FIELD(QString, releaser)
    QS_FIELD(QString, releasedTime)
    QS_FIELD(Recipe_Enum::RecipeType, recipeType)

public:
    S_RecipeInfo();
    S_RecipeInfo(const S_RecipeInfo &rcp);
    S_RecipeInfo &operator=(const S_RecipeInfo &rcp);
};

class GUIFRAMEWORK_EXPORT S_RecipeNames : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, QString, lst_Relesed)
    QS_COLLECTION(QList, QString, lst_UnRelesed)

public:
    S_RecipeNames();
    S_RecipeNames(const S_RecipeNames &names);
    S_RecipeNames &operator=(const S_RecipeNames &names);
};

#endif // RECIPEINFO_H
