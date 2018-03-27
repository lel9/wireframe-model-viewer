#include "id_creator.h"

IdCreator::IdCreator() :
    id(-1)
{

}

IdCreator &IdCreator::getInstance()
{
    static IdCreator idCreator;
    return idCreator;
}

int IdCreator::nextId()
{
    return ++id;
}

int IdCreator::getLastId()
{
    return id;
}
