#include "recipeview.h"
#include "ui_recipeview.h"
#include "Language/language.h"
#include "TimeSynchronization/Manage/timesync.h"
#include "IRecipe/Command/cmd_recipe.h"
#include "IRecipe/View/recipeoperateboard.h"
#include "IRecipe/Subscriber/recipesubscriber.h"

#include <QRegExpValidator>
#include <QtConcurrent/QtConcurrent>

#include <QDebug>

RecipeView::RecipeView(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::RecipeView)
{
    ui->setupUi(this);
}

RecipeView::~RecipeView()
{
    delete ui;
}

void RecipeView::ConstructFinished()
{

}

S_Recipe RecipeView::CreateNewRecipe(QStringList lst_ExistNames)
{
    S_Recipe newRecipe;
    bool repeat = true;
    int index = -1;

    while (repeat)
    {
        index++;
        if(lst_ExistNames.count() > 0)
        {
            for(int i = 0; i < lst_ExistNames.count(); i++)
            {
                QStringList lst = lst_ExistNames.at(i).split('_', QString::SkipEmptyParts);
                if (lst.count() == 2 && lst.at(0) == "Recipe" && lst.at(1) == QString::number(index))
                {
                    repeat = true;
                    break;
                }
                else
                {
                    repeat = false;
                }
            }
        }
        else
        {
            repeat = false;
        }
    }

    newRecipe.recipeInfo.rcpName = "Recipe_" + QString::number(index);
    newRecipe.recipeInfo.recipeType = Recipe_Enum::UnReleased;
    return newRecipe;
}

void RecipeView::setWidgets()
{
    p_RecipeBoard = new RecipeOperateBoard("RecipeOperateBoard", this);
    p_RecipeBoard->ItemInitialize();
    ui->vly_RecipeOperateBoard->addWidget(p_RecipeBoard);
    connect(this, &AuthorityWidget::Signal_ConstructFinished, p_RecipeBoard, &AuthorityWidget::ConstructFinished);


    p_RecipeEditView = new RecipeEditView("RecipeEdit", this);
    p_RecipeEditView->ItemInitialize();
    ui->stw_Recipe->addWidget(p_RecipeEditView);
}

void RecipeView::setWidgetStyleSheet()
{
    QFont font = GlobalStyleSheet->Font();

    ui->gpb_Recipe->SetheaderFontSize(16);
    //    ui->gpb_Recipe->setStyleSheet(globalStyle->fontStyle_normal_16);
    ui->gpb_Recipe->SetHeaderText(Tr("Recipe List"));


    ui->gpb_RecipeInfo->SetheaderFontSize(16);
    ui->gpb_RecipeInfo->SetHeaderText(Tr("Recipe Basic Information"));

    foreach(UC_TString *uts, ui->gpb_RecipeInfo->findChildren<UC_TString *>())
    {
        uts->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12 + "QLabel{color: " + "#000000" + ";}");
    }
}

void RecipeView::setLanguageKeys()
{
    Tr("Recipe List");
    Tr("Recipe Type");
    Tr("Selected Recipe");
    Tr("Filter");
    Tr("New");
    Tr("Edit");
    Tr("Cancel");
    Tr("Save");
    Tr("Copy");
    Tr("Release");
    Tr("Delete");
    Tr("Recipe Name");
    Tr("Recipe Basic Information");
}

void RecipeView::setConnections()
{
    connect(this, &AuthorityWidget::Signal_ConstructFinished, p_RecipeEditView, &AuthorityWidget::ConstructFinished);

    connect(RecipeSubscriber::getInstance(), &RecipeSubscriber::sig_Recipe, this, [ = ](QByteArray & data)
    {
        qDebug() << "------------enter connect sig_Recipe in recipeview";
        QList<QByteArray> lst_data = data.split('#');
        if(lst_data.count() == 2)
        {
            loadRecipeInfo(lst_data[0]);
            loadRecipeContent(lst_data[1]);
        }
    });

    connect(p_RecipeBoard, &RecipeOperateBoard::sig_RecipeInfo, ui->wdg_RecipeInfo, &RecipeInfoView::on_RecipeInfo);
    connect(p_RecipeBoard, &RecipeOperateBoard::sig_RecipeContent, this, &RecipeView::loadRecipeContent);

    connect(p_RecipeBoard, &RecipeOperateBoard::sig_CancelRecipe, this, [ = ]()
    {
        QByteArray emptyRecipeInfo = emptyRecipe.recipeInfo.toRawJson();
        loadRecipeInfo(emptyRecipeInfo);

        QByteArray emptyRecipeContent = emptyRecipe.recipeContent.toRawJson();
        loadRecipeContent(emptyRecipeContent);
    });

    connect(p_RecipeBoard, &RecipeOperateBoard::sig_EditViewStatus, p_RecipeEditView, &RecipeEditView::setEditorStatus);
    connect(p_RecipeBoard, &RecipeOperateBoard::sig_InfoViewStatus, ui->wdg_RecipeInfo, &RecipeInfoView::setEditorStatus);
    connect(p_RecipeBoard, &RecipeOperateBoard::sig_SaveRecipe, this, &RecipeView::saveRecipe);
}

