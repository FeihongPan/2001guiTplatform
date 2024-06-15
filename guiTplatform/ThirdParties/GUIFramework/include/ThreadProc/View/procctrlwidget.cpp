#include "procctrlwidget.h"
#include "ui_procctrlwidget.h"
#include <QDebug>

ProcCtrlWidget::ProcCtrlWidget(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::ProcCtrlWidget)
{
    qRegisterMetaType<S_SingleProcData>("S_SingleProcData");
    qRegisterMetaType<S_SingleProcData>("S_SingleProcData&");

    ui->setupUi(this);
    ui->lbl_Name->setText(name);

    Binding(&m_ProcData.stepIndex, ui->spb_StepIndex);
    Binding(&m_ProcData.jumpOutIndex, ui->spb_JumpOutIndex);
    Binding(&m_ProcData.isInitialized, ui->btn_Initialized);
    Binding(&m_ProcData.isContinousRunning, ui->btn_Start);
    Binding(&m_ProcData.isStepRunning, ui->btn_SingleStep);
    Binding(&m_ProcData.isNextStepAction, ui->btn_NextStep);
    Binding(&m_SignalValue, ui->btn_SetSignal);
}

ProcCtrlWidget::~ProcCtrlWidget()
{
    delete ui;
}

void ProcCtrlWidget::SetProcData(S_SingleProcData &procData)
{
    this->m_ProcData = procData;
    bool isRunning = m_ProcData.isContinousRunning.value || m_ProcData.isStepRunning.value;
    if(ui->btn_Stop->isChecked() == isRunning)
    {
        ui->btn_Stop->setChecked(!(isRunning));
    }

    QString selectedSignal = ui->cmb_SignalItem->currentText();
    if(m_SignalValue.value != this->m_ProcData.dic_ProcessSignal[selectedSignal])
    {
        m_SignalValue = this->m_ProcData.dic_ProcessSignal[selectedSignal];
    }
}

void ProcCtrlWidget::SetSignalItem(QStringList signalItems)
{
    ui->cmb_SignalItem->clear();
    if(signalItems.count() == 0)
    {
        ui->cmb_SignalItem->setEnabled(false);
        ui->btn_SetSignal->setEnabled(false);
    }
    ui->cmb_SignalItem->addItems(signalItems);
}

void ProcCtrlWidget::setWidgetStyleSheet()
{
    ui->btn_Initialized->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->spb_StepIndex->setStyleSheet(StyleSheet::getInstance()->SpinBox_Dark);
    ui->spb_JumpOutIndex->setStyleSheet(StyleSheet::getInstance()->SpinBox_Dark);
    ui->btn_Reset->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_Start->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_SingleStep->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_NextStep->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_Stop->setStyleSheet(StyleSheet::getInstance()->Button_Border);
    ui->btn_SetSignal->setStyleSheet(StyleSheet::getInstance()->Button_Border);
}

void ProcCtrlWidget::setLanguageKeys()
{
    ui->btn_Reset->setText(Tr("Reset"));
    ui->btn_Start->setText(Tr("Start"));
    ui->btn_SingleStep->setText(Tr("Single Step"));
    ui->btn_NextStep->setText(Tr("Next Step"));
    ui->btn_Stop->setText(Tr("Stop"));
}

void ProcCtrlWidget::setConnections()
{
    connect(ui->btn_Reset, &QPushButton::clicked, this, [ = ]
    {
        S_SingleProcData procData;
        procData = m_ProcData;
        emit Reset(procData);
    });

    connect(ui->btn_Start, &QPushButton::clicked, this, [ = ]
    {
        S_SingleProcData procData;
        procData = m_ProcData;
        emit Start(procData);
    });

    connect(ui->btn_SingleStep, &QPushButton::clicked, this, [ = ]
    {
        S_SingleProcData procData;
        procData = m_ProcData;
        emit SetSingleStepModel(procData);
    });

    connect(ui->btn_NextStep, &QPushButton::clicked, this, [ = ]
    {
        S_SingleProcData procData;
        procData = m_ProcData;
        emit NextStep(procData);
    });

    connect(ui->btn_Stop, &QPushButton::clicked, this, [ = ]
    {
        S_SingleProcData procData;
        procData = m_ProcData;
        emit Stop(procData);
    });


    connect(ui->btn_SetSignal, &QPushButton::clicked, this, [ = ]
    {
        S_SingleProcData procData;
        m_ProcData.selectedSignalTargetState = ui->btn_SetSignal->isChecked();
        m_ProcData.selectedSignal = ui->cmb_SignalItem->currentText();
        procData = m_ProcData;
        emit SetSignal(procData);
    });

    connect(ui->cmb_SignalItem, &QComboBox::currentTextChanged, this, [ = ](const QString & text)
    {
        m_ProcData.selectedSignal = text;
        m_SignalValue = m_ProcData.dic_ProcessSignal[text];
    });

}
