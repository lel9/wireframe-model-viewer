#include "simple_scene.h"
#include "exceptions.h"

void SimpleScene::draw()
{
    if ((activeCamera).expired())
        throw NoObjectException("no camera");

    Matrix pv = (activeCamera).lock()->getPVMatrix() ;
    for (auto child = children.begin(); child != children.end(); child++)
    {
        vector<shared_ptr<GraphicsItems>> items = (*child)->geometryPrimitives(pv);
        for (auto item = items.begin(); item < items.end(); item++)
            (*item)->drawItem(canvas);
    }
}

