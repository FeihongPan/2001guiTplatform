#include "effectbutton.h"
#include <QEvent>
#include <QMetaEnum>
EffectButton::EffectButton(QWidget *parent) : QPushButton(parent)
{
    effect = new QGraphicsDropShadowEffect(this);
    this->setGraphicsEffect(effect);

    QMetaEnum metaEnum = QMetaEnum::fromType<Status>();
    for(int i = 0; i < metaEnum.keyCount(); i++)
    {
        dic_EffectInfos.insert(static_cast<Status>(metaEnum.keyToValue(metaEnum.key(i))), EffectInfo());
    }

    setEffectInfo(EffectButton::Normal,0,0,"#DEEEFF",6);
    setEffectInfo(EffectButton::Hover,0,0,"#FFFFFF",6);
    setEffectInfo(EffectButton::Pressed,0,0,"#FFFFFF",6);
    setEffectInfo(EffectButton::Disabled,0,0,"#D8D8D8",6);

    setEffectStatus(Status::Normal);

    connect(this,&QPushButton::toggled,this,&EffectButton::setColor_Toggled);
    connect(this,&QPushButton::pressed,this,&EffectButton::setColor_Pressed);
    connect(this,&QPushButton::released,this,&EffectButton::setColor_Released);
}

EffectButton::~EffectButton()
{
    if(effect != NULL)
    {
        effect->deleteLater();
        effect= NULL;
    }
}

bool EffectButton::event(QEvent *e)
{
    switch (e->type())
    {
    case QEvent::HoverEnter:
        isHover = true;
        changeDisplayStatus();
        break;

    case QEvent::HoverLeave:
        isHover = false;
        changeDisplayStatus();
        break;

    case QEvent::EnabledChange:
        changeDisplayStatus();
        break;

    default:
        break;
    }
    return QWidget::event(e);
}

void EffectButton::SetEffectInfo(Status status, int offset_x, int offset_y, QString color, int blur)
{
    setEffectInfo(status, offset_x, offset_y, color, blur);
    changeDisplayStatus();
}

void EffectButton::SetEffectStatus(bool on)
{
    bEffectOn = on;
    changeDisplayStatus();
}

void EffectButton::setColor_Toggled(bool r)
{
    Q_UNUSED(r)
    changeDisplayStatus();
}

void EffectButton::setColor_Pressed()
{
    isPressed = true;
    changeDisplayStatus();
}

void EffectButton::setColor_Released()
{
    isPressed = false;
    changeDisplayStatus();
}

void EffectButton::changeDisplayStatus()
{
    if(!isEnabled())
    {
       setEffectStatus(Status::Disabled);
    }
    else if(this->isChecked() || isPressed)
    {
        setEffectStatus(Status::Pressed);
    }
    else if(this->isHover)
    {
        setEffectStatus(Status::Hover);
    }
    else
    {
        setEffectStatus(Status::Normal);
    }
}

void EffectButton::setEffectStatus(Status status)
{
    if(bEffectOn)
    {
        effect->setOffset(dic_EffectInfos[status].offset.x(),dic_EffectInfos[status].offset.y());
        effect->setColor(dic_EffectInfos[status].color);
//        effect->setBlurRadius(dic_EffectInfos[status].blurRadius);
    }
    else
    {
        effect->setOffset(0,0);
        effect->setColor("#FFFFFF");
//        effect->setBlurRadius(1);
    }
}

void EffectButton::setEffectInfo(Status status, int offset_x, int offset_y, QString color, int blur)
{
    dic_EffectInfos[status].offset.setX(offset_x);
    dic_EffectInfos[status].offset.setX(offset_y);
    dic_EffectInfos[status].color = color;
    dic_EffectInfos[status].blurRadius = blur;
}
