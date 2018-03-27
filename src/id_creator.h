#ifndef IDCREATOR_H
#define IDCREATOR_H


class IdCreator
{
private:
    int id;

public:
    static IdCreator &getInstance();

    int nextId();
    int getLastId();

    IdCreator(const IdCreator &) = delete;
    IdCreator &operator=(const IdCreator &) = delete;

private:
    IdCreator();
};
#endif // IDCREATOR_H
