#include "sgtwidgetcontroller.h"
#include "SGT/Subscriber/sgtctrlsubscriber.h"

#include <QMutex>

SGTWidgetController *SGTWidgetController::self = NULL;
SGTWidgetController::SGTWidgetController(QObject *parent) : QObject(parent)
{
    //    m_Timer.start(m_Interval);
    connect(&m_Timer, &QTimer::timeout, this, &SGTWidgetController::setSGTWidgetState);

    connect(SGTCtrlSubscriber::getInstance(), &SGTCtrlSubscriber::Send_SGTComponentState, this, [ = ](S_SGTTwinkleData & twinkelData)
    {
        m_Timer.stop();
        this->m_TwinkleData = twinkelData;
        //        qDebug() << __FUNCTION__ << "ffffffffffffffffffffff" << this->m_TwinkleData.toRawJson();
        m_Timer.start(m_Interval);
    });
}

SGTWidgetController *SGTWidgetController::getInstance()
{
    if(self == NULL)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == NULL)
        {
            self = new SGTWidgetController();
        }
    }
    return self;
}

SGTWidgetController::~SGTWidgetController()
{

}

void SGTWidgetController::RegisteSGTWidget(SGTSystem::SGTComponent component, QPushButton *btn)
{
    if(!dic_SGTWidget.contains(component))
    {
        dic_SGTWidget.insert(component, btn);
        dic_WidgetElapse.insert(btn, 0);
    }
}

void SGTWidgetController::Terminate()
{
    m_Timer.stop();
}

void SGTWidgetController::setSGTWidgetState()
{
    QList<SGTSystem::SGTComponent> lst_Component = dic_SGTWidget.keys();
    for(int i = 0; i < lst_Component.count(); i++)
    {
        //        qDebug() << __FUNCTION__ << lst_Component[i]
        //                 << m_TwinkleData.dic_SGTTwinkleTime[lst_Component[i]].timeSpan_On
        //                 << m_TwinkleData.dic_SGTTwinkleTime[lst_Component[i]].timeSpan_Off;

        QPushButton *wdg = dic_SGTWidget[lst_Component[i]];
        if(m_TwinkleData.dic_SGTTwinkleTime[lst_Component[i]].timeSpan_On == 0)
        {
            wdg->setChecked(false);
        }
        else if(m_TwinkleData.dic_SGTTwinkleTime[lst_Component[i]].timeSpan_Off == 0)
        {
            wdg->setChecked(true);
        }
        else
        {
            dic_WidgetElapse[wdg] += m_Interval;
            if(wdg->isChecked())
            {
                if(dic_WidgetElapse[wdg] >= m_TwinkleData.dic_SGTTwinkleTime[lst_Component[i]].timeSpan_On)
                {
                    wdg->setChecked(false);
                    dic_WidgetElapse[wdg] = 0;
                }
            }
            else
            {
                if(dic_WidgetElapse[wdg] >= m_TwinkleData.dic_SGTTwinkleTime[lst_Component[i]].timeSpan_Off)
                {
                    wdg->setChecked(true);
                    dic_WidgetElapse[wdg] = 0;
                }
            }
        }
    }
}
