#ifndef CMD_TEMPLATELIB_H
#define CMD_TEMPLATELIB_H

#include "GUIFramework_global.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT CMD_TemplateLib : public QObject
{
    Q_OBJECT
public:
    enum Command
    {
        CMD_Names,
        CMD_Temp,
        CMD_Info,
        CMD_Content,
        CMD_New,
        CMD_Save,
        CMD_Copy,
        CMD_Delete,
    };
    Q_ENUM(Command)

    explicit CMD_TemplateLib(QObject *parent = nullptr);

signals:
};

#endif // CMD_TEMPLATELIB_H
