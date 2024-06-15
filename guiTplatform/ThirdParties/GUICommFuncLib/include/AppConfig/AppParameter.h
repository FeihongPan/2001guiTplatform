#ifndef APPPARAMETER_H
#define APPPARAMETER_H
#include <QString>

#if defined (WIN32)
static QString DataPath = "C:/App_Data/";
#else
static QString DataPath = "/home/istar/App_Data/";
#endif

static QString PublishTopicPrefix = "GUI";

#endif // APPPARAMETER_H
