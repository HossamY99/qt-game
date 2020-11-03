
#include <QApplication>
#include <QGraphicsItem>
#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QGraphicsView>
#include "game1scene.h"
#include "startg1.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    startg1 *st = new startg1();
    st->show();

    return app.exec();
}
