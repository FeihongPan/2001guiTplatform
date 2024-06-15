#include "templateliboperateboard.h"
#include "ui_templateliboperateboard.h"

TemplateLibOperateBoard::TemplateLibOperateBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemplateLibOperateBoard)
{
    ui->setupUi(this);
}

TemplateLibOperateBoard::~TemplateLibOperateBoard()
{
    delete ui;
}
