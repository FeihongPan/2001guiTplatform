/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        filesystem.cpp
* Description:      文件处理系统类，进行文件读写以及核验等操作
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-2-21
* Modify Record：
*       V1.0.1     2024-2-21     Feihong     增加异步方式写文件
***********************************************************************/

#include "filesystem.h"
#include "FileSystem/utils.h"

#include <QDir>
#include <QDebug>
#include <QFuture>
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>

#define CHECKSUM_AUX_LEN 12

bool FileSystem::Write(const QString &folderPath, const QString &fileName, const QByteArray &datas)
{
    QDir dir(folderPath);
    if(!dir.exists())
    {
        if(!dir.mkpath(folderPath))
        {
            return false;
        }
    }
    QString filePath = folderPath + "/" + fileName;
    return Write(filePath, datas);
}

bool FileSystem::Write(const QString &filePath, const QByteArray &datas)
{
    int idx = filePath.lastIndexOf('/');
    if (idx > 0)
    {
        auto folderPath = filePath.left(idx);
        QDir dir(folderPath);
        if(!dir.exists())
        {
            if(!dir.mkpath(folderPath))
            {
                return false;
            }
        }
    }

    QFile fp(filePath);
    if(fp.exists())
    {
        fp.remove();
    }

    if(fp.open(QIODevice::WriteOnly))
    {
        bool res = false;
        QFutureWatcher<bool> watcher;
        QEventLoop eventLoop;
        QObject::connect(&watcher, &QFutureWatcher<bool>::finished, &eventLoop, [&]
        {
            res = watcher.result();
            eventLoop.quit();
        });
        QFuture<bool> m_Future = QtConcurrent::run([&]()
        {
            fp.write(datas);
            fp.close();
            return true;
        });
        watcher.setFuture(m_Future);
        eventLoop.exec();
        return res;
    }
    return false;
}

bool FileSystem::Write_CRC(const QString &folderPath, const QString &fileName, const QByteArray &datas)
{
    return FileSystem::Write_CRC(folderPath + "/" + fileName, datas);
}

bool FileSystem::Write_CRC(const QString &filePath, QByteArray datas)
{
    FileSystem::AddChecksum(datas);
    return FileSystem::Write(filePath, datas);
}

void FileSystem::AsyncWrite_CRC(const QString &strFolderPath, const QString &strFileName, const QByteArray &ba)
{
    FileSystem::AsyncWrite_CRC(strFolderPath + "/" + strFileName, ba);
}

void FileSystem::AsyncWrite_CRC(const QString &strFilePath, QByteArray ba)
{
    FileSystem::AddChecksum(ba);
    return FileSystem::AsyncWrite(strFilePath, ba);
}

void FileSystem::AsyncWrite(const QString &strFolderPath, const QString &strFileName, const QByteArray &ba)
{
    AsyncWrite(strFolderPath + "/" + strFileName, ba);
}

void FileSystem::AsyncWrite(const QString &strFilePath, const QByteArray &ba)
{
    QtConcurrent::run([strFilePath, ba]()
    {
        int idx = strFilePath.lastIndexOf('/');
        if (idx > 0)
        {
            auto strFolderPath = strFilePath.left(idx);
            QDir dir(strFolderPath);
            if(!dir.exists())
            {
                if(!dir.mkpath(strFolderPath))
                {
                    return;
                }
            }
        }

        QFile fp(strFilePath);
        if(fp.exists())
        {
            fp.remove();
        }

        if(fp.open(QIODevice::WriteOnly))
        {
            fp.write(ba);
            fp.close();
        }
    });
}

bool FileSystem::Read(const QString &folderPath, const QString &fileName, QByteArray &datas)
{
    return FileSystem::Read(folderPath + "/" + fileName, datas);
}

bool FileSystem::Read(const QString &filePath, QByteArray &datas)
{
    QFile fp(filePath);

    if (fp.exists() == false)
    {
        return false;
    }

    if(fp.open(QIODevice::ReadOnly))
    {
        datas = fp.readAll();
        fp.close();
        return true;
    }
    return false;
}

