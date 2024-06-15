#ifndef JSONTREEMODEL_MC_H
#define JSONTREEMODEL_MC_H

#include "GUIFramework_global.h"

#include <QAbstractItemModel>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QVariant>

#include "JsonTreeItem_mc.h"

class GUIFRAMEWORK_EXPORT JsonTreeModel_MC : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit JsonTreeModel_MC(QObject *parent = nullptr);
    ~JsonTreeModel_MC();

    QJsonValue getJson(void);
    bool loadJson(const QString &filepath);
    bool loadJson(const QByteArray &data);
    bool dumpJson(const QString &filepath);
    bool dumpJson(QByteArray &data);
    void setReadOnly(bool readOnly);

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    static bool searchJsonValue(const QJsonValue &jValue, const QVariantList &path, QJsonValue &result);

private:
    JsonTreeItem_MC *getItem(const QModelIndex &index) const;
    void parseObject(const QString &key, const QJsonObject &obj, JsonTreeItem_MC *&item);
    void parseArray(const QString &key, const QJsonArray &arr, JsonTreeItem_MC *&item);
    void parseValue(const QString &key, const QJsonValue &val, JsonTreeItem_MC *&item);
    void setItemProprity(const QString &key, const QJsonObject &val, JsonTreeItem_MC *pItem);
    void showItemProprity(JsonTreeItem_MC *pItem);
    bool isObjectArray(const QJsonArray &arr);
    QString getJsonValueString(const QJsonObject &obj);
    QString getJsonString(const QJsonObject &obj, const QString &key);
    QJsonValue getItemJson(JsonTreeItem_MC *pItem);
    QJsonObject getItemJsonObject(JsonTreeItem_MC *pItem);
    QJsonArray getItemJsonArray(JsonTreeItem_MC *pItem);
    QJsonObject getItemProprity(JsonTreeItem_MC *pItem);
    QVariantMap dumpObject(JsonTreeItem_MC *&item) const;
    QVariantList dumpArray(JsonTreeItem_MC *&item) const;
    QVariant dumpValue(JsonTreeItem_MC *&item) const;
    void updateItemTag(JsonTreeItem_MC *item);
    bool insertProprityString(QJsonObject &obj, const QString &jsonKey, const QString &tagKey, JsonTreeItem_MC *pItem);
    bool insertProprityInt(QJsonObject &obj, const QString &jsonKey, const QString &tagKey, JsonTreeItem_MC *pItem);
    void insertProprityValue(QJsonObject &obj, JsonTreeItem_MC *pItem);
    QString getKeyEx(const QStringList &keys, const QString &key, int ex = 0);
    static QHash<int, QVariant> NullItemData(const QString &key);

private:
    JsonTreeItem_MC *theRootItem = nullptr;                                        ///根项目
    const QStringList header = {"name", "value", "min", "max", "unit", "brief"};   ///表头
    bool m_bIsReadOnly = false;                                                    ///是否只读
};

#endif // JSONTREEMODEL_MC_H
