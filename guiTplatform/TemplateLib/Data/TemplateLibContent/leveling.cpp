#include "leveling.h"

S_Leveling::S_Leveling()
{

}

S_Leveling::S_Leveling(const S_Leveling &data)
{
    this->lst_FLPoints = data.lst_FLPoints;
    this->passThresholdNumber = data.passThresholdNumber;
}

S_Leveling &S_Leveling::operator=(const S_Leveling &data)
{
    this->lst_FLPoints = data.lst_FLPoints;
    this->passThresholdNumber = data.passThresholdNumber;
    return *this;
}
