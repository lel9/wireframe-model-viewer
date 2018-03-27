#ifndef GRAPHICSITEMS_H
#define GRAPHICSITEMS_H

#include "canvas.h"
#include <memory>
using namespace std;

class GraphicsItems
{
public:
    GraphicsItems() = default;
    virtual ~GraphicsItems() = default;

    virtual void drawItem(shared_ptr<Canvas> &) = 0;
};

class Line : public GraphicsItems
{
private:
    float X1, Y1, X2, Y2;

public:
    Line(float x1, float y1, float x2, float y2) : X1(x1), Y1(y1), X2(x2), Y2(y2) { }

    virtual void drawItem(shared_ptr<Canvas> &canvas) override
    {
        float w = canvas->width(),
              h = canvas->height(),
              dx = 1 / w,
              dy = 1 / h;

        float x1 = (X1) / dx,
              y1 = h - (Y1) / dy,
              x2 = (X2) / dx,
              y2 = h - (Y2) / dy;

        canvas->drawLine(x1, y1, x2, y2);
    }
};

#endif // GRAPHICSITEMS_H
