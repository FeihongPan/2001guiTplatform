#include "sgtconstantsubscriber.h"
#include "SGT/Command/cmd_sgtconstant.h"
#include "Converter/enumconverter.h"

#include <QMutex>

SGTConstantSubscriber *SGTConstantSubscriber::self = NULL;
SGTConstantSubscriber::SGTConstantSubscriber(QString name, QObject *parent) : ISubscriber(name, parent)
{
    qRegisterMetaType<S_SGTConstant>("S_SGTConstant");
    qRegisterMetaType<S_SGTConstant>("S_SGTConstant&");
}

SGTConstantSubscriber *SGTConstantSubscriber::getInstance()
{
    if(self == NULL)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == NULL)
        {
            self = new SGTConstantSubscriber("SGTConstantSubscriber");
        }
    }
    return self;
}

SGTConstantSubscriber::~SGTConstantSubscriber()
{

}

void SGTConstantSubscriber::decoding(const QString &topic, const QByteArray &message)
{
    TaskInfo task_Recived;
    task_Recived.fromJson(message);
    CMD_SGTConstant::Command cmd = EnumConverter::ConvertStringToEnum<CMD_SGTConstant::Command>(task_Recived.task);
    switch (cmd)
    {
        case CMD_SGTConstant::CMD_SGTData:
            {
                S_SGTConstant sgtConstant;
                sgtConstant.fromJson(task_Recived.context);
                emit Send_SGTConstant(sgtConstant);
            }
            break;

        case CMD_SGTConstant::CMD_SaveSGTData:
            {
                emit Send_SaveResult(task_Recived.result);
            }

        default:
            break;
    }
}
