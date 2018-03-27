#ifndef SCENECOMMAND_H
#define SCENECOMMAND_H

#include "scene.h"

class SceneCommand
{
protected:
    weak_ptr<Scene> scene;
public:
    SceneCommand() = default;
    virtual ~SceneCommand() = default;

    virtual void setScene(const shared_ptr<Scene> &sc) { scene = sc; }
    virtual int execute() = 0;
};


#endif // SCENECOMMAND_H
