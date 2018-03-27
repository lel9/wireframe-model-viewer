#include "camera.h"

vector<shared_ptr<GraphicsItems>> Camera::geometryPrimitives
    (const Matrix &, const Matrix &)
{
    vector<shared_ptr<GraphicsItems>> nullVector;
    return nullVector;
}

vector<shared_ptr<SceneObject>>::iterator Camera::begin()
{
    return nullIterator;
}
vector<shared_ptr<SceneObject>>::iterator Camera::end()
{
    return nullIterator;
}
