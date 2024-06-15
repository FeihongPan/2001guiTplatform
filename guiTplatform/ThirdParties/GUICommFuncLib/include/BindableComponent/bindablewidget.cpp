#include "bindablewidget.h"
#include "BasicValue/tvalue.h"
#include "Language/language.h"
//#include "Dialog/messagedialog.h"
#include "bindablecontainer.h"

#include <QtConcurrent/QtConcurrent>
#include <QTime>

BindableWidget::BindableWidget(QString name, QWidget *parent) : QWidget(parent)
{
    this->name = name;
    connect(this, &BindableWidget::showed, BindableContainer::GetInstance(), &BindableContainer::AddWidget);
    connect(this, &BindableWidget::hided, BindableContainer::GetInstance(), &BindableContainer::RemoveWidget);
    connect(BindableContainer::GetInstance(), &BindableContainer::sendStartRefresh, this, &BindableWidget::Refreshing);
    connect(this, static_cast<void(BindableWidget::*)(TString *)>(&BindableWidget::dataChanged), this, [ = ](TString * value)
    {
        refreshWidget(value);
    });

    connect(this, static_cast<void(BindableWidget::*)(TInt *)>(&BindableWidget::dataChanged), this, [ = ](TInt * value)
    {
        refreshWidget(value);
    });

    connect(this, static_cast<void(BindableWidget::*)(TDouble *)>(&BindableWidget::dataChanged), this, [ = ](TDouble * value)
    {
        refreshWidget(value);
    });

    connect(this, static_cast<void(BindableWidget::*)(TBool *)>(&BindableWidget::dataChanged), this, [ = ](TBool * value)
    {
        refreshWidget(value);
    });

    connect(this, static_cast<void(BindableWidget::*)(TEnum *)>(&BindableWidget::dataChanged), this, [ = ](TEnum * value)
    {
        refreshWidget(value);
    });

}

BindableWidget::~BindableWidget()
{

}

void BindableWidget::showEvent(QShowEvent *event)
{
    Q_UNUSED(event)
    this->bShowing = true;
    //    qDebug() << "BindableWidget::showEvent" << this->name;

    QList<TValueBase *> lstValues = dicBindWidget.uniqueKeys();
    //        qDebug() << "BindableWidget::showEvent"  << lstValues.count();
    foreach(TValueBase *value, lstValues)
    {
        //        qDebug() << "BindableWidget::showEvent value" << value->valueName;
        if(value->valueType == ValueType::Value_String)
        {
            emit dataChanged(static_cast<TString *>(value));
        }
        else if(value->valueType == ValueType::Value_Int)
        {
            emit dataChanged(static_cast<TInt *>(value));
        }
        else if(value->valueType == ValueType::Value_Double)
        {
            emit dataChanged(static_cast<TDouble *>(value));
        }
        else if (value->valueType == ValueType::Value_Bool)
        {
            emit dataChanged(static_cast<TBool *>(value));
        }
        else if (value->valueType == ValueType::Value_Enum)
        {
            emit dataChanged(static_cast<TEnum *>(value));
        }
    }
    emit showed(this);
}

void BindableWidget::hideEvent(QHideEvent *event)
{
    Q_UNUSED(event)

    bShowing = false;
    future.waitForFinished();

    emit hided(this);
}

void BindableWidget::Binding(TInt *value, QLabel *lbl)
{
    dicBindWidget.insert(value, lbl);
}

void BindableWidget::Binding(TInt *value, QLineEdit *led)
{
    dicBindWidget.insert(value, led);
    connect(led, &QLineEdit::editingFinished, this, [ = ]()
    {
        while (!BindableContainer::GetInstance()->IsBusy)
        {
            bool ok;
            int n = led->text().toInt(&ok);
            if(!(ok && value->SetValue(n)))
            {
                led->setText(QString::number(value->value));
            }
            break;
        }
    });
}

void BindableWidget::Binding(TInt *value, QSpinBox *spb)
{
    dicBindWidget.insert(value, spb);
    connect(spb, &QSpinBox::editingFinished, this, [ = ]()
    {
        while (!BindableContainer::GetInstance()->IsBusy)
        {
            value->SetValue(spb->value());
            break;
        }
    });
}

