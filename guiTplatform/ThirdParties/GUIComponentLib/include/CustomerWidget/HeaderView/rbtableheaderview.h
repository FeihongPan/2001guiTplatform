#ifndef RBTABLEHEADERVIEW_H
#define RBTABLEHEADERVIEW_H



#ifndef RBTABLEHEADERVIEW_H_
#define RBTABLEHEADERVIEW_H_
#include <QHeaderView>
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QHash>
#include <QPair>
#include "GUIComponentLib_global.h"

class QHeaderViewPrivate;

enum eRbHeaderRole
{
    COLUMN_SPAN_ROLE = Qt::UserRole + 1,
    ROW_SPAN_ROLE,
    COLUMN_SIZE_ROLE,
    ROW_SIZE_ROLE,
};

class RbTableHeaderItem
{
public:
    RbTableHeaderItem(RbTableHeaderItem* parent = nullptr);
    RbTableHeaderItem(int arow, int acolumn, RbTableHeaderItem* parent = 0);
    virtual ~RbTableHeaderItem();

    // interface
    RbTableHeaderItem* insertChild(int row, int col);
    const RbTableHeaderItem* child(int row, int col) const;
    RbTableHeaderItem* child(int row, int col);
    void setData(const QVariant& data, int role);
    QVariant data(int role = Qt::UserRole + 1) const;
    inline int column() const { return column_prop; }
    inline int row() const { return row_prop; }
    RbTableHeaderItem* parent() { return parent_item; }
    void setText(const QString& text);
    void clear();

private:
    // properties
    int row_prop;                                              //当前表格在表头中所在行
    int column_prop;                                           //当前表格在表头中所在行
    // inherent features
    RbTableHeaderItem* parent_item;
    QHash<QPair<int, int>, RbTableHeaderItem*> child_items;
    QHash<int, QVariant> role_datas;                           //
};


class RbTableHeaderModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    RbTableHeaderModel(int rows, int cols, QObject* parent = 0);
    virtual ~RbTableHeaderModel();

public:
    // override
    virtual QModelIndex index(int row, int column, const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE { Q_UNUSED(parent); return row_count_prop; }
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE { Q_UNUSED(parent); return column_count_prop; }
    virtual QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    virtual bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) Q_DECL_OVERRIDE;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

private:
    // properties
    int row_count_prop;                    //表头行总数
    int column_count_prop;                 //表头列总数
    // inherent features
    RbTableHeaderItem* root_item;          //表头视图模型的根节点
};


class GUICOMPONENTLIB_EXPORT RbTableHeaderView : public QHeaderView
{
    Q_OBJECT
public:
    RbTableHeaderView(Qt::Orientation orientation, int rows, int columns, QWidget* parent = 0);
    virtual ~RbTableHeaderView();

    void setRowHeight(int row, int rowHeight);
    void setColumnWidth(int col, int colWidth);
    void setSpan(int row, int column, int rowSpanCount, int columnSpanCount);
    void setCellBackgroundColor(const QModelIndex& index, const QColor&);
    void setCellForegroundColor(const QModelIndex& index, const QColor&);

protected:
    // override
//    virtual bool event(QEvent *e) override;
//    virtual void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    virtual QModelIndex indexAt(const QPoint&);
    virtual void paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const Q_DECL_OVERRIDE;
    virtual QSize sectionSizeFromContents(int logicalIndex) const Q_DECL_OVERRIDE;

    // inherent features
    QModelIndex columnSpanIndex(const QModelIndex& currentIndex) const;
    QModelIndex rowSpanIndex(const QModelIndex& currentIndex) const;
    int columnSpanSize(int row, int from, int spanCount) const;
    int rowSpanSize(int column, int from, int spanCount) const;
    int getSectionRange(QModelIndex& index, int* beginSection, int* endSection) const;

protected slots:
    void onSectionResized(int logicalIdx, int oldSize, int newSize);

private:
    int pressed;
    int hover;

signals:
    void sectionPressed(int from, int to);
};

#endif /* RBTABLEHEADERVIEW_H_ */


#endif // RBTABLEHEADERVIEW_H
