#include "JsonTreeModel_mc.h"

#include "AuthorityManage/Data/userinfo.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>


JsonTreeModel_MC::JsonTreeModel_MC(QObject *parent)
    : QAbstractItemModel(parent), theRootItem(new JsonTreeItem_MC(nullptr))
{
    theRootItem->setType(JsonTreeItem_MC::Object);
}

JsonTreeModel_MC::~JsonTreeModel_MC()
{
    delete theRootItem;
}

bool JsonTreeModel_MC::loadJson(const QString &filepath)
{
    if(filepath.isEmpty())
    {
        return false;
    }
    QFile file(filepath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }
    const QByteArray raw_data = file.readAll();
    file.close();

    QJsonParseError json_error;
    QJsonDocument json_doc = QJsonDocument::fromJson(raw_data, &json_error);
    if(json_doc.isNull() || json_doc.isEmpty() || json_error.error != QJsonParseError::NoError)
    {
        return false;
    }
    QJsonObject obj = json_doc.object();


    emit beginResetModel();
    theRootItem->deleteAllChild();
    parseValue("root", obj, theRootItem);
    emit endResetModel();

    return true;
}

bool JsonTreeModel_MC::loadJson(const QByteArray &data)
{
    QJsonParseError json_error;
    QJsonDocument json_doc = QJsonDocument::fromJson(data, &json_error);
    QJsonValue json = json_doc.object();


    emit beginResetModel();
    theRootItem->deleteAllChild();

    if(!json_doc.isNull() && !json_doc.isEmpty() && json_error.error == QJsonParseError::NoError)
    {
        parseValue("", json, theRootItem);
    }

    emit endResetModel();

    return true;
}

bool JsonTreeModel_MC::dumpJson(const QString &filepath)
{
    if(filepath.isEmpty())
    {
        return false;
    }

    if(!theRootItem || theRootItem->childCount() == 0)
    {
        return false;
    }
    JsonTreeItem_MC *top_level_item = theRootItem->childItem(0);
    if(!top_level_item)
    {
        return false;
    }

    QJsonDocument json_doc;
    switch (top_level_item->type())
    {
        case JsonTreeItem_MC::Object:
            json_doc = QJsonDocument::fromVariant(dumpObject(top_level_item));
            break;
        case JsonTreeItem_MC::Array:
            json_doc = QJsonDocument::fromVariant(dumpArray(top_level_item));
            break;
        default:
            break;
    }

    QFile file(filepath);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return false;
    }
    file.write(json_doc.toJson(QJsonDocument::Indented));
    file.close();

    qDebug() << "dump json file";
    return true;
}

bool JsonTreeModel_MC::dumpJson(QByteArray &data)
{
    data.clear();
    if(!theRootItem || theRootItem->childCount() == 0)
    {
        return false;
    }

    QJsonDocument json_doc;
    switch (JsonTreeItem_MC::Object)
    {
        case JsonTreeItem_MC::Object:
            json_doc = QJsonDocument::fromVariant(dumpObject(theRootItem));
            break;
        case JsonTreeItem_MC::Array:
            json_doc = QJsonDocument::fromVariant(dumpArray(theRootItem));
            break;
        default:
            break;
    }
    data = json_doc.toJson();
    return true;
}

void JsonTreeModel_MC::setReadOnly(bool readOnly)
{
    m_bIsReadOnly = readOnly;
    theRootItem->setReadOnly(readOnly);
}



QModelIndex JsonTreeModel_MC::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
    {
        return QModelIndex();
    }

    JsonTreeItem_MC *parentItem = getItem(parent);
    JsonTreeItem_MC *childItem = parentItem->childItem(row);
    if (childItem)
    {
        return createIndex(row, column, childItem);
    }
    else
    {
        return QModelIndex();
    }
}