void BindableWidget::Binding(TDouble *value, QLabel *lbl)
{
    dicBindWidget.insert(value, lbl);
}

void BindableWidget::Binding(TDouble *value, QLineEdit *led)
{
    dicBindWidget.insert(value, led);
    connect(led, &QLineEdit::editingFinished, this, [ = ]()
    {
        while (!BindableContainer::GetInstance()->IsBusy)
        {
            bool ok;
            double n = led->text().toDouble(&ok);
            if(!(ok && value->SetValue(n)))
            {
                led->setText(QString::number(value->value));
            }
            break;
        }
    });
}

void BindableWidget::Binding(TDouble *value, QDoubleSpinBox *spb)
{
    dicBindWidget.insert(value, spb);
    connect(spb, &QDoubleSpinBox::editingFinished, this, [ = ]()
    {
        while (!BindableContainer::GetInstance()->IsBusy)
        {
            if(!value->SetValue(spb->value()))
            {
                spb->setValue(value->value);
            }
            break;
        }
    });
}

void BindableWidget::Binding(TBool *value, QPushButton *btn)
{
    dicBindWidget.insert(value, btn);
    connect(btn, &QPushButton::toggled, this, [ = ](bool checked)
    {
        while (!BindableContainer::GetInstance()->IsBusy)
        {
            value->SetValue(checked);
            break;
        }
    });
}

void BindableWidget::Binding(TString *value, QLabel *lbl)
{
    dicBindWidget.insert(value, lbl);
}

void BindableWidget::Binding(TString *value, QLineEdit *led)
{
    dicBindWidget.insert(value, led);
    connect(led, &QLineEdit::textChanged, this, [ = ]()
    {
        while (!BindableContainer::GetInstance()->IsBusy)
        {
            if(!value->SetValue(led->text()))
            {
                led->setText(value->value);
            }
            break;
        }
    });
}

void BindableWidget::Binding(TEnum *value, QComboBox *cmb)
{
    dicBindWidget.insert(value, cmb);
    cmb->clear();
    cmb->addItems(value->dataSource);
    cmb->setCurrentIndex(value->value);

    connect(cmb, static_cast<void(QComboBox::*)(int index)>(&QComboBox::activated), this, [ = ](int index)
    {
        while (!BindableContainer::GetInstance()->IsBusy)
        {
            value->SetValue(index);
            break;
        }
    });
}

void BindableWidget::Binding(TInt *value, UC_TString *led)
{
    dicBindWidget.insert(value, led);
    QString name = Tr(value->valueName);
    led->setName(name);
    connect(led, &UC_TString::editingFinished, this, [ = ]()
    {
        while (!BindableContainer::GetInstance()->IsBusy)
        {
            if(!value->SetValue(led->text().toInt()))
            {
                led->setText(QString::number(value->value));
            }
            break;
        }
    });
}

void BindableWidget::Binding(TString *value, UC_TString *led)
{
    dicBindWidget.insert(value, led);
    QString name = Tr(value->valueName);
    led->setName(name);
    connect(led, &UC_TString::editingFinished, this, [ = ]()
    {
        while (!BindableContainer::GetInstance()->IsBusy)
        {
            if(!value->SetValue(led->text()))
            {
                led->setText(value->value);
            }
            break;
        }
    });
}

void BindableWidget::Binding(TInt *value, UC_TInt *spb)
{
    dicBindWidget.insert(value, spb);
    QString name = Tr(value->valueName);
    spb->setName(name);
    spb->setUnit(value->unit);
    connect(spb, &UC_TInt::editingFinished, this, [ = ]()
    {
        while (!BindableContainer::GetInstance()->IsBusy)
        {
            if(!value->SetValue(spb->value()))
            {
                spb->setValue(value->value);
            }
            break;
        }
    });
}

