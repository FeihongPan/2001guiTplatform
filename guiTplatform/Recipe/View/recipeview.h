#ifndef RECIPEVIEW_H
#define RECIPEVIEW_H

#include "AuthorityComponent/authoritywidget.h"
#include "BasicValue/serializablelist.h"
#include "IRecipe/Data/recipeinfo.h"
#include "IRecipe/View/recipeoperateboard.h"
#include "Recipe/Data/recipe.h"
#include "Recipe/View/recipemodel.h"
#include "Recipe/View/recipeeditview.h"

#include <QWidget>

namespace Ui
{
    class RecipeView;
}

class RecipeView : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit RecipeView(QString name, QWidget *parent = nullptr);
    ~RecipeView();

signals:
    void sig_RecipeInfo(S_RecipeInfo &recipeInfo);

public slots:
    virtual void ConstructFinished() override;
    void saveRecipe(S_RecipeNames &m_RecipeNames, QString preRecipeName, bool isModify);

public:
    S_Recipe CreateNewRecipe(QStringList lst_ExistNames);
    RecipeEditView *p_RecipeEditView;
    void loadRecipeInfo(QByteArray &data);
    void loadRecipeContent(QByteArray &data);

private:
    virtual void setWidgets() override;
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;
    virtual void setConnections() override;

private:
    Ui::RecipeView *ui;
    S_RecipeInfo recipe_Keep;
    S_Recipe recipe;
    S_Recipe emptyRecipe;
    TEnum recipeType;
    RecipeModel *recipeModel;
    TString selectedRecipeName;
    S_RecipeNames recipeNames;
    bool isModify{false};

    RecipeOperateBoard *p_RecipeBoard = nullptr;
};

#endif // RECIPEVIEW_H
