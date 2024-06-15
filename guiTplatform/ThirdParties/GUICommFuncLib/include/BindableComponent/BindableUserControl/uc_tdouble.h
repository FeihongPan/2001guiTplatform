#ifndef UC_TDOUBLE_H
#define UC_TDOUBLE_H

#include "GUICommFuncLib_global.h"
#include <QWidget>

namespace Ui
{
    class UC_TDouble;
}

class GUICOMMFUNCLIB_EXPORT UC_TDouble : public QWidget
{
    Q_OBJECT

public:
    explicit UC_TDouble(QWidget *parent = nullptr);
    ~UC_TDouble();

    double value();
    void setName(QString str);
    void setUnit(QString unit);
    void setValue(double value);
    void setDecimals(int decimal);
    void setMinimum(double min);
    void setMaximum(double max);
    void setStrechFactor(int v1, int v2, int v3); //123
    void setEnabled(bool enable);

    double getValue();

signals:
    void editingFinished();

private:
    Ui::UC_TDouble *ui;
};

#endif // UC_TDOUBLE_H
