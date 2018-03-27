#include "scene.h"

void Scene::addChild(const shared_ptr<SceneObject> &child)
{
    children.push_back(child);
}

shared_ptr<SceneObject> Scene::getChild(int id)
{
    shared_ptr<SceneObject> result = nullptr;
    for (auto it = children.begin(); it != children.end() && !result; it++)
        if ((*it)->getId() == id)
            result = (*it);
    return result;
}

void Scene::removeChild(int id)
{
    auto it = children.begin();
    for ( ; it != children.end() && (*it)->getId() != id; it++)
        ;
    if (it != children.end())
        children.erase(it);
}

void Scene::addCamera(const shared_ptr<SceneObject> &obj)
{
    cameras.push_back(static_pointer_cast<Camera>(obj));
}

void Scene::removeCamera(const shared_ptr<SceneObject> &obj)
{
    auto it = cameras.begin();
    for (; it != cameras.end() && (*it).lock() != obj; it++)
        ;

    if (it != cameras.end())
        cameras.erase(it);
}

void Scene::setActiveCamera(int id)
{
    auto it = cameras.begin();
    for (; it != cameras.end() && (*it).lock() && (*it).lock()->getId() != id; it++)
        ;
    if (it != cameras.end())
        activeCamera = *it;
}
