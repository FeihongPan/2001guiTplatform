#include "focusandleveling.h"

S_FocusAndLeveling::S_FocusAndLeveling()
{

}

S_FocusAndLeveling::S_FocusAndLeveling(const S_FocusAndLeveling &data)
{
    this->isMapping = data.isMapping;
    this->mappingInterval = data.mappingInterval;
    this->lst_FLPoints = data.lst_FLPoints;
    this->focusOffset = data.focusOffset;
    this->passThresholdNumber = data.passThresholdNumber;
}

S_FocusAndLeveling &S_FocusAndLeveling::operator=(const S_FocusAndLeveling &data)
{
    this->isMapping = data.isMapping;
    this->mappingInterval = data.mappingInterval;
    this->lst_FLPoints = data.lst_FLPoints;
    this->focusOffset = data.focusOffset;
    this->passThresholdNumber = data.passThresholdNumber;
    return *this;
}