void BindableWidget::Binding(TDouble *value, UC_TDouble *spb)
{
    dicBindWidget.insert(value, spb);
    QString name = Tr(value->valueName);
    spb->setName(name);
    spb->setUnit(value->unit);
    connect(spb, &UC_TDouble::editingFinished, this, [ = ]()
    {
        while (!BindableContainer::GetInstance()->IsBusy)
        {
            if(!value->SetValue(spb->value()))
            {
                spb->setValue(value->value);
            }
            break;
        }
    });
}

void BindableWidget::Binding(TEnum *value, UC_TEnum *cmb)
{
    dicBindWidget.insert(value, cmb);
    QString name = Tr(value->valueName);
    cmb->setName(name);

    cmb->setDatasource(value->dataSource);
    cmb->setCurrentIndex(value->value);
    connect(cmb, &UC_TEnum::activated, this, [ = ](int index)
    {
        while (!BindableContainer::GetInstance()->IsBusy)
        {
            value->SetValue(index);
            break;
        }
    });
}

void BindableWidget::Binding(TBool *value, UC_TBool *btn)
{
    dicBindWidget.insert(value, btn);
    QString name = Tr(value->valueName);
    btn->setName(name);
    connect(btn, &UC_TBool::toggled, this, [ = ](bool checked)
    {
        while (!BindableContainer::GetInstance()->IsBusy)
        {
            value->SetValue(checked);
            break;
        }
    });
}

void BindableWidget::DisBinding(TString *value, QLineEdit *wdg)
{
    dicBindWidget.remove(value);

    //    wdg.
    //    disconnect(wdg,&QLineEdit::editingFinished,value);
    //    connect(led, &QLineEdit::editingFinished, this, [=](){
    //        while (!BindableContainer::GetInstance()->IsBusy) {
    //            qDebug() << value->value;
    //            if(!value->SetValue(led->text()))
    //            {

    //                led->setText(value->value);
    //            }
    //            break;
    //        }
    //    });
}

void BindableWidget::Refreshing()
{
    future = QtConcurrent::run([ = ]
    {
        if(this->bShowing)
        {
            QList<TValueBase *> lstValues = dicBindWidget.uniqueKeys();
            foreach(TValueBase *value, lstValues)
            {
                if(value->PropertyChanged)
                {
                    if(value->valueType == ValueType::Value_String)
                    {
                        emit dataChanged(static_cast<TString *>(value));
                    }
                    else if(value->valueType == ValueType::Value_Int)
                    {
                        emit dataChanged(static_cast<TInt *>(value));
                    }
                    else if(value->valueType == ValueType::Value_Double)
                    {
                        emit dataChanged(static_cast<TDouble *>(value));
                    }
                    else if (value->valueType == ValueType::Value_Bool)
                    {
                        emit dataChanged(static_cast<TBool *>(value));
                    }
                    else if (value->valueType == ValueType::Value_Enum)
                    {
                        emit dataChanged(static_cast<TEnum *>(value));
                    }
                }
            }
        }
    });
    future.waitForFinished();
    uiRefreshed = true;
}

void BindableWidget::refreshWidget(TString *value)
{
    QList<QWidget *> lstWidget = dicBindWidget.values(value);
    foreach(QWidget *wdg, lstWidget)
    {
        if(wdg->inherits("QLabel"))
        {
            QLabel *lbl = static_cast<QLabel *>(wdg);
            lbl->setText(value->value);
        }
        else if(wdg->inherits("QLineEdit"))
        {
            QLineEdit *led = static_cast<QLineEdit *>(wdg);
            led->setText(value->value);
        }
        else if(wdg->inherits("UC_TString"))
        {
            UC_TString *led = static_cast<UC_TString *>(wdg);
            led->setText(value->value);
        }
    }
}

