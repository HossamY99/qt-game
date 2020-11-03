
#include "arrow.h"
#include "shot.h"
#include <QGraphicsPixmapItem>
#include<QDebug>
#include<QGraphicsScene>
#include <cmath>
#include<QtMath>

arrow::arrow(QObject *parent) : QObject(parent)
{
    this->setPixmap((QPixmap(":/images/arrow.png")).scaled(140,60));
    this->setPos(200,400);
    setFlag(QGraphicsItem :: ItemIsFocusable);

    setFocus();
    degrees=0;
    direction=1;
    speedIncreased =0;
    setTransformOriginPoint(140,30);
    setRotation(0);
    temp=new QTimer();
    rolltime=40;
    wait=new QTimer();
    connect(wait, SIGNAL(timeout()),this, SLOT(waitfun()) );

}
void arrow::CheckShot(){
    qDebug("missed");
    emit VirusMissed();
}
void arrow::startroll()
{

    connect(temp, SIGNAL(timeout()),this, SLOT(roll()) );
    temp->start(rolltime);

}

void arrow::increasespeed(){
    if (rolltime>10)
    {
        temp->setInterval(temp->interval()/2);

    }
    else{}
}

void arrow::roll()
{

//qDebug()<<this->scenePos();
  //  qDebug()<<"still";
    if (direction==1)
    {
               degrees=degrees+2;
                if (degrees<70)
                {
                    this->setRotation(degrees);

                }
                else{
                    degrees=degrees-4;
                    this->setRotation(degrees);
                    direction=-1;
                    }

       }





    else {          //direction==-1

        degrees=degrees-2;
                if (degrees>-70)
                {
                    this->setRotation(degrees);
                }
                else{
                    degrees=degrees+4;
                    this->setRotation(degrees);
                    direction=1;
                    }

    }

}





void arrow::keyPressEvent(QKeyEvent *event)
{
    clearFocus();
    temp->stop();
    wait->start(700);

    if (event->key()==Qt::Key_Space)
    {
       // temp->stop();
        this->setRotation(degrees);
        shot *sh1= new shot();
        //sh1->setTransformOriginPoint(120,60);
        //sh1->setRotation(degrees);
        float xnew=340-140*cos(degrees*3.14159/180);// 200+140
        float ynew=430-140*sin(degrees*3.14159/180);//400+30


        sh1->setPos(xnew,ynew);
        scene()->addItem(sh1);


        float slope= (430-ynew)/(340-xnew);
        float yintercept=430-slope*340; //origin point
        sh1->lineequation(slope,yintercept,xnew);
        sh1->shoot();
         QObject::connect(sh1, SIGNAL(VirusMissed()), this, SLOT(CheckShot()));

    }
}

void arrow::waitfun()
{
    this->setFocus();
    temp->start();
    wait->stop();

}
