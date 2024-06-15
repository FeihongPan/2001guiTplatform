#include "bonding.h"

Bonding::Bonding()
{
    vacOffStableTime = 60000;
}

Bonding::Bonding(const Bonding &bonding)
{
    this->settings = bonding.settings;
    this->vacOffStableTime = bonding.vacOffStableTime;
    this->bondingSequence = bonding.bondingSequence;
}

Bonding &Bonding::operator=(const Bonding &bonding)
{
    this->settings = bonding.settings;
    this->vacOffStableTime = bonding.vacOffStableTime;
    this->bondingSequence = bonding.bondingSequence;
    return *this;
}

BondingSequence::BondingSequence()
{

}

BondingSequence::BondingSequence(const BondingSequence &sequence)
{
    this->cmd = sequence.cmd;
    this->parameters =  sequence.parameters;
}

BondingSequence &BondingSequence::operator=(const BondingSequence &sequence)
{
    this->cmd = sequence.cmd;
    this->parameters =  sequence.parameters;
    return *this;
}

BondingSettings::BondingSettings()
{

}

BondingSettings::BondingSettings(const BondingSettings &settings)
{
    this->preBondTemp = settings.preBondTemp;
}

BondingSettings &BondingSettings::operator=(const BondingSettings &settings)
{
    this->preBondTemp = settings.preBondTemp;
    return *this;
}
