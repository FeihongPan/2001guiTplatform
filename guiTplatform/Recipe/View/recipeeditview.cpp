#include "recipeeditview.h"
#include "ui_recipeeditview.h"
#include "Language/language.h"
#include "AuthorityManage/WidgetManage/authoritywdgmanager.h"
#include "IRecipe/Command/cmd_recipe.h"
#include "IRecipe/Subscriber/recipesubscriber.h"
#include "ITemplateLib/Subscriber/templatelibsubscriber.h"

#include <QFileDialog>

RecipeEditView::RecipeEditView(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::RecipeEditView)
{
    ui->setupUi(this);
    QStringList verticalHeader;
    verticalHeader << QStringLiteral("index");
    ui->fl_tableWidget->setVerticalHeaderLabels(verticalHeader);
    QHeaderView *headerView = ui->fl_tableWidget->verticalHeader();
    headerView->setHidden(false);
    //    ui->Bonding_tableWidget->setSelectionBehavior(QTableWidget::SelectRows);
    //    ui->Bonding_tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}

RecipeEditView::~RecipeEditView()
{
    delete ui;
}

void RecipeEditView::SetRecipe(S_Recipe &recipe)
{
    this->recipe = recipe;
}

void RecipeEditView::SetRecipe(QByteArray &recipe)
{
    ui->jsonView->loadJson(recipe);
}


void RecipeEditView::ConstructFinished()
{
    emit ui->cbx_shape->currentIndexChanged("Round");
    //    emit ui->type2_comboBox_3->activated("radius");

    ui->coarseAlign_tableWidget->horizontalHeader()->setMinimumSectionSize(50);
    ui->coarseAlign_tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->coarseAlign_tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->coarseAlign_tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

    ui->backAlign_tableWidget->horizontalHeader()->setMinimumSectionSize(50);
    ui->backAlign_tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->backAlign_tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->backAlign_tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

    ui->refineAlign_tableWidget->horizontalHeader()->setMinimumSectionSize(50);
    ui->refineAlign_tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->refineAlign_tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->refineAlign_tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

    ui->fl_tableWidget->horizontalHeader()->setMinimumSectionSize(50);
    //    ui->fl_tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    //    ui->fl_tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    ui->fl_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void RecipeEditView::setWidgets()
{
    ui->tabWidget->removeTab(4); // 20230519 by Jaydon
}

void RecipeEditView::setWidgetStyleSheet()
{
    setStyleSheet(StyleSheet::getInstance()->DoubleSpinBox_Dark);
    ui->jsonView->setStyleSheet(StyleSheet::getInstance()->tabStyle + StyleSheet::getInstance()->fontStyle_normal_12);
    //    ui->Bonding_tableWidget->setStyleSheet(StyleSheet::getInstance()->tabStyle + StyleSheet::getInstance()->fontStyle_normal_12);
    //    ui->al_crs_down_tableWidget_3->setStyleSheet(StyleSheet::getInstance()->tabStyle + StyleSheet::getInstance()->fontStyle_normal_12);
    ui->coarseAlign_tableWidget->setStyleSheet(StyleSheet::getInstance()->tabStyle + StyleSheet::getInstance()->fontStyle_normal_12);
    ui->refineAlign_tableWidget->setStyleSheet(StyleSheet::getInstance()->tabStyle + StyleSheet::getInstance()->fontStyle_normal_12);
    ui->backAlign_tableWidget->setStyleSheet(StyleSheet::getInstance()->tabStyle + StyleSheet::getInstance()->fontStyle_normal_12);
    //    ui->al_fine_tableWidget_2->setStyleSheet(StyleSheet::getInstance()->tabStyle + StyleSheet::getInstance()->fontStyle_normal_12);
    ui->fl_tableWidget->setStyleSheet(StyleSheet::getInstance()->tabStyle + StyleSheet::getInstance()->fontStyle_normal_12);
    ui->tabWidget->setStyleSheet(StyleSheet::getInstance()->TabWidget + StyleSheet::getInstance()->fontStyle_normal_12);

    ui->substrate_groupBox->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->ComboBox + StyleSheet::getInstance()->DoubleSpinBox_Dark);
    ui->substrate2_groupBox_2->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->ComboBox + StyleSheet::getInstance()->DoubleSpinBox_Dark);
    ui->gpb_coarseAlign_point->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->Button_Border + StyleSheet::getInstance()->SpinBox_Dark);
    ui->gpb_refineAlign_point->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->Button_Border + StyleSheet::getInstance()->SpinBox_Dark);
    ui->gpb_backAlign_point->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->Button_Border + StyleSheet::getInstance()->SpinBox_Dark);
    //    ui->crs_down_group->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->Button_Border + StyleSheet::getInstance()->SpinBox_Dark);
    //    ui->fine_groupBox_5->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->Button_Border + StyleSheet::getInstance()->SpinBox_Dark);
    //    ui->aloffset_groupbox->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->DoubleSpinBox_Dark);
    ui->fl_groupBox->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->Button_Border + StyleSheet::getInstance()->SpinBox_Dark);
    //    ui->BondingSequence_groupBox_6->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->ComboBox + StyleSheet::getInstance()->Button_Border);
    //    ui->bonding_groupBox_2->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->SpinBox_Dark);
    //    for (auto group : ui->stackedWidget->findChildren<GroupBox *>())
    //    {
    //        group->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->LineEdit_Dark + StyleSheet::getInstance()->ComboBox + StyleSheet::getInstance()->SpinBox_Dark +
    //                             StyleSheet::getInstance()->DoubleSpinBox_Dark);
    //    }

    //    for (auto group : ui->stackedWidget->findChildren<GroupBox *>())
    //    {
    //        group->SetheaderFontSize(16);
    //        for (auto lineEdit : group->findChildren<QLineEdit *>())
    //        {
    //            if (lineEdit->objectName() != "qt_spinbox_lineedit")
    //            {
    //                group->SetHeaderText(Tr(lineEdit->text()));
    //            }
    //        }
    //    }

    ui->substrate_groupBox->SetheaderFontSize(16);
    ui->substrate_groupBox->SetHeaderText(Tr("Substrate"));
    ui->substrate2_groupBox_2->SetheaderFontSize(16);
    ui->substrate2_groupBox_2->SetHeaderText(Tr("Template"));
    ui->gpb_coarseAlign_point->SetheaderFontSize(16);
    ui->gpb_coarseAlign_point->SetHeaderText(Tr("CoarseAlign Points"));
    ui->gpb_refineAlign_point->SetheaderFontSize(16);
    ui->gpb_refineAlign_point->SetHeaderText(Tr("RefineAlign Points"));
    ui->gpb_backAlign_point->SetheaderFontSize(16);
    ui->gpb_backAlign_point->SetHeaderText(Tr("BackAlign Points"));
    ui->gpb_model->SetheaderFontSize(16);
    ui->gpb_model->SetHeaderText(Tr("Model"));
    ui->gpb_preAlign->SetheaderFontSize(16);
    ui->gpb_preAlign->SetHeaderText(Tr("Pre-Align"));

    ui->fl_groupBox->SetheaderFontSize(16);
    ui->gpb_mapping->SetheaderFontSize(16);
    ui->gpb_offset->SetheaderFontSize(16);
    ui->gpb_mapping->SetHeaderText(Tr("Mapping"));
    ui->fl_groupBox->SetHeaderText(Tr("FL Points"));
    ui->gpb_offset->SetHeaderText(Tr("Focus Offset"));
    ui->gpb_MicroStageCompensation->SetHeaderText(Tr("MicroStage Compensation"));
    ui->gpb_MicroStageCompensation->SetheaderFontSize(16);
    ui->gpb_CameraParams->SetHeaderText(Tr("Camera Params"));
    ui->gpb_CameraParams->SetheaderFontSize(16);
    //    ui->gpb_MatchAlgorithm->SetHeaderText(Tr("Match Algorithm"));
    //    ui->gpb_MatchAlgorithm->SetheaderFontSize(16);

    ui->gpb_exposure1->SetheaderFontSize(16);
    ui->gpb_exposure2->SetheaderFontSize(16);
    ui->gpb_exposure3->SetheaderFontSize(16);
    ui->gpb_exposure_compensation->SetheaderFontSize(16);
    ui->gpb_exposure1->SetHeaderText(Tr("Model"));
    ui->gpb_exposure2->SetHeaderText(Tr("Compensation Grid"));
    ui->gpb_exposure3->SetHeaderText(Tr("Dose"));
    ui->gpb_exposure_compensation->SetHeaderText(Tr("Compensation Switch"));

    ui->tabWidget->setTabText(0, Tr("Material"));
    ui->tabWidget->setTabText(1, Tr("FocAndLev"));
    ui->tabWidget->setTabText(2, Tr("Align"));
    ui->tabWidget->setTabText(3, Tr("Exposure"));
    ui->tabWidget->setTabText(4, Tr("AllParmeters"));
}

