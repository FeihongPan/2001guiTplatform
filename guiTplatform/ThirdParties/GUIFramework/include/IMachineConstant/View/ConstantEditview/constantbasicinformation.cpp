#include "constantbasicinformation.h"
#include "ui_constantbasicinformation.h"
#include "StyleSheet/stylesheet.h"
#include "Language/language.h"

#include <QGraphicsDropShadowEffect>

ConstantBasicInformation::ConstantBasicInformation(const S_ConstantInfo &constant, bool isAvtive,
                                                   QWidget *pBlurWgt, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConstantBasicInformation)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect();
    effect->setOffset(0, 0);
    effect->setColor("#C9C9C9");
    effect->setBlurRadius(15);
    ui->dialog_frame->setGraphicsEffect(effect);
    m_pBlurWdg = pBlurWgt;
    if(pBlurWgt != nullptr)
    {
        QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect();
        blurEffect->setBlurRadius(5);
        blurEffect->setBlurHints(QGraphicsBlurEffect::PerformanceHint);
        pBlurWgt->setGraphicsEffect(blurEffect);
    }

    ui->lbl_Decorate->setStyleSheet("QLabel{background-color:" + GlobalStyleSheet->Color_Blue + ";}");
    ui->lbl_Title->setText(Tr("Machinie Constant Basic Information"));
    ui->btn_Confirm->setText(Tr("Confirm"));
    ui->btn_Confirm->setStyleSheet(GlobalStyleSheet->Button_Border + GlobalStyleSheet->fontStyle_normal_14);

    ui->lbl_name->setText(Tr("Name"));
    ui->lbl_creator->setText(Tr("Creator"));
    ui->lbl_created_time->setText(Tr("Create Time"));
    ui->lbl_modifier->setText(Tr("Modifier"));
    ui->lbl_modifier_time->setText(Tr("Modified Time"));
    ui->lbl_Description->setText(Tr("Description"));

    ui->lbl_Title->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_name->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_creator->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_created_time->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_modifier->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_modifier_time->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_Description->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->ted_Description->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);

    ui->led_name->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    ui->led_creator->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    ui->led_creted_time->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    ui->led_modifier->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    ui->led_modifier_time->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);

    m_constantInfo = constant;
    m_bIsActive = isAvtive;
    ui->widget->setEnabled(true);
    ui->led_name->setEnabled(false);
    ui->led_creator->setEnabled(false);
    ui->led_creted_time->setEnabled(false);
    ui->led_modifier->setEnabled(false);
    ui->led_modifier_time->setEnabled(false);
    ui->ted_Description->setEnabled(true);
    updateClient(true);
}

void ConstantBasicInformation::updateClient(bool isClient)
{
//    if(m_bIsActive)
//    {
//        ui->led_name->setEnabled(true);
//        ui->led_creator->setEnabled(true);
//        ui->led_creted_time->setEnabled(true);
//        ui->led_modifier->setEnabled(true);
//        ui->led_modifier_time->setEnabled(true);
//        ui->ted_Description->setEnabled(true);
//    }
//    else
//    {
//        ui->led_name->setEnabled(false);
//        ui->led_creator->setEnabled(false);
//        ui->led_creted_time->setEnabled(false);
//        ui->led_modifier->setEnabled(false);
//        ui->led_modifier_time->setEnabled(false);
//        ui->ted_Description->setEnabled(true);
//    }

    if(isClient)
    {
        ui->led_name->setText(m_constantInfo.constantName);
        ui->led_creator->setText(m_constantInfo.creator);
        ui->led_creted_time->setText(m_constantInfo.createdTime);
        ui->led_modifier->setText(m_constantInfo.modifier);
        ui->led_modifier_time->setText(m_constantInfo.modifiedTime);
        ui->ted_Description->setText(m_constantInfo.description);
        ui->ted_Description->setReadOnly(!m_bIsActive);
    }
    else
    {
        m_constantInfo.constantName = ui->led_name->text();
        m_constantInfo.modifier = ui->led_modifier->text();
        m_constantInfo.creator = ui->led_creator->text();
        m_constantInfo.createdTime = ui->led_creted_time->text();
        m_constantInfo.modifiedTime = ui->led_modifier_time->text();
        m_constantInfo.description = ui->ted_Description->toPlainText();
    }
}

ConstantBasicInformation::~ConstantBasicInformation()
{
    delete ui;
}

S_ConstantInfo ConstantBasicInformation::getResult()
{
    updateClient(false);
    return m_constantInfo;
}

void ConstantBasicInformation::reject()
{
    if(m_pBlurWdg != nullptr)
    {
        m_pBlurWdg->setGraphicsEffect(nullptr);
    }
    QDialog::reject();
}

void ConstantBasicInformation::on_btn_Confirm_clicked()
{
    if(m_pBlurWdg != nullptr)
    {
        m_pBlurWdg->setGraphicsEffect(nullptr);
    }

    QDialog::accept();
}

