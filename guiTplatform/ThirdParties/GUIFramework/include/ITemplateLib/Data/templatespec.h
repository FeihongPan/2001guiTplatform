#ifndef TEMPLATESPEC_H
#define TEMPLATESPEC_H

#include "GUIFramework_global.h"
#include "Serializer/QSerializer"

class GUIFRAMEWORK_EXPORT S_TemplateSpec : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(int, idLength)
    QS_FIELD(int, serialNumLength)

public:
    S_TemplateSpec();
    S_TemplateSpec(const S_TemplateSpec &spec);
    S_TemplateSpec &operator=(const S_TemplateSpec &spec);
};

#endif // TEMPLATESPEC_H
