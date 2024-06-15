#include "recipeoperateboard.h"
#include "ui_recipeoperateboard.h"
#include "AppConfig/AppParameter.h"
#include "IRecipe/Command/cmd_recipe.h"
#include "IRecipe/Data/recipe_enum.h"
#include "IRecipe/Subscriber/recipesubscriber.h"
#include "TimeSynchronization/Manage/timesync.h"
#include "Communication/MQTT/mqttclientmanager.h"

RecipeOperateBoard::RecipeOperateBoard(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::RecipeOperateBoard)
{
    ui->setupUi(this);
    modelInitialize();

    m_Publisher.LinkToClient(MqttClientManager::getInstance()->GetClient(0), PublishTopicPrefix);

    m_SelectedRecipeType.SetEnumValue<Recipe_Enum::RecipeType>(0);
    Binding(&m_SelectedRecipeType, ui->cmb_RecipeType);
    Binding(&m_SelectedRecipeName, ui->led_SelectedRecipeName);
}

RecipeOperateBoard::~RecipeOperateBoard()
{
    delete ui;
}

void RecipeOperateBoard::ConstructFinished()
{
    m_Publisher.Publish("Recipe", EnumConverter::ConvertToString(CMD_Recipe::CMD_RcpNames));
}

void RecipeOperateBoard::setWidgets()
{

}

void RecipeOperateBoard::setWidgetStyleSheet()
{
    ui->lbl_RecipeType->setText(Tr("Recipe Type"));
    ui->lbl_SelectedRecipeName->setText(Tr("Selected Recipe"));
    ui->lbl_Filter->setText(Tr("Filter"));

    ui->led_SelectedRecipeName->setEnabled(false);
    ui->led_SearchValue->setStyleSheet(StyleSheet::getInstance()->LineEdit_Dark + StyleSheet::getInstance()->fontStyle_qlineEdit_normal_12);
    ui->led_SearchValue->SetIconDock(IconLineEdit::Right);
    ui->led_SearchValue->SetIconFont(StyleSheet::getInstance()->Font());
    ui->led_SearchValue->setTextMargins(0, 0, 35, 0);
    ui->led_SearchValue->SetIcon(QString(0xa024), 14);

    ui->lbl_RecipeType->setStyleSheet(StyleSheet::getInstance()->fontStyle_normal_12);
    ui->lbl_SelectedRecipeName->setStyleSheet(StyleSheet::getInstance()->fontStyle_normal_12);
    ui->lbl_Filter->setStyleSheet(StyleSheet::getInstance()->fontStyle_normal_12);
    ui->cmb_RecipeType->setStyleSheet(StyleSheet::getInstance()->ComboBox + StyleSheet::getInstance()->fontStyle_normal_12);
    ui->led_SelectedRecipeName->setStyleSheet(StyleSheet::getInstance()->LineEdit_Dark + StyleSheet::getInstance()->fontStyle_normal_12);
    ui->tbw_Recipes->setStyleSheet(StyleSheet::getInstance()->tabStyle + StyleSheet::getInstance()->fontStyle_normal_12);

    QFont font = StyleSheet::getInstance()->Font();
    ui->btn_New->setFont(font);
    ui->btn_New->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_New->SetVertivalStyle(font, QString(0xa44), 30, Language::getInstance()->Translate("New"), 12, QFont::Bold);
    ui->btn_New->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_New->setEnabled(false);

    ui->btn_Edit->setFont(font);
    ui->btn_Edit->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_Edit->SetVertivalStyle(font, QString(0xa51), 28, Language::getInstance()->Translate("Edit"), 12, QFont::Bold);
    ui->btn_Edit->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_Edit->setEnabled(false);

    ui->btn_Cancel->setFont(font);
    ui->btn_Cancel->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_Cancel->SetVertivalStyle(font, QString(0xa46), 30, Language::getInstance()->Translate("Cancel"), 12, QFont::Bold);
    ui->btn_Cancel->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_Cancel->setEnabled(false);

    ui->btn_Copy->setFont(font);
    ui->btn_Copy->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_Copy->SetVertivalStyle(font, QString(0xa54), 30, Language::getInstance()->Translate("Copy"), 12, QFont::Bold);
    ui->btn_Copy->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_Copy->setEnabled(false);

    ui->btn_Save->setFont(font);
    ui->btn_Save->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_Save->SetVertivalStyle(font, QString(0xa50), 30, Language::getInstance()->Translate("Save"), 12, QFont::Bold);
    ui->btn_Save->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_Save->setEnabled(false);


    ui->btn_Release->setFont(font);
    ui->btn_Release->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_Release->SetHorizontalStyle(font, QString(0xa55), 30, Tr("UnRelease"), 12, QFont::Bold);
    ui->btn_Release->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_Release->setEnabled(false);

    ui->btn_Delete->setFont(font);
    ui->btn_Delete->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_Delete->SetHorizontalStyle(font, QString(0xa53), 30, Language::getInstance()->Translate("Delete"), 12, QFont::Bold);
    ui->btn_Delete->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_Delete->setEnabled(false);
}

