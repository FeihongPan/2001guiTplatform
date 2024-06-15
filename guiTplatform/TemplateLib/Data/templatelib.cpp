#include "templatelib.h"

S_TemplateLib::S_TemplateLib()
{

}

S_TemplateLib::S_TemplateLib(const S_TemplateLib &templateLib)
{
    this->templateInfo = templateLib.templateInfo;
    this->templateLibContent = templateLib.templateLibContent;
}

S_TemplateLib &S_TemplateLib::operator=(const S_TemplateLib &templateLib)
{
    this->templateInfo = templateLib.templateInfo;
    this->templateLibContent = templateLib.templateLibContent;
    return *this;
}
