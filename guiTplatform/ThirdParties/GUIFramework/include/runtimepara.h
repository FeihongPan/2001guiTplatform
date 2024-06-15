#ifndef RUNTIMEPARA_H
#define RUNTIMEPARA_H

#include "GUIFramework_global.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT RuntimePara : public QObject
{
    Q_OBJECT
public:
    explicit RuntimePara(QObject *parent = nullptr);

    ~RuntimePara();

    static RuntimePara *getInstance();

signals:

public:
    QWidget *p_BlurParentWidget = nullptr;

private:
    static RuntimePara *self;

};


#endif // RUNTIMEPARA_H
