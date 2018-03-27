#include "simplescenefactory.h"
#include "simple_scene.h"

#include "id_creator.h"

shared_ptr<Scene> SimpleSceneFactory::create()
{
    unique_ptr<SimpleScene> scene = make_unique<SimpleScene>(canvas);
    scene->setId(IdCreator::getInstance().nextId());
    return std::move(scene);
}


