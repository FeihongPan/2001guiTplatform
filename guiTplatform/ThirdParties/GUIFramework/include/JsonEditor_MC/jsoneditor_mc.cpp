#include "jsoneditor_mc.h"
#include "ui_jsoneditor_mc.h"
#include "JsonEditor_MC/itemdelegate_mc.h"
#include "StyleSheet/stylesheet.h"

#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QGraphicsDropShadowEffect>

JsonEditor_MC::JsonEditor_MC(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JsonEditor_MC)
{
    ui->setupUi(this);

    jsonModel = new JsonTreeModel_MC(this);
    ui->treeView->setModel(jsonModel);
    ui->treeView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->treeView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->treeView->header()->setSectionResizeMode(QHeaderView::Fixed);
    ui->treeView->header()->setStretchLastSection(true);
    ui->treeView->header()->setDefaultAlignment(Qt::AlignCenter );
    ui->treeView->setColumnWidth(0, 400);
    ui->treeView->setColumnWidth(1, 170);
    ui->treeView->setColumnWidth(2, 170);
    ui->treeView->setColumnWidth(3, 170);
    ui->treeView->setColumnWidth(4, 170);
    ui->treeView->setItemDelegateForColumn(1, ItemDelegate_MC::getInstance());
    ui->treeView->setItemDelegateForColumn(2, ItemDelegate_MC::getInstance());
    ui->treeView->setItemDelegateForColumn(3, ItemDelegate_MC::getInstance());
    ui->treeView->setItemDelegateForColumn(4, ItemDelegate_MC::getInstance());
    ui->treeView->setItemDelegateForColumn(5, ItemDelegate_MC::getInstance());
    ui->treeView->setItemDelegateForColumn(6, ItemDelegate_MC::getInstance());
    ui->treeView->setStyleSheet(GlobalStyleSheet->treeStyle);

    QGraphicsDropShadowEffect *effect_tree = new QGraphicsDropShadowEffect(this);
    effect_tree->setOffset(0, 0);
    effect_tree->setColor(QColor(0, 0, 0, 64));
    effect_tree->setBlurRadius(10);
    ui->treeView->setGraphicsEffect(effect_tree);
}

JsonEditor_MC::~JsonEditor_MC()
{
    delete ui;
}

void JsonEditor_MC::expandAll()
{
    ui->treeView->expandAll();
}

void JsonEditor_MC::loadJson(QByteArray &data)
{
    jsonModel->loadJson(data);
}

void JsonEditor_MC::dumpJson(QByteArray &data)
{
    //    jsonModel->dumpJson(data);

    QJsonValue jsonVal = jsonModel->getJson();
    QJsonDocument jsonDoc(jsonVal.toObject());

    data = jsonDoc.toJson();
}

void JsonEditor_MC::setReadOnly(bool readOnly)
{
    jsonModel->setReadOnly(readOnly);
}

void JsonEditor_MC::updateIndex()
{
    bool hasCurrent = ui->treeView->selectionModel()->currentIndex().isValid();
    if (hasCurrent)
    {
        ui->treeView->closePersistentEditor(ui->treeView->selectionModel()->currentIndex());

        int row = ui->treeView->selectionModel()->currentIndex().row();
        int column = ui->treeView->selectionModel()->currentIndex().column();
        if (ui->treeView->selectionModel()->currentIndex().parent().isValid())
        {
            qDebug() << tr("Position: (%1,%2)").arg(row).arg(column);
        }
        else
        {
            qDebug() << tr("Position: (%1,%2) in top level").arg(row).arg(column);
        }
    }
}