bool FileSystem::Read_CRC(const QString &folderPath, const QString &fileName, QByteArray &datas)
{
    return FileSystem::Read_CRC(folderPath + "/" + fileName, datas);
}

bool FileSystem::Read_CRC(const QString &filePath, QByteArray &datas)
{
    if(FileSystem::Read(filePath, datas) && FileSystem::Checksum(datas))
    {
        //        FileSystem::RemoveChecksum(datas);
        return true;
    }
    return false;
}

QStringList FileSystem::GetAllFileNames(const QString &folderPath, const QStringList &filter)
{
    QStringList result;
    if(folderPath.isEmpty())
    {
        return result;
    }

    QDir dir(folderPath);
    dir.setNameFilters(filter);
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::Size | QDir::Reversed);

    QFileInfoList list = dir.entryInfoList();
    for(int i = 0; i < list.count(); i++)
    {
        result.append(list.at(i).fileName());
    }
    return result;
}

QStringList FileSystem::GetAllFolderNames(const QString &folderPath, const QStringList &filter)
{
    QStringList result;
    if(folderPath.isEmpty())
    {
        return result;
    }

    QDir dir(folderPath);
    dir.setNameFilters(filter);
    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::DirsFirst);

    QFileInfoList list = dir.entryInfoList();
    for(int i = 0; i < list.count(); i++)
    {
        QStringList data = list.at(i).fileName().split("/");
        if(data.size() > 0 && !data.last().isEmpty())
        {
            result.append(data);
        }
    }
    return result;
}

bool FileSystem::FileExist(const QString &folderPath, const QString &fileName, const QStringList &filter)
{
    QStringList lst_Names = GetAllFileNames(folderPath, filter);
    return lst_Names.contains(fileName);
}

void FileSystem::ClearDirectory(const QString &path)
{
    QDir dir(path);
    QFileInfoList fileList = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

    for (int i = 0; i < fileList.count(); i++)
    {
        QFileInfo fileInfo = fileList.at(i);
        if (fileInfo.isDir())
        {
            // 递归清空子目录
            ClearDirectory(fileInfo.filePath());
            // 删除子目录
            dir.rmdir(fileInfo.absoluteFilePath());
        }
        else
        {
            // 删除文件
            dir.remove(fileInfo.absoluteFilePath());
        }
    }
}

bool FileSystem::CopyDirectory(const QString &srcPath, const QString &destPath)
{
    QDir sourceDir(srcPath);
    QDir destDir(destPath);

    if (!sourceDir.exists())
    {
        qDebug() << "Source directory does not exist.";
        return false;
    }

    if (!destDir.exists())
    {
        if (!destDir.mkpath(destPath))
        {
            qDebug() << "Failed to create destination directory.";
            return false;
        }
    }

    QFileInfoList fileList = sourceDir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs | QDir::Hidden | QDir::System);
    foreach (const QFileInfo &fileInfo, fileList)
    {
        QString fileName = fileInfo.fileName();
        QString srcFilePath = srcPath + QDir::separator() + fileName;
        QString destFilePath = destPath + QDir::separator() + fileName;

        if (fileInfo.isDir())
        {
            if (!CopyDirectory(srcFilePath, destFilePath))
            {
                return false;
            }
        }
        else if (fileInfo.isFile())
        {
            if (!QFile::copy(srcFilePath, destFilePath))
            {
                qDebug() << "Failed to copy file: " << srcFilePath;
                return false;
            }
        }
    }
    return true;
}

bool FileSystem::Remove(const QString &filePath)
{
    if (QFile::exists(filePath) == false)
    {
        return false;
    }

    QFile::remove(filePath);
    return true;
}

bool FileSystem::Remove(const QString &folderPath, const QString &fileName)
{
    return Remove(folderPath + "/" + fileName);
}

bool FileSystem::Rename(const QString &filePath, const QString &newName)
{
    QFile fp(filePath);

    if (fp.exists() == false)
    {
        return false;
    }

    return fp.rename(newName);
}

bool FileSystem::Copy(const QString &filePath, const QString &newPath)
{
    if (QFile::exists(filePath) == false)
    {
        return false;
    }

    if (QFile::exists(newPath) == false)
    {
        QFile::remove(newPath);
    }

    return QFile::copy(filePath, newPath);
}

