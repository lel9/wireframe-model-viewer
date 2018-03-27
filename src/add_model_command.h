#ifndef ADDMODELCOMMAND_H
#define ADDMODELCOMMAND_H

#include "scene_command.h"

class AddModelCommand : public SceneCommand
{
protected:
    const char *filename;
public:
    AddModelCommand(const char *name);

    virtual int execute() override;
};

#endif // ADDMODELCOMMAND_H
