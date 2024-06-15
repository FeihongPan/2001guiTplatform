#include "stenciltransfer.h"

S_StencilTransferPos::S_StencilTransferPos()
{

}

S_StencilTransferPos::S_StencilTransferPos(const S_StencilTransferPos &transfer)
{
    this->pos_Idle = transfer.pos_Idle;
    this->pos_ReadBarcode = transfer.pos_ReadBarcode;
    this->pos_TransferSafe = transfer.pos_TransferSafe;
    this->pos_FeederPrepare = transfer.pos_FeederPrepare;
    this->pos_FeederUp = transfer.pos_FeederUp;
    this->pos_FeederPick = transfer.pos_FeederPick;
    this->pos_LibraryMiddleDw = transfer.pos_LibraryMiddleDw;
    this->pos_LibraryMiddleUp = transfer.pos_LibraryMiddleUp;
    this->pos_LibraryPick = transfer.pos_LibraryPick;
    this->pos_LibraryUp = transfer.pos_LibraryUp;
    this->pos_LibraryPrepare = transfer.pos_LibraryPrepare;
    this->pos_SwapMiddle = transfer.pos_SwapMiddle;
    this->pos_SwapUp = transfer.pos_SwapUp;
    this->pos_Swap = transfer.pos_Swap;
    this->pos_StencilStageSafety = transfer.pos_StencilStageSafety;
    this->pos_StencilStageSwap = transfer.pos_StencilStageSwap;

}

S_StencilTransferPos::S_StencilTransferPos(const SR_StencilTransferPos &transfer)
{
    this->pos_Idle = transfer.pos_Idle;
    this->pos_ReadBarcode = transfer.pos_ReadBarcode;
    this->pos_TransferSafe = transfer.pos_TransferSafe;
    this->pos_FeederPrepare = transfer.pos_FeederPrepare;
    this->pos_FeederUp = transfer.pos_FeederUp;
    this->pos_FeederPick = transfer.pos_FeederPick;
    this->pos_LibraryMiddleDw = transfer.pos_LibraryMiddleDw;
    this->pos_LibraryMiddleUp = transfer.pos_LibraryMiddleUp;
    this->pos_LibraryPick = transfer.pos_LibraryPick;
    this->pos_LibraryUp = transfer.pos_LibraryUp;
    this->pos_LibraryPrepare = transfer.pos_LibraryPrepare;
    this->pos_SwapMiddle = transfer.pos_SwapMiddle;
    this->pos_SwapUp = transfer.pos_SwapUp;
    this->pos_Swap = transfer.pos_Swap;
    this->pos_StencilStageSafety = transfer.pos_StencilStageSafety;
    this->pos_StencilStageSwap = transfer.pos_StencilStageSwap;

}

S_StencilTransferPos &S_StencilTransferPos::operator=(const S_StencilTransferPos &transfer)
{
    this->pos_Idle = transfer.pos_Idle;
    this->pos_ReadBarcode = transfer.pos_ReadBarcode;
    this->pos_TransferSafe = transfer.pos_TransferSafe;
    this->pos_FeederPrepare = transfer.pos_FeederPrepare;
    this->pos_FeederUp = transfer.pos_FeederUp;
    this->pos_FeederPick = transfer.pos_FeederPick;
    this->pos_LibraryMiddleDw = transfer.pos_LibraryMiddleDw;
    this->pos_LibraryMiddleUp = transfer.pos_LibraryMiddleUp;
    this->pos_LibraryPick = transfer.pos_LibraryPick;
    this->pos_LibraryUp = transfer.pos_LibraryUp;
    this->pos_LibraryPrepare = transfer.pos_LibraryPrepare;
    this->pos_SwapMiddle = transfer.pos_SwapMiddle;
    this->pos_SwapUp = transfer.pos_SwapUp;
    this->pos_Swap = transfer.pos_Swap;
    this->pos_StencilStageSafety = transfer.pos_StencilStageSafety;
    this->pos_StencilStageSwap = transfer.pos_StencilStageSwap;
    return *this;
}

