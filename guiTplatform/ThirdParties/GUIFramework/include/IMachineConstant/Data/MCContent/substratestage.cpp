#include "substratestage.h"

S_SubstrateStage::S_SubstrateStage()
{

}

S_SubstrateStage::S_SubstrateStage(const S_SubstrateStage &stage)
{
    this->verticalStage = stage.verticalStage;
    this->horizontalStage = stage.horizontalStage;
    this->epin = stage.epin;
    this->rz = stage.rz;
    this->fiducial = stage.fiducial;
    this->ESS = stage.ESS;
    this->iCsTF = stage.iCsTF;
    this->vCsTF = stage.vCsTF;
    this->chunk = stage.chunk;
    this->matrix = stage.matrix;
}

S_SubstrateStage::S_SubstrateStage(const SR_SubstrateStage &stage)
{
    this->verticalStage = stage.verticalStage;
    this->horizontalStage = stage.horizontalStage;
    this->epin = stage.epin;
    this->rz = stage.rz;
    this->fiducial = stage.fiducial;
    this->ESS = stage.ESS;
    this->iCsTF = stage.iCsTF;
    this->vCsTF = stage.vCsTF;
    this->chunk = stage.chunk;
    this->matrix = stage.matrix.value;
}

S_SubstrateStage &S_SubstrateStage::operator=(const S_SubstrateStage &stage)
{
    this->verticalStage = stage.verticalStage;
    this->horizontalStage = stage.horizontalStage;
    this->epin = stage.epin;
    this->rz = stage.rz;
    this->fiducial = stage.fiducial;
    this->ESS = stage.ESS;
    this->iCsTF = stage.iCsTF;
    this->vCsTF = stage.vCsTF;
    this->chunk = stage.chunk;
    this->matrix = stage.matrix;
    return *this;
}

S_SubstrateStage &S_SubstrateStage::operator=(const SR_SubstrateStage &stage)
{
    this->verticalStage = stage.verticalStage;
    this->horizontalStage = stage.horizontalStage;
    this->epin = stage.epin;
    this->rz = stage.rz;
    this->fiducial = stage.fiducial;
    this->ESS = stage.ESS;
    this->iCsTF = stage.iCsTF;
    this->vCsTF = stage.vCsTF;
    this->chunk = stage.chunk;
    this->matrix = stage.matrix.value;
    return *this;
}

SR_SubstrateStage::SR_SubstrateStage()
{
    this->verticalStage.valueName = toStr(verticalStage);
    this->horizontalStage.valueName = toStr(horizontalStage);
    this->epin.valueName = toStr(epin);
    this->rz.valueName = toStr(rz);
    this->fiducial.valueName = toStr(fiducial);
    this->ESS.valueName = toStr(ESS);
    this->iCsTF.valueName = toStr(iCsTF);
    this->vCsTF.valueName = toStr(vCsTF);
    this->chunk.valueName = toStr(chunk);
    this->matrix.valueName = toStr(matrix);
}

SR_SubstrateStage::SR_SubstrateStage(const SR_SubstrateStage &stage)
{
    this->verticalStage = stage.verticalStage;
    this->horizontalStage = stage.horizontalStage;
    this->epin = stage.epin;
    this->rz = stage.rz;
    this->fiducial = stage.fiducial;
    this->ESS = stage.ESS;
    this->iCsTF = stage.iCsTF;
    this->vCsTF = stage.vCsTF;
    this->chunk = stage.chunk;
    this->matrix = stage.matrix;
}

SR_SubstrateStage::SR_SubstrateStage(const S_SubstrateStage &stage)
{
    this->verticalStage = stage.verticalStage;
    this->horizontalStage = stage.horizontalStage;
    this->epin = stage.epin;
    this->rz = stage.rz;
    this->fiducial = stage.fiducial;
    this->ESS = stage.ESS;
    this->iCsTF = stage.iCsTF;
    this->vCsTF = stage.vCsTF;
    this->chunk = stage.chunk;
    this->matrix = stage.matrix;
}

SR_SubstrateStage &SR_SubstrateStage::operator=(const SR_SubstrateStage &stage)
{
    this->verticalStage = stage.verticalStage;
    this->horizontalStage = stage.horizontalStage;
    this->epin = stage.epin;
    this->rz = stage.rz;
    this->fiducial = stage.fiducial;
    this->ESS = stage.ESS;
    this->iCsTF = stage.iCsTF;
    this->vCsTF = stage.vCsTF;
    this->chunk = stage.chunk;
    this->matrix = stage.matrix;
    return *this;
}

SR_SubstrateStage &SR_SubstrateStage::operator=(const S_SubstrateStage &stage)
{
    this->verticalStage = stage.verticalStage;
    this->horizontalStage = stage.horizontalStage;
    this->epin = stage.epin;
    this->rz = stage.rz;
    this->fiducial = stage.fiducial;
    this->ESS = stage.ESS;
    this->iCsTF = stage.iCsTF;
    this->vCsTF = stage.vCsTF;
    this->chunk = stage.chunk;
    this->matrix = stage.matrix;
    return *this;
}

