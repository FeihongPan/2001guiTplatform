#ifndef ICONLINEEDIT_H
#define ICONLINEEDIT_H

#include "GUIComponentLib_global.h"

#include <QLineEdit>
#include <QObject>
#include <QPushButton>
#include <QHBoxLayout>
#include <QEvent>
class GUICOMPONENTLIB_EXPORT IconLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    enum Dock
    {
        Left,                               ///图标靠左
        Right,                              ///图标靠右
    };
    Q_ENUM(Dock)
    explicit IconLineEdit(QWidget *parent = nullptr);

    bool event(QEvent *e) override;

    void SetIconFont(QFont font);           ///设置Icon的字体
    void SetIcon(QString icon, int size);   ///设置Icon及Icon大小
    void SetIconDock(Dock dock);            ///设置Icon停靠的方向
    QPushButton * GetIconButton();          ///获取图标按钮指针

signals:
    void iconClicked(QString str);          ///点击
    void iconPressed();                     ///按下
    void iconReleased();                    ///松开

private:
    QFont font;
    QString icon;
    int size = 12;
    QPushButton *btn_Icon = new QPushButton();
    QHBoxLayout *layout;
    Dock dock;
};

#endif // ICONLINEEDIT_H
