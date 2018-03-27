#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
protected:
    static const int size = 4;
    float data[size][size];

public:
    Matrix();
    Matrix(float matrix[size][size]);
    Matrix(float i11, float i22, float i33, float i44);
    Matrix(const Matrix &origin);

    ~Matrix();

    Matrix &operator=(const Matrix &origin);

    Matrix &operator+=(const Matrix &other);
    Matrix &operator*=(const Matrix &other);

    Matrix operator+(const Matrix &other) const;
    Matrix operator*(const Matrix &other) const;

    float operator()(int i, int j) const;
    float &operator()(int i, int j);
};

#endif // MATRIX_H
