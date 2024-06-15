#include "checkboxdelegate.h"

#include <QMutex>
#include <QCheckBox>
#include <QApplication>
#include <QDebug>

CheckBoxDelegate *CheckBoxDelegate::self = nullptr;
CheckBoxDelegate::CheckBoxDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
}

CheckBoxDelegate *CheckBoxDelegate::getInstance()
{
    if(self == nullptr)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == nullptr)
        {
            self = new CheckBoxDelegate;
        }
    }
    return self;
}

void CheckBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column() > 0)
    {
        QStyleOptionButton checkBoxOption;
        QRect checkBoxRect = QApplication::style()->subElementRect(QStyle::SE_CheckBoxIndicator, &checkBoxOption);
        QStyleOptionViewItem newoption(option);
        newoption.rect.setLeft(option.rect.left() + (option.rect.width()) / 2 - checkBoxRect.width() * 2 / 3);
        QStyledItemDelegate::paint(painter, newoption, index);
    }
    else
    {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

bool CheckBoxDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    Qt::ItemFlags flag = model->flags(index);
    if(flag == Qt::ItemIsSelectable ||  flag == (Qt::ItemIsSelectable | Qt::ItemIsUserCheckable))
    {
        return false;
    }
    if(event->type()  == QEvent::MouseButtonPress)
    {
        bool isChecked = index.data(Qt::CheckStateRole).toBool();
        Qt::CheckState state = isChecked ? Qt::Unchecked : Qt::Checked;
        model->setData(index, state, Qt::CheckStateRole);
        return QStyledItemDelegate::editorEvent(event, model, option, index);
    }
    return false;
}











