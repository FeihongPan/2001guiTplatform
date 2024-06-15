#ifndef TEMPLATELIBSIZE_H
#define TEMPLATELIBSIZE_H

#include "BasicValue/point.h"
#include "Serializer/QSerializer"

#include <QObject>

class TemplatelibSize : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE
    QS_FIELD(QString, shape)
    QS_FIELD(double, width)
    QS_FIELD(double, height)
    QS_FIELD(double, thickness)

public:
    TemplatelibSize();
    TemplatelibSize(const TemplatelibSize &data);
    TemplatelibSize &operator=(const TemplatelibSize &data);
};

#endif // TEMPLATELIBSIZE_H
