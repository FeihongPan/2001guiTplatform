#include "JsonTreeItem_mc.h"

#include <QDebug>

JsonTreeItem_MC::JsonTreeItem_MC(JsonTreeItem_MC *parent)
    : theParentItem(parent), theItemType(JsonTreeItem_MC::None)
{

}

JsonTreeItem_MC::JsonTreeItem_MC(const QHash<int, QVariant> &datas, JsonTreeItem_MC::JsonItemType type, JsonTreeItem_MC *parent)
    : theParentItem(parent), theItemType(type), theItemDatas(datas)
{

}

JsonTreeItem_MC::~JsonTreeItem_MC()
{
    deleteAllChild();
}

bool JsonTreeItem_MC::insertChild(int row, JsonTreeItem_MC *child)
{
    if(row < 0 || row > theChildItems.count())
    {
        return false;
    }
    theChildItems.insert(row, child);
    child->setParentItem(this);
    return true;
}

bool JsonTreeItem_MC::removeChild(int row)
{
    if(row < 0 || row + 1 > theChildItems.count())
    {
        return false;
    }
    delete theChildItems.takeAt(row);
    return true;
}

bool JsonTreeItem_MC::insertChildren(int row, int count)
{
    if(row < 0 || row > theChildItems.count())
    {
        return false;
    }
    for(int i = 0; i < count; i++)
    {
        JsonTreeItem_MC *item = new JsonTreeItem_MC(this);
        item->setType(JsonTreeItem_MC::Value);
        theChildItems.insert(row, item);
    }
    return true;
}

bool JsonTreeItem_MC::removeChildren(int row, int count)
{
    if (row < 0 || row + count > theChildItems.count())
    {
        return false;
    }
    for(int i = 0; i < count; i++)
    {
        delete theChildItems.takeAt(row + i);
    }
    return true;
}

void JsonTreeItem_MC::appendChild(JsonTreeItem_MC *child)
{
    theChildItems.append(child);
    child->setParentItem(this);
}

void JsonTreeItem_MC::deleteAllChild()
{
    qDeleteAll(theChildItems);
    theChildItems.clear();
}

JsonTreeItem_MC *JsonTreeItem_MC::childItem(int row)
{
    return theChildItems.value(row);
}

QList<JsonTreeItem_MC *> JsonTreeItem_MC::children()
{
    return theChildItems;
}

JsonTreeItem_MC *JsonTreeItem_MC::parentItem()
{
    return theParentItem;
}

void JsonTreeItem_MC::setParentItem(JsonTreeItem_MC *parent)
{
    theParentItem = parent;
}

int JsonTreeItem_MC::childCount() const
{
    return theChildItems.count();
}

int JsonTreeItem_MC::columnCount() const
{
    return theItemDatas.count();
}

void JsonTreeItem_MC::setTag(const QString &key, const QString &tagValue)
{
    m_tagMap[key] = tagValue;
}

QString JsonTreeItem_MC::getTag(const QString &key)
{
    if(m_tagMap.contains(key))
    {
        return m_tagMap[key];
    }
    return EMPTY_STRING_FLAG;
}

bool JsonTreeItem_MC::tagContains(const QString &key)
{
    return m_tagMap.contains(key);
}

void JsonTreeItem_MC::setReadOnly(bool readOnly)
{
    m_bIsReadOnly = readOnly;
    for(JsonTreeItem_MC *childItem : qAsConst(theChildItems))
    {
        childItem->setReadOnly(readOnly);
    }
}

QJsonValue JsonTreeItem_MC::getJson()
{
    return m_json;
}

void JsonTreeItem_MC::setJson(const QJsonValue &json)
{
    m_json = json;
}

QVariant JsonTreeItem_MC::data(int column) const
{
    return theItemDatas.value(column, QVariant());
}

void JsonTreeItem_MC::setData(int column, const QVariant &val)
{
    theItemDatas.insert(column, val);
}

void JsonTreeItem_MC::showValue(void)
{
    int iValType = getTag("valueType").toInt();
    const int ValueColumn = 1;
    QString strVal = getTag("view-value");

    switch (iValType)
    {
        case ValueType::Value_String:
            theItemDatas.insert(ValueColumn, strVal);
            break;
        case ValueType::Value_Int:
            theItemDatas.insert(ValueColumn, strVal.toInt());
            break;
        case ValueType::Value_Double:
            theItemDatas.insert(ValueColumn, strVal.toDouble());
            break;
        case ValueType::Value_Bool:
            theItemDatas.insert(ValueColumn, strVal.toInt());
            break;
        case ValueType::Value_Enum:
        {
            QJsonArray dataSource = m_json.toArray();
            QString strEnum = dataSource[strVal.toInt()].toString();

            theItemDatas.insert(ValueColumn, strEnum);
        }
        break;
        case ValueType::Value_Complex:
            theItemDatas.insert(ValueColumn, strVal.toDouble());
            break;
        case ValueType::Value_List:
            theItemDatas.insert(ValueColumn, strVal);
            break;
        default:
            qDebug() << "error value type";
            break;
    }
}


int JsonTreeItem_MC::row() const
{
    if(theParentItem)
    {
        return theParentItem->theChildItems.indexOf(const_cast<JsonTreeItem_MC *>(this));
    }
    return 0;
}

bool JsonTreeItem_MC::editable(int column) const
{
    if(m_bIsReadOnly)
    {
        return (theParentItem && theParentItem->parentItem()
                && 0 != column
                && 1 != column
                && 2 != column
                && 3 != column
                && 4 != column
                && 5 != column);
    }
    else
    {
        return theParentItem && theParentItem->parentItem() && 0 != column;
    }
}

QString JsonTreeItem_MC::key() const
{
    return theItemDatas.value(0, "").toString();
}

void JsonTreeItem_MC::setKey(const QString &key)
{
    theItemDatas[0] = key;
}

QVariant JsonTreeItem_MC::value() const
{
    return theItemDatas.value(1, 0);
}

void JsonTreeItem_MC::setValue(const QVariant &value)
{
    theItemDatas[1] = value;
}

JsonTreeItem_MC::JsonItemType JsonTreeItem_MC::type() const
{
    return theItemType;
}

void JsonTreeItem_MC::setType(JsonTreeItem_MC::JsonItemType type)
{
    theItemType = type;
}

