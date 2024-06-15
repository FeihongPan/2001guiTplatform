#include "groupbox.h"
#include "ui_groupbox.h"
#include "StyleSheet/stylesheet.h"
#include <QGraphicsDropShadowEffect>
GroupBox::GroupBox(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::GroupBox)
{
    ui->setupUi(this);

    this->setStyleSheet(GlobalStyleSheet->GroupBoxStyle);
}

GroupBox::~GroupBox()
{
    delete ui;
}

void GroupBox::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    ui->lbl_Title->setFixedWidth(this->width() - 40);
}

void GroupBox::SetDecorateColor(QString color)
{
    ui->lbl_Decorate->setStyleSheet("QLabel{background-color: " + color + ";}");
}

void GroupBox::SetHeaderText(QString text)
{
    ui->lbl_Title->setText(text);
}

void GroupBox::SetheaderFontSize(int size)
{
    QFont font;
    font.setPixelSize(size);
    font.setBold(true);
    ui->lbl_Title->setFont(font);
    ui->lbl_Title->setFixedHeight(size + 8);
    ui->lbl_Decorate->setFixedHeight(size + 8);
}

void GroupBox::SetHeaderFontColor(QString color)
{
    ui->lbl_Title->setStyleSheet("QLabel{color: " + color + ";}");
}