S_StencilTransferPos &S_StencilTransferPos::operator=(const SR_StencilTransferPos &transfer)
{
    this->pos_Idle = transfer.pos_Idle;
    this->pos_ReadBarcode = transfer.pos_ReadBarcode;
    this->pos_TransferSafe = transfer.pos_TransferSafe;
    this->pos_FeederPrepare = transfer.pos_FeederPrepare;
    this->pos_FeederUp = transfer.pos_FeederUp;
    this->pos_FeederPick = transfer.pos_FeederPick;
    this->pos_LibraryMiddleDw = transfer.pos_LibraryMiddleDw;
    this->pos_LibraryMiddleUp = transfer.pos_LibraryMiddleUp;
    this->pos_LibraryPick = transfer.pos_LibraryPick;
    this->pos_LibraryUp = transfer.pos_LibraryUp;
    this->pos_LibraryPrepare = transfer.pos_LibraryPrepare;
    this->pos_SwapMiddle = transfer.pos_SwapMiddle;
    this->pos_SwapUp = transfer.pos_SwapUp;
    this->pos_Swap = transfer.pos_Swap;
    this->pos_StencilStageSafety = transfer.pos_StencilStageSafety;
    this->pos_StencilStageSwap = transfer.pos_StencilStageSwap;
    return *this;
}

SR_StencilTransferPos::SR_StencilTransferPos() : TValueBase()
{

}

SR_StencilTransferPos::SR_StencilTransferPos(const SR_StencilTransferPos &transfer) : TValueBase(transfer)
{
    this->pos_Idle = transfer.pos_Idle;
    this->pos_ReadBarcode = transfer.pos_ReadBarcode;
    this->pos_TransferSafe = transfer.pos_TransferSafe;
    this->pos_FeederPrepare = transfer.pos_FeederPrepare;
    this->pos_FeederUp = transfer.pos_FeederUp;
    this->pos_FeederPick = transfer.pos_FeederPick;
    this->pos_LibraryMiddleDw = transfer.pos_LibraryMiddleDw;
    this->pos_LibraryMiddleUp = transfer.pos_LibraryMiddleUp;
    this->pos_LibraryPick = transfer.pos_LibraryPick;
    this->pos_LibraryUp = transfer.pos_LibraryUp;
    this->pos_LibraryPrepare = transfer.pos_LibraryPrepare;
    this->pos_SwapMiddle = transfer.pos_SwapMiddle;
    this->pos_SwapUp = transfer.pos_SwapUp;
    this->pos_Swap = transfer.pos_Swap;
    this->pos_StencilStageSafety = transfer.pos_StencilStageSafety;
    this->pos_StencilStageSwap = transfer.pos_StencilStageSwap;
}

SR_StencilTransferPos::SR_StencilTransferPos(const S_StencilTransferPos &transfer) : TValueBase()
{
    this->pos_Idle = transfer.pos_Idle;
    this->pos_ReadBarcode = transfer.pos_ReadBarcode;
    this->pos_TransferSafe = transfer.pos_TransferSafe;
    this->pos_FeederPrepare = transfer.pos_FeederPrepare;
    this->pos_FeederUp = transfer.pos_FeederUp;
    this->pos_FeederPick = transfer.pos_FeederPick;
    this->pos_LibraryMiddleDw = transfer.pos_LibraryMiddleDw;
    this->pos_LibraryMiddleUp = transfer.pos_LibraryMiddleUp;
    this->pos_LibraryPick = transfer.pos_LibraryPick;
    this->pos_LibraryUp = transfer.pos_LibraryUp;
    this->pos_LibraryPrepare = transfer.pos_LibraryPrepare;
    this->pos_SwapMiddle = transfer.pos_SwapMiddle;
    this->pos_SwapUp = transfer.pos_SwapUp;
    this->pos_Swap = transfer.pos_Swap;
    this->pos_StencilStageSafety = transfer.pos_StencilStageSafety;
    this->pos_StencilStageSwap = transfer.pos_StencilStageSwap;
}

