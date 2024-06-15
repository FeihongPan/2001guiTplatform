#include "sgtview.h"
#include "ui_sgtview.h"
#include "SGT/Data/sgtsystem.h"
#include "SGT/Command/cmd_sgtconstant.h"
#include "SGT/Command/cmd_sgtctrl.h"
#include "SGT/Subscriber/sgtconstantsubscriber.h"
#include "SGT/Subscriber/sgtctrlsubscriber.h"

SGTView::SGTView(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::SGTView)
{
    ui->setupUi(this);
}

SGTView::~SGTView()
{
    delete ui;
}

void SGTView::ConstructFinished()
{
    m_Publisher.Publish("SGTConstant", EnumConverter::ConvertToString(CMD_SGTConstant::CMD_SGTData));
}

void SGTView::setWidgets()
{
    QStringList lst_States = EnumConverter::ConvertToStringList<SGTSystem::State>();
    ui->cmb_SGTStatus->addItems(lst_States);

    QStringList lst_TwinkleModel = EnumConverter::ConvertToStringList<SGTSystem::TwinkleMode>();
    ui->cmb_RedLightTwinkleMode->addItems(lst_TwinkleModel);
    ui->cmb_YellowLightTwinkleMode->addItems(lst_TwinkleModel);
    ui->cmb_GreenLightTwinkleMode->addItems(lst_TwinkleModel);
    ui->cmb_BlueLightTwinkleMode->addItems(lst_TwinkleModel);
    ui->cmb_BuzzerTwinkleMode->addItems(lst_TwinkleModel);

    //    ui->gpb_SGT->setEnabled(false);
}

void SGTView::setWidgetStyleSheet()
{
    ui->gpb_SGT->SetheaderFontSize(16);
    ui->gpb_SGT->setStyleSheet(StyleSheet::getInstance()->GroupBoxStyle + StyleSheet::getInstance()->ComboBox
                               + StyleSheet::getInstance()->LineEdit_Dark + StyleSheet::getInstance()->DoubleSpinBox_Dark
                               + StyleSheet::getInstance()->SpinBox_Dark + StyleSheet::getInstance()->fontStyle_normal_12);

    ui->btn_Confirm->setStyleSheet(StyleSheet::getInstance()->Button_Border + StyleSheet::getInstance()->fontStyle_normal_14);
    ui->btn_MaunalTest->setStyleSheet(StyleSheet::getInstance()->Button_Border + StyleSheet::getInstance()->fontStyle_normal_14);
    ui->btn_MaunalTestExit->setStyleSheet(StyleSheet::getInstance()->Button_Border + StyleSheet::getInstance()->fontStyle_normal_14);

}

void SGTView::setLanguageKeys()
{
    ui->gpb_SGT->SetHeaderText(Tr("Signal Tower"));
    ui->btn_Confirm->setText(Tr("Confirm"));
    ui->btn_MaunalTest->setText(Tr("Manual Test"));
    ui->btn_MaunalTestExit->setText(Tr("Exit Test"));
}

