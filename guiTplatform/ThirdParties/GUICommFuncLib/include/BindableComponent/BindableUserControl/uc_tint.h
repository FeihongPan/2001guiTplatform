#ifndef UC_TINT_H
#define UC_TINT_H

#include "GUICommFuncLib_global.h"

#include <QWidget>

namespace Ui
{
    class UC_TInt;
}

class GUICOMMFUNCLIB_EXPORT UC_TInt : public QWidget
{
    Q_OBJECT

public:
    explicit UC_TInt(QWidget *parent = nullptr);
    ~UC_TInt();

    double value();
    void setName(QString &str);
    void setUnit(QString &unit);
    void setValue(double value);
    void setMinimum(double min);
    void setMaximum(double max);
    void setStrechFactor(int v1, int v2, int v3); //123

signals:
    void editingFinished();

private:
    Ui::UC_TInt *ui;
};

#endif // UC_TINT_H
