#include "needle.h"

needle::needle(QObject *parent) : QObject(parent)
{
    this->setPixmap((QPixmap(":/images/needle.jpg")).scaled(100,100));
    this->setPos(320,430);
}
