#ifndef BINDABLEWIDGET_H
#define BINDABLEWIDGET_H

#include "GUICommFuncLib_global.h"

#include "BasicValue/node.h"
#include "BasicValue/tvalue.h"
#include "StyleSheet/stylesheet.h"
#include "CustomerWidget/Dialog/messagedialog.h"
#include "Language/language.h"

#include "BindableUserControl/uc_tstring.h"
#include "BindableUserControl/uc_tint.h"
#include "BindableUserControl/uc_tdouble.h"
#include "BindableUserControl/uc_tenum.h"
#include "BindableUserControl/uc_tbool.h"

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QFuture>
#include <QMutex>
#include <QWaitCondition>

class GUICOMMFUNCLIB_EXPORT BindableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BindableWidget(QString name, QWidget *parent = nullptr);
    ~BindableWidget();

    virtual void showEvent(QShowEvent *event);
    virtual void hideEvent(QHideEvent *event);

    void Binding(TInt *value, QLabel *lbl);
    void Binding(TInt *value, QLineEdit *led);
    void Binding(TInt *value, QSpinBox *spb);
    void Binding(TDouble *value, QLabel *lbl);
    void Binding(TDouble *value, QLineEdit *led);
    void Binding(TDouble *value, QDoubleSpinBox *spb);
    void Binding(TBool *value, QPushButton *btn);
    void Binding(TString *value, QLabel *lbl);
    void Binding(TString *value, QLineEdit *led);
    void Binding(TEnum *value, QComboBox *cmb);

    void Binding(TInt *value, UC_TString *led);
    void Binding(TString *value, UC_TString *led);
    void Binding(TInt *value, UC_TInt *spb);
    void Binding(TDouble *value, UC_TDouble *spb);
    void Binding(TEnum *value, UC_TEnum *cmb);
    void Binding(TBool *value, UC_TBool *btn);

    void DisBinding(TString *value, QLineEdit *wdg);

    QMultiMap<TValueBase *, QWidget *> dicBindWidget;
    bool uiRefreshed = false;
    QMutex mutex_ValueChange;
    QWaitCondition condition;
    QString name;

public slots:
    void Refreshing();

signals:
    void showed(BindableWidget *wdg);
    void hided(BindableWidget *wdg);

    void dataChanged(TInt *value);
    void dataChanged(TDouble *value);
    void dataChanged(TBool *value);
    void dataChanged(TString *value);
    void dataChanged(TEnum *value);

private:
    void refreshWidget(TString *value);
    void refreshWidget(TInt *value);
    void refreshWidget(TDouble *value);
    void refreshWidget(TBool *value);
    void refreshWidget(TEnum *value);

private:
    bool bShowing;
    QFuture<void> future;

};

#endif // BINDABLEWIDGET_H
