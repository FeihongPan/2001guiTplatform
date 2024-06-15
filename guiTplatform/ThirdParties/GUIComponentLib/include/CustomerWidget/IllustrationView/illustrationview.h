#ifndef ILLUSTRATIONVIEW_H
#define ILLUSTRATIONVIEW_H

#include "GUIComponentLib_global.h"
#include <QWidget>

namespace Ui
{
    class IllustrationView;
}

class GUICOMPONENTLIB_EXPORT IllustrationView : public QWidget
{
    Q_OBJECT

public:
    enum Shape
    {
        Rect = 0,     //方形
        Round,        //圆形
    };
    enum Mode
    {
        Normal = 0,   //正常
        Leveling,     //调平
        AlignMent,    //对准
        Exposure      //曝光
    };

public:
    explicit IllustrationView(QWidget *parent = nullptr);
    ~IllustrationView();

    void setShape(Shape shape);
    void setWidth(int width);
    void setHeight(int height);
    void setRadius(int ra);
    void setMode(Mode mode);
    void setFocAndLelPoints(QList<QPointF> lst_Points);
    void setFocAndLelColors(QList<QColor> lst_Colors);
    void setAlignPoints(QList<QPointF> lst_Points);
    void setAlignColors(QList<QColor> lst_Colors);
    void setAlignScores(QList<int> lst_Scores);

    Shape getShape();
    int getWidth();
    int getHeight();
    int getRadius();
    Mode getMode();
    QList<QPointF> getFocAndLelPoints();
    QList<QColor> getFocAndLelColors();
    QList<QPointF> getAlignPoints();
    QList<QColor> getAlignColors();
    QList<int> getAlignScores();

protected:
    void paintEvent(QPaintEvent *event);

private:
    void drawBackground();                 //绘制背景
    bool drawShape();                      //绘制形状
    void drawLeveling();                   //绘制调平
    void drawAlignment();                  //绘制对准
    void drawExposure();                   //绘制曝光


private:
    Ui::IllustrationView *ui;
    Mode m_mode{Normal};
    Shape m_shape{Rect};                   //形状
    int m_width{0};                        //宽度
    int m_height{0};                       //高度
    int m_radius{0};                       //直径
    double m_k{1};                         //系数比例

    int mSize{0};                          //绘制的长度
    int centerX{0};
    int centerY{0};

    QList<QPointF> lst_FocAndLelPoints;    //调平点坐标
    QList<QColor> lst_FocAndLelColors;     //调平点颜色
    QList<QPointF> lst_AlignPoints;        //校准点坐标
    QList<QColor> lst_AlignColors;         //校准点颜色
    QList<int> lst_AlignScore;             //校准点分数
};

#endif // ILLUSTRATIONVIEW_H
