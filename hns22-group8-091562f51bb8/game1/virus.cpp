#include "virus.h"
#include <QGraphicsPixmapItem>
#include<QDebug>
#include<QGraphicsScene>
#include<iostream>
using namespace std;


virus::virus(QObject *parent) : QObject(parent)
{
    srand(time(0));
    size = variousSizes[rand()%3];

    listeningTimer = new QTimer();
    QObject::connect(listeningTimer, SIGNAL(timeout()), this, SLOT(checkVaccine()));
    listeningTimer->start(10);

}
void virus:: checkVaccine(){
    if (!(scene()->collidingItems(this).isEmpty()) && isDead ==false){

        isDead = true;
    }
    if(isDead)
     {
        if(size=="S")
          this->setPixmap((QPixmap(":/images/virusSmallDead.png")).scaled(50,50));
        else if(size=="M")
          this->setPixmap((QPixmap(":/images/virusMediumDead.png")).scaled(75,75 ));
        else if(size=="L")
          this->setPixmap((QPixmap(":/images/virusLargeDead.png")).scaled(100,100));
        emit updateVirus();
    }
}
void virus::generateRandomVirus()
{
    int x =rand()%3;
    size = variousSizes[x];

    if(size=="S")
      this->setPixmap((QPixmap(":/images/virusSmall.png")).scaled(50,50));
    else if(size=="M")
      this->setPixmap((QPixmap(":/images/virusMedium.png")).scaled(75,75 ));
    else if(size=="L")
      this->setPixmap((QPixmap(":/images/virusLarge.png")).scaled(100,100 ));
    this->setPos(0,100+rand()%800);


}