void SGTView::setConnections()
{
    connect(SGTConstantSubscriber::getInstance(), &SGTConstantSubscriber::Send_SGTConstant, this, [ = ](S_SGTConstant & sgt)
    {
        this->m_SGTConstant = sgt;
        ui->gpb_SGT->setEnabled(true);
    });

    connect(SGTCtrlSubscriber::getInstance(), &SGTCtrlSubscriber::Send_SGTSystemState, this, [ = ](SGTSystem::State state)
    {
        ui->lbl_SGTState->setText(EnumConverter::ConvertToString(state));
    });

    connect(ui->cmb_SGTStatus, &QComboBox::currentTextChanged, this, [ = ](const QString & state)
    {
        SGTSystem::State sgtState = EnumConverter::ConvertStringToEnum<SGTSystem::State>(state);
        S_SGTTwinkleData twinkleData = this->m_SGTConstant.dic_SGTTwinkleData[sgtState];
        ui->cmb_RedLightTwinkleMode->setCurrentText(EnumConverter::ConvertToString(twinkleData.dic_SGTTwinkleTime[SGTSystem::SGTComponent::RedLight].twinkleMode));
        ui->cmb_YellowLightTwinkleMode->setCurrentText(EnumConverter::ConvertToString(twinkleData.dic_SGTTwinkleTime[SGTSystem::SGTComponent::YellowLight].twinkleMode));
        ui->cmb_GreenLightTwinkleMode->setCurrentText(EnumConverter::ConvertToString(twinkleData.dic_SGTTwinkleTime[SGTSystem::SGTComponent::GreenLight].twinkleMode));
        ui->cmb_BlueLightTwinkleMode->setCurrentText(EnumConverter::ConvertToString(twinkleData.dic_SGTTwinkleTime[SGTSystem::SGTComponent::BlueLight].twinkleMode));
        ui->cmb_BuzzerTwinkleMode->setCurrentText(EnumConverter::ConvertToString(twinkleData.dic_SGTTwinkleTime[SGTSystem::SGTComponent::Buzzer].twinkleMode));
    });

    connect(ui->cmb_RedLightTwinkleMode, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentTextChanged), this, [ = ](const QString & state)
    {
        SGTSystem::State sgtState = EnumConverter::ConvertStringToEnum<SGTSystem::State>(ui->cmb_SGTStatus->currentText());
        SGTSystem::TwinkleMode twinkleModel = EnumConverter::ConvertStringToEnum<SGTSystem::TwinkleMode>(state);
        this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[SGTSystem::SGTComponent::RedLight].twinkleMode = twinkleModel;
        showSGTData(ui->spb_RedLight_Off, ui->spb_RedLight_On, SGTSystem::SGTComponent::RedLight, sgtState, twinkleModel);
    });

    connect(ui->cmb_YellowLightTwinkleMode, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentTextChanged), this, [ = ](const QString & state)
    {
        SGTSystem::State sgtState = EnumConverter::ConvertStringToEnum<SGTSystem::State>(ui->cmb_SGTStatus->currentText());
        SGTSystem::TwinkleMode twinkleModel = EnumConverter::ConvertStringToEnum<SGTSystem::TwinkleMode>(state);
        this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[SGTSystem::SGTComponent::YellowLight].twinkleMode = twinkleModel;
        showSGTData(ui->spb_YellowLight_Off, ui->spb_YellowLight_On, SGTSystem::SGTComponent::YellowLight, sgtState, twinkleModel);
    });

    connect(ui->cmb_GreenLightTwinkleMode, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentTextChanged), this, [ = ](const QString & state)
    {
        SGTSystem::State sgtState = EnumConverter::ConvertStringToEnum<SGTSystem::State>(ui->cmb_SGTStatus->currentText());
        SGTSystem::TwinkleMode twinkleModel = EnumConverter::ConvertStringToEnum<SGTSystem::TwinkleMode>(state);
        this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[SGTSystem::SGTComponent::GreenLight].twinkleMode = twinkleModel;
        showSGTData(ui->spb_GreenLight_Off, ui->spb_GreenLight_On, SGTSystem::SGTComponent::GreenLight, sgtState, twinkleModel);
    });

    connect(ui->cmb_BlueLightTwinkleMode, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentTextChanged), this, [ = ](const QString & state)
    {
        SGTSystem::State sgtState = EnumConverter::ConvertStringToEnum<SGTSystem::State>(ui->cmb_SGTStatus->currentText());
        SGTSystem::TwinkleMode twinkleModel = EnumConverter::ConvertStringToEnum<SGTSystem::TwinkleMode>(state);
        this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[SGTSystem::SGTComponent::BlueLight].twinkleMode = twinkleModel;
        showSGTData(ui->spb_BlueLight_Off, ui->spb_BlueLight_On, SGTSystem::SGTComponent::BlueLight, sgtState, twinkleModel);
    });

    connect(ui->cmb_BuzzerTwinkleMode, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentTextChanged), this, [ = ](const QString & state)
    {
        SGTSystem::State sgtState = EnumConverter::ConvertStringToEnum<SGTSystem::State>(ui->cmb_SGTStatus->currentText());
        SGTSystem::TwinkleMode twinkleModel = EnumConverter::ConvertStringToEnum<SGTSystem::TwinkleMode>(state);
        this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[SGTSystem::SGTComponent::Buzzer].twinkleMode = twinkleModel;
        showSGTData(ui->spb_Buzzer_Off, ui->spb_Buzzer_On, SGTSystem::SGTComponent::Buzzer, sgtState, twinkleModel);
    });

    connect(ui->spb_RedLight_Off, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, [ = ](int value)
    {
        SGTSystem::State sgtState = EnumConverter::ConvertStringToEnum<SGTSystem::State>(ui->cmb_SGTStatus->currentText());
        this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[SGTSystem::SGTComponent::RedLight].timeSpan_Off = value;
    });

    connect(ui->spb_RedLight_On, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, [ = ](int value)
    {
        SGTSystem::State sgtState = EnumConverter::ConvertStringToEnum<SGTSystem::State>(ui->cmb_SGTStatus->currentText());
        this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[SGTSystem::SGTComponent::RedLight].timeSpan_On = value;
    });

    connect(ui->spb_YellowLight_Off, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, [ = ](int value)
    {
        SGTSystem::State sgtState = EnumConverter::ConvertStringToEnum<SGTSystem::State>(ui->cmb_SGTStatus->currentText());
        this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[SGTSystem::SGTComponent::YellowLight].timeSpan_Off = value;
    });

    connect(ui->spb_YellowLight_On, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, [ = ](int value)
    {
        SGTSystem::State sgtState = EnumConverter::ConvertStringToEnum<SGTSystem::State>(ui->cmb_SGTStatus->currentText());
        this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[SGTSystem::SGTComponent::YellowLight].timeSpan_On = value;
    });

    connect(ui->spb_GreenLight_Off, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, [ = ](int value)
    {
        SGTSystem::State sgtState = EnumConverter::ConvertStringToEnum<SGTSystem::State>(ui->cmb_SGTStatus->currentText());
        this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[SGTSystem::SGTComponent::GreenLight].timeSpan_Off = value;
    });

    connect(ui->spb_GreenLight_On, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, [ = ](int value)
    {
        SGTSystem::State sgtState = EnumConverter::ConvertStringToEnum<SGTSystem::State>(ui->cmb_SGTStatus->currentText());
        this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[SGTSystem::SGTComponent::GreenLight].timeSpan_On = value;
    });

    connect(ui->spb_BlueLight_Off, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, [ = ](int value)
    {
        SGTSystem::State sgtState = EnumConverter::ConvertStringToEnum<SGTSystem::State>(ui->cmb_SGTStatus->currentText());
        this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[SGTSystem::SGTComponent::BlueLight].timeSpan_Off = value;
    });

    connect(ui->spb_BlueLight_On, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, [ = ](int value)
    {
        SGTSystem::State sgtState = EnumConverter::ConvertStringToEnum<SGTSystem::State>(ui->cmb_SGTStatus->currentText());
        this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[SGTSystem::SGTComponent::BlueLight].timeSpan_On = value;
    });

    connect(ui->spb_Buzzer_Off, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, [ = ](int value)
    {
        SGTSystem::State sgtState = EnumConverter::ConvertStringToEnum<SGTSystem::State>(ui->cmb_SGTStatus->currentText());
        this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[SGTSystem::SGTComponent::Buzzer].timeSpan_Off = value;
    });

    connect(ui->spb_Buzzer_On, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, [ = ](int value)
    {
        SGTSystem::State sgtState = EnumConverter::ConvertStringToEnum<SGTSystem::State>(ui->cmb_SGTStatus->currentText());
        this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[SGTSystem::SGTComponent::Buzzer].timeSpan_On = value;
    });

    connect(ui->btn_Confirm, &QPushButton::clicked, this, [ = ]
    {
        m_Publisher.Publish("SGTConstant", EnumConverter::ConvertToString(CMD_SGTConstant::CMD_SaveSGTData), true, this->m_SGTConstant.toRawJson());
    });

    connect(SGTConstantSubscriber::getInstance(), &SGTConstantSubscriber::Send_SaveResult, this, [ = ](bool r)
    {
        if(r)
        {
            MessageDialog dlg(MessageDialog::Success, this, Tr("S_SaveSGTOK"));
            dlg.exec();
        }
        else
        {
            MessageDialog dlg(MessageDialog::Error, this, Tr("E_SaveSGTFail"));
            dlg.exec();
        }
    });

    connect(ui->btn_MaunalTest, &QPushButton::clicked, this, [ = ]
    {
        m_Publisher.Publish("SGTCtrl", EnumConverter::ConvertToString(CMD_SGTCtrl::CMD_MaunualSet), true, ui->cmb_SGTStatus->currentText().toUtf8());
    });

    connect(ui->btn_MaunalTestExit, &QPushButton::clicked, this, [ = ]
    {
        m_Publisher.Publish("SGTCtrl", EnumConverter::ConvertToString(CMD_SGTCtrl::CMD_MaunualSetExit));
    });
}

