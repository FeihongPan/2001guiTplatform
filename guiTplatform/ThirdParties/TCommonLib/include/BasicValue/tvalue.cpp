#include "tvalue.h"

#include <cfloat>

#define toStr(name) (#name)

TInt::TInt()
    : TValueBase()
{
    this->valueType = ValueType::Value_Int;
    this->min = -INT32_MAX;
    this->max = INT32_MAX;
    this->value = 0;
}

TInt::TInt(int val)
    : TValueBase()
{
    this->valueType = ValueType::Value_Int;
    this->min = -INT32_MAX;
    this->max = INT32_MAX;
    this->value = val;
}

TInt::TInt(const TInt &val)
    : TValueBase(val)
{
    this->valueType = ValueType::Value_Int;
    this->min = -INT32_MAX;
    this->max = INT32_MAX;
    this->value = val.value;
}

TInt::TInt(TValueBase *parent)
    : TValueBase(parent)
{
    this->valueType = ValueType::Value_Int;
    this->min = -INT32_MAX;
    this->max = INT32_MAX;
    this->value = 0;
}

TInt &TInt::operator=(const TInt &val)
{
    TValueBase::operator=(val);
    this->value = val.value;
    this->min = val.min;
    this->max = val.max;
    this->PropertyChanged = true;
    return *this;
}

TInt &TInt::operator=(const int &val)
{
    this->value = val;
    this->PropertyChanged = true;
    return *this;
}

bool TInt::SetValue(int value)
{
    if(value <= max && value >= min)
    {
        this->value = value;
        PropertyChanged = true;
        return true;
    }
    return false;
}

bool TInt::SetMaximum(int max)
{
    if(max >= min && max >= value)
    {
        this->max = max;
        PropertyChanged = true;
        return true;
    }
    return false;
}

bool TInt::SetMinimum(int min)
{
    if(min <= max && min <= value)
    {
        this->min = min;
        PropertyChanged = true;
        return true;
    }
    return false;
}

bool TInt::SetValue(int value, int min, int max)
{
    if(value >= min && value <= max)
    {
        this->value = value;
        this->min = min;
        this->max = max;
        PropertyChanged = true;
        return true;
    }
    return false;
}

bool TInt::SetRange(int min, int max)
{
    if(value >= min && value <= max)
    {
        this->min = min;
        this->max = max;
        PropertyChanged = true;
        return true;
    }
    return false;
}

void TInt::SetProperty(QString name, int min, int max, QString unit, QString brief)
{
    this->valueName = name;
    this->min = min;
    this->max = max;
    this->unit = unit;
    this->brief = brief;
    this->PropertyChanged = true;
}

TDouble::TDouble()
    : TValueBase()
{
    this->valueType = ValueType::Value_Double;
    this->min = -DBL_MAX;
    this->max = DBL_MAX;
    this->precision = 3;
    this->value = 0;
}

TDouble::TDouble(double val)
    : TValueBase()
{
    this->valueType = ValueType::Value_Double;
    this->min = -DBL_MAX;
    this->max = DBL_MAX;
    this->precision = 3;
    this->value = val;
}

TDouble::TDouble(const TDouble &val)
    : TValueBase(val)
{
    this->valueType = ValueType::Value_Double;
    this->min = -DBL_MAX;
    this->max = DBL_MAX;
    this->precision = 3;
    this->value = val.value;
}

TDouble::TDouble(TValueBase *parent)
    : TValueBase(parent)
{
    this->valueType = ValueType::Value_Double;
    this->min = -DBL_MAX;
    this->max = DBL_MAX;
    this->precision = 3;
    this->value = 0;
}

TDouble &TDouble::operator=(const TDouble &val)
{
    TValueBase::operator=(val);

    this->value = val.value;
    this->min = val.min;
    this->max = val.max;
    this->precision = val.precision;
    this->PropertyChanged = true;
    return *this;
}

TDouble &TDouble::operator=(const double &val)
{
    this->value = val;
    this->PropertyChanged = true;
    return *this;
}

bool TDouble::SetValue(double value)
{
    if(value <= max && value >= min)
    {
        this->value = value;
        PropertyChanged = true;
        return true;
    }
    return false;
}

bool TDouble::SetMaximum(double max)
{
    if(max >= min && max >= value)
    {
        this->max = max;
        PropertyChanged = true;
        return true;
    }
    return false;
}

bool TDouble::SetMinimum(double min)
{
    if(min <= max && min <= value)
    {
        this->min = min;
        PropertyChanged = true;
        return true;
    }
    return false;
}

bool TDouble::SetValue(double value, double min, double max)
{
    if(value >= min && value <= max)
    {
        this->value = value;
        this->min = min;
        this->max = max;
        PropertyChanged = true;
        return true;
    }
    return false;
}

