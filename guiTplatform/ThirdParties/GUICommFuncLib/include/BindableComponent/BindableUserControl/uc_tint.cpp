#include "uc_tint.h"
#include "ui_uc_tint.h"
#include "StyleSheet/stylesheet.h"

UC_TInt::UC_TInt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UC_TInt)
{
    ui->setupUi(this);

    ui->spb_Value->setStyleSheet(GlobalStyleSheet->SpinBox_Dark);
    connect(ui->spb_Value, &QSpinBox::editingFinished, this, [=]{
        emit editingFinished();
    });

//    ui->horizontalLayout->setStretch(0, 3);
//    ui->horizontalLayout->setStretch(1, 4);
//    ui->horizontalLayout->setStretch(2, 3);
}

UC_TInt::~UC_TInt()
{
    delete ui;
}

double UC_TInt::value()
{
    return ui->spb_Value->value();
}

void UC_TInt::setName(QString &str)
{
    ui->lbl_Name->setText(str);
}

void UC_TInt::setUnit(QString &unit)
{
    ui->lbl_Unit->setText(unit);
}

void UC_TInt::setValue(double value)
{
    ui->spb_Value->setValue(value);
}

void UC_TInt::setMinimum(double min)
{
    ui->spb_Value->setMinimum(min);
}

void UC_TInt::setMaximum(double max)
{
    ui->spb_Value->setMaximum(max);
}

void UC_TInt::setStrechFactor(int v1, int v2, int v3)
{
    ui->lbl_Name->setMinimumSize(0,0);
    ui->lbl_Unit->setMinimumSize(0,0);
    ui->horizontalLayout->setStretch(0, v1);
    ui->horizontalLayout->setStretch(1, v2);
    ui->horizontalLayout->setStretch(2, v3);
}
