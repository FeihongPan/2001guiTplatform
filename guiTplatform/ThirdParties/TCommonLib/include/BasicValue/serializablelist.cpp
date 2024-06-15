#include "serializablelist.h"

S_List_String::S_List_String()
{

}

S_List_String::S_List_String(const S_List_String &lst)
{
    this->values = lst.values;
}

S_List_String::S_List_String(const QStringList &lst)
{
    this->values.clear();
    for(int i = 0; i < lst.count(); ++i)
    {
        this->values.append(lst[i]);
    }
}

S_List_String &S_List_String::operator=(const S_List_String &lst)
{
    this->values = lst.values;
    return *this;
}

S_List_String &S_List_String::operator=(const QStringList &lst)
{
    this->values.clear();
    for(int i = 0; i < lst.count(); ++i)
    {
        this->values.append(lst[i]);
    }
    return *this;
}

S_List_Bool::S_List_Bool()
{

}

S_List_Bool::S_List_Bool(const S_List_Bool &lst)
{
    this->values = lst.values;
}

S_List_Bool::S_List_Bool(const QList<bool> &lst)
{
    this->values.clear();
    for(int i = 0; i < lst.count(); ++i)
    {
        this->values.append(lst[i]);
    }
}

S_List_Bool &S_List_Bool::operator=(const S_List_Bool &lst)
{
    this->values = lst.values;
    return *this;
}

S_List_Bool &S_List_Bool::operator=(const QList<bool> &lst)
{
    this->values.clear();
    for(int i = 0; i < lst.count(); ++i)
    {
        this->values.append(lst[i]);
    }
    return *this;
}

S_List_Double::S_List_Double()
{

}

S_List_Double::S_List_Double(const S_List_Double &lst)
{
    this->values = lst.values;
}

S_List_Double::S_List_Double(const QList<double> &lst)
{
    this->values.clear();
    for(int i = 0; i < lst.count(); ++i)
    {
        this->values.append(lst[i]);
    }
}

S_List_Double::S_List_Double(const SR_List_Double &lst)
{
    this->values.clear();
    for(int i = 0; i < lst.values.count(); ++i)
    {
        this->values.append(lst.values[i].value);
    }
}

S_List_Double &S_List_Double::operator=(const S_List_Double &lst)
{
    this->values = lst.values;
    return *this;
}

S_List_Double &S_List_Double::operator=(const QList<double> &lst)
{
    this->values.clear();
    for(int i = 0; i < lst.count(); ++i)
    {
        this->values.append(lst[i]);
    }
    return *this;
}

S_List_Double &S_List_Double::operator=(const SR_List_Double &lst)
{
    this->values.clear();
    for(int i = 0; i < lst.values.count(); ++i)
    {
        this->values.append(lst.values[i].value);
    }
    return *this;
}

SR_List_Double::SR_List_Double() : TValueBase()
{

}

SR_List_Double::SR_List_Double(const S_List_Double &lst) : TValueBase()
{
    this->values.clear();
    for(int i = 0; i < lst.values.count(); ++i)
    {
        this->values.append(lst.values[i]);
    }
}

SR_List_Double::SR_List_Double(const QList<double> &lst) : TValueBase()
{
    this->values.clear();
    for(int i = 0; i < lst.count(); ++i)
    {
        this->values.append(lst[i]);
    }
}

SR_List_Double::SR_List_Double(const SR_List_Double &lst) : TValueBase(lst)
{
    this->values = lst.values;
}

SR_List_Double &SR_List_Double::operator=(const S_List_Double &lst)
{
    this->values.clear();
    for(int i = 0; i < lst.values.count(); ++i)
    {
        this->values.append(lst.values[i]);
    }
    return *this;
}

SR_List_Double &SR_List_Double::operator=(const QList<double> &lst)
{
    this->values.clear();
    for(int i = 0; i < lst.count(); ++i)
    {
        this->values.append(lst[i]);
    }
    return *this;
}

SR_List_Double &SR_List_Double::operator=(const SR_List_Double &lst)
{
    TValueBase::operator=(lst);
    this->values = lst.values;
    return *this;
}
