#ifndef HELPFORM_H
#define HELPFORM_H

#include "AuthorityComponent/authoritywidget.h"

#include <QWidget>

namespace Ui
{
    class HelpForm;
}

class HelpForm : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit HelpForm(QString name, QWidget *parent = nullptr);
    ~HelpForm();

private:
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;

private:
    Ui::HelpForm *ui;
};

#endif // HELPFORM_H
