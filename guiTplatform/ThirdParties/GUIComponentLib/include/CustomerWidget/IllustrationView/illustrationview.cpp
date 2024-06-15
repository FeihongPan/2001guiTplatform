#include "illustrationview.h"
#include "ui_illustrationview.h"
#include <QPainter>

IllustrationView::IllustrationView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IllustrationView)
{
    ui->setupUi(this);
}

IllustrationView::~IllustrationView()
{
    delete ui;
}

void IllustrationView::paintEvent(QPaintEvent *event)
{
    int width = this->width();
    int height = this->height();
    mSize = qMin(width, height);
    mSize = 0.7*mSize;
    centerX = width/2;
    centerY = height/2;

    drawBackground();
    bool hasDrawShape = drawShape();
    if(!hasDrawShape)
    {
        return;
    }

    if(m_mode == Leveling)
    {
        drawLeveling();
    }
    if(m_mode == AlignMent)
    {
        drawAlignment();
    }
    if(m_mode == Exposure)
    {
        drawExposure();
    }
}

void IllustrationView::drawBackground()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen;
    pen.setColor(QColor(255,255,255,255));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(Qt::white);
    painter.drawRect(this->rect());
    painter.restore();
}

bool IllustrationView::drawShape()
{
    bool hasDrawShape = false;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen;
    pen.setColor(QColor(0,160,255,255));
    pen.setWidth(2);
    painter.setPen(pen);

    if(m_shape == Rect && m_width>0 && m_height>0)
    {
        double k = (double)m_width/m_height;
        int w = mSize*k;
        int h = mSize;
        m_k= (double)mSize/m_height;
        if(k>1)
        {
            w = mSize;
            h = mSize/k;
            m_k = (double)mSize/m_width;
        }
        painter.drawRect(centerX-w/2, centerY-h/2, w, h);
        painter.drawLine(QLine(QPoint(centerX-10, centerY), QPoint(centerX+10, centerY)));
        painter.drawLine(QLine(QPoint(centerX, centerY-10), QPoint(centerX, centerY+10)));
        hasDrawShape = true;
    }
    else if(m_shape == Round && m_radius>0)
    {
        m_k = (double)mSize/m_radius;
        painter.drawEllipse(centerX-mSize/2, centerY-mSize/2, mSize, mSize);
        painter.drawLine(QLine(QPoint(centerX-10, centerY), QPoint(centerX+10, centerY)));
        painter.drawLine(QLine(QPoint(centerX, centerY-10), QPoint(centerX, centerY+10)));
        hasDrawShape = true;
    }
    painter.restore();
    return hasDrawShape;
}

void IllustrationView::drawLeveling()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen;
    pen.setColor(QColor(100,100,100));
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
            painter.drawEllipse(centerX+x*m_k-2,centerY+y*m_k-2,4,4);

            QString str = QString("P%3(%1,%2)").arg(x).arg(-y).arg(i+1);
            painter.drawText(centerX+x*m_k+2, centerY+y*m_k-2, str);
        }
    }
    painter.restore();
}

void IllustrationView::drawAlignment()
{
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

void IllustrationView::drawExposure()
{


}

IllustrationView::Shape IllustrationView::getShape()
{
    return this->m_shape;
}

int IllustrationView::getWidth()
{
    return this->m_width;
}

int IllustrationView::getHeight()
{
    return this->m_height;
}

int IllustrationView::getRadius()
{
    return this->m_radius;
}

IllustrationView::Mode IllustrationView::getMode()
{
    return this->m_mode;
}

void IllustrationView::setShape(Shape shape)
{
    this->m_shape = shape;
}

void IllustrationView::setWidth(int width)
{
    this->m_width = width;
}

void IllustrationView::setHeight(int height)
{
    this->m_height = height;
}

void IllustrationView::setRadius(int ra)
{
    this->m_radius = ra;
}

void IllustrationView::setMode(Mode mode)
{
    this->m_mode = mode;
}

void IllustrationView::setFocAndLelPoints(QList<QPointF> lst_Points)
{
    this->lst_FocAndLelPoints = lst_Points;
}

QList<QPointF> IllustrationView::getFocAndLelPoints()
{
    return this->lst_FocAndLelPoints;
}

void IllustrationView::setFocAndLelColors(QList<QColor> lst_Colors)
{
    this->lst_FocAndLelColors = lst_Colors;
}

void IllustrationView::setAlignPoints(QList<QPointF> lst_Points)
{
    this->lst_AlignPoints = lst_Points;
}

void IllustrationView::setAlignColors(QList<QColor> lst_Colors)
{
    this->lst_AlignColors = lst_Colors;
}

void IllustrationView::setAlignScores(QList<int> lst_Scores)
{
    this->lst_AlignScore = lst_Scores;
}

QList<QColor> IllustrationView::getFocAndLelColors()
{
    return this->lst_FocAndLelColors;
}

QList<int> IllustrationView::getAlignScores()
{
    return this->lst_AlignScore;
}
