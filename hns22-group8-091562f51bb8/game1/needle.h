#ifndef NEEDLE_H
#define NEEDLE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include<QKeyEvent>

class needle : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit needle(QObject *parent = nullptr);

signals:

};

#endif // NEEDLE_H
