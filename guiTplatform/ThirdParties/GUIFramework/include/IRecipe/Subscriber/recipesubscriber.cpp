#include "recipesubscriber.h"
#include "Converter/enumconverter.h"

#include <QMutex>

RecipeSubscriber *RecipeSubscriber::self = nullptr;
RecipeSubscriber::RecipeSubscriber(QString name, QObject *parent) : ISubscriber(name, parent)
{
    qRegisterMetaType<S_RecipeNames>("S_RecipeNames");
    qRegisterMetaType<S_RecipeNames>("S_RecipeNames&");
    //    qRegisterMetaType<S_Recipe>("S_Recipe");
    //    qRegisterMetaType<S_Recipe>("S_Recipe&");
    qRegisterMetaType<QByteArray>("QByteArray");
    qRegisterMetaType<QByteArray>("QByteArray&");
}

RecipeSubscriber *RecipeSubscriber::getInstance()
{
    if(self == NULL)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == NULL)
        {
            self = new RecipeSubscriber("RecipeSubscriber");
        }
    }
    return self;
}

void RecipeSubscriber::decoding(const QString &topic, const QByteArray &message)
{
    TaskInfo task_Recived;
    task_Recived.fromJson(message);
    CMD_Recipe::Command cmd = EnumConverter::ConvertStringToEnum<CMD_Recipe::Command>(task_Recived.task);
    switch (cmd)
    {
        case CMD_Recipe::CMD_RcpNames:
        {
            S_RecipeNames recipNames;
            recipNames.fromJson(task_Recived.context);
            emit sig_RecipeNames(recipNames);
        }
        break;

        case CMD_Recipe::CMD_Rcp:
        {
            emit sig_Recipe(task_Recived.context);
        }
        break;

        case CMD_Recipe::CMD_RcpInfo:
        {
            S_RecipeInfo info;
            info.fromJson(task_Recived.context);
            emit sig_RecipeInfo(info);
        }
        break;

        case CMD_Recipe::CMD_CreateRcp:
        {
            S_RecipeInfo info;
            info.fromJson(task_Recived.context);
            emit sig_RecipeInfo(info);
        }
        break;

        case CMD_Recipe::CMD_RcpContent:
        {
            emit sig_RecipeContent(task_Recived.context);
        }
        break;

        case CMD_Recipe::CMD_SaveRcp:
        case CMD_Recipe::CMD_CopyRcp:
        case CMD_Recipe::CMD_DeleteRcp:
        case CMD_Recipe::CMD_ReleaseRcp:
        case CMD_Recipe::CMD_UnReleaseRcp:
        {
            emit sig_OperateResult(cmd, task_Recived.result);
        }
        break;

        default:
            break;
    }
}
