#ifndef MCEDITORVIEW_H
#define MCEDITORVIEW_H

#include "GUIFramework_global.h"
#include "AuthorityComponent/authoritywidget.h"
#include "IMachineConstant/Data/machineconstant.h"
#include "IMachineConstant/Data/mccontent.h"
//#include "../../Data/MCContent/mccontext.h"

#include <QWidget>

namespace Ui
{
    class McEditorView;
}

class GUIFRAMEWORK_EXPORT McEditorView : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit McEditorView(QString name, QWidget *parent = nullptr);
    ~McEditorView();

public:
    void setConstant(QByteArray data);
    void setMcContent(S_MCContent &mcContext);
    void dumpJson(QByteArray &data);
    void expandAll();
    void setReadOnly(bool readOnly);

public slots:
    virtual void ConstructFinished() override;

signals:

private:
    virtual void setWidgets() override;
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;
    virtual void setConnections() override;

private:
    Ui::McEditorView *ui;
};

#endif // MCEDITORVIEW_H
