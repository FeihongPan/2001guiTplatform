#ifndef SGTVIEW_H
#define SGTVIEW_H

#include "GUIFramework_global.h"
#include "AuthorityComponent/authoritywidget.h"
#include "SGT/Data/sgtconstant.h"
#include "SGT/Data/sgtsystem.h"

#include <QWidget>

namespace Ui
{
    class SGTView;
}

class GUIFRAMEWORK_EXPORT SGTView : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit SGTView(QString name, QWidget *parent = nullptr);
    ~SGTView();

    virtual void ConstructFinished() override;

private:
    virtual void setWidgets() override;
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;
    virtual void setConnections() override;

    void showSGTData(QSpinBox *off, QSpinBox *on, SGTSystem::SGTComponent component, SGTSystem::State sgtState, SGTSystem::TwinkleMode twinkleModel);

private:
    Ui::SGTView *ui;

    S_SGTConstant m_SGTConstant;
};

#endif // SGTVIEW_H
