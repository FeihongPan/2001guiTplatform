#include "machineconstantview.h"
#include "ui_machineconstantview.h"
#include "TimeSynchronization/Manage/timesync.h"
#include "IMachineConstant/Command/cmd_machineconstant.h"
#include "IMachineConstant/Subscriber/machineconstantsubscriber.h"
#include "runtimepara.h"
#include "IMachineConstant/View/ConstantEditview/constantbasicinformation.h"

#include <QList>

using namespace std;

MachineConstantView::MachineConstantView(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::MachineConstantView)
{
    SR_ConstantInfo constantInfo;

    ui->setupUi(this);
    userModelInitialize();

    this->setStyleSheet( "GroupBox,QLineEdit,IconLineEdit,QTableView, QAbstractItemView,QHeaderView" + GlobalStyleSheet->fontStyle_export_12 );

}

MachineConstantView::~MachineConstantView()
{
    delete ui;
}


void MachineConstantView::cleanViewer()
{
    if(m_pEditView)
    {
        m_pEditView->setConstant(QByteArray());
    }

    ui->constant_head_view->clean();
    ui->lbl_SelectedConstantName->clear();
    ui->lbl_SelectedName->clear();
}

void MachineConstantView::setReadOnly(bool readOnly)
{
    ui->constant_head_view->setReadOnly(readOnly);
    m_pEditView->setReadOnly(readOnly);
}

void MachineConstantView::ConstructFinished()
{
    m_Publisher.Publish("MachineConstant", EnumConverter::ConvertToString(CMD_MachineConstant::CMD_Actived_MC));
    m_Publisher.Publish("MachineConstant", EnumConverter::ConvertToString(CMD_MachineConstant::CMD_Actived_Info));
    m_Publisher.Publish("MachineConstant", EnumConverter::ConvertToString(CMD_MachineConstant::CMD_Names));
}

void MachineConstantView::slot_sendConstantInfo(S_ConstantInfo conInfo)
{
}

void MachineConstantView::setWidgets()
{
    m_pEditView = new McEditorView("McEditorView", this);
    m_pEditView->ItemInitialize();
    ui->stw_Constant->addWidget(m_pEditView);
    status = ViewStatus::Idle;
    setEditorStatus();
}


