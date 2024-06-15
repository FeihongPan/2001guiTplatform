#include "templatelibbasicinformation.h"
#include "ui_templatelibbasicinformation.h"
#include "StyleSheet/stylesheet.h"
#include "Language/language.h"
#include "Converter/enumconverter.h"

TemplateLibBasicInformation::TemplateLibBasicInformation(S_TemplateInfo &tempInfo, bool enable, QWidget *blurWdg, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TemplateLibBasicInformation)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect();
    effect->setOffset(0, 0);
    effect->setColor("#C9C9C9");
    effect->setBlurRadius(15);
    ui->frame_Dialog->setGraphicsEffect(effect);
    p_BlurWdg = blurWdg;
    if(p_BlurWdg != nullptr)
    {
        qDebug() << "TemplateLibBasicInformation";
        QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect();
        blurEffect->setBlurRadius(5);
        blurEffect->setBlurHints(QGraphicsBlurEffect::PerformanceHint);
        p_BlurWdg->setGraphicsEffect(blurEffect);
    }

    ui->lbl_Decorate->setStyleSheet("QLabel{background-color:" + Style()->Color_Blue + ";}");
    ui->lbl_Title->setText(Tr("TemplateLib Basic Information"));
    ui->btn_Confirm->setText(Tr("Confirm"));
    ui->btn_Confirm->setStyleSheet(Style()->Button_Border + Style()->fontStyle_normal_14);

    ui->lbl_Creator->setText(Tr("Creator"));
    ui->lbl_CreateTime->setText(Tr("Create Time"));
    ui->lbl_Modifier->setText(Tr("Modifier"));
    ui->lbl_ModifiedTime->setText(Tr("Modified Time"));
    ui->lbl_Description->setText(Tr("Description"));

    ui->lbl_Creator->setStyleSheet(Style()->fontStyle_normal_12);
    ui->lbl_CreateTime->setStyleSheet(Style()->fontStyle_normal_12);
    ui->lbl_Modifier->setStyleSheet(Style()->fontStyle_normal_12);
    ui->lbl_ModifiedTime->setStyleSheet(Style()->fontStyle_normal_12);
    ui->lbl_Description->setStyleSheet(Style()->fontStyle_normal_12);

    ui->led_Creator->setStyleSheet(Style()->LineEdit_Dark);
    ui->led_CreateTime->setStyleSheet(Style()->LineEdit_Dark);
    ui->led_Modifier->setStyleSheet(Style()->LineEdit_Dark);
    ui->led_ModifiedTime->setStyleSheet(Style()->LineEdit_Dark);
    ui->ted_Description->setStyleSheet("QTextEdit{border:1px solid #EEEEEE;padding:5px 2px;background-color:#EEEEEE;border-radius:10px;color:#686868;}"
                                       "QTextEdit:hover{border:1px solid #A4B7FF;}"
                                       "QTextEdit:focus{border:1px solid #4C70FA;}"
                                       "QTextEdit:disabled{background-color:#C8C8C8;color:#FFFFFF;}");

    ui->led_Creator->setEnabled(false);
    ui->led_CreateTime->setEnabled(false);
    ui->led_Modifier->setEnabled(false);
    ui->led_ModifiedTime->setEnabled(false);

    this->m_TempInfo = tempInfo;
    refresh(enable);
    connect(ui->btn_Confirm, &QPushButton::clicked, this, [ = ]
    {
        this->m_TempInfo.description = ui->ted_Description->toPlainText();
        emit  sig_TemplateInfo(this->m_TempInfo);

        if(p_BlurWdg != nullptr)
        {
            p_BlurWdg->setGraphicsEffect(nullptr);
        }
        accept();
    });
}

TemplateLibBasicInformation::~TemplateLibBasicInformation()
{
    delete ui;
}

void TemplateLibBasicInformation::reject()
{
    if(p_BlurWdg != nullptr)
    {
        p_BlurWdg->setGraphicsEffect(nullptr);
    }
    QDialog::reject();
}

void TemplateLibBasicInformation::refresh(bool enable)
{
    ui->led_Creator->setText(this->m_TempInfo.creator);
    ui->led_CreateTime->setText(this->m_TempInfo.createdTime);
    ui->led_Modifier->setText(this->m_TempInfo.modifier);
    ui->led_ModifiedTime->setText(this->m_TempInfo.modifiedTime);
    ui->ted_Description->setText(this->m_TempInfo.description);
    ui->ted_Description->setEnabled(enable);
}