S_Fiducial::S_Fiducial()
{

}

S_Fiducial::S_Fiducial(const S_Fiducial &instance)
{
    this->center = instance.center;
    this->orthogonality = instance.orthogonality;
    this->pos = instance.pos;
}

S_Fiducial::S_Fiducial(const SR_Fiducial &instance)
{
    this->center.clear();
    for(int i = 0; i < instance.center.count(); i++)
    {
        this->center.append(instance.center[i].value);
    }

    this->orthogonality.clear();
    for(int i = 0; i < instance.orthogonality.count(); i++)
    {
        this->orthogonality.append(instance.orthogonality[i].value);
    }

    this->pos.clear();
    for(int i = 0; i < instance.pos.count(); i++)
    {
        this->pos.append(instance.pos[i].value);
    }
}

S_Fiducial &S_Fiducial::operator=(const S_Fiducial &instance)
{
    this->center = instance.center;
    this->orthogonality = instance.orthogonality;
    this->pos = instance.pos;
    return *this;
}

S_Fiducial &S_Fiducial::operator=(const SR_Fiducial &instance)
{
    this->center.clear();
    for(int i = 0; i < instance.center.count(); i++)
    {
        this->center.append(instance.center[i].value);
    }

    this->orthogonality.clear();
    for(int i = 0; i < instance.orthogonality.count(); i++)
    {
        this->orthogonality.append(instance.orthogonality[i].value);
    }

    this->pos.clear();
    for(int i = 0; i < instance.pos.count(); i++)
    {
        this->pos.append(instance.pos[i].value);
    }
    return *this;
}

SR_Fiducial::SR_Fiducial()
{

}

SR_Fiducial::SR_Fiducial(const S_Fiducial &instance)
{
    this->center.clear();
    for(int i = 0; i < instance.center.count(); i++)
    {
        this->center.append(instance.center[i]);
    }

    this->orthogonality.clear();
    for(int i = 0; i < instance.orthogonality.count(); i++)
    {
        this->orthogonality.append(instance.orthogonality[i]);
    }

    this->pos.clear();
    for(int i = 0; i < instance.pos.count(); i++)
    {
        this->pos.append(instance.pos[i]);
    }
}

SR_Fiducial::SR_Fiducial(const SR_Fiducial &instance)
{
    this->center = instance.center;
    this->orthogonality = instance.orthogonality;
    this->pos = instance.pos;
}

SR_Fiducial &SR_Fiducial::operator=(const S_Fiducial &instance)
{
    this->center.clear();
    for(int i = 0; i < instance.center.count(); i++)
    {
        this->center.append(instance.center[i]);
    }

    this->orthogonality.clear();
    for(int i = 0; i < instance.orthogonality.count(); i++)
    {
        this->orthogonality.append(instance.orthogonality[i]);
    }

    this->pos.clear();
    for(int i = 0; i < instance.pos.count(); i++)
    {
        this->pos.append(instance.pos[i]);
    }
    return *this;
}


SR_Fiducial &SR_Fiducial::operator=(const SR_Fiducial &instance)
{
    this->center = instance.center;
    this->orthogonality = instance.orthogonality;
    this->pos = instance.pos;
    return *this;
}

S_ESS::S_ESS()
{

}

S_ESS::S_ESS(const S_ESS &instance)
{
    this->center = instance.center;
}

S_ESS::S_ESS(const SR_ESS &instance)
{
    this->center.clear();
    for(int i = 0; i < instance.center.count(); i++)
    {
        this->center.append(instance.center[i].value);
    }
}

S_ESS &S_ESS::operator=(const S_ESS &instance)
{
    this->center = instance.center;
    return *this;
}

S_ESS &S_ESS::operator=(const SR_ESS &instance)
{
    this->center.clear();
    for(int i = 0; i < instance.center.count(); i++)
    {
        this->center.append(instance.center[i].value);
    }
    return *this;
}

SR_ESS::SR_ESS()
{

}

SR_ESS::SR_ESS(const S_ESS &instance)
{
    this->center.clear();
    for(int i = 0; i < instance.center.count(); i++)
    {
        this->center.append(instance.center[i]);
    }
}

SR_ESS::SR_ESS(const SR_ESS &instance)
{
    this->center = instance.center;
}

SR_ESS &SR_ESS::operator=(const S_ESS &instance)
{
    this->center.clear();
    for(int i = 0; i < instance.center.count(); i++)
    {
        this->center.append(instance.center[i]);
    }
    return *this;
}

SR_ESS &SR_ESS::operator=(const SR_ESS &instance)
{
    this->center = instance.center;
    return *this;
}
