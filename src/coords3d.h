#ifndef COORDS3D_H
#define COORDS3D_H

#include "matrix.h"

class Coords3D
{
private:
    static const int size = 4;
    float data[size];
public:
    Coords3D();
    Coords3D(float x, float y, float z, float w = 1);
    Coords3D(const Coords3D &origin);

    ~Coords3D();

    float x() const { return data[0]; }
    float y() const { return data[1]; }
    float z() const { return data[2]; }
    float w() const { return data[3]; }

    void setX(float x) { data[0] = x; }
    void setY(float y) { data[1] = y; }
    void setZ(float z) { data[2] = z; }
    void setW(float w) { data[3] = w; }

    float length();

    void normalize();
    Coords3D getNormalized();

    void transform(const Matrix &m);
    Coords3D getTransformed(const Matrix &m);

    void cross(const Coords3D &other);
    Coords3D getCross(const Coords3D &other);

    float getDot(const Coords3D &other);

    Coords3D &operator=(const Coords3D &origin);

    Coords3D operator-(const Coords3D &other) const;
    Coords3D operator-() const;
};

#endif // COORDS3D_H