SR_StencilTransferPos &SR_StencilTransferPos::operator=(const SR_StencilTransferPos &transfer)
{
    TValueBase::operator=(transfer);
    this->pos_Idle = transfer.pos_Idle;
    this->pos_ReadBarcode = transfer.pos_ReadBarcode;
    this->pos_TransferSafe = transfer.pos_TransferSafe;
    this->pos_FeederPrepare = transfer.pos_FeederPrepare;
    this->pos_FeederUp = transfer.pos_FeederUp;
    this->pos_FeederPick = transfer.pos_FeederPick;
    this->pos_LibraryMiddleDw = transfer.pos_LibraryMiddleDw;
    this->pos_LibraryMiddleUp = transfer.pos_LibraryMiddleUp;
    this->pos_LibraryPick = transfer.pos_LibraryPick;
    this->pos_LibraryUp = transfer.pos_LibraryUp;
    this->pos_LibraryPrepare = transfer.pos_LibraryPrepare;
    this->pos_SwapMiddle = transfer.pos_SwapMiddle;
    this->pos_SwapUp = transfer.pos_SwapUp;
    this->pos_Swap = transfer.pos_Swap;
    this->pos_StencilStageSafety = transfer.pos_StencilStageSafety;
    this->pos_StencilStageSwap = transfer.pos_StencilStageSwap;
    return *this;
}

SR_StencilTransferPos &SR_StencilTransferPos::operator=(const S_StencilTransferPos &transfer)
{
    this->pos_Idle = transfer.pos_Idle;
    this->pos_ReadBarcode = transfer.pos_ReadBarcode;
    this->pos_TransferSafe = transfer.pos_TransferSafe;
    this->pos_FeederPrepare = transfer.pos_FeederPrepare;
    this->pos_FeederUp = transfer.pos_FeederUp;
    this->pos_FeederPick = transfer.pos_FeederPick;
    this->pos_LibraryMiddleDw = transfer.pos_LibraryMiddleDw;
    this->pos_LibraryMiddleUp = transfer.pos_LibraryMiddleUp;
    this->pos_LibraryPick = transfer.pos_LibraryPick;
    this->pos_LibraryUp = transfer.pos_LibraryUp;
    this->pos_LibraryPrepare = transfer.pos_LibraryPrepare;
    this->pos_SwapMiddle = transfer.pos_SwapMiddle;
    this->pos_SwapUp = transfer.pos_SwapUp;
    this->pos_Swap = transfer.pos_Swap;
    this->pos_StencilStageSafety = transfer.pos_StencilStageSafety;
    this->pos_StencilStageSwap = transfer.pos_StencilStageSwap;
    return *this;
}

S_StencilLibrary::S_StencilLibrary()
{

}

S_StencilLibrary::S_StencilLibrary(const S_StencilLibrary &instance)
{
    this->offset_SlotGap = instance.offset_SlotGap;
    this->totalSlotCount = instance.totalSlotCount;
}

S_StencilLibrary::S_StencilLibrary(const SR_StencilLibrary &instance)
{
    this->offset_SlotGap = instance.offset_SlotGap.value;
    this->totalSlotCount = instance.totalSlotCount.value;
}

S_StencilLibrary &S_StencilLibrary::operator=(const S_StencilLibrary &instance)
{
    this->offset_SlotGap = instance.offset_SlotGap;
    this->totalSlotCount = instance.totalSlotCount;
    return *this;
}

S_StencilLibrary &S_StencilLibrary::operator=(const SR_StencilLibrary &instance)
{
    this->offset_SlotGap = instance.offset_SlotGap.value;
    this->totalSlotCount = instance.totalSlotCount.value;
    return *this;
}

SR_StencilLibrary::SR_StencilLibrary() : TValueBase()
{

}

SR_StencilLibrary::SR_StencilLibrary(const S_StencilLibrary &instance) : TValueBase()
{
    this->offset_SlotGap = instance.offset_SlotGap;
    this->totalSlotCount = instance.totalSlotCount;
}

SR_StencilLibrary::SR_StencilLibrary(const SR_StencilLibrary &instance) : TValueBase(instance)
{
    this->offset_SlotGap = instance.offset_SlotGap;
    this->totalSlotCount = instance.totalSlotCount;
}

SR_StencilLibrary &SR_StencilLibrary::operator=(const S_StencilLibrary &instance)
{
    this->offset_SlotGap = instance.offset_SlotGap;
    this->totalSlotCount = instance.totalSlotCount;
    return *this;
}

