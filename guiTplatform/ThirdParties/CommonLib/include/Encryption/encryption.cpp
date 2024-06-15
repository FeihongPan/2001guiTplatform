#include "encryption.h"

#include "qaesencryption.h"

#include <QDebug>
#include <QProcess>
#include <QException>
#include <QCryptographicHash>

QString Encryption::DecodedText(const QString &data, const QString &key)
{
    try
    {
        QAESEncryption encryption(QAESEncryption::AES_128, QAESEncryption::ECB, QAESEncryption::ZERO);
        QByteArray hashKey = QCryptographicHash::hash(key.toUtf8(), QCryptographicHash::Md5);
        QByteArray decodedText = encryption.decode(QByteArray::fromBase64(data.toLatin1()), hashKey);
        QString decodedTextStr = QString::fromLatin1(decodedText);
        return decodedTextStr;
    }
    catch (...)
    {
        qDebug() << __FUNCTION__ << "Fail";
        return QString();
    }
}
