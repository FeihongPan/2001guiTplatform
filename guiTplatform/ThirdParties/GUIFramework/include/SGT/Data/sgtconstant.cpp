#include "sgtconstant.h"

#include "Converter/enumconverter.h"

S_SGTTwinkleTime::S_SGTTwinkleTime()
{
    timeSpan_On = 500;
    timeSpan_Off = 500;
}

S_SGTTwinkleTime::S_SGTTwinkleTime(const S_SGTTwinkleTime &data)
{
    this->twinkleMode = data.twinkleMode;
    this->timeSpan_On = data.timeSpan_On;
    this->timeSpan_Off = data.timeSpan_Off;
}

S_SGTTwinkleTime &S_SGTTwinkleTime::operator=(const S_SGTTwinkleTime &data)
{
    this->twinkleMode = data.twinkleMode;
    this->timeSpan_On = data.timeSpan_On;
    this->timeSpan_Off = data.timeSpan_Off;
    return *this;
}

S_SGTTwinkleData::S_SGTTwinkleData()
{
    QStringList lst = EnumConverter::ConvertToStringList<SGTSystem::SGTComponent>();
    for(int i = 0; i < lst.count(); i++)
    {
        dic_SGTTwinkleTime.insert(EnumConverter::ConvertStringToEnum<SGTSystem::SGTComponent>(lst[i]), S_SGTTwinkleTime());
    }
}

S_SGTConstant::S_SGTConstant()
{
    dic_TimeSpan.insert(SGTSystem::TwinkleMode::HighFrequency, 200);
    dic_TimeSpan.insert(SGTSystem::TwinkleMode::LowFrequency, 500);

    QStringList lst = EnumConverter::ConvertToStringList<SGTSystem::State>();
    for(int i = 0; i < lst.count(); i++)
    {
        dic_SGTTwinkleData.insert(EnumConverter::ConvertStringToEnum<SGTSystem::State>(lst[i]), S_SGTTwinkleData());
    }
}
