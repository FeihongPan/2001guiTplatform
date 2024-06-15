#include "alarmeditview.h"
#include "ui_alarmeditview.h"
#include "CustomerWidget/Button/effectbutton.h"
#include "Language/language.h"
#include "StyleSheet/stylesheet.h"
#include "CustomerWidget/Dialog/messagedialog.h"
#include "Alarms/Subscriber/alarmSubscriber.h"
#include "Alarms/Command/cmd_alarm.h"
#include "CustomerWidget/Delegate/checkboxdelegate.h"

AlarmEditView::AlarmEditView(const QString &name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::AlarmEditView)
{
    ui->setupUi(this);
    modelInitialize();
}

AlarmEditView::~AlarmEditView()
{
    delete ui;
}

Ui::AlarmEditView *AlarmEditView::GetUI()
{
    return ui;
}

void AlarmEditView::ConstructFinished()
{
    m_Publisher.Publish("Alarm", EnumConverter::ConvertToString(CMD_Alarm::CMD_AlarmsInfo));
}

void AlarmEditView::setWidgets()
{

}

void AlarmEditView::setWidgetStyleSheet()
{
    QGraphicsDropShadowEffect *effect_tbw_Alarms = new QGraphicsDropShadowEffect(this);
    effect_tbw_Alarms->setOffset(0, 0);
    effect_tbw_Alarms->setColor(QColor(0, 0, 0, 64));
    effect_tbw_Alarms->setBlurRadius(10);
    ui->tbw_AlarmEditor->setGraphicsEffect(effect_tbw_Alarms);
    ui->tbw_AlarmEditor->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->btn_CreateNew->setStyleSheet(GlobalStyleSheet->ButtonStyle_Back);
    ui->btn_Delete->setStyleSheet(GlobalStyleSheet->ButtonStyle_Back);
    ui->btn_Save->setStyleSheet(GlobalStyleSheet->ButtonStyle_Back);
    ui->btn_Abandon->setStyleSheet(GlobalStyleSheet->ButtonStyle_Back);
}

void AlarmEditView::setLanguageKeys()
{
    ui->lbl_Filter->setText(Tr("Filter"));
    ui->btn_CreateNew->setText(Tr("New"));
    ui->btn_Delete->setText(Tr("Delete"));
    ui->btn_Save->setText(Tr("Save"));
    ui->btn_Abandon->setText(Tr("Abandon"));

    QStringList lst_Header;
    lst_Header << Tr("Alarm Code") << Tr("Retry") << Tr("Skip") << Tr("Continue") << Tr("Reset") << Tr("Message") << Tr("Trouble Shooting");
    p_AlarmEditModel->SetHeader(lst_Header);
}

void AlarmEditView::setConnections()
{
    connect(AlarmSubscriber::getInstance(), &AlarmSubscriber::sig_WriteToFileResult, this, &AlarmEditView::on_WriteToFileResult);
    connect(AlarmSubscriber::getInstance(), &AlarmSubscriber::sig_SendAlarmsInfo, this, &AlarmEditView::on_UpdateView);
    connect(ui->led_SearchValue, &QLineEdit::textChanged, this, &AlarmEditView::on_Filter);
    connect(ui->btn_CreateNew, &QPushButton::clicked, this, &AlarmEditView::on_CreateNew);
    connect(ui->btn_Delete, &QPushButton::clicked, this, &AlarmEditView::on_Delete);
    connect(ui->btn_Abandon, &QPushButton::clicked, this, &AlarmEditView::on_Abandon);
    connect(ui->btn_Save, &QPushButton::clicked, this, &AlarmEditView::on_Save);
}

void AlarmEditView::modelInitialize()
{
    p_AlarmEditModel = new AlarmEditModel(this);
    QStringList lst_Header;
    lst_Header << Tr("Alarm Code") << Tr("Retry") << Tr("Skip") << Tr("Continue") << Tr("Reset") << Tr("Message") << Tr("Trouble Shooting");
    p_AlarmEditModel->SetModel(&m_AlarmsInfo);
    p_AlarmEditModel->SetHeader(lst_Header);
    ui->tbw_AlarmEditor->setModel(p_AlarmEditModel);
    ui->tbw_AlarmEditor->setColumnWidth(0, 150);
    ui->tbw_AlarmEditor->setColumnWidth(1, 100);
    ui->tbw_AlarmEditor->setColumnWidth(2, 100);
    ui->tbw_AlarmEditor->setColumnWidth(3, 100);
    ui->tbw_AlarmEditor->setColumnWidth(4, 100);
    ui->tbw_AlarmEditor->setColumnWidth(5, 500);

    ui->tbw_AlarmEditor->setItemDelegateForColumn( 1, CheckBoxDelegate::getInstance());
    ui->tbw_AlarmEditor->setItemDelegateForColumn( 2, CheckBoxDelegate::getInstance());
    ui->tbw_AlarmEditor->setItemDelegateForColumn( 3, CheckBoxDelegate::getInstance());
    ui->tbw_AlarmEditor->setItemDelegateForColumn( 4, CheckBoxDelegate::getInstance());
}

