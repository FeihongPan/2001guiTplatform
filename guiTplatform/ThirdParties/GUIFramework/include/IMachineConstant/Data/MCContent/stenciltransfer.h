#ifndef STENCILTRANSFER_H
#define STENCILTRANSFER_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "BasicValue/point.h"
#include "IMachineConstant/Data/STDConstant/std_constant_acsaxis.h"

#include "Serializer/QSerializer"

class SR_StencilLibrary;

class GUIFRAMEWORK_EXPORT S_StencilLibrary : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, offset_SlotGap)
    QS_FIELD(int, totalSlotCount)

public:
    S_StencilLibrary();
    S_StencilLibrary(const S_StencilLibrary &instance);
    S_StencilLibrary(const SR_StencilLibrary &instance);
    S_StencilLibrary &operator=(const S_StencilLibrary &instance);
    S_StencilLibrary &operator=(const SR_StencilLibrary &instance);
};

class GUIFRAMEWORK_EXPORT SR_StencilLibrary : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TDouble, offset_SlotGap)
    QS_OBJECT(TInt, totalSlotCount)

public:
    SR_StencilLibrary();
    SR_StencilLibrary(const S_StencilLibrary &instance);
    SR_StencilLibrary(const SR_StencilLibrary &instance);
    SR_StencilLibrary &operator=(const S_StencilLibrary &instance);
    SR_StencilLibrary &operator=(const SR_StencilLibrary &instance);
};


class SR_StencilTransferPos;

class GUIFRAMEWORK_EXPORT S_StencilTransferPos : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_Point2D, pos_Idle)
    QS_OBJECT(S_Point2D, pos_ReadBarcode)
    QS_OBJECT(S_Point2D, pos_TransferSafe)
    QS_OBJECT(S_Point2D, pos_FeederPrepare)
    QS_OBJECT(S_Point2D, pos_FeederUp)
    QS_OBJECT(S_Point2D, pos_FeederPick)
    QS_OBJECT(S_Point2D, pos_LibraryPrepare)
    QS_OBJECT(S_Point2D, pos_LibraryMiddleUp)
    QS_OBJECT(S_Point2D, pos_LibraryMiddleDw)
    QS_OBJECT(S_Point2D, pos_LibraryUp)
    QS_OBJECT(S_Point2D, pos_LibraryPick)
    QS_OBJECT(S_Point2D, pos_SwapMiddle)
    QS_OBJECT(S_Point2D, pos_SwapUp)
    QS_OBJECT(S_Point2D, pos_Swap)
    QS_OBJECT(S_Point2D, pos_StencilStageSafety)
    QS_OBJECT(S_Point2D, pos_StencilStageSwap)




public:
    S_StencilTransferPos();
    S_StencilTransferPos(const S_StencilTransferPos &transfer);
    S_StencilTransferPos(const SR_StencilTransferPos &transfer);
    S_StencilTransferPos &operator=(const S_StencilTransferPos &transfer);
    S_StencilTransferPos &operator=(const SR_StencilTransferPos &transfer);
};

class GUIFRAMEWORK_EXPORT SR_StencilTransferPos : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_Point2D, pos_Idle)
    QS_OBJECT(SR_Point2D, pos_ReadBarcode)
    QS_OBJECT(SR_Point2D, pos_TransferSafe)
    QS_OBJECT(SR_Point2D, pos_FeederPrepare)
    QS_OBJECT(SR_Point2D, pos_FeederUp)
    QS_OBJECT(SR_Point2D, pos_FeederPick)
    QS_OBJECT(SR_Point2D, pos_LibraryPrepare)
    QS_OBJECT(SR_Point2D, pos_LibraryMiddleUp)
    QS_OBJECT(SR_Point2D, pos_LibraryMiddleDw)
    QS_OBJECT(SR_Point2D, pos_LibraryUp)
    QS_OBJECT(SR_Point2D, pos_LibraryPick)
    QS_OBJECT(SR_Point2D, pos_SwapMiddle)
    QS_OBJECT(SR_Point2D, pos_SwapUp)
    QS_OBJECT(SR_Point2D, pos_Swap)
    QS_OBJECT(SR_Point2D, pos_StencilStageSafety)
    QS_OBJECT(SR_Point2D, pos_StencilStageSwap)


public:
    SR_StencilTransferPos();
    SR_StencilTransferPos(const SR_StencilTransferPos &transfer);
    SR_StencilTransferPos(const S_StencilTransferPos &transfer);
    SR_StencilTransferPos &operator=(const SR_StencilTransferPos &transfer);
    SR_StencilTransferPos &operator=(const S_StencilTransferPos &transfer);
};


class SR_IDReader;

class GUIFRAMEWORK_EXPORT S_IDReader : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

public:
    S_IDReader();
    S_IDReader(const S_IDReader &instance);
    S_IDReader(const SR_IDReader &instance);
    S_IDReader &operator=(const S_IDReader &instance);
    S_IDReader &operator=(const SR_IDReader &instance);
};

class GUIFRAMEWORK_EXPORT SR_IDReader : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

public:
    SR_IDReader();
    SR_IDReader(const S_IDReader &instance);
    SR_IDReader(const SR_IDReader &instance);
    SR_IDReader &operator=(const S_IDReader &instance);
    SR_IDReader &operator=(const SR_IDReader &instance);
};

class SR_StencilManagement;

class GUIFRAMEWORK_EXPORT S_StencilManagement : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_StencilLibrary, stencilLibrary)
    QS_OBJECT(S_StencilTransferPos, transferPos)
    QS_OBJECT(S_STD_Constant_AcsAxis, zAxis)
    QS_OBJECT(S_STD_Constant_AcsAxis, yAxis)
    QS_OBJECT(S_IDReader, idReader)

public:
    S_StencilManagement();
    S_StencilManagement(const S_StencilManagement &instance);
    S_StencilManagement(const SR_StencilManagement &instance);
    S_StencilManagement &operator=(const S_StencilManagement &instance);
    S_StencilManagement &operator=(const SR_StencilManagement &instance);
};

class GUIFRAMEWORK_EXPORT SR_StencilManagement : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_StencilLibrary, stencilLibrary)
    QS_OBJECT(SR_StencilTransferPos, transferPos)
    QS_OBJECT(SR_STD_Constant_AcsAxis, zAxis)
    QS_OBJECT(SR_STD_Constant_AcsAxis, yAxis)
    QS_OBJECT(SR_IDReader, idReader)

public:
    SR_StencilManagement();
    SR_StencilManagement(const S_StencilManagement &instance);
    SR_StencilManagement(const SR_StencilManagement &instance);
    SR_StencilManagement &operator=(const S_StencilManagement &instance);
    SR_StencilManagement &operator=(const SR_StencilManagement &instance);
};

#endif // STENCILTRANSFER_H
