#ifndef ENUMCONVERTER_H
#define ENUMCONVERTER_H

#include "CommonLib_global.h"

#include <QObject>
#include <QMetaEnum>

class COMMONLIB_EXPORT EnumConverter : public QObject
{
    Q_OBJECT

public:
    template<typename T>
    static QString ConvertToString(const T &type)
    {
        QMetaEnum metaEnum = QMetaEnum::fromType<T>();
        return metaEnum.valueToKey(type);
    }

    template<typename T>
    static QStringList ConvertToStringList()
    {
        QStringList lst;
        QMetaEnum metaEnum = QMetaEnum::fromType<T>();
        for(int i = 0; i < metaEnum.keyCount(); ++i)
        {
            lst.append(metaEnum.key(i));
        }
        return lst;
    }

    template<typename T>
    static QByteArray ConvertToQByteArray()
    {
        QStringList lst;
        QMetaEnum metaEnum = QMetaEnum::fromType<T>();
        for(int i = 0; i < metaEnum.keyCount(); ++i)
        {
            lst.append(metaEnum.key(i));
        }

        QString joinedString = lst.join(",");
        QByteArray byteArray = joinedString.toUtf8();
        return byteArray;
    }

    template<typename T>
    static QList<int> ConvertToIntList()
    {
        QList<int> lst;
        QMetaEnum metaEnum = QMetaEnum::fromType<T>();
        for(int i = 0; i < metaEnum.keyCount(); ++i)
        {
            lst.append(static_cast<T>(metaEnum.keyToValue(metaEnum.key(i))));
        }
        return lst;
    }

    template<typename T>
    static T ConvertStringToEnum(const QString &type)
    {
        QMetaEnum metaEnum = QMetaEnum::fromType<T>();
        std::string str = type.toStdString();
        return static_cast<T>(metaEnum.keyToValue(str.c_str()));
    }

    template<typename T>
    static QString ConvertIntToString(int index)
    {
        return ConvertToString((T)index);
    }

    template<typename T>
    static int GetEnumCount()
    {
        QMetaEnum metaEnum = QMetaEnum::fromType<T>();
        return metaEnum.keyCount();
    }

    template<typename T>
    static QMap<int, QString> ConvertToIntStringDic()
    {
        QMap<int, QString> dic;
        QMetaEnum metaEnum = QMetaEnum::fromType<T>();
        for(int i = 0; i < metaEnum.keyCount(); ++i)
        {
            dic.insert(static_cast<T>(metaEnum.keyToValue(metaEnum.key(i))), metaEnum.key(i));
        }
        return dic;
    }
};

#endif // ENUMCONVERTER_H
