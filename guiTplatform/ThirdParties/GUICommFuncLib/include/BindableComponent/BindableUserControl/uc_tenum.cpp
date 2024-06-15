#include "uc_tenum.h"
#include "ui_uc_tenum.h"
#include "StyleSheet/stylesheet.h"

UC_TEnum::UC_TEnum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UC_TEnum)
{
    ui->setupUi(this);

    ui->cmb_Value->setStyleSheet(GlobalStyleSheet->ComboBox);

    connect(ui->cmb_Value, static_cast<void(QComboBox::*)(int index)>(&QComboBox::activated), this, [=](int index){
        emit activated(index);
    });

    connect(ui->cmb_Value, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), this, [=](const QString &str){
        emit currentIndexChanged(str);
    });

//    ui->horizontalLayout->setStretch(0, 3);
//    ui->horizontalLayout->setStretch(1, 7);
}

UC_TEnum::~UC_TEnum()
{
    delete ui;
}

void UC_TEnum::setName(QString &str)
{
    ui->lbl_Name->setText(str);
}

void UC_TEnum::setCurrentIndex(int index)
{
    ui->cmb_Value->setCurrentIndex(index);
}

void UC_TEnum::setDatasource(QStringList datasource)
{
    ui->cmb_Value->clear();
    ui->cmb_Value->addItems(datasource);
}
