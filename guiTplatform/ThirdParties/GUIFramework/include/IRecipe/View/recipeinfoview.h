#ifndef RECIPEINFOVIEW_H
#define RECIPEINFOVIEW_H

#include "GUIFramework_global.h"
#include "IRecipe/Data/recipeinfo.h"
#include "IRecipe/View/recipebasicinfomation.h"

#include <QWidget>

namespace Ui
{
    class RecipeInfoView;
}

class GUIFRAMEWORK_EXPORT RecipeInfoView : public QWidget
{
    Q_OBJECT

public:
    explicit RecipeInfoView(QWidget *parent = nullptr);
    ~RecipeInfoView();

    void setEditorStatus(bool status);
    void dumpUI();

    S_RecipeInfo m_RecipeInfo;

signals:
    void sig_RecipeInfo(S_RecipeInfo &rcp);

public slots:
    void on_RecipeInfo(S_RecipeInfo &rcp);


private:
    Ui::RecipeInfoView *ui;
    bool m_bStatus;
};

#endif // RECIPEINFOVIEW_H
