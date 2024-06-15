#include "fileoperatormanager.h"

#include "FileSystem/ifileoperator.h"

#include <QMutex>

FileOperatorManager *FileOperatorManager::self = nullptr;

FileOperatorManager::FileOperatorManager(QObject *parent) : QObject(parent)
{

}

FileOperatorManager::~FileOperatorManager()
{

}

FileOperatorManager *FileOperatorManager::getInstance()
{
    if (self == nullptr)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if (self == nullptr)
        {
            self = new FileOperatorManager;
        }
    }
    return self;
}

bool FileOperatorManager::AddFileOperator(IFileOperator *fileOperator)
{
    if(!m_lst_FileOperators.contains(fileOperator))
    {
        m_lst_FileOperators.append(fileOperator);
        return true;
    }
    return false;
}

void FileOperatorManager::SaveCommandInfo()
{
    for(int i = 0; i < m_lst_FileOperators.count(); ++i)
    {
        m_lst_FileOperators[i]->SaveCommandInfo();
    }
}
