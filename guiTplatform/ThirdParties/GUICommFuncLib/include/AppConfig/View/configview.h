#ifndef CONFIGVIEW_H
#define CONFIGVIEW_H

#include "GUICommFuncLib_global.h"
#include "AuthorityComponent/authoritywidget.h"
#include "AppConfig/Data/guiconfig.h"

#include <QWidget>

namespace Ui
{
    class ConfigView;
}

class GUICOMMFUNCLIB_EXPORT ConfigView : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit ConfigView(QString name, QWidget *parent = nullptr);
    ~ConfigView();

public:
    virtual void ConstructFinished() override;

protected:
    virtual void setWidgets() override;
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;
    virtual void setConnections() override;

private:
    Ui::ConfigView *ui;

    SR_GUIConfig m_UIPara;
    Language::LanguageType m_LanguageType;
    MessageDialog *m_DLG_License = NULL;
};

#endif // CONFIGVIEW_H