void RecipeOperateBoard::setLanguageKeys()
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
}

void RecipeOperateBoard::setConnections()
{
    connect(RecipeSubscriber::getInstance(), &RecipeSubscriber::sig_RecipeNames, this, [ = ](S_RecipeNames recipeNames)
    {
        this->m_RecipeNames = recipeNames;
        if(ui->cmb_RecipeType->currentIndex() == Recipe_Enum::Released)
        {
            p_RecipeModel->resetModel(recipeNames.lst_Relesed);
        }
        else if(ui->cmb_RecipeType->currentIndex() == Recipe_Enum::UnReleased)
        {
            p_RecipeModel->resetModel(recipeNames.lst_UnRelesed);
        }
        else if(ui->cmb_RecipeType->currentIndex() == -1)
        {
            p_RecipeModel->resetModel(recipeNames.lst_Relesed);
        }
        setEditorStatus();
    });

    connect(ui->cmb_RecipeType, static_cast<void(QComboBox::*)(int index)>(&QComboBox::activated), this, [ = ](int index)
    {
        QFont font = StyleSheet::getInstance()->Font();
        if(index == Recipe_Enum::Released)
        {
            p_RecipeModel->resetModel(m_RecipeNames.lst_Relesed);
            ui->btn_Release->SetHorizontalStyle(font, QString(0xa55), 30, Tr("UnRelease"), 12, QFont::Bold);
        }
        else if(index == Recipe_Enum::UnReleased)
        {
            p_RecipeModel->resetModel(m_RecipeNames.lst_UnRelesed);
            ui->btn_Release->SetHorizontalStyle(font, QString(0xa55), 30, Tr("Release"), 12, QFont::Bold);
        }

        if(index == Recipe_Enum::Released || index == Recipe_Enum::UnReleased)
        {
            ui->led_SelectedRecipeName->setText("");
            ui->led_SearchValue->setText("");
            status = ViewStatus::Idle;
            emit ViewStatusChanged(status);
            setEditorStatus();
        }
    });

    connect(ui->tbw_Recipes, &QTableView::clicked, this, [ = ](const QModelIndex & index)
    {
        m_SelectedRecipeName = ui->tbw_Recipes->model()->data(index, Qt::UserRole).value<QString>();
        S_RecipeInfo rcpInfo;
        rcpInfo.rcpName = m_SelectedRecipeName.value;
        rcpInfo.recipeType = m_SelectedRecipeType.Value<Recipe_Enum::RecipeType>();
        //        rcpInfo.recipeType = EnumConverter::ConvertStringToEnum<Recipe_Enum::RecipeType>(m_SelectedRecipeType.dataSource.at(m_SelectedRecipeType.value));
        m_Publisher.Publish("Recipe", EnumConverter::ConvertToString(CMD_Recipe::CMD_RcpInfo), false, rcpInfo.toRawJson());
        m_Publisher.Publish("Recipe", EnumConverter::ConvertToString(CMD_Recipe::CMD_RcpContent), false, rcpInfo.toRawJson());
        setEditorStatus();
    });

    connect(ui->led_SearchValue, &QLineEdit::textChanged, this, [ = ](QString str)
    {
        for(int i = 0; i < ui->tbw_Recipes->model()->rowCount(); i++)
        {
            ui->tbw_Recipes->setRowHidden(i, true);
            QAbstractItemModel *model = ui->tbw_Recipes->model();
            QModelIndex index;
            index = model->index(i, 1);
            if(model->data(index).toString().contains(str, Qt::CaseInsensitive))
            {
                ui->tbw_Recipes->setRowHidden(i, false);
            }
        }
    });

    connect(ui->btn_New, &QPushButton::clicked, this, [ = ]()
    {
        this->m_bIsModify = false;
        m_Publisher.Publish("Recipe", EnumConverter::ConvertToString(CMD_Recipe::CMD_CreateRcp));
        status = ViewStatus::Modifying;
        emit ViewStatusChanged(status);
        setEditorStatus();
    });

    connect(ui->btn_Edit, &QPushButton::clicked, this, [ = ]()
    {
        if (ui->tbw_Recipes->currentIndex().isValid())
        {
            this->m_bIsModify = true;
            status = ViewStatus::Modifying;
            emit ViewStatusChanged(status);
            setEditorStatus();
        }
    });

    connect(ui->btn_Cancel, &QPushButton::clicked, this, [ = ]()
    {
        MessageDialog dlg(MessageDialog::Attention, this, Language::getInstance()->Translate("E_RcpName_Cancel"));
        if(dlg.exec() == QDialog::Accepted)
        {
            emit sig_CancelRecipe();
        }
        else
        {
            return;
        }
        status = ViewStatus::Idle;
        emit ViewStatusChanged(status);
        if(ui->cmb_RecipeType->currentIndex() == Recipe_Enum::Released)
        {
            p_RecipeModel->resetModel(m_RecipeNames.lst_Relesed);
        }
        else if(ui->cmb_RecipeType->currentIndex() == Recipe_Enum::UnReleased)
        {
            p_RecipeModel->resetModel(m_RecipeNames.lst_UnRelesed);
        }
        else if(ui->cmb_RecipeType->currentIndex() == -1)
        {
            p_RecipeModel->resetModel(m_RecipeNames.lst_Relesed);
        }
        setEditorStatus();
    });

    connect(ui->btn_Save, &QPushButton::clicked, this, [ = ]()
    {
        emit sig_SaveRecipe(m_RecipeNames, m_SelectedRecipeName.value, m_bIsModify);
    });

    connect(ui->btn_Copy, &QPushButton::clicked, this, [ = ]()
    {
        if (ui->tbw_Recipes->currentIndex().isValid())
        {
            if (m_RecipeInfo.rcpName.contains("_backup_"))
            {
                MessageDialog dlg(MessageDialog::Error, this, Language::getInstance()->Translate("E_RcpName_Copy"));
                dlg.exec();
                return ;
            }
            m_Publisher.Publish("Recipe", EnumConverter::ConvertToString(CMD_Recipe::CMD_CopyRcp), false, m_RecipeInfo.toRawJson());
            setEditorStatus();
        }
    });

    connect(ui->btn_Release, &QPushButton::clicked, this, [ = ]()
    {
        if (ui->tbw_Recipes->currentIndex().isValid())
        {
            m_RecipeInfo.releaser = user.userName;
            m_RecipeInfo.releasedTime = Time()->TimeToString();
            if (Recipe_Enum::RecipeType::Released == m_RecipeInfo.recipeType)
            {
                m_Publisher.Publish("Recipe", EnumConverter::ConvertToString(CMD_Recipe::CMD_UnReleaseRcp), false, m_RecipeInfo.toRawJson());
            }
            else if (Recipe_Enum::RecipeType::UnReleased == m_RecipeInfo.recipeType)
            {
                m_Publisher.Publish("Recipe", EnumConverter::ConvertToString(CMD_Recipe::CMD_ReleaseRcp), false, m_RecipeInfo.toRawJson());
            }
        }
    });

    connect(ui->btn_Delete, &QPushButton::clicked, this, [ = ]()
    {
        if (ui->tbw_Recipes->currentIndex().isValid())
        {
            MessageDialog dlg(MessageDialog::Attention, this, Language::getInstance()->Translate("E_RcpName_Delete"));
            if(dlg.exec() == QDialog::Accepted)
            {
                m_Publisher.Publish("Recipe", EnumConverter::ConvertToString(CMD_Recipe::CMD_DeleteRcp), false, m_RecipeInfo.toRawJson());
            }
            else
            {
                return;
            }
        }
    });

    connect(RecipeSubscriber::getInstance(), &RecipeSubscriber::sig_RecipeInfo, this, [ = ](S_RecipeInfo & info)
    {
        this->m_RecipeInfo = info;
        emit sig_RecipeInfo(info);
    });

    connect(RecipeSubscriber::getInstance(), &RecipeSubscriber::sig_RecipeContent, this, [ = ](QByteArray & content)
    {
        this->m_byte_RecipeContent = content;
        emit sig_RecipeContent(content);
    });
}

