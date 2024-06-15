#include "logindialog.h"
#include "ui_logindialog.h"
#include "StyleSheet/stylesheet.h"
#include "Language/language.h"
#include <QRegExpValidator>
#include <QGraphicsDropShadowEffect>
//#include <QGraphicsBlurEffect>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
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


    ui->lbl_Title->setText(Tr("Sign in"));

    ui->led_User->SetIcon(QString(0xa039), 14);
    ui->led_User->setTextMargins(35,2,5,2);
    ui->led_User->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);

    ui->led_pwd->SetIcon(QString(0xa040), 14);
    ui->led_pwd->setTextMargins(35,2,5,2);
    ui->led_pwd->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);

    ui->btn_OK->setText(Tr("OK"));
    ui->btn_Cancel->setText(Tr("Cancel"));

    ui->btn_OK->setStyleSheet(GlobalStyleSheet->Button_Border);
    ui->btn_Cancel->setStyleSheet(GlobalStyleSheet->Button_Border);


    connect(ui->led_User, &QLineEdit::textChanged, this, [=](QString value){
        this->userName = value;
    });
    connect(ui->led_pwd, &QLineEdit::textChanged, this, [=](QString value){
        this->password = value;
    });
    connect(ui->btn_OK, &QPushButton::clicked, this, [=]{
        this->userName = ui->led_User->text();
        this->password = ui->led_pwd->text();
        emit SendLoginInfo(userName, password);
    });

    connect(ui->btn_Cancel, &QPushButton::clicked, this, [=]{
        QWidget *parent = static_cast<QWidget *>(this->parent());
        if(parent != nullptr)
        {
            (static_cast<QWidget *>(parent))->setGraphicsEffect(nullptr);
        }
        reject();
    });

    connect(ui->led_User,&QLineEdit::textEdited,ui->lbl_ErrorMsg,&QLabel::clear);
    connect(ui->led_pwd,&QLineEdit::textEdited,ui->lbl_ErrorMsg,&QLabel::clear);

    QRegExp rx("[_|a-zA-Z0-9|]+$");
    ui->led_User->setValidator(new QRegExpValidator(rx, this));
    ui->led_User->setMaxLength(10);
    ui->led_pwd->setValidator(new QRegExpValidator(rx, this));
    ui->led_pwd->setMaxLength(16);

    Tr("Password error!");
    Tr("User name do not exist!");
    Tr("Unknown error!");
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::reject()
{
    QWidget *parent = static_cast<QWidget *>(this->parent());
    if(parent != nullptr)
    {
        (static_cast<QWidget *>(parent))->setGraphicsEffect(nullptr);
    }
    QDialog::reject();
}

void LoginDialog::RecivedLoginInfo(int res)
{
    if(res == 0)
    {
        QWidget *parent = static_cast<QWidget *>(this->parent());
        if(parent != nullptr)
        {
            (static_cast<QWidget *>(parent))->setGraphicsEffect(nullptr);
        }
        accept();
    }
    else if(res == 1)
    {
        ui->lbl_ErrorMsg->setText(Tr("Password error!"));
    }
    else if (res == 2)
    {
        ui->lbl_ErrorMsg->setText(Tr("User name do not exist!"));
    }
    else
    {
        ui->lbl_ErrorMsg->setText(Tr("Unknown error!"));
    }
}
