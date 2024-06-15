#ifndef CMD_SGTCTRL_H
#define CMD_SGTCTRL_H

#include "GUIFramework_global.h"
#include <QObject>

class GUIFRAMEWORK_EXPORT CMD_SGTCtrl : public QObject
{
    Q_OBJECT

public:
    enum Command
    {
        CMD_SGTState,
        CMD_MaunualSet,                 // 人工测试
        CMD_MaunualSetExit,             // 退出人工测试
        CMD_SGTSystemState,             // 信号塔状态指示
        CMD_SGTComponentState,          // 信号塔闪烁状态信息
        CMD_BuzzerOff,                  // 消音
    };
    Q_ENUM(Command)
};

#endif // CMD_SGTCTRL_H
