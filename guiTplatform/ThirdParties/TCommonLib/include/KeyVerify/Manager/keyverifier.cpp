#include "keyverifier.h"
#include "KeyVerify/Command/cmd_keyverify.h"
#include "Converter/enumconverter.h"

#include "FileSystem/filesystem.h"
#include "Encryption/encryption.h"
#include "DeviceRecognize/devicerecognize.h"
#include "FileSystem/fileoperatormanager.h"

#include <QDateTime>
#include <QMutex>
#include <QDebug>

KeyVerifier *KeyVerifier::self = NULL;
KeyVerifier::KeyVerifier(QString name, QObject *parent) : QObject(parent), IPublish(name), IFileOperator(name)
{

}

KeyVerifier *KeyVerifier::getInstance()
{
    if(self == NULL)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == NULL)
        {
            self = new KeyVerifier("KeyVerifier");
        }
    }
    return self;
}

void KeyVerifier::Initialize()
{

}

void KeyVerifier::GetDeviceID()
{
    m_DeviceID.uuid = DeviceRecognize::GetUUID();
    m_DeviceID.cpuId = DeviceRecognize::GetCpuId();
    m_DeviceID.baseBoardNum = DeviceRecognize::GetBaseBoardNum();
    m_DeviceID.biosNum = DeviceRecognize::GetBiosNum();
    m_DeviceID.diskNum = DeviceRecognize::GetDiskNum();
}

bool KeyVerifier::WriteDeviceInfoToFile()
{
    uint dateTime = QDateTime::currentDateTime().toTime_t();
    GetDeviceID();
    m_FileName = QString::number(dateTime) + ".db";
    return WriteToFile(m_DeviceID.toRawJson());
}

bool KeyVerifier::CheckAuthorization()
{
    QStringList lst_Names = FileSystem::GetAllFileNames(m_FolderPath);
    if(lst_Names.count() != 1)
    {
        return false;
    }

    QStringList lst = lst_Names[0].split('.');
    if(lst[0].count() != 2 && lst.last() != "db")
    {
        return false;
    }

    QString key = lst[0];
    QByteArray data;
    m_FileName = lst_Names[0];
    if(!ReadFromFile(data))
    {
        return false;
    }
    QString res = Encryption::DecodedText(data, key);
    QStringList lst_Context = res.split('#');
    if(lst_Context.count() != 2)
    {
        return false;
    }

    GetDeviceID();
    DeviceID deviceID;
    deviceID.fromJson(lst_Context[0].toLatin1());
    if(m_DeviceID != deviceID)
    {
        return false;
    }

    if(lst_Context[1] == "Permanent")
    {
        m_bPermanentAuthoritied = true;
        m_AuthorizationDate = QDate::currentDate().addYears(100);
    }
    else
    {
        m_AuthorizationDate = QDate::fromString(lst_Context[1], Qt::DateFormat::ISODate);
    }

    if(QDate::currentDate() > m_AuthorizationDate)
    {
        return false;
    }

    Publish(EnumConverter::ConvertToString(CMD_KeyVerify::CMD_LicenseExpirationDate), true, GetLicenseExpirationDate());

    bool r = false;
    QByteArray licenseState = GetLicenseState(r);
    Publish(EnumConverter::ConvertToString(CMD_KeyVerify::CMD_LicenseState), r, licenseState);
    return true;
}

void KeyVerifier::SetPeriodPublish()
{
    bool r = false;
    m_Publisher.PublishPeriodically(this->m_Topic, EnumConverter::ConvertToString(CMD_KeyVerify::CMD_LicenseState), r,
                                    std::bind(&KeyVerifier::GetLicenseState, this, std::placeholders::_1), 60000);
}

void KeyVerifier::StartPublish()
{

}

void KeyVerifier::SaveCommandInfo()
{
    bool r = false;
    QByteArray resultMsg;
    TaskInfo task;

    resultMsg += "payload:\n";
    resultMsg += QDateTime::currentDateTime().toString(Qt::DateFormat::ISODate).toLatin1() + "\n";
    resultMsg += "Permanent\n";
    resultMsg += "Not authorized\n";
    task.context = GetLicenseExpirationDate();
    task.task = EnumConverter::ConvertToString(CMD_KeyVerify::CMD_LicenseExpirationDate);
    resultMsg += task.toRawJson();

    resultMsg += "payload:\n";
    resultMsg += QByteArray::number(true) + "\n";
    resultMsg += QByteArray::number(false) + "\n";
    task.context = GetLicenseState(r);
    task.task = EnumConverter::ConvertToString(CMD_KeyVerify::CMD_LicenseState);
    resultMsg += task.toRawJson();

    writeCmdSampleToFile(GetTopic(), resultMsg);
}

QByteArray KeyVerifier::GetLicenseExpirationDate()
{
    if(m_bPermanentAuthoritied)
    {
        return "Permanent";
    }
    else
    {
        QString date = m_AuthorizationDate.toString(Qt::DateFormat::ISODate);
        if(date != QString())
        {
            return date.toLatin1();
        }
        else
        {
            return "Not authorized";
        }
    }
}

QByteArray KeyVerifier::GetLicenseState(bool &r)
{
    r = true;
    if(m_bPermanentAuthoritied)
    {
        return QByteArray::number(true);
    }
    else
    {
        return QByteArray::number(QDate::currentDate() < m_AuthorizationDate);
    }
}
