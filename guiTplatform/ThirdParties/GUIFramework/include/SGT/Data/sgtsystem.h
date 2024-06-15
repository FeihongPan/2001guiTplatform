#ifndef SGTSYSTEM_H
#define SGTSYSTEM_H

#include "GUIFramework_global.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT SGTSystem : public QObject
{
    Q_OBJECT

public:
    enum State
    {
        SGT_UNKNOWN,                // 未知
        SGT_READY,                  // 准备完成
        SGT_IDLE,                   // 等待
        SGT_RUNNING,                // 运行
        SGT_PAUSED,                 // 暂停
        SGT_STOPPED,                // 停止
        SGT_NOTICING,               // 提醒
        SGT_ERROR,                  // 错误
        SGT_EXCEPTION,              // 打断
    };
    Q_ENUM(State)

    enum TwinkleMode
    {
        AlwaysOff = 0,              // 常关
        AlwaysOn,                   // 常开
        HighFrequency,              // 高频
        LowFrequency,               // 低频
        Customer,                   // 自定义设置
    };
    Q_ENUM(TwinkleMode)

    enum SGTComponent
    {
        RedLight,                   // 红灯
        YellowLight,                // 黄灯
        GreenLight,                 // 绿灯
        BlueLight,                  // 蓝灯
        Buzzer,                     // 喇叭
    };
    Q_ENUM(SGTComponent)
};

#endif // SGTSYSTEM_H
