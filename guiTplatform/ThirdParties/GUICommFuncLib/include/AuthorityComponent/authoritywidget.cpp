#include "authoritywidget.h"
#include "AppConfig/AppParameter.h"
#include "Communication/MQTT/mqttclientmanager.h"

#include <QDebug>

AuthorityWidget::AuthorityWidget(QString name, QWidget *parent) : BindableWidget(name, parent)
{
    this->wdgInfo = new AuthorityWdgInfo();
    this->wdgInfo->wdgName = name;
    connect(this, &AuthorityWidget::MachineStateChanged, this, &AuthorityWidget::RecivedMachineState);
}

void AuthorityWidget::SetWdgStatus(ViewStatus::Status status)
{
    this->status = status;
    emit ViewStatusChanged(this->status);
}

void AuthorityWidget::ItemInitialize(bool left)
{
    layoutInitial(left);
    ItemInitialize();
}

void AuthorityWidget::ItemInitialize()
{
    qDebug() << this->name << "AuthorityWidget::ItemInitialize()";
    setWidgets();
    setWidgetStyleSheet();
    setLanguageKeys();
    setConnections();
}

void AuthorityWidget::SetMachineState(int state)
{
    this->m_MachineState = state;
}

void AuthorityWidget::setLayoutWidgets(QHBoxLayout *layout, QStackedWidget *stackWidget, QFrame *frame_SubNavi)
{
    this->layout = layout;
    this->stackWidget = stackWidget;
    this->frame_SubNavi = frame_SubNavi;
}

void AuthorityWidget::RecivedViewStatus(ViewStatus::Status status)
{
    emit ViewStatusChanged(status);
}

void AuthorityWidget::layoutInitial(bool leftSide)
{
    try
    {
        if(leftSide && this->layout != NULL && this->stackWidget != NULL && this->frame_SubNavi != NULL)
        {
            this->layout->removeWidget(this->frame_SubNavi);
            this->layout->removeWidget(this->stackWidget);
            this->layout->addWidget(this->frame_SubNavi);
            this->layout->addWidget(this->stackWidget);
        }
    }
    catch (...)
    {

    }
}

void AuthorityWidget::PublisherInitialize()
{
    m_Publisher.LinkToClient(MqttClientManager::getInstance()->GetClient(0), PublishTopicPrefix);
}
