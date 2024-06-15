#include "std_constant_cal.h"

S_STD_Constant_Cal::S_STD_Constant_Cal()
{

}

S_STD_Constant_Cal::S_STD_Constant_Cal(const S_STD_Constant_Cal &instance)
{
    this->fov = instance.fov;
    this->focus = instance.focus;
    this->fovCenterPos = instance.fovCenterPos;
    this->intrinsicParams = instance.intrinsicParams;
    this->extrinsicParams = instance.extrinsicParams;
}

S_STD_Constant_Cal::S_STD_Constant_Cal(const SR_STD_Constant_Cal &instance)
{
    this->fov.clear();
    for(int i = 0; i < instance.fov.count(); i++)
    {
        this->fov.append(instance.fov[i].value);
    }

    this->focus = instance.focus.value;

    this->fovCenterPos.clear();
    for(int i = 0; i < instance.fovCenterPos.count(); i++)
    {
        this->fovCenterPos.append(instance.fovCenterPos[i].value);
    }

    this->intrinsicParams = instance.intrinsicParams;
    this->extrinsicParams = instance.extrinsicParams;
}

S_STD_Constant_Cal &S_STD_Constant_Cal::operator=(const S_STD_Constant_Cal &instance)
{
    this->fov = instance.fov;
    this->focus = instance.focus;
    this->fovCenterPos = instance.fovCenterPos;
    this->intrinsicParams = instance.intrinsicParams;
    this->extrinsicParams = instance.extrinsicParams;
    return *this;
}

S_STD_Constant_Cal &S_STD_Constant_Cal::operator=(const SR_STD_Constant_Cal &instance)
{
    this->fov.clear();
    for(int i = 0; i < instance.fov.count(); i++)
    {
        this->fov.append(instance.fov[i].value);
    }

    this->focus = instance.focus.value;

    this->fovCenterPos.clear();
    for(int i = 0; i < instance.fovCenterPos.count(); i++)
    {
        this->fovCenterPos.append(instance.fovCenterPos[i].value);
    }

    this->intrinsicParams = instance.intrinsicParams;
    this->extrinsicParams = instance.extrinsicParams;
    return *this;
}

SR_STD_Constant_Cal::SR_STD_Constant_Cal() : TValueBase()
{

}

SR_STD_Constant_Cal::SR_STD_Constant_Cal(const S_STD_Constant_Cal &instance) : TValueBase()
{
    this->fov.clear();
    for(int i = 0; i < instance.fov.count(); i++)
    {
        this->fov.append(instance.fov[i]);
    }

    this->focus = instance.focus;

    this->fovCenterPos.clear();
    for(int i = 0; i < instance.fovCenterPos.count(); i++)
    {
        this->fovCenterPos.append(instance.fovCenterPos[i]);
    }

    this->intrinsicParams = instance.intrinsicParams;
    this->extrinsicParams = instance.extrinsicParams;
}

SR_STD_Constant_Cal::SR_STD_Constant_Cal(const SR_STD_Constant_Cal &instance) : TValueBase(instance)
{
    this->fov = instance.fov;
    this->focus = instance.focus;
    this->fovCenterPos = instance.fovCenterPos;
    this->intrinsicParams = instance.intrinsicParams;
    this->extrinsicParams = instance.extrinsicParams;
}

SR_STD_Constant_Cal &SR_STD_Constant_Cal::operator=(const S_STD_Constant_Cal &instance)
{
    this->fov.clear();
    for(int i = 0; i < instance.fov.count(); i++)
    {
        this->fov.append(instance.fov[i]);
    }

    this->focus = instance.focus;

    this->fovCenterPos.clear();
    for(int i = 0; i < instance.fovCenterPos.count(); i++)
    {
        this->fovCenterPos.append(instance.fovCenterPos[i]);
    }

    this->intrinsicParams = instance.intrinsicParams;
    this->extrinsicParams = instance.extrinsicParams;
    return *this;
}

