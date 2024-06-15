#include "exposureview.h"
#include "ui_exposureview.h"

#include <QPainter>

ExposureView::ExposureView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExposureView)
{
    ui->setupUi(this);
}

ExposureView::~ExposureView()
{
    delete ui;
}

void ExposureView::paintEvent(QPaintEvent *event)
{
    int width = this->width();
    int height = this->height();
    mSize = qMin(width, height);
    mSize = 0.84 * mSize;
    if(m_radius!=0)
    {
        m_k = mSize/m_radius;
    }
    centerX = width / 2;
    centerY = height / 2;

    drawShape();
    drawExposure();
}

void ExposureView::drawShape()
{
    QPainterPath path1;
    QRectF rectf = QRectF(centerX - mSize / 2, centerY - mSize / 2, mSize, mSize);
    path1.addEllipse(rectf);

    QPainterPath path2;
    path2.moveTo(centerX - mSize / 2, centerY - mSize / 2);
    path2.lineTo(centerX + mSize / 2, centerY - mSize / 2);
    path2.lineTo(centerX + mSize / 2, centerY - mSize / 2 + 0.999 * mSize);
    path2.lineTo(centerX + 5, centerY - mSize / 2 + 0.999 * mSize);
    path2.cubicTo(QPointF(centerX + 5, centerY - mSize / 2 + 0.999 * mSize),
                  QPointF(centerX, centerY - mSize / 2 + 0.97 * mSize),
                  QPointF(centerX - 5, centerY - mSize / 2 + 0.999 * mSize));
    path2.lineTo(centerX - 5, centerY - mSize / 2 + 0.999 * mSize);
    path2.lineTo(centerX - mSize / 2, centerY - mSize / 2 + 0.999 * mSize);
    path2.lineTo(centerX - mSize / 2, centerY - mSize / 2);
    path2.closeSubpath();

    QPainterPath path = path1.intersected(path2);
    QPainter painter(this);
    QColor color = QColor(255, 255, 255, 255);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen;
    pen.setColor(QColor(255, 0, 255, 255));
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

void ExposureView::drawExposure()
{

}

