#ifndef MATRIX_SET_H
#define MATRIX_SET_H

#include "matrix.h"
#include "coords3d.h"

class MatrixFactory
{
public:
    MatrixFactory() = default;
    virtual ~MatrixFactory() = default;
    virtual Matrix create() = 0;
};

class MatrixShift : public MatrixFactory
{
protected:
    Coords3D move;
public:
    MatrixShift(const Coords3D &mv) { move = mv; }
    virtual Matrix create() override;
};

class MatrixScale : public MatrixFactory
{
protected:
    Coords3D factors;
public:
    MatrixScale(const Coords3D &f) { factors = f; }
    virtual Matrix create() override;
};

class MatrixRotateX : public MatrixFactory
{
protected:
    float angle;
public:
    MatrixRotateX(const float a) { angle = a; }
    virtual Matrix create() override;
};

class MatrixRotateY : public MatrixFactory
{
protected:
    float angle;
public:
    MatrixRotateY(const float a) { angle = a; }
    virtual Matrix create() override;
};

class MatrixRotateZ : public MatrixFactory
{
protected:
    float angle;
public:
    MatrixRotateZ(const float a) { angle = a; }
    virtual Matrix create() override;
};

class MatrixView : public MatrixFactory
{
protected:
    Coords3D position;
    Coords3D lookAt;
    Coords3D up;
public:
    MatrixView(const Coords3D &pos, const Coords3D &l, const Coords3D &u = Coords3D(0, 1, 0))
    {
        position = pos;
        lookAt = l;
        up = u;
    }
    virtual Matrix create() override;
};

class MatrixOrthographicProjection : public MatrixFactory
{
public:
    virtual Matrix create() override;
};

class MatrixPerspectiveProjection : public MatrixFactory
{
protected:
    float FOVx;
    float FOVy;
    float nearZ;
    float farZ;
public:
    MatrixPerspectiveProjection(float Fx, float Fy, float nZ, float fZ)
    {
        FOVx = Fx;
        FOVy = Fy;
        nearZ = nZ;
        farZ = fZ;
    }

    virtual Matrix create() override;
};

#endif // MATRIXF_SET_H
