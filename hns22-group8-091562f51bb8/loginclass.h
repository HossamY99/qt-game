#ifndef LOGINCLASS_H
#define LOGINCLASS_H

#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include "mainwidget.h"
class loginclass : public QWidget
{
    Q_OBJECT
public:
    explicit loginclass(QWidget *parent = nullptr);
    QLabel *username;
    QLabel *password;
    QLineEdit *usernameLine;
    QLineEdit *passwordLine;
    QMessageBox warning;
    QPushButton *login;
    QGridLayout *grid;
     QPushButton *back;


signals:
public slots:
 void loginClicked();
void goback();
};

#endif // LOGINCLASS_H
