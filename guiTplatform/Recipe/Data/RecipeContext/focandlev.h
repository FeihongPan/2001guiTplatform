#ifndef FOCANDLEV_H
#define FOCANDLEV_H

#include "BasicValue/point.h"

#include <QSerializer>

class FocAndLev : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION_OBJECTS(QList, S_Point2D, flPoints)
    QS_COLLECTION(QList, double, focOffset)
    QS_COLLECTION(QList, double, bondIfOffset)

public:
    FocAndLev();
    FocAndLev(const FocAndLev &focAndLev);
    FocAndLev &operator=(const FocAndLev &focAndLev);
};

#endif // FOCANDLEV_H
