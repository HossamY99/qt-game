
#include "shot.h"
#include <stdlib.h>
#include <QTimer>
#include<QGraphicsScene>
#include<QDebug>

shot::shot(QObject *parent) : QObject(parent)
{
    this->setPixmap((QPixmap(":/images/shot.png")).scaled(60,60));
   // this->setPos(200,400);
setTransformOriginPoint(30,30);
setRotation(270);
ss=0;
yy=0;
xx=0;


//shoot();
}

void shot::lineequation(float slope, float yintercept,float xstart)
{

    ss=slope;
    yy=yintercept;
    xx=xstart;
}

void shot::shoot()
{

    timershot=new QTimer(this);
    connect(timershot, SIGNAL(timeout()),this, SLOT(move()) );
    timershot->start(20);

}


void shot::move()
{
    if(!(scene()->collidingItems(this).isEmpty()))
    {
        if(scene()->collidingItems(this).takeLast()->pos().x() == 0 )
        {if(scene()->collidingItems(this).takeLast()->pos().y() >100)
            qDebug("hit");
            delete this;
        }
    }
    if (this->x()-5<0)
    {
        emit VirusMissed();
        scene()->removeItem(this);
        delete this;
    }
    else{
    this->setX(x()-5);
    this->setY(ss*x()+yy);
    }
}

/**
 * \brief
 *
 *
 */
