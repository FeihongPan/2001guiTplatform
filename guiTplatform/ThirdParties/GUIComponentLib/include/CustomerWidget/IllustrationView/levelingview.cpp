#include "levelingview.h"
#include "ui_levelingview.h"

#include <QPainter>

LevelingView::LevelingView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LevelingView)
{
    ui->setupUi(this);
}

LevelingView::~LevelingView()
{
    delete ui;
}

void LevelingView::setRadius(int radius)
{
    this->m_radius = radius;
}

void LevelingView::setFocAndLelPoints(QList<QPointF> lst_Points)
{
    this->lst_FocAndLelPoints = lst_Points;
}

void LevelingView::setFocAndLelColors(QList<QColor> lst_Colors)
{
    this->lst_FocAndLelColors = lst_Colors;
}

void LevelingView::setFocAndLelValues(QList<double> lst_Values)
{
    this->lst_FocAndLelValues = lst_Values;
}

void LevelingView::paintEvent(QPaintEvent *event)
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
    drawLeveling();
}

void LevelingView::drawShape()
{
    QPainterPath path1;
    QRectF rectf = QRectF(centerX - mSize / 2, centerY - mSize / 2, mSize, mSize);
    path1.addEllipse(rectf);

    QPainterPath path2;
    path2.moveTo(centerX - mSize / 2, centerY - mSize / 2);
    path2.lineTo(centerX + mSize / 2+2, centerY - mSize / 2);
    path2.lineTo(centerX + mSize / 2+2, centerY - mSize / 2 + 0.999 * mSize);
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

void LevelingView::drawLeveling()
{
    if(m_k == -1)
        return;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen;
    pen.setColor(QColor(255,0,255,255));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setFont(QFont("HarmonyOS",9));

    if(lst_FocAndLelPoints.size() == lst_FocAndLelColors.size())
    {
        for (int i=0; i<lst_FocAndLelPoints.size(); i++)
        {
            QColor color = lst_FocAndLelColors.at(i);
            pen.setColor(color);
            painter.setPen(pen);
            painter.setBrush(color);
            int x = lst_FocAndLelPoints.at(i).x();
            int y = -lst_FocAndLelPoints.at(i).y();
            painter.drawEllipse(centerX+x*m_k-3,centerY+y*m_k-3,6,6);

            QString str = QString("P%3(%1,%2)").arg(x).arg(-y).arg(i+1);
            painter.drawText(centerX+x*m_k+3, centerY+y*m_k-3, str);
        }
    }
    painter.restore();
}
