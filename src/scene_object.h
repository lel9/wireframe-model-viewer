#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H


#include <memory>
#include <vector>
using namespace std;

#include "coords3d.h"
#include "graphics_items.h"


class SceneObject
{
protected:
    int idObj;
    Coords3D position;

public:
    SceneObject() { }
    virtual ~SceneObject() { }

    virtual void setId(int id) { idObj = id; }
    virtual int getId() { return idObj; }

    virtual void setPosition(const Coords3D &pos) { position = pos; }
    virtual const Coords3D &getPosition() { return position; }

    virtual void addChild(const shared_ptr<SceneObject> &) = 0;
    virtual shared_ptr<SceneObject> getChild(int ) = 0;
    virtual void removeChild(int ) = 0;

    virtual vector<shared_ptr<GraphicsItems>> geometryPrimitives
        (const Matrix &pv, const Matrix &m = Matrix(1,1,1,1)) = 0;
    virtual void transform(const Matrix &m) = 0;

    virtual vector<shared_ptr<SceneObject>>::iterator begin() = 0;
    virtual vector<shared_ptr<SceneObject>>::iterator end() = 0;
};
#endif // SCENEOBJECT_H