QModelIndex JsonTreeModel_MC::parent(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return QModelIndex();
    }

    JsonTreeItem_MC *childItem = getItem(index);
    JsonTreeItem_MC *parentItem = childItem->parentItem();

    if (parentItem == theRootItem)
    {
        return QModelIndex();
    }

    return createIndex(parentItem->row(), 0, parentItem);
}

int JsonTreeModel_MC::rowCount(const QModelIndex &parent) const
{
    JsonTreeItem_MC *parentItem = getItem(parent);
    return parentItem->childCount();
}

int JsonTreeModel_MC::columnCount(const QModelIndex &parent) const
{
    return header.count();

    //    JsonTreeItem *parentItem = getItem(parent);

    //    return parentItem->columnCount();
}

QVariant JsonTreeModel_MC::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if(role == Qt::TextAlignmentRole)
    {
        if(index.column() > 0)
        {
            return QVariant(Qt::AlignCenter);
        }
    }

    if (role != Qt::DisplayRole && role != Qt::EditRole)
    {
        return QVariant();
    }

    JsonTreeItem_MC *item = getItem(index);
    if(item->data(index.column()).toString() == "null" && item->childCount() != 0)
    {
        return QVariant();
    }
    return item->data(index.column());
}

QVariant JsonTreeModel_MC::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }
    if(role == Qt::TextAlignmentRole)
    {
        return Qt::AlignCenter;
    }
    if(orientation == Qt::Horizontal)
    {
        return header.at(section);
    }
    return QVariant();
}

Qt::ItemFlags JsonTreeModel_MC::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return 0;
    }

    JsonTreeItem_MC *item = getItem(index);
    return (item->editable(index.column()) ? Qt::ItemIsEditable : Qt::NoItemFlags)
           | QAbstractItemModel::flags(index);
}

bool JsonTreeModel_MC::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
    {
        return false;
    }

    JsonTreeItem_MC *item = getItem(index);
    item->setData(index.column(), value);
    emit dataChanged(index, index, {role});
    return true;
}

bool JsonTreeModel_MC::insertRows(int row, int count, const QModelIndex &parent)
{
    JsonTreeItem_MC *parentItem = getItem(parent);

    beginInsertRows(parent, row, row + count - 1);
    const bool result = parentItem->insertChildren(row, count);
    endInsertRows();

    return result;
}

bool JsonTreeModel_MC::removeRows(int row, int count, const QModelIndex &parent)
{
    JsonTreeItem_MC *parentItem = getItem(parent);

    beginRemoveRows(parent, row, row + count - 1);
    const bool result = parentItem->removeChildren(row, count);
    endRemoveRows();

    return result;
}

bool JsonTreeModel_MC::searchJsonValue(const QJsonValue &jValue, const QVariantList &path, QJsonValue &result)
{
    result = jValue;
    for(int i = 0; i < path.length(); ++i)
    {
        if(result.isNull() || result.isUndefined())
        {
            return false;
        }
        if (result.isArray())
        {
            result = result[path[i].toInt()];
        }
        else
        {
            result = result[path[i].toString()];
        }
    }
    return true;
}

QJsonValue JsonTreeModel_MC::getJson(void)
{
    QJsonValue json;

    if(theRootItem)
    {
        QList<JsonTreeItem_MC *> children = theRootItem->children();

        if(!children.isEmpty())
        {
            JsonTreeItem_MC *pItem = children[0];

            if(pItem)
            {
                json = getItemJson(pItem);
            }
        }
    }
    return json;
}

JsonTreeItem_MC *JsonTreeModel_MC::getItem(const QModelIndex &index) const
{
    if (index.isValid())
    {
        JsonTreeItem_MC *item = static_cast<JsonTreeItem_MC *>(index.internalPointer());
        if (item)
        {
            return item;
        }
    }
    return theRootItem;
}

