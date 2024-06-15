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
    QDoubleSpinBox *GetDoubleSpinBox();   ///获取QDoubleSpinBox控件指针
    QPushButton *GetBtn();                ///获取QPushButton控件指针

private:
    Ui::BtnDoubleSpinBox *ui;
};

#endif // BTNDOUBLESPINBOX_H
