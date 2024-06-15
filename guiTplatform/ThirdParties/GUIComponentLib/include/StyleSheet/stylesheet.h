#ifndef STYLESHEET_H
#define STYLESHEET_H

#include "GUIComponentLib_global.h"

#include <QObject>
#include <QFont>
#include <QColor>

#define GlobalStyleSheet StyleSheet::getInstance()

class GUICOMPONENTLIB_EXPORT StyleSheet : public QObject
{
    Q_OBJECT
public:
    explicit StyleSheet(QObject *parent = nullptr);
    static StyleSheet *getInstance();
    QFont Font();
signals:

public:
    QString Color_Blue = "#4C70FA";
    QString Color_Green = "#35EF14";
    QString Color_Red = "#FD6B6D";
    QString Color_Yellow = "#EDAD16";


    QString CalendarWidgetStyle = "QDateTimeEdit{border-radius:6px; border:1px solid rgb(220,220,220); padding:3px 0px 3px 6px; color:#000000; selection-background-color:#4C70FA; }\
            QDateTimeEdit::drop-down{border:none; width:22px; margin-right:5px; }\
            QDateTimeEdit::down-arrow{ width:22px;  height:22px; border-image:url(:/image/calendarwidget/calendar.png);  }\
            QCalendarWidget QWidget#qt_calendar_navigationbar{background-color:#4C70FA;}\
            QCalendarWidget QToolButton{ height:25px; color:white;  font-size:20px; icon-size:40px,40px; background-color:#4C70FA; }\
            QCalendarWidget QToolButton#qt_calendar_prevmonth{ qproperty-icon:url(:/image/calendarwidget/left0.png); }\
            QCalendarWidget QToolButton#qt_calendar_nextmonth{ qproperty-icon:url(:/image/calendarwidget/right0.png); }\
            QCalendarWidget QSpinBox{font-size:20px; color:white; background-color:#4C70FA; selection-background-color:#4C70FA; selection-color:#FFFFFF; }\
            QCalendarWidget QSpinBox::up-button{ subcontrol-origin:border; subcontrol-position:top right; }\
            QCalendarWidget QSpinBox::down-button{ subcontrol-origin:border; subcontrol-position:bottom right; }\
            QCalendarWidget QAbstractItemView:enabled{ font-size:18px; }";


    QString GroupBoxStyle = "QGroupBox{border:none;border-radius:10px;background-color:#FFFFFF}"
                            "QLabel{background-color:transparent;}";

    QString NaviButtonStyle = "QPushButton{background-color:#FFFFFF; border-style:none}"
                              "QLabel{background-color:transparent;}";

    QString SubNaviButtonStyle = "QPushButton{background-color:#FFFFFF;border-style:none}"
                                 "QPushButton:pressed{background-color:#F3F4FA;}"
                                 "QPushButton:checked{background-color:#F3F4FA;}"
                                 "QLabel{background-color:transparent;}";

    QString Button_Motion = "QPushButton{background-color:rgba(76,112,250,200); border:1px solid #4D70FA; border-radius:5px;color:#FFFFFF;}"
                            "QPushButton:hover{border:none; background-color:#A4B7FF;color:#FFFFFF;}"
                            "QPushButton:pressed{border:none; background-color:#4C70FA;color:#FFFFFF;}"
                            "QPushButton:checked{border:none; background-color:#4C70FA;color:#FFFFFF;}"
                            "QLabel{background-color:transparent;}";

    QString ButtonStyle_Front = "QPushButton{color:#707070;background-color:transparent; border-style:none; border-radius:10px;}"
                                "QPushButton:hover{color:#A4B7FF;}"
                                "QPushButton:pressed{color:#4C70FA;}"
                                "QPushButton:checked{color:#4C70FA;}"
                                "QPushButton:disabled{color:#D4D4D4;}";

