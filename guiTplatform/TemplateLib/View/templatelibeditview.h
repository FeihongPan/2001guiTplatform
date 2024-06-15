#ifndef TEMPLATELIBEDITVIEW_H
#define TEMPLATELIBEDITVIEW_H

#include "AuthorityComponent/authoritywidget.h"
#include "TemplateLib/Data/templatelib.h"
#include "itemdelegate.h"

#include <QWidget>
#include <QTableWidget>

namespace Ui
{
    class TemplateLibEditView;
}

class TemplateLibEditView : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit TemplateLibEditView(QString name, QWidget *parent = nullptr);
    ~TemplateLibEditView();

    void setEditorStatus(bool status);
    void loadUi();
    void dumpUi();

    S_TemplateLib templateLib;

public slots:
    virtual void ConstructFinished() override;

    void pointTabWidget_add(QTableWidget *widget);
    void pointTabWidget_delete(QTableWidget *widget);
    void pointTabWidget_up(QTableWidget *widget);
    void pointTabWidget_down(QTableWidget *widget);

private:
    virtual void setWidgets() override;
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;
    virtual void setConnections() override;

    void on_TabChanged(int index);

private:
    Ui::TemplateLibEditView *ui;
};

#endif // TEMPLATELIBEDITVIEW_H
