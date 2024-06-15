#ifndef SUBSTRATE_H
#define SUBSTRATE_H

#include "Serializer/QSerializer"

class S_Substrate : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, double, size)
    QS_FIELD(double, thickness)
    QS_FIELD(double, orientation)

public:
    S_Substrate();
    S_Substrate(const S_Substrate &sub);
    S_Substrate &operator=(const S_Substrate &sub);
};


class S_Stencil : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(QString, id)

public:
    S_Stencil();
    S_Stencil(const S_Stencil &stl);
    S_Stencil &operator=(const S_Stencil &stl);
};

#endif // SUBSTRATE_H