    QString ButtonStyle_Back = "QPushButton{background-color:#FFFFFF; border-style:none; border-radius:10px;}"
                               "QPushButton:hover{background-color:#A4B7FF;}"
                               "QPushButton:pressed{background-color:#4C70FA;}"
                               "QPushButton:checked{background-color:#4C70FA;}"
                               "QPushButton:disabled{background-color:#D4D4D4;}"
                               "QLabel{background-color:transparent;}";

    QString Button_Border = "QPushButton{background-color:rgba(255,255,255,255);color:#4D70FA;border:1px solid rgba(76,112,250,200); border-radius:5px;font-size:14px;}"
                            "QPushButton:hover{border:none; background-color:#A4B7FF;color:#FFFFFF;}"
                            "QPushButton:pressed{border:none; background-color:#4C70FA;color:#FFFFFF;}"
                            "QPushButton:checked{border:none; background-color:#4C70FA;color:#FFFFFF;}"
                            "QPushButton:disabled{border:none; background-color:#D4D4D4;color:#FFFFFF;}"
                            "QLabel{background-color:transparent;}";

    QString Button_DIO = "QPushButton{background-color:#FFFFFF; border:1px solid #4D70FA; border-radius:5px;color:#4C70FA;}"
                         "QPushButton:hover{border:none; background-color:#A4B7FF;color:#FFFFFF;}"
                         "QPushButton:pressed{border:none; background-color:#4C70FA;color:#FFFFFF;}"
                         "QPushButton:checked{border:none; background-color:#4C70FA;color:#FFFFFF;}"
                         "QLabel{background-color:transparent;}";

    QString ComboBox = "QComboBox{color:#808080;background-color:#FFFFFF;padding-left:5px;padding-right:5px;padding-top:2px;padding-bottom:2px;border:1px solid #808080;border-radius:3px;}"
                       "QComboBox:hover{border:1px solid #A4B7FF;}"
                       "QComboBox:on{border:1px solid #4C70FA;border-top-left-radius:3px;border-top-right-radius:3px;border-bottom-left-radius:0px;border-bottom-right-radius:0px;}"
                       "QComboBox::drop-down{border: none;}"
                       "QComboBox::down-arrow{width:10;height:10;image: url(:/icon/Arrow_Down.svg)}"
                       "QComboBox::down-arrow:on{width:10;height:10;image: url(:/icon/Arrow_Up.svg);}"
                       "QComboBox QAbstractItemView{outline: 0px;border:1px solid #4C70FA;border-radius:0px;color:#808080;background-color:transparent;}"
                       "QComboBox QAbstractItemView::item{padding-left:5px;padding-right:5px;padding-top:3px;padding-bottom:3px;color: #808080;background-color:#FFFFFF;}"
                       "QComboBox QAbstractItemView::item:selected{background-color:qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0.6 #F3F6FF, stop:1 #FFFFFF); color:#4C70FA;}"
                       "QComboBox QAbstractItemView::item:hover{background-color:qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0.6 #F3F6FF, stop:1 #FFFFFF); color:#4C70FA;}"
                       "QComboBox:disabled{background-color:#D8D8D8;color:#FFFFFF;}";

    QString LineEdit_Dark = "QLineEdit{border:1px solid #EEEEEE;padding:5px 2px;background-color:#EEEEEE;border-radius:10px;color:#686868;}"
                            "QLineEdit:hover{border:1px solid #A4B7FF;}"
                            "QLineEdit:focus{border:1px solid #4C70FA;}"
                            "QLineEdit:disabled{background-color:#C8C8C8;color:#FFFFFF;}";
    QString LineEdit = "QLineEdit{border:1px solid #EEEEEE;padding:5px 2px;background-color:#EEEEEE;border-radius:1px;color:#686868;}"
                       "QLineEdit:hover{border:1px solid #A4B7FF;}"
                       "QLineEdit:focus{border:1px solid #4C70FA;}"
                       "QLineEdit:disabled{background-color:#C8C8C8;color:#FFFFFF;}";

