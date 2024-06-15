#include "reportalarmview.h"
#include "ui_reportalarmview.h"
#include "Language/language.h"
#include "StyleSheet/stylesheet.h"
#include "Alarms/Subscriber/alarmSubscriber.h"
#include "Alarms/Command/cmd_alarm.h"
#include "SGT/Command/cmd_sgtctrl.h"
#include "TimeSynchronization/Manage/timesync.h"

ReportAlarmView::ReportAlarmView(const QString &name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::ReportAlarmView)
{
    ui->setupUi(this);
    modelInitialize();
    refreshViewInfo();
}

ReportAlarmView::~ReportAlarmView()
{
    delete ui;
}

Ui::ReportAlarmView *ReportAlarmView::GetUI()
{
    return ui;
}

void ReportAlarmView::ReleaseAlarm(const QString &strAlarmCode, const int &nMethod)
{
    int count = m_ReportedAlarms.lst_ReportedAlarms.count();
    for(int i = 0; i < count; i++)
    {
        if(m_ReportedAlarms.lst_ReportedAlarms[i].alarmData.alarmCode == strAlarmCode)
        {
            p_SelectedAlarm = &m_ReportedAlarms.lst_ReportedAlarms[i];
            p_SelectedAlarm->handlingMethod = (S_AlarmData::ErrorHandlingMethod)nMethod;
            p_SelectedAlarm->releaseTime = Time()->TimeToString();
            m_Publisher.Publish("Alarm", EnumConverter::ConvertToString(CMD_Alarm::CMD_AlarmHandle), false, p_SelectedAlarm->toRawJson());
        }
    }
}

void ReportAlarmView::on_AlarmReport(const S_ReportedAlarms &alarms)
{
    this->m_Mutex.lock();
    bool dataChanged = false;
    QStringList lst_AlarmCodes;
    QStringList lst_AlarmCodesNew;
    for (int i = 0; i < m_ReportedAlarms.lst_ReportedAlarms.count(); i++)
    {
        lst_AlarmCodes.append(m_ReportedAlarms.lst_ReportedAlarms[i].alarmData.alarmCode);
    }

    for (int i = 0; i < alarms.lst_ReportedAlarms.count(); i++)
    {
        lst_AlarmCodesNew.append(alarms.lst_ReportedAlarms[i].alarmData.alarmCode);
    }

    for (int i = 0; i < lst_AlarmCodesNew.count(); i++)
    {
        if(!lst_AlarmCodes.contains(lst_AlarmCodesNew[i]))
        {
            lst_AlarmCodes.append(alarms.lst_ReportedAlarms[i].alarmData.alarmCode);
            m_ReportedAlarms.lst_ReportedAlarms.append(alarms.lst_ReportedAlarms[i]);
            dataChanged = true;
        }
    }

    for (int i = 0; i < lst_AlarmCodes.count(); i++)
    {
        if(!lst_AlarmCodesNew.contains(lst_AlarmCodes[i]))
        {
            lst_AlarmCodes.removeOne(lst_AlarmCodes[i]);
            m_ReportedAlarms.lst_ReportedAlarms.removeAt(i);
            dataChanged = true;
        }
    }

    for(int i = 0; i < m_ReportedAlarms.lst_ReportedAlarms.count(); i++)
    {
        for(int j = 0; j < alarms.lst_ReportedAlarms.count(); j++)
        {
            if(m_ReportedAlarms.lst_ReportedAlarms[i] == alarms.lst_ReportedAlarms[j] &&
                    m_ReportedAlarms.lst_ReportedAlarms[i].reportTime != alarms.lst_ReportedAlarms[j].reportTime)
            {
                m_ReportedAlarms.lst_ReportedAlarms[i] = alarms.lst_ReportedAlarms[j];
                dataChanged = true;
            }
        }
    }

    if(dataChanged)
    {
        int nRow = ui->tbw_Alarms->currentIndex().row();
        p_ReportedAlarmsModel->ResetModel(&m_ReportedAlarms);
        if(nRow >= m_ReportedAlarms.lst_ReportedAlarms.count())
        {
            nRow = m_ReportedAlarms.lst_ReportedAlarms.count() - 1;
        }
        ui->tbw_Alarms->selectRow(nRow);
        p_SelectedAlarm = ui->tbw_Alarms->model()->data(ui->tbw_Alarms->currentIndex(), Qt::UserRole).value<S_ReportedAlarm *>();
        refreshViewInfo();
    }
    this->m_Mutex.unlock();
}

void ReportAlarmView::on_CellClicked(const QModelIndex &index)
{
    this->m_Mutex.lock();
    p_SelectedAlarm = ui->tbw_Alarms->model()->data(index, Qt::UserRole).value<S_ReportedAlarm *>();
    refreshViewInfo();
    this->m_Mutex.unlock();
}

void ReportAlarmView::setWidgets()
{

}

