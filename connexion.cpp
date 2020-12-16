#include "connexion.h"

connexion::connexion()
{}

bool connexion::ouvrirConnexion()
{

    db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("base");
db.setUserName("youssef1");//inserer nom de l'utilisateur
db.setPassword("56330407");//inserer mot de passe de cet utilisateur
if (db.open())
return true;

return  false;

}
void connexion::fermerConnexion()
{db.close();}
