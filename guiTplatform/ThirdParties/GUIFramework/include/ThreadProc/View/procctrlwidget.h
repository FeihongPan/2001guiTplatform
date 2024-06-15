#ifndef PROCCTRLWIDGET_H
#define PROCCTRLWIDGET_H

#include "GUIFramework_global.h"
#include "AuthorityComponent/authoritywidget.h"
#include "ThreadProc/Data/processdata_gui.h"
#include "ThreadProc/Data/processdata.h"

#include <QWidget>

namespace Ui
{
    class ProcCtrlWidget;
}

class GUIFRAMEWORK_EXPORT ProcCtrlWidget : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit ProcCtrlWidget(QString name, QWidget *parent = nullptr);
    ~ProcCtrlWidget() override;

    void SetProcData(S_SingleProcData &procData);
    void SetSignalItem(QStringList signalItems);

signals:
    void Start(S_SingleProcData &procData);
    void Stop(S_SingleProcData &procData);
    void Reset(S_SingleProcData &procData);
    void SetSingleStepModel(S_SingleProcData &procData);
    void NextStep(S_SingleProcData &procData);
    void SetSignal(S_SingleProcData &procData);

private:
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;
    virtual void setConnections() override;

private:
    Ui::ProcCtrlWidget *ui;

    SR_SingleProcData m_ProcData;
    TBool m_SignalValue;
};

#endif // PROCCTRLWIDGET_H
