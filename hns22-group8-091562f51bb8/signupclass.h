#ifndef SIGNUPCLASS_H
#define SIGNUPCLASS_H

#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include "mainwidget.h"



class signupclass : public QWidget
{
    Q_OBJECT
public:
    explicit signupclass(QWidget *parent = nullptr);


    QLineEdit *passwordLine,*repeatPasswordLine,*emailLine;
    QLabel *firstname, * lastname,*username,*password, *repeatpassword,*email, *date;
    QLineEdit *firstnameLine,*lastnameLine,*usernameLine;
    QPushButton *signup;
    QGridLayout *signupGrid;
    QDateEdit *dateEdit;
    QMessageBox warning;
     QPushButton *back;
    bool CheckPassword(QString);
    bool CheckUsername(QString);
signals:

public slots:
 void SignupClicked();
 void goback();

};

#endif // SIGNUPCLASS_H
