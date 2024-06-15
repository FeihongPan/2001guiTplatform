#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H

#include <QItemDelegate>
#include <QObject>

class ItemDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    static ItemDelegate *getInstance();

protected:
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
private:
    ItemDelegate(QObject *parent = nullptr);
    static ItemDelegate *self;
};

#endif // ITEMDELEGATE_H
