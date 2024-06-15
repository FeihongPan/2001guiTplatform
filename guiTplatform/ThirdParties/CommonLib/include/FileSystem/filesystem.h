/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        filesystem.h
* Description:      文件处理系统类，进行文件读写以及核验等操作
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-2-21
* Modify Record：
*       V1.0.1     2024-2-21     Feihong     增加异步方式写文件
***********************************************************************/

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "CommonLib_global.h"

#include <QFileInfo>

class COMMONLIB_EXPORT FileSystem
{
public:
    static bool Write(const QString &folderPath, const QString &fileName, const QByteArray &datas);
    static bool Write(const QString &filePath, const QByteArray &datas);
    static bool Write_CRC(const QString &folderPath, const QString &fileName, const QByteArray &datas);
    static bool Write_CRC(const QString &filePath, QByteArray datas);

    /// <summary>
    /// 异步方式写文件
    /// </summary>
    /// <param name="strFolderPath">文件夹地址</param>
    /// <param name="strFileName">文件名</param>
    /// <param name="ba">待写入的数据</param>
    static void AsyncWrite_CRC(const QString &strFolderPath, const QString &strFileName, const QByteArray &ba);

    /// <summary>
    /// 异步方式写文件
    /// </summary>
    /// <param name="strFilePath">文件地址</param>
    /// <param name="ba">待写入的数据</param>
    static void AsyncWrite_CRC(const QString &strFilePath, QByteArray ba);

    /// <summary>
    /// 异步方式写文件
    /// </summary>
    /// <param name="strFolderPath">文件夹地址</param>
    /// <param name="strFileName">文件名</param>
    /// <param name="ba">待写入的数据</param>
    static void AsyncWrite(const QString &strFolderPath, const QString &strFileName, const QByteArray &ba);

    /// <summary>
    /// 异步方式写文件
    /// </summary>
    /// <param name="strFilePath">文件地址</param>
    /// <param name="ba">待写入的数据</param>
    static void AsyncWrite(const QString &strFilePath, const QByteArray &ba);

    static bool Read(const QString &folderPath, const QString &fileName, QByteArray &datas);
    static bool Read(const QString &filePath, QByteArray &datas);
    static bool Read_CRC(const QString &folderPath, const QString &fileName, QByteArray &datas);
    static bool Read_CRC(const QString &filePath, QByteArray &datas);

    /// <summary>
    /// 获取指定目录下所有符合过滤条件的文件名
    /// </summary>
    /// <param name="folderPath">文件夹路径</param>
    /// <param name="filter">过滤条件</param>
    /// <returns>填写返回值的说明</returns>
    static QStringList GetAllFileNames(const QString &folderPath, const QStringList &filter = {});

    /// <summary>
    /// 获取指定目录下所有符合过滤条件的文件夹名
    /// </summary>
    /// <param name="folderPath">文件夹路径</param>
    /// <param name="filter">过滤条件</param>
    /// <returns>填写返回值的说明</returns>
    static QStringList GetAllFolderNames(const QString &folderPath, const QStringList &filter = {});

    /// <summary>
    /// 检查指定目录下是否存在符合过滤条件的文件
    /// </summary>
    /// <param name="folderPath">填写参数a的说明</param>
    /// <param name="fileName">填写参数b的说明</param>
    /// <param name="filter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static bool FileExist(const QString &folderPath, const QString &fileName, const QStringList &filter = {});

    /// <summary>
    /// 清空指定目录下的所有文件和文件夹
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static void ClearDirectory(const QString &path);

    /// <summary>
    /// 复制一个目录及其内容到目标目录
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static bool CopyDirectory(const QString &srcPath, const QString &destPath);

    /// <summary>
    /// 删除指定路径的文件
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static bool Remove(const QString &filePath);

    /// <summary>
    /// 删除指定目录下的指定文件
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static bool Remove(const QString &folderPath, const QString &fileName);

    /// <summary>
    /// 重命名指定文件名
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static bool Rename(const QString &filePath, const QString &newName);

    /// <summary>
    /// 将文件复制到新的路径
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static bool Copy(const QString &fileName, const QString &newPath);

    /// <summary>
    /// 备份文件
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static QString Backup(const QString &fileName);

    /// <summary>
    /// 将文件移动到新的路径
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static bool Move(const QString &fileName, const QString &path);

    /// <summary>
    /// 检查指定目录是否为空
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static bool FolderEmpty(const QString &dirPath);

    /// <summary>
    /// 复制一个目录及其内容到目标目录
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static bool CopyFolder(const QString &sourcePath, const QString &targetPath);

    /// <summary>
    /// 返回指定目录中符合后缀条件的所有文件名
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static QStringList Retrieve(const QString &dirPath, const QString &suffix = QString());

    /// <summary>
    /// 检查文件的有效性
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static bool Validity(const QString &fileName);

    /// <summary>
    /// 验证文件的校验和
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static bool Checksum(QByteArray &datas);

    /// <summary>
    /// 添加文件的校验和
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static uint16_t AddChecksum(QByteArray &datas);

    /// <summary>
    /// 移除文件的校验和
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static void RemoveChecksum(QByteArray &datas);

    /// <summary>
    /// 获取文件名的基本名称，即去除文件扩展名的部分
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static QString GetBaseName(const QString &fileName);

    /// <summary>
    /// 获取文件路径中的文件名部分
    /// </summary>
    /// <param name="parameter">填写参数a的说明</param>
    /// <param name="parameter">填写参数b的说明</param>
    /// <returns>填写返回值的说明</returns>
    static QString GetFileName(const QString &filePath);
};

#endif
