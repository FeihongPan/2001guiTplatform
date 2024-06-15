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
        QString name;            ///ʸ����������
        QPointF pointStart;      ///ʸ��������ʼλ��
        QPointF pointEnd;        ///ʸ��������ֹλ��
    }CompData;

    explicit CompensationChart(QWidget *parent = nullptr);
    void updateView(QList<CompData> lst_Line);   ///����ʸ������
    void setXYFactory(double factory);           ///���ÿ�߱���
private:
    void clearView();                            ///�����ͼ

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
