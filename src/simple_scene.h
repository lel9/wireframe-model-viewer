#ifndef SIMPLESCENE_H
#define SIMPLESCENE_H

#include "scene.h"
#include "canvas.h"

class SimpleScene : public Scene
{
private:
    shared_ptr<Canvas> canvas;

public:
    SimpleScene(const shared_ptr<Canvas> &canv) { canvas = canv; }

    void SetCanvas(const shared_ptr<Canvas> &canv) { canvas = canv; }
    const shared_ptr<Canvas> getCanvas() { return canvas; }
    virtual void draw() override;
};

#endif // SIMPLESCENE_H