void RecipeEditView::setLanguageKeys()
{

}

void RecipeEditView::setConnections()
{
    connect(ui->cbx_shape, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), this, [ = ](const QString & arg1)
    {
        this->typeComboBoxUpCurrentTextChanged(arg1);
    });


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


    connect(ui->coarseAlign_add_pushButton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_add(ui->coarseAlign_tableWidget);
    });

    connect(ui->coarseAlign_delete_pushbutton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_delete(ui->coarseAlign_tableWidget);
    });

    connect(ui->coarseAlign_up_pushbutton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_up(ui->coarseAlign_tableWidget);
    });

    connect(ui->coarseAlign_down_pushbutton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_down(ui->coarseAlign_tableWidget);
    });

    connect(ui->backAlign_add_pushButton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_add(ui->backAlign_tableWidget);
    });

    connect(ui->backAlign_delete_pushbutton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_delete(ui->backAlign_tableWidget);
    });

    connect(ui->backAlign_up_pushbutton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_up(ui->backAlign_tableWidget);
    });

    connect(ui->backAlign_down_pushbutton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_down(ui->backAlign_tableWidget);
    });

    connect(ui->refineAlign_add_pushButton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_add(ui->refineAlign_tableWidget);
    });

    connect(ui->refineAlign_delete_pushbutton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_delete(ui->refineAlign_tableWidget);
    });

    connect(ui->refineAlign_up_pushbutton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_up(ui->refineAlign_tableWidget);
    });

    connect(ui->refineAlign_down_pushbutton, &QPushButton::clicked, this, [ = ]()
    {
        this->pointTabWidget_down(ui->refineAlign_tableWidget);
    });

    connect(TemplateLibSubscriber::getInstance(), &TemplateLibSubscriber::sig_TemplateNames, this, [ = ](S_List_String & templateNames)
    {
        this->m_lst_TemplateLibNames = templateNames.values;
        ui->cbb_ID_Stencil->clear();
        ui->cbb_ID_Stencil->addItems(this->m_lst_TemplateLibNames);
    });
}

