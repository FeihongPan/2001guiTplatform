#include "templatelibinfoview.h"
#include "ui_templatelibinfoview.h"
#include "Converter/enumconverter.h"
#include "Language/language.h"
#include "StyleSheet/stylesheet.h"
#include "runtimepara.h"

TemplateLibInfoView::TemplateLibInfoView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemplateLibInfoView)
{
    ui->setupUi(this);

    ui->lbl_TemplateName->setText(Tr("Type"));

    ui->lbl_TemplateName->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->led_TemplateName->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);



    ui->btn_TemplateBasicInfo->setText(Tr("Basic Information"));
    ui->btn_TemplateBasicInfo->setStyleSheet(GlobalStyleSheet->Button_Border + GlobalStyleSheet->fontStyle_normal_12);

    connect(ui->btn_TemplateBasicInfo, &QPushButton::clicked, this, [ & ]
    {
        TemplateLibBasicInformation *tempInfo = new TemplateLibBasicInformation(this->m_TemplateInfo, m_bStatus, RuntimePara::getInstance()->p_BlurParentWidget, this);
        connect(tempInfo, &TemplateLibBasicInformation::sig_TemplateInfo, this, [ = ](S_TemplateInfo & temp)
        {
            this->m_TemplateInfo = temp;
        });
        tempInfo->exec();
    });
}

TemplateLibInfoView::~TemplateLibInfoView()
{
    delete ui;
}

void TemplateLibInfoView::setEditorStatus(bool status)
{
    this->m_bStatus = status;
    ui->led_TemplateName->setEnabled(this->m_bStatus);
}

void TemplateLibInfoView::dumpUI()
{
    this->m_TemplateInfo.templateType = ui->led_TemplateName->text();
}

void TemplateLibInfoView::on_TemplateInfo(S_TemplateInfo &temp)
{
    this->m_TemplateInfo = temp;
    ui->led_TemplateName->setText(this->m_TemplateInfo.templateType);
}
