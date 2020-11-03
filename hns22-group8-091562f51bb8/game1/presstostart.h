#ifndef PRESSTOSTART_H
#define PRESSTOSTART_H

#include <QObject>
#include<QtWidgets>


class PressToStart : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PressToStart();
    QPushButton *startB;
private:
    //members:

    //methods:
    void keyPressEvent(QKeyEvent *event);

public slots:

signals:

};

#endif // PRESSTOSTART_H
