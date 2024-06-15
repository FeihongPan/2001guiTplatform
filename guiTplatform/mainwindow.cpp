#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AppConfig/Manage/guiconfigmanager.h"
#include "TimeSynchronization/Manage/timesync.h"
#include "AuthorityManage/WidgetManage/authoritywdgmanager.h"
#include "NaviForm/Recipes/recipesform.h"
#include "NaviForm/Setup/setupform.h"
#include "NaviForm/Help/helpform.h"
#include "Language/language.h"
#include "BindableComponent/bindablecontainer.h"
#include "CustomerWidget/Dialog/logindialog.h"
#include "SGT/Control/sgtwidgetcontroller.h"
#include "SGT/Command/cmd_sgtctrl.h"
#include "KeyVerify/Subscriber/keyverifysubscriber.h"
#include "KeyVerify/Command/cmd_keyverify.h"
#include "Communication/MQTT/mqttclientmanager.h"
#include "runtimepara.h"
#include "startmanager.h"

#include <QDebug>
#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <QGraphicsBlurEffect>
#include <QProcess>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : AuthorityWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_Publisher.LinkToClient(MqttClientManager::getInstance()->GetClient(0), PublishTopicPrefix);

    RuntimePara::getInstance()->p_BlurParentWidget = ui->centralwidget;

    setWindowStyle();
    naviBtnInitial();
    titleWidgetInitial();
    subFormInitialize();
    setTimer();

    ui->lbl_MachineState->setText(Tr("Machine State"));
    ui->lbl_MachineState->setStyleSheet(StyleSheet::getInstance()->fontStyle_normal_14);
    ui->led_MachineState->setStyleSheet(StyleSheet::getInstance()->LineEdit_Dark + StyleSheet::getInstance()->fontStyle_normal_14);

    m_Publisher.Publish("User", EnumConverter::ConvertToString(CMD_User::CMD_CurrentUser));
}

MainWindow::~MainWindow()
{
    qDebug() << "MainWindow::~MainWindow()";
    timer->stop();
    BindableContainer::GetInstance()->Terminate();
    delete ui;
}

void MainWindow::userChanged(S_UserInfo &user)
{
    ui->lbl_UserName->setText(user.userName);
}

void MainWindow::setWindowStyle()
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect *effect_Title = new QGraphicsDropShadowEffect(ui->frame_Title);
    effect_Title->setOffset(0, 8);
    effect_Title->setColor("#DEEEFF");
    effect_Title->setBlurRadius(12);
    ui->frame_Title->setGraphicsEffect(effect_Title);

    QGraphicsDropShadowEffect *effect_NaviPanel = new QGraphicsDropShadowEffect(ui->frame_NaviPanel);
    effect_NaviPanel->setOffset(0, -8);
    effect_NaviPanel->setColor("#DEEEFF");
    effect_NaviPanel->setBlurRadius(12);
    ui->frame_NaviPanel->setGraphicsEffect(effect_NaviPanel);
}

void MainWindow::naviBtnInitial()
{
    QFont font = GlobalStyleSheet->Font();
    ui->btn_Recipes->SetVertivalStyle(font, QString(0xa028), 30, Tr("Recipes"), 12, QFont::Bold);
    ui->btn_Setup->SetVertivalStyle(font, QString(0xa030), 30, Tr("Setup"), 12, QFont::Bold);
    ui->btn_Help->SetVertivalStyle(font, QString(0xa023), 30, Tr("Helps"), 12, QFont::Bold);

    ui->btn_Recipes->setStyleSheet(GlobalStyleSheet->NaviButtonStyle);
    ui->btn_Setup->setStyleSheet(GlobalStyleSheet->NaviButtonStyle);
    ui->btn_Help->setStyleSheet(GlobalStyleSheet->NaviButtonStyle);
}

