#ifndef MACHINECONSTANTSUBSCRIBER_H
#define MACHINECONSTANTSUBSCRIBER_H

#include "GUIFramework_global.h"
#include "Communication/MQTT/isubscriber.h"
#include "IMachineConstant/Data/machineconstant.h"
#include "BasicValue/serializablelist.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT MachineConstantSubscriber : public ISubscriber
{
    Q_OBJECT
public:
    explicit MachineConstantSubscriber(QString name, QObject *parent = nullptr);
    static MachineConstantSubscriber *getInstance();

signals:
    void sendNames(S_List_String constantNames);
    void sendInfo(const S_ConstantInfo &constant);
    void sendContent(const QByteArray &constant);
    void sendCurrentInfo(const S_ConstantInfo &data);
    void sendCurrentContent(const QByteArray &constant);
    void sendNew(const S_ConstantInfo &constant);

private slots:
    virtual void decoding(const QString &topic, const QByteArray &message) override;

private:
    static MachineConstantSubscriber *self;
};

#endif // MACHINECONSTANTSUBSCRIBER_H
