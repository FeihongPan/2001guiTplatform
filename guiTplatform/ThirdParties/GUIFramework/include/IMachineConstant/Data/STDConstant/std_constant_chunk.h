#ifndef STD_CONSTANT_CHUNK_H
#define STD_CONSTANT_CHUNK_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

class SR_STD_Constant_Chunk;

class GUIFRAMEWORK_EXPORT S_STD_Constant_Chunk : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, vacThreshold)
    QS_FIELD(int, vacTimeout)

public:
    S_STD_Constant_Chunk();
    S_STD_Constant_Chunk(const S_STD_Constant_Chunk &chunk);
    S_STD_Constant_Chunk(const SR_STD_Constant_Chunk &chunk);
    S_STD_Constant_Chunk &operator=(const S_STD_Constant_Chunk &chunk);
    S_STD_Constant_Chunk &operator=(const SR_STD_Constant_Chunk &chunk);
};

class GUIFRAMEWORK_EXPORT SR_STD_Constant_Chunk : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TDouble, vacThreshold)
    QS_OBJECT(TInt, vacTimeout)

public:
    SR_STD_Constant_Chunk();
    SR_STD_Constant_Chunk(const SR_STD_Constant_Chunk &chunk);
    SR_STD_Constant_Chunk(const S_STD_Constant_Chunk &chunk);
    SR_STD_Constant_Chunk &operator=(const SR_STD_Constant_Chunk &chunk);
    SR_STD_Constant_Chunk &operator=(const S_STD_Constant_Chunk &chunk);
};

#endif // STD_CONSTANT_CHUNK_H
