#include "matrix_set.h"

#include <cmath>



Matrix MatrixShift::create()
{
    Matrix result(1, 1, 1, 1);
    result(3, 0) = move.x();
    result(3, 1) = move.y();
    result(3, 2) = move.z();
    result(3, 3) = 1;
    return result;
}

Matrix MatrixScale::create()
{
    Matrix result;
    result(0, 0) = factors.x();
    result(1, 1) = factors.y();
    result(2, 2) = factors.z();
    result(3, 3) = 1;
    return result;
}

Matrix MatrixRotateX::create()
{
    Matrix result;
    result(0, 0) = 1;
    result(1, 1) = cos(angle);
    result(1, 2) = sin(angle);
    result(2, 1) = -sin(angle);
    result(2, 2) = cos(angle);
    result(3, 3) = 1;
    return result;
}

Matrix MatrixRotateY::create()
{
    Matrix result;
    result(1, 1) = 1;
    result(0, 0) = cos(angle);
    result(0, 2) = -sin(angle);
    result(2, 0) = sin(angle);
    result(2, 2) = cos(angle);
    result(3, 3) = 1;
    return result;
}

Matrix MatrixRotateZ::create()
{
    Matrix result;
    result(2, 2) = 1;
    result(1, 1) = cos(angle);
    result(1, 0) = -sin(angle);
    result(0, 1) = sin(angle);
    result(0, 0) = cos(angle);
    result(3, 3) = 1;
    return result;
}

Matrix MatrixView::create()
{
    Coords3D zaxis = (lookAt - position).getNormalized();
    Coords3D xaxis = zaxis.getCross(up).getNormalized();
    Coords3D yaxis = zaxis.getCross(xaxis);

    float mat[4][4] = {{xaxis.x(), xaxis.y(), xaxis.z(), xaxis.getDot(position)},
                       {yaxis.x(), yaxis.y(), yaxis.z(), yaxis.getDot(position)},
                       {zaxis.x(), zaxis.y(), zaxis.z(), zaxis.getDot(position)},
                       {0, 0, 0, 1}};

    Matrix result (mat);

    return result;
}

Matrix MatrixOrthographicProjection::create()
{
    Matrix result;
    result(0, 0) = 1;
    result(1, 1) = 1;
    result(3, 3) = 1;
    return result;
}

Matrix MatrixPerspectiveProjection::create()
{
    Matrix result;
    result(0, 0) = atan(FOVx / 2);
    result(1, 1) = atan(FOVy / 2);
    result(2, 2) = -(farZ + nearZ) / (farZ - nearZ);
    result(3, 2) = -(2 * farZ*nearZ) / (farZ - nearZ);
    result(2, 3) = -1;
    result(3, 3) = 0;
    return result;
}
