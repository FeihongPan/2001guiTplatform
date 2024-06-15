#ifndef LEVELINGVIEW_H
#define LEVELINGVIEW_H

#include "GUIComponentLib_global.h"
#include <QWidget>

namespace Ui {
class LevelingView;
}

class GUICOMPONENTLIB_EXPORT LevelingView : public QWidget
{
    Q_OBJECT

public:
    explicit LevelingView(QWidget *parent = nullptr);
    ~LevelingView();

    void setRadius(int radius);
    void setFocAndLelPoints(QList<QPointF> lst_Points);
    void setFocAndLelColors(QList<QColor> lst_Colors);
    void setFocAndLelValues(QList<double> lst_Values);

protected:
    void paintEvent(QPaintEvent *event);


private:
    void drawShape();
    void drawLeveling();

private:
    Ui::LevelingView *ui;

    int m_width{0};                        //宽度
    int m_height{0};                       //高度
    int m_radius{0};                       //直径
    double m_k{-1};                        //缩放比例系数
    int mSize{0};                          //绘制的长度
    int centerX{0};
    int centerY{0};

    QList<QPointF> lst_FocAndLelPoints;    //调平点坐标
    QList<QColor> lst_FocAndLelColors;     //调平点颜色
    QList<double> lst_FocAndLelValues;     //调平点值


};

#endif // LEVELINGVIEW_H
