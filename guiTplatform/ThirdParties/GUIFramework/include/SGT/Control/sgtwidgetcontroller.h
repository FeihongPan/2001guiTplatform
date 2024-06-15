#ifndef SGTWIDGETCONTROLLER_H
#define SGTWIDGETCONTROLLER_H

#include "GUIFramework_global.h"
#include "SGT/Data/sgtsystem.h"
#include "SGT/Data/sgtconstant.h"

#include <QObject>
#include <QPushButton>
#include <QMap>
#include <QTimer>

class GUIFRAMEWORK_EXPORT SGTWidgetController : public QObject
{
    Q_OBJECT
public:
    explicit SGTWidgetController(QObject *parent = nullptr);
    static SGTWidgetController *getInstance();
    ~SGTWidgetController();

    void RegisteSGTWidget(SGTSystem::SGTComponent component, QPushButton *btn);
    void Terminate();

private:
    void setSGTWidgetState();
private:
    static SGTWidgetController *self;

    QMap<SGTSystem::SGTComponent, QPushButton *> dic_SGTWidget;
    QMap<QPushButton *, int> dic_WidgetElapse;
    QTimer m_Timer;
    int m_Interval = 100;
    S_SGTTwinkleData m_TwinkleData;
};

#endif // SGTWIDGETCONTROLLER_H
