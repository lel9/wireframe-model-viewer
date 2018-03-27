#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include <memory>
using namespace std;

#include "scene.h"

class SceneFactory
{
public:
    SceneFactory() = default;
    virtual ~SceneFactory() = default;
    virtual shared_ptr<Scene> create() = 0;
};

#endif // SCENEFACTORY_H