void SGTView::showSGTData(QSpinBox *off, QSpinBox *on, SGTSystem::SGTComponent component, SGTSystem::State sgtState, SGTSystem::TwinkleMode twinkleModel)
{
    if(twinkleModel == SGTSystem::TwinkleMode::HighFrequency || twinkleModel == SGTSystem::TwinkleMode::LowFrequency)
    {
        off->setEnabled(false);
        on->setEnabled(false);
        off->setValue(this->m_SGTConstant.dic_TimeSpan[twinkleModel]);
        on->setValue(this->m_SGTConstant.dic_TimeSpan[twinkleModel]);
    }
    else if(twinkleModel == SGTSystem::TwinkleMode::AlwaysOff)
    {
        off->setEnabled(false);
        on->setEnabled(false);
        off->setValue(1000);
        on->setValue(0);
    }
    else if(twinkleModel == SGTSystem::TwinkleMode::AlwaysOn)
    {
        off->setEnabled(false);
        on->setEnabled(false);
        off->setValue(0);
        on->setValue(1000);
    }
    else
    {
        off->setEnabled(true);
        on->setEnabled(true);
        off->setValue(this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[component].timeSpan_Off);
        on->setValue(this->m_SGTConstant.dic_SGTTwinkleData[sgtState].dic_SGTTwinkleTime[component].timeSpan_On);
    }
}