void BindableWidget::refreshWidget(TInt *value)
{
    QList<QWidget *> lstWidget = dicBindWidget.values(value);
    foreach(QWidget *wdg, lstWidget)
    {
        if(wdg->inherits("QLabel"))
        {
            QLabel *lbl = static_cast<QLabel *>(wdg);
            lbl->setText(QString::number(value->value));
        }
        else if(wdg->inherits("QLineEdit"))
        {
            QLineEdit *led = static_cast<QLineEdit *>(wdg);
            led->setText(QString::number(value->value));
        }
        else if(wdg->inherits("QSpinBox"))
        {
            QSpinBox *spb = static_cast<QSpinBox *>(wdg);
            spb->setMinimum(value->min);
            spb->setMaximum(value->max);
            spb->setValue(value->value);

            if(spb->objectName() == "spb_StepIndex")
            {
                // qDebug() << "spb->setValue(value->value);" << value << value->value << spb->value();
            }
        }
        else if(wdg->inherits("QDoubleSpinBox"))
        {
            QDoubleSpinBox *spb = static_cast<QDoubleSpinBox *>(wdg);
            spb->setDecimals(0);
            spb->setMinimum(value->min);
            spb->setMaximum(value->max);
            spb->setValue(value->value);
        }
        else if(wdg->inherits("UC_TInt"))
        {
            UC_TInt *spb = static_cast<UC_TInt *>(wdg);
            spb->setMinimum(value->min);
            spb->setMaximum(value->max);
            spb->setValue(value->value);
        }
        else if(wdg->inherits("UC_TString"))
        {
            UC_TString *led = static_cast<UC_TString *>(wdg);
            led->setText(QString::number(value->value));
        }
    }
}

void BindableWidget::refreshWidget(TDouble *value)
{
    QList<QWidget *> lstWidget = dicBindWidget.values(value);
    foreach(QWidget *wdg, lstWidget)
    {
        if(wdg->objectName() == "wdg_imgPos_x")
        {
            qDebug() << "BindableWidget::refreshWidget";
        }
        if(wdg->inherits("QLabel"))
        {
            QLabel *lbl = static_cast<QLabel *>(wdg);
            lbl->setText(QString::number(value->value));
        }
        else if(wdg->inherits("QLineEdit"))
        {
            QLineEdit *led = static_cast<QLineEdit *>(wdg);
            led->setText(QString::number(value->value));
        }
        else if(wdg->inherits("QDoubleSpinBox"))
        {
            QDoubleSpinBox *spb = static_cast<QDoubleSpinBox *>(wdg);
            spb->setDecimals(value->precision);
            spb->setMinimum(value->min);
            spb->setMaximum(value->max);
            spb->setValue(value->value);
        }
        else if(wdg->inherits("UC_TDouble"))
        {
            UC_TDouble *spb = static_cast<UC_TDouble *>(wdg);
            spb->setDecimals(value->precision);
            spb->setMinimum(value->min);
            spb->setMaximum(value->max);
            spb->setValue(value->value);
        }
    }
}

void BindableWidget::refreshWidget(TBool *value)
{
    QList<QWidget *> lstWidget = dicBindWidget.values(value);
    foreach(QWidget *wdg, lstWidget)
    {
        if(wdg->inherits("QPushButton"))
        {
            QPushButton *btn = static_cast<QPushButton *>(wdg);
            btn->setChecked(value->value);
        }
        else if(wdg->inherits("QCheckBox"))
        {
            QCheckBox *ckb = static_cast<QCheckBox *>(wdg);
            ckb->setChecked(value->value);
        }
        else if(wdg->inherits("UC_TBool"))
        {
            UC_TBool *btn = static_cast<UC_TBool *>(wdg);
            btn->setChecked(value->value);
        }
    }
}

void BindableWidget::refreshWidget(TEnum *value)
{
    QList<QWidget *> lstWidget = dicBindWidget.values(value);
    foreach(QWidget *wdg, lstWidget)
    {
        if(wdg->inherits("QComboBox"))
        {
            QComboBox *cmb = static_cast<QComboBox *>(wdg);
            //            cmb->clear();
            //            cmb->addItems(value->dataSource);
            cmb->setCurrentIndex(value->value);
        }
        else if(wdg->inherits("UC_TEnum"))
        {
            UC_TEnum *cmb = static_cast<UC_TEnum *>(wdg);
            //            cmb->setDatasource(value->dataSource);
            cmb->setCurrentIndex(value->value);
        }
    }
}
