#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include "BasicValue/point.h"
#include "Serializer/QSerializer"

class S_AlignPoint : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_Point2D, point)
    QS_FIELD(QString, markId)
    QS_FIELD(QString, threshold)

public:
    S_AlignPoint();
    S_AlignPoint(const S_AlignPoint &point);
    S_AlignPoint &operator=(const S_AlignPoint &point);
};

class S_Alignment : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(int, model)
    QS_FIELD(double, CCD_Pos)
    QS_COLLECTION(QList, double, lst_RotatingAngles)
    QS_COLLECTION_OBJECTS(QList, S_AlignPoint, lst_AlignPoints)
    QS_FIELD(double, minValidMarks)

public:
    S_Alignment();
    S_Alignment(const S_Alignment &align);
    S_Alignment &operator=(const S_Alignment &align);
};

#endif // ALIGNMENT_H
