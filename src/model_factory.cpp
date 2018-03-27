#include "model_factory.h"

#include "exceptions.h"
#include "base_file_reader.h"
#include "id_creator.h"


ModelFactory::ModelFactory(const char *filename) :
    reader(make_unique<FileReader>(filename))
{

}

shared_ptr<SceneObject> ModelFactory::create()
{
    model = make_unique<Model>();

    readObjType();
    Coords3D pos = readPosition();
    model->setPosition(pos);
    readItems();

    model->setId(IdCreator::getInstance().nextId());

    return std::move(model);
}

void ModelFactory::readObjType()
{
    bool eof;
    char t = reader->readChar(eof);
    if (eof)
        throw ReaderException("type");
    if (t != 'm')
        throw ReaderException("type");
}

Coords3D ModelFactory::readPosition()
{
    bool eof;
    int v1 = reader->readFloat(eof);
    int v2 = reader->readFloat(eof);
    int v3 = reader->readFloat(eof);
    if (eof)
        throw ReaderException("model position");
    return Coords3D(v1, v2, v3);
}

void ModelFactory::readItems()
{
    bool eof = false;
    char current = reader->readChar(eof);

    while (!eof)
    {
        if (current == 'e')
            model->addEdge(readEdge());
        else if (current == 'v')
            model->addVertex(readVertex());
        else if (!isspace(current))
            throw ReaderException("model items");
        current = reader->readChar(eof);
    }
}


Edge ModelFactory::readEdge()
{
    bool eof;
    int e1 = reader->readInt(eof);
    int e2 = reader->readInt(eof);
    if (eof)
        throw ReaderException("model edge");
    return(Edge(e1-1, e2-1));
}

Coords3D ModelFactory::readVertex()
{
    bool eof;
    float v1 = reader->readFloat(eof);
    float v2 = reader->readFloat(eof);
    float v3 = reader->readFloat(eof);
    if (eof)
        throw ReaderException("model vertex");
    return(Coords3D(v1, v2, v3));
}

