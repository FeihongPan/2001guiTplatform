#ifndef ITEMDELEGATE_MC_H
#define ITEMDELEGATE_MC_H

#include "GUIFramework_global.h"

#include <QItemDelegate>
#include <QStyledItemDelegate>
#include <QObject>

class GUIFRAMEWORK_EXPORT ItemDelegate_MC : public QStyledItemDelegate
{
    Q_OBJECT
public:
    ItemDelegate_MC(QObject *parent = nullptr);
    static ItemDelegate_MC *getInstance();

protected:
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
private:
    static ItemDelegate_MC *self;
};

#endif // ITEMDELEGATE_MC_H