void ReportAlarmView::setWidgetStyleSheet()
{
    QGraphicsDropShadowEffect *effect_tbw_Alarms = new QGraphicsDropShadowEffect();
    effect_tbw_Alarms->setOffset(0, 0);
    effect_tbw_Alarms->setColor(QColor(0, 0, 0, 64));
    effect_tbw_Alarms->setBlurRadius(10);
    ui->tbw_Alarms->setGraphicsEffect(effect_tbw_Alarms);
    ui->tbw_Alarms->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->btn_Reset->setStyleSheet(GlobalStyleSheet->ButtonStyle_Back);
    ui->btn_Skip->setStyleSheet(GlobalStyleSheet->ButtonStyle_Back);
    ui->btn_Retry->setStyleSheet(GlobalStyleSheet->ButtonStyle_Back);
    ui->btn_Continue->setStyleSheet(GlobalStyleSheet->ButtonStyle_Back);
    ui->btn_BuzzerOff->setStyleSheet(GlobalStyleSheet->ButtonStyle_Back);

    ui->btn_Reset->SetEffectStatus(true);
    ui->btn_Skip->SetEffectStatus(true);
    ui->btn_Retry->SetEffectStatus(true);
    ui->btn_Continue->SetEffectStatus(true);
    ui->btn_BuzzerOff->SetEffectStatus(true);
}

void ReportAlarmView::setLanguageKeys()
{
    ui->btn_Reset->setText(Tr("Reset"));
    ui->btn_Skip->setText(Tr("Skip"));
    ui->btn_Retry->setText(Tr("Retry"));
    ui->btn_Continue->setText(Tr("Continue"));
    ui->btn_BuzzerOff->setText(Tr("Buzzer Off"));
    ui->lbl_AlarmhandleTitle->setText(Tr("Trouble Shooting"));

    QStringList lst_Header;
    lst_Header << Tr("AlarmCode") << Tr("Report Time") << Tr("Message");
    p_ReportedAlarmsModel->SetHeader(lst_Header);
}

void ReportAlarmView::setConnections()
{
    connect(AlarmSubscriber::getInstance(), &AlarmSubscriber::sig_AlarmReport, this, &ReportAlarmView::on_AlarmReport);

    connect(ui->tbw_Alarms, &QTableView::clicked, this, &ReportAlarmView::on_CellClicked);

    connect(ui->btn_Reset, &QPushButton::clicked, this, [ = ]
    {
        sendHandleCommand(S_AlarmData::Reset);
    });

    connect(ui->btn_Retry, &QPushButton::clicked, this, [ = ]
    {
        sendHandleCommand(S_AlarmData::Retry);
    });

    connect(ui->btn_Continue, &QPushButton::clicked, this, [ = ]
    {
        sendHandleCommand(S_AlarmData::Continue);
    });

    connect(ui->btn_Skip, &QPushButton::clicked, this, [ = ]
    {
        sendHandleCommand(S_AlarmData::Skip);
    });

    connect(ui->btn_BuzzerOff, &QPushButton::clicked, this, [ = ]
    {
        m_Publisher.Publish("SGTCtrl", EnumConverter::ConvertToString(CMD_SGTCtrl::CMD_BuzzerOff));
    });
}

void ReportAlarmView::modelInitialize()
{
    QStringList lst_Header;
    lst_Header << Tr("AlarmCode") << Tr("Report Time") << Tr("Message");
    p_ReportedAlarmsModel = new ReportedAlarmsModel(this);
    p_ReportedAlarmsModel->SetModel(&m_ReportedAlarms);
    p_ReportedAlarmsModel->SetHeader(lst_Header);
    ui->tbw_Alarms->setModel(p_ReportedAlarmsModel);
    ui->tbw_Alarms->setColumnWidth(0, 200);
    ui->tbw_Alarms->setColumnWidth(1, 200);
}

void ReportAlarmView::refreshViewInfo()
{
    if (p_SelectedAlarm != nullptr)
    {
        ui->btn_Reset->setEnabled(p_SelectedAlarm->alarmData.dic_Methodvalidity[S_AlarmData::Reset]);
        ui->btn_Continue->setEnabled(p_SelectedAlarm->alarmData.dic_Methodvalidity[S_AlarmData::Continue]);
        ui->btn_Retry->setEnabled(p_SelectedAlarm->alarmData.dic_Methodvalidity[S_AlarmData::Retry]);
        ui->btn_Skip->setEnabled(p_SelectedAlarm->alarmData.dic_Methodvalidity[S_AlarmData::Skip]);
        ui->ted_HandleMethod->setText(p_SelectedAlarm->alarmData.brief);
    }
    else
    {
        ui->btn_Reset->setEnabled(false);
        ui->btn_Continue->setEnabled(false);
        ui->btn_Retry->setEnabled(false);
        ui->btn_Skip->setEnabled(false);
        ui->ted_HandleMethod->setText(QString());
    }

    if(m_ReportedAlarms.lst_ReportedAlarms.count() == 0)
    {
        status = ViewStatus::Idle;
        emit ViewStatusChanged(ViewStatus::Idle);
    }
    else
    {
        status = ViewStatus::Alarm;
        emit ViewStatusChanged(ViewStatus::Alarm);
    }
}

void ReportAlarmView::alarmTableHandled()
{
    p_SelectedAlarm = nullptr;
    ui->tbw_Alarms->selectRow(-1);
    refreshViewInfo();
}

void ReportAlarmView::sendHandleCommand(const S_AlarmData::ErrorHandlingMethod &method)
{
    m_Mutex.lock();
    p_SelectedAlarm->handlingMethod = method;
    p_SelectedAlarm->releaseTime = Time()->TimeToString();
    m_Publisher.Publish("Alarm", EnumConverter::ConvertToString(CMD_Alarm::CMD_AlarmHandle), false, p_SelectedAlarm->toRawJson());
    alarmTableHandled();
    m_Mutex.unlock();
}
