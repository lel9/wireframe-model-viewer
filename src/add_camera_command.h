#ifndef ADDCAMERACOMMAND_H
#define ADDCAMERACOMMAND_H

#include "scene_command.h"

class AddCameraCommand : public SceneCommand
{
protected:
    const char *filename;
public:
    AddCameraCommand(const char *name);

    virtual int execute() override;

};
#endif // ADDCAMERACOMMAND_H
