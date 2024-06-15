#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "CommonLib_global.h"

#include <QString>

class COMMONLIB_EXPORT Encryption
{
public:
    static QString DecodedText(const QString &data, const QString &key);
};

#endif // ENCRYPTION_H
