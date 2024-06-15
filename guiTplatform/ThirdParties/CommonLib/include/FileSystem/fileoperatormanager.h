#ifndef FILEOPERATORMANAGER_H
#define FILEOPERATORMANAGER_H

#include "CommonLib_global.h"

#include <QObject>

class IFileOperator;

class COMMONLIB_EXPORT FileOperatorManager : public QObject
{
    Q_OBJECT

public:
    ~FileOperatorManager();

    static FileOperatorManager *getInstance();

    bool AddFileOperator(IFileOperator *fileOperator);

    void SaveCommandInfo();

private:
    FileOperatorManager(QObject *parent = nullptr);
    FileOperatorManager(const FileOperatorManager &) = delete;
    FileOperatorManager &operator=(const FileOperatorManager &) = delete;

private:
    static FileOperatorManager *self;
    QList<IFileOperator *> m_lst_FileOperators;
};

#endif // FILEOPERATORMANAGER_H
