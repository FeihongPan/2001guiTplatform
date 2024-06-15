/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        ifileoperator.h
* Description:      文件处理接口类，提供文件读写操作
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-2-21
* Modify Record：
*       V1.0.1     2024-2-21     Feihong     增加异步方式写文件
***********************************************************************/

#ifndef IFILEOPERATOR_H
#define IFILEOPERATOR_H

#include "CommonLib_global.h"
#include "FileSystem/filesystem.h"

#include <QString>

class COMMONLIB_EXPORT IFileOperator
{
public:
    IFileOperator(QString name);

    inline const QString &GetName();

    inline void SetFolderPath(const QString &folderPath);

    inline void SetFileName(const QString &fileName);

    inline void SetFolderPath_CmdSample(const QString &folderPath);

    /// 设置通过该基类执行文件读写操作时是否需要CRC校验
    inline void SetCRCVerifyUsed(bool used);

    /// folderPath文件夹路径
    /// folderPath_Backup备份文件夹路径
    /// fileName 仅针对该类只操作一个文件的场景下使用
    /// cmdPath mqtt指令保存的文件路径
    inline void SetPath(const QString &folderPath, const QString &folderPath_Backup, const QString &fileName, const QString &cmdPath);

    /// 将文件写入SetPath()方法设置的folderPath文件夹下，文件名为fileName
    bool WriteToFile(const QByteArray &msg);

    /// 将文件写入文件夹下，文件名为SetPath()方法设置的fileName
    bool WriteToFile(const QString &filePath, const QByteArray &msg);

    /// folderPath文件夹路径
    /// fileName 文件名
    /// msg 文件信息
    bool WriteToFile(const QString &folderPath, const QString &fileName, const QByteArray &msg);

    /// <summary>
    /// 异步方式写文件
    /// </summary>
    /// <param name="ba">待写入的数据</param>
    void AsyncWriteToFile(const QByteArray &ba);

    /// <summary>
    /// 异步方式写文件
    /// </summary>
    /// <param name="strFilePath">文件地址</param>
    /// <param name="ba">待写入的数据</param>
    void AsyncWriteToFile(const QString &strFilePath, const QByteArray &ba);

    /// <summary>
    /// 异步方式写文件
    /// </summary>
    /// <param name="strFolderPath">文件夹地址</param>
    /// <param name="strFileName">文件名</param>
    /// <param name="ba">待写入的数据</param>
    void AsyncWriteToFile(const QString &strFolderPath, const QString &strFileName, const QByteArray &ba);

    /// 读取在SetPath()方法设置的folderPath文件夹下，文件名为fileName的文件
    bool ReadFromFile(QByteArray &msg);

    /// 读取在filePath文件夹下，SetPath()方法设置的文件名为fileName的文件
    bool ReadFromFile(const QString &filePath, QByteArray &msg);

    /// folderPath文件夹路径
    /// fileName 文件名
    /// msg 文件信息
    bool ReadFromFile(const QString &folderPath, const QString &fileName, QByteArray &msg);

    bool IsFolderEmpty();

    bool Backup();

    virtual void SaveCommandInfo() {};

protected:
    bool writeCmdSampleToFile(const QString &name, const QByteArray &msg);

private:
    bool writeToFile(const QByteArray &msg);
    bool writeToFile_CRC(const QByteArray &msg);

    bool readFromFile(QByteArray &msg);
    bool readFromFile_CRC(QByteArray &msg);

protected:
    QString m_Name;
    QString m_FolderPath;
    QString m_FileName;
    QString m_FolderPath_CmdSample;
    QString m_FolderPath_Backup;
    bool m_bCRCVerifyUsed = false;
};

inline const QString &IFileOperator::GetName()
{
    return this->m_Name;
}

inline void IFileOperator::SetCRCVerifyUsed(bool used)
{
    this->m_bCRCVerifyUsed = used;
}

inline void IFileOperator::SetFolderPath(const QString &folderPath)
{
    this->m_FolderPath = folderPath;
}

inline void IFileOperator::SetFileName(const QString &fileName)
{
    this->m_FileName = fileName;
}

inline void IFileOperator::SetFolderPath_CmdSample(const QString &folderPath)
{
    this->m_FolderPath_CmdSample = folderPath;
}

inline void IFileOperator::SetPath(const QString &folderPath, const QString &folderPath_Backup, const QString &fileName, const QString &cmdPath)
{
    this->m_FolderPath = folderPath;
    this->m_FileName = fileName;
    this->m_FolderPath_CmdSample = cmdPath;
    this->m_FolderPath_Backup = folderPath_Backup;
}

#endif // IFILEOPERATOR_H