    QString SpinBox_Dark = "QSpinBox{border:1px solid #EEEEEE;padding:5px 2px;background-color:#EEEEEE;border-radius:5px;color:#686868;}"
                           "QSpinBox:hover{border:1px solid #A4B7FF;}"
                           "QSpinBox:focus{border:1px solid #4C70FA;}"
                           "QSpinBox:disabled{background-color:#C8C8C8;color:#FFFFFF;}";

    QString DoubleSpinBox_Dark = "QDoubleSpinBox{border:1px solid #EEEEEE;padding:5px 2px;background-color:#EEEEEE;border-radius:5px;color:#686868;}"
                                 "QDoubleSpinBox:hover{border:1px solid #A4B7FF;}"
                                 "QDoubleSpinBox:focus{border:1px solid #4C70FA;}"
                                 "QDoubleSpinBox:disabled{background-color:#C8C8C8;color:#FFFFFF;}";
    QString DoubleSpinBox_Dark_NoneColor = "QDoubleSpinBox{border:1px solid #EEEEEE;padding:5px 2px;border-radius:5px;}"
                                           "QDoubleSpinBox:hover{border:1px solid #A4B7FF;}"
                                           "QDoubleSpinBox:focus{border:1px solid #4C70FA;}"
                                           "QDoubleSpinBox:disabled{background-color:#C8C8C8;color:#FFFFFF;}";

    const QString tableStyle = "QTableView{show-decoration-selected:1;border:1px solid #E0DDDC; border-radius:0px;}";

    QString TabWidget = "QTabWidget{border:none;border-radius:5;background-color: blue;}"
                        "QTabWidget::pane{border-bottom-left-radius:5;border-bottom-right-radius:10;background-color:transparent;}"
                        "QTabBar{background-color:transparent;}"
                        "QTabBar::tab{width:180;height:30;border-bottom:5px solid #D4D4D4;color:#4D4D4D;}"
                        "QTabBar::tab:hover{border-bottom:5px solid #A4B7FF;color:#4D4D4D;}"
                        "QTabBar::tab:selected{border-bottom:5px solid #4C70FA;color:#4D4D4D;}";

    const QString tabLineStyle = "background-color: rgb(220,220,220);";

    const QString tabStyle_oneTab = QString("QWidget{ background-color: rgb(255, 255, 255);}\
                                       QTabWidget::pane { border: 1px solid #FFFFFF; background-color:#FFFFFF; border-top: 0px solid #C2C7CB;\
                                                          border-bottom-left-radius:10px; border-bottom-right-radius:10px;}\
                                       QTabWidget{border:0px solid rgb(100, 100, 100);border-radius:5; background-color:transparent;}\
                                       QTabBar{background-color:transparent;}\
                                       QTabBar::tab{width:169;height:24;font-family:HarmonyOS Sans;font-weight:bold;font-size:12pt;color:rgb(0, 0, 0);\
                                       border-top:8px solid rgb(220,220,220);\
                                       border-bottom:8px solid qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgb(220, 220, 220), stop:1 rgb(200, 200, 200));color:#4D4D4D;}\
                                       QTabBar::tab:!selected{ background-color:rgb(220,220,220); color:rgb(60, 165, 250);border-right:0px solid rgb(120,120,120); border-left:0px solid rgb(120,120,120); }\
                                       QTabBar::tab:selected{background-color:rgb(255,255,255); border-right:0px solid rgb(120,120,120);\
                                                             border-left:0px solid rgb(120,120,120); border-top:8px solid rgb(255,255,255);border-bottom:8px solid #FFFFFF;\
                                                             border-top-left-radius:10; border-top-right-radius:10; color:#4D4D4D;}\
                                       QTabBar::tab:first{border-top-left-radius:10; border-left:0px solid rgb(120,120,120);}\
                                       QTabBar::tab:last{border-top-right-radius:10; border-right:0px solid rgb(120,120,120);}");

