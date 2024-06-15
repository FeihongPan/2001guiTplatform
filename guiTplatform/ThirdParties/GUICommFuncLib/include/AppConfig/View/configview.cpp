#include "configview.h"
#include "ui_configview.h"
#include "CustomerWidget/Dialog/messagedialog.h"
#include "KeyVerify/Subscriber/keyverifysubscriber.h"
#include "KeyVerify/Command/cmd_keyverify.h"
#include "KeyVerify/Manager/keyverifier.h"
#include "AppConfig/View/appconfigview.h"
#include "AppConfig/Manage/guiconfigmanager.h"

ConfigView::ConfigView(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::ConfigView)
{
    ui->setupUi(this);

    Binding(&m_UIPara.serverIp, ui->wdg_serverIP);
    Binding(&m_UIPara.serverPort, ui->wdg_serverPort);
}

ConfigView::~ConfigView()
{
    delete ui;
}

void ConfigView::ConstructFinished()
{
    m_UIPara = GUIConfigManager::getInstance()->GetUIParameter();
    ui->cmb_Language->addItems(m_UIPara.language.dataSource);
    ui->cmb_Language->setCurrentIndex(m_UIPara.language.value);
    m_LanguageType = (Language::LanguageType)m_UIPara.language.value;

    m_Publisher.Publish("KeyVerify", EnumConverter::ConvertToString(CMD_KeyVerify::CMD_LicenseExpirationDate));
    m_Publisher.Publish("KeyVerify", EnumConverter::ConvertToString(CMD_KeyVerify::CMD_LicenseState));

    ui->led_LicenseDate_GUI->setText(KeyVerifier::getInstance()->GetLicenseExpirationDate());
}

void ConfigView::setWidgets()
{
    QRegExp regExpIP("((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])[\\.]){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])");
    ui->wdg_serverIP->setValidator(new QRegExpValidator(regExpIP, this));
    ui->hly_Config->addWidget(new AppConfigView("AppConfigView", this));
}

void ConfigView::setWidgetStyleSheet()
{
    ui->gb_net->SetheaderFontSize(16);
    ui->gb_net->SetHeaderText(Tr("Net Setting"));
    ui->btn_SaveConfig->setText(Tr("Save Config"));
    ui->btn_SaveConfig->setStyleSheet(GlobalStyleSheet->Button_Border + GlobalStyleSheet->fontStyle_normal_12);
    ui->wdg_serverIP->setStrechFactor(0, 1, 0);
    ui->wdg_serverPort->setStrechFactor(0, 1, 0);


    ui->gb_language->SetheaderFontSize(16);
    ui->gb_language->SetHeaderText(Tr("Language Setting"));
    ui->lbl_Language->setText(Tr("Language"));
    ui->lbl_Language->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->btn_SaveLanguage->setText(Tr("Save Language"));
    ui->btn_SaveLanguage->setStyleSheet(GlobalStyleSheet->Button_Border + GlobalStyleSheet->fontStyle_normal_12);
    ui->cmb_Language->setStyleSheet(GlobalStyleSheet->ComboBox + GlobalStyleSheet->fontStyle_normal_12);


    ui->gb_license->SetheaderFontSize(16);
    ui->gb_license->SetHeaderText(Tr("License"));
    ui->lbl_LicenseDate_MCtrl->setText(Tr("MCtrl Expiration Date"));
    ui->lbl_LicenseDate_MCtrl->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->led_LicenseDate_MCtrl->setStyleSheet(GlobalStyleSheet->LineEdit_Dark + GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_LicenseDate_GUI->setText(Tr("GUI Expiration Date"));
    ui->lbl_LicenseDate_GUI->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->led_LicenseDate_GUI->setStyleSheet(GlobalStyleSheet->LineEdit_Dark + GlobalStyleSheet->fontStyle_normal_12);
}

void ConfigView::setLanguageKeys()
{
    Tr("Save Config");
    Tr("Save Language");
    Tr("E_Language_RestartToExcute");
    Tr("License");
}

void ConfigView::setConnections()
{
    connect(ui->btn_SaveConfig, &QPushButton::clicked, this, [ = ]
    {
        GUIConfigManager::getInstance()->WriteToFile(this->m_UIPara);
    });

    connect(ui->btn_SaveLanguage, &QPushButton::clicked, this, [ = ]
    {
        Language::getInstance()->SaveToFile();
    });

    connect(ui->cmb_Language, static_cast<void(QComboBox::*)(int index)>(&QComboBox::activated), this, [ = ](int index)
    {
        if(index != m_LanguageType)
        {
            MessageDialog dlg(MessageDialog::Attention, this, Tr("E_Language_RestartToExcute"));
            if (dlg.exec() == QDialog::Accepted)
            {
                return;
            }
        }
    });

    connect(KeyVerifySubscriber::getInstance(), &KeyVerifySubscriber::sig_LicenseExpirationDate, this, [ = ](QString date)
    {
        ui->led_LicenseDate_MCtrl->setText(date);
    });

    connect(KeyVerifySubscriber::getInstance(), &KeyVerifySubscriber::sig_LicenseState, this, [ = ](bool actived)
    {
        // if(!actived && m_DLG_License == NULL)
        if (false)
        {
            m_DLG_License = new MessageDialog(MessageDialog::Error, this, Tr("E_MCtrlLicenseExpiration"));
            int res = m_DLG_License->exec();
            qDebug() << "KeyVerifySubscriber::getInstance()" << res;
            if(res == QDialog::Accepted || res == QDialog::Rejected)
            {
                delete m_DLG_License;
                m_DLG_License = NULL;
            }
        }
    });
}
