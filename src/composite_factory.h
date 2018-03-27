#ifndef COMPOSITEFACTORY_H
#define COMPOSITEFACTORY_H

#include "scene_object_factory.h"
#include "composite_object.h"
#include "file_reader.h"

class CompositeFactory : public SceneObjectFactory
{
protected:
    const char **filenames;
    int count;

public:
    CompositeFactory(const char **names, int n);
    char readObjType(unique_ptr<FileReader> &reader);
    virtual shared_ptr<SceneObject> create() override;

protected:
    unique_ptr<SceneObject> composite;
};

#endif // COMPOSITEFACTORY_H
