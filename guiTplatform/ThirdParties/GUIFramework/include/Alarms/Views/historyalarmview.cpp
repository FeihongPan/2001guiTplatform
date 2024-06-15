#include "historyalarmview.h"
#include "ui_historyalarmview.h"

#include "Alarms/Command/cmd_alarm.h"
#include "BasicValue/others.h"
#include "Alarms/Subscriber/alarmSubscriber.h"

const int MaxDays_History = 30;   ///最大查询相差天数

HistoryAlarmView::HistoryAlarmView(const QString &strName, QWidget *parent) :
    AuthorityWidget(strName, parent),
    ui(new Ui::HistoryAlarmView)
{
    ui->setupUi(this);
}

HistoryAlarmView::~HistoryAlarmView()
{
    delete ui;
}

void HistoryAlarmView::on_UpdateView(const S_ReportedAlarms &alarms)
{
    m_ReportedAlarms = alarms;
    p_HistoryModel->ResetModel(&m_ReportedAlarms);
}

void HistoryAlarmView::setWidgets()
{
    p_HistoryModel = new HistoryAlarmsModel(this);
    p_HistoryModel->SetModel(&m_ReportedAlarms);

    QStringList lst_Header;
    lst_Header << Tr("AlarmCode") << Tr("Alarm Time") << Tr("Message") << Tr("Brief")
               << Tr("HandlingMethod") << Tr("ReleaseUser") << Tr("ReleaseTime") << Tr("AddtionalNotes");
    p_HistoryModel->SetHeader(lst_Header);

    initTable(ui->tbw_History);
    ui->tbw_History->setModel(p_HistoryModel);
    ui->tbw_History->setColumnWidth(0, 200);
    ui->tbw_History->setColumnWidth(1, 200);
    ui->tbw_History->setColumnWidth(2, 300);
    ui->tbw_History->setColumnWidth(3, 300);
    ui->tbw_History->setColumnWidth(4, 200);
    ui->tbw_History->setColumnWidth(5, 200);
    ui->tbw_History->setColumnWidth(6, 200);

    ui->de_Start->setDate(QDate::currentDate());
    ui->de_End->setDate(QDate::currentDate());
    ui->led_Filter->SetIconDock(IconLineEdit::Right);
    ui->led_Filter->SetIconFont(GlobalStyleSheet->Font());
    ui->led_Filter->setTextMargins(0, 0, 35, 0);
    ui->led_Filter->SetIcon(QString(0xa024), 14);

    QGraphicsDropShadowEffect *effect_tbw = new QGraphicsDropShadowEffect(this);
    effect_tbw->setOffset(0, 0);
    effect_tbw->setColor(QColor(0, 0, 0, 64));
    effect_tbw->setBlurRadius(10);
    ui->tbw_History->setGraphicsEffect(effect_tbw);
}

void HistoryAlarmView::setWidgetStyleSheet()
{
    ui->btn_Search->setStyleSheet(GlobalStyleSheet->Button_Border + GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_Date->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_Filter->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_to->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->tbw_History->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->de_Start->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12 + GlobalStyleSheet->CalendarWidgetStyle);
    ui->de_End->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12 + GlobalStyleSheet->CalendarWidgetStyle);
}

void HistoryAlarmView::setLanguageKeys()
{
    QStringList lst_Header;
    lst_Header << Tr("AlarmCode") << Tr("Alarm Time") << Tr("Message") << Tr("Brief")
               << Tr("HandlingMethod") << Tr("ReleaseUser") << Tr("ReleaseTime") << Tr("AddtionalNotes");
    p_HistoryModel->SetHeader(lst_Header);

    ui->lbl_Filter->setText(Tr("Filter"));
    ui->lbl_Date->setText(Tr("Date"));
    ui->lbl_to->setText(Tr("to"));
    ui->btn_Search->setText(Tr("Search"));
}

void HistoryAlarmView::setConnections()
{
    connect(AlarmSubscriber::getInstance(), &AlarmSubscriber::sig_HistoryAlarms, this, &HistoryAlarmView::on_UpdateView);
    connect(ui->btn_Search, &QPushButton::clicked, this, &HistoryAlarmView::on_Search);
    connect(ui->de_Start, &QDateEdit::dateChanged, this, &HistoryAlarmView::on_DateStart);
    connect(ui->de_End, &QDateEdit::dateChanged, this, &HistoryAlarmView::on_DateEnd);
    connect(ui->led_Filter, &IconLineEdit::textChanged, this, &HistoryAlarmView::on_Filter);
}

void HistoryAlarmView::on_Search()
{
    S_TimeSlot times;
    times.dateTimeStart = ui->de_Start->date().toString("yyyy-MM-dd");
    times.dateTimeEnd = ui->de_End->date().toString("yyyy-MM-dd");
    ui->led_Filter->clear();
    //发送日期
    m_Publisher.Publish("Alarm", EnumConverter::ConvertToString(CMD_Alarm::CMD_AlarmsHistory), false, times.toRawJson());
}

void HistoryAlarmView::on_DateStart(const QDate &date)
{
    QDate dateStart = ui->de_Start->date();
    QDate dateEnd = ui->de_End->date();
    int difference = dateStart.daysTo(dateEnd);
    if(difference < 0)
    {
        ui->de_End->setDate(ui->de_Start->date());
    }
    if(difference > MaxDays_History)
    {
        ui->de_End->setDate(ui->de_Start->date().addDays(MaxDays_History));
    }
}

void HistoryAlarmView::on_DateEnd(const QDate &date)
{
    QDate dateStart = ui->de_Start->date();
    QDate dateEnd = ui->de_End->date();
    int difference = dateStart.daysTo(dateEnd);
    if(difference < 0)
    {
        ui->de_Start->setDate(ui->de_End->date());
    }
    if(difference > MaxDays_History)
    {
        ui->de_Start->setDate(ui->de_End->date().addDays(-MaxDays_History));
    }
}

void HistoryAlarmView::on_Filter(const QString &strText)
{
    int rowCount = ui->tbw_History->model()->rowCount();
    for(int i = 0; i < rowCount; i++)
    {
        ui->tbw_History->setRowHidden(i, true);
        QAbstractItemModel *model = ui->tbw_History->model();
        QModelIndex index;
        index = model->index(i, 0);
        if(model->data(index).toString().contains(strText, Qt::CaseInsensitive))
        {
            ui->tbw_History->setRowHidden(i, false);
        }
    }
}

void HistoryAlarmView::initTable(QTableView *pTable)
{
    if(pTable)
    {
        pTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        pTable->horizontalHeader()->setStretchLastSection(true);
        pTable->verticalHeader()->setVisible(false);
        pTable->setSelectionMode(QAbstractItemView::SingleSelection);
        pTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        pTable->setStyleSheet(GlobalStyleSheet->tableStyle);
    }
}
