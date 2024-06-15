#ifndef PUBLISHERMANAGER_H
#define PUBLISHERMANAGER_H

#include "TCommonLib_global.h"

#include <QObject>
#include <QMultiMap>

class IPublish;
class Publisher;
class QMqttClient;

class TCOMMONLIB_EXPORT PublisherManager
{
public:
    ~PublisherManager();

    static PublisherManager *getInstance();

    void AddPublisher(Publisher &publisher);

    void AddIPublish(IPublish *ipublish);

    void AddIPublishs(QList<IPublish *> ipublishs);

    void SetDefaltPublish();

private:
    explicit PublisherManager();
    PublisherManager(const PublisherManager &) = delete;
    PublisherManager &operator=(const PublisherManager &) = delete;

private:
    static PublisherManager *self;
    QList<IPublish *> m_lst_IPublish;
    QList<Publisher *> m_lst_Publishers;

    QMultiMap<QMqttClient *, IPublish *> p_dic_IPublich;
};

#endif // PUBLISHERMANAGER_H
