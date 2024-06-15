#pragma execution_character_set("utf-8")
#include "switchbutton.h"
#include <QPainter>

#include <QDebug>

SwitchButton::SwitchButton(QWidget *parent) : QWidget(parent)
{
    m_space = 4;
    m_radius = 5;
    m_checked = false;
    m_showText = true;
    m_showText = false;
    m_animation = true;

//    m_bgColorOn = QColor(21, 156, 119);
//    m_bgColorOff = QColor(111, 122, 126);
//    m_bgColorOff = QColor(240, 240, 240);

    m_bgColorOn = QColor(115, 143, 253);
    m_bgColorOff = QColor(230, 230, 230);
    m_bgColorOff = QColor(230, 230, 230);

    m_sliderColorOn = QColor(255, 255, 255);
    m_sliderColorOff = QColor(255, 255, 255);

    m_textColor = QColor(0, 0, 0);

    m_textOn = "ON";
    m_textOff = "OFF";

    m_step = 0;
    m_startX = 0;
    m_endX = 0;

    m_timer = new QTimer(this);
    m_timer->setInterval(30);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(UpdateValue()));

    m_timerStatus = new QTimer(this);
    m_timerStatus->setInterval(1000);
    connect(m_timerStatus, &QTimer::timeout, this, &SwitchButton::on_Enable);
}


void SwitchButton::drawBackGround(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    QColor bgColor = m_checked ? m_bgColorOn : m_bgColorOff;

    QRect rect(0, 0, width(), height());
    int side = qMin(width(), height());
    m_space = side*0.1;
    int max = qMax(width(), height());
    if(1.6*side <= max)
    {
        m_zoom = true;
    }

    QPainterPath path0;
    path0.addRoundRect(rect.x(), rect.y(), rect.width(), rect.height(), side/3);

    QPainterPath path1;
    path1.addRoundRect(rect.x()+1, rect.y()+1, rect.width()-2, rect.height()-2, side/3-1);

    painter->setBrush(m_bgColorOn);
    painter->drawPath(path0);
    if (isEnabled()) {
        bgColor.setAlpha(255);
    }
    painter->setBrush(bgColor);
    painter->drawPath(path1);
    painter->restore();
}

void SwitchButton::drawSlider(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    QColor color = m_checked ? m_sliderColorOn : m_sliderColorOff;
    painter->setBrush(QBrush(color));

    int sliderWidth = qMin(width(), height()) - m_space * 2;
    QRect rect(m_space + m_startX, m_space, sliderWidth*1.6, sliderWidth);

    //painter->drawEllipse(rect);
    painter->drawRoundRect(rect, 10);

    //滑块半径
    QRect textRect(m_space + m_startX, m_space, sliderWidth*1.6, sliderWidth);
    painter->setFont(QFont("黑体",11));
    painter->setPen(QPen(m_textColor));
    if (m_checked)
    {

        painter->drawText(textRect, Qt::AlignCenter, m_textOn);
    }
    else
    {
        painter->drawText(textRect, Qt::AlignCenter, m_textOff);
    }
    painter->restore();
}

void SwitchButton::paintEvent(QPaintEvent *ev)
{
    //启用反锯齿
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    //绘制背景
    drawBackGround(&painter);

    //绘制滑块
    drawSlider(&painter);
}

void SwitchButton::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)

    m_checked = !m_checked;
    emit statusChanged(m_checked);
    enable = false;
    m_timerStatus->start();

    //计算步长
    m_step = width() / 10;

    //计算滑块X轴终点坐标
    if (m_checked) {
        int sliderWidth = qMin(width(), height()) - m_space * 2;
        m_endX = (width()-2*m_space) - 1.6*sliderWidth;
    } else {
        m_endX = 0;
    }

    //判断是否使用动画
    if (m_animation) {
        m_timer->start();
    } else{
        m_startX = m_endX;
        update();
    }
}

