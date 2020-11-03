#include "presstostart.h"

PressToStart::PressToStart()
{
    setBackgroundBrush(QBrush(QImage(":/images/backg.jpeg")
                                .scaledToHeight(400) .scaledToWidth(1000)));

startB = new QPushButton("Press To Start");

addWidget(startB)->setMinimumSize(200,100);



}
void PressToStart:: keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_F1 )
       emit startB->clicked(true);
}