QString JsonTreeModel_MC::getJsonString(const QJsonObject &obj, const QString &key)
{
    if(!obj.contains(key))
    {
        return EMPTY_STRING_FLAG;
    }

    QJsonValue val = obj.value(key);
    QString retVal = "error";

    switch(val.type())
    {
        case QJsonValue::Bool:
            retVal = QString::number(val.toBool());
            break;
        case QJsonValue::Double:
            retVal = QString::number(val.toDouble());
            break;
        case QJsonValue::String:
            retVal = val.toString();
            break;
        default:
            retVal = QString("unknown");
            break;
    }

    return retVal;
}

void JsonTreeModel_MC::setItemProprity(const QString &key, const QJsonObject &obj, JsonTreeItem_MC *pItem)
{
    if(pItem == nullptr)
    {
        qDebug() << "show leaf error item is nullptr";
        return;
    }

    QString valueName = getJsonString(obj, "valueName");
    int iValueType = obj.value("valueType").toInt();

    pItem->setTag("key", key);
    pItem->setTag("valueName", valueName);
    pItem->setTag("valueType", QString::number(iValueType));
    pItem->setTag("value", obj.value("value").toString());

    if(iValueType == ValueType::Value_Enum)
    {
        pItem->setJson(obj.value("dataSource"));
    }

    if(valueName.isEmpty())
    {
        valueName = key;
    }

    pItem->setTag("view-name", valueName);
    pItem->setTag("view-value", getJsonValueString(obj));
    pItem->setTag("view-min", getJsonString(obj, "length_min"));
    pItem->setTag("view-max", getJsonString(obj, "length_max"));
    pItem->setTag("view-unit", getJsonString(obj, "unit"));
    pItem->setTag("view-brief", getJsonString(obj, "brief"));
}

void JsonTreeModel_MC::showItemProprity(JsonTreeItem_MC *pItem)
{
    if(pItem == nullptr)
    {
        return;
    }

    pItem->setData(0, pItem->getTag("view-name"));
    pItem->showValue();
    pItem->setData(2, pItem->getTag("view-min"));
    pItem->setData(3, pItem->getTag("view-max"));
    pItem->setData(4, pItem->getTag("view-unit"));
    pItem->setData(5, pItem->getTag("view-brief"));
    pItem->setReadOnly(m_bIsReadOnly);
}

bool JsonTreeModel_MC::isObjectArray(const QJsonArray &arr)
{
    for(int i = 0; i < arr.count(); i++)
    {
        QJsonValue val = arr[i];

        if(val.isArray() || val.isObject())
        {
            return true;
        }
    }

    return false;
}

QString JsonTreeModel_MC::getJsonValueString(const QJsonObject &obj)
{
    QString qsValue;

    if(obj.contains("value") && obj.contains("valueType"))
    {
        const int iValueType = getJsonString(obj, "valueType").toInt();

        switch (iValueType)
        {
            case ValueType::Value_Bool:
            case ValueType::Value_Double:
            case ValueType::Value_Int:
            case ValueType::Value_String:
                qsValue = getJsonString(obj, "value");
                break;
            case ValueType::Value_Enum:
            {
                if(obj.contains("dataSource") && obj.contains("value"))
                {
                    int iValue = obj.value("value").toInt();
                    QJsonArray dataSource = obj.value("dataSource").toArray();
                    qsValue = dataSource[iValue].toString();
                }
            }
            break;
            default:
                qDebug() << "null value";
                break;
        }
    }
    else
    {
        qsValue = EMPTY_STRING_FLAG;
    }

    return qsValue;
}

void JsonTreeModel_MC::parseObject(const QString &key, const QJsonObject &obj, JsonTreeItem_MC *&item)
{

    JsonTreeItem_MC *pChild = new JsonTreeItem_MC(NullItemData(key), JsonTreeItem_MC::Object, item);
    item->appendChild(pChild);
    setItemProprity(key, obj, pChild);
    showItemProprity(pChild);

    for(const QString &item_key : obj.keys())
    {
        parseValue(item_key, obj.value(item_key), pChild);
    }
}

