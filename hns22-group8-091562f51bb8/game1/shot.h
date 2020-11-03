/**
 * \file shot.h
 *\brief shot header
 *
 *\author
*/

#ifndef SHOT_H
#define SHOT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class shot : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit shot(QObject *parent = nullptr);
    QTimer *timershot;
    void lineequation(float slope, float yintercept,float xstart);
    void shoot();


    float ss=0;
    float yy=0;
    float xx=0;


public slots:
void move();

signals:
    void  VirusMissed();

};

#endif // shot_H
