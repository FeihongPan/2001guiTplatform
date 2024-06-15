#ifndef EXPOSUREVIEW_H
#define EXPOSUREVIEW_H

#include "GUIComponentLib_global.h"
#include <QWidget>

namespace Ui {
class ExposureView;
}

class GUICOMPONENTLIB_EXPORT ExposureView : public QWidget
{
    Q_OBJECT

public:
    explicit ExposureView(QWidget *parent = nullptr);
    ~ExposureView();

protected:
    void paintEvent(QPaintEvent *event);

private:
    void drawShape();
    void drawExposure();                   //绘制曝光

private:
    Ui::ExposureView *ui;

    int m_width{0};                        //宽度
    int m_height{0};                       //高度
    int m_radius{0};                       //直径
    double m_k{1};                         //系数比例
    int mSize{0};                          //绘制的长度
    int centerX{0};
    int centerY{0};

    int totalCount{15};
    QPoint point;
    bool isLeftStart{true};
};

#endif // EXPOSUREVIEW_H
