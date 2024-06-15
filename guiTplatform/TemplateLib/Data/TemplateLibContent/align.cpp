#include "align.h"

S_AlignPointInfo::S_AlignPointInfo()
{

}

S_AlignPointInfo::S_AlignPointInfo(const S_AlignPointInfo &point)
{
    this->point = point.point;
    this->markId = point.markId;
    this->threshold = point.threshold;
}

S_AlignPointInfo &S_AlignPointInfo::operator=(const S_AlignPointInfo &point)
{
    this->point = point.point;
    this->markId = point.markId;
    this->threshold = point.threshold;
    return *this;
}

S_Align::S_Align()
{

}

S_Align::S_Align(const S_Align &align)
{
    this->lst_AlignPoints = align.lst_AlignPoints;
    this->passThresholdNumber = align.passThresholdNumber;
}

S_Align &S_Align::operator=(const S_Align &align)
{
    this->lst_AlignPoints = align.lst_AlignPoints;
    this->passThresholdNumber = align.passThresholdNumber;
    return *this;
}
