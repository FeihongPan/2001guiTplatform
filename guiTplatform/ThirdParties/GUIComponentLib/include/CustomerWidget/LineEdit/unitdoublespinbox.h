#ifndef UNITDOUBLESPINBOX_H
#define UNITDOUBLESPINBOX_H

#include "GUIComponentLib_global.h"
#include <QWidget>
#include <QDoubleSpinBox>
#include "StyleSheet/stylesheet.h"

namespace Ui {
class UnitDoubleSpinBox;
}

class GUICOMPONENTLIB_EXPORT UnitDoubleSpinBox : public QWidget
{
    Q_OBJECT

public:
    explicit UnitDoubleSpinBox(QWidget *parent = nullptr);
    ~UnitDoubleSpinBox();
    QDoubleSpinBox * GetDoubleSpinBox();   ///获取QDoubleSpinBox控件指针
    QLineEdit *GetLineEdit();              ///获取QLineEdit控件指针

private:
    Ui::UnitDoubleSpinBox *ui;
};

#endif // UNITDOUBLESPINBOX_H
