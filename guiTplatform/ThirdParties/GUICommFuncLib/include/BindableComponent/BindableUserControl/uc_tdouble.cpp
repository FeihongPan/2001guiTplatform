#include "uc_tdouble.h"
#include "ui_uc_tdouble.h"
#include "StyleSheet/stylesheet.h"

UC_TDouble::UC_TDouble(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UC_TDouble)
{
    ui->setupUi(this);

    ui->spb_Value->setStyleSheet(GlobalStyleSheet->DoubleSpinBox_Dark);
    connect(ui->spb_Value, &QDoubleSpinBox::editingFinished, this, [=]{
        emit editingFinished();
    });

//    ui->horizontalLayout->setStretch(0, 3);
//    ui->horizontalLayout->setStretch(1, 4);
//    ui->horizontalLayout->setStretch(2, 3);
}

UC_TDouble::~UC_TDouble()
{
    delete ui;
}

double UC_TDouble::value()
{
    return ui->spb_Value->value();
}

void UC_TDouble::setName(QString str)
{
    ui->lbl_Name->setText(str);
}

void UC_TDouble::setUnit(QString unit)
{
    ui->lbl_Unit->setText(unit);
}

void UC_TDouble::setValue(double value)
{
    ui->spb_Value->setValue(value);
}

void UC_TDouble::setDecimals(int decimal)
{
    ui->spb_Value->setDecimals(decimal);
}

void UC_TDouble::setMinimum(double min)
{
    ui->spb_Value->setMinimum(min);
}

void UC_TDouble::setMaximum(double max)
{
    ui->spb_Value->setMaximum(max);
}

void UC_TDouble::setStrechFactor(int v1, int v2, int v3)
{
    ui->horizontalLayout->setStretch(0, v1);
    ui->horizontalLayout->setStretch(1, v2);
    ui->horizontalLayout->setStretch(2, v3);
}

void UC_TDouble::setEnabled(bool enable)
{
    ui->spb_Value->setEnabled(enable);
}

double UC_TDouble::getValue()
{
    return ui->spb_Value->value();
}
