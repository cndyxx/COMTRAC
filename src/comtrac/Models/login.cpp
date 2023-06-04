
#include "login.h"


Login::Login(QObject *parent)
    : QObject{parent}
{

}

void Login::checkLoginData(QString userName, QString password){
    //Benutzername und Passwort an das Model übergeben
    qDebug() << userName << " + " << password;
}
