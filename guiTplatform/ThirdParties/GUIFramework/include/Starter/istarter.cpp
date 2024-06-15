#include "istarter.h"
#include "Language/language.h"
#include "Communication/MQTT/mqttclientmanager.h"
#include "CustomerWidget/Dialog/messagedialog.h"
#include "AppConfig/AppParameter.h"
#include "AppConfig/Manage/guiconfigmanager.h"
#include "AppConfig/Manage/appconfigmanager.h"
#include "Logger/loggermanager.h"

#include "AuthorityManage/Subscriber/userSubscriber.h"
#include "ThreadProc/Subscriber/threadprocsubscriber.h"
#include "Alarms/Subscriber/alarmSubscriber.h"
#include "SGT/Subscriber/sgtconstantsubscriber.h"
#include "SGT/Subscriber/sgtctrlsubscriber.h"
#include "SGT/Control/sgtwidgetcontroller.h"
#include "KeyVerify/Subscriber/keyverifysubscriber.h"
#include "KeyVerify/Manager/keyverifier.h"
#include "FileSystem/fileoperatormanager.h"
#include "Communication/MQTT/publishermanager.h"

#include <QThreadPool>

using NS_Log::LoggerManager;

IStarter::IStarter(QObject *parent) : QObject(parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(200);
}

bool IStarter::Start()
{
    qDebug() << "IStarter::Start()";

    if(true)
    {
        bool r = true;
        r &= softwareInitialize();
        LOG()->Log_Debug(("softwareInitialize... " + QString::number(r)).toLatin1().data());
        r &= SoftwareInitialize();
        LOG()->Log_Debug(("SoftwareInitialize... " + QString::number(r)).toLatin1().data());
        r &= hardwareInitialize();
        LOG()->Log_Debug(("hardwareInitialize... " + QString::number(r)).toLatin1().data());
        r &= HardwareInitialize();
        LOG()->Log_Debug(("HardwareInitialize... " + QString::number(r)).toLatin1().data());
        if(r)
        {
            subscriberInitialize();
            SubscriberInitialize();
            qDebug() << "...InitialOK...";
            emit sig_InitialOK();
            return true;
        }
        else
        {
            qDebug() << "InitialFail";
            emit sig_InitialFail();
            return false;
        }
    }
    else
    {
        MessageDialog dlg(MessageDialog::Error, NULL, "GUI License Fail!");
        dlg.exec();
        qDebug() << "...LicenseFail...";
        emit sig_LicenseFail();
        return false;
    }
}

bool IStarter::Terminate()
{
    qDebug() << "IStarter::Terminate()";
    bool r = true;
    r &= hardwareDestroy();
    r &= HardwareDestroy();
    r &= softwareDestroy();
    r &= SoftwareDestroy();
    emit sig_Terminated();
    return r;
}



bool IStarter::hardwareInitialize()
{
    bool r = true;
    MqttClientManager::getInstance()->AddClient(0, "GUI");

    if(GUIConfigManager::getInstance()->IsInitialized())
    {
        SR_GUIConfig uiPara = GUIConfigManager::getInstance()->GetUIParameter();
        qDebug() << "uiPara" << uiPara.serverIp.value << uiPara.serverPort.value;
        QList<int> lst_ClientId = MqttClientManager::getInstance()->GetClientID();
        for(int i = 0; i < lst_ClientId.count(); i++)
        {
            if(!MqttClientManager::getInstance()->Connect(lst_ClientId[i], uiPara.serverIp.value, uiPara.serverPort.value))
            {
                MessageDialog dlg(MessageDialog::Error, NULL, "Client connect to server fail!");
                dlg.exec();
                r = false;
            }
        }
    }

    if(AppConfigManager::getInstance()->IsInitialized())
    {
        AppConfig config = AppConfigManager::getInstance()->GetAppConfig();
        qDebug() << "AppConfig" << config.appDataPath << config.serverAdd.IP << config.serverAdd.port;
    }

    return r;
}

