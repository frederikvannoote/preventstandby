#include "mousemover.h"
#include <QCursor>


MouseMover::MouseMover(QObject *parent):
    QObject(parent)
{

}

void MouseMover::moveMouse()
{
    const QPoint pos = QCursor::pos();

    // Move the mouse
    QPoint alternative = pos;
    alternative.setX(pos.x() + 1);
    QCursor::setPos(alternative);

    // Move it back
    QCursor::setPos(pos);
}
