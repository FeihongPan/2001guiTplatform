#include "alignment.h"

S_AlignPoint::S_AlignPoint()
{

}

S_AlignPoint::S_AlignPoint(const S_AlignPoint &point)
{
    this->point = point.point;
    this->markId = point.markId;
    this->threshold = point.threshold;
}

S_AlignPoint &S_AlignPoint::operator=(const S_AlignPoint &point)
{
    this->point = point.point;
    this->markId = point.markId;
    this->threshold = point.threshold;
    return *this;
}

S_Alignment::S_Alignment()
{

}

S_Alignment::S_Alignment(const S_Alignment &align)
{
    this->model = align.model;
    this->CCD_Pos = align.CCD_Pos;
    this->lst_RotatingAngles = align.lst_RotatingAngles;
    this->lst_AlignPoints = align.lst_AlignPoints;
    this->minValidMarks = align.minValidMarks;
}

S_Alignment &S_Alignment::operator=(const S_Alignment &align)
{
    this->model = align.model;
    this->CCD_Pos = align.CCD_Pos;
    this->lst_RotatingAngles = align.lst_RotatingAngles;
    this->lst_AlignPoints = align.lst_AlignPoints;
    this->minValidMarks = align.minValidMarks;
    return *this;
}
