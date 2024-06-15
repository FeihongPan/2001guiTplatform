#ifndef SCANNINGSTAGE_H
#define SCANNINGSTAGE_H

#include "GUIFramework_global.h"
#include "IMachineConstant/Data/STDConstant/std_constant_acsaxis.h"
#include "IMachineConstant/Data/STDConstant/std_constant_tf.h"
#include "Serializer/QSerializer"

class SR_ScanningStage;

class GUIFRAMEWORK_EXPORT S_ScanningStage : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_STD_Constant_AcsAxis, xAxis)
    QS_OBJECT(S_STD_Constant_AcsAxis, yAxis)
    QS_OBJECT(S_STD_Constant_iCsTF, iCsTF)
    QS_OBJECT(S_STD_Constant_Air, airFoot)
    QS_FIELD(QString, matrix)

public:
    S_ScanningStage();
    S_ScanningStage(const S_ScanningStage &stage);
    S_ScanningStage(const SR_ScanningStage &stage);
    S_ScanningStage &operator=(const S_ScanningStage &stage);
    S_ScanningStage &operator=(const SR_ScanningStage &stage);
};

class GUIFRAMEWORK_EXPORT SR_ScanningStage : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(SR_STD_Constant_AcsAxis, xAxis)
    QS_OBJECT(SR_STD_Constant_AcsAxis, yAxis)
    QS_OBJECT(SR_STD_Constant_iCsTF, iCsTF)
    QS_OBJECT(SR_STD_Constant_Air, airFoot)
    QS_OBJECT(TString, matrix)

public:
    SR_ScanningStage();
    SR_ScanningStage(const SR_ScanningStage &stage);
    SR_ScanningStage(const S_ScanningStage &stage);
    SR_ScanningStage &operator=(const SR_ScanningStage &stage);
    SR_ScanningStage &operator=(const S_ScanningStage &stage);
};

#endif // SCANNINGSTAGE_H
