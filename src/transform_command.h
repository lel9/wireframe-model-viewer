#ifndef TRANSFORMCOMMAND_H
#define TRANSFORMCOMMAND_H


#include <memory>
#include <utility>
using namespace std;

#include "matrix.h"
#include "coords3d.h"
#include "scene_object.h"

class TransformCommand
{
protected:
    weak_ptr<SceneObject> object;
public:
    TransformCommand() = default;
    virtual ~TransformCommand() = default;
    void setObject(const weak_ptr<SceneObject> obj) { object = obj; }
    virtual void execute() = 0;
};

class ScaleCommand : public TransformCommand
{
private:
    Coords3D center;
    Coords3D coefs;
public:
    ScaleCommand(const Coords3D &cntr, const Coords3D &cfs) : center(cntr), coefs(cfs) {}
    virtual void execute() override;
};

class ShiftCommand : public TransformCommand
{
private:
    Coords3D move;
public:
    ShiftCommand(const Coords3D &mv) : move(mv) {}
    virtual void execute() override;
};

class RotateXCommand : public TransformCommand
{
private:
    Coords3D center;
    float angle;
public:
    RotateXCommand(const Coords3D &cntr, const float &ang) : center(cntr), angle(ang) {}
    virtual void execute() override;
};

class RotateYCommand : public TransformCommand
{
private:
    Coords3D center;
    float angle;
public:
    RotateYCommand(const Coords3D &cntr, const float &ang) : center(cntr), angle(ang) {}
    virtual void execute() override;
};

class RotateZCommand : public TransformCommand
{
private:
    Coords3D center;
    float angle;
public:
    RotateZCommand(const Coords3D &cntr, const float &ang) : center(cntr), angle(ang) {}
    virtual void execute() override;
};

#endif // TRANSFORMCOMMAND_H
