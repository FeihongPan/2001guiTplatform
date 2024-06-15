#include "logprocessview.h"
#include "ui_logprocessview.h"
#include "BasicValue/others.h"
#include "DataLog/Subscriber/logsubscriber.h"

LogProcessView::LogProcessView(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::LogProcessView)
{
    ui->setupUi(this);
}


LogProcessView::~LogProcessView()
{
    delete ui;
}

RbTableHeaderView *LogProcessView::getHeader()
{
    return m_pHeader;
}


void LogProcessView::updateHeader(const S_LogHeader_Process &headers)
{
    if(m_pHeader == nullptr)
    {
        int count_col = 1;
        for (auto &key : headers.dic_Header.keys())
        {
            S_List_String lst_header = headers.dic_Header.value(key);
            count_col = count_col + lst_header.values.size();
        }
        initTable(ui->tbw_LogProcess);

        m_pHeader = new RbTableHeaderView(Qt::Horizontal, 2, count_col, ui->tbw_LogProcess);
        QAbstractItemModel *pHeaderModel = m_pHeader->model();

        m_pHeader->setSpan(0, 0, 2, 1);
        m_pHeader->setSectionsClickable(false);
        m_pHeader->setMinimumHeight(2 * 30);
        m_pHeader->setRowHeight(0, 30);
        m_pHeader->setRowHeight(1, 30);
        pHeaderModel->setData(pHeaderModel->index(0, 0), QString("DateTime"), Qt::DisplayRole);

        m_lst_Header.clear();
        int indexModule = 1;
        int indexHeader = 1;

        int width0 = ui->tbw_LogProcess->width() / count_col - 70;
        int width = (ui->tbw_LogProcess->width() - width0) / (count_col - 3);

        for (auto &key : m_headerModuleOrder)
        {
            if(!headers.dic_Header.keys().contains(key))
            {
                continue;
            }

            S_List_String lst_header = headers.dic_Header.value(key);
            m_pHeader->setSpan(0, indexModule, 1, lst_header.values.size());
            pHeaderModel->setData(pHeaderModel->index(0, indexModule), key, Qt::DisplayRole);
            m_pHeader->setCellBackgroundColor(pHeaderModel->index(0, indexModule), QColor(239, 244, 255));
            for (auto &value : lst_header.values)
            {
                m_pHeader->setSpan(1, indexHeader, 1, 1);
                pHeaderModel->setData(pHeaderModel->index(1, indexHeader), value, Qt::DisplayRole);
                m_pHeader->setCellBackgroundColor(pHeaderModel->index(1, indexHeader), QColor(239, 244, 255));
                m_pHeader->setColumnWidth(indexHeader, width);
                m_lst_Header.append(value);
                indexHeader++;
            }
            indexModule = indexModule + lst_header.values.size();
        }
        m_pHeader->setColumnWidth(0, width0);
        m_pHeader->setCellBackgroundColor(pHeaderModel->index(0, 0), QColor(239, 244, 255));
    }
    else
    {
        //更新隐藏显示表头
        QStringList lstHeader;
        for (auto &key : headers.dic_Header.keys())
        {
            S_List_String lst_header = headers.dic_Header.value(key);
            for (auto &value : lst_header.values)
            {
                lstHeader.append(value);
            }
        }
        for (int i = 0; i < m_lst_Header.size(); i++)
        {
            bool isHidden = true;
            if(lstHeader.contains(m_lst_Header.at(i)))
            {
                isHidden = false;
            }
            ui->tbw_LogProcess->setColumnHidden(i, isHidden);
        }
    }
    ui->tbw_LogProcess->setHorizontalHeader(m_pHeader);
}

#if 0
void LogProcessView::on_UpdateHeader(ProcListBasicInfo &info, bool result)
{
    QMap<int, QString> hashHeader;
    hashHeader.insert(7, "InitialProc");
    hashHeader.insert(8, "MonitorProc");
    hashHeader.insert(9, "AutoRunProc");

    QStringList lst = info.dic_ProcInfo.keys();
    qDebug() << senderSignalIndex() << lst;

    if(hashHeader.contains(senderSignalIndex()) &&
            !m_headerModuleOrder.contains(hashHeader[senderSignalIndex()]))
    {
        m_headerModuleOrder.append(hashHeader[senderSignalIndex()]);
        m_headers.dic_Header.insert(hashHeader[senderSignalIndex()], lst);
    }

    if(m_headerModuleOrder.size() == hashHeader.keys().size())
    {
        QStringList lst_Header;
        for (auto list : m_headers.dic_Header)
        {
            lst_Header.append(list.values);
        }

        if(nullptr == p_model)
        {
            p_model = new LogProcessModel(this);
            m_ProcessInfos.lst_Header = lst_Header;
            p_model->setModel(&m_ProcessInfos);
            ui->tbw_LogProcess->setModel(p_model);
        }
        updateHeader(m_headers);
    }
}
#endif

void LogProcessView::on_UpdateView(const S_LogInfo_Process &data)
{
    m_ProcessInfos.lst_Header = data.lst_Header;
    m_ProcessInfos.dic_ProcessInfo = data.dic_ProcessInfo;
    if(nullptr == p_model)
    {
        //        p_model = new LogProcessModel(this);
        //        p_model->setModel(&m_ProcessInfos);
        //        ui->tbw_LogProcess->setModel(p_model);
    }
    else
    {
        p_model->resetModel(&m_ProcessInfos);
        ui->tbw_LogProcess->scrollToTop();
    }
}

