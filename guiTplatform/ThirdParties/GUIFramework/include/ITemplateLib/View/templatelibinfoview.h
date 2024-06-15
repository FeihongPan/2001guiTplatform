#ifndef TEMPLATELIBINFOVIEW_H
#define TEMPLATELIBINFOVIEW_H

#include "GUIFramework_global.h"
#include "ITemplateLib/Data/templateinfo.h"
#include "ITemplateLib/View/templatelibbasicinformation.h"

#include <QWidget>

namespace Ui
{
    class TemplateLibInfoView;
}

class GUIFRAMEWORK_EXPORT TemplateLibInfoView : public QWidget
{
    Q_OBJECT

public:
    explicit TemplateLibInfoView(QWidget *parent = nullptr);
    ~TemplateLibInfoView();

    void setEditorStatus(bool status);
    void dumpUI();

    S_TemplateInfo m_TemplateInfo;

signals:
    void sig_TemplateInfo(S_TemplateInfo &temp);

public slots:
    void on_TemplateInfo(S_TemplateInfo &temp);


private:
    Ui::TemplateLibInfoView *ui;
    bool m_bStatus;
};

#endif // TEMPLATELIBINFOVIEW_H
