#ifndef STARTMANAGER_H
#define STARTMANAGER_H

#include "Starter/istarter.h"
#include "mainwindow.h"

#include <QObject>

class StartManager : public IStarter
{
    Q_OBJECT
public:
    explicit StartManager(QObject *parent = nullptr);
    static StartManager *getInstance();

private:
    virtual bool HardwareInitialize() override;
    virtual bool SoftwareInitialize() override;
    virtual bool SubscriberInitialize() override;
    virtual bool PublisherInitialize() override;
    virtual bool HardwareDestroy() override;
    virtual bool SoftwareDestroy() override;

private:
    static StartManager *self;
};

#endif // STARTMANAGER_H
