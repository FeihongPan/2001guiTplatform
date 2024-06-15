#ifndef TASK_H
#define TASK_H

#include "TCommonLib_global.h"
#include "Serializer/QSerializer"

class TCOMMONLIB_EXPORT TaskInfo : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(QString, task)
    QS_FIELD(bool, result)
    QS_FIELD(QByteArray, context)
    QS_FIELD(QByteArray, errMsg)

public:
    TaskInfo() {}

    TaskInfo(const TaskInfo &task)
    {
        this->task = task.task;
        this->result = task.result;
        this->context = task.context;
        this->errMsg = task.errMsg;
    }

    TaskInfo &operator=(const TaskInfo &task)
    {
        this->task = task.task;
        this->result = task.result;
        this->context = task.context;
        this->errMsg = task.errMsg;
        return *this;
    }
};

#endif // TASK_H
