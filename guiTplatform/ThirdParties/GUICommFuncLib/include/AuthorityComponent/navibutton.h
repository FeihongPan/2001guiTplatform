#ifndef NAVIBUTTON_H
#define NAVIBUTTON_H

#include "GUICommFuncLib_global.h"
#include "CustomerWidget/Button/iconbutton.h"
#include "viewstatus.h"
#include "synctimer.h"

#include <QObject>
#include <QTimer>
#include <QMap>

class GUICOMMFUNCLIB_EXPORT NaviButton : public IconButton
{
    Q_OBJECT

public:
    explicit NaviButton(QWidget *parent = nullptr);
    ~NaviButton();

    bool event(QEvent *e) override;

signals:
    void SendViewStatus(ViewStatus::Status status);

public slots:
    void RecivedViewStatus(ViewStatus::Status status);

protected:
    virtual void setColor_Toggled(bool r) override;
    virtual void setColor_Pressed() override;
    virtual void setColor_Released() override;

public slots:
    void showStatus();

private:
    SyncTimer *timer;
    ViewStatus::Status status;
    bool bTwinkleOn = false;
    QString twinkleColor;
    QMap<ViewStatus::Status, QString> dicTwinklwColor;
};

#endif // NAVIBUTTON_H
