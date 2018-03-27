#include "scene_manager.h"

SceneManager::SceneManager()
{

}

SceneManager &SceneManager::getInstance()
{
    static SceneManager manager;
    return manager;
}

void SceneManager::addScene(const shared_ptr<Scene> &scene)
{
    scenes.push_back(scene);
    activeScene = scene;
}

void SceneManager::replaceActiveScene(const shared_ptr<Scene> &scene)
{
    shared_ptr<Scene> result = nullptr;
    for (auto it = scenes.begin(); it != scenes.end() && !result; it++)
        if ((*it)->getId() == scene->getId())
            result = scene;
    if (result)
        activeScene = result;
    else
        addScene(scene);
}

void SceneManager::replaceActiveScene(int id)
{
    shared_ptr<Scene> result = nullptr;
    for (auto it = scenes.begin(); it != scenes.end() && !result; it++)
        if ((*it)->getId() == id)
            result = (*it);
    if (result)
        activeScene = result;
}

shared_ptr<Scene> SceneManager::getActiveScene()
{
    if (!activeScene.expired())
        return activeScene.lock();
    else
        return nullptr;
}


void SceneManager::removeScene(int id)
{
    auto it = scenes.begin();
    for (; it != scenes.end() && (*it)->getId() != id; it++)
        ;
    if (it != scenes.end())
        scenes.erase(it);
}

void SceneManager::drawActiveScene()
{
    if (!activeScene.expired())
        activeScene.lock()->draw();
}

void SceneManager::clear()
{
    scenes.clear();
    activeScene.reset();
}

