#include "align.h"

AlignmentMode::AlignmentMode()
{

}

AlignmentMode::AlignmentMode(const AlignmentMode &alignmentMode)
{
    this->isCrsAl = alignmentMode.isCrsAl;
    this->isFiducialChk = alignmentMode.isFiducialChk;
    this->isOperatorCfm = alignmentMode.isOperatorCfm;
    this->isAllowManualAl = alignmentMode.isAllowManualAl;
}

AlignmentMode &AlignmentMode::operator=(const AlignmentMode &alignmentMode)
{
    this->isCrsAl = alignmentMode.isCrsAl;
    this->isFiducialChk = alignmentMode.isFiducialChk;
    this->isOperatorCfm = alignmentMode.isOperatorCfm;
    this->isAllowManualAl = alignmentMode.isAllowManualAl;
    return *this;
}

CrsAlPoints::CrsAlPoints()
{
    this->searchWidth = 0.3;
    this->searchHeight = 0.3;
    this->searchStep = 0;
    this->threshold = 90;
}

CrsAlPoints::CrsAlPoints(const CrsAlPoints &alignPoint)
{
    this->points = alignPoint.points;
    this->markID = alignPoint.markID;
    this->threshold = alignPoint.threshold;
    this->searchWidth = alignPoint.searchWidth;
    this->searchHeight = alignPoint.searchHeight;
    this->searchStep = alignPoint.searchStep;
}

CrsAlPoints &CrsAlPoints::operator=(const CrsAlPoints &alignPoint)
{
    this->points = alignPoint.points;
    this->markID = alignPoint.markID;
    this->threshold = alignPoint.threshold;
    this->searchWidth = alignPoint.searchWidth;
    this->searchHeight = alignPoint.searchHeight;
    this->searchStep = alignPoint.searchStep;
    return *this;
}

Alignm::Alignm()
{
    this->fineALPoint.threshold = 90;
    this->waferEdgeSearch = false;
    this->crsAlPoints.append(CrsAlPoints());
    this->crsAlPoints.append(CrsAlPoints());
}

Alignm::Alignm(const Alignm &alignment)
{
    this->mode = alignment.mode;
    this->crsAlPoints = alignment.crsAlPoints;
    this->fineALPoint = alignment.fineALPoint;
    this->alOffset = alignment.alOffset;
    this->waferEdgeSearch = alignment.waferEdgeSearch;
}

Alignm &Alignm::operator=(const Alignm &alignment)
{
    this->mode = alignment.mode;
    this->crsAlPoints = alignment.crsAlPoints;
    this->fineALPoint = alignment.fineALPoint;
    this->alOffset = alignment.alOffset;
    this->waferEdgeSearch = alignment.waferEdgeSearch;
    return *this;
}

FineALPoints::FineALPoints()
{

}

FineALPoints::FineALPoints(const FineALPoints &fineALPoints)
{
    this->points = fineALPoints.points;
    this->markID = fineALPoints.markID;
    this->threshold = fineALPoints.threshold;
    this->minValidMarks = fineALPoints.minValidMarks;
}

FineALPoints &FineALPoints::operator=(const FineALPoints &fineALPoints)
{
    this->points = fineALPoints.points;
    this->markID = fineALPoints.markID;
    this->threshold = fineALPoints.threshold;
    this->minValidMarks = fineALPoints.minValidMarks;
    return *this;
}
