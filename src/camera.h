#ifndef CAMERA_H
#define CAMERA_H

#include "scene_object.h"
#include "matrix_set.h"

class Camera : public SceneObject
{
protected:
    Matrix viewMatrix;
    Matrix projectionMatrix;
    Coords3D look_At;

    vector<shared_ptr<SceneObject>>::iterator nullIterator;

public:
    Camera() { }
    ~Camera() { }

    void setProjectionMatrix(const Matrix &m) { projectionMatrix = m; }
    void lookAt(const Coords3D &pos) {look_At = pos; setViewMatrix(); }
    Matrix getPVMatrix() { return projectionMatrix * viewMatrix; }

    virtual void addChild(const shared_ptr<SceneObject> &) override { }
    virtual shared_ptr<SceneObject> getChild(int ) override { return nullptr; }
    virtual void removeChild(int ) { }

    virtual vector<shared_ptr<GraphicsItems>> geometryPrimitives
           (const Matrix &, const Matrix &) override;
    virtual void transform(const Matrix &m) override { position.transform(m); }

    virtual vector<shared_ptr<SceneObject>>::iterator begin() override;
    virtual vector<shared_ptr<SceneObject>>::iterator end() override;

protected:
    void setViewMatrix() { viewMatrix = MatrixView(position, look_At).create(); }
};

#endif // CAMERA_H
