#include "serializabledic.h"

S_Dic_StringBool::S_Dic_StringBool()
{

}

S_Dic_StringBool::S_Dic_StringBool(const S_Dic_StringBool &dic)
{
    this->values = dic.values;
}

S_Dic_StringBool::S_Dic_StringBool(const QMap<QString, bool> &dic)
{
    this->values.clear();
    QMap<QString, bool>::const_iterator it;
    for (it = dic.constBegin(); it != dic.constEnd(); ++it)
    {
        this->values.insert(it.key(), it.value());
    }
}

S_Dic_StringBool &S_Dic_StringBool::operator=(const S_Dic_StringBool &dic)
{
    this->values = dic.values;
    return *this;
}

S_Dic_StringBool &S_Dic_StringBool::operator=(const QMap<QString, bool> &dic)
{
    this->values.clear();
    QMap<QString, bool>::const_iterator it;
    for (it = dic.constBegin(); it != dic.constEnd(); ++it)
    {
        this->values.insert(it.key(), it.value());
    }
    return *this;
}

S_Dic_IntString::S_Dic_IntString()
{

}

S_Dic_IntString::S_Dic_IntString(const S_Dic_IntString &dic)
{
    this->values = dic.values;
}

S_Dic_IntString::S_Dic_IntString(const QMap<int, QString> &dic)
{
    this->values.clear();
    QMap<int, QString>::const_iterator it;
    for (it = dic.constBegin(); it != dic.constEnd(); ++it)
    {
        this->values.insert(it.key(), it.value());
    }
}

S_Dic_IntString &S_Dic_IntString::operator=(const S_Dic_IntString &dic)
{
    this->values = dic.values;
    return *this;
}

S_Dic_IntString &S_Dic_IntString::operator=(const QMap<int, QString> &dic)
{
    this->values.clear();
    QMap<int, QString>::const_iterator it;
    for (it = dic.constBegin(); it != dic.constEnd(); ++it)
    {
        this->values.insert(it.key(), it.value());
    }
    return *this;
}

S_Dic_IntBool::S_Dic_IntBool()
{

}

S_Dic_IntBool::S_Dic_IntBool(const S_Dic_IntBool &dic)
{
    this->values = dic.values;
}

S_Dic_IntBool::S_Dic_IntBool(const QMap<int, bool> &dic)
{
    this->values.clear();
    QMap<int, bool>::const_iterator it;
    for (it = dic.constBegin(); it != dic.constEnd(); ++it)
    {
        this->values.insert(it.key(), it.value());
    }
}

S_Dic_IntBool &S_Dic_IntBool::operator=(const S_Dic_IntBool &dic)
{
    this->values = dic.values;
    return *this;
}

S_Dic_IntBool &S_Dic_IntBool::operator=(const QMap<int, bool> &dic)
{
    this->values.clear();
    QMap<int, bool>::const_iterator it;
    for (it = dic.constBegin(); it != dic.constEnd(); ++it)
    {
        this->values.insert(it.key(), it.value());
    }
    return *this;
}

S_Dic_StringString::S_Dic_StringString()
{

}

S_Dic_StringString::S_Dic_StringString(const S_Dic_StringString &dic)
{
    values = dic.values;
}

S_Dic_StringString::S_Dic_StringString(const QMap<QString, QString> &dic)
{
    this->values.clear();
    QMap<QString, QString>::const_iterator it;
    for (it = dic.constBegin(); it != dic.constEnd(); ++it)
    {
        this->values.insert(it.key(), it.value());
    }
}

S_Dic_StringString &S_Dic_StringString::operator=(const S_Dic_StringString &dic)
{
    values = dic.values;
    return *this;
}

S_Dic_StringString &S_Dic_StringString::operator=(const QMap<QString, QString> &dic)
{
    this->values.clear();
    QMap<QString, QString>::const_iterator it;
    for (it = dic.constBegin(); it != dic.constEnd(); ++it)
    {
        this->values.insert(it.key(), it.value());
    }
    return *this;
}
