#include "messagedialog.h"
#include "ui_messagedialog.h"
#include "StyleSheet/stylesheet.h"
#include "Language/language.h"
#include "Converter/enumconverter.h"

#include <QGraphicsDropShadowEffect>
#include <QGraphicsBlurEffect>
#include <QDebug>
MessageDialog::MessageDialog(NoticeType type, QWidget *parent, const QString msg) :
    QDialog(parent),
    ui(new Ui::MessageDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect();
    effect->setOffset(0,0);
    effect->setColor("#C9C9C9");
    effect->setBlurRadius(15);
    ui->frame_Dialog->setGraphicsEffect(effect);

    if(parent != nullptr)
    {
        QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect();
        blurEffect->setBlurRadius(5);
        blurEffect->setBlurHints(QGraphicsBlurEffect::PerformanceHint);
        parent->setGraphicsEffect(blurEffect);
    }

    noticeType = type;
    dic_NoticeColor.insert(NoticeType::Success, GlobalStyleSheet->Color_Green);
    dic_NoticeColor.insert(NoticeType::Attention, GlobalStyleSheet->Color_Yellow);
    dic_NoticeColor.insert(NoticeType::Error, GlobalStyleSheet->Color_Red);

    dic_NoticeIcon.insert(NoticeType::Success, QString(0xa010));
    dic_NoticeIcon.insert(NoticeType::Attention, QString(0xa011));
    dic_NoticeIcon.insert(NoticeType::Error, QString(0xa012));

    QFont font;
    font = GlobalStyleSheet->Font();
    font.setPointSize(40);

    ui->lbl_Decorate->setStyleSheet("QLabel{background-color:"+ dic_NoticeColor[type] + ";}");
    ui->lbl_Title->setText(Tr(EnumConverter::ConvertToString(type)));
    ui->lbl_Icon->setFont(font);
    ui->lbl_Icon->setText(dic_NoticeIcon[type]);
    ui->lbl_Icon->setStyleSheet("QLabel{color:"+ dic_NoticeColor[type] + ";}");
    ui->lbl_Message->setText(msg);
    ui->btn_OK->setText(Tr("OK"));
    ui->btn_Cancel->setText(Tr("Cancel"));

    ui->btn_OK->setStyleSheet(GlobalStyleSheet->Button_Border);
    ui->btn_Cancel->setStyleSheet(GlobalStyleSheet->Button_Border);

    ui->btn_OK->SetEffectStatus(true);
    ui->btn_Cancel->SetEffectStatus(true);

    connect(ui->btn_OK, &QPushButton::clicked, this, [=]{
        QWidget *parent = static_cast<QWidget *>(this->parent());
        if(parent != nullptr)
        {
            (static_cast<QWidget *>(parent))->setGraphicsEffect(nullptr);
        }
        this->accept();
    });

    connect(ui->btn_Cancel, &QPushButton::clicked, this, [=]{
        this->reject();
    });

    if(type == NoticeType::Success || type == NoticeType::Error)
    {
        ui->btn_Cancel->setEnabled(false);
    }
}

MessageDialog::~MessageDialog()
{
    delete ui;
}

void MessageDialog::showEvent(QShowEvent *event)
{
    emit Showed();
}

void MessageDialog::hideEvent(QHideEvent *event)
{
    emit Hided();
}

void MessageDialog::reject()
{
    QWidget *parent = static_cast<QWidget *>(this->parent());
    if(parent != nullptr)
    {
        (static_cast<QWidget *>(parent))->setGraphicsEffect(nullptr);
    }
    QDialog::reject();
}

void MessageDialog::SetNoticeColor(QString success, QString attention, QString error)
{
    dic_NoticeColor[NoticeType::Success] = success;
    dic_NoticeColor[NoticeType::Attention] = attention;
    dic_NoticeColor[NoticeType::Error] = error;
    ui->lbl_Decorate->setStyleSheet("QLabel{background-color:"+ dic_NoticeColor[noticeType] + ";}");
}

void MessageDialog::SetNoticeIcon(QString success, QString attention, QString error)
{
    dic_NoticeIcon[NoticeType::Success] = success;
    dic_NoticeIcon[NoticeType::Attention] = attention;
    dic_NoticeIcon[NoticeType::Error] = error;
    ui->lbl_Icon->setText(dic_NoticeIcon[noticeType]);
}

