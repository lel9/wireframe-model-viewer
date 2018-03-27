#ifndef MODELFACTORY_H
#define MODELFACTORY_H


#include "file_reader.h"
#include "scene_object_factory.h"
#include "model.h"

class ModelFactory : public SceneObjectFactory
{
protected:
    unique_ptr<FileReader> reader;

public:
    ModelFactory(const char *filename);
    virtual shared_ptr<SceneObject> create() override;

protected:
    void readObjType();
    Coords3D readPosition();
    void readItems();
    Edge readEdge();
    Coords3D readVertex();

    unique_ptr <Model> model;
};

#endif // MODELFACTORY_H
