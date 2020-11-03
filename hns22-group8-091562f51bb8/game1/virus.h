#ifndef VIRUS_H
#define VIRUS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include<QKeyEvent>
#include <QTimer>
#include<string>


class virus : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit virus(QObject *parent = nullptr);
    QTimer *listeningTimer ;
    bool isDead=0;
    QString variousSizes[3] = {"S","M","L"};
    QString size;
    QString lastSize;
    void generateRandomVirus();

public slots:
     void checkVaccine();

signals:
    void  updateVirus();
};

#endif // VIRUS_H
