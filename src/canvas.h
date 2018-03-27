#ifndef CANVAS_H
#define CANVAS_H


class Canvas
{
public:
    Canvas() = default;
    virtual ~Canvas() = default;

    virtual void drawLine(int x1, int y1, int x2, int y2) = 0;
    virtual float width() = 0;
    virtual float height() = 0;
};

#endif // CANVAS_H
