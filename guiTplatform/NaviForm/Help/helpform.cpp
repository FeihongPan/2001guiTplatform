#include "helpform.h"
#include "ui_helpform.h"
#include "Help/Views/helpview.h"
#include "AuthorityManage/WidgetManage/authoritywdgmanager.h"

HelpForm::HelpForm(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::HelpForm)
{
    ui->setupUi(this);
    setLayoutWidgets(ui->horizontalLayout, ui->stw_View, ui->frame_SubNavi);

    AuthorityWdgManager::getInstance()->InitOpt(ui->btn_About , new HelpView("About", this), ui->stw_View, this, 0);
}

HelpForm::~HelpForm()
{
    delete ui;
}

void HelpForm::setWidgetStyleSheet()
{
    QFont font = GlobalStyleSheet->Font();
    ui->btn_About->SetVertivalStyle(font, QString(0xa023), 30, Tr("About"), 12, QFont::Bold);

    ui->btn_About->setStyleSheet(GlobalStyleSheet->SubNaviButtonStyle);
}

void HelpForm::setLanguageKeys()
{
    Tr("About");
}
