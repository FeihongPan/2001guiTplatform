#ifndef DEVICEID_H
#define DEVICEID_H

#include "TCommonLib_global.h"

#include "Serializer/QSerializer"

class TCOMMONLIB_EXPORT DeviceID : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(QString, uuid)
    QS_FIELD(QString, cpuId)
    QS_FIELD(QString, baseBoardNum)
    QS_FIELD(QString, biosNum)
    QS_FIELD(QString, diskNum)
    QS_FIELD(QByteArray, deviceMesaage)

public:
    DeviceID();
    bool operator==(const DeviceID &id);
    bool operator!=(const DeviceID &id);
};

#endif // DEVICEID_H
