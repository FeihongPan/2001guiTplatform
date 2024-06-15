#include "templatelibeditview.h"
#include "ui_templatelibeditview.h"

TemplateLibEditView::TemplateLibEditView(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::TemplateLibEditView)
{
    ui->setupUi(this);
    QStringList verticalHeader;
    verticalHeader << QStringLiteral("index");
    ui->fl_tableWidget->setVerticalHeaderLabels(verticalHeader);
    QHeaderView *headerView = ui->fl_tableWidget->verticalHeader();
    headerView->setHidden(false);
}

TemplateLibEditView::~TemplateLibEditView()
{
    delete ui;
}

void TemplateLibEditView::ConstructFinished()
{
    ui->align_tableWidget->horizontalHeader()->setMinimumSectionSize(50);
    ui->align_tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->align_tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->align_tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

    ui->fl_tableWidget->horizontalHeader()->setMinimumSectionSize(50);
    ui->fl_tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->fl_tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
}


void TemplateLibEditView::setWidgets()
{

}

void TemplateLibEditView::setWidgetStyleSheet()
{
    setStyleSheet(StyleSheet::getInstance()->DoubleSpinBox_Dark);
    ui->tabWidget->setTabText(0, Tr("FocAndLev"));
    ui->tabWidget->setTabText(1, Tr("Align"));
    ui->align_tableWidget->setStyleSheet(StyleSheet::getInstance()->tabStyle + StyleSheet::getInstance()->fontStyle_normal_12);
    ui->fl_tableWidget->setStyleSheet(StyleSheet::getInstance()->tabStyle + StyleSheet::getInstance()->fontStyle_normal_12);
    ui->tabWidget->setStyleSheet(StyleSheet::getInstance()->TabWidget + StyleSheet::getInstance()->fontStyle_normal_12);
    ui->gpb_align_flpoint->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->Button_Border + StyleSheet::getInstance()->SpinBox_Dark);
    ui->fl_groupBox->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->Button_Border + StyleSheet::getInstance()->SpinBox_Dark);
//    ui->fl_groupBox->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->Button_Border);

    ui->fl_groupBox->SetheaderFontSize(16);
    ui->fl_groupBox->SetHeaderText(Tr("FL Points"));

    ui->gpb_align_flpoint->SetheaderFontSize(16);
    ui->gpb_align_flpoint->SetHeaderText(Tr("Align Points"));

    ui->size_groupBox->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->Button_Border);
    ui->ill_groupBox1->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->Button_Border);
    ui->ill_groupBox2->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->Button_Border);
    ui->ill_groupBox3->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->Button_Border);

    ui->size_groupBox->SetHeaderText(Tr("Size"));
    ui->ill_groupBox1->SetHeaderText(Tr("FL Illustration"));
    ui->ill_groupBox2->SetHeaderText(Tr("Align Illustration"));
    ui->ill_groupBox3->SetHeaderText(Tr("Size Illustration"));

    ui->size_groupBox->SetheaderFontSize(16);
    ui->ill_groupBox1->SetheaderFontSize(16);
    ui->ill_groupBox2->SetheaderFontSize(16);
    ui->ill_groupBox3->SetheaderFontSize(16);
}

void TemplateLibEditView::setLanguageKeys()
{

}

void TemplateLibEditView::setConnections()
{
    connect(ui->fl_add_pushButton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_add(ui->fl_tableWidget);
    });
    connect(ui->fl_delete_pushButton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_delete(ui->fl_tableWidget);
    });
    connect(ui->fl_up_pushButton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_up(ui->fl_tableWidget);
    });
    connect(ui->fl_down_pushButton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_down(ui->fl_tableWidget);
    });

    connect(ui->align_add_pushButton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_add(ui->align_tableWidget);
    });
    connect(ui->align_delete_pushbutton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_delete(ui->align_tableWidget);
    });
    connect(ui->align_up_pushbutton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_up(ui->align_tableWidget);
    });
    connect(ui->align_down_pushbutton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_down(ui->align_tableWidget);
    });

    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &TemplateLibEditView::on_TabChanged );

}

void TemplateLibEditView::on_TabChanged(int index)
{
    ui->illustration1->setMode(IllustrationView::Leveling);
    ui->illustration2->setMode(IllustrationView::AlignMent);
    ui->illustration3->setMode(IllustrationView::Normal);
    ui->illustration1->update();
    ui->illustration2->update();
    ui->illustration3->update();
}

void TemplateLibEditView::setEditorStatus(bool status)
{
    ui->Align->setEnabled(status);
    ui->FocAndLev->setEnabled(status);
    ui->Size->setEnabled(status);
}