SR_StencilLibrary &SR_StencilLibrary::operator=(const SR_StencilLibrary &instance)
{
    TValueBase::operator=(instance);
    this->offset_SlotGap = instance.offset_SlotGap;
    this->totalSlotCount = instance.totalSlotCount;
    return *this;
}

S_StencilManagement::S_StencilManagement()
{

}

S_StencilManagement::S_StencilManagement(const S_StencilManagement &instance)
{
    this->stencilLibrary = instance.stencilLibrary;
    this->transferPos = instance.transferPos;
    this->zAxis = instance.zAxis;
    this->yAxis = instance.yAxis;
    this->idReader = instance.idReader;
}

S_StencilManagement::S_StencilManagement(const SR_StencilManagement &instance)
{
    this->stencilLibrary = instance.stencilLibrary;
    this->transferPos = instance.transferPos;
    this->zAxis = instance.zAxis;
    this->yAxis = instance.yAxis;
    this->idReader = instance.idReader;
}

S_StencilManagement &S_StencilManagement::operator=(const S_StencilManagement &instance)
{
    this->stencilLibrary = instance.stencilLibrary;
    this->transferPos = instance.transferPos;
    this->zAxis = instance.zAxis;
    this->yAxis = instance.yAxis;
    this->idReader = instance.idReader;
    return *this;
}

S_StencilManagement &S_StencilManagement::operator=(const SR_StencilManagement &instance)
{
    this->stencilLibrary = instance.stencilLibrary;
    this->transferPos = instance.transferPos;
    this->zAxis = instance.zAxis;
    this->yAxis = instance.yAxis;
    this->idReader = instance.idReader;
    return *this;
}

SR_StencilManagement::SR_StencilManagement() : TValueBase()
{

}

SR_StencilManagement::SR_StencilManagement(const S_StencilManagement &instance) : TValueBase()
{
    this->stencilLibrary = instance.stencilLibrary;
    this->transferPos = instance.transferPos;
    this->zAxis = instance.zAxis;
    this->yAxis = instance.yAxis;
    this->idReader = instance.idReader;
}

SR_StencilManagement::SR_StencilManagement(const SR_StencilManagement &instance) : TValueBase(instance)
{
    this->stencilLibrary = instance.stencilLibrary;
    this->transferPos = instance.transferPos;
    this->zAxis = instance.zAxis;
    this->yAxis = instance.yAxis;
    this->idReader = instance.idReader;
}

SR_StencilManagement &SR_StencilManagement::operator=(const S_StencilManagement &instance)
{
    this->stencilLibrary = instance.stencilLibrary;
    this->transferPos = instance.transferPos;
    this->zAxis = instance.zAxis;
    this->yAxis = instance.yAxis;
    this->idReader = instance.idReader;
    return *this;
}

SR_StencilManagement &SR_StencilManagement::operator=(const SR_StencilManagement &instance)
{
    TValueBase::operator=(instance);
    this->stencilLibrary = instance.stencilLibrary;
    this->transferPos = instance.transferPos;
    this->zAxis = instance.zAxis;
    this->yAxis = instance.yAxis;
    this->idReader = instance.idReader;
    return *this;
}

S_IDReader::S_IDReader()
{

}

S_IDReader::S_IDReader(const S_IDReader &instance)
{

}

S_IDReader::S_IDReader(const SR_IDReader &instance)
{

}

S_IDReader &S_IDReader::operator=(const S_IDReader &instance)
{
    return *this;
}

S_IDReader &S_IDReader::operator=(const SR_IDReader &instance)
{
    return *this;
}

SR_IDReader::SR_IDReader() : TValueBase()
{

}

SR_IDReader::SR_IDReader(const S_IDReader &instance) : TValueBase()
{

}

SR_IDReader::SR_IDReader(const SR_IDReader &instance) : TValueBase(instance)
{

}

SR_IDReader &SR_IDReader::operator=(const S_IDReader &instance)
{
    return *this;
}

SR_IDReader &SR_IDReader::operator=(const SR_IDReader &instance)
{
    TValueBase::operator=(instance);
    return *this;
}

