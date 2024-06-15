#ifndef BTNDOUBLESPINBOX_H
#define BTNDOUBLESPINBOX_H

#include "GUIComponentLib_global.h"
#include <QWidget>
#include <QDoubleSpinBox>
#include <QPushButton>

namespace Ui {
class BtnDoubleSpinBox;
}

class GUICOMPONENTLIB_EXPORT BtnDoubleSpinBox : public QWidget
{
    Q_OBJECT
public:
    explicit BtnDoubleSpinBox(QWidget *parent = nullptr);
    ~BtnDoubleSpinBox();
    QDoubleSpinBox *GetDoubleSpinBox();   ///��ȡQDoubleSpinBox�ؼ�ָ��
    QPushButton *GetBtn();                ///��ȡQPushButton�ؼ�ָ��

private:
    Ui::BtnDoubleSpinBox *ui;
};

#endif // BTNDOUBLESPINBOX_H
