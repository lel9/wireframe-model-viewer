#ifndef QTCANVAS_H
#define QTCANVAS_H

#include <QGraphicsScene>

#include "canvas.h"

class QtCanvas : public Canvas
{
private:
    QGraphicsScene *scene;
public:
    QtCanvas(QGraphicsScene *sc);

    virtual void drawLine(int x1, int y1, int x2, int y2) override;

    virtual float width() override;
    virtual float height() override;
};

#endif // QTCANVAS_H
