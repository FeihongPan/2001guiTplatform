#ifndef OTHERS_H
#define OTHERS_H

#include "TCommonLib_global.h"
#include "tvalue.h"

class SR_IPAddress;

class TCOMMONLIB_EXPORT S_IPAddress : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(QString, IP)
    QS_FIELD(int, port)

public:
    S_IPAddress();
    S_IPAddress(const SR_IPAddress &ip);
    S_IPAddress(const S_IPAddress &ip);
    S_IPAddress &operator=(const SR_IPAddress &ip);
    S_IPAddress &operator=(const S_IPAddress &ip);
};

class TCOMMONLIB_EXPORT SR_IPAddress : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TString, IP)
    QS_OBJECT(TInt, port)

public:
    SR_IPAddress();
    SR_IPAddress(const SR_IPAddress &ip);
    SR_IPAddress(const S_IPAddress &ip);
    SR_IPAddress &operator=(const SR_IPAddress &ip);
    SR_IPAddress &operator=(const S_IPAddress &ip);
};


class TCOMMONLIB_EXPORT S_TimeSlot : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE
    QS_FIELD(QString, dateTimeStart)
    QS_FIELD(QString, dateTimeEnd)

public:
    S_TimeSlot();
    S_TimeSlot(const S_TimeSlot &info);
    S_TimeSlot &operator=(const S_TimeSlot &info);
};

#endif // OTHERS_H
