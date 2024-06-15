#include "templatelibsubscriber.h"
#include "Converter/enumconverter.h"

#include <QMutex>

TemplateLibSubscriber *TemplateLibSubscriber::self = nullptr;
TemplateLibSubscriber::TemplateLibSubscriber(QString name, QObject *parent) : ISubscriber(name, parent)
{
    //    qRegisterMetaType<S_RecipeNames>("S_RecipeNames");
    //    qRegisterMetaType<S_RecipeNames>("S_RecipeNames&");
    qRegisterMetaType<QByteArray>("QByteArray");
    qRegisterMetaType<QByteArray>("QByteArray&");
}

TemplateLibSubscriber *TemplateLibSubscriber::getInstance()
{
    if(self == NULL)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == NULL)
        {
            self = new TemplateLibSubscriber("TemplateLibSubscriber");
        }
    }
    return self;
}

void TemplateLibSubscriber::decoding(const QString &topic, const QByteArray &message)
{
    TaskInfo task_Recived;
    task_Recived.fromJson(message);
    CMD_TemplateLib::Command cmd = EnumConverter::ConvertStringToEnum<CMD_TemplateLib::Command>(task_Recived.task);
    switch (cmd)
    {
        case CMD_TemplateLib::CMD_Names:
        {
            S_List_String templateNames;
            templateNames.fromJson(task_Recived.context);
            emit sig_TemplateNames(templateNames);
        }
        break;
        case CMD_TemplateLib::CMD_New:
        {
            S_TemplateInfo info;
            info.fromJson(task_Recived.context);
            emit sig_NewTemplateLib(info);
        }
        break;

        case CMD_TemplateLib::CMD_Info:
        {
            emit sig_TemplateLib(task_Recived.context);
        }
        break;

        case CMD_TemplateLib::CMD_Content:
        {
            emit sig_TemplateContent(task_Recived.context);
        }
        break;

        default:
            break;
    }
}
