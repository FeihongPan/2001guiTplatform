#include "constanthead.h"
#include "ui_constanthead.h"
#include "constantbasicinformation.h"
#include "StyleSheet/stylesheet.h"
#include "Language/language.h"
#include "IRecipe/Data/recipeinfo.h"
#include "runtimepara.h"

#include <QMainWindow>

ConstantHead::ConstantHead(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConstantHead)
{
    ui->setupUi(this);

    ui->lbl_name->setText(Tr("Constant Name"));

    ui->lbl_name->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->led_name->setStyleSheet(GlobalStyleSheet->LineEdit_Dark + GlobalStyleSheet->fontStyle_normal_12);
    ui->led_name->setReadOnly(false);

    ui->btn_basicInfo->setText(Tr("Basic Information"));
    ui->btn_basicInfo->setStyleSheet(GlobalStyleSheet->Button_Border + GlobalStyleSheet->fontStyle_normal_12);
}

ConstantHead::~ConstantHead()
{
    delete ui;
}

void ConstantHead::setConstantInfo(const S_ConstantInfo &constantInfo)
{
    ui->led_name->setText(constantInfo.constantName);
    m_constantInfo = constantInfo;
}

S_ConstantInfo ConstantHead::getContantInfo()
{
    m_constantInfo.constantName = ui->led_name->text();
    return m_constantInfo;
}

void ConstantHead::setReadOnly(bool readOnly)
{
    ui->led_name->setEnabled(!readOnly);
}

void ConstantHead::clean()
{
    ui->led_name->setText("");
    m_constantInfo = S_ConstantInfo();
}

void ConstantHead::setBtnEnable(bool enable)
{
    ui->btn_basicInfo->setEnabled(enable);
}


void ConstantHead::on_btn_basicInfo_clicked()
{
    ConstantBasicInformation infoDlg(m_constantInfo, false, this);

    infoDlg.exec();
    m_constantInfo = infoDlg.getResult();
    ui->led_name->setText(m_constantInfo.constantName);
    emit sig_sendConstantInfo(m_constantInfo);
}