void RecipeEditView::setEditorStatus(bool status) // FIXOKGUYS
{
    ui->Substrates->setEnabled(status);
    ui->Align->setEnabled(status);
    ui->FocAndLev->setEnabled(status);
    ui->Exposure->setEnabled(status);
}

void RecipeEditView::expandAll()
{
    ui->jsonView->expandAll();
}

void RecipeEditView::dumpJson(QByteArray &data)
{
    ui->jsonView->dumpJson(data);
}

void RecipeEditView::loadUi()
{
    //substrate
    ui->cbx_shape->setCurrentIndex(1);
    ui->dbb_radius->setValue(0);
    ui->dbb_width->setValue(0);
    ui->dbb_heigth->setValue(0);
    ui->dbb_thickness->setValue(0);
    ui->dbb_orientation->setValue(0);
    //    ui->cbb_ID_Stencil->clear();
    //    ui->cbb_ID_Stencil->addItems(this->m_lst_TemplateLibNames);
    qDebug() << "this->m_lst_TemplateLibNames:" << this->m_lst_TemplateLibNames;
    //Round
    if (this->recipe.recipeContent.substrates.size.count() == 1)
    {
        ui->cbx_shape->setCurrentIndex(0);
        emit ui->cbx_shape->currentIndexChanged("Round");
        ui->dbb_radius->setValue(this->recipe.recipeContent.substrates.size[0]);
    }
    //Rect
    else if(this->recipe.recipeContent.substrates.size.count() == 2)
    {
        ui->cbx_shape->setCurrentIndex(1);
        emit ui->cbx_shape->currentIndexChanged("Rect");
        ui->dbb_width->setValue(this->recipe.recipeContent.substrates.size[0]);
        ui->dbb_heigth->setValue(this->recipe.recipeContent.substrates.size[1]);
    }
    ui->dbb_thickness->setValue(this->recipe.recipeContent.substrates.thickness);
    ui->dbb_orientation->setValue(this->recipe.recipeContent.substrates.orientation);
    if(m_lst_TemplateLibNames.contains(this->recipe.recipeContent.stencil.id))
    {
        ui->cbb_ID_Stencil->setCurrentText(this->recipe.recipeContent.stencil.id);
    }
    else
    {
        ui->cbb_ID_Stencil->setCurrentIndex(0);
    }

    //focusAndLeveing
    ui->rbt_mapping->setChecked(this->recipe.recipeContent.focusAndLeveing.isMapping);
    ui->dbb_intervalX->setValue(this->recipe.recipeContent.focusAndLeveing.mappingInterval.x);
    ui->dbb_intervalY->setValue(this->recipe.recipeContent.focusAndLeveing.mappingInterval.y);
    ui->dbb_offset->setValue(this->recipe.recipeContent.focusAndLeveing.focusOffset);
    ui->dbb_intervalX->setValue(this->recipe.recipeContent.focusAndLeveing.mappingInterval.x);
    ui->dbb_intervalY->setValue(this->recipe.recipeContent.focusAndLeveing.mappingInterval.y);
    ui->spb_flPassThresholdNum->setValue(this->recipe.recipeContent.focusAndLeveing.passThresholdNumber);

    ui->fl_tableWidget->setRowCount(0);
    QList<QPointF> lst_Points;
    QList<QColor> lst_Colors;
    for(int i = 0; i < this->recipe.recipeContent.focusAndLeveing.lst_FLPoints.count(); i++)
    {
        ui->fl_tableWidget->insertRow(i);
        double x = this->recipe.recipeContent.focusAndLeveing.lst_FLPoints[i].x;
        double y = this->recipe.recipeContent.focusAndLeveing.lst_FLPoints[i].y;
        lst_Points.append(QPointF(x, y));
        lst_Colors.append(QColor(100, 100, 100));
        for(int j = 0; j < this->recipe.recipeContent.focusAndLeveing.lst_FLPoints[i].ToDoubleList().count(); j++)
        {
            ItemDelegate *dlg = ItemDelegate::getInstance();
            ui->fl_tableWidget->setItemDelegateForColumn(j, dlg);
            ui->fl_tableWidget->model()->setData(ui->fl_tableWidget->model()->index(i, j), this->recipe.recipeContent.focusAndLeveing.lst_FLPoints[i].ToDoubleList()[j]);
        }
    }

    ui->wgt_illustrationLeveling->setRadius(ui->dbb_radius->value());
    ui->wgt_illustrationLeveling->setFocAndLelPoints(lst_Points);
    ui->wgt_illustrationLeveling->setFocAndLelColors(lst_Colors);
    ui->wgt_illustrationLeveling->update();

    ui->dsb_ExposureTime->setValue(this->recipe.recipeContent.exposureTime);
    ui->dsb_FocalOffset->setValue(this->recipe.recipeContent.focalOffset);
    if (this->recipe.recipeContent.rectROI.size() == 4)
    {
        ui->dsb_ROI_x->setValue(this->recipe.recipeContent.rectROI[0]);
        ui->dsb_ROI_y->setValue(this->recipe.recipeContent.rectROI[1]);
        ui->dsb_ROI_w->setValue(this->recipe.recipeContent.rectROI[2]);
        ui->dsb_ROI_h->setValue(this->recipe.recipeContent.rectROI[3]);
    }
    ui->rbt_ShapeMatch->setChecked(this->recipe.recipeContent.isShapeMatch);
    ui->rbt_GrayMatch->setChecked(this->recipe.recipeContent.isGrayMatch);

    //Back Align
    ui->rbt_isAllowBackAlign->setChecked(this->recipe.recipeContent.isAllowManualAlign);

    //coarseAlign
    ui->cbx_model->setCurrentText(QString::number(this->recipe.recipeContent.coarseAlign.model));
    ui->rbt_isBlank->setChecked(this->recipe.recipeContent.isBlank);
    ui->rbt_isAllowManualAlign->setChecked(this->recipe.recipeContent.isAllowManualAlign);
    ui->rbt_isPreAlign->setChecked(this->recipe.recipeContent.isPreAlign);
    ui->dsb_posCCD->setValue(this->recipe.recipeContent.coarseAlign.CCD_Pos);
    if(this->recipe.recipeContent.coarseAlign.lst_RotatingAngles.count() != 0)
    {
        ui->dsb_rotatingAngle1->setValue(this->recipe.recipeContent.coarseAlign.lst_RotatingAngles[0]);
        ui->dsb_rotatingAngle2->setValue(this->recipe.recipeContent.coarseAlign.lst_RotatingAngles[1]);
        ui->dsb_rotatingAngle3->setValue(this->recipe.recipeContent.coarseAlign.lst_RotatingAngles[2]);
    }
    //    ui->dbb_searchWidth->setValue(this->recipe.recipeContent.coarseAlign.searchWidth);
    //    ui->dbb_searchHeight->setValue(this->recipe.recipeContent.coarseAlign.searchHeight);
    //    ui->sb_searchStep->setValue(this->recipe.recipeContent.coarseAlign.searchStep);

    QList<QPointF> lst_AlignPoints;
    QList<QColor> lst_AlignColors;
    // coarseAlign
    ui->coarseAlign_tableWidget->setRowCount(0);
    for(int i = 0; i < this->recipe.recipeContent.coarseAlign.lst_AlignPoints.count(); i++)
    {

        double x = this->recipe.recipeContent.coarseAlign.lst_AlignPoints[i].point.x;
        double y = this->recipe.recipeContent.coarseAlign.lst_AlignPoints[i].point.y;
        lst_AlignPoints.append(QPointF(x, y));
        lst_AlignColors.append(QColor(100, 100, 100));

        ui->coarseAlign_tableWidget->insertRow(i);
        for(int j = 0; j < this->recipe.recipeContent.coarseAlign.lst_AlignPoints[i].point.ToDoubleList().count(); j++)
        {
            ItemDelegate *dlg = ItemDelegate::getInstance();
            ui->coarseAlign_tableWidget->setItemDelegateForColumn(j, dlg);
            ui->coarseAlign_tableWidget->model()->setData(ui->coarseAlign_tableWidget->model()->index(i, j), this->recipe.recipeContent.coarseAlign.lst_AlignPoints[i].point.ToDoubleList()[j]);
        }
        ui->coarseAlign_tableWidget->model()->setData(ui->coarseAlign_tableWidget->model()->index(i, 2), this->recipe.recipeContent.coarseAlign.lst_AlignPoints[i].markId);
        ui->coarseAlign_tableWidget->model()->setData(ui->coarseAlign_tableWidget->model()->index(i, 3), this->recipe.recipeContent.coarseAlign.lst_AlignPoints[i].threshold);
    }
    ui->spb_coarseMinValidMarks->setValue(this->recipe.recipeContent.coarseAlign.minValidMarks);

    ui->wgt_illustrationAlign->setRadius(ui->dbb_radius->value());
    ui->wgt_illustrationAlign->setAlignPoints(lst_AlignPoints);
    ui->wgt_illustrationAlign->setAlignColors(lst_AlignColors);
    ui->wgt_illustrationAlign->update();

    //refineAlign
    ui->refineAlign_tableWidget->setRowCount(0);
    for(int i = 0; i < this->recipe.recipeContent.refineAlign.lst_AlignPoints.count(); i++)
    {
        ui->refineAlign_tableWidget->insertRow(i);
        for(int j = 0; j < this->recipe.recipeContent.refineAlign.lst_AlignPoints[i].point.ToDoubleList().count(); j++)
        {
            ItemDelegate *dlg = ItemDelegate::getInstance();
            ui->refineAlign_tableWidget->setItemDelegateForColumn(j, dlg);
            ui->refineAlign_tableWidget->model()->setData(ui->refineAlign_tableWidget->model()->index(i, j), this->recipe.recipeContent.refineAlign.lst_AlignPoints[i].point.ToDoubleList()[j]);
        }
        ui->refineAlign_tableWidget->model()->setData(ui->refineAlign_tableWidget->model()->index(i, 2), this->recipe.recipeContent.refineAlign.lst_AlignPoints[i].markId);
        ui->refineAlign_tableWidget->model()->setData(ui->refineAlign_tableWidget->model()->index(i, 3), this->recipe.recipeContent.refineAlign.lst_AlignPoints[i].threshold);
    }
    ui->spb_refineMinValidMarks->setValue(this->recipe.recipeContent.refineAlign.minValidMarks);

    //backAlign
    ui->backAlign_tableWidget->setRowCount(0);
    for(int i = 0; i < this->recipe.recipeContent.backAlign.lst_AlignPoints.count(); i++)
    {
        ui->backAlign_tableWidget->insertRow(i);
        for(int j = 0; j < this->recipe.recipeContent.backAlign.lst_AlignPoints[i].point.ToDoubleList().count(); j++)
        {
            ItemDelegate *dlg = ItemDelegate::getInstance();
            ui->backAlign_tableWidget->setItemDelegateForColumn(j, dlg);
            ui->backAlign_tableWidget->model()->setData(ui->backAlign_tableWidget->model()->index(i, j), this->recipe.recipeContent.backAlign.lst_AlignPoints[i].point.ToDoubleList()[j]);
        }
        ui->backAlign_tableWidget->model()->setData(ui->backAlign_tableWidget->model()->index(i, 2), this->recipe.recipeContent.backAlign.lst_AlignPoints[i].markId);
        ui->backAlign_tableWidget->model()->setData(ui->backAlign_tableWidget->model()->index(i, 3), this->recipe.recipeContent.backAlign.lst_AlignPoints[i].threshold);
    }
    ui->spb_backMinValidMarks->setValue(this->recipe.recipeContent.backAlign.minValidMarks);

    //exposure
    ui->cbx_wavelength->setCurrentIndex(this->recipe.recipeContent.exposure.model.waveLength);
    ui->rbt_isLocalAlign->setChecked(this->recipe.recipeContent.exposure.model.isLocalAlign);
    ui->rbt_isLocalFocus->setChecked(this->recipe.recipeContent.exposure.model.isLocalFocus);
    ui->dbb_exposure_X->setValue(this->recipe.recipeContent.exposure.compensationGrid.x);
    ui->dbb_exposure_Y->setValue(this->recipe.recipeContent.exposure.compensationGrid.y);
    ui->dbb_dose->setValue(this->recipe.recipeContent.exposure.dose);

    ui->dsb_MicroStage_X->setValue(this->recipe.recipeContent.exposure.microStageCompensation.x);
    ui->dsb_MicroStage_Y->setValue(this->recipe.recipeContent.exposure.microStageCompensation.y);
    ui->dsb_MicroStage_Rz->setValue(this->recipe.recipeContent.exposure.microStageCompensation.Rz);
    ui->dsb_MicroStage_ZOffset->setValue(this->recipe.recipeContent.exposure.microStageCompensation.zOffset);

    ui->rbt_isMaskStageCompensation->setChecked(this->recipe.recipeContent.exposure.compensation.isMaskStageCompensation);
    ui->rbt_isMicroStageCompensation->setChecked(this->recipe.recipeContent.exposure.compensation.isMicroStageCompensation);
    ui->rbt_isAlignCompensation->setChecked(this->recipe.recipeContent.exposure.compensation.isAlignCompensation);
    ui->rbt_isDownFLSCompensation->setChecked(this->recipe.recipeContent.exposure.compensation.isDownFLSCompensation);
    ui->rbt_isOverlayCompensation->setChecked(this->recipe.recipeContent.exposure.compensation.isOverlayCompensation);
}

