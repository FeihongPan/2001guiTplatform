#include "startmanager.h"
#include "AppConfig/AppParameter.h"
#include "Language/language.h"
#include "CustomerWidget/Dialog/messagedialog.h"
#include "Communication/MQTT/mqttclientmanager.h"
#include "IMachineConstant/Subscriber/machineconstantsubscriber.h"
#include "IRecipe/Subscriber/recipesubscriber.h"

#include <QMutex>

StartManager *StartManager::self = nullptr;
StartManager::StartManager(QObject *parent) : IStarter(parent)
{

}

StartManager *StartManager::getInstance()
{
    if(self == NULL)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == NULL)
        {
            self = new StartManager;
        }
    }
    return self;
}

bool StartManager::HardwareInitialize()
{
    return true;
}

bool StartManager::SoftwareInitialize()
{
    bool r = true;

    return r;
}

bool StartManager::SubscriberInitialize()
{
    MachineConstantSubscriber::getInstance()->LinkToSubscribeClient(MqttClientManager::getInstance()->GetClient(0));
    RecipeSubscriber::getInstance()->LinkToSubscribeClient(MqttClientManager::getInstance()->GetClient(0));

    MachineConstantSubscriber::getInstance()->Subscribe(this->m_strDefaultPrefix + "_" + "MachineConstant");
    RecipeSubscriber::getInstance()->Subscribe(this->m_strDefaultPrefix + "_" + "Recipe");

    return true;
}

bool StartManager::PublisherInitialize()
{
    return true;
}

bool StartManager::HardwareDestroy()
{
    return true;
}

bool StartManager::SoftwareDestroy()
{
    return true;
}
