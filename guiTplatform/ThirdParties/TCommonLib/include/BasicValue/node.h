#ifndef NODE_H
#define NODE_H

#include "TCommonLib_global.h"

#include "Serializer/QSerializer"

#define toStr(name) (#name)

class TCOMMONLIB_EXPORT ValueType : public QObject
{
    Q_OBJECT

public:
    enum Type
    {
        Value_String,
        Value_Int,
        Value_Double,
        Value_Bool,
        Value_Enum,
        Value_Complex,
        Value_List,
    };
    Q_ENUM(Type)
};

class TCOMMONLIB_EXPORT TValueBase : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(QString, valueName)
    QS_FIELD(QString, brief)
    QS_FIELD(QString, unit)
    QS_FIELD(ValueType::Type, valueType)

public:
    TValueBase();
    TValueBase(const TValueBase &tv);
    TValueBase(TValueBase *parent);

    void SetParent(TValueBase *parent);
    void SetPropertyChanged(bool r);
    bool PropertyChanged = true;

    TValueBase *parent;
    QList<TValueBase *> children;
};

#endif // NODE_H