void RecipeEditView::dumpUi()
{
    //substrate
    //    this->recipe.recipeContent.lst_Substrates[0].size.clear();
    S_Substrate s_substrate;
    s_substrate.size.clear();
    s_substrate.thickness = ui->dbb_thickness->value();
    s_substrate.orientation = ui->dbb_orientation->value();
    //    s_substrate.inch = ui->dbb_size->value();
    if(ui->cbx_shape->currentText() == "Round")
    {
        s_substrate.size.append(ui->dbb_radius->value());
        //        this->recipe.recipeContent.lst_Substrates[0].size.append(ui->dbb_radius->value());
        //        this->recipe.recipeContent.lst_Substrates[0].thickness = ui->dbb_thickness->value();
        //        this->recipe.recipeContent.lst_Substrates[0].orientation = ui->dbb_orientation->value();
    }
    else if(ui->cbx_shape->currentText() == "Rect")
    {
        s_substrate.size.append(ui->dbb_width->value());
        s_substrate.size.append(ui->dbb_heigth->value());
        //        this->recipe.recipeContent.lst_Substrates[0].size.append(ui->dbb_width->value());
        //        this->recipe.recipeContent.lst_Substrates[0].size.append(ui->dbb_heigth->value());
        //        this->recipe.recipeContent.lst_Substrates[0].thickness = ui->dbb_thickness->value();
        //        this->recipe.recipeContent.lst_Substrates[0].orientation = ui->dbb_orientation->value();
    }
    // this->recipe.recipeContent.lst_Substrates.clear();
    this->recipe.recipeContent.substrates = s_substrate;
    this->recipe.recipeContent.stencil.id = ui->cbb_ID_Stencil->currentText();

    // focusAndLeveing
    this->recipe.recipeContent.focusAndLeveing.isMapping = ui->rbt_mapping->isChecked();
    this->recipe.recipeContent.focusAndLeveing.mappingInterval.x = ui->dbb_intervalX->value();
    this->recipe.recipeContent.focusAndLeveing.mappingInterval.y = ui->dbb_intervalY->value();
    this->recipe.recipeContent.focusAndLeveing.focusOffset = ui->dbb_offset->value();
    this->recipe.recipeContent.focusAndLeveing.passThresholdNumber = ui->spb_flPassThresholdNum->value();

    // this->recipe.recipeContent.focusAndLeveing.lst_FLPoints.clear();
    S_Point2D s_point2D;
    this->recipe.recipeContent.focusAndLeveing.lst_FLPoints.clear();
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
        this->recipe.recipeContent.focusAndLeveing.lst_FLPoints.append(s_point2D);
    }

    this->recipe.recipeContent.isBlank = ui->rbt_isBlank->isChecked();
    this->recipe.recipeContent.isAllowManualAlign = ui->rbt_isAllowManualAlign->isChecked();
    this->recipe.recipeContent.isAllowBackAlign = ui->rbt_isAllowBackAlign->isChecked();
    this->recipe.recipeContent.isPreAlign = ui->rbt_isPreAlign->isChecked();

    //coarseAlign
    this->recipe.recipeContent.coarseAlign.model = ui->cbx_model->currentText().toInt();
    this->recipe.recipeContent.coarseAlign.CCD_Pos = ui->dsb_posCCD->value();
    this->recipe.recipeContent.coarseAlign.lst_RotatingAngles.clear();
    this->recipe.recipeContent.coarseAlign.lst_RotatingAngles.append(ui->dsb_rotatingAngle1->value());
    this->recipe.recipeContent.coarseAlign.lst_RotatingAngles.append(ui->dsb_rotatingAngle2->value());
    this->recipe.recipeContent.coarseAlign.lst_RotatingAngles.append(ui->dsb_rotatingAngle3->value());

    this->recipe.recipeContent.coarseAlign.minValidMarks = ui->spb_coarseMinValidMarks->value();
    this->recipe.recipeContent.backAlign.minValidMarks = ui->spb_backMinValidMarks->value();
    this->recipe.recipeContent.refineAlign.minValidMarks = ui->spb_refineMinValidMarks->value();
    //    this->recipe.recipeContent.coarseAlign.searchWidth = ui->dbb_searchWidth->value();
    //    this->recipe.recipeContent.coarseAlign.searchHeight = ui->dbb_searchHeight->value();
    //    this->recipe.recipeContent.coarseAlign.searchStep = ui->sb_searchStep->value();

    this->recipe.recipeContent.exposureTime = ui->dsb_ExposureTime->value();
    this->recipe.recipeContent.focalOffset = ui->dsb_FocalOffset->value();

    this->recipe.recipeContent.rectROI.clear();
    this->recipe.recipeContent.rectROI.push_back(ui->dsb_ROI_x->value());
    this->recipe.recipeContent.rectROI.push_back(ui->dsb_ROI_y->value());
    this->recipe.recipeContent.rectROI.push_back(ui->dsb_ROI_w->value());
    this->recipe.recipeContent.rectROI.push_back(ui->dsb_ROI_h->value());

    this->recipe.recipeContent.isShapeMatch = ui->rbt_ShapeMatch->isChecked();
    this->recipe.recipeContent.isGrayMatch = ui->rbt_GrayMatch->isChecked();

    // Coarse Align
    S_AlignPoint s_coarseAlignpoint;
    this->recipe.recipeContent.coarseAlign.lst_AlignPoints.clear();
    for (int i = 0; i < ui->coarseAlign_tableWidget->rowCount(); i++)
    {
        for (int j = 0; j < ui->coarseAlign_tableWidget->columnCount(); j++)
        {
            if (j == 0)
            {
                s_coarseAlignpoint.point.x = ui->coarseAlign_tableWidget->model()->index(i, j).data().toDouble();;
                //                this->recipe.recipeContent.alignment.lst_AlignPoints[i].point.x = ui->align_tableWidget->model()->index(i, j).data().toDouble();
            }
            else if (j == 1)
            {
                s_coarseAlignpoint.point.y = ui->coarseAlign_tableWidget->model()->index(i, j).data().toDouble();;
                //                this->recipe.recipeContent.alignment.lst_AlignPoints[i].point.y = ui->align_tableWidget->model()->index(i, j).data().toDouble();
            }
            else if (j == 2)
            {
                s_coarseAlignpoint.markId = ui->coarseAlign_tableWidget->model()->index(i, j).data().toString();;
                //                this->recipe.recipeContent.alignment.lst_AlignPoints[i].markId = ui->fl_tableWidget->model()->index(i, j).data().toString();
            }
            else if (j == 3)
            {
                s_coarseAlignpoint.threshold = ui->coarseAlign_tableWidget->model()->index(i, j).data().toString();
                //                this->recipe.recipeContent.alignment.lst_AlignPoints[i].threshold = ui->fl_tableWidget->model()->index(i, j).data().toString();
            }
        }
        this->recipe.recipeContent.coarseAlign.lst_AlignPoints.append(s_coarseAlignpoint);
    }

    // Refine Align
    S_AlignPoint s_refineAlignpoint;
    this->recipe.recipeContent.refineAlign.lst_AlignPoints.clear();
    for (int i = 0; i < ui->refineAlign_tableWidget->rowCount(); i++)
    {
        for (int j = 0; j < ui->refineAlign_tableWidget->columnCount(); j++)
        {
            if (j == 0)
            {
                s_refineAlignpoint.point.x = ui->refineAlign_tableWidget->model()->index(i, j).data().toDouble();;
                //                this->recipe.recipeContent.alignment.lst_AlignPoints[i].point.x = ui->align_tableWidget->model()->index(i, j).data().toDouble();
            }
            else if (j == 1)
            {
                s_refineAlignpoint.point.y = ui->refineAlign_tableWidget->model()->index(i, j).data().toDouble();;
                //                this->recipe.recipeContent.alignment.lst_AlignPoints[i].point.y = ui->align_tableWidget->model()->index(i, j).data().toDouble();
            }
            else if (j == 2)
            {
                s_refineAlignpoint.markId = ui->refineAlign_tableWidget->model()->index(i, j).data().toString();;
                //                this->recipe.recipeContent.alignment.lst_AlignPoints[i].markId = ui->fl_tableWidget->model()->index(i, j).data().toString();
            }
            else if (j == 3)
            {
                s_refineAlignpoint.threshold = ui->refineAlign_tableWidget->model()->index(i, j).data().toString();
                //                this->recipe.recipeContent.alignment.lst_AlignPoints[i].threshold = ui->fl_tableWidget->model()->index(i, j).data().toString();
            }
        }
        this->recipe.recipeContent.refineAlign.lst_AlignPoints.append(s_refineAlignpoint);
    }

    // Back Align
    S_AlignPoint s_backAlignpoint;
    this->recipe.recipeContent.backAlign.lst_AlignPoints.clear();
    for (int i = 0; i < ui->backAlign_tableWidget->rowCount(); i++)
    {
        for (int j = 0; j < ui->backAlign_tableWidget->columnCount(); j++)
        {
            if (j == 0)
            {
                s_backAlignpoint.point.x = ui->backAlign_tableWidget->model()->index(i, j).data().toDouble();;
                //                this->recipe.recipeContent.alignment.lst_AlignPoints[i].point.x = ui->align_tableWidget->model()->index(i, j).data().toDouble();
            }
            else if (j == 1)
            {
                s_backAlignpoint.point.y = ui->backAlign_tableWidget->model()->index(i, j).data().toDouble();;
                //                this->recipe.recipeContent.alignment.lst_AlignPoints[i].point.y = ui->align_tableWidget->model()->index(i, j).data().toDouble();
            }
            else if (j == 2)
            {
                s_backAlignpoint.markId = ui->backAlign_tableWidget->model()->index(i, j).data().toString();;
                //                this->recipe.recipeContent.alignment.lst_AlignPoints[i].markId = ui->fl_tableWidget->model()->index(i, j).data().toString();
            }
            else if (j == 3)
            {
                s_backAlignpoint.threshold = ui->backAlign_tableWidget->model()->index(i, j).data().toString();
                //                this->recipe.recipeContent.alignment.lst_AlignPoints[i].threshold = ui->fl_tableWidget->model()->index(i, j).data().toString();
            }
        }
        this->recipe.recipeContent.backAlign.lst_AlignPoints.append(s_backAlignpoint);
    }

    //exposure
    if(ui->cbx_wavelength->currentText() == "ghi")
    {
        this->recipe.recipeContent.exposure.model.waveLength = S_ExposureModel::ghi;
    }
    else if(ui->cbx_wavelength->currentText() == "gh")
    {
        this->recipe.recipeContent.exposure.model.waveLength = S_ExposureModel::gh;
    }
    else if(ui->cbx_wavelength->currentText() == "i")
    {
        this->recipe.recipeContent.exposure.model.waveLength = S_ExposureModel::i;
    }
    this->recipe.recipeContent.exposure.model.isLocalAlign = ui->rbt_isLocalAlign->isChecked();
    this->recipe.recipeContent.exposure.model.isLocalFocus = ui->rbt_isLocalFocus->isChecked();
    this->recipe.recipeContent.exposure.compensationGrid.x = ui->dbb_exposure_X->value();
    this->recipe.recipeContent.exposure.compensationGrid.y = ui->dbb_exposure_Y->value();
    this->recipe.recipeContent.exposure.dose = ui->dbb_dose->value();

    this->recipe.recipeContent.exposure.compensation.isMaskStageCompensation = ui->rbt_isMaskStageCompensation->isChecked();
    this->recipe.recipeContent.exposure.compensation.isMicroStageCompensation = ui->rbt_isMicroStageCompensation->isChecked();
    this->recipe.recipeContent.exposure.compensation.isAlignCompensation = ui->rbt_isAlignCompensation->isChecked();
    this->recipe.recipeContent.exposure.compensation.isDownFLSCompensation = ui->rbt_isDownFLSCompensation->isChecked();
    this->recipe.recipeContent.exposure.compensation.isOverlayCompensation = ui->rbt_isOverlayCompensation->isChecked();

    this->recipe.recipeContent.exposure.microStageCompensation.x = ui->dsb_MicroStage_X->value();
    this->recipe.recipeContent.exposure.microStageCompensation.y = ui->dsb_MicroStage_Y->value();
    this->recipe.recipeContent.exposure.microStageCompensation.Rz = ui->dsb_MicroStage_Rz->value();
    this->recipe.recipeContent.exposure.microStageCompensation.zOffset = ui->dsb_MicroStage_ZOffset->value();
}

