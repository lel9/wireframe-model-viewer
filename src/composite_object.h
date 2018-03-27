#ifndef COMPOSITE_OBJECT_H
#define COMPOSITE_OBJECT_H

#include "scene_object.h"

class CompositeObject : public SceneObject
{
protected:
    vector<shared_ptr<SceneObject>> children;
public:
    CompositeObject();

    virtual void addChild(const shared_ptr<SceneObject> &child) override;
    virtual shared_ptr<SceneObject> getChild(int id) override;
    virtual void removeChild(int id) override;

    virtual vector<shared_ptr<GraphicsItems>> geometryPrimitives
        (const Matrix &pv, const Matrix &m = Matrix()) override;
    virtual void transform(const Matrix &matrix) override;

    virtual vector<shared_ptr<SceneObject>>::iterator begin() override;
    virtual vector<shared_ptr<SceneObject>>::iterator end() override;
};

#endif // COMPOSITE_OBJECT_H
