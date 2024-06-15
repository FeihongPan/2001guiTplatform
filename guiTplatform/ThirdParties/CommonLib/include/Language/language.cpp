#include "language.h"

#include "FileSystem/filesystem.h"
#include "Converter/enumconverter.h"

#include <QFile>
#include <QMutex>
#include <QTextStream>

Language *Language::self = nullptr;

Language::Language(QObject *parent): QObject(parent)
{

}

Language::~Language()
{

}

Language *Language::getInstance()
{
    if(self == nullptr)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == nullptr)
        {
            self = new Language;
        }
    }
    return self;
}

bool Language::Initialize()
{
    if(!m_bInitialized)
    {
        lstLanguage.clear();
        dicLanguage.clear();
        QFile file(m_FolderPath + "/Language/Language.csv");
        QStringList lines;
        if(file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            while (!stream.atEnd())
            {
                lines.push_back(stream.readLine());
            }

            for(int i = 0; i < lines.count(); i++)
            {
                QString line = lines.at(i);
                QStringList split = line.split(",");
                lstLanguage.append(split.at(0));
                dicLanguage.insert(split.takeAt(0), split);
            }
            file.close();
            m_bInitialized = true;
        }
    }
    return m_bInitialized;
}

bool Language::Initialize(const QString &folderPath)
{
    if(m_FolderPath != folderPath)
    {
        m_FolderPath = folderPath;
        m_bInitialized = false;
    }
    return Initialize();
}

void Language::SetFilePath(const QString &folderPath)
{
    this->m_FolderPath = folderPath;
}

bool Language::SaveToFile()
{
    QFile file(m_FolderPath + "/Language/Language_Untranslated.csv");
    QByteArray datas;
    lstUnTranslated.sort();
    for(int i = 0; i < lstUnTranslated.count(); i++)
    {
        datas += lstUnTranslated.at(i) + ",";
        for(int j = 1; j < EnumConverter::ConvertToStringList<LanguageType>().count(); j++)
        {
            datas += ",";
        }
        datas += "\n";
    }
    return FileSystem::Write(m_FolderPath + "/Language", "Language_Untranslated.csv", datas);
}

void Language::SetLanguageType(LanguageType type)
{
    this->languageType = type;
}

QString Language::Translate(const QString &msg)
{
    if(msg != QString())
    {
        if(lstLanguage.indexOf(msg) != -1)
        {
            if(languageType < dicLanguage[msg].count())
            {
                QString str = dicLanguage[msg].at(languageType);
                if(str == QString())
                {
                    str = msg;
                }
                return str;
            }
            return msg;
        }
        else
        {
            if(lstUnTranslated.indexOf(msg) == -1)
            {
                lstUnTranslated.append(msg);
            }
            return msg;
        }
    }
    else
    {
        return msg;
    }
}

QStringList Language::Translate(const QStringList &msg)
{
    QStringList result;
    for(int i = 0; i < msg.count(); i++)
    {
        result.append(Translate(msg.at(i)));
    }
    return result;
}

