#ifndef ISTARTER_H
#define ISTARTER_H

#include "GUIFramework_global.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT IStarter : public QObject
{
    Q_OBJECT
public:
    explicit IStarter(QObject *parent = nullptr);

    inline void SetDefaultSubscribePrefix(const QString &strDefaultPrefix);

    inline void SetPublishTopicPrefix(const QString &strPublishTopicPrefix);

    bool Start();

    bool Terminate();

signals:
    void sig_InitialOK();
    void sig_InitialFail();
    void sig_LicenseFail();
    bool sig_Terminated();

protected:
    virtual bool HardwareInitialize() = 0;
    virtual bool SoftwareInitialize() = 0;
    virtual bool SubscriberInitialize() = 0;
    virtual bool PublisherInitialize() = 0;
    virtual bool HardwareDestroy() = 0;
    virtual bool SoftwareDestroy() = 0;

protected:
    QString m_strDefaultPrefix;
    QString m_strPublishTopicPrefix;

private:
    bool hardwareInitialize();
    bool softwareInitialize();
    bool subscriberInitialize();
    bool publisherInitialize();

    bool hardwareDestroy();
    bool softwareDestroy();

    bool checkLisence();
};

inline void IStarter::SetDefaultSubscribePrefix(const QString &strDefaultPrefix)
{
    m_strDefaultPrefix = strDefaultPrefix;
}

inline void IStarter::SetPublishTopicPrefix(const QString &strPublishTopicPrefix)
{
    m_strPublishTopicPrefix = strPublishTopicPrefix;
}

#endif // ISTARTER_H
