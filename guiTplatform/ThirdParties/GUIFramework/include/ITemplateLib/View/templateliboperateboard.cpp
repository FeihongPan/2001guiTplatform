#include "templateliboperateboard.h"
#include "ui_templateliboperateboard.h"
#include "AppConfig/AppParameter.h"
#include "Communication/MQTT/mqttclientmanager.h"
#include "ITemplateLib/Command/cmd_templatelib.h"
#include "ITemplateLib/Subscriber/templatelibsubscriber.h"
#include "TimeSynchronization/Manage/timesync.h"

TemplateLibOperateBoard::TemplateLibOperateBoard(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::TemplateLibOperateBoard)
{
    ui->setupUi(this);
    modelInitialize();
    m_Publisher.LinkToClient(MqttClientManager::getInstance()->GetClient(0), PublishTopicPrefix);

    //    m_SelectedRecipeType.SetEnumValue<Recipe_Enum::RecipeType>(0);
    //    Binding(&m_SelectedRecipeType, ui->cmb_RecipeType);
    //    Binding(&m_SelectedRecipeName, ui->led_SelectedRecipeName);
}

TemplateLibOperateBoard::~TemplateLibOperateBoard()
{
    delete ui;
}

void TemplateLibOperateBoard::ConstructFinished()
{
    m_Publisher.Publish("TemplateLib", EnumConverter::ConvertToString(CMD_TemplateLib::CMD_Names));
}

void TemplateLibOperateBoard::setWidgets()
{

}

void TemplateLibOperateBoard::setWidgetStyleSheet()
{
    //    ui->lbl_RecipeType->setText(Tr("Recipe Type"));
    //    ui->lbl_SelectedRecipeName->setText(Tr("Selected Recipe"));
    ui->lbl_Filter_2->setText(Tr("Filter"));

    //    ui->led_SelectedRecipeName->setEnabled(false);
    ui->led_SearchValue_2->setStyleSheet(StyleSheet::getInstance()->LineEdit_Dark + StyleSheet::getInstance()->fontStyle_qlineEdit_normal_12);
    ui->led_SearchValue_2->SetIconDock(IconLineEdit::Right);
    ui->led_SearchValue_2->SetIconFont(StyleSheet::getInstance()->Font());
    ui->led_SearchValue_2->setTextMargins(0, 0, 35, 0);
    ui->led_SearchValue_2->SetIcon(QString(0xa024), 14);

    //    ui->lbl_RecipeType_2->setStyleSheet(StyleSheet::getInstance()->fontStyle_normal_12);
    //    ui->lbl_SelectedRecipeName_2->setStyleSheet(StyleSheet::getInstance()->fontStyle_normal_12);
    ui->lbl_Filter_2->setStyleSheet(StyleSheet::getInstance()->fontStyle_normal_12);
    //    ui->cmb_RecipeType_2->setStyleSheet(StyleSheet::getInstance()->ComboBox + StyleSheet::getInstance()->fontStyle_normal_12);
    //    ui->led_SelectedRecipeName_2->setStyleSheet(StyleSheet::getInstance()->LineEdit_Dark + StyleSheet::getInstance()->fontStyle_normal_12);
    //    ui->tbw_Recipes_2->setStyleSheet(StyleSheet::getInstance()->tabStyle + StyleSheet::getInstance()->fontStyle_normal_12);

    QFont font = StyleSheet::getInstance()->Font();
    ui->btn_New_2->setFont(font);
    ui->btn_New_2->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_New_2->SetVertivalStyle(font, QString(0xa44), 30, Language::getInstance()->Translate("New"), 12, QFont::Bold);
    ui->btn_New_2->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_New_2->setEnabled(false);

    ui->btn_Edit_2->setFont(font);
    ui->btn_Edit_2->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_Edit_2->SetVertivalStyle(font, QString(0xa51), 28, Language::getInstance()->Translate("Edit"), 12, QFont::Bold);
    ui->btn_Edit_2->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_Edit_2->setEnabled(false);

    ui->btn_Cancel_2->setFont(font);
    ui->btn_Cancel_2->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_Cancel_2->SetVertivalStyle(font, QString(0xa46), 30, Language::getInstance()->Translate("Cancel"), 12, QFont::Bold);
    ui->btn_Cancel_2->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_Cancel_2->setEnabled(false);

    //    ui->btn_Copy_2->setFont(font);
    //    ui->btn_Copy_2->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    //    ui->btn_Copy_2->SetVertivalStyle(font, QString(0xa54), 30, Language::getInstance()->Translate("Copy"), 12, QFont::Bold);
    //    ui->btn_Copy_2->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    //    ui->btn_Copy_2->setEnabled(false);

    ui->btn_Save_2->setFont(font);
    ui->btn_Save_2->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_Save_2->SetVertivalStyle(font, QString(0xa50), 30, Language::getInstance()->Translate("Save"), 12, QFont::Bold);
    ui->btn_Save_2->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_Save_2->setEnabled(false);


    ui->btn_Delete_2->setFont(font);
    ui->btn_Delete_2->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_Delete_2->SetHorizontalStyle(font, QString(0xa53), 30, Language::getInstance()->Translate("Delete"), 12, QFont::Bold);
    ui->btn_Delete_2->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_Delete_2->setEnabled(false);
}

