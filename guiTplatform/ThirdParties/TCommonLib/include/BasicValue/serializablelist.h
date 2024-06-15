#ifndef SERIALIZABLESTRINGLIST_H
#define SERIALIZABLESTRINGLIST_H

#include "TCommonLib_global.h"
#include "tvalue.h"

class TCOMMONLIB_EXPORT S_List_String : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, QString, values)

public:
    S_List_String();
    S_List_String(const S_List_String &lst);
    S_List_String(const QStringList &lst);
    S_List_String &operator=(const S_List_String &lst);
    S_List_String &operator=(const QStringList &lst);
};

class TCOMMONLIB_EXPORT S_List_Bool : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, bool, values)

public:
    S_List_Bool();
    S_List_Bool(const S_List_Bool &lst);
    S_List_Bool(const QList<bool> &lst);
    S_List_Bool &operator=(const S_List_Bool &lst);
    S_List_Bool &operator=(const QList<bool> &lst);
};

class SR_List_Double;

class TCOMMONLIB_EXPORT S_List_Double : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, double, values)

public:
    S_List_Double();
    S_List_Double(const S_List_Double &lst);
    S_List_Double(const QList<double> &lst);
    S_List_Double(const SR_List_Double &lst);
    S_List_Double &operator=(const S_List_Double &lst);
    S_List_Double &operator=(const QList<double> &lst);
    S_List_Double &operator=(const SR_List_Double &lst);
};

class TCOMMONLIB_EXPORT SR_List_Double : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, TDouble, values)

public:
    SR_List_Double();
    SR_List_Double(const S_List_Double &lst);
    SR_List_Double(const QList<double> &lst);
    SR_List_Double(const SR_List_Double &lst);
    SR_List_Double &operator=(const S_List_Double &lst);
    SR_List_Double &operator=(const QList<double> &lst);
    SR_List_Double &operator=(const SR_List_Double &lst);
};

#endif // SERIALIZABLESTRINGLIST_H
