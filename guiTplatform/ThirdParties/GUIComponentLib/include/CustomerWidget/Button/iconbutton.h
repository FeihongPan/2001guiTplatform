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

    ///����ͼ����ʽ
    void SetIconStyle(QFont font, QString icon, int iconSzie,
                      QFont::Weight weight = QFont::Weight::Normal);
    ///���ô�ֱ������ʽ
    void SetVertivalStyle(QFont font, QString icon, int iconSzie, QString text, int textSize,
                          QFont::Weight weight = QFont::Weight::Normal);
    ///����ˮƽ������ʽ
    void SetHorizontalStyle(QFont font, QString icon, int iconSzie, QString text, int textSize,
                            QFont::Weight weight = QFont::Weight::Normal);
    ///�����ı�
    void SetText(QString text);
    ///����Icon
    void SetIcon(QFont font, QString icon);
    ///����Icon��text����ɫ
    void SetColor(QString color);
    ///ͨ��status����Icon��text����ɫ
    void SetColor(Status status);
    ///����Status::Normal��Pressed��Hover��Disabled״̬��Ӧ����ɫ
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
