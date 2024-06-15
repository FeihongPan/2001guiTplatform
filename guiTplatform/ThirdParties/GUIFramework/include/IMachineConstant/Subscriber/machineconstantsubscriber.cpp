#include "machineconstantsubscriber.h"
#include "IMachineConstant/Command/cmd_machineconstant.h"
#include "Converter/enumconverter.h"

#include <QMutex>

MachineConstantSubscriber *MachineConstantSubscriber::self = NULL;
MachineConstantSubscriber::MachineConstantSubscriber(QString name, QObject *parent) : ISubscriber(name, parent)
{
    qRegisterMetaType<S_List_String>("S_List_String");
    qRegisterMetaType<S_List_String>("S_List_String&");
}

MachineConstantSubscriber *MachineConstantSubscriber::getInstance()
{
    if(self == NULL)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == NULL)
        {
            self = new MachineConstantSubscriber("MachineConstantSubscriber");
        }
    }
    return self;
}

void MachineConstantSubscriber::decoding(const QString &topic, const QByteArray &message)
{
    TaskInfo task_Recived;

    task_Recived.fromJson(message);

    CMD_MachineConstant::Command cmd = EnumConverter::ConvertStringToEnum<CMD_MachineConstant::Command>(task_Recived.task);


    switch (cmd)
    {
        case CMD_MachineConstant::CMD_Names:
        {
            S_List_String names;

            names.fromJson(task_Recived.context);
            emit sendNames(names);
        }
        break;

        case CMD_MachineConstant::CMD_Info:
        {
            S_ConstantInfo contantHead;

            contantHead.fromJson(task_Recived.context);
            emit sendInfo(contantHead);
        }
        break;

        case CMD_MachineConstant::CMD_Content:
        {
            emit sendContent(task_Recived.context);
        }
        break;

        case CMD_MachineConstant::CMD_Delete:
        {

        }
        break;

        case CMD_MachineConstant::CMD_Backup:
        {
            S_List_String names;
            names.fromJson(task_Recived.context);
            emit sendNames(names);
        }
        break;

        case CMD_MachineConstant::CMD_Execute:
        {
            //            SerializableStringList names;
            //            names.fromJson(task_Recived.context);
            //            emit sendNames(names);
        }
        break;

        case CMD_MachineConstant::CMD_Actived_MC:
        {
            qDebug() << "-----------------------------recieve CMD_Actived_MC------------------------------";
            QList<QByteArray> constant = task_Recived.context.split('#');
            S_ConstantInfo contantHead;

            if(constant.size() == 2)
            {
                contantHead.fromJson(constant[0]);
                emit sendCurrentInfo(contantHead);
                emit sendContent(constant[1]);
            }
            else
            {
                qDebug() << "CMD_MachineConstant::CMD_MC error contant-size = " << constant.size();
            }
        }
        break;

        case CMD_MachineConstant::CMD_Actived_Info:
        {
            qDebug() << "-----------------------------recieve CMD_Actived_Info------------------------------";
            S_ConstantInfo contantHead;

            contantHead.fromJson(task_Recived.context);
            emit sendInfo(contantHead);
        }
        break;

        case CMD_MachineConstant::CMD_Actived_Content:
        {
            qDebug() << "-----------------------------recieve CMD_Actived_Content------------------------------";
            emit sendContent(task_Recived.context);
        }
        break;

        case CMD_MachineConstant::CMD_MC:
        {
            QList<QByteArray> constant = task_Recived.context.split('#');
            S_ConstantInfo contantHead;

            if(constant.size() == 2)
            {
                contantHead.fromJson(constant[0]);
                emit sendInfo(contantHead);
                emit sendContent(constant[1]);
            }
            else
            {
                qDebug() << "CMD_MachineConstant::CMD_MC error contant-size = " << constant.size();
            }
        }
        break;
        case CMD_MachineConstant::CMD_New:
        {
            S_ConstantInfo constant;

            constant.fromJson(task_Recived.context);
            emit sendNew(constant);
        }
        break;
        default:
            break;
    }
}