QString FileSystem::Backup(const QString &filePath)
{
    if (QFile::exists(filePath) == false)
    {
        return QString();
    }

    QFileInfo info(filePath);
    QString path = info.path();
    QString name = QString("%1(copy).%2").arg(info.baseName()).arg(info.suffix());
    QString newPath = path + "/" + name;
    if (QFile::copy(filePath, newPath) == true)
    {
        return name;
    }

    return QString();
}

bool FileSystem::Move(const QString &filePath, const QString &path)
{
    if (QFile::exists(filePath) == false)
    {
        return false;
    }

    QFileInfo info(filePath);
    QString newPath = path + "/" + info.fileName();
    return QFile::rename(filePath, newPath);
}

bool FileSystem::FolderEmpty(const QString &dirPath)
{
    QDir dir(dirPath);
    if (dir.exists() == false)
    {
        return false;
    }

    QStringList files = Retrieve(dirPath);

    for (int i = 0; i < files.length(); i++)
    {
        QString fileName = dirPath + "/" + files[i];

        Remove(fileName);
    }

    return true;
}

bool FileSystem::CopyFolder(const QString &sourcePath, const QString &targetPath)
{
    QDir dir(sourcePath);
    if (dir.exists() == false)
    {
        return false;
    }

    QDir target(targetPath);
    if (target.exists() == false)
    {
        dir.mkpath(targetPath);
    }

    QStringList files = Retrieve(sourcePath);

    for (int i = 0; i < files.length(); i++)
    {
        QString fileName = sourcePath + "/" + files[i];
        QString newPath = targetPath + "/" + files[i];

        Copy(fileName, newPath);
    }

    return true;
}

QStringList FileSystem::Retrieve(const QString &dirPath, const QString &suffix)
{
    QDir dir(dirPath);
    QStringList files;

    if (dir.exists() == false)
    {
        qDebug("The folder path is incorrect");
        return files;
    }

    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    QFileInfoList list = dir.entryInfoList();

    int fileCnt = list.count();
    if(fileCnt <= 0)
    {
        return files;
    }

    for(int i = 0; i < fileCnt; i++)
    {
        QFileInfo info = list.at(i);

        if (suffix.isEmpty() == true)
        {
            files.append(info.fileName());
        }
        else
        {
            if(QString::compare(info.suffix(), suffix, Qt::CaseInsensitive) == 0)
            {
                files.append(info.fileName());
            }
        }
    }

    return files;
}

bool FileSystem::Validity(const QString &fileName)
{
    QByteArray datas;

    if (Read(fileName, datas) == false)
    {
        return false;
    }

    if (datas.isEmpty() == true)
    {
        return false;
    }

    if (datas.length() <= CHECKSUM_AUX_LEN)
    {
        return false;
    }

    QByteArray aux = datas.right(CHECKSUM_AUX_LEN);
    if (aux.indexOf("CRC") < 0)
    {
        return false;
    }

    return true;
}

bool FileSystem::Checksum(QByteArray &datas)
{
    QByteArray aux = datas.right(CHECKSUM_AUX_LEN);
    QByteArray crc = aux.mid(7, 4);
    uint16_t checksum1 = Utils::toHex(crc);

    datas = datas.left(datas.length() - CHECKSUM_AUX_LEN);
    uint16_t checksum2 = Utils::getCrc(datas);

    return (checksum1 == checksum2) ? true : false;
}

uint16_t FileSystem::AddChecksum(QByteArray &datas)
{
    uint16_t checksum = Utils::getCrc(datas);
    QString crc = QString("{\"CRC\":%1}").arg(checksum, 4, 16, QLatin1Char('0'));

    datas.append(crc);
    return checksum;
}

void FileSystem::RemoveChecksum(QByteArray &datas)
{
    datas = datas.left(datas.length() - CHECKSUM_AUX_LEN);
}

QString FileSystem::GetBaseName(const QString &fileName)
{
    return fileName.split(".")[0];
}

QString FileSystem::GetFileName(const QString &filePath)
{
    QFileInfo info(filePath);
    return info.fileName();
}
