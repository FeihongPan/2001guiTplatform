#include "mceditorview.h"
#include "ui_mceditorview.h"

McEditorView::McEditorView(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::McEditorView)
{
    ui->setupUi(this);
}
McEditorView::~McEditorView()
{
    delete ui;
}

void McEditorView::setConstant(QByteArray data)
{
    ui->widget->loadJson(data);
}

void McEditorView::setMcContent(S_MCContent &mcContext)
{
    QByteArray data = mcContext.toRawJson();
    ui->widget->loadJson(data);
}

void McEditorView::dumpJson(QByteArray &data)
{
    ui->widget->dumpJson(data);
}

void McEditorView::expandAll()
{
    ui->widget->expandAll();
}

void McEditorView::setReadOnly(bool readOnly)
{
    ui->widget->setReadOnly(readOnly);
}

void McEditorView::ConstructFinished()
{

}

void McEditorView::setWidgets()
{

}

void McEditorView::setWidgetStyleSheet()
{
    ui->widget->setStyleSheet(GlobalStyleSheet->tabStyle + GlobalStyleSheet->fontStyle_normal_12);
}

void McEditorView::setLanguageKeys()
{

}

void McEditorView::setConnections()
{

}
