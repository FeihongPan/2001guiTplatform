#ifndef SETUPFORM_H
#define SETUPFORM_H

#include "AuthorityComponent/authoritywidget.h"

#include <QWidget>

namespace Ui
{
    class SetupForm;
}

class SetupForm : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit SetupForm(QString name, QWidget *parent = nullptr);
    ~SetupForm();

private:
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;

private:
    Ui::SetupForm *ui;
};

#endif // SETUPFORM_H
