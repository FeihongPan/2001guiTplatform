#include "sgtctrlsubscriber.h"
#include "SGT/Command/cmd_sgtctrl.h"
#include "Converter/enumconverter.h"
#include "SGT/Data/sgtsystem.h"

#include <QMutex>

SGTCtrlSubscriber *SGTCtrlSubscriber::self = NULL;
SGTCtrlSubscriber::SGTCtrlSubscriber(QString name, QObject *parent) : ISubscriber(name, parent)
{
    qRegisterMetaType<S_SGTTwinkleData>("S_SGTTwinkleData");
    qRegisterMetaType<S_SGTTwinkleData>("S_SGTTwinkleData&");
    qRegisterMetaType<SGTSystem::State>("SGTSystem::State");
    qRegisterMetaType<SGTSystem::State>("SGTSystem::State&");
}

SGTCtrlSubscriber *SGTCtrlSubscriber::getInstance()
{
    if(self == NULL)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == NULL)
        {
            self = new SGTCtrlSubscriber("SGTCtrlSubscriber");
        }
    }
    return self;
}

SGTCtrlSubscriber::~SGTCtrlSubscriber()
{

}

void SGTCtrlSubscriber::decoding(const QString &topic, const QByteArray &message)
{
    TaskInfo task_Recived;
    task_Recived.fromJson(message);
    CMD_SGTCtrl::Command cmd = EnumConverter::ConvertStringToEnum<CMD_SGTCtrl::Command>(task_Recived.task);
    switch (cmd)
    {
        case CMD_SGTCtrl::CMD_SGTSystemState:
        {
            SGTSystem::State state = (SGTSystem::State)task_Recived.context.toInt();
            emit Send_SGTSystemState(state);
        }
        break;

        case CMD_SGTCtrl::CMD_SGTComponentState:
        {
            S_SGTTwinkleData twinkelData;
            twinkelData.fromJson(task_Recived.context);
            emit Send_SGTComponentState(twinkelData);
        }
        break;

        default:
            break;
    }
}
