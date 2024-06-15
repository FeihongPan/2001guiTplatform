#ifndef POINT_H
#define POINT_H

#include "TCommonLib_global.h"
#include "tvalue.h"

class SR_Point2D;

class TCOMMONLIB_EXPORT S_Point2D : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, x)
    QS_FIELD(double, y)

public:
    S_Point2D();
    S_Point2D(double x, double y);
    S_Point2D(const QPointF &p);
    S_Point2D &operator=(const SR_Point2D &p);
    S_Point2D &operator=(const QPointF &p);
    S_Point2D &operator+=(const S_Point2D &p);
    S_Point2D operator+(const S_Point2D &p);

    QList<double> ToDoubleList();

    /// <summary>
    /// 获取坐标字符串
    /// </summary>
    /// <param name="nF">浮点数格式 'g':科学计数法 'f':浮点数</param>
    /// <param name="nPrec">保留小数位数</param>
    /// <returns>字符串格式坐标，“(x, y)”</returns>
    QString ToString(char nF = 'f', int nPrec = 6) const;
};

class TCOMMONLIB_EXPORT SR_Point2D : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TDouble, x)
    QS_OBJECT(TDouble, y)

public:
    SR_Point2D();
    SR_Point2D(const SR_Point2D &p);
    SR_Point2D(const QPointF &p);
    SR_Point2D &operator=(const SR_Point2D &p);
    SR_Point2D &operator=(const S_Point2D &p);
    SR_Point2D &operator=(const QPointF &p);
};

class SR_Point3D;

class TCOMMONLIB_EXPORT S_Point3D : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, x)
    QS_FIELD(double, y)
    QS_FIELD(double, z)

public:
    S_Point3D();
    S_Point3D(double x, double y, double z);
    S_Point3D &operator=(const S_Point3D &p);
    S_Point3D &operator=(const SR_Point3D &p);
    S_Point3D &operator+=(const S_Point3D &p);
    S_Point3D operator+(const S_Point3D &p);

    QList<double> ToDoubleList();
};

class TCOMMONLIB_EXPORT SR_Point3D : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(TDouble, x)
    QS_OBJECT(TDouble, y)
    QS_OBJECT(TDouble, z)

public:
    SR_Point3D();
    SR_Point3D(const SR_Point3D &p);
    SR_Point3D &operator=(const SR_Point3D &p);
    SR_Point3D &operator=(const S_Point3D &p);
    SR_Point3D &operator=(const SR_Point2D &p);
    SR_Point3D &operator=(const S_Point2D &p);
    SR_Point3D &operator=(const QPointF &p);
};

class TCOMMONLIB_EXPORT S_XYRz : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, x)
    QS_FIELD(double, y)
    QS_FIELD(double, rz)

public:
    S_XYRz();
    S_XYRz(double x, double y, double rz);
    S_XYRz(const S_XYRz &instance);
    S_XYRz &operator=(const S_XYRz &instance);
    S_XYRz &operator=(const S_Point3D &p);
};

class TCOMMONLIB_EXPORT S_RxRyZ : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(double, rx)
    QS_FIELD(double, ry)
    QS_FIELD(double, z)

public:
    S_RxRyZ();
    S_RxRyZ(double rx, double ry, double z);
    S_RxRyZ(const S_RxRyZ &instance);
    S_RxRyZ &operator=(const S_RxRyZ &instance);
    S_RxRyZ &operator=(const S_Point3D &p);
};

#endif // POINT_H