    const QString tabStyle_mutiTab = QString("QWidget{ background-color: rgb(255, 255, 255);}\
                                       QTabWidget{ border: 0px solid #FFFFFF; background-color:#FFFFFF; border-top: 0px solid #C2C7CB;\
                                                   border-bottom-left-radius:10px; border-bottom-right-radius:10px; }\
                                       QTabWidget::pane{ border: 5px solid #FFFFFF; background-color:#FFFFFF; border-top: 0px solid #C2C7CB;\
                                                         border-bottom-left-radius:10px; border-bottom-right-radius:10px; }\
                                       QTabWidget{border:1px solid rgb(100, 100, 100);border-radius:10; background-color:transparent;}\
                                       QTabBar{ background-color:transparent;}\
                                       QTabBar::tab{ width:169;height:24;border-top:8px solid rgb(220,220,220);font-family:HarmonyOS Sans;font-weight:bold;font-size:12pt;color:rgb(0, 0, 0);\
                                                                         border-bottom:8px solid qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgb(220, 220, 220), stop:1 rgb(200, 200, 200));color:#4D4D4D;}\
                                       QTabBar::tab:!selected{ background-color:rgb(220,220,220); color:rgb(60, 165, 250); border-left:1px solid rgb(120,120,120); }\
                                       QTabBar::tab:selected{background-color:rgb(255,255,255); border-right:1px solid rgb(120,120,120); border-left:1px solid rgb(120,120,120);\
                                                            border-top:8px solid rgb(255,255,255); border-bottom:8px solid #FFFFFF; color:#4D4D4D;}\
                                                            QTabBar::tab:first{border-top-left-radius:10; border-left:0px solid rgb(120,120,120);}\
                                                            QTabBar::tab:last{border-top-right-radius:10; border-right:0px solid rgb(120,120,120);}");