bool IStarter::softwareInitialize()
{
    bool r = true;

    #pragma region AppConfig {
    AppConfigManager::getInstance()->SetPath(m_AppConfig.appDataPath + "AppConfig", m_AppConfig.appDataPath_Backup + "AppConfig", "AppConfig.json", m_AppConfig.appDataPath + "CommunicationCommand");
    if(!AppConfigManager::getInstance()->Initialize())
    {
        MessageDialog dlg(MessageDialog::Error, NULL, "AppConfig initial fail!");
        dlg.exec();
        r = false;
    }
    #pragma endregion}

    #pragma region logger initialize{
    LOG()->Initialize_DebugLogger(m_AppConfig.appDataPath);
    LOG()->Initialize_ExceptionLogger(m_AppConfig.appDataPath);
    LOG()->Initialize_AlarmLogger("Reported", m_AppConfig.appDataPath);
    LOG()->Initialize_AlarmLogger("Released", m_AppConfig.appDataPath);
    #pragma endregion}

    #pragma region file system initialize{
    KeyVerifier::getInstance()->SetPath(m_AppConfig.appDataPath + "Key", m_AppConfig.appDataPath_Backup + "Key", "KeyVerifier.json", m_AppConfig.appDataPath + "CommunicationCommand");

    FileOperatorManager::getInstance()->AddFileOperator(AppConfigManager::getInstance());
    FileOperatorManager::getInstance()->AddFileOperator(KeyVerifier::getInstance());
    #pragma endregion}

    #pragma region module initialize{
    if(!GUIConfigManager::getInstance()->Initialize())
    {
        MessageDialog dlg(MessageDialog::Error, NULL, "UI parameter initial fail!");
        dlg.exec();
    }

    if(!Language::getInstance()->Initialize(m_AppConfig.appDataPath))
    {
        MessageDialog dlg(MessageDialog::Error, NULL, "Language initial fail!");
        dlg.exec();
    }
    else
    {
        SR_GUIConfig uiPara = GUIConfigManager::getInstance()->GetUIParameter();
        Language::getInstance()->SetLanguageType((Language::LanguageType)uiPara.language.value);
    }
    #pragma endregion}

    return r;
}

bool IStarter::subscriberInitialize()
{
    UserSubscriber::getInstance()->LinkToSubscribeClient(MqttClientManager::getInstance()->GetClient(0));
    ThreadProcSubscriber::getInstance()->LinkToSubscribeClient(MqttClientManager::getInstance()->GetClient(0));
    AlarmSubscriber::getInstance()->LinkToSubscribeClient(MqttClientManager::getInstance()->GetClient(0));
    SGTConstantSubscriber::getInstance()->LinkToSubscribeClient(MqttClientManager::getInstance()->GetClient(0));
    SGTCtrlSubscriber::getInstance()->LinkToSubscribeClient(MqttClientManager::getInstance()->GetClient(0));
    KeyVerifySubscriber::getInstance()->LinkToSubscribeClient(MqttClientManager::getInstance()->GetClient(0));

    UserSubscriber::getInstance()->Subscribe("MC_User");
    ThreadProcSubscriber::getInstance()->Subscribe("MC_ThreadProc");
    AlarmSubscriber::getInstance()->Subscribe("MC_Alarm");
    SGTConstantSubscriber::getInstance()->Subscribe("MC_SGTConstant");
    SGTCtrlSubscriber::getInstance()->Subscribe("MC_SGTCtrl");
    KeyVerifySubscriber::getInstance()->Subscribe("MC_KeyVerify");

    bool r = true;

    return r;
}

bool IStarter::publisherInitialize()
{
    bool r = true;

    AppConfigManager::getInstance()->LinkToPublishClient(MqttClientManager::getInstance()->GetClient(0), "GUI", "AppConfig");

    PublisherManager::getInstance()->AddIPublish(AppConfigManager::getInstance());

    return r;
}

bool IStarter::hardwareDestroy()
{
    bool r = true;

    return r;
}

bool IStarter::softwareDestroy()
{
    Language::getInstance()->SaveToFile();
    SGTWidgetController::getInstance()->Terminate();
    return true;
}

bool IStarter::checkLisence()
{
    KeyVerifier::getInstance()->SetCRCVerifyUsed(true);
    if(KeyVerifier::getInstance()->IsFolderEmpty())
    {
        KeyVerifier::getInstance()->WriteDeviceInfoToFile();
        return false;
    }
    return KeyVerifier::getInstance()->CheckAuthorization();
}