void TemplateLibEditView::loadUi()
{
    QString shape = this->templateLib.templateLibContent.templateLibSize.shape;
    double width = this->templateLib.templateLibContent.templateLibSize.width;
    double height = this->templateLib.templateLibContent.templateLibSize.height;
    double thickness = this->templateLib.templateLibContent.templateLibSize.thickness;

    ui->sBox_Width->setValue(width);
    ui->sBox_Height->setValue(height);
    ui->sBox_Thickness->setValue(thickness);

    ui->illustration1->setMode(IllustrationView::Leveling);
    ui->illustration1->setShape(IllustrationView::Rect);
    ui->illustration1->setWidth(width);
    ui->illustration1->setHeight(height);

    ui->illustration2->setMode(IllustrationView::AlignMent);
    ui->illustration2->setShape(IllustrationView::Rect);
    ui->illustration2->setWidth(width);
    ui->illustration2->setHeight(height);

    ui->illustration3->setMode(IllustrationView::Normal);
    ui->illustration3->setShape(IllustrationView::Rect);
    ui->illustration3->setWidth(width);
    ui->illustration3->setHeight(height);

    QList<QPointF> lst_LevelingPoints;
    QList<QPointF> lst_AlignPoints;
    QList<QColor> lst_LevelingColor;
    QList<QColor> lst_AlignColor;

    ui->spb_FL_PassThreshold->setValue(this->templateLib.templateLibContent.leveing.passThresholdNumber);
    ui->spb_Align_PassThreshold->setValue(this->templateLib.templateLibContent.align.passThresholdNumber);

    ui->fl_tableWidget->setRowCount(0);
    for(int i = 0; i < this->templateLib.templateLibContent.leveing.lst_FLPoints.count(); i++)
    {
        ui->fl_tableWidget->insertRow(i);
        S_Point2D point = this->templateLib.templateLibContent.leveing.lst_FLPoints[i];
        lst_LevelingPoints.append(QPoint(point.x, point.y));
        lst_LevelingColor.append(QColor(100,100,100));
        for(int j = 0; j < this->templateLib.templateLibContent.leveing.lst_FLPoints[i].ToDoubleList().count(); j++)
        {
            ItemDelegate *dlg = ItemDelegate::getInstance();
            ui->fl_tableWidget->setItemDelegateForColumn(j, dlg);
            ui->fl_tableWidget->model()->setData(ui->fl_tableWidget->model()->index(i, j), this->templateLib.templateLibContent.leveing.lst_FLPoints[i].ToDoubleList()[j]);
        }
    }

    ui->align_tableWidget->setRowCount(0);
    for(int i = 0; i < this->templateLib.templateLibContent.align.lst_AlignPoints.count(); i++)
    {
        ui->align_tableWidget->insertRow(i);
        S_AlignPointInfo pointInfo = this->templateLib.templateLibContent.align.lst_AlignPoints[i];
        lst_AlignPoints.append(QPointF(pointInfo.point.x, pointInfo.point.y));
        lst_AlignColor.append(QColor(100,100,100));
        for(int j = 0; j < this->templateLib.templateLibContent.align.lst_AlignPoints[i].point.ToDoubleList().count(); j++)
        {
            ItemDelegate *dlg = ItemDelegate::getInstance();
            ui->align_tableWidget->setItemDelegateForColumn(j, dlg);
            ui->align_tableWidget->model()->setData(ui->align_tableWidget->model()->index(i, j), this->templateLib.templateLibContent.align.lst_AlignPoints[i].point.ToDoubleList()[j]);
        }
        ui->align_tableWidget->model()->setData(ui->align_tableWidget->model()->index(i, 2), this->templateLib.templateLibContent.align.lst_AlignPoints[i].markId);
        ui->align_tableWidget->model()->setData(ui->align_tableWidget->model()->index(i, 3), this->templateLib.templateLibContent.align.lst_AlignPoints[i].threshold);
    }

    ui->illustration1->setFocAndLelPoints(lst_LevelingPoints);
    ui->illustration1->setFocAndLelColors(lst_LevelingColor);

    ui->illustration2->setAlignPoints(lst_AlignPoints);
    ui->illustration2->setAlignColors(lst_AlignColor);

    ui->illustration1->update();
    ui->illustration2->update();
    ui->illustration3->update();

//    on_TabChanged(ui->tabWidget->currentIndex());
}

