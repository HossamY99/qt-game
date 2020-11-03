#include "signupclass.h"

signupclass::signupclass(QWidget *parent) : QWidget(parent)
{
    firstname= new QLabel("First Name");
    lastname= new QLabel("Last Name");
    username = new QLabel("Username");
    repeatpassword= new QLabel("Repeat Password");
    email= new QLabel("Email");
    password= new QLabel("Password");
    signup= new QPushButton ("Signup");
     date = new QLabel("Date Of Birth");
    emailLine = new QLineEdit;
    passwordLine = new QLineEdit;
    repeatPasswordLine = new QLineEdit;
    firstnameLine = new QLineEdit;
    lastnameLine = new QLineEdit;
    usernameLine = new QLineEdit;
    dateEdit= new QDateEdit;

    back= new QPushButton("Back");
    connect(back, SIGNAL(clicked()), this, SLOT(goback()));

    connect(signup, SIGNAL(clicked()), this, SLOT(SignupClicked()));

    signupGrid=new QGridLayout;
    signupGrid->addWidget(firstname,0,0);
    signupGrid->addWidget(firstnameLine,0,2);
    signupGrid->addWidget(lastname,1,0);
    signupGrid->addWidget(lastnameLine,1,2);
    signupGrid->addWidget(email,2,0);
    signupGrid->addWidget(emailLine,2,2);
    signupGrid->addWidget(username,3,0);
    signupGrid->addWidget(usernameLine,3,2);
    signupGrid->addWidget(date,4,0);
    signupGrid->addWidget(dateEdit,4,2);
    signupGrid->addWidget(password,5,0);
    signupGrid->addWidget(passwordLine,5,2);
    signupGrid->addWidget(signup,6,3);
    signupGrid->addWidget(back,7,7);
    setLayout(signupGrid);


}
void signupclass::SignupClicked(){


    if(CheckUsername(usernameLine->text()))
    {
        warning.setText("Username already exist");
        warning.exec();
        return;
    }
    if(!CheckPassword(passwordLine->text()))
    {
        warning.setText("Password must contain at least one number, upper andlower case letters");
        warning.exec();
        return;
    }

    QFile file(QDir::homePath()+ "/users.txt");
    if(!file.open(QIODevice::Append))
        qDebug()<<"Error";


    QTextStream out(&file);
    out<<username->text().toUtf8()+":"+ usernameLine->text().toUtf8()+" ";
    out<<password->text().toUtf8() +":" + passwordLine->text().toUtf8()+" ";
    out<<date->text().toUtf8()+":"+ dateEdit->text().toUtf8()+" ";
    out<<firstname->text().toUtf8()+":"+ firstnameLine->text().toUtf8()+" ";
    out<<lastname->text().toUtf8()+":"+ lastname->text().toUtf8()+" ";
    out<<email->text().toUtf8()+":"+ emailLine->text().toUtf8()+" \n";

    file.close();
    qDebug()<<"Signed Up";

}
bool signupclass::CheckPassword(QString pass)
{
    bool containUpper = false;
    bool containLower = false;
    bool containNumber = false;
if(pass.size()<8)
    return false;

for(QChar e : pass) {
    if(e.isUpper())
        containUpper = true;
    if(e.isLower())
        containLower = true;
    if(e.isDigit())
        containNumber = true;
}

if(containUpper && containLower && containNumber)
    return true;

return false;
}

bool signupclass::CheckUsername(QString user)
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

            QStringList userfound = splitedLine[1].split(" ");

            if(userfound[0]==user)
                founded=true;
        }
    }

return founded;
}


void signupclass::goback()
{
    mainwidget *m=new mainwidget;
    hide();
    m->show();
}

