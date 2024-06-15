/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        appconfigview.cpp
* Description:      aAppConfig修改主界面
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-2-19
* Modify Record：
***********************************************************************/

#include "appconfigview.h"
#include "ui_appconfigview.h"
#include "AppConfig/Manage/appconfigmanager.h"

AppConfigView::AppConfigView(QString name, QWidget *parent) : AuthorityWidget(name, parent),
    ui(new Ui::AppConfigView)
{
    ui->setupUi(this);
    m_AppConfig = AppConfigManager::getInstance()->GetAppConfig();
    ItemInitialize();
}

AppConfigView::~AppConfigView()
{
    delete ui;
}

void AppConfigView::ConstructFinished()
{
    m_AppConfig = AppConfigManager::getInstance()->GetAppConfig();
}

void AppConfigView::setWidgets()
{
    ui->gpb_Config->SetheaderFontSize(16);
    ui->gpb_Config->SetHeaderText(Tr("AppData Setting"));

    ui->lbl_Path->setText("AppDataPath");
    ui->lbl_PathB->setText("appDataPath_Backup");
    ui->lbl_IP->setText("Server.IP");
    ui->lbl_Port->setText("Server.Port");
    ui->lbl_LocalIP->setText("Local IP");

    ui->led_Path->setText(m_AppConfig.appDataPath);
    ui->led_PathB->setText(m_AppConfig.appDataPath_Backup);
    ui->led_IP->setText(m_AppConfig.serverAdd.IP);
    ui->led_Port->setText(QString::number(m_AppConfig.serverAdd.port));
    ui->led_LocalIP->setText(m_AppConfig.LocalIP);
    ui->led_LocalIP->setEnabled(true);

    ui->btn_SaveConfig->setText("Save Config");
}

void AppConfigView::setWidgetStyleSheet()
{
    ui->gpb_Config->setStyleSheet(GlobalStyleSheet->GroupBoxStyle + GlobalStyleSheet->LineEdit_Dark + GlobalStyleSheet->Button_Border);

    ui->lbl_Path->setAlignment(Qt::AlignCenter);
    ui->lbl_PathB->setAlignment(Qt::AlignCenter);
    ui->lbl_IP->setAlignment(Qt::AlignCenter);
    ui->lbl_Port->setAlignment(Qt::AlignCenter);
    ui->lbl_LocalIP->setAlignment(Qt::AlignCenter);
    ui->lbl_Path->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_PathB->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_IP->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_Port->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->lbl_LocalIP->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);

    ui->led_Path->setAlignment(Qt::AlignCenter);
    ui->led_PathB->setAlignment(Qt::AlignCenter);
    ui->led_IP->setAlignment(Qt::AlignCenter);
    ui->led_Port->setAlignment(Qt::AlignCenter);
    ui->led_LocalIP->setAlignment(Qt::AlignCenter);
    ui->led_Path->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12 + GlobalStyleSheet->LineEdit_Dark);
    ui->led_PathB->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12 + GlobalStyleSheet->LineEdit_Dark);
    ui->led_IP->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12 + GlobalStyleSheet->LineEdit_Dark);
    ui->led_Port->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12 + GlobalStyleSheet->LineEdit_Dark);
    ui->led_LocalIP->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12 + GlobalStyleSheet->LineEdit_Dark);

    ui->btn_SaveConfig->setStyleSheet(GlobalStyleSheet->Button_Border + GlobalStyleSheet->fontStyle_normal_12);
}

void AppConfigView::setLanguageKeys()
{
    Tr("AppConfig Setting");
    Tr("AppDataPath");
    Tr("Server.IP");
    Tr("Server.Port");
    Tr("Save Config");
}

void AppConfigView::setConnections()
{
    connect(ui->btn_SaveConfig, &QPushButton::clicked, this, [ = ]
    {
        m_AppConfig.appDataPath = ui->led_Path->text();
        m_AppConfig.appDataPath_Backup = ui->led_PathB->text();
        m_AppConfig.serverAdd.IP = ui->led_IP->text();
        m_AppConfig.serverAdd.port = ui->led_Port->text().toInt();
        m_AppConfig.LocalIP= ui->led_LocalIP->text();
        AppConfigManager::getInstance()->WriteToFile(m_AppConfig);
    });
}
