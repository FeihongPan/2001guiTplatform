#ifndef MATERIALINFO_H
#define MATERIALINFO_H

#include <QSerializer>

class Substrate : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, double, size)
    QS_FIELD(double, thickness)
    QS_FIELD(double, orientation)

public:
    Substrate();
    Substrate(const Substrate &substrate);
    Substrate &operator=(const Substrate &substrate);
};

//class MaterialInfo : public QSerializer
//{
//    Q_GADGET
//    QS_SERIALIZABLE

//    QS_COLLECTION_OBJECTS(QList, Substrate, substrates)

//public:
//    MaterialInfo();
//    MaterialInfo(const MaterialInfo &materialInfo);
//    MaterialInfo &operator=(const MaterialInfo &materialInfo);
//};

#endif // MATERIALINFO_H
