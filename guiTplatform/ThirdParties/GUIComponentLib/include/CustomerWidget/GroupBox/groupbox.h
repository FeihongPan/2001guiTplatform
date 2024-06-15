#ifndef GROUPBOX_H
#define GROUPBOX_H

#include "GUIComponentLib_global.h"

#include <QGroupBox>
#include <QGraphicsDropShadowEffect>

namespace Ui {
class GroupBox;
}

class GUICOMPONENTLIB_EXPORT GroupBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit GroupBox(QWidget *parent = nullptr);
    ~GroupBox();
    void resizeEvent(QResizeEvent *event) override;

    void SetDecorateColor(QString color);    ///设置装饰条颜色
    void SetHeaderText(QString text);        ///设置标题内容
    void SetheaderFontSize(int size);        ///设置标题字体大小
    void SetHeaderFontColor(QString color);  ///设置标题字体颜色
private:
    Ui::GroupBox *ui;
};

#endif // GROUPBOX_H
