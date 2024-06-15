#include "mainwindow.h"
#include "startmanager.h"
#include "Language/language.h"
#include "CustomerWidget/Dialog/messagedialog.h"

#include <QDebug>
#include <QObject>
#include <QLocale>
#include <QApplication>
#include <QSharedMemory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLocale::setDefault(QLocale::English);

    // check only 1 program can be constructed
    QSharedMemory mem("guiPlatform");
    bool b = mem.create(1);
    if (!b)
    {
        MessageDialog dlg(MessageDialog::Error, nullptr, Tr("E_An instance has already been running."));
        dlg.exec();
        return -1;
    }

    StartManager::getInstance()->SetDefaultSubscribePrefix("MC");
    StartManager::getInstance()->SetPublishTopicPrefix("GUI");

    QObject::connect(StartManager::getInstance(), &StartManager::sig_LicenseFail, &a, &QApplication::quit);
    if(StartManager::getInstance()->Start())
    {
        MainWindow w;
        QObject::connect(&w, &MainWindow::Closing, StartManager::getInstance(), &StartManager::Terminate);
        QObject::connect(StartManager::getInstance(), &StartManager::sig_Terminated, &w, &MainWindow::CloseProgram);
        w.show();
        return a.exec();
    }
}
