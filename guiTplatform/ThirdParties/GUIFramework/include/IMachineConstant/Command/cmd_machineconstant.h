#ifndef CMD_MACHINECONSTANT_H
#define CMD_MACHINECONSTANT_H

#include "GUIFramework_global.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT CMD_MachineConstant : public QObject
{
    Q_OBJECT
public:
    enum Command
    {
        CMD_Actived_MC,
        CMD_Actived_Info,
        CMD_Actived_Content,
        CMD_Names,
        CMD_MC,
        CMD_Info,
        CMD_Content,
        CMD_New,
        CMD_Save,
        CMD_Backup,
        CMD_Delete,
        CMD_Execute,
    };
    Q_ENUM(Command)

    explicit CMD_MachineConstant(QObject *parent = nullptr);
};

#endif // CMD_MACHINECONSTANT_H
