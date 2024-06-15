#include "uc_tbool.h"
#include "ui_uc_tbool.h"
#include "StyleSheet/stylesheet.h"

UC_TBool::UC_TBool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uc_TBool)
{
    ui->setupUi(this);

    ui->btn_Value->setStyleSheet(GlobalStyleSheet->Button_Border);
    connect(ui->btn_Value, &QPushButton::toggled, this, [=](bool checked){
        emit toggled(checked);
    });

    connect(ui->btn_Value, &QPushButton::clicked, this, [=]{
        emit clicked();
    });
}

UC_TBool::~UC_TBool()
{
    delete ui;
}

bool UC_TBool::isChecked()
{
    return ui->btn_Value->isChecked();
}

void UC_TBool::setName(QString &str)
{
    ui->lbl_Name->setText(str);
}

void UC_TBool::setChecked(bool checked)
{
    ui->btn_Value->setChecked(checked);
}