void MachineConstantView::setWidgetStyleSheet()
{
    ui->gpb_Constant->SetheaderFontSize(16);
    ui->gpb_Constant->SetHeaderText(Tr("Constant List"));

    ui->lbl_CurrentConstant->setText(Tr("Current Constant"));
    ui->lbl_SelectedName->setText(Tr("Selected Constant"));
    ui->lbl_Filter->setText(Tr("Filter"));

    ui->btn_ShowDetail_Current->setText(Tr("Show Detail"));

    QFont font = GlobalStyleSheet->Font();
    ui->bth_New->setFont(font);
    ui->bth_New->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->bth_New->SetVertivalStyle(font, QString(0xa44), 30, Tr("New"), 12, QFont::Bold);
    ui->bth_New->setStyleSheet(GlobalStyleSheet->Button_Border);
    ui->bth_New->SetColor(IconButton::Status::Normal);

    ui->btn_ConstantModify->setFont(font);
    ui->btn_ConstantModify->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_ConstantModify->SetVertivalStyle(font, QString(0xa51), 30, Tr("Modify"), 12, QFont::Bold);
    ui->btn_ConstantModify->setStyleSheet(GlobalStyleSheet->Button_Border);
    ui->btn_ConstantModify->SetColor(IconButton::Status::Disabled);


    ui->btn_EditCancel->setFont(font);
    ui->btn_EditCancel->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_EditCancel->SetVertivalStyle(font, QString(0xa46), 30, Tr("Cancel"), 12, QFont::Bold);
    ui->btn_EditCancel->setStyleSheet(GlobalStyleSheet->Button_Border);
    ui->btn_EditCancel->SetColor(IconButton::Status::Disabled);

    ui->btn_SaveConstant->setFont(font);
    ui->btn_SaveConstant->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_SaveConstant->SetVertivalStyle(font, QString(0xa50), 30, Tr("Save"), 12, QFont::Bold);
    ui->btn_SaveConstant->setStyleSheet(GlobalStyleSheet->Button_Border);
    ui->btn_SaveConstant->SetColor(IconButton::Status::Disabled);

    ui->btn_Execute->setFont(font);
    ui->btn_Execute->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_Execute->SetVertivalStyle(font, QString(0xa55), 30, Tr("Execute"), 12, QFont::Bold);
    ui->btn_Execute->setStyleSheet(GlobalStyleSheet->Button_Border);
    ui->btn_Execute->SetColor(IconButton::Status::Disabled);

    ui->btn_BackupConstant->setFont(font);
    ui->btn_BackupConstant->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_BackupConstant->SetVertivalStyle(font, QString(0xa54), 30, Tr("Backup"), 12, QFont::Bold);
    ui->btn_BackupConstant->setStyleSheet(GlobalStyleSheet->Button_Border);
    ui->btn_BackupConstant->SetColor(IconButton::Status::Disabled);

    ui->btn_DeleteConstant->setFont(font);
    ui->btn_DeleteConstant->SetFrontColor("#4C70FA", "#FFFFFF", "#FFFFFF", "#FFFFFF");
    ui->btn_DeleteConstant->SetVertivalStyle(font, QString(0xa53), 30, Tr("Delete"), 12, QFont::Bold);
    ui->btn_DeleteConstant->setStyleSheet(GlobalStyleSheet->Button_Border);
    ui->btn_DeleteConstant->SetColor(IconButton::Status::Disabled);

    ui->led_SearchValue->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);
    ui->led_SearchValue->SetIconDock(IconLineEdit::Right);
    ui->led_SearchValue->SetIconFont(GlobalStyleSheet->Font());
    ui->led_SearchValue->setTextMargins(0, 0, 35, 0);
    ui->led_SearchValue->SetIcon(QString(0xa024), 14);

    QFont fontt;

    fontt.setFamily("HarmonyOS Sans");
    ui->lbl_CurrentConstant->setStyleSheet(GlobalStyleSheet->Button_Border + GlobalStyleSheet->fontStyle_normal_14);
    ui->btn_ShowDetail_Current->setStyleSheet(GlobalStyleSheet->Button_Border + GlobalStyleSheet->fontStyle_bold_12);
    ui->lbl_SelectedName->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_Filter->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->led_CurrentConstant->setStyleSheet(GlobalStyleSheet->LineEdit_Dark + GlobalStyleSheet->fontStyle_normal_14);
    ui->led_SearchValue->setStyleSheet(GlobalStyleSheet->LineEdit_Dark + GlobalStyleSheet->fontStyle_qlineEdit_normal_12);
    ui->led_SearchValue->SetIconDock(IconLineEdit::Right);
    ui->led_SearchValue->SetIconFont(GlobalStyleSheet->Font());
    ui->led_SearchValue->setTextMargins(0, 0, 35, 0);
    ui->led_SearchValue->SetIcon(QString(0xa024), 14);
    ui->TBW_Constants->setStyleSheet(GlobalStyleSheet->tabStyle + GlobalStyleSheet->fontStyle_normal_12);
}

void MachineConstantView::setLanguageKeys()
{

}


