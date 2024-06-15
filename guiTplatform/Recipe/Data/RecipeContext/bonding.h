#ifndef BONDING_H
#define BONDING_H

#include <QSerializer>

class BondingSequence : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(QString, cmd)
    QS_COLLECTION(QList, double, parameters)

public:
    BondingSequence();
    BondingSequence(const BondingSequence &sequence);
    BondingSequence &operator=(const BondingSequence &sequence);
};

class BondingSettings : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, double, preBondTemp)

public:
    BondingSettings();
    BondingSettings(const BondingSettings &settings);
    BondingSettings &operator=(const BondingSettings &settings);
};

class Bonding : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(BondingSettings, settings)
    QS_COLLECTION_OBJECTS(QList, BondingSequence, bondingSequence)
    QS_FIELD(int, vacOffStableTime)

public:
    Bonding();
    Bonding(const Bonding &bonding);
    Bonding &operator=(const Bonding &bonding);
};

#endif // BONDING_H
