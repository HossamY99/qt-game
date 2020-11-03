#ifndef GAMESELECT_H
#define GAMESELECT_H

#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include "mainwidget.h"
//#include "startgame1.h"


class gameselect : public QWidget
{
    Q_OBJECT
public:
    explicit gameselect(QWidget *parent = nullptr);
    QPushButton *game1;
    QPushButton *game2;
    QVBoxLayout *vbox;
    QPushButton *back;
signals:

public slots:
    void gogame1();
    void gogame2();
    void goback();

};

#endif // GAMESELECT_H
