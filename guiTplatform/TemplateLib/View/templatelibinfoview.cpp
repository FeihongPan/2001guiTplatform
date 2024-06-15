#include "templatelibinfoview.h"
#include "ui_templatelibinfoview.h"

TemplateLibInfoView::TemplateLibInfoView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemplateLibInfoView)
{
    ui->setupUi(this);
}

TemplateLibInfoView::~TemplateLibInfoView()
{
    delete ui;
}