void JsonTreeModel_MC::parseArray(const QString &key, const QJsonArray &arr, JsonTreeItem_MC *&item)
{
    if(!isObjectArray(arr))
    {
        return;
    }

    JsonTreeItem_MC *child = new JsonTreeItem_MC(NullItemData(key), JsonTreeItem_MC::Array, item);
    item->appendChild(child);

    for(int i = 0; i < arr.count(); ++i)
    {
        parseValue(QString::number(i), arr.at(i), child);
    }
}

void JsonTreeModel_MC::parseValue(const QString &key, const QJsonValue &val, JsonTreeItem_MC *&item)
{
    switch (val.type())
    {
        case QJsonValue::Object:
            parseObject(key, val.toObject(), item);
            return;
        case QJsonValue::Array:
            parseArray(key, val.toArray(), item);
            return;
        default:
            break;
    }
}

QJsonValue JsonTreeModel_MC::getItemJson(JsonTreeItem_MC *pItem)
{
    // result
    // check parameter
    QJsonValue rootJson;
    if(pItem == nullptr)
    {
        qDebug() << "get json error null item";
        return rootJson;
    }

    updateItemTag(pItem);
    if(pItem->type() == JsonTreeItem_MC::Object)
    {
        rootJson = getItemJsonObject(pItem);
    }
    else if(pItem->type() == JsonTreeItem_MC::Array)
    {
        rootJson = getItemJsonArray(pItem);
    }
    else
    {
        qDebug() << "item type error type = " << pItem->type();
    }
    return rootJson;
}

QString JsonTreeModel_MC::getKeyEx(const QStringList &keys, const QString &key, int ex)
{
    QString result = key + QString::number(ex);
    if(keys.contains(result))
    {
        result = getKeyEx(keys, key, ex + 1);
    }
    return result;
}

QJsonObject JsonTreeModel_MC::getItemJsonObject(JsonTreeItem_MC *pItem)
{
    QJsonObject rootJson = getItemProprity(pItem);
    for(JsonTreeItem_MC *pChildItem : pItem->children())
    {
        QStringList keys = rootJson.keys();
        QString key = pChildItem->key();
        if(keys.contains(key))
        {
            key = getKeyEx(keys, key);
        }
        rootJson[key] = getItemJson(pChildItem);
    }
    return rootJson;
}

QJsonArray JsonTreeModel_MC::getItemJsonArray(JsonTreeItem_MC *pItem)
{
    QJsonArray jsonArray;
    for(JsonTreeItem_MC *pChildItem : pItem->children())
    {
        jsonArray.append(getItemJson(pChildItem));
    }
    return jsonArray;
}

bool JsonTreeModel_MC::insertProprityString(QJsonObject &obj, const QString &jsonKey, const QString &tagKey, JsonTreeItem_MC *pItem)
{
    if(pItem && pItem->tagContains(tagKey))
    {
        obj[jsonKey] = pItem->getTag(tagKey);
        return true;
    }
    return false;
}

bool JsonTreeModel_MC::insertProprityInt(QJsonObject &obj, const QString &jsonKey, const QString &tagKey, JsonTreeItem_MC *pItem)
{
    if(pItem && pItem->tagContains(tagKey))
    {
        QString qsValue = pItem->getTag(tagKey);
        if(qsValue == EMPTY_STRING_FLAG)
        {
            obj[jsonKey] = EMPTY_STRING_FLAG;
        }
        else
        {
            bool ok = false;
            double iValue = qsValue.toDouble(&ok);
            if(ok)
            {
                obj[jsonKey] = iValue;
                return true;
            }
        }
    }
    return false;
}