void RecipeOperateBoard::setEditorStatus()
{
    bool bTableSelected = ui->tbw_Recipes->currentIndex().isValid();
    if(this->m_SelectedRecipeType.value == Recipe_Enum::Released)
    {
        ui->btn_Save->setEnabled(false);
        ui->btn_Cancel->setEnabled(false);
        ui->btn_Copy->setEnabled(bTableSelected);
        ui->btn_Delete->setEnabled(bTableSelected);
        ui->btn_Edit->setEnabled(false);
        ui->btn_Release->setEnabled(bTableSelected);
        ui->btn_New->setEnabled(false);
        emit sig_EditViewStatus(false);
        emit sig_InfoViewStatus(false);
    }
    else
    {
        if(status == ViewStatus::Idle)
        {
            ui->btn_Save->setEnabled(false);
            ui->btn_Cancel->setEnabled(false);
            ui->btn_New->setEnabled(true);
            ui->btn_Edit->setEnabled(bTableSelected);
            ui->btn_Copy->setEnabled(bTableSelected);
            ui->btn_Delete->setEnabled(bTableSelected);
            ui->btn_Release->setEnabled(bTableSelected);
            ui->tbw_Recipes->setEnabled(true);
            ui->cmb_RecipeType->setEnabled(true);
            ui->led_SearchValue->setEnabled(true);
            emit sig_EditViewStatus(false);
            emit sig_InfoViewStatus(false);
        }
        else
        {
            ui->btn_Save->setEnabled(true);
            ui->btn_Cancel->setEnabled(true);
            ui->btn_Copy->setEnabled(false);
            ui->btn_Delete->setEnabled(false);
            ui->btn_Edit->setEnabled(false);
            ui->btn_Release->setEnabled(false);
            ui->btn_New->setEnabled(false);
            ui->tbw_Recipes->setEnabled(false);
            ui->cmb_RecipeType->setEnabled(false);
            ui->led_SearchValue->setEnabled(false);
            emit sig_EditViewStatus(true);
            emit sig_InfoViewStatus(true);
        }
    }
}

void RecipeOperateBoard::modelInitialize()
{
    p_RecipeModel = new RecipeModel(this);
    p_RecipeModel->SetModel(m_RecipeNames.lst_Relesed);
    ui->tbw_Recipes->setModel(p_RecipeModel);
    ui->tbw_Recipes->setColumnWidth(0, 60);
}

void RecipeOperateBoard::statusChangedAfterSave()
{
    status = ViewStatus::Idle;
    emit ViewStatusChanged(status);
    setEditorStatus();
}


