#ifndef SGTCONSTANT_H
#define SGTCONSTANT_H

#include "GUIFramework_global.h"
#include "sgtsystem.h"
#include "Serializer/QSerializer"

class GUIFRAMEWORK_EXPORT S_SGTTwinkleTime : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(SGTSystem::TwinkleMode, twinkleMode)                                           // 闪烁模式
    QS_FIELD(int, timeSpan_On)                                                              // 打开时长
    QS_FIELD(int, timeSpan_Off)                                                             // 关闭时长

public:
    S_SGTTwinkleTime();
    S_SGTTwinkleTime(const S_SGTTwinkleTime &data);
    S_SGTTwinkleTime &operator=(const S_SGTTwinkleTime &data);

};

class GUIFRAMEWORK_EXPORT S_SGTTwinkleData : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_QT_DICT_OBJECTS(QMap, SGTSystem::SGTComponent, S_SGTTwinkleTime, dic_SGTTwinkleTime) // 各信号塔组件闪烁信息

public:
    S_SGTTwinkleData();
};

class GUIFRAMEWORK_EXPORT S_SGTConstant : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_QT_DICT(QMap, SGTSystem::TwinkleMode, int, dic_TimeSpan)                             // 各闪烁模式对应时长
    QS_QT_DICT_OBJECTS(QMap, SGTSystem::State, S_SGTTwinkleData, dic_SGTTwinkleData)        // 各信号塔状态对应闪烁信息

public:
    S_SGTConstant();
};

#endif // SGTCONSTANT_H
