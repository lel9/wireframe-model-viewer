#ifndef SCENE_H
#define SCENE_H


#include <memory>
#include <utility>
#include <vector>
using namespace std;

#include "scene_object.h"
#include "camera.h"

class Scene
{
protected:
    int idScene;
    vector<shared_ptr<SceneObject>> children;
    vector<weak_ptr<Camera>> cameras;
    weak_ptr<Camera> activeCamera;

public:
    Scene() = default;
    virtual ~Scene() = default;

    virtual void setId(int id) { idScene = id; }
    virtual int getId() { return idScene; }

    virtual void addChild(const shared_ptr<SceneObject> &child);
    virtual shared_ptr<SceneObject> getChild(int id);
    virtual void removeChild(int id);

    virtual void addCamera(const shared_ptr<SceneObject> &obj);
    virtual void removeCamera(const shared_ptr<SceneObject> &obj);
    virtual void setActiveCamera(int id);

    virtual void draw() = 0;

    virtual vector<shared_ptr<SceneObject>>::iterator begin() { return children.begin(); }
    virtual vector<shared_ptr<SceneObject>>::iterator end()   { return children.end();   }
};

#endif // SCENE_H