bool TDouble::SetRange(double min, double max)
{
    if(value >= min && value <= max)
    {
        this->min = min;
        this->max = max;
        PropertyChanged = true;
        return true;
    }
    return false;
}

void TDouble::SetPrecision(uint pcs)
{
    if(pcs >= 0 && pcs <= 323)
    {
        this->precision = pcs;
    }
    PropertyChanged = true;
}

void TDouble::SetProperty(QString name, double min, double max, int pcs, QString unit, QString brief)
{
    this->valueName = name;
    this->min = min;
    this->max = max;
    this->unit = unit;
    this->brief = brief;
    if(pcs >= 0 && pcs <= 323)
    {
        this->precision = pcs;
    }
    else
    {
        this->precision = 3;
    }
    this->PropertyChanged = true;
}

TBool::TBool()
    : TValueBase()
{
    this->valueType = ValueType::Value_Bool;
}

TBool::TBool(bool val)
    : TValueBase()
{
    this->valueType = ValueType::Value_Bool;
    this->value = val;
}

TBool::TBool(const TBool &val)
    : TValueBase(val)
{
    this->valueType = ValueType::Value_Bool;
    this->value = val.value;
}

TBool &TBool::operator=(const TBool &val)
{
    TValueBase::operator=(val);

    this->value = val.value;
    this->PropertyChanged = true;
    return *this;
}

TBool &TBool::operator=(const bool &val)
{
    this->value = val;
    this->PropertyChanged = true;
    return *this;
}

TBool::TBool(TValueBase *parent)
    : TValueBase(parent)
{
    this->valueType = ValueType::Value_Bool;
}

bool TBool::SetValue(bool value)
{
    this->value = value;
    PropertyChanged = true;
    return true;
}

TString::TString()
    : TValueBase()
{
    this->valueType = ValueType::Value_String;
    this->length_min = 0;
    this->length_max = INT32_MAX;
    this->value = QString();
}

TString::TString(const QString &str)
{
    this->valueType = ValueType::Value_String;
    this->length_min = 0;
    this->length_max = INT32_MAX;
    this->value = str;
}

TString::TString(const TString &str)
    : TValueBase(str)
{
    this->valueType = ValueType::Value_String;
    this->value = str.value;
    this->length_min = str.length_min;
    this->length_max = str.length_max;
}

TString::TString(TValueBase *parent)
    : TValueBase(parent)
{
    this->valueType = ValueType::Value_String;
    this->length_min = 0;
    this->length_max = INT32_MAX;
    this->value = QString();
}

TString &TString::operator=(const TString &str)
{
    TValueBase::operator=(str);

    this->value = str.value;
    this->length_min = str.length_min;
    this->length_max = str.length_max;
    this->PropertyChanged = true;
    return *this;
}

TString &TString::operator=(const QString &str)
{
    this->value = str;
    this->PropertyChanged = true;
    return *this;
}

bool TString::SetValue(QString value)
{
    if(value.length() <= length_max && value.length() >= length_min)
    {
        this->value = value;
        PropertyChanged = true;
        return true;
    }
    return false;
}

bool TString::SetMaxLength(int maxLenght)
{
    if(maxLenght >= value.length())
    {
        this->length_max = maxLenght;
        PropertyChanged = true;
        return true;
    }
    return false;
}

bool TString::SetMinLength(int minLenght)
{
    if(minLenght >= 0 && minLenght <= value.length())
    {
        this->length_min = minLenght;
        PropertyChanged = true;
        return true;
    }
    return false;
}

bool TString::SetValue(QString value, int minLenght, int maxLenght)
{
    if(minLenght >= 0 && value.length() >= minLenght && value.length() <= maxLenght)
    {
        this->value = value;
        this->length_min = minLenght;
        this->length_max = maxLenght;
        PropertyChanged = true;
        return true;
    }
    return false;
}

bool TString::SetRange(int minLenght, int maxLenght)
{
    this->length_min = minLenght;
    this->length_max = maxLenght;
    this->PropertyChanged = true;
    return true;
}

TEnum::TEnum(): TValueBase()
{
    this->valueType = ValueType::Value_Enum;
}

TEnum::TEnum(TValueBase *parent)
    : TValueBase(parent)
{
    this->valueType = ValueType::Value_Enum;
}

TEnum::TEnum(const TEnum &val)
    : TValueBase(val)
{
    this->value = val.value;
    this->dataSource = val.dataSource;
    this->PropertyChanged = true;
}

TEnum &TEnum::operator=(const TEnum &val)
{
    TValueBase::operator=(val);

    this->value = val.value;
    this->dataSource = val.dataSource;
    this->PropertyChanged = true;
    return *this;
}

TEnum &TEnum::operator=(const int &val)
{
    SetValue(val);
    return *this;
}

bool TEnum::SetValue(int value)
{
    if(value < dataSource.count())
    {
        this->value = value;
        SetPropertyChanged(true);
        return true;
    }
    return false;
}
