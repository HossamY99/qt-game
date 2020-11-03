#ifndef VICTORY_H
#define VICTORY_H

#include <QObject>
#include <QWidget>
#include<QtWidgets>

class Victory : public QGraphicsScene
{
    Q_OBJECT
public:
    Victory();
    QLabel *winL ;
};

#endif // VICTORY_H
