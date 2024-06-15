#ifndef CHECKBOXDELEGATE_H
#define CHECKBOXDELEGATE_H

#include "GUIComponentLib_global.h"
#include <QObject>
#include <QStyledItemDelegate>

class GUICOMPONENTLIB_EXPORT CheckBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    static CheckBoxDelegate *getInstance();

protected:
    void paint(QPainter *painter,const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;

private:
    static CheckBoxDelegate *self;
    CheckBoxDelegate(QObject *parent = nullptr);
};


#endif // CHECKBOXDELEGATE_H
