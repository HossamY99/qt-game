#include "loginclass.h"
#include "mainwidget.h"

loginclass::loginclass(QWidget *parent) : QWidget(parent)
{
    username= new QLabel("Username");
    password= new QLabel("Password");
    login= new QPushButton ("login");


    warning.setText("Wrong username or password");
    usernameLine = new QLineEdit;
    passwordLine = new QLineEdit;
    passwordLine->setEchoMode(QLineEdit::Password);
    connect(login, SIGNAL(clicked()), this, SLOT(loginClicked()));

    back= new QPushButton("Back");
    connect(back, SIGNAL(clicked()), this, SLOT(goback()));


    grid=new QGridLayout;
    grid->addWidget(username,2,0);
    grid->addWidget(usernameLine,2,2);
    grid->addWidget(password,3,0);
    grid->addWidget(passwordLine,3,2);
    grid->addWidget(login,5,3);
    grid->addWidget(back,6,6);

    setLayout(grid);

}
void loginclass::loginClicked()
{
    bool founded = false;
    QFile file(QDir::homePath()+ "/users.txt");
    if(!file.open(QIODevice::ReadOnly))
        qDebug()<<"Error";

while(!file.atEnd())
   {
    QString line = file.readLine();
    QStringList splitedLine = line.split(":");
        if(splitedLine[0] == "Username")
        {

            QString fUsername = splitedLine[1].split(" ")[0];
            QString fPass = splitedLine[2].split(" ")[0];

            if(fUsername==usernameLine->text() && fPass == passwordLine->text())
                founded=true;
        }
    }




if(founded)
    qDebug()<<"succesful";
else warning.exec();


}

void loginclass::goback()
{
    mainwidget *m=new mainwidget;
    hide();
    m->show();
}

