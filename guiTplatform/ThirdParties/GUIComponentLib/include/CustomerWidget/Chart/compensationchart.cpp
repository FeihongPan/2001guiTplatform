#include "compensationchart.h"

CompensationChart::CompensationChart(QWidget *parent) : QCustomPlot(parent)
{
    this->addLayer("abovemain", this->layer("main"), QCustomPlot::limAbove);
    this->addLayer("belowmain", this->layer("main"), QCustomPlot::limBelow);

    ft.setFamily("黑体");
    ft.setPointSize(12);
}

void CompensationChart::updateView(QList<CompData> lst_Line)
{
    this->m_lst_Point = lst_Line;

    clearView();
    if(lst_Line.size()==0)
    {
        this->replot();
        return;
    }

    double xMin;
    double xMax;
    double yMin;
    double yMax;
    for(int i=0; i<lst_Line.size(); i++)
    {
        QString objName = lst_Line.at(i).name;
        QPointF pointStart = lst_Line.at(i).pointStart;
        QPointF pointEnd = lst_Line.at(i).pointEnd;
        if(i==0)
        {
            xMin = qMin(pointStart.x(), pointEnd.x());
            xMax = qMax(pointStart.x(), pointEnd.x());
            yMin = qMin(pointStart.y(), pointEnd.y());
            yMax = qMax(pointStart.y(), pointEnd.y());
        }
        else
        {
            xMin = qMin(xMin, pointStart.x());
            xMin = qMin(xMin, pointEnd.x());
            xMax = qMax(xMax, pointStart.x());
            xMax = qMax(xMax, pointEnd.x());

            yMin = qMin(yMin, pointStart.y());
            yMin = qMin(yMin, pointEnd.y());
            yMax = qMax(yMax, pointStart.y());
            yMax = qMax(yMax, pointEnd.y());
        }

        QCPItemText *text = new QCPItemText(this);
        text->setObjectName(objName);
        text->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
        text->position->setCoords(pointStart);
        QString str = QString("(%1,%2,%3,%4)").arg(pointStart.x()).arg(pointStart.y())
                                            .arg(pointEnd.x()-pointStart.x()).arg(pointEnd.y()-pointStart.y());
        text->setText(str);
        text->setFont(QFont("黑体",12));
        text->setPen(QPen(QColor(240,240,240,0)));
        text->setLayer("abovemain");

        QCPItemLine *arrow = new QCPItemLine(this);
        arrow->start->setCoords(pointStart.x(), pointStart.y()); //设置直线终点为坐标系中的点
        arrow->end->setCoords(pointEnd.x(), pointEnd.y()); //设置直线终点为坐标系中的点
        arrow->setHead(QCPLineEnding::esSpikeArrow);//设置箭头类型（三角形、菱形、方形等）
        arrow->setPen(QPen(QColor(120, 120, 120), 4));
        arrow->setLayer("abovemain");
    }

    this->xAxis->setLabelFont(ft);
    this->yAxis->setLabelFont(ft);
    this->xAxis->setTickLabelFont(ft);
    this->yAxis->setTickLabelFont(ft);

    double diffY = yMax-yMin;
    double diffX = xMax-xMin;
    if(diffY*factory >= diffX)
    {
        diffY= diffY*0.55;
        diffX = diffY*factory;
    }
    else
    {
        diffX = diffX*0.55;
        diffY = diffX/factory;
    }

    //设置坐标轴范围
    double centerX = (xMax+xMin)/2;
    double centerY = (yMax+yMin)/2;
    double diff = qMax(xMax-xMin, (yMax-yMin)*factory);
    double rate= diff/10;
    if(rate!=0)
    {
        this->xAxis->setRange(centerX-diffX, centerX+diffX);
        this->yAxis->setRange(centerY-diffY, centerY+diffY);
    }
    else
    {
        this->yAxis->setRange(xMin, xMin*2,Qt::AlignCenter);
        this->yAxis->setRange(yMin, yMin*2,Qt::AlignCenter);
    }
//    this->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
//    this->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    this->replot();
    this->xRange=this->xAxis->range();
    this->yRange=this->yAxis->range();
    connect(this, &QCustomPlot::itemClick, this, &CompensationChart::ItemClicked, Qt::UniqueConnection);
}

void CompensationChart::setXYFactory(double factory)
{
    this->factory = factory;
}

void CompensationChart::clearView()
{
    clearItems();
    clearGraphs();
    clearFocus();
}

void CompensationChart::ItemClicked(QCPAbstractItem *item, QMouseEvent *event)
{
    if(item->objectName().isEmpty())
    {
        return;
    }
    emit Sig_ItemClicked(item->objectName());
}
