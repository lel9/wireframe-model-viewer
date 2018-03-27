#include "coords3d.h"

#include <cmath>

Coords3D::Coords3D() :
    data{0, 0, 0, 1}
{

}

Coords3D::Coords3D(float x, float y, float z, float w) :
    data{x, y, z, w}
{

}

Coords3D::Coords3D(const Coords3D &origin)
{
    for (int i = 0; i < size; i++)
        data[i] = origin.data[i];
}

Coords3D::~Coords3D()
{

}

void Coords3D::normalize()
{
    Coords3D result;
    result.data[0] /= length();
    result.data[1] /= length();
    result.data[2] /= length();
    *this = result;
}

Coords3D Coords3D::getNormalized()
{
    Coords3D result(*this);
    result.data[0] /= length();
    result.data[1] /= length();
    result.data[2] /= length();
    return result;
}


void Coords3D::transform(const Matrix &m)
{
    *this = this->getTransformed(m);
}

Coords3D Coords3D::getTransformed(const Matrix &m)
{
    Coords3D result(0, 0, 0, 0);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result.data[i] += m(i, j) * data[j];
    return result;
}

void Coords3D::cross(const Coords3D &other)
{
    *this = this->getCross(other);
}

Coords3D Coords3D::getCross(const Coords3D &other)
{
    Coords3D result;
    result.data[0] = data[1] * other.data[2] - data[2] * other.data[1];
    result.data[1] = data[2] * other.data[0] - data[0] * other.data[2];
    result.data[2] = data[0] * other.data[1] - data[1] * other.data[0];
    return result;
}


float Coords3D::getDot(const Coords3D &other)
{
    float result = 0;
    result += data[0] * other.data[0];
    result += data[1] * other.data[1];
    result += data[2] * other.data[2];
    return result;
}

float Coords3D::length()
{
    float result = 0;
    for (int i = 0; i < size - 1; i++)
        result += data[i] * data[i];
    return sqrt(result);
}

Coords3D& Coords3D::operator=(const Coords3D &origin)
{
    for (int i = 0; i < size; i++)
        data[i] = origin.data[i];
    return *this;
}

Coords3D Coords3D::operator-(const Coords3D &other) const
{
    Coords3D result;
    for (int i = 0; i < size; i++)
        result.data[i] = data[i] - other.data[i];
    return result;
}

Coords3D Coords3D::operator-() const
{
    Coords3D result;
    for (int i = 0; i < size; i++)
        result.data[i] = -data[i];
    return result;
}

