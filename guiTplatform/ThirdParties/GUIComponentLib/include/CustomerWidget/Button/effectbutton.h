#ifndef EFFECTBUTTON_H
#define EFFECTBUTTON_H
#include "GUIComponentLib_global.h"

#include <QPushButton>
#include <QObject>
#include <QGraphicsDropShadowEffect>
#include <QMap>

class GUICOMPONENTLIB_EXPORT EffectInfo
{
public:
    QPointF offset = QPointF(0,0);
    QString color = "#FFFFFF";
    int blurRadius = 1;
};

class GUICOMPONENTLIB_EXPORT EffectButton : public QPushButton
{
    Q_OBJECT
public:
    enum Status
    {
        Normal,     ///正常
        Hover,      ///悬浮
        Pressed,    ///按下
        Disabled,   ///不可用
    };
    Q_ENUM(Status)

    explicit EffectButton(QWidget *parent = nullptr);
    ~EffectButton();

    bool event(QEvent *e) override;
    ///设置status对应的投影方向，颜色，模糊半径
    void SetEffectInfo(Status status, int offset_x, int offset_y, QString color, int blur);
    ///设置是否启动effect
    void SetEffectStatus(bool on);

public:
    QGraphicsDropShadowEffect *effect;

protected:
    virtual void setColor_Toggled(bool r);
    virtual void setColor_Pressed();
    virtual void setColor_Released();
    virtual void changeDisplayStatus();

    bool isHover = false;
    bool isPressed = false;
    QMap<Status, EffectInfo> dic_EffectInfos;
    void setEffectStatus(Status status);
    bool bEffectOn = false;

private:
    void setEffectInfo(Status status, int offset_x, int offset_y, QString color, int blur);

};

#endif // EFFECTBUTTON_H
