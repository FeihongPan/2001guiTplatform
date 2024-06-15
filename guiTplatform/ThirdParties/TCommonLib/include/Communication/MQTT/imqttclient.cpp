#include "imqttclient.h"

IMqttClient::IMqttClient(const QString &name, QObject *parent)
    : ISubscriber(name, parent)
    , IPublish(name)
    , m_Timeout(10000)
    , m_TimerInterval(100)
{
    connect(&m_Timer, &QTimer::timeout, this, [ = ]
    {
        QStringList lst = m_dic_CommandTimeout.keys();
        for(int i = 0; i < lst.count(); ++i)
        {
            m_dic_CommandTimeout[lst[i]] += m_TimerInterval;

            if(m_dic_CommandTimeout[lst[i]] > this->m_Timeout)
            {
                m_dic_CommandBusy[lst[i]] = false;
                m_dic_CommandTimeout[lst[i]] = 0;
                emit sig_CommandTimeout(lst[i]);
            }
        }
    });
    m_Timer.start(m_TimerInterval);
}

void IMqttClient::SetCommandTimeout(uint timeout)
{
    this->m_Timeout = timeout;
}

void IMqttClient::conmmandSetInitialize(const QStringList &lst_CMD)
{
    for(int i = 0 ; i < lst_CMD.count(); ++i)
    {
        m_dic_CommandBusy.insert(lst_CMD[i], false);
        m_dic_CommandTimeout.insert(lst_CMD[i], 0);
    }
}

int IMqttClient::async_SendCommand(const QString &cmd, const QByteArray &msg)
{
    if(!m_dic_CommandBusy[cmd])
    {
        m_dic_CommandBusy[cmd] = true;
        m_dic_CommandTimeout[cmd] = 0;
        Publish(cmd, true, msg);
        return 0;
    }
    return 1;
}

void IMqttClient::decoding(const QString &topic, const QByteArray &message)
{
    TaskInfo recievedTask;
    recievedTask.fromJson(message);
    decoding(recievedTask.task, recievedTask.result, recievedTask.context, recievedTask.errMsg);
    m_dic_CommandBusy[recievedTask.task] = false;
}
