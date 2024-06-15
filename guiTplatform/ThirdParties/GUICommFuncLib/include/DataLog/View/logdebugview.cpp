#include "logdebugview.h"
#include "ui_logdebugview.h"
#include "DataLog/Subscriber/logsubscriber.h"
#include "BasicValue/others.h"
#include <QCalendarWidget>

LogDebugView::LogDebugView(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::LogDebugView)
{
    ui->setupUi(this);
}

LogDebugView::~LogDebugView()
{
    delete ui;
}

void LogDebugView::setConnections()
{
    connect(LogSubscriber::getInstance(), &LogSubscriber::Sig_LogInfo, this, &LogDebugView::on_UpdateView);
    connect(ui->btn_Search, &QPushButton::clicked, this, &LogDebugView::on_Search);
    connect(ui->dtEditDateStart, &QDateTimeEdit::dateTimeChanged, this, &LogDebugView::on_DateStart);
    connect(ui->dtEditDateEnd, &QDateTimeEdit::dateTimeChanged, this, &LogDebugView::on_DateEnd);
//    connect(vscrollBar, &QScrollBar::valueChanged, this, &LogDebugView::on_ScrollValueChanged);
    connect(ui->dtEditTimeStart, &QDateTimeEdit::timeChanged, this, &LogDebugView::on_TimeChanged);
    connect(ui->dtEditTimeEnd, &QDateTimeEdit::timeChanged, this, &LogDebugView::on_TimeChanged);
    connect(ui->led_Filter, &IconLineEdit::textChanged, this, &LogDebugView::on_Filter);
}

void LogDebugView::on_UpdateView(S_LogInfo_Debugs &data, bool result)
{
    m_debugInfos.dicMessage = data.dicMessage;
    //    S_LogInfo_Debugs debugs;
    //    getShowData(data , debugs,  0);
    //    vscrollBar->setPageStep(23);
    //    m_debugInfos.dicMessage = debugs.dicMessage;
    m_debugModel->resetModel(&m_debugInfos);
    ui->tbw_LogDebug->scrollToTop();
}


void LogDebugView::on_Filter(const QString &strText)
{
    int rowCount = ui->tbw_LogDebug->model()->rowCount();
    for(int i = 0; i < rowCount; i++)
    {
        ui->tbw_LogDebug->setRowHidden(i, true);
        QAbstractItemModel *model = ui->tbw_LogDebug->model();
        QModelIndex index;
        index = model->index(i, 1);
        if(model->data(index).toString().contains(strText, Qt::CaseInsensitive))
        {
            ui->tbw_LogDebug->setRowHidden(i, false);
        }
    }
}


void LogDebugView::on_Search()
{
    S_TimeSlot times;
    times.dateTimeStart =  ui->dtEditDateStart->dateTime().toString("yyyy-MM-dd ") + ui->dtEditTimeStart->time().toString("H");
    times.dateTimeEnd = ui->dtEditDateEnd->dateTime().toString("yyyy-MM-dd ") + ui->dtEditTimeEnd->time().toString("H");
    CMD_Log::Command cmd = CMD_Log::CMD_LogDebug;
    ui->led_Filter->clear();
    if(ui->cmb_Mode->currentIndex() == 1)
    {
        cmd = CMD_Log::CMD_LogException;
    }
    m_Publisher.Publish("DataLog", EnumConverter::ConvertToString(cmd), false, times.toRawJson());
}

void LogDebugView::on_DateStart(QDateTime date)
{
    int timeStart = date.toTime_t();
    int timeEnd = ui->dtEditDateEnd->dateTime().toTime_t();
    if(timeEnd < timeStart)
    {
        ui->dtEditDateEnd->setDateTime(date);
    }

    if(timeEnd - timeStart >= 3600 * 24*13)
    {
        ui->dtEditDateEnd->setDateTime(date.addDays(13));
    }
}

void LogDebugView::on_DateEnd(QDateTime date)
{
    int timeStart = ui->dtEditDateStart->dateTime().toTime_t();
    int timeEnd = date.toTime_t();
    if(timeEnd < timeStart)
    {
        ui->dtEditDateStart->setDateTime(date);
    }

    if(timeEnd - timeStart >= 3600 * 24*13)
    {
        ui->dtEditDateStart->setDateTime(date.addDays(-13));
    }
}

void LogDebugView::on_ScrollValueChanged(int value)
{


}

void LogDebugView::on_TimeChanged(QTime time)
{
    QDateTimeEdit *dtEdit = static_cast<QDateTimeEdit *>(sender());
    if(dtEdit)
    {
        dtEdit->setCurrentSection(QDateTimeEdit::HourSection);
        QTime timeNew(time.hour(), 0);
        dtEdit->setTime(timeNew);
    }
}

void LogDebugView::setWidgets()
{
    QStringList items;
    items << "Debug" << "Exception";
    ui->cmb_Mode->addItems(items);

    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    ui->dtEditDateStart->setDateTime(QDateTime::fromString(date, "yyyy-MM-dd"));
    ui->dtEditDateEnd->setDateTime(QDateTime::fromString(date, "yyyy-MM-dd"));

    m_debugModel = new LogDebugModel(this);
    m_debugModel->setModel(&m_debugInfos);
    initTable(ui->tbw_LogDebug);
    ui->tbw_LogDebug->setModel(m_debugModel);
    ui->tbw_LogDebug->setColumnWidth(0, 300);

    //    vscrollBar = new QScrollBar(Qt::Vertical, ui->tbw_LogDebug);
    ui->dtEditDateStart->calendarWidget()->setFirstDayOfWeek(Qt::Monday);
    ui->dtEditDateEnd->calendarWidget()->setFirstDayOfWeek(Qt::Monday);

    QGraphicsDropShadowEffect *effect_tbw = new QGraphicsDropShadowEffect(this);
    effect_tbw->setOffset(0, 0);
    effect_tbw->setColor(QColor(0, 0, 0, 64));
    effect_tbw->setBlurRadius(10);
    ui->tbw_LogDebug->setGraphicsEffect(effect_tbw);
}

void LogDebugView::setWidgetStyleSheet()
{
    setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->btn_Search->setStyleSheet(GlobalStyleSheet->Button_Border + GlobalStyleSheet->fontStyle_normal_12);
    ui->dtEditDateStart->setStyleSheet(GlobalStyleSheet->CalendarWidgetStyle);
    ui->dtEditDateEnd->setStyleSheet(GlobalStyleSheet->CalendarWidgetStyle);
}

void LogDebugView::setLanguageKeys()
{

}

void LogDebugView::initTable(QTableView *table)
{
    if(table)
    {
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->horizontalHeader()->setStretchLastSection(true);
        table->verticalHeader()->setVisible(false);
        table->setSelectionMode(QAbstractItemView::SingleSelection);
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        table->setStyleSheet(GlobalStyleSheet->tableStyle);
    }
}

void LogDebugView::getShowData(S_LogInfo_Debugs &data, S_LogInfo_Debugs &out, int scrIndex)
{
    QMap<QString, QString> &dicMessage = data.dicMessage;
    for(int i = 0; i < 24; i++)
    {
        if(dicMessage.keys().count() > i + scrIndex)
        {
            QString key = dicMessage.keys().at(i + scrIndex);
            out.dicMessage.insert(key, dicMessage.value(key));
        }
    }
}