void AlarmEditView::on_CreateNew()
{
    if(this->status == ViewStatus::Idle)
    {
        m_AlarmsInfoBack = m_AlarmsInfo;
    }
    ui->led_SearchValue->setText(QString());
    p_AlarmEditModel->AddModelData(p_AlarmEditModel->rowCount(), S_AlarmData());
    ui->tbw_AlarmEditor->selectRow(p_AlarmEditModel->rowCount() - 1);
    ui->tbw_AlarmEditor->scrollToBottom();
    this->status = ViewStatus::Modifying;
    emit ViewStatusChanged(ViewStatus::Modifying);
}

void AlarmEditView::on_Delete()
{
    MessageDialog *dlg = new MessageDialog(MessageDialog::Attention, this, Tr("A_Alarm_Delete"));
    dlg->setObjectName("dlgDelete");
    if (dlg->exec() == QDialog::Accepted)
    {
        if(ui->tbw_AlarmEditor->currentIndex().row() < 0 || ui->tbw_AlarmEditor->currentIndex().row() >= p_AlarmEditModel->rowCount())
        {
            MessageDialog dlg(MessageDialog::Error, this, Tr("A_Alarm_SelectFirst"));
            if (dlg.exec() == QDialog::Accepted)
            {
                return;
            }
        }
        if(this->status == ViewStatus::Idle)
        {
            m_AlarmsInfoBack = m_AlarmsInfo;
        }
        p_AlarmEditModel->DeleteModelData(ui->tbw_AlarmEditor->currentIndex().row());
        this->status = ViewStatus::Modifying;
        emit ViewStatusChanged(ViewStatus::Modifying);
    }
    delete dlg;
}

void AlarmEditView::on_Abandon()
{
    MessageDialog *dlg = new MessageDialog(MessageDialog::Attention, this, Tr("A_Alarm_Abandon"));
    dlg->setObjectName("dlgAbandon");
    if (dlg->exec() == QDialog::Accepted)
    {
        m_AlarmsInfo = m_AlarmsInfoBack;
        p_AlarmEditModel->ResetModel(&m_AlarmsInfo);
        ui->led_SearchValue->setText(QString());
        this->status = ViewStatus::Idle;
        emit ViewStatusChanged(ViewStatus::Idle);
    }
    delete dlg;
}

void AlarmEditView::on_Save()
{
    m_Publisher.Publish("Alarm", EnumConverter::ConvertToString(CMD_Alarm::CMD_SaveAlarmsInfo), false, m_AlarmsInfo.toRawJson());
    this->status = ViewStatus::Idle;
    emit ViewStatusChanged(ViewStatus::Idle);
}

void AlarmEditView::on_WriteToFileResult(const bool &bResult)
{
    if(bResult)
    {
        MessageDialog dlg(MessageDialog::Success, this, Tr("A_Alarm_WriteOK"));
        dlg.setObjectName("Alarm_Success");
        dlg.exec();
    }
    else
    {
        MessageDialog dlg(MessageDialog::Error, this, Tr("A_Alarm_WriteFail"));
        dlg.setObjectName("Alarm_Error");
        dlg.exec();
    }
}

void AlarmEditView::on_UpdateView(const S_AlarmsInfo &alarmsInfo, const bool &result)
{
    Q_UNUSED(result);
    this->m_AlarmsInfo = alarmsInfo;
    p_AlarmEditModel->ResetModel(&this->m_AlarmsInfo);
}

void AlarmEditView::on_Filter(const QString &strText)
{
    for(int i = 0; i < ui->tbw_AlarmEditor->model()->rowCount(); i++)
    {
        ui->tbw_AlarmEditor->setRowHidden(i, true);
        QAbstractItemModel *model = ui->tbw_AlarmEditor->model();
        QModelIndex index;
        index = model->index(i, 0);
        if(model->data(index).toString().contains(strText, Qt::CaseInsensitive))
        {
            ui->tbw_AlarmEditor->setRowHidden(i, false);
        }
    }
}
