#include "composite_object.h"

#include "matrix_set.h"


CompositeObject::CompositeObject()
{

}

void CompositeObject::addChild(const shared_ptr<SceneObject> &child)
{
    children.push_back(child);
}

shared_ptr<SceneObject> CompositeObject::getChild(int id)
{
    shared_ptr<SceneObject> result = nullptr;
    for (auto it = begin(); it != end() && !result; it++)
        if ((*it)->getId() == id)
            result = (*it);
    return result;
}

void CompositeObject::removeChild(int id)
{
    auto it = begin();
    for (; it != end() && (*it)->getId() != id; it++)
        ;
    if (it != end())
        children.erase(it);
}

vector<shared_ptr<GraphicsItems>> CompositeObject::geometryPrimitives
    (const Matrix &pv, const Matrix &m)
{
    vector<shared_ptr<GraphicsItems>> result;

    Matrix curModel = m * MatrixShift(getPosition()).create();
    for (auto it = begin(); it != end(); it++)
    {
        vector<shared_ptr<GraphicsItems>> tmp = (*it)->geometryPrimitives(pv, curModel);
        for (auto item = tmp.begin(); item < tmp.end(); item++)
            result.push_back(*item);
    }

    return result;
}

void CompositeObject::transform(const Matrix &mat4)
{
    for (auto it = begin(); it != end(); it++)
        (*it)->transform(mat4);
}

vector<shared_ptr<SceneObject>>::iterator CompositeObject::begin()
{
    return children.begin();
}

vector<shared_ptr<SceneObject>>::iterator CompositeObject::end()
{
    return children.end();
}
