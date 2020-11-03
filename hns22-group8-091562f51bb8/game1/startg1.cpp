#include "startg1.h"

startg1::startg1()
{

    ptsScene = new PressToStart();
    g1Scene = new game1scene();
    victoryScene = new Victory();
    lostScene = new Lost();
   setScene(ptsScene);
   setFixedSize(400,1000);
   setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
   setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
QObject::connect(ptsScene->startB,SIGNAL(clicked(bool)),this,SLOT(changeScene()));
QObject::connect(g1Scene,SIGNAL(Victory()),this,SLOT(WonGame()));
QObject::connect(g1Scene,SIGNAL(Lost()),this,SLOT(LostGame()));

}

void startg1::changeScene(){
    if(scene() == ptsScene)
    setScene(g1Scene);

}
void startg1::WonGame(){
    if(scene() == g1Scene)
    setScene(victoryScene);

}
void startg1::LostGame(){
    if(scene() == g1Scene)
    setScene(lostScene);

}
