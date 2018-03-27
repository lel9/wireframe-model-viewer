#include "add_model_command.h"

#include "exceptions.h"
#include "model_factory.h"

AddModelCommand::AddModelCommand(const char *name):
    filename(name)
{

}

int AddModelCommand::execute()
{
    if (scene.expired())
        throw NoSceneException("add model command");

    ModelFactory modelFactory(filename);

    auto _scene = scene.lock();
    auto model = modelFactory.create();
    _scene->addChild(model);
    return model->getId();
}
