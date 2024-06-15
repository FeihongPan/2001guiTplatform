#ifndef VISION_H
#define VISION_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

#include <QObject>
//#include "matrix.h"

class SR_Vision;
class GUIFRAMEWORK_EXPORT S_Vision : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(QString, matrixInternal)
    QS_FIELD(QString, matrixExternal)
public:
    S_Vision();
    S_Vision(const S_Vision &vision);
    S_Vision(const SR_Vision &vision);
    S_Vision &operator=(const S_Vision &vision);
    S_Vision &operator=(const SR_Vision &vision);
};


class GUIFRAMEWORK_EXPORT SR_Vision : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TString, matrixInternal)
    QS_OBJECT(TString, matrixExternal)
public:
    SR_Vision();
    SR_Vision(const S_Vision &vision);
    SR_Vision(const SR_Vision &vision);
    SR_Vision &operator=(const S_Vision &vision);
    SR_Vision &operator=(const SR_Vision &vision);

};




#endif // VISION_H
