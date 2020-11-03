#include "victory.h"

Victory::Victory()
{
    setBackgroundBrush(QBrush(QImage(":/images/backg.jpeg")
                                .scaledToHeight(400) .scaledToWidth(1000)));

winL = new QLabel("You Won");
winL->setStyleSheet(
            "color: white;"
            "font-weight: bold;"
            "background-color : red;"
            "font-size : 50px"
            );

addWidget(winL)->setMinimumSize(100,100);

}
