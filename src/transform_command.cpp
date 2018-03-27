#include "transform_command.h"

#include "matrix_set.h"
#include "exceptions.h"


void ScaleCommand::execute()
{
    if (object.expired())
        throw NoObjectException("Scale command execute");

    Matrix m = MatrixShift(-center).create() *
               MatrixScale(coefs).create() * MatrixShift(center).create();
    object.lock()->transform(m);
}

void ShiftCommand::execute()
{
    if (object.expired())
        throw NoObjectException("Shift command execute");
    Matrix m = MatrixShift(move).create();
    object.lock()->transform(m);
}

void RotateXCommand::execute()
{
    if (object.expired())
        throw NoObjectException("Rotate x command execute");
    Matrix m = MatrixShift(-center).create() *
               MatrixRotateX(angle).create() * MatrixShift(center).create();
    object.lock()->transform(m);
}

void RotateYCommand::execute()
{
    if (object.expired())
        throw NoObjectException("Rotate y command execute");
    Matrix m = MatrixShift(-center).create() *
               MatrixRotateY(angle).create() * MatrixShift(center).create();
    object.lock()->transform(m);
}

void RotateZCommand::execute()
{
    if (object.expired())
        throw NoObjectException("Rotate z command execute");
    Matrix m = MatrixShift(-center).create() *
               MatrixRotateZ(angle).create() * MatrixShift(center).create();
    object.lock()->transform(m);
}
