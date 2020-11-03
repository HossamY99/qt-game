#include "mainwidget.h"
#include "loginclass.h"
#include"signupclass.h"
#include"gameselect.h"

mainwidget::mainwidget(QWidget *parent) : QWidget(parent)
{
login = new QPushButton("Login");
signup = new QPushButton("Sign Up");
guest = new QPushButton("Play as Guest");
connect(login, SIGNAL(clicked()), this, SLOT(loginclicked()));
connect(signup, SIGNAL(clicked()), this, SLOT(signupclicked()));
connect(guest, SIGNAL(clicked()), this, SLOT(guestclicked()));




box = new QVBoxLayout();
    box->addWidget(login);
    box->addWidget(signup);
    box->addWidget(guest);
setLayout(box);

setFixedSize(400,400);
}

void mainwidget::loginclicked(){

    // mainwidget *w2= this;  this is just to try and go back

    loginclass *l=new loginclass;
    hide();

    l->show();

}

void mainwidget::signupclicked(){

    signupclass *s= new signupclass;
    hide();
    s->show();
}

void mainwidget::guestclicked(){

    gameselect *s= new gameselect;
    hide();
    s->show();
}



