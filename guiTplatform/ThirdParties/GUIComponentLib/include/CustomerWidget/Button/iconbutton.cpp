#include "iconbutton.h"
//#include "iconfontmanager.h"

#include <QDebug>
#include <QVBoxLayout>
#include <QMetaEnum>
IconButton::IconButton(QWidget *parent) : EffectButton(parent)
{
    lbl_Icon = new QLabel(this);
    lbl_Text = new QLabel(this);

    //    setStyleSheet("QPushButton{background-color:#FFFFFF; border-style:none; border-radius:10px;}");
    //    setStyleSheet("QPushButton{background-color:#FFFFFF; border-style:none; border-radius:10px;}""QLabel{background-color:transparent;}");

    dic_ContextColor.insert(Status::Normal, "#808080");
    dic_ContextColor.insert(Status::Pressed, "#4C70FA");
    dic_ContextColor.insert(Status::Hover, "#A4B7FF");
    dic_ContextColor.insert(Status::Disabled, "#D8D8D8");
    SetColor(dic_ContextColor[Status::Normal]);
}

IconButton::~IconButton()
{
    if(lbl_Icon != NULL)
    {
        lbl_Icon->deleteLater();
        lbl_Icon = NULL;
    }
    if(lbl_Text != NULL)
    {
        lbl_Text->deleteLater();
        lbl_Text = NULL;
    }
}

void IconButton::SetIconStyle(QFont font, QString icon, int iconSzie, QFont::Weight weight)
{
    Q_UNUSED(weight)
    QFont ft = font;
    ft.setPointSize(iconSzie);
    lbl_Icon->setFont(ft);
    lbl_Icon->setText(icon);
    lbl_Icon->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addStretch();
    layout->addWidget(lbl_Icon);
    layout->addStretch();
    layout->setSpacing(5);
    this->setLayout(layout);
}

void IconButton::SetVertivalStyle(QFont font, QString icon, int iconSzie, QString text, int textSize, QFont::Weight weight)
{
    QFont ft = font;
    ft.setPointSize(iconSzie);
    lbl_Icon->setFont(ft);
    lbl_Icon->setText(icon);
    lbl_Icon->setAlignment(Qt::AlignCenter);

    ft.setPointSize(textSize);
    ft.setWeight(weight);
    lbl_Text->setFont(ft);
    lbl_Text->setText(text);
    lbl_Text->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addStretch();
    layout->addWidget(lbl_Icon);
    layout->addWidget(lbl_Text);
    layout->addStretch();
    layout->setMargin(10);
    layout->setSpacing(10);
    this->setLayout(layout);
}

void IconButton::SetHorizontalStyle(QFont font, QString icon, int iconSzie, QString text, int textSize, QFont::Weight weight)
{
    QFont ft = font;
    ft.setPointSize(iconSzie);
    lbl_Icon->setFont(ft);
    lbl_Icon->setText(icon);
    lbl_Icon->setAlignment(Qt::AlignCenter);

    ft.setPointSize(textSize);
    ft.setWeight(weight);
    lbl_Text->setFont(ft);
    lbl_Text->setText(text);
    lbl_Text->setAlignment(Qt::AlignCenter);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addStretch();
    layout->addWidget(lbl_Icon);
    layout->addWidget(lbl_Text);
    layout->addStretch();
    layout->setSpacing(10);
    this->setLayout(layout);
}

void IconButton::SetText(QString text)
{
    this->lbl_Text->setText(text);
}

void IconButton::SetIcon(QFont font, QString icon)
{
    QFont ft = font;
    lbl_Icon->setFont(ft);
    lbl_Icon->setText(icon);
    lbl_Icon->setAlignment(Qt::AlignCenter);
}

void IconButton::SetColor(QString color)
{
    lbl_Icon->setStyleSheet("QLabel{color: " + color + ";}");
    lbl_Text->setStyleSheet("QLabel{color: " + color + ";}");
}

void IconButton::SetColor(Status status)
{
    lbl_Icon->setStyleSheet("QLabel{color: " + dic_ContextColor[status] + ";}");
    lbl_Text->setStyleSheet("QLabel{color: " + dic_ContextColor[status] + ";}");
}

void IconButton::SetFrontColor(QString normal, QString pressed, QString hover, QString disable)
{
    dic_ContextColor.insert(Status::Normal, normal);
    dic_ContextColor.insert(Status::Pressed, pressed);
    dic_ContextColor.insert(Status::Hover, hover);
    dic_ContextColor.insert(Status::Disabled, disable);
}

void IconButton::changeDisplayStatus()
{
    if(!isEnabled())
    {
        SetColor(Status::Disabled);
        setEffectStatus(Status::Disabled);
    }
    else if(this->isChecked() || isPressed)
    {
        SetColor(Status::Pressed);
        setEffectStatus(Status::Pressed);
    }
    else if(this->isHover)
    {
        SetColor(Status::Hover);
        setEffectStatus(Status::Hover);
    }
    else
    {
        SetColor(Status::Normal);
        setEffectStatus(Status::Normal);
    }
}


