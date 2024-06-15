#include "uc_tstring.h"
#include "ui_uc_tstring.h"
#include "StyleSheet/stylesheet.h"

#include <QDebug>

UC_TString::UC_TString(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UC_TString)
{
    ui->setupUi(this);

    ui->led_Context->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    connect(ui->led_Context, &QLineEdit::editingFinished, this, [ = ]
    {
        emit editingFinished();
    });

    //    ui->horizontalLayout->setStretch(0, 3);
    //    ui->horizontalLayout->setStretch(1, 7);
}

UC_TString::~UC_TString()
{
    delete ui;
}

QString UC_TString::text()
{
    return ui->led_Context->text();
}

void UC_TString::setText(const QString &str)
{
    ui->led_Context->setText(str);
}

void UC_TString::setName(QString str)
{
    ui->lbl_Name->setText(str);
}

void UC_TString::setEnabled(bool enable)
{
    ui->led_Context->setEnabled(enable);
}

void UC_TString::setValidator(const QValidator *validator)
{
    ui->led_Context->setValidator(validator);
}

void UC_TString::setStrechFactor(int v1, int v2, int v3)
{
    ui->lbl_Name->setMinimumSize(0, 0);
    ui->horizontalLayout->setStretch(0, v1);
    ui->horizontalLayout->setStretch(1, v2);
    ui->horizontalLayout->setStretch(2, v3);
}
