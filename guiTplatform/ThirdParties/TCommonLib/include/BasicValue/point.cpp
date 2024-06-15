#include "point.h"

#include <QPointF>

S_Point2D::S_Point2D()
{

}

S_Point2D::S_Point2D(double x, double y)
{
    this->x = x;
    this->y = y;
}

S_Point2D::S_Point2D(const QPointF &p)
{
    this->x = p.x();
    this->y = p.y();
}

S_Point2D &S_Point2D::operator=(const SR_Point2D &p)
{
    this->x = p.x.value;
    this->y = p.y.value;
    return *this;
}

S_Point2D &S_Point2D::operator+=(const S_Point2D &p)
{
    this->x += p.x;
    this->y += p.y;
    return *this;
}

S_Point2D S_Point2D::operator+(const S_Point2D &p)
{
    S_Point2D ret;
    ret.x = x + p.x;
    ret.y = y + p.y;
    return ret;
}

QList<double> S_Point2D::ToDoubleList()
{
    QList<double> lst_Pos;
    lst_Pos.append(this->x);
    lst_Pos.append(this->y);
    return lst_Pos;
}

QString S_Point2D::ToString(char nF, int nPrec) const
{
    return ("(" + QString::number(x, nF, nPrec) + ", " + QString::number(y, nF, nPrec) + ")");
}

S_Point2D &S_Point2D::operator=(const QPointF &p)
{
    this->x = p.x();
    this->y = p.y();
    return *this;
}

SR_Point2D::SR_Point2D()
{
    this->x.valueName = toStr(x);
    this->y.valueName = toStr(y);
}

SR_Point2D::SR_Point2D(const SR_Point2D &p)
{
    this->x = p.x;
    this->y = p.y;
}

SR_Point2D::SR_Point2D(const QPointF &p)
{
    this->x = p.x();
    this->y = p.y();
}

SR_Point2D &SR_Point2D::operator=(const SR_Point2D &p)
{
    this->x = p.x;
    this->y = p.y;
    return *this;
}

SR_Point2D &SR_Point2D::operator=(const S_Point2D &p)
{
    this->x.SetValue(p.x);
    this->y.SetValue(p.y);
    return *this;
}

SR_Point2D &SR_Point2D::operator=(const QPointF &p)
{
    this->x.SetValue(p.x());
    this->y.SetValue(p.y());
    return *this;
}

S_Point3D::S_Point3D()
{

}

S_Point3D::S_Point3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

S_Point3D &S_Point3D::operator=(const S_Point3D &p)
{
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
    return *this;
}

S_Point3D &S_Point3D::operator+=(const S_Point3D &p)
{
    this->x += p.x;
    this->y += p.y;
    this->z += p.z;
    return *this;
}

S_Point3D S_Point3D::operator+(const S_Point3D &p)
{
    S_Point3D ret;
    ret.x = x + p.x;
    ret.y = y + p.y;
    ret.z = z + p.z;
    return ret;
}

S_Point3D &S_Point3D::operator=(const SR_Point3D &p)
{
    this->x = p.x.value;
    this->y = p.y.value;
    this->z = p.z.value;
    return *this;
}

QList<double> S_Point3D::ToDoubleList()
{
    QList<double> lst_Pos;
    lst_Pos.append(this->x);
    lst_Pos.append(this->y);
    lst_Pos.append(this->z);
    return lst_Pos;
}

SR_Point3D::SR_Point3D()
{
    this->x.valueName = toStr(x);
    this->y.valueName = toStr(y);
    this->z.valueName = toStr(z);
}

SR_Point3D::SR_Point3D(const SR_Point3D &p)
{
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
}

SR_Point3D &SR_Point3D::operator=(const SR_Point3D &p)
{
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
    return *this;
}

SR_Point3D &SR_Point3D::operator=(const S_Point3D &p)
{
    this->x.SetValue(p.x);
    this->y.SetValue(p.y);
    this->z.SetValue(p.z);
    return *this;
}

SR_Point3D &SR_Point3D::operator=(const SR_Point2D &p)
{
    this->x = p.x;
    this->y = p.y;
    this->z.SetValue(0);
    return *this;
}

SR_Point3D &SR_Point3D::operator=(const S_Point2D &p)
{
    this->x.SetValue(p.x);
    this->y.SetValue(p.y);
    this->z.SetValue(0);
    return *this;
}

SR_Point3D &SR_Point3D::operator=(const QPointF &p)
{
    this->x.SetValue(p.x());
    this->y.SetValue(p.y());
    this->z.SetValue(0);
    return *this;
}

S_XYRz::S_XYRz()
    : x(0)
    , y(0)
    , rz(0)
{

}

S_XYRz::S_XYRz(double x, double y, double rz)
    : x(x)
    , y(y)
    , rz(rz)
{

}

S_XYRz::S_XYRz(const S_XYRz &instance)
{
    x = instance.x;
    y = instance.y;
    rz = instance.rz;
}

S_XYRz &S_XYRz::operator=(const S_XYRz &instance)
{
    x = instance.x;
    y = instance.y;
    rz = instance.rz;

    return *this;
}

S_XYRz &S_XYRz::operator=(const S_Point3D &instance)
{
    x = instance.x;
    y = instance.y;
    rz = instance.z;

    return *this;
}

S_RxRyZ::S_RxRyZ()
    : rx(0)
    , ry(0)
    , z(0)
{

}

S_RxRyZ::S_RxRyZ(double rx, double ry, double z)
    : rx(rx)
    , ry(ry)
    , z(z)
{

}

S_RxRyZ::S_RxRyZ(const S_RxRyZ &instance)
{
    rx = instance.rx;
    ry = instance.ry;
    z = instance.z;
}

S_RxRyZ &S_RxRyZ::operator=(const S_RxRyZ &instance)
{
    rx = instance.rx;
    ry = instance.ry;
    z = instance.z;

    return *this;
}

S_RxRyZ &S_RxRyZ::operator=(const S_Point3D &instance)
{
    rx = instance.x;
    ry = instance.y;
    z = instance.z;

    return *this;
}
