#include "score.h"

score::score(QWidget *parent) : QWidget(parent)
{


    winningScore = 150;
    numberOfMisses =3;

    smallL = new QLabel("Small:");
    smallL->setStyleSheet(
                "color: white;"
                "font-weight: bold;"
                );

    mediumL = new QLabel("Medium:");
    mediumL->setStyleSheet(
                "color: white;"
                "font-weight: bold;"
                );

    largeL = new QLabel("Large:");
    largeL->setStyleSheet(
                "color: white;"
                "font-weight: bold;"
                );

    smallCounterL = new QLabel("0");
    smallCounterL->setStyleSheet(
                "color: white;"
                "font-weight: bold;"
                );

    mediumCounterL = new QLabel("0");
    mediumCounterL->setStyleSheet(
                "color: white;"
                "font-weight: bold;"
                );

    largeCounterL = new QLabel("0");
    largeCounterL->setStyleSheet(
                "color: white;"
                "font-weight: bold;"
                );

    totalScoreL = new QLabel("Total Score:");
    totalScoreL->setStyleSheet(
                "color: white;"
                "font-weight: bold;"
                "font-size: M0px;"
                );

    totalL = new QLabel("0");
    totalL->setStyleSheet(
                "color: white;"
                "font-weight: bold;"
                "font-size: M0px;"
                );

    counterSLayout = new QHBoxLayout();
    counterMLayout = new QHBoxLayout();
    counterLLayout = new QHBoxLayout();
    countersLayout = new QHBoxLayout();
    scoreLayout = new QHBoxLayout();
    boardLayout = new QVBoxLayout();

    setUp();

    setLayout(boardLayout);
    setStyleSheet(
                "background-color : blue;"
                );

}


void score::setUp(){
    counterSLayout->addWidget(smallL);
    counterSLayout->addWidget(smallCounterL);

    counterMLayout->addWidget(mediumL);
    counterMLayout->addWidget(mediumCounterL);

    counterLLayout->addWidget(largeL);
    counterLLayout->addWidget(largeCounterL);

    countersLayout->addItem(counterSLayout);
    countersLayout->addItem(counterMLayout);
    countersLayout->addItem(counterLLayout);
    countersLayout->setSpacing(10);

    scoreLayout->addWidget(totalScoreL);
    scoreLayout->addWidget(totalL);

    boardLayout->addItem(countersLayout);
    boardLayout->addItem(scoreLayout);



    counterSLayout->setSpacing(10);
    counterMLayout->setSpacing(10);
    counterLLayout->setSpacing(10);
    //VSLayout->setMargin(50);
}

