#ifndef AUTHORITYWDGINFO_H
#define AUTHORITYWDGINFO_H

#include "GUICommFuncLib_global.h"

#include "AuthorityManage/Data/userinfo.h"
#include "BasicValue/tvalue.h"

#include <QMap>

class GUICOMMFUNCLIB_EXPORT AuthorityWdgInfo : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(QString, wdgName)
    QS_COLLECTION(QList, AccessLevel::Level, accessLevels)
    QS_COLLECTION_OBJECTS(QList, AuthorityWdgInfo, subWidgets)

public:
    AuthorityWdgInfo();
};

#endif // AUTHORITYWDGINFO_H