void RecipeView::saveRecipe(S_RecipeNames &m_RecipeNames, QString preRecipeName, bool isModify)
{
    ui->wdg_RecipeInfo->dumpUI();
    this->recipe.recipeInfo = ui->wdg_RecipeInfo->m_RecipeInfo;

    if(this->recipe.recipeInfo.rcpName.isEmpty())
    {
        MessageDialog dlg(MessageDialog::Error, this, Language::getInstance()->Translate("E_RcpName_Empty"));
        dlg.exec();
        return ;
    }
    if(this->recipe.recipeInfo.rcpName.length() < 6 || this->recipe.recipeInfo.rcpName.length() > 20)
    {
        MessageDialog dlg(MessageDialog::Error, this, Language::getInstance()->Translate("E_RcpName_LengthError"));
        dlg.exec();
        return ;
    }

    QRegExp re("[a-zA-Z_][a-zA-Z0-9_]*$");
    QRegExpValidator validator(re, this);
    int pos = 0;
    if(QValidator::Acceptable != validator.validate(this->recipe.recipeInfo.rcpName, pos))
    {
        MessageDialog dlg(MessageDialog::Error, this, Language::getInstance()->Translate("E_RcpName_FormatError"));
        dlg.exec();
        return ;
    }

    if(!p_RecipeBoard)
    {
        bool res_r = m_RecipeNames.lst_Relesed.contains(this->recipe.recipeInfo.rcpName);
        bool res_u = m_RecipeNames.lst_UnRelesed.contains(this->recipe.recipeInfo.rcpName);
        if (res_r || res_u)
        {
            MessageDialog dlg(MessageDialog::Error, this, Language::getInstance()->Translate("E_RcpName_Repeat_Create"));
            dlg.exec();
            return ;
        }
    }
    else
    {
        bool res_r = (this->recipe.recipeInfo.rcpName != preRecipeName) && m_RecipeNames.lst_Relesed.contains(this->recipe.recipeInfo.rcpName);
        bool res_u = (this->recipe.recipeInfo.rcpName != preRecipeName) && m_RecipeNames.lst_UnRelesed.contains(this->recipe.recipeInfo.rcpName);
        if (res_r || res_u)
        {
            MessageDialog dlg(MessageDialog::Error, this, Language::getInstance()->Translate("E_RcpName_Repeat_Modify"));
            dlg.exec();
            return ;
        }
    }
    if(isModify)
    {
        S_RecipeInfo preRecipeInfo = this->recipe.recipeInfo;
        preRecipeInfo.rcpName = preRecipeName;
        m_Publisher.Publish("Recipe", EnumConverter::ConvertToString(CMD_Recipe::CMD_DeleteRcp), false, preRecipeInfo.toRawJson());
        this->recipe.recipeInfo.modifier = user.userName;
        this->recipe.recipeInfo.modifiedTime = Time()->TimeToString();
    }
    else
    {
        this->recipe.recipeInfo.creator = user.userName;
        this->recipe.recipeInfo.createdTime = Time()->TimeToString();
    }

    p_RecipeEditView->dumpUi();
    this->recipe.recipeContent = p_RecipeEditView->recipe.recipeContent;
    QByteArray Serialized_recipe = this->recipe.recipeInfo.toRawJson() + "#" + this->recipe.recipeContent.toRawJson() ;
    m_Publisher.Publish("Recipe", EnumConverter::ConvertToString(CMD_Recipe::CMD_SaveRcp), false, Serialized_recipe);
    p_RecipeBoard->statusChangedAfterSave();
}

void RecipeView::loadRecipeInfo(QByteArray &data)
{
    S_RecipeInfo recipeInfo;
    recipeInfo.fromJson(data);
    ui->wdg_RecipeInfo->on_RecipeInfo(recipeInfo);
}

void RecipeView::loadRecipeContent(QByteArray &data)
{
    S_RecipeContent recipeContent;
    recipeContent.fromJson(data);
    p_RecipeEditView->recipe.recipeContent = recipeContent;
    p_RecipeEditView->loadUi();
}
