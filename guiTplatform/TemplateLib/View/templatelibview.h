#ifndef TEMPLATELIBVIEW_H
#define TEMPLATELIBVIEW_H

#include "AuthorityComponent/authoritywidget.h"
#include "BasicValue/serializablelist.h"

#include "ITemplateLib/View/templateliboperateboard.h"
#include "ITemplateLib/View/templatelibinfoview.h"
#include "ITemplateLib/Data/templateinfo.h"
#include "ITemplateLib/Data/templatespec.h"
#include "TemplateLib/View/templatelibeditview.h"
#include "TemplateLib/Data/templatelib.h"

#include <QWidget>

namespace Ui
{
    class TemplateLibView;
}

class TemplateLibView : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit TemplateLibView(QString name, QWidget *parent = nullptr);
    ~TemplateLibView();

signals:
    void sig_TemplateLibInfo(S_TemplateInfo &recipeInfo);

public slots:
    virtual void ConstructFinished() override;
    void saveTemplate(S_List_String m_TemplateNames, QString preTemplateName, bool isModify);
    void loadTemplateLibInfo(QByteArray &data);
    void loadTemplateLibContent(QByteArray &data);


public:
    //    S_Recipe CreateNewRecipe(QStringList lst_ExistNames);
    TemplateLibEditView *p_TemplateLibEditView;



private:
    virtual void setWidgets() override;
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;
    virtual void setConnections() override;

private:
    Ui::TemplateLibView *ui;
    S_TemplateInfo tempInfo;
    S_TemplateSpec tempSpec;
    //    S_TemplateLibContent tempContent;
    TString selectedRecipeName;
    QStringList templateNames;
    bool isModify{false};

    TemplateLibOperateBoard *p_TemplateLibBoard = nullptr;
};
#endif // TEMPLATELIBVIEW_H
