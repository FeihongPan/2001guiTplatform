#include "iconlineedit.h"
#include "StyleSheet/stylesheet.h"
#include <QDebug>
IconLineEdit::IconLineEdit(QWidget *parent) : QLineEdit(parent)
{

    this->font = GlobalStyleSheet->Font();
    btn_Icon = new QPushButton(this);
    btn_Icon->setFixedSize(this->height() - 4, this->height() - 4);
    btn_Icon->setStyleSheet(GlobalStyleSheet->ButtonStyle_Front);

    this->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);

    this->font.setPointSize(size);
    btn_Icon->setFont(this->font);
    btn_Icon->setText(icon);

    layout = new QHBoxLayout();
    layout->setContentsMargins(10,2,10,2);

    layout->addWidget(btn_Icon);
    layout->addStretch();
    layout->setSpacing(5);
    this->setLayout(layout);

    connect(btn_Icon, &QPushButton::clicked, this, [=]{emit iconClicked(this->text());});
    connect(btn_Icon, &QPushButton::pressed, this, [=]{emit iconPressed();});
    connect(btn_Icon, &QPushButton::released, this, [=]{emit iconReleased();});
}

bool IconLineEdit::event(QEvent *e)
{
    switch (e->type())
    {
    case QEvent::EnabledChange:
        btn_Icon->setEnabled(this->isEnabled());
        break;

    default:
        break;
    }
    return QWidget::event(e);
}

void IconLineEdit::SetIconFont(QFont font)
{
    this->font = font;
}

void IconLineEdit::SetIcon(QString icon, int size)
{
    this->font.setPointSize(size);
    btn_Icon->setFont(this->font);
    btn_Icon->setText(icon);
}

void IconLineEdit::SetIconDock(Dock dock)
{
//    if(layout !=NULL)
//    {
//        delete layout;
//        layout = NULL;
//    }

//    layout = new QHBoxLayout();

    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != 0) {
//        item->widget()->setParent(nullptr);
//        delete item;
    }

    if(dock == Dock::Left)
    {
        layout->addWidget(btn_Icon);
        layout->addStretch();
        this->setLayout(layout);
    }
    else
    {
        layout->addStretch();
        layout->addWidget(btn_Icon);
        this->setLayout(layout);
    }
}

QPushButton * IconLineEdit::GetIconButton()
{
    return btn_Icon;
}
