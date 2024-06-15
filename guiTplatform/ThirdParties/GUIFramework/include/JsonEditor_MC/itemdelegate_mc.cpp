#include "itemdelegate_mc.h"

#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QMutex>
#include <QDebug>

ItemDelegate_MC *ItemDelegate_MC::self = nullptr;
ItemDelegate_MC::ItemDelegate_MC(QObject *parent) :
    QStyledItemDelegate(parent)
{

}

ItemDelegate_MC *ItemDelegate_MC::getInstance()
{
    if(self == nullptr)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == nullptr)
        {
            self = new ItemDelegate_MC;
        }
    }
    return self;
}

QWidget *ItemDelegate_MC::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column() == 1)
    {
        //        QDoubleSpinBox *spb = new QDoubleSpinBox(parent);
        //        spb->setAlignment(Qt::AlignCenter);
        //        spb->setMinimum(-9999);
        //        spb->setMaximum(60000);
        //        spb->setDecimals(6);
        //        return spb;
        QLineEdit *ldt = new QLineEdit(parent);
        ldt->setAlignment(Qt::AlignCenter);
        return ldt;
    }
    else if(index.column() > 1)
    {
        QLineEdit *ldt = new QLineEdit(parent);
        ldt->setAlignment(Qt::AlignCenter);
        return ldt;
    }
}