void LogProcessView::on_Search()
{
    int index = 0;
    qDebug() << index;
    S_LogInfo_Process logProcess;
    S_TimeSlot time;
    time.dateTimeStart = ui->dtEditDateStart->dateTime().toString("yyyy-MM-dd ") + ui->dtEditTimeStart->time().toString("HH:mm");
    time.dateTimeEnd = ui->dtEditDateEnd->dateTime().toString("yyyy-MM-dd ") + ui->dtEditTimeEnd->time().toString("HH:mm");
    logProcess.lst_Header = m_lst_Header;
    logProcess.dateTime = time;
    m_Publisher.Publish("DataLog", EnumConverter::ConvertToString(CMD_Log::CMD_LogProcess), false, logProcess.toRawJson());
}

void LogProcessView::on_DateTimeChanged(QDateTime date)
{
    Q_UNUSED(date);
    QDateTime dateTimeStart = ui->dtEditDateStart->dateTime();
    QDateTime dateTimeEnd = ui->dtEditDateEnd->dateTime();
    dateTimeStart.setTime(ui->dtEditTimeStart->time());
    dateTimeEnd.setTime(ui->dtEditTimeEnd->time());

    QDateTimeEdit *dateTime = static_cast<QDateTimeEdit *>(sender());
    if(dateTime)
    {
        QString obj = dateTime->objectName();
        int diff = dateTimeEnd.toTime_t() - dateTimeStart.toTime_t();
        if(diff < 0)
        {
            if(obj == "dtEditDateStart" || obj == "dtEditTimeStart")
            {
                ui->dtEditDateEnd->setDateTime(ui->dtEditDateStart->dateTime());
                ui->dtEditTimeEnd->setDateTime(ui->dtEditTimeStart->dateTime());
            }
            else
            {
                ui->dtEditDateStart->setDateTime(ui->dtEditDateEnd->dateTime());
                ui->dtEditTimeStart->setDateTime(ui->dtEditTimeEnd->dateTime());
            }
            return;
        }

        if(diff > 3600)
        {
            if(obj == "dtEditDateStart" || obj == "dtEditTimeStart")
            {
                QDateTime dateTime = dateTimeStart.addSecs(3600);
                ui->dtEditDateEnd->setDateTime(dateTime);
                ui->dtEditTimeEnd->setDateTime(dateTime);
            }
            else
            {
                QDateTime dateTime = dateTimeEnd.addSecs(-3600);
                ui->dtEditDateStart->setDateTime(dateTime);
                ui->dtEditTimeStart->setDateTime(dateTime);
            }
            return;
        }
    }
}


void LogProcessView::setWidgets()
{
    QGraphicsDropShadowEffect *effect_tbw = new QGraphicsDropShadowEffect(this);
    effect_tbw->setOffset(0, 0);
    effect_tbw->setColor(QColor(0, 0, 0, 64));
    effect_tbw->setBlurRadius(10);
    ui->tbw_LogProcess->setGraphicsEffect(effect_tbw);

    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    ui->dtEditDateStart->setDateTime(QDateTime::fromString(date, "yyyy-MM-dd"));
    ui->dtEditDateEnd->setDateTime(QDateTime::fromString(date, "yyyy-MM-dd"));

    ui->btn_Profile->hide();
}


void LogProcessView::setWidgetStyleSheet()
{
    setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->btn_Search->setStyleSheet(GlobalStyleSheet->Button_Border + GlobalStyleSheet->fontStyle_normal_12);
    ui->btn_Profile->setStyleSheet(GlobalStyleSheet->Button_Border + GlobalStyleSheet->fontStyle_normal_12);
    ui->dtEditDateStart->setStyleSheet(GlobalStyleSheet->CalendarWidgetStyle);
    ui->dtEditDateEnd->setStyleSheet(GlobalStyleSheet->CalendarWidgetStyle);
}


void LogProcessView::setLanguageKeys()
{

}


void LogProcessView::setConnections()
{
    //    connect(ThreadProcSubscriber::getInstance(), &ThreadProcSubscriber::sig_InitialProcSingalInfo, this, &LogProcessView::on_UpdateHeader);
    //    connect(ThreadProcSubscriber::getInstance(), &ThreadProcSubscriber::sig_MonitorProcSingalInfo, this, &LogProcessView::on_UpdateHeader);
    //    connect(ThreadProcSubscriber::getInstance(), &ThreadProcSubscriber::sig_AutoRunProcSingalInfo, this, &LogProcessView::on_UpdateHeader);
    connect(LogSubscriber::getInstance(), &LogSubscriber::Sig_LogInfo_Process, this, &LogProcessView::on_UpdateView);

    connect(ui->btn_Search, &QPushButton::clicked, this, &LogProcessView::on_Search);
    connect(ui->dtEditDateStart, &QDateTimeEdit::dateTimeChanged, this, &LogProcessView::on_DateTimeChanged);
    connect(ui->dtEditDateEnd, &QDateTimeEdit::dateTimeChanged, this, &LogProcessView::on_DateTimeChanged);
    connect(ui->dtEditTimeStart, &QDateTimeEdit::dateTimeChanged, this, &LogProcessView::on_DateTimeChanged);
    connect(ui->dtEditTimeEnd, &QDateTimeEdit::dateTimeChanged, this, &LogProcessView::on_DateTimeChanged);
}


void LogProcessView::initTable(QTableView *table)
{
    if(table)
    {
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->horizontalHeader()->setStretchLastSection(true);
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        table->verticalHeader()->setVisible(false);
        table->setSelectionMode(QAbstractItemView::SingleSelection);
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        table->setStyleSheet(GlobalStyleSheet->tableStyle);
        table->setContextMenuPolicy(Qt::CustomContextMenu);
    }
}
