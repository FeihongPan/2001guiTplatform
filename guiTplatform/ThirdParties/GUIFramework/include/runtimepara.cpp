#include "runtimepara.h"

#include <QMutex>

RuntimePara *RuntimePara::self = nullptr;
RuntimePara::RuntimePara(QObject *parent) : QObject(parent)
{

}

RuntimePara::~RuntimePara()
{

}

RuntimePara *RuntimePara::getInstance()
{
    if(self == nullptr)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == nullptr)
        {
            self = new RuntimePara;
        }
    }
    return self;
}
