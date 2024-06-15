#include "setupform.h"
#include "ui_setupform.h"
#include "AuthorityManage/WidgetManage/authoritywdgmanager.h"
#include "AuthorityManage/View/authoritysettingview.h"

#include "AppConfig/View/configview.h"
#include "IMachineConstant/View/machineconstantview.h"

SetupForm::SetupForm(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::SetupForm)
{
    ui->setupUi(this);

    setLayoutWidgets(ui->horizontalLayout, ui->stw_View, ui->frame_SubNavi);

    AuthorityWdgManager::getInstance()->InitOpt(ui->btn_Constant, new MachineConstantView("Constant", this), ui->stw_View, this, 0);
    AuthorityWdgManager::getInstance()->InitOpt(ui->btn_AuthorityManage, new AuthoritySettingView("Authority", this), ui->stw_View, this, 1);
    AuthorityWdgManager::getInstance()->InitOpt(ui->btn_AppConfig, new ConfigView("Config", this), ui->stw_View, this, 2);
}

SetupForm::~SetupForm()
{
    delete ui;
}

void SetupForm::setWidgetStyleSheet()
{
    QFont font = GlobalStyleSheet->Font();
    ui->btn_Constant->SetVertivalStyle(font, QString(0xa023), 30, Tr("Constant"), 12, QFont::Bold);
    ui->btn_AuthorityManage->SetVertivalStyle(font, QString(0xa023), 30, Tr("Authority"), 12, QFont::Bold);
    ui->btn_AppConfig->SetVertivalStyle(font, QString(0xa023), 30, Tr("Config"), 12, QFont::Bold);

    ui->btn_Constant->setStyleSheet(GlobalStyleSheet->SubNaviButtonStyle);
    ui->btn_AuthorityManage->setStyleSheet(GlobalStyleSheet->SubNaviButtonStyle);
    ui->btn_AppConfig->setStyleSheet(GlobalStyleSheet->SubNaviButtonStyle);
}

void SetupForm::setLanguageKeys()
{
    Tr("Constant");
    Tr("Authority");
    Tr("Config");
}
