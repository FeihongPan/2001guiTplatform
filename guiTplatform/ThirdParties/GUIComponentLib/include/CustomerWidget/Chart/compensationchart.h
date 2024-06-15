#ifndef COMPENSATIONCHART_H
#define COMPENSATIONCHART_H
#include "qcustomplot.h"
#include "GUIComponentLib_global.h"

#include <QObject>

class QCP_LIB_DECL CompensationChart : public QCustomPlot
{
    Q_OBJECT

public:
    typedef struct _CompData
    {
        QString name;            ///矢量数据名称
        QPointF pointStart;      ///矢量数据起始位置
        QPointF pointEnd;        ///矢量数据终止位置
    }CompData;

    explicit CompensationChart(QWidget *parent = nullptr);
    void updateView(QList<CompData> lst_Line);   ///更新矢量数据
    void setXYFactory(double factory);           ///设置宽高比例
private:
    void clearView();                            ///清空视图

private slots:
    void ItemClicked(QCPAbstractItem *item, QMouseEvent *event);

private:
    QList<CompData> m_lst_Point;
    QList<QCPGraph *> m_lst_Line;
    QCPRange xRange;
    QCPRange yRange;
    double factory{1};
    QFont ft;

signals:
    void Sig_ItemClicked(QString objName);
};

#endif // COMPENSATIONCHART_H
