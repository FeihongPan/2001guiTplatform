#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include "GUIComponentLib_global.h"

#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QColor>

class GUICOMPONENTLIB_EXPORT SwitchButton : public QWidget
{
    Q_OBJECT
public:
    explicit SwitchButton(QWidget *parent = nullptr);

public Q_SLOTS:
    void setSpace(int space);                     ///设置滑块距离边界距离
    void setRadius(int radius);                   ///设置圆角角度
    void setChecked(bool checked);                ///设置选中状态
    void setShowText(bool show);                  ///设置是否显示文本
    void setShowCircle(bool show);                ///设置是否显示圆
    void setAnimation(bool ok);                   ///设置是否使用动画
    void setBgColorOn(const QColor &color);       ///设置选中背景色
    void setBgColorOff(const QColor &color);      ///设置未选中背景色
    void setSliderColorOn(const QColor &color);   ///设置选中滑块颜色
    void setSliderColorOff(const QColor &color);  ///设置未选中滑块颜色
    void setTextColor(const QColor &color);       ///设置文本颜色
    void setTextOn(const QString &text);          ///设置选中文本
    void setTextOff(const QString &text);         ///设置未选中文本
public:
    int space()                 const;            ///滑块距离边界距离
    int radius()                const;            ///圆角角度
    bool checked()              const;            ///选中状态
    bool showText()             const;            ///是否显示文本
    bool showCircle()           const;            ///是否显示圆
    bool animation()            const;            ///是否使用动画
    QColor bgColorOn()          const;            ///选中背景色
    QColor bgColorOff()         const;            ///未选中背景色
    QColor sliderColorOn()      const;            ///选中滑块颜色
    QColor sliderColorOff()     const;            ///未选中滑块颜色
    QColor textColor()          const;            ///文本颜色
    QString textOn()            const;            ///选中文本
    QString textOff()           const;            ///未选中文本
    int step()                  const;            ///动画步长
    int startX()                const;            ///滑块开始X轴坐标
    int endX()                  const;            ///滑块介绍X轴坐标
signals:
    void statusChanged(bool checked);             ///选中状态发生改变

private slots:
    void UpdateValue();
    void on_Enable();

private:
    void drawBackGround(QPainter *painter);
    void drawSlider(QPainter *painter);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    //滑块距离边界距离
    int m_space;
    //圆角角度
    int m_radius;
    //是否选中
    bool m_checked;
    //是否显示文本
    bool m_showText;
    //是否显示圆
    bool m_showCircle;
    //是否使用动画
    bool m_animation;

    //打开时候背景色
    QColor m_bgColorOn;
    //关闭时候背景色
    QColor m_bgColorOff;
    //打开时候滑块颜色
    QColor m_sliderColorOn;
    //关闭时候滑块颜色
    QColor m_sliderColorOff;
    //文字颜色
    QColor m_textColor;

    //打开时候文字
    QString m_textOn;
    //关闭时候文字
    QString m_textOff;

    //动画定时器
    QTimer *m_timer;

    QTimer *m_timerStatus;

    bool enable{true};
    //动画步长
    int m_step;
    //滑块开始X轴坐标
    int m_startX;
    //滑块介绍X轴坐标
    int m_endX;
    bool m_zoom{false};

//    void setStep(int step);
//    void setStartX(int startX);
//    void setEndX(int endX);
};

#endif // SWITCHBUTTON_H
