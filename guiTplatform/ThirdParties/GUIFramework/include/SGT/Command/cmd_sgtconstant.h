#ifndef CMD_SGTCONSTANT_H
#define CMD_SGTCONSTANT_H

#include "GUIFramework_global.h"
#include <QObject>

class GUIFRAMEWORK_EXPORT CMD_SGTConstant : public QObject
{
    Q_OBJECT

public:
    enum Command
    {
        CMD_SGTData,                    // 信号塔配置信息
        CMD_SaveSGTData,                // 保存配置信息
        CMD_SaveDefaultSGTData,         // 恢复并保存默认配置信息
    };
    Q_ENUM(Command)
};

#endif // CMD_SGTCONSTANT_H
