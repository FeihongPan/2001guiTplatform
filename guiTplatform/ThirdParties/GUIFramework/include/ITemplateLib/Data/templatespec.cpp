#include "templatespec.h"

S_TemplateSpec::S_TemplateSpec()
{

}

S_TemplateSpec::S_TemplateSpec(const S_TemplateSpec &spec)
{
    this->idLength = spec.idLength;
    this->serialNumLength = spec.serialNumLength;
}

S_TemplateSpec &S_TemplateSpec::operator=(const S_TemplateSpec &spec)
{
    this->idLength = spec.idLength;
    this->serialNumLength = spec.serialNumLength;
    return *this;
}
