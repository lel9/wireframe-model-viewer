#ifndef SCENEMANAGET_H
#define SCENEMANAGET_H

#include <memory>
#include <utility>
#include <vector>
using namespace std;

#include "scene.h"

class SceneManager
{

private:
    vector<shared_ptr<Scene>> scenes;
    weak_ptr<Scene> activeScene;

public:
    SceneManager(const SceneManager &) = delete;
    SceneManager &operator=(const SceneManager &) = delete;

    static SceneManager &getInstance();

    void addScene(const shared_ptr<Scene> &scene);
    void replaceActiveScene(const shared_ptr<Scene> &scene);
    void replaceActiveScene(int id);

    shared_ptr<Scene> getActiveScene();
    void removeScene(int id);

    const vector<shared_ptr<Scene>> &getScenes();

    void drawActiveScene();
    void clear();

private:
    SceneManager();
};

#endif // SCENEMANAGET_H
