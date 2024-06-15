#ifndef LEVELING_H
#define LEVELING_H

#include "BasicValue/point.h"
#include "Serializer/QSerializer"

class S_Leveling : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, S_Point2D, lst_FLPoints)
    QS_FIELD(int, passThresholdNumber)

public:
    S_Leveling();
    S_Leveling(const S_Leveling &data);
    S_Leveling &operator=(const S_Leveling &data);
};

#endif // LEVELING_H
