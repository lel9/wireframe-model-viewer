#include "qt_canvas.h"

QtCanvas::QtCanvas(QGraphicsScene *sc):
    scene(sc)
{

}

void QtCanvas::drawLine(int x1, int y1, int x2, int y2)
{
    scene->addLine(x1, y1, x2, y2);
}

float QtCanvas::width()
{
    return 1280;
}

float QtCanvas::height()
{
    return 1280;
}

