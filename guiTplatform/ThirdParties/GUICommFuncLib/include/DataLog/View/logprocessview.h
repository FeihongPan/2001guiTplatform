#ifndef LOGPROCESSVIEW_H
#define LOGPROCESSVIEW_H

#include "GUICommFuncLib_global.h"
#include "AuthorityComponent/authoritywidget.h"
#include "CustomerWidget/HeaderView/rbtableheaderview.h"
#include "DataLog/Data/loginfo.h"
#include "logprocessmodel.h"

#include <QWidget>
#include <QTableView>

namespace Ui
{
    class LogProcessView;
}

class GUICOMMFUNCLIB_EXPORT LogProcessView : public AuthorityWidget
{
    Q_OBJECT
public:
    explicit LogProcessView(QString name, QWidget *parent = nullptr);
    ~LogProcessView();
    RbTableHeaderView *getHeader();

public slots:
    void on_UpdateView(const S_LogInfo_Process &data);
    //    void on_UpdateHeader(ProcListBasicInfo &info, bool result);

private slots:
    void on_Search();
    void on_DateTimeChanged(QDateTime date);


private:
    virtual void setWidgets() override;
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;
    virtual void setConnections() override;

    void initTable(QTableView *table);
    void updateHeader(const S_LogHeader_Process &headers);

private:
    Ui::LogProcessView *ui;
    RbTableHeaderView *m_pHeader{nullptr};
    S_LogHeader_Process m_headers;
    QStringList m_headerModuleOrder;

    QStringList m_lst_Header;
    S_LogInfo_Process m_ProcessInfos;
    LogProcessModel *p_model{nullptr};

};

#endif // LOGPROCESSVIEW_H
