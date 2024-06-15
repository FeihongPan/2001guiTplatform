#include "templatelibsize.h"

TemplatelibSize::TemplatelibSize()
{

}

TemplatelibSize::TemplatelibSize(const TemplatelibSize &data)
{
    this->shape = data.shape;
    this->width = data.width;
    this->height = data.height;
    this->thickness = data.thickness;
}

TemplatelibSize &TemplatelibSize::operator=(const TemplatelibSize &data)
{
    this->shape = data.shape;
    this->width = data.width;
    this->height = data.height;
    this->thickness = data.thickness;
    return *this;
}
