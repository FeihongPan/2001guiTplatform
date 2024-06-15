#ifndef SERIALIZABLEDIC_H
#define SERIALIZABLEDIC_H

#include "TCommonLib_global.h"
#include "Serializer/QSerializer"

class TCOMMONLIB_EXPORT S_Dic_StringBool : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_QT_DICT(QMap, QString, bool, values)

public:
    S_Dic_StringBool();
    S_Dic_StringBool(const S_Dic_StringBool &dic);
    S_Dic_StringBool(const QMap<QString, bool> &dic);
    S_Dic_StringBool &operator=(const S_Dic_StringBool &dic);
    S_Dic_StringBool &operator=(const QMap<QString, bool> &dic);
};

class TCOMMONLIB_EXPORT S_Dic_IntString : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_QT_DICT(QMap, int, QString, values)

public:
    S_Dic_IntString();
    S_Dic_IntString(const S_Dic_IntString &dic);
    S_Dic_IntString(const QMap<int, QString> &dic);
    S_Dic_IntString &operator=(const S_Dic_IntString &dic);
    S_Dic_IntString &operator=(const QMap<int, QString> &dic);
};

class TCOMMONLIB_EXPORT S_Dic_IntBool : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_QT_DICT(QMap, int, bool, values)

public:
    S_Dic_IntBool();
    S_Dic_IntBool(const S_Dic_IntBool &dic);
    S_Dic_IntBool(const QMap<int, bool> &dic);
    S_Dic_IntBool &operator=(const S_Dic_IntBool &dic);
    S_Dic_IntBool &operator=(const QMap<int, bool> &dic);
};

class TCOMMONLIB_EXPORT S_Dic_StringString : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_QT_DICT(QMap, QString, QString, values);

public:
    S_Dic_StringString();
    S_Dic_StringString(const S_Dic_StringString &dic);
    S_Dic_StringString(const QMap<QString, QString> &dic);
    S_Dic_StringString &operator=(const S_Dic_StringString &dic);
    S_Dic_StringString &operator=(const QMap<QString, QString> &dic);
};

#endif // SERIALIZABLEDIC_H
