#ifndef SIMPLE_SCENE_FACTORY_H
#define SIMPLE_SCENE_FACTORY_H

#include "scenefactory.h"

class SimpleSceneFactory : public SceneFactory
{
public:
    virtual shared_ptr<Scene> create() override;
};

#endif // SIMPLE_SCENE_FACTORY_H
