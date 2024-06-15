#ifndef RECIPE_ENUM_H
#define RECIPE_ENUM_H

#include <QObject>

class Recipe_Enum : public QObject
{
    Q_OBJECT
public:
    enum RecipeType
    {
        Released,
        UnReleased,
    };
    Q_ENUM(RecipeType)

    explicit Recipe_Enum(QObject *parent = nullptr);

signals:

};

#endif // RECIPE_ENUM_H
