#ifndef TEMPLATELIBOPERATEBOARD_H
#define TEMPLATELIBOPERATEBOARD_H

#include "AuthorityComponent/authoritywidget.h"
#include "ITemplateLib/View/templatelibmodel.h"
#include "ITemplateLib/Data/templateinfo.h"
#include "BasicValue/serializablelist.h"
#include <QWidget>

namespace Ui
{
    class TemplateLibOperateBoard;
}

class GUIFRAMEWORK_EXPORT TemplateLibOperateBoard : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit TemplateLibOperateBoard(QString name, QWidget *parent = nullptr);
    ~TemplateLibOperateBoard();

    void statusChangedAfterSave();

    virtual void ConstructFinished() override;

signals:
    void sig_TemplateInfo(S_TemplateInfo &info);
    void sig_TemplateContent(QByteArray &content);
    void sig_SaveTemplate(S_List_String m_TemplateNames, QString m_SelectedTemplateName, bool isModify);
    void sig_CancelTemplate();
    void sig_EditViewStatus(bool status);
    void sig_InfoViewStatus(bool status);

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
    Ui::TemplateLibOperateBoard *ui;
    //    TEnum m_SelectedRecipeType;
    //    TString m_SelectedRecipeName;
    QString m_SelectedTemplateName;
    S_List_String m_TemplateNames;
    TemplateLibModel *p_TemplateLibModel;
    bool m_bIsModify = false;
    S_TemplateInfo m_TemplateInfo;
    QByteArray m_byte_TemplateContent;
};

#endif // TEMPLATELIBOPERATEBOARD_H
