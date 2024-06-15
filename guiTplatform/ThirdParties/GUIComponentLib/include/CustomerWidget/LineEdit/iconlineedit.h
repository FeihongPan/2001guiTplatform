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
        Left,                               ///ͼ�꿿��
        Right,                              ///ͼ�꿿��
    };
    Q_ENUM(Dock)
    explicit IconLineEdit(QWidget *parent = nullptr);

    bool event(QEvent *e) override;

    void SetIconFont(QFont font);           ///����Icon������
    void SetIcon(QString icon, int size);   ///����Icon��Icon��С
    void SetIconDock(Dock dock);            ///����Iconͣ���ķ���
    QPushButton * GetIconButton();          ///��ȡͼ�갴ťָ��

signals:
    void iconClicked(QString str);          ///���
    void iconPressed();                     ///����
    void iconReleased();                    ///�ɿ�

private:
    QFont font;
    QString icon;
    int size = 12;
    QPushButton *btn_Icon = new QPushButton();
    QHBoxLayout *layout;
    Dock dock;
};

#endif // ICONLINEEDIT_H