void MainWindow::titleWidgetInitial()
{
    #pragma region exit{
    QFont font = GlobalStyleSheet->Font();
    font.setPixelSize(30);
    ui->btn_Exit->setFont(font);
    ui->btn_Exit->setText(QString(0xa005));
    ui->btn_Exit->setStyleSheet(GlobalStyleSheet->ButtonStyle_Front);
    connect(ui->btn_Exit, &QPushButton::clicked, this, [ = ]
    {
        MessageDialog dlg(MessageDialog::Attention, ui->centralwidget, Tr("Are you sure to exit?"));
        if (dlg.exec() == QDialog::Accepted)
        {
            emit Closing();
        }
    });
    #pragma endregion}

    #pragma region login{
    qRegisterMetaType<S_UserInfo>("S_UserInfo");
    font.setPixelSize(30);
    ui->btn_Login->setFont(font);
    ui->btn_Login->setText(QString(0xa001));
    ui->btn_Login->setStyleSheet(GlobalStyleSheet->ButtonStyle_Front);
    connect(ui->btn_Login, &QPushButton::clicked, this, [ = ]
    {
        if(this->user.accessLevel != AccessLevel::Visitor)
        {
            MessageDialog dlg(MessageDialog::NoticeType::Attention, ui->centralwidget, Tr("Are you sure to logout?"));
            if(dlg.exec() == QDialog::Accepted)
            {
                m_Publisher.Publish("User", EnumConverter::ConvertToString(CMD_User::CMD_Logout));
            }
        }
        else
        {
            LoginDialog dlg(ui->centralwidget);
            connect(&dlg, &LoginDialog::SendLoginInfo, this, [ = ](QString name, QString pwd)
            {
                S_UserInfo user;
                user.userName = name;
                user.password = pwd;
                m_Publisher.Publish("User", EnumConverter::ConvertToString(CMD_User::CMD_Login), false, user.toRawJson());
            });
            connect(UserSubscriber::getInstance(), &UserSubscriber::sendLoginResult, &dlg, &LoginDialog::RecivedLoginInfo);
            dlg.exec();
        }
    });
    #pragma endregion}

    #pragma region server connect{
    ui->btn_ServerConnectState->setStyleSheet(StyleSheet::getInstance()->ButtonStyle_Back);
    m_bServerConnected = MqttClientManager::getInstance()->GetClient(0)->IsConnected();
    if(m_bServerConnected.value)
    {
        ui->btn_ServerConnectState->setText(Tr("Connected"));
        ui->btn_ServerConnectState->setChecked(true);
    }
    else
    {
        ui->btn_ServerConnectState->setText(Tr("Disconnected"));
        ui->btn_ServerConnectState->setChecked(false);
    }

    connect(MqttClientManager::getInstance()->GetClient(0), &MqttClient::connected, this, [ = ]
    {
        ui->btn_ServerConnectState->setText(Tr("Connected"));
        ui->btn_ServerConnectState->setChecked(true);
    });

    connect(MqttClientManager::getInstance()->GetClient(0), &MqttClient::disconnected, this, [ = ]
    {
        ui->btn_ServerConnectState->setText(Tr("Disconnected"));
        ui->btn_ServerConnectState->setChecked(false);
    });

    connect(ui->btn_ServerConnectState, &QPushButton::toggled, this, [ = ](bool checked)
    {

    });
    #pragma endregion}

    #pragma region SGT{
    SGTWidgetController::getInstance()->RegisteSGTWidget(SGTSystem::RedLight, ui->btn_RedLight);
    SGTWidgetController::getInstance()->RegisteSGTWidget(SGTSystem::YellowLight, ui->btn_YellowLight);
    SGTWidgetController::getInstance()->RegisteSGTWidget(SGTSystem::GreenLight, ui->btn_GreenLight);
    SGTWidgetController::getInstance()->RegisteSGTWidget(SGTSystem::BlueLight, ui->btn_BlueLight);

    m_Publisher.Publish("SGTCtrl", EnumConverter::ConvertToString(CMD_SGTCtrl::CMD_SGTState));
    #pragma endregion}
}


void MainWindow::subFormInitialize()
{
    AuthorityWdgManager::getInstance()->SetMainWindow(this);
    AuthorityWdgManager::getInstance()->SetMainStackedWidget(ui->stackedWidget);

    bool left =  GUIConfigManager::getInstance()->m_UIPara.naviPanelLeft.value;
    AuthorityWdgManager::getInstance()->InitOpt(ui->btn_Recipes, new RecipesForm("Recipes", this), ui->stackedWidget, this, 1, left);
    AuthorityWdgManager::getInstance()->InitOpt(ui->btn_Setup, new SetupForm("Setup", this), ui->stackedWidget, this, 2, left);
    AuthorityWdgManager::getInstance()->InitOpt(ui->btn_Help, new HelpForm("Help", this), ui->stackedWidget, this, 3, left);

    emit MainWindowIntialized();

    AuthorityWdgManager::getInstance()->Initialize();

    Tr("Recipes");
    Tr("Setup");
    Tr("Help");
    BindableContainer::GetInstance()->Run();
}

void MainWindow::setTimer()
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [ = ]
    {
        ui->lbl_DateTime->setText(Time()->TimeToString());
    });
    timer->start(1000);
}

void MainWindow::CloseProgram()
{
    qDebug() << "MainWindow::closeProgram()";
    //    publisher.Publish("MachineState", EnumConverter::ConvertToString(MachineStateInterpreter::CMD_Terminate));
    close();
}

