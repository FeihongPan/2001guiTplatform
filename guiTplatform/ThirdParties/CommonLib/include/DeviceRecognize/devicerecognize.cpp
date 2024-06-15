#include "devicerecognize.h"

#include <QProcess>

QString DeviceRecognize::GetUUID()
{
    return getInfo("wmic csproduct get uuid");
}

QString DeviceRecognize::GetCpuId()
{
    return getInfo("wmic cpu get processorid");
}

QString DeviceRecognize::GetBaseBoardNum()
{
    return getInfo("wmic baseboard get serialnumber");
}

QString DeviceRecognize::GetBiosNum()
{
    return getInfo("wmic bios get serialnumber");
}

QString DeviceRecognize::GetDiskNum()
{
    return getInfo("wmic diskdrive where index=0 get serialnumber");
}

QString DeviceRecognize::getInfo(const QString &cmd)
{
    QProcess p;
    p.start(cmd);
    p.waitForFinished();

    QString result = QString::fromLocal8Bit(p.readAllStandardOutput());
    QStringList list = cmd.split(" ");
    result = result.remove(list.last(), Qt::CaseInsensitive);
    result = result.replace("\r", "");
    result = result.replace("\n", "");
    result = result.simplified();

    p.kill();
    p.close();

    return result;
}
