#include "recipesform.h"
#include "ui_recipesform.h"
#include "AuthorityManage/WidgetManage/authoritywdgmanager.h"

RecipesForm::RecipesForm(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::RecipesForm)
{
    ui->setupUi(this);

    setLayoutWidgets(ui->horizontalLayout, ui->stw_View, ui->frame_SubNavi);

    recipeView = new RecipeView("Recipe", this);
    recipeEditView = recipeView->p_RecipeEditView;
    AuthorityWdgManager::getInstance()->InitOpt(ui->btn_Recipe, recipeView, ui->stw_View, this, 0);


    templateLibView = new TemplateLibView("TemplateLib", this);
    templateLibEditView = templateLibView->p_TemplateLibEditView;
    AuthorityWdgManager::getInstance()->InitOpt(ui->btn_TemplateLib, templateLibView, ui->stw_View, this, 1);
}

RecipesForm::~RecipesForm()
{
    delete ui;
}

void RecipesForm::ConstructFinished()
{

}

void RecipesForm::setWidgetStyleSheet()
{
    QFont font = GlobalStyleSheet->Font();
    ui->btn_Recipe->SetVertivalStyle(font, QString(0xa023), 30, Tr("Recipe"), 12, QFont::Bold);
    ui->btn_Recipe->setStyleSheet(GlobalStyleSheet->SubNaviButtonStyle);
    ui->btn_TemplateLib->SetVertivalStyle(font, QString(0xa023), 30, Tr("TemplateLib"), 12, QFont::Bold);
    ui->btn_TemplateLib->setStyleSheet(GlobalStyleSheet->SubNaviButtonStyle);
}

void RecipesForm::setLanguageKeys()
{
    Tr("Recipe");
    Tr("TemplateLib");
}