SR_STD_Constant_Cal &SR_STD_Constant_Cal::operator=(const SR_STD_Constant_Cal &instance)
{
    TValueBase::operator=(instance);
    this->fov = instance.fov;
    this->focus = instance.focus;
    this->fovCenterPos = instance.fovCenterPos;
    this->intrinsicParams = instance.intrinsicParams;
    this->extrinsicParams = instance.extrinsicParams;
    return *this;
}

S_STD_Constant_Cal_IntrinsicParams::S_STD_Constant_Cal_IntrinsicParams()
{

}

S_STD_Constant_Cal_IntrinsicParams::S_STD_Constant_Cal_IntrinsicParams(const S_STD_Constant_Cal_IntrinsicParams &instance)
{
    this->cameraMatrix = instance.cameraMatrix;
    this->DistortionCoeff = instance.DistortionCoeff;
}

S_STD_Constant_Cal_IntrinsicParams::S_STD_Constant_Cal_IntrinsicParams(const SR_STD_Constant_Cal_IntrinsicParams &instance)
{
    this->cameraMatrix.clear();
    for(int i = 0; i < instance.cameraMatrix.count(); i++)
    {
        this->cameraMatrix.append(instance.cameraMatrix[i].value);
    }

    this->DistortionCoeff.clear();
    for(int i = 0; i < instance.DistortionCoeff.count(); i++)
    {
        this->DistortionCoeff.append(instance.DistortionCoeff[i].value);
    }
}

S_STD_Constant_Cal_IntrinsicParams &S_STD_Constant_Cal_IntrinsicParams::operator=(const S_STD_Constant_Cal_IntrinsicParams &instance)
{
    this->cameraMatrix = instance.cameraMatrix;
    this->DistortionCoeff = instance.DistortionCoeff;
    return *this;
}

S_STD_Constant_Cal_IntrinsicParams &S_STD_Constant_Cal_IntrinsicParams::operator=(const SR_STD_Constant_Cal_IntrinsicParams &instance)
{
    this->cameraMatrix.clear();
    for(int i = 0; i < instance.cameraMatrix.count(); i++)
    {
        this->cameraMatrix.append(instance.cameraMatrix[i].value);
    }

    this->DistortionCoeff.clear();
    for(int i = 0; i < instance.DistortionCoeff.count(); i++)
    {
        this->DistortionCoeff.append(instance.DistortionCoeff[i].value);
    }
    return *this;
}

SR_STD_Constant_Cal_IntrinsicParams::SR_STD_Constant_Cal_IntrinsicParams() : TValueBase()
{

}

SR_STD_Constant_Cal_IntrinsicParams::SR_STD_Constant_Cal_IntrinsicParams(const S_STD_Constant_Cal_IntrinsicParams &instance) : TValueBase()
{
    this->cameraMatrix.clear();
    for(int i = 0; i < instance.cameraMatrix.count(); i++)
    {
        this->cameraMatrix.append(instance.cameraMatrix[i]);
    }

    this->DistortionCoeff.clear();
    for(int i = 0; i < instance.DistortionCoeff.count(); i++)
    {
        this->DistortionCoeff.append(instance.DistortionCoeff[i]);
    }
}

SR_STD_Constant_Cal_IntrinsicParams::SR_STD_Constant_Cal_IntrinsicParams(const SR_STD_Constant_Cal_IntrinsicParams &instance) : TValueBase(instance)
{
    this->cameraMatrix = instance.cameraMatrix;
    this->DistortionCoeff = instance.DistortionCoeff;
}

SR_STD_Constant_Cal_IntrinsicParams &SR_STD_Constant_Cal_IntrinsicParams::operator=(const S_STD_Constant_Cal_IntrinsicParams &instance)
{
    this->cameraMatrix.clear();
    for(int i = 0; i < instance.cameraMatrix.count(); i++)
    {
        this->cameraMatrix.append(instance.cameraMatrix[i]);
    }

    this->DistortionCoeff.clear();
    for(int i = 0; i < instance.DistortionCoeff.count(); i++)
    {
        this->DistortionCoeff.append(instance.DistortionCoeff[i]);
    }
    return *this;
}

