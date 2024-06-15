#include "templatelibview.h"
#include "ui_templatelibview.h"

#include "Language/language.h"
#include "TimeSynchronization/Manage/timesync.h"
#include "ITemplateLib/Subscriber/templatelibsubscriber.h"

#include <QRegExpValidator>
#include <QtConcurrent/QtConcurrent>


TemplateLibView::TemplateLibView(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::TemplateLibView)
{
    ui->setupUi(this);
}

TemplateLibView::~TemplateLibView()
{
    delete ui;
}

void TemplateLibView::ConstructFinished()
{

}

void TemplateLibView::setWidgets()
{
    p_TemplateLibBoard = new TemplateLibOperateBoard("TemplateLibOperateBoard", this);
    p_TemplateLibBoard->ItemInitialize();
    ui->vly_RecipeOperateBoard_3->addWidget(p_TemplateLibBoard);
    connect(this, &AuthorityWidget::Signal_ConstructFinished, p_TemplateLibBoard, &AuthorityWidget::ConstructFinished);


    p_TemplateLibEditView = new TemplateLibEditView("TemplateLibEdit", this);
    p_TemplateLibEditView->ItemInitialize();
    ui->stw_TemplateLibContent->addWidget(p_TemplateLibEditView);
}

void TemplateLibView::setWidgetStyleSheet()
{
    QFont font = StyleSheet::getInstance()->Font();
    ui->gpb_TemplateLibBoard->SetheaderFontSize(16);
    ui->gpb_TemplateLibBoard->SetHeaderText(Language::getInstance()->Translate("TemplateLib List"));

    ui->gpb_TemplateLibInfo->SetheaderFontSize(16);
    ui->gpb_TemplateLibInfo->SetHeaderText(Language::getInstance()->Translate("Template Basic Information"));

    foreach(UC_TString *uts, ui->gpb_TemplateLibInfo->findChildren<UC_TString *>())
    {
        uts->setStyleSheet(StyleSheet::getInstance()->fontStyle_normal_12 + "QLabel{color: " + "#000000" + ";}");
    }
}

void TemplateLibView::setLanguageKeys()
{
    Language::getInstance()->Translate("TemplateLib List");
    Language::getInstance()->Translate("TemplateLib Type");
    Language::getInstance()->Translate("Selected TemplateLib");
    Language::getInstance()->Translate("Filter");
    Language::getInstance()->Translate("New");
    Language::getInstance()->Translate("Edit");
    Language::getInstance()->Translate("Cancel");
    Language::getInstance()->Translate("Save");
    Language::getInstance()->Translate("Copy");
    Language::getInstance()->Translate("Delete");
    Language::getInstance()->Translate("TemplateLib Name");
    Language::getInstance()->Translate("Template Basic Information");
}

void TemplateLibView::setConnections()
{
    connect(this, &AuthorityWidget::Signal_ConstructFinished, p_TemplateLibEditView, &AuthorityWidget::ConstructFinished);
    connect(p_TemplateLibBoard, &TemplateLibOperateBoard::sig_TemplateInfo, ui->wdg_TemplateLibInfo, &TemplateLibInfoView::on_TemplateInfo);
    connect(p_TemplateLibBoard, &TemplateLibOperateBoard::sig_TemplateContent, this, &TemplateLibView::loadTemplateLibContent);

    connect(p_TemplateLibBoard, &TemplateLibOperateBoard::sig_CancelTemplate, this, [ = ]()
    {
        qDebug() << "---sig_CancelTemplate---";
        S_TemplateInfo emptyInfo;
        S_TemplateLibContent emptyContent;
        QByteArray ba_emptyInfo = emptyInfo.toRawJson();
        QByteArray ba_emptyContent = emptyContent.toRawJson();
        loadTemplateLibInfo(ba_emptyInfo);
        loadTemplateLibContent(ba_emptyContent);
    });

    connect(p_TemplateLibBoard, &TemplateLibOperateBoard::sig_EditViewStatus, p_TemplateLibEditView, &TemplateLibEditView::setEditorStatus);
    connect(p_TemplateLibBoard, &TemplateLibOperateBoard::sig_InfoViewStatus, ui->wdg_TemplateLibInfo, &TemplateLibInfoView::setEditorStatus);
    connect(p_TemplateLibBoard, &TemplateLibOperateBoard::sig_SaveTemplate, this, &TemplateLibView::saveTemplate);
}

void TemplateLibView::saveTemplate(S_List_String m_TemplateNames, QString preTemplateName, bool isModify)
{
    ui->wdg_TemplateLibInfo->dumpUI();
    this->tempInfo = ui->wdg_TemplateLibInfo->m_TemplateInfo;

    if(this->tempInfo.templateType.isEmpty())
    {
        MessageDialog dlg(MessageDialog::Error, this, Language::getInstance()->Translate("E_RcpName_Empty"));
        dlg.exec();
        return ;
    }

    if(this->tempInfo.templateType.length() != 9)
    {
        MessageDialog dlg(MessageDialog::Error, this, Language::getInstance()->Translate("E_RcpName_LengthError"));
        dlg.exec();
        return ;
    }

    if(!isModify)
    {
        bool res = m_TemplateNames.values.contains(this->tempInfo.templateType);
        if (res)
        {
            MessageDialog dlg(MessageDialog::Error, this, Language::getInstance()->Translate("E_RcpName_Repeat_Create"));
            dlg.exec();
            return ;
        }
    }
    else
    {
        bool res = (this->tempInfo.templateType != preTemplateName) && m_TemplateNames.values.contains(this->tempInfo.templateType);
        if (res)
        {
            MessageDialog dlg(MessageDialog::Error, this, Language::getInstance()->Translate("E_RcpName_Repeat_Modify"));
            dlg.exec();
            return ;
        }
    }

    if(isModify)
    {
        S_TemplateInfo preTemplateInfo = this->tempInfo;
        preTemplateInfo.templateType = preTemplateName;
        m_Publisher.Publish("TemplateLib", EnumConverter::ConvertToString(CMD_TemplateLib::CMD_Delete), false, preTemplateInfo.toRawJson());
        this->tempInfo.modifier = user.userName;
        this->tempInfo.modifiedTime = Time()->TimeToString();
    }
    else
    {
        this->tempInfo.creator = user.userName;
        this->tempInfo.createdTime = Time()->TimeToString();
    }

    p_TemplateLibEditView->dumpUi();
    QByteArray Serialized_template = this->tempInfo.toRawJson() + "#" + p_TemplateLibEditView->templateLib.templateLibContent.toRawJson();
    m_Publisher.Publish("TemplateLib", EnumConverter::ConvertToString(CMD_TemplateLib::CMD_Save), false, Serialized_template);
    p_TemplateLibBoard->statusChangedAfterSave();
}

void TemplateLibView::loadTemplateLibInfo(QByteArray &data)
{
    S_TemplateInfo templateInfo;
    templateInfo.fromJson(data);
    ui->wdg_TemplateLibInfo->on_TemplateInfo(templateInfo);
}

void TemplateLibView::loadTemplateLibContent(QByteArray &data)
{
    S_TemplateLibContent emptyContent;
    p_TemplateLibEditView->templateLib.templateLibContent = emptyContent;
    p_TemplateLibEditView->templateLib.templateLibContent.fromJson(data);
    p_TemplateLibEditView->loadUi();
}

