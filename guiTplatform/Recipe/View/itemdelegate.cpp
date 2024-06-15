#include "itemdelegate.h"

#include <QDoubleSpinBox>
#include <QMutex>

ItemDelegate *ItemDelegate::self = nullptr;
ItemDelegate::ItemDelegate(QObject *parent) :
    QItemDelegate(parent)
{

}

ItemDelegate *ItemDelegate::getInstance()
{
    if(self == nullptr)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == nullptr)
        {
            self = new ItemDelegate;
        }
    }
    return self;
}

QWidget *ItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QDoubleSpinBox *spb = new QDoubleSpinBox(parent);
    spb->setMinimum(-9999);
    spb->setMaximum(9999);
    spb->setDecimals(6);
    return spb;
}
