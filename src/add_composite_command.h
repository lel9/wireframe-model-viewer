#ifndef ADDCOMPOSITECOMMAND_H
#define ADDCOMPOSITECOMMAND_H

#include "scene_command.h"

class AddCompositeCommand : public SceneCommand
{
protected:
    const char **filenames;
    int count;
public:
    AddCompositeCommand();
    AddCompositeCommand(const char **names, int n);

    virtual int execute() override;
};

#endif // ADDCOMPOSITECOMMAND_H
