#ifndef CMD_RECIPE_H
#define CMD_RECIPE_H

#include "GUIFramework_global.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT CMD_Recipe : public QObject
{
    Q_OBJECT
public:
    enum Command
    {
        CMD_RcpNames,
        CMD_Rcp,
        CMD_RcpInfo,
        CMD_RcpContent,
        CMD_CreateRcp,
        CMD_SaveRcp,
        CMD_CopyRcp,
        CMD_DeleteRcp,
        CMD_ReleaseRcp,
        CMD_UnReleaseRcp,
    };
    Q_ENUM(Command)

    explicit CMD_Recipe(QObject *parent = nullptr);

signals:

};

#endif // CMD_RECIPE_H
