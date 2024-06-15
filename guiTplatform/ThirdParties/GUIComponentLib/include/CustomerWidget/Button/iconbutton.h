#ifndef ICONBUTTON_H
#define ICONBUTTON_H

#include "GUIComponentLib_global.h"

#include "effectbutton.h"
#include <QPushButton>
#include <QObject>
#include <QLabel>
#include <QGraphicsDropShadowEffect>

class GUICOMPONENTLIB_EXPORT IconButton : public EffectButton
{
    Q_OBJECT
public:
    explicit IconButton(QWidget *parent = nullptr);
    ~IconButton();

    ///设置图标样式
    void SetIconStyle(QFont font, QString icon, int iconSzie,
                      QFont::Weight weight = QFont::Weight::Normal);
    ///设置垂直布局样式
    void SetVertivalStyle(QFont font, QString icon, int iconSzie, QString text, int textSize,
                          QFont::Weight weight = QFont::Weight::Normal);
    ///设置水平布局样式
    void SetHorizontalStyle(QFont font, QString icon, int iconSzie, QString text, int textSize,
                            QFont::Weight weight = QFont::Weight::Normal);
    ///设置文本
    void SetText(QString text);
    ///设置Icon
    void SetIcon(QFont font, QString icon);
    ///设置Icon及text的颜色
    void SetColor(QString color);
    ///通过status设置Icon及text的颜色
    void SetColor(Status status);
    ///设置Status::Normal、Pressed、Hover、Disabled状态对应的颜色
    void SetFrontColor(QString normal, QString pressed, QString hover, QString disable);

protected:
    QMap<Status, QString> dic_ContextColor;
    virtual void changeDisplayStatus() override;

//    virtual void setColor_Toggled(bool r) override;
//    virtual void setColor_Pressed() override;
//    virtual void setColor_Released() override;
//    virtual void changeDisplayStatus() override;

private:
    QLabel *lbl_Icon;
    QLabel *lbl_Text;
};

#endif // ICONBUTTON_H
