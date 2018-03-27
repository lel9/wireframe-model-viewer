#ifndef SIMPLESCENEFACTORY_H
#define SIMPLESCENEFACTORY_H

#include "scene_factory.h"

class SimpleSceneFactory : public SceneFactory
{
protected:
    shared_ptr<Canvas> canvas;

public:
    SimpleSceneFactory(shared_ptr<Canvas> canv) { canvas = canv; }
    virtual shared_ptr<Scene> create() override;
};

#endif // SIMPLESCENEFACTORY_H
