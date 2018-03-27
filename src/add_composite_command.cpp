#include "add_composite_command.h"
#include "composite_factory.h"
#include "exceptions.h"

AddCompositeCommand::AddCompositeCommand()
{

}

AddCompositeCommand::AddCompositeCommand(const char **names, int n) :
    filenames(names), count(n)
{

}

int AddCompositeCommand::execute()
{
    if (scene.expired())
        throw NoSceneException("add model command");

    CompositeFactory compositeFactory(filenames, count);

    auto _scene = scene.lock();
    auto composition = compositeFactory.create();
    _scene->addChild(composition);
    return composition->getId();
}