void SwitchButton::UpdateValue()
{
    if (m_checked) {
        if (m_startX < m_endX) {
            m_startX += m_step;
        } else {
            m_startX = m_endX;
            m_timer->stop();
        }
    } else {
        if (m_startX > m_endX) {
            m_startX -= m_step;
        } else {
            m_startX = m_endX;
            m_timer->stop();
        }
    }

    update();
}

void SwitchButton::on_Enable()
{
    enable = true;
}

int SwitchButton::space() const
{
    return m_space;
}

int SwitchButton::radius() const
{
    return m_radius;
}

bool SwitchButton::checked() const
{
    return m_checked;
}

bool SwitchButton::showText() const
{
    return m_showText;
}

bool SwitchButton::showCircle() const
{
    return m_showCircle;
}

bool SwitchButton::animation() const
{
    return m_animation;
}

QColor SwitchButton::bgColorOn() const
{
    return m_bgColorOn;
}

QColor SwitchButton::bgColorOff() const
{
    return m_bgColorOff;
}

QColor SwitchButton::sliderColorOn() const
{
    return m_sliderColorOn;
}

QColor SwitchButton::sliderColorOff() const
{
    return m_sliderColorOff;
}

QColor SwitchButton::textColor() const
{
    return m_textColor;
}

QString SwitchButton::textOn() const
{
    return m_textOn;
}

QString SwitchButton::textOff() const
{
    return m_textOff;
}

int SwitchButton::step() const
{
    return m_step;
}

int SwitchButton::startX() const
{
    return m_startX;
}

int SwitchButton::endX() const
{
    return m_endX;
}

void SwitchButton::setSpace(int space)
{
    if (m_space != space) {
        m_space = space;
        update();
    }
}

void SwitchButton::setRadius(int radius)
{
    if (m_radius != radius)
    {
        m_radius = radius;
        update();
    }
}

void SwitchButton::setChecked(bool checked)
{
    if(!enable)
    {
        return;
    }

    if (m_checked != checked)
    {
        m_checked = checked;

        //计算步长
        m_step = width() / 10;
        //计算滑块X轴终点坐标
        if (m_checked)
        {
            int sliderWidth = qMin(width(), height()) - m_space * 2;
            m_endX = (width()-2*m_space) - 1.6*sliderWidth;
        }
        else
        {
            m_endX = 0;
        }
        //判断是否使用动画
        if (m_animation)
        {
            m_timer->start();
        }
        else
        {
            m_startX = m_endX;
            update();
        }
        update();
    }
}

void SwitchButton::setShowText(bool show)
{
    if (m_showText != show) {
        m_showText = show;
        update();
    }
}

void SwitchButton::setShowCircle(bool show)
{
    if (m_showCircle != show) {
        m_showCircle = show;
        update();
    }
}

void SwitchButton::setAnimation(bool ok)
{
    if (m_animation != ok) {
        m_animation = ok;
        update();
    }
}

void SwitchButton::setBgColorOn(const QColor &color)
{
    if (m_bgColorOn != color) {
        m_bgColorOn = color;
        update();
    }
}

void SwitchButton::setBgColorOff(const QColor &color)
{
    if (m_bgColorOff != color) {
        m_bgColorOff = color;
        update();
    }
}

void SwitchButton::setSliderColorOn(const QColor &color)
{
    if (m_sliderColorOn != color) {
        m_sliderColorOn = color;
        update();
    }
}

void SwitchButton::setSliderColorOff(const QColor &color)
{
    if (m_sliderColorOff != color) {
        m_sliderColorOff = color;
        update();
    }
}

void SwitchButton::setTextColor(const QColor &color)
{
    if (m_textColor != color) {
        m_textColor = color;
        update();
    }
}

void SwitchButton::setTextOn(const QString &text)
{
    if (m_textOn != text) {
        m_textOn = text;
        update();
    }
}

void SwitchButton::setTextOff(const QString &text)
{
    if (m_textOff != text) {
        m_textOff = text;
        update();
    }
}

//void SwitchButton::setStep(int step)
//{
//    if (m_step != step) {
//        m_step = step;
//        update();
//    }
//}

//void SwitchButton::setStartX(int startX)
//{

//}

//void SwitchButton::setEndX(int endX)
//{

//}
