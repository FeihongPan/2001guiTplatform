#include "unitdoublespinbox.h"
#include "ui_unitdoublespinbox.h"

UnitDoubleSpinBox::UnitDoubleSpinBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UnitDoubleSpinBox)
{
    ui->setupUi(this);
}

UnitDoubleSpinBox::~UnitDoubleSpinBox()
{
    delete ui;
}

QDoubleSpinBox *UnitDoubleSpinBox::GetDoubleSpinBox()
{
    return ui->spb_TargetValue;
}

QLineEdit *UnitDoubleSpinBox::GetLineEdit()
{
    return ui->lineEdit;
}
