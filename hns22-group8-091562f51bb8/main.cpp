#include <QApplication>
#include "mainwidget.h"

int main(int argc, char **argv) {
    QApplication app (argc, argv);

    mainwidget * widg=new mainwidget;


    widg->show();

    return app.exec();
}