void TemplateLibEditView::dumpUi()
{
    S_Point2D s_point2D;
    S_AlignPointInfo s_alignpoint;

    this->templateLib.templateLibContent.leveing.lst_FLPoints.clear();
    this->templateLib.templateLibContent.align.lst_AlignPoints.clear();

    this->templateLib.templateLibContent.templateLibSize.shape = ui->cmb_Shape->currentText();
    this->templateLib.templateLibContent.templateLibSize.width = ui->sBox_Width->value();
    this->templateLib.templateLibContent.templateLibSize.height = ui->sBox_Height->value();
    this->templateLib.templateLibContent.templateLibSize.thickness = ui->sBox_Thickness->value();

    this->templateLib.templateLibContent.leveing.passThresholdNumber = ui->spb_FL_PassThreshold->value();
    this->templateLib.templateLibContent.align.passThresholdNumber = ui->spb_Align_PassThreshold->value();

    for (int i = 0; i < ui->fl_tableWidget->rowCount(); i++)
    {
        for (int j = 0; j < ui->fl_tableWidget->columnCount(); j++)
        {
            if (j == 0)
            {
                s_point2D.x = ui->fl_tableWidget->model()->index(i, j).data().toDouble();
                //                this->recipe.recipeContent.focusAndLeveing.lst_FLPoints[i].x = ui->fl_tableWidget->model()->index(i, j).data().toDouble();
            }
            else if (j == 1)
            {
                s_point2D.y = ui->fl_tableWidget->model()->index(i, j).data().toDouble();
                //                this->recipe.recipeContent.focusAndLeveing.lst_FLPoints[i].y = ui->fl_tableWidget->model()->index(i, j).data().toDouble();
            }
        }
        this->templateLib.templateLibContent.leveing.lst_FLPoints.append(s_point2D);
    }


    for (int i = 0; i < ui->align_tableWidget->rowCount(); i++)
    {
        for (int j = 0; j < ui->align_tableWidget->columnCount(); j++)
        {
            if (j == 0)
            {
                s_alignpoint.point.x = ui->align_tableWidget->model()->index(i, j).data().toDouble();;
                //                this->recipe.recipeContent.alignment.lst_AlignPoints[i].point.x = ui->align_tableWidget->model()->index(i, j).data().toDouble();
            }
            else if (j == 1)
            {
                s_alignpoint.point.y = ui->align_tableWidget->model()->index(i, j).data().toDouble();;
                //                this->recipe.recipeContent.alignment.lst_AlignPoints[i].point.y = ui->align_tableWidget->model()->index(i, j).data().toDouble();
            }
            else if (j == 2)
            {
                s_alignpoint.markId = ui->align_tableWidget->model()->index(i, j).data().toString();;
                //                this->recipe.recipeContent.alignment.lst_AlignPoints[i].markId = ui->fl_tableWidget->model()->index(i, j).data().toString();
            }
            else if (j == 3)
            {
                s_alignpoint.threshold = ui->align_tableWidget->model()->index(i, j).data().toString();
                //                this->recipe.recipeContent.alignment.lst_AlignPoints[i].threshold = ui->fl_tableWidget->model()->index(i, j).data().toString();
            }
        }
        this->templateLib.templateLibContent.align.lst_AlignPoints.append(s_alignpoint);
    }
}


void TemplateLibEditView::pointTabWidget_add(QTableWidget *widget)
{
    int row = widget->rowCount();
    widget->insertRow(row);
    ItemDelegate *dlg = ItemDelegate::getInstance();
    widget->setItemDelegateForColumn(0, dlg);
    widget->setItemDelegateForColumn(1, dlg);
}

void TemplateLibEditView::pointTabWidget_delete(QTableWidget *widget)
{
    int row = widget->currentRow();
    widget->removeRow(row);
}

void TemplateLibEditView::pointTabWidget_up(QTableWidget *widget)
{
    int row = widget->currentRow();
    if (row > 0)
    {
        widget->insertRow(row - 1);
        for (int i = 0; i < widget->columnCount(); i++)
        {
            if (widget->item(row + 1, i) != nullptr)
            {
                widget->model()->setData(widget->model()->index(row - 1, i), widget->model()->index(row + 1, i).data());
            }
            else
            {
                widget->model()->setData(widget->model()->index(row - 1, i), QVariant(""));
            }
        }
        widget->removeRow(row + 1);
        widget->selectRow(row - 1);
    }
}

void TemplateLibEditView::pointTabWidget_down(QTableWidget *widget)
{
    int row = widget->currentRow();
    if (row + 2 <= widget->rowCount())
    {
        widget->insertRow(row + 2);
        for (int i = 0; i < widget->columnCount(); i++)
        {
            if (widget->item(row, i) != nullptr)
            {
                widget->model()->setData(widget->model()->index(row + 2, i), widget->model()->index(row, i).data());
            }
            else
            {
                widget->model()->setData(widget->model()->index(row + 2, i), QVariant(""));
            }
        }
        widget->removeRow(row);
        widget->selectRow(row + 1);
    }
}


