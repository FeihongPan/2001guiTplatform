#ifndef RECIPEOPERATEBOARD_H
#define RECIPEOPERATEBOARD_H

#include "GUIFramework_global.h"
#include "AuthorityComponent/authoritywidget.h"
#include "IRecipe/View/recipemodel.h"
#include "IRecipe/Data/recipeinfo.h"

#include <QWidget>

namespace Ui
{
    class RecipeOperateBoard;
}

class GUIFRAMEWORK_EXPORT RecipeOperateBoard : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit RecipeOperateBoard(QString name, QWidget *parent = nullptr);
    ~RecipeOperateBoard();

    void statusChangedAfterSave();

    virtual void ConstructFinished() override;

signals:
    void sig_RecipeInfo(S_RecipeInfo &info);
    void sig_RecipeContent(QByteArray &content);
    void sig_SaveRecipe(S_RecipeNames &m_RecipeNames, QString preRecipeName, bool isModify);
    void sig_CancelRecipe();
    void sig_EditViewStatus(bool status);
    void sig_InfoViewStatus(bool status);
    //    void sig_modifyInfo(S_RecipeInfo &m_RecipeInfo);

protected:
    virtual void setWidgets() override;

    virtual void setWidgetStyleSheet() override;

    virtual void setLanguageKeys() override;

    virtual void setConnections() override;

public slots:
    //    void on_RecipeInfo(S_RecipeInfo &rcp);

private:
    void setEditorStatus();

    void modelInitialize();

private:
    Ui::RecipeOperateBoard *ui;
    TEnum m_SelectedRecipeType;
    TString m_SelectedRecipeName;
    S_RecipeNames m_RecipeNames;
    RecipeModel *p_RecipeModel;
    bool m_bIsModify = false;
    S_RecipeInfo m_RecipeInfo;
    QByteArray m_byte_RecipeContent;
};

#endif // RECIPEOPERATEBOARD_H