void TemplateLibOperateBoard::setLanguageKeys()
{
    Tr("Recipe List");
    //    Tr("Recipe Type");
    //    Tr("Selected Recipe");
    Tr("Filter");
    Tr("New");
    Tr("Edit");
    Tr("Cancel");
    Tr("Save");
    Tr("Copy");
    Tr("Release");
    Tr("Delete");
}

void TemplateLibOperateBoard::setConnections()
{
    connect(TemplateLibSubscriber::getInstance(), &TemplateLibSubscriber::sig_TemplateNames, this, [ = ](S_List_String & templateNames)
    {
        //获取当前
        QModelIndex index = ui->tbw_Template->currentIndex();
        this->m_TemplateNames = templateNames;
        p_TemplateLibModel->resetModel(m_TemplateNames.values);
        setEditorStatus();
        if(index.row() > 0 && p_TemplateLibModel->rowCount() > index.row())
        {
            ui->tbw_Template->selectRow(index.row());
            ui->tbw_Template->clicked(index);
        }
    });

    connect(ui->tbw_Template, &QTableView::clicked, this, [ = ](const QModelIndex & index)
    {
        m_SelectedTemplateName = ui->tbw_Template->model()->data(index, Qt::UserRole).value<QString>();
        S_TemplateInfo tempInfo;
        tempInfo.templateType = m_SelectedTemplateName;

        m_Publisher.Publish("TemplateLib", EnumConverter::ConvertToString(CMD_TemplateLib::CMD_Info), false, tempInfo.toRawJson());
        //        m_Publisher.Publish("TemplateLib", EnumConverter::ConvertToString(CMD_TemplateLib::CMD_Content), false, tempInfo.toRawJson());
        setEditorStatus();
    });

    connect(ui->led_SearchValue_2, &QLineEdit::textChanged, this, [ = ](QString str)
    {
        for(int i = 0; i < ui->tbw_Template->model()->rowCount(); i++)
        {
            ui->tbw_Template->setRowHidden(i, true);
            QAbstractItemModel *model = ui->tbw_Template->model();
            QModelIndex index;
            index = model->index(i, 1);
            if(model->data(index).toString().contains(str, Qt::CaseInsensitive))
            {
                ui->tbw_Template->setRowHidden(i, false);
            }
        }
    });

    connect(ui->btn_New_2, &QPushButton::clicked, this, [ = ]()
    {
        this->m_bIsModify = false;
        m_Publisher.Publish("TemplateLib", EnumConverter::ConvertToString(CMD_TemplateLib::CMD_New));
        status = ViewStatus::Modifying;
        emit ViewStatusChanged(status);
        setEditorStatus();
    });

    connect(ui->btn_Edit_2, &QPushButton::clicked, this, [ = ]()
    {
        if (ui->tbw_Template->currentIndex().isValid())
        {
            this->m_bIsModify = true;
            status = ViewStatus::Modifying;
            emit ViewStatusChanged(status);
            setEditorStatus();
        }
    });

    connect(ui->btn_Cancel_2, &QPushButton::clicked, this, [ = ]()
    {
        MessageDialog dlg(MessageDialog::Attention, this, Language::getInstance()->Translate("TemplateName_Edit_Cancel?"));
        if(dlg.exec() == QDialog::Accepted)
        {
            emit sig_CancelTemplate();
        }
        else
        {
            return;
        }
        status = ViewStatus::Idle;
        emit ViewStatusChanged(status);

        p_TemplateLibModel->resetModel(m_TemplateNames.values);

        setEditorStatus();
    });

    connect(ui->btn_Save_2, &QPushButton::clicked, this, [ = ]()
    {
        qDebug() << "--------------m_bIsModify:-------------" << m_bIsModify;
        emit sig_SaveTemplate(m_TemplateNames, m_SelectedTemplateName, m_bIsModify);
    });


    connect(ui->btn_Delete_2, &QPushButton::clicked, this, [ = ]()
    {
        if (ui->tbw_Template->currentIndex().isValid())
        {
            MessageDialog dlg(MessageDialog::Attention, this, Language::getInstance()->Translate("E_TemplateName_Delete"));
            if(dlg.exec() == QDialog::Accepted)
            {
                m_Publisher.Publish("TemplateLib", EnumConverter::ConvertToString(CMD_TemplateLib::CMD_Delete), false, m_TemplateInfo.toRawJson());
            }
            else
            {
                return;
            }
        }
    });

    connect(TemplateLibSubscriber::getInstance(), &TemplateLibSubscriber::sig_NewTemplateLib, this, [ = ](S_TemplateInfo & info)
    {
        this->m_TemplateInfo = info;
        emit sig_TemplateInfo(m_TemplateInfo);
        QByteArray ba_empty = "";
        emit sig_TemplateContent(ba_empty);
    });

    connect(TemplateLibSubscriber::getInstance(), &TemplateLibSubscriber::sig_TemplateLib, this, [ = ](QByteArray & content)
    {
        QList<QByteArray> lst_ba = content.split('#');
        if(lst_ba.count() == 2)
        {
            this->m_TemplateInfo.fromJson(lst_ba[0]);
            emit sig_TemplateInfo(m_TemplateInfo);
            emit sig_TemplateContent(lst_ba[1]);
        }
    });

    connect(TemplateLibSubscriber::getInstance(), &TemplateLibSubscriber::sig_TemplateContent, this, [ = ](QByteArray & content)
    {
        this->m_byte_TemplateContent = content;
        emit sig_TemplateContent(content);
    });
}

