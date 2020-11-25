#include "connection.h"

Connection::Connection()
{
    db= QSqlDatabase::addDatabase("QODBC");
}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("base");
db.setUserName("youssef1");//inserer nom de l'utilisateur
db.setPassword("56330407");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}


void Connection::closeconnect()
{
    db.close();
}
