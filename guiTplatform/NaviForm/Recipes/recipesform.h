#ifndef RECIPESFORM_H
#define RECIPESFORM_H

#include "AuthorityComponent/authoritywidget.h"
#include "Recipe/View/recipeview.h"
#include "TemplateLib/View/templatelibview.h"

#include <QWidget>

namespace Ui
{
    class RecipesForm;
}

class RecipesForm : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit RecipesForm(QString name, QWidget *parent = nullptr);
    ~RecipesForm();

public slots:
    virtual void ConstructFinished() override;

private:
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;

private:
    Ui::RecipesForm *ui;

    RecipeView *recipeView = NULL;
    RecipeEditView *recipeEditView = NULL;

    TemplateLibView *templateLibView = NULL;
    TemplateLibEditView *templateLibEditView = NULL;
};

#endif // RECIPESFORM_H
