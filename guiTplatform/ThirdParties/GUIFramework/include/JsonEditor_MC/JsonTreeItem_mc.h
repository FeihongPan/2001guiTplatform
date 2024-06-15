#ifndef JSONTREEITEM_MC_H
#define JSONTREEITEM_MC_H

#include "GUIFramework_global.h"
#include "BasicValue/node.h"

#include <QStandardItem>
#include <QList>
#include <QJsonValue>

#define EMPTY_STRING_FLAG QString("null")

class GUIFRAMEWORK_EXPORT JsonTreeItem_MC
{
public:
    enum JsonItemType
    {
        None,    ///空
        Object,  ///结构体
        Array,   ///数组
        Value    ///值
    };
public:
    explicit JsonTreeItem_MC(JsonTreeItem_MC *parent = nullptr);
    explicit JsonTreeItem_MC(const QHash<int, QVariant> &datas, JsonTreeItem_MC::JsonItemType type, JsonTreeItem_MC *parent = nullptr);
    ~JsonTreeItem_MC();

    bool insertChild(int row, JsonTreeItem_MC *child);
    bool removeChild(int row);
    bool insertChildren(int row, int count);
    bool removeChildren(int row, int count);
    void appendChild(JsonTreeItem_MC *child);
    void deleteAllChild();

    JsonTreeItem_MC *parentItem();
    JsonTreeItem_MC *childItem(int row);
    QList<JsonTreeItem_MC *> children(void);

    void setParentItem(JsonTreeItem_MC *parent);
    int childCount() const;
    int columnCount() const;
    void setTag(const QString &key, const QString &tagValue);
    QString getTag(const QString &key);
    bool tagContains(const QString &key);
    void setReadOnly(bool readOnly);
    QJsonValue getJson(void);
    void setJson(const QJsonValue &json);
    QVariant data(int column) const;
    void setData(int column, const QVariant &val);
    void showValue(void);
    int row() const;
    bool editable(int column) const;

    QString key() const;
    void setKey(const QString &key);
    QVariant value() const;
    void setValue(const QVariant &value);
    JsonTreeItem_MC::JsonItemType type() const;
    void setType(JsonTreeItem_MC::JsonItemType type);

private:
    JsonTreeItem_MC *theParentItem;
    QList<JsonTreeItem_MC *> theChildItems;
    JsonItemType theItemType;
    QHash<int, QVariant> theItemDatas;
    QMap<QString, QString> m_tagMap;
    QJsonValue m_json;
    bool m_bIsReadOnly = false;
};

#endif // JSONTREEITEM_MC_H
