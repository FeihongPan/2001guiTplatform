#include "keyverifysubscriber.h"
#include "KeyVerify/Command/cmd_keyverify.h"
#include "Converter/enumconverter.h"
#include "KeyVerify/Manager/keyverifier.h"

#include <QMutex>

KeyVerifySubscriber *KeyVerifySubscriber::self = NULL;
KeyVerifySubscriber::KeyVerifySubscriber(QString name, QObject *parent) : ISubscriber(name, parent)
{

}

KeyVerifySubscriber *KeyVerifySubscriber::getInstance()
{
    if(self == NULL)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == NULL)
        {
            self = new KeyVerifySubscriber("KeyVerifySubscriber");
        }
    }
    return self;
}

void KeyVerifySubscriber::decoding(const QString &topic, const QByteArray &message)
{
    TaskInfo task_Recived;
    task_Recived.fromJson(message);
    CMD_KeyVerify::Command cmd = EnumConverter::ConvertStringToEnum<CMD_KeyVerify::Command>(task_Recived.task);
    switch (cmd)
    {
        case CMD_KeyVerify::CMD_LicenseExpirationDate:
        {
            QByteArray result;
            result = KeyVerifier::getInstance()->GetLicenseExpirationDate();
            emit sig_LicenseExpirationDate(task_Recived.context);
            KeyVerifier::getInstance()->Publish(EnumConverter::ConvertToString(cmd), true, result);
        }
        break;

        case CMD_KeyVerify::CMD_LicenseState:
        {
            bool r = false;
            QByteArray result;
            result = KeyVerifier::getInstance()->GetLicenseState(r);
            emit sig_LicenseState(task_Recived.context.toUShort());
            KeyVerifier::getInstance()->Publish(EnumConverter::ConvertToString(cmd), true, result);
        }
        break;
        default:
            break;
    }
}
