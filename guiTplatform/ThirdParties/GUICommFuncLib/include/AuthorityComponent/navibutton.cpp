#include "navibutton.h"

#include <QEvent>
#include <QDebug>
#include <QtConcurrent/QtConcurrent>

NaviButton::NaviButton(QWidget *parent) : IconButton(parent)
{
    this->setCheckable(true);
    timer = new SyncTimer();
    connect(timer, &SyncTimer::timeout, this, &NaviButton::showStatus);

    dicTwinklwColor.insert(ViewStatus::Status::Idle, "#808080");
    dicTwinklwColor.insert(ViewStatus::Status::Runing, "#35EF14");
    dicTwinklwColor.insert(ViewStatus::Status::Adding, "#EDAD16");
    dicTwinklwColor.insert(ViewStatus::Status::Modifying, "#EDAD16");
    dicTwinklwColor.insert(ViewStatus::Status::Alarm, "#FD6B6D");
}

NaviButton::~NaviButton()
{
    if(timer != NULL)
    {
        timer->stop();
        delete timer;
        timer = NULL;
    }

}

bool NaviButton::event(QEvent *e)
{
    switch (e->type())
    {
        case QEvent::HoverEnter:
            isHover = true;
            if(!timer->isActive())
            {
                changeDisplayStatus();
            }
            break;

        case QEvent::HoverLeave:
            isHover = false;
            if(!timer->isActive())
            {
                changeDisplayStatus();
            }
            break;

        case QEvent::EnabledChange:
            if(!timer->isActive())
            {
                changeDisplayStatus();
            }
            break;

        default:
            break;
    }
    return QWidget::event(e);
}

void NaviButton::setColor_Toggled(bool r)
{
    Q_UNUSED(r)
    if(!timer->isActive())
    {
        changeDisplayStatus();
    }
}

void NaviButton::setColor_Pressed()
{
    isPressed = true;
    if(!timer->isActive())
    {
        changeDisplayStatus();
    }
}

void NaviButton::setColor_Released()
{
    isPressed = false;
    if(!timer->isActive())
    {
        changeDisplayStatus();
    }
}

void NaviButton::RecivedViewStatus(ViewStatus::Status status)
{
    this->status = status;
    if(this->status != ViewStatus::Status::Idle)
    {
        twinkleColor = dicTwinklwColor[this->status];
        if(!timer->isActive())
        {
            timer->start(1000);
        }
    }
    else
    {
        timer->stop();
        changeDisplayStatus();
    }
}

void NaviButton::showStatus()
{
    bTwinkleOn = !bTwinkleOn;
    if(bTwinkleOn)
    {
        SetColor(twinkleColor);
    }
    else
    {
        changeDisplayStatus();
    }
}