void JsonTreeModel_MC::insertProprityValue(QJsonObject &curObj, JsonTreeItem_MC *pItem)
{
    int iType = curObj["valueType"].toInt();

    if(iType == ValueType::Value_Enum)
    {
        const QString tagValue = pItem->getTag("view-value");
        const QJsonArray dataSourceArr = pItem->getJson().toArray();
        curObj["dataSource"] = pItem->getJson();
        for(int iLoop = 0; iLoop < dataSourceArr.size(); iLoop++)
        {
            if(dataSourceArr[iLoop].toString() == tagValue)
            {
                curObj["value"] = iLoop;
                break;
            }
        }
    }
    else if(iType == ValueType::Value_Int || iType == ValueType::Value_Double || iType == ValueType::Value_Bool)
    {
        insertProprityInt(curObj, "value", "view-value", pItem);
    }
    else if(iType == ValueType::Value_String)
    {
        insertProprityString(curObj, "value", "view-value", pItem);
    }
    else
    {
        qDebug() << "type error";
    }
}

QJsonObject JsonTreeModel_MC::getItemProprity(JsonTreeItem_MC *pItem)
{
    QJsonObject curObj;

    (void)insertProprityString(curObj, "valueName", "valueName", pItem);
    (void)insertProprityString(curObj, "unit", "view-unit", pItem);
    (void)insertProprityString(curObj, "brief", "view-brief", pItem);
    (void)insertProprityInt(curObj, "length_min", "view-min", pItem);
    (void)insertProprityInt(curObj, "length_max", "view-max", pItem);
    if(insertProprityInt(curObj, "valueType", "valueType", pItem))
    {
        insertProprityValue(curObj, pItem);
    }

    return curObj;
}

QVariantMap JsonTreeModel_MC::dumpObject(JsonTreeItem_MC *&item) const
{
    QVariantMap json_obj;
    const int child_count = item->childCount();
    for(int i = 0; i < child_count; i++)
    {
        JsonTreeItem_MC *child = item->childItem(i);
        if(!child)
        {
            continue;
        }
        switch (child->type())
        {
            case JsonTreeItem_MC::Object:
                json_obj.insert(child->key(), dumpObject(child));
                break;
            case JsonTreeItem_MC::Array:
                json_obj.insert(child->key(), dumpArray(child));
                break;
            case JsonTreeItem_MC::Value:
                json_obj.insert(child->key(), dumpValue(child));
                break;
            default:
                break;
        }
    }
    return json_obj;
}

QVariantList JsonTreeModel_MC::dumpArray(JsonTreeItem_MC *&item) const
{
    QVariantList json_arr;
    const int child_count = item->childCount();
    for(int i = 0; i < child_count; i++)
    {
        JsonTreeItem_MC *child = item->childItem(i);
        if(!child)
        {
            continue;
        }
        switch (child->type())
        {
            case JsonTreeItem_MC::Object:
                json_arr.append(dumpObject(child));
                break;
            case JsonTreeItem_MC::Array:
                json_arr.append(dumpArray(child));
                break;
            case JsonTreeItem_MC::Value:
                json_arr.append(dumpValue(child));
                break;
            default:
                break;
        }
    }
    return json_arr;
}

QVariant JsonTreeModel_MC::dumpValue(JsonTreeItem_MC *&item) const
{
    return item->value();
}

void JsonTreeModel_MC::updateItemTag(JsonTreeItem_MC *item)
{
    if(item == nullptr)
    {
        return;
    }
    item->setTag("view-name", item->data(0).toString());
    item->setTag("view-value", item->data(1).toString());
    item->setTag("view-min", item->data(2).toString());
    item->setTag("view-max", item->data(3).toString());
    item->setTag("view-unit", item->data(4).toString());
    item->setTag("view-brief", item->data(5).toString());
}

QHash<int, QVariant> JsonTreeModel_MC::NullItemData(const QString &key)
{
    const QHash<int, QVariant> dataInfo =
    {
        {0, key},
        {1, ""},
        {2, ""},
        {3, ""},
        {4, ""},
        {5, ""},
    };

    return dataInfo;
}
