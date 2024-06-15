#include "imageviewer.h"
#include "ui_imageviewer.h"
#include <QtConcurrent/QtConcurrent>
#include <QTransform>
#include <QDebug>
ImageViewer::ImageViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageViewer)
{
    ui->setupUi(this);

    imageLabel = new QLabel;
    imageLabel->setText("dasdadas");
    imageLabel->resize(0, 0);
    imageLabel->setMouseTracking(true);
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
    imageLabel->installEventFilter(this);

    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    scrollArea->setAlignment(Qt::AlignCenter);

    ui->verticalLayout->addWidget(scrollArea);

    connect(ui->btn_LoadImage, &QPushButton::clicked, this, &ImageViewer::loadImage);
    connect(ui->btn_LoadImages, &QPushButton::clicked, this, &ImageViewer::loadImages);
    connect(ui->btn_SaveImage, &QPushButton::clicked, this, &ImageViewer::saveImage);
    connect(ui->btn_ZoomOut, &QPushButton::clicked, this, [=]{ scaleImage(0.80);});
    connect(ui->btn_ZoomIn, &QPushButton::clicked, this, [=]{ scaleImage(1.25);});
    connect(ui->btn_ZoomToFit, &QPushButton::clicked, this, &ImageViewer::zoomToFit);
    connect(ui->btn_RotateAnticlockwise, &QPushButton::clicked, this, [=]{rotate(-90);});
    connect(ui->btn_RotateClockwise, &QPushButton::clicked, this, [=]{rotate(90);});
//    connect(ui->spb_RotateAngle, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, [=](double value){rotate(value);});
    connect(ui->spinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, [=](int value){
        if(lstImages.count() > 0)
        {
            if(value > lstImages.count())
            {
                value = 1;
                ui->spinBox->setValue(value);
            }

            image = lstImages[value - 1];
            refreshLabel();
            imageLabel->adjustSize();
            zoomToFit();
        }
    });
}

ImageViewer::~ImageViewer()
{
    delete ui;
}

void ImageViewer::SetMaxCount(int count)
{
    if(count >= 1)
    {
        this->imageCount_Max = count;
    }
}

void ImageViewer::AddImage(QImage image)
{
//    if()
}

bool ImageViewer::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == imageLabel)
    {
        switch (event->type())
        {
            case QEvent::MouseMove:
            {
                const QMouseEvent* const me = static_cast<const QMouseEvent*>(event);
                const QPoint position = me->pos();
                ui->lbl_Pix_X->setText(QString::number((int)(position.x() / scaleFactor)));
                ui->lbl_Pix_Y->setText(QString::number((int)(position.y() / scaleFactor)));
                break;
            }

            case QEvent::Wheel:
            {
                const QWheelEvent* const we = static_cast<const QWheelEvent*>(event);

                if(we->delta() > 0)
                {
                    scaleImage(1.25);
                }
                else
                {
                    scaleImage(0.8);
                }
                break;
            }

            case QEvent::MouseButtonPress:
            {
                const QMouseEvent* const me = static_cast<const QMouseEvent*>(event);
                const QPoint position = me->pos();
                cursorPos.setX(position.x() / scaleFactor);
                cursorPos.setY(position.y() / scaleFactor);

                qDebug() << "QEvent::MouseButtonPress" << cursorPos.x() << cursorPos.y();
                break;
            }

            default:
                break;
        }
    }
    return false;
}

void ImageViewer::loadImage()
{
    QString lastFileName = fileName.isEmpty() ? QDir::currentPath() : fileName;
    fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open File"),
                                            lastFileName);

    if (!fileName.isEmpty()) {
        lstImages.clear();
        image = QImage(fileName);
        if (image.isNull()) {
         QMessageBox::information(this,
                                  tr("Image Viewer"),
                                  tr("Cannot load %1.").arg(fileName));

         return;
        }

        lstImages.append(image);
        scaleFactor = 1.0;
        croppingState = false;
        setCursor(Qt::ArrowCursor);

        refreshLabel();

        imageLabel->adjustSize();
//        zoomToFit();
        ui->spinBox->setValue(1);
        ui->lbl_ImageTotalCount->setText(QString::number(lstImages.count()));
    }
}

void ImageViewer::loadImages()
{
    QString lastFileName = fileName.isEmpty() ? QDir::currentPath() : fileName;
    fileNames = QFileDialog::getOpenFileNames(this,
                                             tr("Open File"),
                                             lastFileName);

    if(fileNames.count() > 0)
    {
        lstImages.clear();
        for(int i = 0; i < fileNames.count(); i++)
        {
            if(i >= imageCount_Max)
            {
                break;
            }
            fileName = fileNames[i];
            QImage img = QImage(fileName);
            if (img.isNull()) {
             QMessageBox::information(this,
                                      tr("Image Viewer"),
                                      tr("Cannot load %1.").arg(fileName));

             return;
            }
            lstImages.append(img);
        }


        image = lstImages.first();
        scaleFactor = 1.0;
        croppingState = false;
        setCursor(Qt::ArrowCursor);

        refreshLabel();

        imageLabel->adjustSize();
//        zoomToFit();
        ui->spinBox->setValue(1);
        ui->lbl_ImageTotalCount->setText(QString::number(lstImages.count()));
    }
}

void ImageViewer::saveImage()
{
    QString imagePath = QFileDialog::getSaveFileName(this,
                                                     tr("Save File"),
                                                     "",
                                                     tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));

    image.save(imagePath);
}

void ImageViewer::refreshLabel()
{ 
    imageLabel->setPixmap(QPixmap::fromImage(image));
}

void ImageViewer::scaleImage(double factor)
{
    if(scaleFactor * factor > 0.1 && scaleFactor * factor < 5)
    {
        scaleFactor *= factor;
        imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());
        adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
        adjustScrollBar(scrollArea->verticalScrollBar(), factor);
    }
}

void ImageViewer::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    int newValue = factor * scrollBar->value() + (factor - 1) * scrollBar->pageStep() / 2;
    scrollBar->setValue(newValue);
}

void ImageViewer::zoomToFit()
{
    QSize windowSize = scrollArea->size();
    QSize labelSize = imageLabel->pixmap()->size();
    double imageRatio = double(labelSize.height()) / labelSize.width();
    double scaleTo;

    if (windowSize.width() * imageRatio > windowSize.height())
    {
        scaleTo = double(windowSize.height()) / labelSize.height();
    }
    else
    {
        scaleTo = double(windowSize.width()) / labelSize.width();
    }

    double scaleBy = scaleTo / scaleFactor;
    scaleImage(scaleBy);
}

void ImageViewer::rotate(double angle)
{
    QMatrix rm;
    rm.rotate(angle);
    image = image.transformed(rm);

    refreshLabel();

    imageLabel->adjustSize();
    scaleImage(1);
}

