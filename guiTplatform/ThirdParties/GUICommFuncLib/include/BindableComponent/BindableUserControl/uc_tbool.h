#ifndef UC_TBOOL_H
#define UC_TBOOL_H

#include "GUICommFuncLib_global.h"

#include <QWidget>

namespace Ui
{
    class uc_TBool;
}

class GUICOMMFUNCLIB_EXPORT UC_TBool : public QWidget
{
    Q_OBJECT

public:
    explicit UC_TBool(QWidget *parent = nullptr);
    ~UC_TBool();

    bool isChecked();
    void setName(QString &str);
    void setChecked(bool checked);
signals:
    void toggled(bool checked);
    void clicked();

private:
    Ui::uc_TBool *ui;
};

#endif // UC_TBOOL_H
