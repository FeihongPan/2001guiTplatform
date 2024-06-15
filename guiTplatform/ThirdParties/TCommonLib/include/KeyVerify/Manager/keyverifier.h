#ifndef KEYVERIFIER_H
#define KEYVERIFIER_H

#include "TCommonLib_global.h"
//#include "AppConfig/Data/appconfig.h"
#include "KeyVerify/Data/deviceid.h"
#include "Communication/MQTT/ipublish.h"
#include "FileSystem/ifileoperator.h"

#include <QObject>
#include <QDateTime>

class TCOMMONLIB_EXPORT KeyVerifier : public QObject, public IPublish, public IFileOperator
{
    Q_OBJECT
public:
    explicit KeyVerifier(QString name, QObject *parent = nullptr);
    static KeyVerifier *getInstance();

    void Initialize();
    void GetDeviceID();
    bool WriteDeviceInfoToFile();
    bool CheckAuthorization();
    QByteArray GetLicenseExpirationDate();
    QByteArray GetLicenseState(bool &r);

signals:

protected:
    virtual void SetPeriodPublish() override;
    virtual void StartPublish() override;
    virtual void SaveCommandInfo() override;

private:
    static KeyVerifier *self;

    DeviceID m_DeviceID;
    QDate m_AuthorizationDate;
    bool m_bPermanentAuthoritied = false;
};

#endif // KEYVERIFIER_H
