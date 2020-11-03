/**
 * \file arrow.h
 *\brief arrow header
 *
 *\author hossam younes
*/
#ifndef ARROW_H
#define ARROW_H
#include <QGraphicsPixmapItem>
#include<QKeyEvent>
#include <QObject>
#include<iostream>
#include<QTimer>
#include<shot.h>

class arrow : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit arrow(QObject *parent = nullptr);  //!   constructor
    int degrees;
    int direction;
    int deg;
    int speedIncreased;
    int rolltime;
    QTimer *temp;
    QTimer *wait;
    void startroll();
    void increasespeed();
    void keyPressEvent(QKeyEvent *event);   //!   key press detection function
signals:
    void VirusMissed();
public slots:
    void roll();
    void waitfun();
    void CheckShot();
};

#endif // arrow_H
