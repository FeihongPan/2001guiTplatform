#include "recipebasicinfomation.h"
#include "ui_recipebasicinfomation.h"
#include "StyleSheet/stylesheet.h"
#include "Language/language.h"
#include "Converter/enumconverter.h"

RecipeBasicInfomation::RecipeBasicInfomation(S_RecipeInfo &rcp, bool enable, QWidget *blurWdg, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecipeBasicInfomation)
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
        qDebug() << "RecipeBasicInfomation";
        QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect();
        blurEffect->setBlurRadius(5);
        blurEffect->setBlurHints(QGraphicsBlurEffect::PerformanceHint);
        p_BlurWdg->setGraphicsEffect(blurEffect);
    }

    ui->lbl_Decorate->setStyleSheet("QLabel{background-color:" + GlobalStyleSheet->Color_Blue + ";}");
    ui->lbl_Title->setText(Tr("Recipe Basic Information"));
    ui->btn_Confirm->setText(Tr("Confirm"));
    ui->btn_Confirm->setStyleSheet(GlobalStyleSheet->Button_Border + GlobalStyleSheet->fontStyle_normal_14);

    ui->lbl_RcpName->setText(Tr("Recipe Name"));
    ui->lbl_Version->setText(Tr("Version"));
    ui->lbl_Creator->setText(Tr("Creator"));
    ui->lbl_CreateTime->setText(Tr("Create Time"));
    ui->lbl_Modifier->setText(Tr("Modifier"));
    ui->lbl_ModifiedTime->setText(Tr("Modified Time"));
    ui->lbl_Releaser->setText(Tr("Releaser"));
    ui->lbl_ReleasedTime->setText(Tr("Released Time"));
    ui->lbl_RcpType->setText(Tr("Recipe Type"));
    ui->lbl_Description->setText(Tr("Description"));

    ui->lbl_RcpName->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_Version->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_Creator->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_CreateTime->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_Modifier->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_ModifiedTime->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_Releaser->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_ReleasedTime->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_RcpType->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_Description->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);

    ui->led_RecipeName->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    ui->led_Version->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    ui->led_Creator->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    ui->led_CreateTime->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    ui->led_Modifier->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    ui->led_ModifiedTime->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    ui->led_Releaser->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    ui->led_ReleasedTime->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    ui->led_RcpType->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    ui->ted_Description->setStyleSheet("QTextEdit{border:1px solid #EEEEEE;padding:5px 2px;background-color:#EEEEEE;border-radius:10px;color:#686868;}"
                                       "QTextEdit:hover{border:1px solid #A4B7FF;}"
                                       "QTextEdit:focus{border:1px solid #4C70FA;}"
                                       "QTextEdit:disabled{background-color:#C8C8C8;color:#FFFFFF;}");

    ui->led_Version->setEnabled(false);
    ui->led_Creator->setEnabled(false);
    ui->led_CreateTime->setEnabled(false);
    ui->led_Modifier->setEnabled(false);
    ui->led_ModifiedTime->setEnabled(false);
    ui->led_Releaser->setEnabled(false);
    ui->led_ReleasedTime->setEnabled(false);
    ui->led_RcpType->setEnabled(false);

    this->m_RecipeInfo = rcp;
    refresh(enable);
    connect(ui->btn_Confirm, &QPushButton::clicked, this, [ = ]
    {
        this->m_RecipeInfo.description = ui->ted_Description->toPlainText();
        emit  sig_RecipeInfo(this->m_RecipeInfo);

        if(p_BlurWdg != nullptr)
        {
            p_BlurWdg->setGraphicsEffect(nullptr);
        }
        accept();
    });
}

RecipeBasicInfomation::~RecipeBasicInfomation()
{
    delete ui;
}

void RecipeBasicInfomation::reject()
{
    if(p_BlurWdg != nullptr)
    {
        p_BlurWdg->setGraphicsEffect(nullptr);
    }
    QDialog::reject();
}

void RecipeBasicInfomation::refresh(bool enable)
{
    ui->led_RecipeName->setText(this->m_RecipeInfo.rcpName);
    ui->led_Version->setText(this->m_RecipeInfo.rcpVersion);
    ui->led_Creator->setText(this->m_RecipeInfo.creator);
    ui->led_CreateTime->setText(this->m_RecipeInfo.createdTime);
    ui->led_Modifier->setText(this->m_RecipeInfo.modifier);
    ui->led_ModifiedTime->setText(this->m_RecipeInfo.modifiedTime);
    ui->led_Releaser->setText(this->m_RecipeInfo.releaser);
    ui->led_ReleasedTime->setText(this->m_RecipeInfo.releasedTime);
    ui->led_RcpType->setText(EnumConverter::ConvertToString(this->m_RecipeInfo.recipeType));
    ui->ted_Description->setText(this->m_RecipeInfo.description);
    ui->led_RecipeName->setEnabled(enable);
    ui->ted_Description->setEnabled(enable);
}
