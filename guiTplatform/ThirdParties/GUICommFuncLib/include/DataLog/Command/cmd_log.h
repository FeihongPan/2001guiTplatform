#ifndef CMD_LOG_H
#define CMD_LOG_H

#include "GUICommFuncLib_global.h"

#include <QObject>

class GUICOMMFUNCLIB_EXPORT CMD_Log : public QObject
{
    Q_OBJECT
public:
    enum Command
    {
        CMD_LogDebug,
        CMD_LogException,
        CMD_LogProcess,
    };
    Q_ENUM(Command)
    explicit CMD_Log(QObject *parent = nullptr);
};

#endif // CMD_LOG_H
