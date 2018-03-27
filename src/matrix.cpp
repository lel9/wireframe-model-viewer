#include "matrix.h"

Matrix::Matrix() : data{0}
{

}

Matrix::Matrix(float matrix[size][size])
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            data[i][j] = matrix[i][j];
}

Matrix::Matrix(float i11, float i22, float i33, float i44) :
    data{{i11, 0, 0, 0},
         {0, i22, 0, 0},
         {0, 0, i33, 0},
         {0, 0, 0, i44},}
{

}

Matrix::Matrix(const Matrix &origin)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            data[i][j] = origin.data[i][j];
}

Matrix &Matrix::operator=(const Matrix &origin)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            data[i][j] = origin.data[i][j];
    return *this;
}

Matrix::~Matrix()
{

}

Matrix &Matrix::operator+=(const Matrix &other)
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            data[i][j] += other.data[i][j];
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &other)
{
    *this = *this * other;
    return *this;
}

Matrix Matrix::operator+(const Matrix &other) const
{
    Matrix result;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

Matrix Matrix::operator*(const Matrix &other) const
{
    Matrix result;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            for(int k = 0; k < size; k++)
                result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
}

float Matrix::operator()(int i, int j) const
{
    return data[i][j];
}

float &Matrix::operator()(int i, int j)
{
    return data[i][j];
}
