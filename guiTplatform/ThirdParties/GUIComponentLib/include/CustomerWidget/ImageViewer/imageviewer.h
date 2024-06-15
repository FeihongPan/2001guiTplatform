#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include "GUIComponentLib_global.h"

#include <QWidget>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QScrollBar>
#include <QLabel>
#include <QScrollArea>
#include <QMouseEvent>
namespace Ui {
class ImageViewer;
}

class GUICOMPONENTLIB_EXPORT ImageViewer : public QWidget
{
    Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent = nullptr);
    ~ImageViewer();

    void SetMaxCount(int count);
    void AddImage(QImage image);

protected:
     bool eventFilter(QObject *obj, QEvent *event) override;

private:
    void loadImage();
    void loadImages();
    void saveImage();
    void refreshLabel();
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);
    void zoomToFit();
    void rotate(double angle);

private:
    Ui::ImageViewer *ui;
    QLabel *imageLabel;
    QScrollArea *scrollArea;

    QString fileName;
    QStringList fileNames;

    QImage image;
    QList<QImage> lstImages;
    int imageCount_Max = 10;

    QPointF cursorPos;
    double scaleFactor;
    bool croppingState;
};

#endif // IMAGEVIEWER_H
