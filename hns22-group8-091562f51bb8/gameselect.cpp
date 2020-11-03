#include "gameselect.h"

gameselect::gameselect(QWidget *parent) : QWidget(parent)
{

    game1= new QPushButton ("Game 1");
    game2= new QPushButton ("Game 2");
    back=new QPushButton("Back");

    connect(game1, SIGNAL(clicked()), this, SLOT(gogame1()));
    connect(game2, SIGNAL(clicked()), this, SLOT(gogame2()));

    back= new QPushButton("Back");
    connect(back, SIGNAL(clicked()), this, SLOT(goback()));

    vbox=new QVBoxLayout;
    vbox->addWidget(game1);
    vbox->addWidget(game2);
    vbox->addWidget(back);
    setLayout(vbox);

}

void gameselect::gogame1(){
//hide();
//startgame1 st;
}
void gameselect::gogame2(){

}

void gameselect::goback()
{
    mainwidget *m=new mainwidget;
    hide();
    m->show();
}
