#ifndef TEMPLATELIBSUBSCRIBER_H
#define TEMPLATELIBSUBSCRIBER_H

#include "GUIFramework_global.h"
#include "Communication/MQTT/isubscriber.h"
#include "ITemplateLib/Data/templateinfo.h"
#include "ITemplateLib/Command/cmd_templatelib.h"
#include "BasicValue/serializablelist.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT TemplateLibSubscriber : public ISubscriber
{
    Q_OBJECT
public:

    explicit TemplateLibSubscriber(QString name, QObject *parent = nullptr);
    static TemplateLibSubscriber *getInstance();

signals:
    void sig_TemplateNames(S_List_String &templateNames);
    void sig_TemplateLib(QByteArray &content);
    void sig_NewTemplateLib(S_TemplateInfo &info);
    void sig_TemplateContent(QByteArray &content);
    //    void sig_OperateResult(CMD_Recipe::Command cmd, bool res);

private slots:
    virtual void decoding(const QString &topic, const QByteArray &message) override;

private:
    static TemplateLibSubscriber *self;
};

#endif // TEMPLATELIBSUBSCRIBER_H
