#include "bindablecontainer.h"
#include "BasicValue/tvalue.h"

#include <QDebug>
#include <QtConcurrent/QtConcurrent>

BindableContainer *BindableContainer::self = NULL;
BindableContainer::BindableContainer(QObject *parent) : QObject(parent)
{

}

BindableContainer::~BindableContainer()
{
    Terminate();
}

BindableContainer *BindableContainer::GetInstance()
{
    if (self == NULL)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if (self == NULL)
        {
            self = new BindableContainer;
        }
    }
    return self;
}

QList<BindableWidget *> BindableContainer::GetBindableWidgets()
{
    QList<BindableWidget *> lst;
    mutex_Widgets.lock();
    lst = lstBindableWidgets;
    mutex_Widgets.unlock();
    return lst;
}

void BindableContainer::Run()
{
    IsRunning = true;

    future = QtConcurrent::run([ = ]
    {
        while (IsRunning)
        {
            QList<BindableWidget *> lst;
            mutex_Widgets.lock();
            lst = lstBindableWidgets;
            mutex_Widgets.unlock();
            bool isNeedRefresh = false;

            //Check whether widgets need to be refreshed
            foreach(BindableWidget *wdg, lst)
            {
                QList<TValueBase *> lstValues = wdg->dicBindWidget.uniqueKeys();
                foreach(TValueBase *value, lstValues)
                {
                    isNeedRefresh = value->PropertyChanged;
                    if(isNeedRefresh == true)
                    {
                        break;
                    }
                }
                if(isNeedRefresh)
                {
                    break;
                }
            }

            //            qDebug() << "isNeedRefresh" << isNeedRefresh;
            if(isNeedRefresh)
            {
                IsRefreshed = false;
                foreach(BindableWidget *wdg, lst)
                {
                    wdg->uiRefreshed = false;
                }
                emit sendStartRefresh();


                while (!IsRefreshed)
                {
                    foreach(BindableWidget *wdg, lst)
                    {
                        IsRefreshed = wdg->uiRefreshed;
                        if(!IsRefreshed)
                        {
                            break;
                        }
                    }
                    QEventLoop loop;
                    QTimer::singleShot(1, &loop, &QEventLoop::quit);
                    loop.exec();
                }

                IsBusy = true;
                foreach(BindableWidget *wdg, lst)
                {
                    QList<TValueBase *> lstValues = wdg->dicBindWidget.uniqueKeys();
                    foreach(TValueBase *value, lstValues)
                    {
                        value->PropertyChanged = false;
                    }
                    wdg->condition.wakeAll();
                }
                IsBusy = false;
            }
            QEventLoop loop;
            QTimer::singleShot(refreshTimeSpan, &loop, &QEventLoop::quit);
            loop.exec();
        }
    });
}

void BindableContainer::Terminate()
{
    qDebug() << "Terminate";
    IsRunning = false;
    future.waitForFinished();
}

void BindableContainer::SetRefreshTimeSpan(int timeSpan)
{
    if(timeSpan < 10)
    {
        timeSpan = 10;
    }
    refreshTimeSpan = timeSpan;
}

void BindableContainer::AddWidget(BindableWidget *wdg)
{
    mutex_Widgets.lock();
    if(!lstBindableWidgets.contains(wdg))
    {
        lstBindableWidgets.append(wdg);
    }
    mutex_Widgets.unlock();
}

void BindableContainer::RemoveWidget(BindableWidget *wdg)
{
    mutex_Widgets.lock();
    if(lstBindableWidgets.contains(wdg))
    {
        lstBindableWidgets.removeOne(wdg);
    }
    mutex_Widgets.unlock();
}
