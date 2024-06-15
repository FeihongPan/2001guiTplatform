#ifndef LOGDEBUGVIEW_H
#define LOGDEBUGVIEW_H

#include "GUICommFuncLib_global.h"
#include "AuthorityComponent/authoritywidget.h"
#include "DataLog/Data/loginfo.h"
#include "logdebugmodel.h"

#include <QWidget>
#include <QTableView>
#include <QHeaderView>
#include <QScrollBar>

namespace Ui
{
    class LogDebugView;
}

class GUICOMMFUNCLIB_EXPORT LogDebugView : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit LogDebugView(QString name, QWidget *parent = nullptr);
    ~LogDebugView();

public slots:
    void on_UpdateView(S_LogInfo_Debugs &data, bool result);

private slots:
    void on_Filter(const QString &strText);
    void on_Search();
    void on_DateStart(QDateTime date);
    void on_DateEnd(QDateTime date);
    void on_ScrollValueChanged(int value);
    void on_TimeChanged(QTime time);

private:
    virtual void setWidgets() override;
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;
    virtual void setConnections() override;

    void initTable(QTableView *table);
    void getShowData(S_LogInfo_Debugs &data, S_LogInfo_Debugs &out, int scrIndex);


private:
    Ui::LogDebugView *ui;
    S_LogInfo_Debugs m_debugInfos;
    LogDebugModel *m_debugModel;
    QScrollBar *vscrollBar;
};
#endif // LOGDEBUGVIEW_H