void RecipeEditView::typeComboBoxUpCurrentTextChanged(const QString &arg1)
{
    if (arg1 == "Round")
    {
        ui->radius->setVisible(true);
        ui->radius_unit_rad->setVisible(true);
        ui->dbb_radius->setVisible(true);
        ui->width->setVisible(false);
        ui->width_unit_mm->setVisible(false);
        ui->dbb_width->setVisible(false);
        ui->height->setVisible(false);
        ui->height_unit_mm->setVisible(false);
        ui->dbb_heigth->setVisible(false);
    }
    else if (arg1 == "Rect")
    {
        ui->radius->setVisible(false);
        ui->radius_unit_rad->setVisible(false);
        ui->dbb_radius->setVisible(false);
        ui->width->setVisible(true);
        ui->width_unit_mm->setVisible(true);
        ui->dbb_width->setVisible(true);
        ui->height->setVisible(true);
        ui->height_unit_mm->setVisible(true);
        ui->dbb_heigth->setVisible(true);
    }
}


void RecipeEditView::pointTabWidget_add(QTableWidget *widget)
{
    int row = widget->rowCount();
    widget->insertRow(row);
    ItemDelegate *dlg = ItemDelegate::getInstance();
    widget->setItemDelegateForColumn(0, dlg);
    widget->setItemDelegateForColumn(1, dlg);
}

void RecipeEditView::pointTabWidget_delete(QTableWidget *widget)
{
    int row = widget->currentRow();
    widget->removeRow(row);
}

void RecipeEditView::pointTabWidget_up(QTableWidget *widget)
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

void RecipeEditView::pointTabWidget_down(QTableWidget *widget)
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
