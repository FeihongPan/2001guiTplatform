#include "templatelibcontent.h"

S_TemplateLibContent::S_TemplateLibContent()
{

}

S_TemplateLibContent::S_TemplateLibContent(const S_TemplateLibContent &content)
{
    this->leveing = content.leveing;
    this->align = content.align;
    this->templateLibSize = content.templateLibSize;
}

S_TemplateLibContent &S_TemplateLibContent::operator=(const S_TemplateLibContent &content)
{
    this->leveing = content.leveing;
    this->align = content.align;
    this->templateLibSize = content.templateLibSize;
    return *this;
}
