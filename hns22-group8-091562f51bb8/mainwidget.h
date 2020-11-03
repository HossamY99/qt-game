#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include<QObject>
#include <QWidget>
#include<QtWidgets>
#include "loginclass.h"

class mainwidget : public QWidget
{
    Q_OBJECT
public:
    explicit mainwidget(QWidget *parent = nullptr);
    QPushButton * login, * signup, * guest;
    QVBoxLayout *box;

signals:

   public slots:
    void loginclicked();
    void signupclicked();
    void guestclicked();

};

#endif // MAINWIDGET_H