SR_STD_Constant_Cal_IntrinsicParams &SR_STD_Constant_Cal_IntrinsicParams::operator=(const SR_STD_Constant_Cal_IntrinsicParams &instance)
{
    TValueBase::operator=(instance);
    this->cameraMatrix = instance.cameraMatrix;
    this->DistortionCoeff = instance.DistortionCoeff;
    return *this;
}


S_STD_Constant_Cal_ExtrinsicParams::S_STD_Constant_Cal_ExtrinsicParams()
{

}

S_STD_Constant_Cal_ExtrinsicParams::S_STD_Constant_Cal_ExtrinsicParams(const S_STD_Constant_Cal_ExtrinsicParams &instance)
{
    this->rotationVector = instance.rotationVector;
    this->translationVector = instance.translationVector;
}

S_STD_Constant_Cal_ExtrinsicParams::S_STD_Constant_Cal_ExtrinsicParams(const SR_STD_Constant_Cal_ExtrinsicParams &instance)
{
    this->rotationVector.clear();
    for(int i = 0; i < instance.rotationVector.count(); i++)
    {
        this->rotationVector.append(instance.rotationVector[i].value);
    }

    this->translationVector.clear();
    for(int i = 0; i < instance.translationVector.count(); i++)
    {
        this->translationVector.append(instance.translationVector[i].value);
    }
}

S_STD_Constant_Cal_ExtrinsicParams &S_STD_Constant_Cal_ExtrinsicParams::operator=(const S_STD_Constant_Cal_ExtrinsicParams &instance)
{
    this->rotationVector = instance.rotationVector;
    this->translationVector = instance.translationVector;
    return *this;
}

S_STD_Constant_Cal_ExtrinsicParams &S_STD_Constant_Cal_ExtrinsicParams::operator=(const SR_STD_Constant_Cal_ExtrinsicParams &instance)
{
    this->rotationVector.clear();
    for(int i = 0; i < instance.rotationVector.count(); i++)
    {
        this->rotationVector.append(instance.rotationVector[i].value);
    }

    this->translationVector.clear();
    for(int i = 0; i < instance.translationVector.count(); i++)
    {
        this->translationVector.append(instance.translationVector[i].value);
    }
    return *this;
}

SR_STD_Constant_Cal_ExtrinsicParams::SR_STD_Constant_Cal_ExtrinsicParams() : TValueBase()
{

}

SR_STD_Constant_Cal_ExtrinsicParams::SR_STD_Constant_Cal_ExtrinsicParams(const S_STD_Constant_Cal_ExtrinsicParams &instance) : TValueBase()
{
    this->rotationVector.clear();
    for(int i = 0; i < instance.rotationVector.count(); i++)
    {
        this->rotationVector.append(instance.rotationVector[i]);
    }

    this->translationVector.clear();
    for(int i = 0; i < instance.translationVector.count(); i++)
    {
        this->translationVector.append(instance.translationVector[i]);
    }
}

SR_STD_Constant_Cal_ExtrinsicParams::SR_STD_Constant_Cal_ExtrinsicParams(const SR_STD_Constant_Cal_ExtrinsicParams &instance) : TValueBase(instance)
{
    this->rotationVector = instance.rotationVector;
    this->translationVector = instance.translationVector;
}

SR_STD_Constant_Cal_ExtrinsicParams &SR_STD_Constant_Cal_ExtrinsicParams::operator=(const S_STD_Constant_Cal_ExtrinsicParams &instance)
{
    this->rotationVector.clear();
    for(int i = 0; i < instance.rotationVector.count(); i++)
    {
        this->rotationVector.append(instance.rotationVector[i]);
    }

    this->translationVector.clear();
    for(int i = 0; i < instance.translationVector.count(); i++)
    {
        this->translationVector.append(instance.translationVector[i]);
    }
    return *this;
}

SR_STD_Constant_Cal_ExtrinsicParams &SR_STD_Constant_Cal_ExtrinsicParams::operator=(const SR_STD_Constant_Cal_ExtrinsicParams &instance)
{
    TValueBase::operator=(instance);
    this->rotationVector = instance.rotationVector;
    this->translationVector = instance.translationVector;
    return *this;
}
