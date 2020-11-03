
#include "game1scene.h"
#include <QTimer>
#include <iostream>
#include<QThread>


game1scene::game1scene()
{
    arrow1= new arrow();
    addItem(arrow1);

    shot1=new shot();
    //addItem(shot1);


    needle1=new needle();
    addItem(needle1);

    virus1=new virus();
    virus1->generateRandomVirus();
    addItem(virus1);

    virus2=new virus();
    virus2->generateRandomVirus();
    virus2->setVisible(false);
    addItem(virus2);

    scoreBoard = new score();
    scoreBoard->setGeometry(0,0,400,100);
    addWidget(scoreBoard);


  setBackgroundBrush(QBrush(QImage(":/images/backg.jpeg")
                              .scaledToHeight(400) .scaledToWidth(1000)));

    setSceneRect(0,0,400,1000);


 arrow1->startroll();

    //QTimer *temp= new QTimer();
    //connect(temp, SIGNAL(timeout()),this, SLOT(rollarr()) );
   // temp->start(30);

 listeningTimer = new QTimer();
 QObject::connect(virus1, SIGNAL(updateVirus()), this, SLOT(checkVirus()));
 QObject::connect(virus2, SIGNAL(updateVirus()), this, SLOT(checkVirus()));
 QObject::connect(arrow1, SIGNAL(VirusMissed()), this, SLOT(VMissed()));
 listeningTimer->start(10);
}

void game1scene::rollarr()
{

    arrow1->startroll();
}
void game1scene:: checkVirus(){



    if (virus1->isDead && !virus2->isVisible()){
        virus2->setVisible(true);
    }
    else if(virus1->isDead && virus2->isDead)
    {


        if(lastVirusDied ==2)
        {
         UpdateScore(virus2->size);
        virus1->isDead =false;
        virus1->generateRandomVirus();}
        else
        {
            UpdateScore(virus1->size);
            virus2->isDead =false;
            virus2->generateRandomVirus();}

            if(lastVirusDied == 1)
                lastVirusDied=2;
            else lastVirusDied=1;
        }

}
 void game1scene::UpdateScore(QString size){

     if(size == "S")
     {
         if(scoreBoard->totalL->text().toInt() < scoreBoard->winningScore)
        {
             scoreBoard->smallCounterL->setText(QString::number(scoreBoard->smallCounterL->text().toInt()+1));
             scoreBoard->totalL->setText(QString::number(scoreBoard->totalL->text().toInt()+3));
             if(scoreBoard->totalL->text().toInt() >= scoreBoard->winningScore)
             {
                 qDebug("Victory");
                 emit Victory();
             }
        }
     }

     else if ((size == "M"))
     {
        if(scoreBoard->totalL->text().toInt()+5 <= scoreBoard->winningScore)
        {
            scoreBoard->mediumCounterL->setText(QString::number(scoreBoard->mediumCounterL->text().toInt()+1));
            scoreBoard->totalL->setText(QString::number(scoreBoard->totalL->text().toInt()+5));
            if(scoreBoard->totalL->text().toInt()  == scoreBoard->winningScore)
            {
                qDebug("Victory");
                emit Victory();
            }
        }

     }
     else if ((size == "L"))
     {
         if(scoreBoard->totalL->text().toInt()+7 <= scoreBoard->winningScore)
         {
            scoreBoard->largeCounterL->setText(QString::number(scoreBoard->largeCounterL->text().toInt()+1));
            scoreBoard->totalL->setText(QString::number(scoreBoard->totalL->text().toInt()+7));
            if(scoreBoard->totalL->text().toInt() == scoreBoard->winningScore)
            {
                qDebug("Victory");
                emit Victory();
            }
         }
     }
     if(scoreBoard->totalL->text().toInt() > scoreBoard->winningScore/8 && arrow1->speedIncreased == 0)
     {
         qDebug("Speed Increased");
         arrow1->increasespeed();
         arrow1->speedIncreased++;
     }
     if(scoreBoard->totalL->text().toInt() > scoreBoard->winningScore/4  && arrow1->speedIncreased == 1)
     {
         qDebug("Speed Increased");
         arrow1->increasespeed();
         arrow1->speedIncreased++;
     }
     if(scoreBoard->totalL->text().toInt() > scoreBoard->winningScore/2 && arrow1->speedIncreased == 2)
     {
         qDebug("Speed Increased");
         arrow1->increasespeed();
         arrow1->speedIncreased++;
     }
     if(scoreBoard->totalL->text().toInt() > (3*scoreBoard->winningScore)/4  && arrow1->speedIncreased == 3)
     {
         qDebug("Speed Increased");
         arrow1->increasespeed();
         arrow1->speedIncreased++;
     }
}
 void game1scene::VMissed(){
     if(scoreBoard->numberOfMisses > 0)
     scoreBoard->numberOfMisses--;
     if(scoreBoard->numberOfMisses == 0)
         emit Lost();
 }

/**
 * \brief
 */
