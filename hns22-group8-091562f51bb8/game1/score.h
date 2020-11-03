#ifndef SCORE_H
#define SCORE_H

#include <QObject>
#include <QWidget>
#include<QtWidgets>

class score : public QWidget
{
    Q_OBJECT
public:
    explicit score(QWidget *parent = nullptr);
    int winningScore;
    int numberOfMisses;
    QLabel *smallL;
    QLabel *mediumL;
    QLabel *largeL;
    QLabel *smallCounterL;
    QLabel *mediumCounterL;
    QLabel *largeCounterL;
    QLabel *totalScoreL;
    QLabel *totalL;
    QHBoxLayout *counterSLayout;
    QHBoxLayout *counterMLayout;
    QHBoxLayout *counterLLayout;
    QHBoxLayout *countersLayout;
    QHBoxLayout *scoreLayout;
    QVBoxLayout *boardLayout;

    void setUp();
signals:

};

#endif // SCORE_H
