#ifndef ALIGNERVIEW_H
#define ALIGNERVIEW_H

#include "GUIComponentLib_global.h"
#include <QWidget>

namespace Ui {
class AlignerView;
}

class GUICOMPONENTLIB_EXPORT AlignerView : public QWidget
{
    Q_OBJECT

public:
    explicit AlignerView(QWidget *parent = nullptr);
    ~AlignerView();

    void setRadius(int radius);
    void setAlignPoints(QList<QPointF> lst_Points);
    void setAlignColors(QList<QColor> lst_Colors);
    void setAlignScores(QList<int> lst_Scores);

protected:
    void paintEvent(QPaintEvent *event);

private:
    void clearDraw();
    void drawShape();
    void drawAlignment();                  //绘制对准


private:
    Ui::AlignerView *ui;

    int m_width{0};                        //宽度
    int m_height{0};                       //高度
    int m_radius{0};                       //直径
    double m_k{-1};                        //系数比例
    int mSize{0};                          //绘制的长度
    int centerX{0};
    int centerY{0};

    QList<QPointF> lst_AlignPoints;        //校准点坐标
    QList<QColor> lst_AlignColors;         //校准点颜色
    QList<int> lst_AlignScore;             //校准点分数
};

#endif // ALIGNERVIEW_H
