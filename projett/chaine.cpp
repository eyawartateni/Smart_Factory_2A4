#include "chaine.h"


chaine::chaine()
{
    type_produit="";
    reference=0;
    nb_machine=0;
}

chaine::chaine(QString t,int r,int n)
{
       type_produit=t;
       reference=r;
       nb_machine=n;
}

bool chaine::ajouter()
 {
     QSqlQuery query;
     QString res = QString::number(reference);
     query.prepare("INSERT INTO chaine(type_produit,reference,nb_machine)"
                   "VALUES (:type_produit,:reference,:nb_machine)");
     query.bindValue(":type_produit",type_produit);
     query.bindValue(":reference",res);
     query.bindValue(":nb_machine",nb_machine);
     return query.exec();

 }



  QSqlQueryModel *chaine::afficher()
  {
      QSqlQueryModel * model=new QSqlQueryModel();
      model->setQuery("select* from chaine");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("type_produit"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("reference"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("nb_machine"));
      return  model;
  }
/*
    bool chaine::imprimer()
    {
        QString format = "dd.MM.yyyy";
            QString ch=date_de_commande.toString(format);

            QFile file("Commande_de_production.txt");
                     if (!file.open(QIODevice::ReadWrite))
                         return 0;

                   QTextStream flux(&file);

                   // On choisit le codec correspondant au jeu de caract�re que l'on souhaite ; ici, UTF-8

                   flux.setCodec(QTextCodec::codecForName("ISO-8859-1"));


                   // �criture des diff�rentes lignes dans le fichier
                   flux << " commande_de_production " << endl << endl;
                   flux << "       Numero_com_prod :    " <<Numero_com_prod<< endl;
                   flux <<"        date_de_commandee :  " << ch<<endl;
                   flux <<"       Type_de_production : " << Type_de_production<<endl;
                   flux <<"      Quantite : " << Quantite<< endl;
                   flux <<"        CIN_emp " << CIN_emp<< endl;

                          flux <<"        SOTUPA.com" << endl;

                     QPrinter printer;
                   flux.seek(0);

                   // Lecture du fichier et stockage dans un QString :
                   QString text = file.readAll();

                   // Initialisation de document avec le texte simple :
                   QTextDocument document(text);

                   // Cr�ation du QPrintDialog pour le printer :
                   QPrintDialog *dialog = new QPrintDialog(&printer);

                   // Si l'utilisateur a fait "Accepter" :
                   if (dialog->exec() == QDialog::Accepted)
                   {
                       // On imprime :
                       document.print(&printer);
                   }
    }
*/
