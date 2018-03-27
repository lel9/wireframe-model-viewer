#include "add_camera_command.h"


#include "exceptions.h"
#include "camera_factory.h"

AddCameraCommand::AddCameraCommand(const char *name):
    filename(name)
{

}

int AddCameraCommand::execute()
{
    if (scene.expired())
        throw NoSceneException("add camera command");

    CameraFactory cameraFactory(filename);

    auto _scene = scene.lock();
    auto camera = cameraFactory.create();
    _scene->addChild(camera);
    _scene->addCamera(camera);
    _scene->setActiveCamera(camera->getId());
    return camera->getId();
}

