/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        ifileoperator.cpp
* Description:      文件处理接口类，提供文件读写操作
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-2-21
* Modify Record：
*       V1.0.1     2024-2-21     Feihong     增加异步方式写文件
***********************************************************************/

#include "ifileoperator.h"

#include <QDebug>

IFileOperator::IFileOperator(QString name)
{
    this->m_Name = name;
}

bool IFileOperator::WriteToFile(const QByteArray &msg)
{
    if(m_bCRCVerifyUsed)
    {
        return writeToFile_CRC(msg);
    }
    else
    {
        return writeToFile(msg);
    }
}

bool IFileOperator::WriteToFile(const QString &filePath, const QByteArray &msg)
{
    if(m_bCRCVerifyUsed)
    {
        return FileSystem::Write_CRC(filePath, msg);
    }
    else
    {
        return FileSystem::Write(filePath, msg);
    }
}

bool IFileOperator::WriteToFile(const QString &folderPath, const QString &fileName, const QByteArray &msg)
{
    if(m_bCRCVerifyUsed)
    {
        return FileSystem::Write_CRC(folderPath, fileName, msg);
    }
    else
    {
        return FileSystem::Write(folderPath, fileName, msg);
    }
}

void IFileOperator::AsyncWriteToFile(const QByteArray &ba)
{
    if(m_bCRCVerifyUsed)
    {
        FileSystem::AsyncWrite_CRC(m_FolderPath, m_FileName, ba);
    }
    else
    {
        FileSystem::AsyncWrite(m_FolderPath, m_FileName, ba);
    }
}

void IFileOperator::AsyncWriteToFile(const QString &strFilePath, const QByteArray &ba)
{
    if(m_bCRCVerifyUsed)
    {
        FileSystem::AsyncWrite_CRC(strFilePath, ba);
    }
    else
    {
        FileSystem::AsyncWrite(strFilePath, ba);
    }
}

void IFileOperator::AsyncWriteToFile(const QString &strFolderPath, const QString &strFileName, const QByteArray &ba)
{
    if(m_bCRCVerifyUsed)
    {
        FileSystem::AsyncWrite_CRC(strFolderPath, strFileName, ba);
    }
    else
    {
        FileSystem::AsyncWrite(strFolderPath, strFileName, ba);
    }
}

bool IFileOperator::ReadFromFile(QByteArray &msg)
{
    if(m_bCRCVerifyUsed)
    {
        return readFromFile_CRC(msg);
    }
    else
    {
        return readFromFile(msg);
    }
}

bool IFileOperator::ReadFromFile(const QString &filePath, QByteArray &msg)
{
    if(m_bCRCVerifyUsed)
    {
        return FileSystem::Read_CRC(filePath, msg);
    }
    else
    {
        return FileSystem::Read(filePath, msg);
    }
}

bool IFileOperator::ReadFromFile(const QString &folderPath, const QString &fileName, QByteArray &msg)
{
    if(m_bCRCVerifyUsed)
    {
        return FileSystem::Read_CRC(folderPath, fileName, msg);
    }
    else
    {
        return FileSystem::Read(folderPath, fileName, msg);
    }
}

bool IFileOperator::IsFolderEmpty()
{
    return FileSystem::GetAllFileNames(m_FolderPath).count() == 0;
}

bool IFileOperator::Backup()
{
    FileSystem::ClearDirectory(m_FolderPath_Backup);
    return FileSystem::CopyDirectory(m_FolderPath, m_FolderPath_Backup);
}

bool IFileOperator::writeCmdSampleToFile(const QString &name, const QByteArray &msg)
{
    return FileSystem::Write(m_FolderPath_CmdSample, name + ".json", msg);
}

bool IFileOperator::writeToFile(const QByteArray &msg)
{
    return FileSystem::Write(m_FolderPath, m_FileName, msg);
}

bool IFileOperator::writeToFile_CRC(const QByteArray &msg)
{
    return FileSystem::Write_CRC(m_FolderPath, m_FileName, msg);
}

bool IFileOperator::readFromFile(QByteArray &msg)
{
    return FileSystem::Read(m_FolderPath, m_FileName, msg);
}

bool IFileOperator::readFromFile_CRC(QByteArray &msg)
{
    return FileSystem::Read_CRC(m_FolderPath, m_FileName, msg);
}