void MachineConstantView::setConnections()
{
    connect(ui->TBW_Constants, &QTableView::clicked, this, [ = ](const QModelIndex & index)
    {
        ui->constant_head_view->setBtnEnable(false);
        m_selectedIndex = index.row();
        m_selectedConstantName = ui->TBW_Constants->model()->data(index, Qt::UserRole).value<QString>();

        SR_ConstantInfo constantInfo;

        constantInfo.constantName = m_selectedConstantName;
        m_constant.mcInfo = constantInfo;

        m_Publisher.Publish("MachineConstant",
                            EnumConverter::ConvertToString(CMD_MachineConstant::CMD_MC),
                            false, S_ConstantInfo(constantInfo).toRawJson());

        m_selectedConstantName = ui->TBW_Constants->model()->data(index, Qt::UserRole).value<QString>();
        ui->lbl_SelectedConstantName->setText(m_selectedConstantName.value);
    });

    //    QObject::connect(ui->constant_head_view, &ConstantHead::sig_sendConstantInfo,
    //                     this, &MachineConstantView::slot_sendConstantInfo);

    connect(ui->bth_New, &QPushButton::clicked, this, [ = ]
    {
        m_bIsModify = false;
        status = ViewStatus::Modifying;
        emit ViewStatusChanged(status);
        m_Publisher.Publish("MachineConstant",
                            EnumConverter::ConvertToString(CMD_MachineConstant::CMD_New),
                            false);
    });

    connect(ui->btn_SaveConstant, &QPushButton::clicked, this, [ = ]
    {
        QByteArray data;
        S_ConstantInfo constInfo = ui->constant_head_view->getContantInfo();
        ConstantBasicInformation infoDlg(constInfo, true, this);

        if(0 == infoDlg.exec())
        {
            return;
        }

        constInfo = infoDlg.getResult();

        m_pEditView->dumpJson(data);

        m_constant.mcInfo = constInfo;
        m_constant.mcContent.fromJson(data);
        S_MachineConstant constant;
        constant = m_constant;
        //        cleanViewer();

        QByteArray sendData = constant.mcInfo.toRawJson() + '#' + constant.mcContent.toRawJson();
        QString name = m_constant.mcInfo.constantName.value;
        QString nametest = ui->TBW_Constants->model()->data(ui->TBW_Constants->currentIndex(),
                Qt::UserRole).value<QString>();

        //非修改状态，不重名即可
        if(!m_bIsModify)
        {
            bool res = m_constantNames.values.contains(name);
            if (res)
            {
                MessageDialog dlg(MessageDialog::Error, this, Tr("E_ConstantName_Repeat_Create"));
                dlg.exec();
                return ;
            }
        }
        else
        {
            bool res = (name != m_selectedConstantName.value) && m_constantNames.values.contains(name);
            if (res)
            {
                MessageDialog dlg(MessageDialog::Error, this, Tr("E_ConstantName_Repeat_Modify"));
                dlg.exec();
                return ;
            }
            else
            {
                m_Publisher.Publish("MachineConstant",
                                    EnumConverter::ConvertToString(CMD_MachineConstant::CMD_Delete),
                                    false, S_ConstantInfo(m_keepConstantInfo).toRawJson());
            }
        }
        //        //修改状态
        //        if (m_bIsModify)
        //        {
        //            bool res = m_constantNames.values[m_selectedIndex] != m_constant.mcInfo.constantName.value && m_constantNames.values.contains(name);
        //            if (res)
        //            {
        //                MessageDialog dlg(MessageDialog::Error, this, Tr("E_ConstantName_CurrentName_Modify"));
        //                dlg.exec();
        //                return;
        //            }
        //            m_Publisher.Publish("MachineConstant",
        //                                EnumConverter::ConvertToString(CMD_MachineConstant::CMD_Delete),
        //                                false, S_ConstantInfo(m_keepConstantInfo).toRawJson());
        //        }

        m_Publisher.Publish("MachineConstant",
                            EnumConverter::ConvertToString(CMD_MachineConstant::CMD_Save),
                            false, sendData);

        status = ViewStatus::Idle;
        emit ViewStatusChanged(status);
        setEditorStatus();
    });

    connect(ui->btn_BackupConstant, &QPushButton::clicked, this, [ = ]
    {
        if (ui->TBW_Constants->currentIndex().isValid())
        {
            if (m_selectedConstantName.value.contains("_backup_"))
            {
                MessageDialog dlg(MessageDialog::Error, this, Tr("E_ConstantName_RepeatCopy"));
                dlg.exec();
                return ;
            }
            m_Publisher.Publish("MachineConstant",
                                EnumConverter::ConvertToString(CMD_MachineConstant::CMD_Backup),
                                false, S_ConstantInfo(m_constant.mcInfo).toRawJson());
            //            cleanViewer();
        }
    });

    connect(ui->btn_DeleteConstant, &QPushButton::clicked, this, [ = ]
    {
        if (ui->TBW_Constants->currentIndex().isValid())
        {
            if (m_currentConstant.constantName == m_selectedConstantName.value)
            {


                MessageDialog dlg(MessageDialog::Error, this, Tr("E_CurrentConstantName_Delete"));
                dlg.exec();
                return;
            }

            cleanViewer();
            S_ConstantInfo sendContantInfo(m_constant.mcInfo);
            m_Publisher.Publish("MachineConstant",
                                EnumConverter::ConvertToString(CMD_MachineConstant::CMD_Delete),
                                false, sendContantInfo.toRawJson());
        }
    });

    connect(ui->btn_Execute, &QPushButton::clicked, this, [ = ]
    {
        if (ui->TBW_Constants->currentIndex().isValid())
        {
            m_Publisher.Publish("MachineConstant",
                                EnumConverter::ConvertToString(CMD_MachineConstant::CMD_Execute),
                                false, S_ConstantInfo(m_constant.mcInfo).toRawJson());
        }

        status = ViewStatus::Idle;
        emit ViewStatusChanged(status);
        m_pConstantModel->resetModel(m_constantNames.values);
        setEditorStatus();
    });

    connect(ui->btn_ConstantModify, &QPushButton::clicked, this, [ = ]
    {
        if (ui->TBW_Constants->currentIndex().isValid())
        {
            m_bIsModify = true;
            m_keepConstantInfo = m_constant.mcInfo;
            m_constant.mcInfo.modifier.SetValue(user.userName);
            m_constant.mcInfo.modifiedTime.SetValue(Time()->TimeToString());
            ui->constant_head_view->setConstantInfo(S_ConstantInfo(m_constant.mcInfo));
            status = ViewStatus::Modifying;
            emit ViewStatusChanged(status);
            setEditorStatus();
        }
    });

    connect(ui->btn_EditCancel, &QPushButton::clicked, this, [ = ]
    {
        MessageDialog dlg(MessageDialog::Attention, this, Tr("E_RcpName_Cancle"));
        if(dlg.exec() == QDialog::Accepted)
        {
            m_constant = m_emptyConstant;
            cleanViewer();
        }
        else
        {
            return ;
        }
        status = ViewStatus::Idle;
        emit ViewStatusChanged(status);
        m_pConstantModel->resetModel(m_constantNames.values);
        setEditorStatus();
    });

    connect(ui->led_SearchValue, &QLineEdit::textChanged, this, [ = ](QString str)
    {
        for(int i = 0; i < ui->TBW_Constants->model()->rowCount(); i++)
        {
            ui->TBW_Constants->setRowHidden(i, true);

            QAbstractItemModel *model = ui->TBW_Constants->model();
            QModelIndex index;

            index = model->index(i, 1);

            if(model->data(index).toString().contains(str, Qt::CaseInsensitive))
            {
                ui->TBW_Constants->setRowHidden(i, false);
            }
        }
    });

    connect(ui->btn_ShowDetail_Current, &QPushButton::clicked, this, [ = ]
    {
        S_ConstantInfo constantInfo;
        setReadOnly(true);
        constantInfo.constantName = ui->led_CurrentConstant->text();
        m_Publisher.Publish("MachineConstant",
                            EnumConverter::ConvertToString(CMD_MachineConstant::CMD_MC),
                            false, constantInfo.toRawJson());
    });

    // MachineConstantSubscriber
    connect(MachineConstantSubscriber::getInstance(), &MachineConstantSubscriber::sendCurrentInfo,
            this, [ = ](const S_ConstantInfo & contantInfo)
    {
        m_currentConstant = contantInfo;
        ui->constant_head_view->setConstantInfo(contantInfo);
        ui->led_CurrentConstant->setText(contantInfo.constantName);
    });

    connect(MachineConstantSubscriber::getInstance(), &MachineConstantSubscriber::sendInfo,
            this, [ = ](const S_ConstantInfo & contantInfo)
    {
        m_keepConstantInfo = contantInfo;
        m_constant.mcInfo = contantInfo;
        ui->constant_head_view->setConstantInfo(contantInfo);
        ui->constant_head_view->setBtnEnable(true);
    });

    connect(MachineConstantSubscriber::getInstance(), &MachineConstantSubscriber::sendNew,
            this, [ = ](const S_ConstantInfo & contantInfo)
    {
        S_MachineConstant s_newConstant;
        SR_MachineConstant newConstant = s_newConstant;
        newConstant.mcInfo.constantName = contantInfo.constantName;
        newConstant.mcInfo.creator.SetValue(user.userName);
        newConstant.mcInfo.createdTime.SetValue(Time()->TimeToString());
        ui->constant_head_view->setConstantInfo(S_ConstantInfo(newConstant.mcInfo));
        m_pEditView->setConstant(newConstant.mcContent.toRawJson());
        m_pEditView->expandAll();
        setEditorStatus();
    });

    connect(MachineConstantSubscriber::getInstance(), &MachineConstantSubscriber::sendNames, this,
            [ = ](S_List_String constantNames)
    {
        m_constantNames = constantNames;
        m_pConstantModel->resetModel(constantNames.values);
        setEditorStatus();
    });

    connect(MachineConstantSubscriber::getInstance(), &MachineConstantSubscriber::sendContent, this,
            [ = ](const QByteArray & constant)
    {
        S_MCContent s_Content;
        s_Content.fromJson(constant);
        SR_MCContent sr_Content;
        sr_Content = s_Content;
        QByteArray msg = sr_Content.toRawJson();
        m_pEditView->setConstant(msg);
        m_pEditView->expandAll();
        setEditorStatus();
    });
}

