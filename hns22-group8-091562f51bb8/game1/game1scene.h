
#ifndef GAME1SCENE_H
#define GAME1SCENE_H
#include <QGraphicsItem>

#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QGraphicsView>
#include "arrow.h"
#include "shot.h"
#include "virus.h"
#include "needle.h"
#include<QObject>
#include<QTimer>
#include<QGraphicsView>
#include <QGraphicsPixmapItem>
#include"score.h"

class game1scene : public QGraphicsScene
{
    Q_OBJECT
public:
    game1scene();
    arrow *arrow1; //!< a arrow object
    shot *shot1;
    needle *needle1;
    virus *virus1,*virus2;
    QTimer *listeningTimer;
    score *scoreBoard;
    int lastVirusDied =2;
private:
    //members:

    //methods:
    void UpdateScore(QString size);


signals:
    void  Victory();
    void  Lost();

public slots:
    void checkVirus();
    void VMissed();
void rollarr();
};

#endif // GAME1SCENE_H
