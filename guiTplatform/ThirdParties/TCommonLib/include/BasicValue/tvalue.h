#ifndef TVALUE_H
#define TVALUE_H

#include "TCommonLib_global.h"
#include "node.h"
#include "Converter/enumconverter.h"

class TCOMMONLIB_EXPORT TInt : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(int, value)
    QS_FIELD(int, min)
    QS_FIELD(int, max)

public:
    TInt();
    TInt(int val);
    TInt(const TInt &val);
    TInt(TValueBase *parent);
    TInt &operator=(const TInt &val);
    TInt &operator=(const int &val);

    bool SetValue(int value);
    bool SetMaximum(int max);
    bool SetMinimum(int min);
    bool SetValue(int value, int min, int max);
    bool SetRange(int min, int max);
    void SetProperty(QString name, int min, int max, QString unit = QString(), QString brief = QString());
};

class TCOMMONLIB_EXPORT TDouble : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, value)
    QS_FIELD(double, min)
    QS_FIELD(double, max)
    QS_FIELD(int, precision)

public:
    TDouble();
    TDouble(double val);
    TDouble(const TDouble &val);
    TDouble(TValueBase *parent);
    TDouble &operator=(const TDouble &val);
    TDouble &operator=(const double &val);

    bool SetValue(double value);
    bool SetMaximum(double max);
    bool SetMinimum(double min);
    bool SetValue(double value, double min, double max);
    bool SetRange(double min, double max);
    void SetPrecision(uint pcs);
    void SetProperty(QString name, double min, double max, int pcs = 3, QString unit = QString(), QString brief = QString());
};

class TCOMMONLIB_EXPORT TBool : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(bool, value)

public:
    TBool();
    TBool(bool val);
    TBool(const TBool &val);
    TBool(TValueBase *parent);
    TBool &operator=(const TBool &val);
    TBool &operator=(const bool &val);

    bool SetValue(bool value);
};

class TCOMMONLIB_EXPORT TString : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(QString, value)
    QS_FIELD(int, length_min)
    QS_FIELD(int, length_max)

public:
    TString();
    TString(const QString &str);
    TString(const TString &str);
    TString(TValueBase *parent);
    TString &operator=(const TString &str);
    TString &operator=(const QString &str);

    bool SetValue(QString value);
    bool SetMaxLength(int maxLenght);
    bool SetMinLength(int minLenght);
    bool SetValue(QString value, int minLenght, int maxLenght);
    bool SetRange(int minLenght, int maxLenght);
};

class TCOMMONLIB_EXPORT TEnum : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(int, value)
    QS_FIELD(QStringList, dataSource)

public:
    TEnum();
    TEnum(TValueBase *parent);
    TEnum(const TEnum &val);
    TEnum &operator=(const TEnum &val);
    TEnum &operator=(const int &val);

    bool SetValue(int value);

    template<class T>
    void SetEnumValue(int value)
    {
        this->value = value;
        this->dataSource = EnumConverter::ConvertToStringList<T>();
        this->PropertyChanged = true;
    }

    template<typename T>
    T Value()
    {
        return EnumConverter::ConvertStringToEnum<T>(dataSource.at(value));
    }
};

#endif // TVALUE_H
