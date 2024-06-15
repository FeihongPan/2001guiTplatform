#ifndef BINDABLECONTAINER_H
#define BINDABLECONTAINER_H

#include "GUICommFuncLib_global.h"
#include "bindablewidget.h"

#include <QObject>
#include <QMutex>
#include <QEventLoop>

class GUICOMMFUNCLIB_EXPORT BindableContainer : public QObject
{
    Q_OBJECT
public:
    explicit BindableContainer(QObject *parent = nullptr);
    ~BindableContainer();
    static BindableContainer *GetInstance();
    QList<BindableWidget *> GetBindableWidgets();

    void Run();
    void Terminate();
    void SetRefreshTimeSpan(int timeSpan);
    bool IsBusy = false;

public slots:
    void AddWidget(BindableWidget *wdg);
    void RemoveWidget(BindableWidget *wdg);
signals:
    void sendStartRefresh();

private:
    static BindableContainer *self;
    QList<BindableWidget *> lstBindableWidgets;
    QMutex mutex_Widgets;
    bool IsRunning = false;
    bool IsRefreshed = false;
    QFuture<void> future;
    int refreshTimeSpan = 200;

};

#endif // BINDABLECONTAINER_H
