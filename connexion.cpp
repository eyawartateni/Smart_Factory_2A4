#include "connexion.h"

connexion::connexion()
{}

bool connexion::ouvrirConnexion()
{

    db=QSqlDatabase::addDatabase("QODBC");
/*db.setDatabaseName("Source_Projet2A");
db.setUserName("soumaya");//inserer nom de l'utilisateur
db.setPassword("admin");//inserer mot de passe de cet utilisateur*/

db.setDatabaseName("source_de_donnes");
db.setUserName("Rostom");//inserer nom de l'utilisateur
db.setPassword("liverpool");//inserer mot de passe de cet utilisateur
if (db.open())
return true;

return  false;

}
void connexion::fermerConnexion()
{db.close();}
