#ifndef TEST_H
#define TEST_H

#include <QObject>
#include<QKeyEvent>
#include<QGraphicsView>
#include "presstostart.h"
#include "game1scene.h"
#include"victory.h"
#include"lost.h"

class startg1 : public QGraphicsView
{
    Q_OBJECT
public:
    startg1();
    PressToStart *ptsScene;
    game1scene *g1Scene;
    Victory *victoryScene;
    Lost *lostScene;

private:
    //members:

    //methods:

public slots:
    void changeScene();
    void WonGame();
    void LostGame();
signals:

};

#endif // TEST_H
