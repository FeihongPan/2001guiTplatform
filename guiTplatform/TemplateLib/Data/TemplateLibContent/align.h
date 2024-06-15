#ifndef ALIGN_H
#define ALIGN_H

#include "BasicValue/point.h"
#include "Serializer/QSerializer"

class S_AlignPointInfo : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_Point2D, point)
    QS_FIELD(QString, markId)
    QS_FIELD(QString, threshold)

public:
    S_AlignPointInfo();
    S_AlignPointInfo(const S_AlignPointInfo &point);
    S_AlignPointInfo &operator=(const S_AlignPointInfo &point);
};

class S_Align : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, S_AlignPointInfo, lst_AlignPoints)
    QS_FIELD(int, passThresholdNumber)

public:
    S_Align();
    S_Align(const S_Align &align);
    S_Align &operator=(const S_Align &align);
};

#endif // ALIGN_H
