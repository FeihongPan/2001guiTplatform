#include "recipeinfoview.h"
#include "ui_recipeinfoview.h"
#include "Converter/enumconverter.h"
#include "Language/language.h"
#include "StyleSheet/stylesheet.h"
#include "runtimepara.h"

RecipeInfoView::RecipeInfoView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecipeInfoView)
{
    ui->setupUi(this);

    ui->lbl_RecipeName->setText(Tr("Recipe Name"));
    ui->lbl_RecipeType->setText(Tr("Recipe Type"));

    ui->lbl_RecipeName->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->led_RecipeName->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    //    ui->led_RecipeName->setReadOnly(true);


    ui->lbl_RecipeType->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->led_RecipeType->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    ui->led_RecipeType->setReadOnly(true);

    ui->btn_RcpBasicInfo->setText(Tr("Basic Information"));
    ui->btn_RcpBasicInfo->setStyleSheet(GlobalStyleSheet->Button_Border + GlobalStyleSheet->fontStyle_normal_12);

    connect(ui->btn_RcpBasicInfo, &QPushButton::clicked, this, [ & ]
    {
        RecipeBasicInfomation *rcpInfo = new RecipeBasicInfomation(this->m_RecipeInfo, m_bStatus, RuntimePara::getInstance()->p_BlurParentWidget, this);
        connect(rcpInfo, &RecipeBasicInfomation::sig_RecipeInfo, this, [ = ](S_RecipeInfo & rcp)
        {
            this->m_RecipeInfo = rcp;
        });
        rcpInfo->exec();
    });
}

RecipeInfoView::~RecipeInfoView()
{
    delete ui;
}

void RecipeInfoView::setEditorStatus(bool status)
{
    this->m_bStatus = status;
    ui->led_RecipeName->setEnabled(this->m_bStatus);
}

void RecipeInfoView::dumpUI()
{
    this->m_RecipeInfo.rcpName = ui->led_RecipeName->text();
}

void RecipeInfoView::on_RecipeInfo(S_RecipeInfo &rcp)
{
    this->m_RecipeInfo = rcp;
    ui->led_RecipeName->setText(this->m_RecipeInfo.rcpName);
    ui->led_RecipeType->setText(EnumConverter::ConvertToString(this->m_RecipeInfo.recipeType));
}
