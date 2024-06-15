#include "focandlev.h"


FocAndLev::FocAndLev()
{

}

FocAndLev::FocAndLev(const FocAndLev &focAndLev)
{
    this->flPoints = focAndLev.flPoints;
    this->focOffset = focAndLev.focOffset;
    this->bondIfOffset = focAndLev.bondIfOffset;
}

FocAndLev &FocAndLev::operator=(const FocAndLev &focAndLev)
{
    this->flPoints = focAndLev.flPoints;
    this->focOffset = focAndLev.focOffset;
    this->bondIfOffset = focAndLev.bondIfOffset;
    return *this;
}
