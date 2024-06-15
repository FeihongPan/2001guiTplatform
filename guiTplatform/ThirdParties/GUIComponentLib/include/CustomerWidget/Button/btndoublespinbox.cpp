#include "btndoublespinbox.h"
#include "ui_btndoublespinbox.h"

BtnDoubleSpinBox::BtnDoubleSpinBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BtnDoubleSpinBox)
{
    ui->setupUi(this);
}

BtnDoubleSpinBox::~BtnDoubleSpinBox()
{
    delete ui;
}

QDoubleSpinBox *BtnDoubleSpinBox::GetDoubleSpinBox()
{
    return ui->spb_TargetValue;
}

QPushButton *BtnDoubleSpinBox::GetBtn()
{
    return ui->btn_SetValue;
}
