#ifndef CMD_THREADPROC_H
#define CMD_THREADPROC_H

#include "GUIFramework_global.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT CMD_ThreadProc : public QObject
{
    Q_OBJECT
public:
    enum Command
    {
        CMD_AllProcInfo,                    // 所有流程
        CMD_InitialProcInfo,                // 初始化类流程
        CMD_MonitorProcInfo,                // 监控类流程
        CMD_AutoRunProcInfo,                // 自动运行类流程
        CMD_ProcStates,                     // 流程状态
        CMD_Reset,                          // 重置
        CMD_Start,                          // 开始
        CMD_SetSingleStepModel,             // 单步模式设置
        CMD_NextStep,                       // 下一步
        CMD_Stop,                           // 停止
        CMD_SetInputSignal,                 // 输入信号设置
    };
    Q_ENUM(Command)

    explicit CMD_ThreadProc(QObject *parent = nullptr);

signals:

};

#endif // CMD_THREADPROC_H
