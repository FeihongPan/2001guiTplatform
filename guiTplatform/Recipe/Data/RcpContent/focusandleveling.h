#ifndef FOCUSANDLEVELING_H
#define FOCUSANDLEVELING_H

#include "BasicValue/point.h"
#include "Serializer/QSerializer"

class S_FocusAndLeveling : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(bool, isMapping)
    QS_OBJECT(S_Point2D, mappingInterval)
    QS_COLLECTION_OBJECTS(QList, S_Point2D, lst_FLPoints)
    QS_FIELD(double, focusOffset)
    QS_FIELD(double, passThresholdNumber)

public:
    S_FocusAndLeveling();
    S_FocusAndLeveling(const S_FocusAndLeveling &data);
    S_FocusAndLeveling &operator=(const S_FocusAndLeveling &data);
};

#endif // FOCUSANDLEVELING_H
