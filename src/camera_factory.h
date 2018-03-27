#ifndef CAMERAFACTORY_H
#define CAMERAFACTORY_H


#include "file_reader.h"
#include "scene_object_factory.h"
#include "camera.h"

class CameraFactory : public SceneObjectFactory
{
protected:
    unique_ptr<FileReader> reader;

public:
    CameraFactory(const char *filename);

    virtual shared_ptr<SceneObject> create() override;

protected:
    void readObjType();
    void readView();
    Coords3D readPosition();
    Coords3D readLookAt();
    char readType();
    void readPespective();
    void readOrthographic();

    unique_ptr<Camera> camera;
};

#endif // CAMERAFACTORY_H
