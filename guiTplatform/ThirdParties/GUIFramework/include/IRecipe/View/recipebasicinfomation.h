#ifndef RECIPEBASICINFOMATION_H
#define RECIPEBASICINFOMATION_H

#include "GUIFramework_global.h"
#include "IRecipe/Data/recipeinfo.h"

#include <QDialog>

namespace Ui
{
    class RecipeBasicInfomation;
}

class GUIFRAMEWORK_EXPORT RecipeBasicInfomation : public QDialog
{
    Q_OBJECT

public:
    explicit RecipeBasicInfomation(S_RecipeInfo &rcp, bool enable, QWidget *blurWdg, QWidget *parent = nullptr);
    ~RecipeBasicInfomation();

    virtual void reject() override;

signals:
    void sig_RecipeInfo(S_RecipeInfo &rcp);

private:
    void refresh(bool enable);

private:
    Ui::RecipeBasicInfomation *ui;
    QWidget *p_BlurWdg;
    S_RecipeInfo m_RecipeInfo;
};

#endif // RECIPEBASICINFOMATION_H