    const QString tabStyle = "QWidget{border:none;}"
                             "QTabWidget{border:none;border-radius:5;background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(205, 235, 255), stop:1 rgb(210, 180, 225));}"
                             "QTabWidget::pane{border-bottom-left-radius:5;border-bottom-right-radius:5;background-color: rgb(255, 255, 255);}"
                             "QTabBar{background-color:transparent;}"
                             "QTabBar::tab{width:180;height:40;border-right:2px solid rgb(220,220,220);font-family:HarmonyOS Sans;font-weight:bold;font-size:14pt;color:rgb(79, 79, 79);}"
                             "QTabBar::tab:first{border-top-left-radius:5;}"
                             "QTabBar::tab:hover{background-color:rgb(200,200,200);color:rgb(60, 165, 250);}"
                             "QTabBar::tab:selected{margin-left:-5;margin-right:-5;margin-top:0;width:190;border-right:none;background-color:rgb(255,255,255);color:qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(60, 165, 250), stop:1 rgb(182, 127, 202));}"
                             "QTabBar::tab:first:selected{margin-left:0;margin-right:-5;width:185;color:rgb(60, 165, 250);}"
                             "QTabBar::tab:last:selected{margin-left:-5;margin-right:-0;width:185;}"
                             "QTabBar::tab:!selected{border-right:2px solid rgb(200,200,200);}";
    const QString tabStyle1 ="QWidget{border:none;}"
                             "QTabWidget{border:none;border-radius:5;background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(205, 235, 255), stop:1 rgb(210, 180, 225));}"
                             "QTabWidget::pane{border-bottom-left-radius:5;border-bottom-right-radius:5;background-color: rgb(255, 255, 255);}"
                             "QTabBar::tab{width:180;height:40;border-right:2px solid rgb(220,220,220);font-family:HarmonyOS Sans;font-weight:bold;font-size:14pt;color:rgb(79, 79, 79);}"
                             "QTabBar::tab:first{border-top-left-radius:5;}"
                             "QTabBar::tab:hover{background-color:rgb(200,200,200);color:rgb(60, 165, 250);}"
                             "QTabBar::tab:selected{margin-left:-5;margin-right:-5;margin-top:0;width:190;border-right:none;background-color:rgb(255,255,255);color:qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(60, 165, 250), stop:1 rgb(182, 127, 202));}"
                             "QTabBar::tab:first:selected{margin-left:0;margin-right:-5;width:185;color:rgb(60, 165, 250);}"
                             "QTabBar::tab:last:selected{margin-left:-5;margin-right:-0;width:185;}"
                             "QTabBar::tab:!selected{border-right:2px solid rgb(200,200,200);}";
    const QString treeStyle ="QTreeView {show-decoration-selected:1; font-size:12pt; font-family:HarmonyOS Sans; font-weight:normal; alternate-background-color:rgb(255,255,255); background-color:rgb(243,244,250);}\
                              QTreeView::item {height:30px; border-top-color:transparent; border-bottom-color:transparent;}\
                              QTreeView::item:hover{background:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(204,232,255,180), stop:1 rgba(204,232,255,180)); border: 1px solid #bfcde4;}\
                              QTreeView::item:selected{ border:1px solid rgba(86,125,188,80);}\
                              QTreeView::item:selected:active{background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #cce8ff, stop: 1 #cce8ff);}\
                              QTreeView::item:selected:!active{background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #cce8ff, stop: 1 #cce8ff);}\
                              QTreeView::branch:has-siblings:!adjoins-item {border-image: url(:image/treeview/vline.png) 0;}\
                              QTreeView::branch:has-siblings:adjoins-item {border-image: url(:image/treeview/branch-more.png) 0; }\
                              QTreeView::branch:!has-children:!has-siblings:adjoins-item {border-image: url(:image/treeview/branch-end.png) 0;}\
                              QTreeView::branch:has-children:!has-siblings:closed,QTreeView::branch:closed:has-children:has-siblings{ border-image:none; image:url(:image/treeview/branch-closed.png); }\
                              QTreeView::branch:open:has-children:!has-siblings,QTreeView::branch:open:has-children:has-siblings{ border-image:none; image:url(:image/treeview/branch-open.png); }\
                              QTreeView::branch:hover{ background:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(204,232,255,180), stop:1 rgba(204,232,255,180));}\
                              QTreeView::branch:selected:!active{background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #cce8ff, stop: 1 #cce8ff); }\
                            QHeaderView::section {font-size:14pt;font-family:HarmonyOS Sans;font-weight:normal;height:25px;}";
    const QString fontStyle_bold_16 = "QWidget{font-family:HarmonyOS Sans;font-weight:bold;font-size:16pt;}";
    const QString fontStyle_bold_14 = "QWidget{font-family:HarmonyOS Sans;font-weight:bold;font-size:14pt;}";
    const QString fontStyle_bold_12 = "QWidget{font-family:HarmonyOS Sans;font-weight:bold;font-size:12pt;}";
    const QString fontStyle_normal_16 = "QWidget{font-family:HarmonyOS Sans;font-weight:normal;font-size:16pt;}";
    const QString fontStyle_normal_14 = "QWidget{font-family:HarmonyOS Sans;font-weight:normal;font-size:14pt;}";
    const QString fontStyle_normal_12 = "QWidget{font-family:HarmonyOS Sans;font-weight:normal;font-size:12pt;}";
    const QString fontStyle_export_16 = "{font-family:HarmonyOS Sans;font-weight:normal;font-size:16pt;}";
    const QString fontStyle_export_14 = "{font-family:HarmonyOS Sans;font-weight:normal;font-size:14pt;}";
    const QString fontStyle_export_12 = "{font-family:HarmonyOS Sans;font-weight:normal;font-size:12pt;}";
    const QString fontStyle_qlineEdit_normal_12 = "QLineEdit{font-family:HarmonyOS Sans;font-weight:normal;font-size:12pt;}";

    const QString PieState_unknow = "QLabel{background-color:rgb(200, 200, 200);}";
    const QString PieState_ok = "QLabel{background-color:rgb(0, 255, 127);}";
    const QString PieState_failed = "QLabel{background-color:rgb(255, 0, 0);}";
    const QString PieState_prepared = "QLabel{background-color:rgb(255, 255, 0);}";
    const QString PieState_exposure = "QLabel{background-color:rgb(0, 0, 255);}";

private:
    static StyleSheet *self;
    QFont font;
};

#endif // STYLESHEET_H
