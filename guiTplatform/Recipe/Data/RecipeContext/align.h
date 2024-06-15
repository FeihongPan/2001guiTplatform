#ifndef ALIGN_H
#define ALIGN_H
#include "BasicValue/point.h"
#include <QSerializer>
#include <QObject>

class AlignmentMode : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(bool, isCrsAl)
    QS_FIELD(bool, isFiducialChk)
    QS_FIELD(bool, isOperatorCfm)
    QS_FIELD(bool, isAllowManualAl)

public:
    AlignmentMode();
    AlignmentMode(const AlignmentMode &alignmentMode);
    AlignmentMode &operator=(const AlignmentMode &alignmentMode);
};

class CrsAlPoints : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, S_Point2D, points)
    QS_COLLECTION(QList, QString, markID)
    QS_FIELD(double, threshold)
    QS_FIELD(double, searchWidth)
    QS_FIELD(double, searchHeight)
    QS_FIELD(int, searchStep)

public:
    CrsAlPoints();
    CrsAlPoints(const CrsAlPoints &alignPoint);
    CrsAlPoints &operator=(const CrsAlPoints &alignPoint);
};

class FineALPoints : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, S_Point2D, points)
    QS_COLLECTION(QList, QString, markID)
    QS_FIELD(double, threshold)
    QS_FIELD(double, minValidMarks)

public:
    FineALPoints();
    FineALPoints(const FineALPoints &fineALPoints);
    FineALPoints &operator=(const FineALPoints &fineALPoints);
};

class Alignm : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(AlignmentMode, mode)
    QS_COLLECTION_OBJECTS(QList, CrsAlPoints, crsAlPoints)
    QS_OBJECT(FineALPoints, fineALPoint)
    QS_OBJECT(S_Point2D, alOffset)
    QS_FIELD(bool, waferEdgeSearch)

public:
    Alignm();
    Alignm(const Alignm &alignment);
    Alignm &operator=(const Alignm &alignment);
};

#endif // ALIGN_H
