#include "composite_factory.h"
#include "id_creator.h"
#include "camera_factory.h"
#include "model_factory.h"
#include "exceptions.h"

CompositeFactory::CompositeFactory(const char **names, int n) :
    filenames(names), count(n)
{

}

char CompositeFactory::readObjType(unique_ptr<FileReader> &reader)
{
    bool eof;
    char type = reader->readChar(eof);
    if (eof)
        throw ReaderException("type");
    return type;
}

shared_ptr<SceneObject> CompositeFactory::create()
{
    composite = make_unique<CompositeObject>();

    for(int i = 0; i < count; i++)
    {
        unique_ptr<FileReader> reader(make_unique<FileReader>(filenames[i]));
        char type = readObjType(reader);
        if (type == 'c')
            composite->addChild(CameraFactory(filenames[i]).create());
        else if (type == 'm')
            composite->addChild(ModelFactory(filenames[i]).create());
        else
            throw ReaderException("type");
    }

    composite->setId(IdCreator::getInstance().nextId());
    return std::move(composite);
}