void TemplateLibOperateBoard::setEditorStatus()
{
    bool bTableSelected = ui->tbw_Template->currentIndex().isValid();

    if(status == ViewStatus::Idle)
    {
        ui->btn_Save_2->setEnabled(false);
        ui->btn_Cancel_2->setEnabled(false);
        ui->btn_New_2->setEnabled(true);
        ui->btn_Edit_2->setEnabled(bTableSelected);
        //        ui->btn_Copy_2->setEnabled(bTableSelected);
        ui->btn_Delete_2->setEnabled(bTableSelected);
        ui->led_SearchValue_2->setEnabled(true);
        ui->tbw_Template->setEnabled(true);
        emit sig_EditViewStatus(false);
        emit sig_InfoViewStatus(false);
    }
    else
    {
        ui->btn_Save_2->setEnabled(true);
        ui->btn_Cancel_2->setEnabled(true);
        //        ui->btn_Copy_2->setEnabled(false);
        ui->btn_Delete_2->setEnabled(false);
        ui->btn_Edit_2->setEnabled(false);
        ui->btn_New_2->setEnabled(false);
        ui->led_SearchValue_2->setEnabled(false);
        ui->tbw_Template->setEnabled(false);
        emit sig_EditViewStatus(true);
        emit sig_InfoViewStatus(true);
    }
}

void TemplateLibOperateBoard::modelInitialize()
{
    p_TemplateLibModel = new TemplateLibModel(this);
    p_TemplateLibModel->SetModel(m_TemplateNames.values);
    ui->tbw_Template->setModel(p_TemplateLibModel);
    ui->tbw_Template->setColumnWidth(0, 60);
}

void TemplateLibOperateBoard::statusChangedAfterSave()
{
    status = ViewStatus::Idle;
    emit ViewStatusChanged(status);
    setEditorStatus();
}
