#ifndef UC_TSTRING_H
#define UC_TSTRING_H

#include "GUICommFuncLib_global.h"

#include <QWidget>
#include <QValidator>

namespace Ui
{
    class UC_TString;
}

class GUICOMMFUNCLIB_EXPORT UC_TString : public QWidget
{
    Q_OBJECT

public:
    explicit UC_TString(QWidget *parent = nullptr);
    ~UC_TString();

    QString text();
    void setText(const QString &str);
    void setName(QString str);

    void setEnabled(bool enable);
    void setValidator(const QValidator *validator);
    void setStrechFactor(int v1, int v2, int v3); //123

signals:
    void editingFinished();

private:
    Ui::UC_TString *ui;
};

#endif // UC_TSTRING_H
