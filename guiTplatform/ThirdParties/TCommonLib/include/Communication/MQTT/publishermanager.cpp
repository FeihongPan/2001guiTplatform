#include "publishermanager.h"

#include "ipublish.h"
#include "publisher.h"

#include <QMutex>

PublisherManager *PublisherManager::self = NULL;

PublisherManager::PublisherManager()
{

}

PublisherManager::~PublisherManager()
{

}

PublisherManager *PublisherManager::getInstance()
{
    if(self == NULL)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == NULL)
        {
            self = new PublisherManager;
        }
    }
    return self;
}

void PublisherManager::AddPublisher(Publisher &publisher)
{
    if(m_lst_Publishers.contains(&publisher))
    {
        m_lst_Publishers.append(&publisher);
    }
}

void PublisherManager::AddIPublish(IPublish *ipublish)
{
    if(!m_lst_IPublish.contains(ipublish))
    {
        m_lst_IPublish.append(ipublish);
        m_lst_Publishers.append(ipublish->GetPublisher());
    }
}

void PublisherManager::AddIPublishs(QList<IPublish *> ipublishs)
{
    for(int i = 0; i < ipublishs.count(); ++i)
    {
        AddIPublish(ipublishs[i]);
    }
}

void PublisherManager::SetDefaltPublish()
{
    for(int i = 0; i < m_lst_IPublish.count(); ++i)
    {
        m_lst_IPublish[i]->StartPublish();
        m_lst_IPublish[i]->SetPeriodPublish();
    }
}
