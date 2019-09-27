#include "config.h"
#include "mousemover.h"
#include "planner.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Config w;
//    w.show();

    Planner planner;
    planner.addActivePeriod(QTime(8, 0, 0), QTime(17, 0, 0));

    MouseMover mover;
    QObject::connect(&planner, &Planner::tick, &MouseMover::moveMouse);

    return a.exec();
}
