#include "alignerview.h"
#include "ui_alignerview.h"

#include <QPainter>

AlignerView::AlignerView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlignerView)
{
    ui->setupUi(this);
}

AlignerView::~AlignerView()
{
    delete ui;
}

void AlignerView::setRadius(int radius)
{
    this->m_radius = radius;
}

void AlignerView::setAlignPoints(QList<QPointF> lst_Points)
{
    this->lst_AlignPoints = lst_Points;
}

void AlignerView::setAlignColors(QList<QColor> lst_Colors)
{
    this->lst_AlignColors = lst_Colors;
}

void AlignerView::setAlignScores(QList<int> lst_Scores)
{
    this->lst_AlignScore = lst_Scores;
}

void AlignerView::paintEvent(QPaintEvent *event)
{
    int width = this->width();
    int height = this->height();
    mSize = qMin(width, height);
    mSize = 0.84 * mSize;
    m_k = -1;
    if(m_radius!=0)
    {
        m_k = mSize/m_radius;
    }

    centerX = width / 2;
    centerY = height / 2;

    drawShape();
    drawAlignment();
}

void AlignerView::clearDraw()
{
    QPainter painter(this);
    QColor color = QColor(255, 255, 255, 255);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen;
    pen.setColor(QColor(255, 255, 255, 255));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(color);
    painter.drawRect(0,0,width(), height());
}

void AlignerView::drawShape()
{
    QPainterPath path1;
    QRectF rectf = QRectF(centerX - mSize / 2, centerY - mSize / 2, mSize, mSize);
    path1.addEllipse(rectf);

    QPainterPath path2;
    path2.moveTo(centerX - mSize / 2, centerY - mSize / 2);
    path2.lineTo(centerX + mSize / 2, centerY - mSize / 2);
    path2.lineTo(centerX + mSize / 2, centerY - mSize / 2 + 0.999 * mSize);
    path2.lineTo(centerX + mSize*0.03, centerY - mSize / 2 + 0.999 * mSize);
    path2.cubicTo(QPointF(centerX + mSize*0.03, centerY - mSize / 2 + 0.999 * mSize),
                  QPointF(centerX, centerY - mSize / 2 + 0.97 * mSize),
                  QPointF(centerX - mSize*0.03, centerY - mSize / 2 + 0.999 * mSize));
    path2.lineTo(centerX - mSize*0.03, centerY - mSize / 2 + 0.999 * mSize);
    path2.lineTo(centerX - mSize / 2, centerY - mSize / 2 + 0.999 * mSize);
    path2.lineTo(centerX - mSize / 2, centerY - mSize / 2);
    path2.closeSubpath();

    QPainterPath path = path1.intersected(path2);
    QPainter painter(this);
    QColor color = QColor(255, 255, 255, 255);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen;
    pen.setColor(QColor(0, 160, 255, 255));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(color);
    painter.drawPath(path);

    painter.drawLine(QPointF(centerX - mSize*0.06, centerY), QPointF(centerX + mSize*0.06, centerY));
    painter.drawLine(QPointF(centerX, centerY - mSize*0.06), QPointF(centerX, centerY + mSize*0.06));

    pen.setColor(QColor(0, 0, 0, 255));
    painter.setPen(pen);
    painter.setFont(QFont("HarmonyOS",10));
    painter.drawText(QPointF(centerX - mSize / 2-mSize*0.12, centerY+mSize*0.02),"-X");
    painter.drawText(QPointF(centerX + mSize / 2+mSize*0.04, centerY+mSize*0.02),"+X");
    painter.drawText(QPointF(centerX-mSize*0.04, centerY-mSize/2-mSize*0.03),"-Y");
    painter.drawText(QPointF(centerX-mSize*0.04, centerY+mSize/2+mSize*0.09),"+Y");
    painter.restore();
}

void AlignerView::drawAlignment()
{
    if(m_k == -1)
    {
        update();
        return;
    }

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen;
    pen.setColor(QColor(255,0,255,255));
    pen.setWidth(1);
    painter.setPen(pen);
    painter.setFont(QFont("HarmonyOS",9));

    if(lst_AlignPoints.size() == lst_AlignColors.size())
    {
        for (int i=0; i<lst_AlignPoints.size(); i++)
        {
            QColor color = lst_AlignColors.at(i);
            pen.setColor(color);
            painter.setPen(pen);
            painter.setBrush(color);
            int x = lst_AlignPoints.at(i).x();
            int y = -lst_AlignPoints.at(i).y();

            painter.drawLine(QLineF(QPointF(centerX+x*m_k-5, centerY+y*m_k), QPointF(centerX+x*m_k+5, centerY+y*m_k)));
            painter.drawLine(QLineF(QPointF(centerX+x*m_k, centerY+y*m_k-5), QPointF(centerX+x*m_k, centerY+y*m_k+5)));

            QString str = QString("P%3(%1,%2)").arg(x).arg(-y).arg(i+1);
            painter.drawText(centerX+x*m_k+5, centerY+y*m_k-5, str);
        }
    }
    painter.restore();
}