void MachineConstantView::userModelInitialize()
{
    m_pConstantModel = new ConstantModel(this);
    m_pConstantModel->SetModel(m_constantNames.values);
    ui->TBW_Constants->setModel(m_pConstantModel);
    ui->TBW_Constants->setColumnWidth(0, 60);
}

void MachineConstantView::setEditorStatus()
{
    bool bTableSelected = ui->TBW_Constants->currentIndex().isValid();

    if (status == ViewStatus::Idle)
    {
        ui->bth_New->setEnabled(true);
        ui->btn_ConstantModify->setEnabled(bTableSelected);
        ui->btn_SaveConstant->setEnabled(false);
        ui->btn_EditCancel->setEnabled(false);
        ui->btn_BackupConstant->setEnabled(bTableSelected);
        ui->btn_Execute->setEnabled(bTableSelected);
        ui->btn_DeleteConstant->setEnabled(bTableSelected);
        ui->led_CurrentConstant->setEnabled(false);
        ui->led_SearchValue->setEnabled(true);
        ui->TBW_Constants->setEnabled(true);
        ui->btn_ShowDetail_Current->setEnabled(true);
        ui->constant_head_view->setReadOnly(true);
        m_pEditView->setReadOnly(true);
    }
    else
    {
        ui->bth_New->setEnabled(false);
        ui->btn_ConstantModify->setEnabled(false);
        ui->btn_SaveConstant->setEnabled(true);
        ui->btn_EditCancel->setEnabled(true);
        ui->btn_BackupConstant->setEnabled(false);
        ui->btn_Execute->setEnabled(false);
        ui->btn_DeleteConstant->setEnabled(false);
        ui->led_CurrentConstant->setEnabled(false);
        ui->led_SearchValue->setEnabled(false);
        ui->TBW_Constants->setEnabled(false);
        ui->btn_ShowDetail_Current->setEnabled(false);
        ui->constant_head_view->setReadOnly(false);
        m_pEditView->setReadOnly(false);
    }
}
