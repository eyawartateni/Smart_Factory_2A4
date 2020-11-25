#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "agence.h"
#include <QSqlQuery >
#include "employer.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_profil))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_assurence))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_reclamation))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_ajout))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_affi))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_emp))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_mod))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_sup))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_assur))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->menu_ag))  ;
  ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->aj_ajout))  ;
  ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_aff))  ;
  ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_mod))  ;
  ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_supp))  ;
  ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_stat))  ;

     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_assurence))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_reclamation))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_ajout))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_affi))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_emp))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_mod))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_sup))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_assur))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->menu_ag))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->aj_ajout))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_menu))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_aff))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_mod))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_supp))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_stat))  ;






}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_login_clicked()
{
      ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->login))  ;
      QSqlQuery query   ;
      query.prepare("SELECT *  FROM TABLE1 WHERE PASSE=:passe AND ADRESSE=:adresse");
      query.bindValue(":passe",ui->logpass->text());
      query.bindValue(":adresse",ui->log_add->text() ) ;
    //  query.exec() ;
     if (query.exec()&&query.next()) {
        if(query.value(4).toString()=="administrateur") {
            ui->tabWidget->insertTab(max,ui->adm_menu,"Home") ;

     }
        else {
        ui->tabWidget->insertTab(max,ui->em_profil,"Profile") ;
        ui->aff_cin->setText(query.value(0).toString() );
        ui->aff_nom->setText(query.value(1).toString() );
        ui->aff_prenom->setText(query.value(2).toString() );
        ui->aff_sal->setText(query.value(3).toString() );
        ui->aff_poste->setText(query.value(4).toString() );
         if(query.value(5).toString()=="married"){
        ui->aff_combo_etat->setCurrentIndex(2) ;
 }
         else
             ui->aff_combo_etat->setCurrentIndex(1) ;
        ui->aff_spinBox->setValue(query.value(6).toInt()) ;

        }

     }
}

void MainWindow::on_m_agence_clicked()
{agence ag ;
    ui->ag_tab_aff->setModel(ag.afficher());
    max=0 ;
    ui->tabWidget->removeTab(max)  ;
    ui->tabWidget->insertTab(max,ui->menu_ag,"Agence") ;
    max++ ;
    ui->tabWidget->insertTab(max,ui->aj_ajout,"Ajouter");
    max++ ;
    ui->tabWidget->insertTab(max,ui->ag_aff,"Afficher") ;
    max++  ;
    ui->tabWidget->insertTab(max,ui->ag_mod,"Modifier") ;
    max++ ;
    ui->tabWidget->insertTab(max,ui->ag_supp,"Supprimer") ;
    max++ ;
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->menu_ag)) ;



}

void MainWindow::on_but_ag_ajou_clicked()
{
     ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->aj_ajout))  ;
}

void MainWindow::on_but_ag_affi_clicked()
{
  ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->ag_aff)) ;
}

void MainWindow::on_but_ag_mod_clicked()
{
  ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->ag_mod)) ;
}

void MainWindow::on_but_adm_sup_2_clicked()
{
      ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->ag_supp)) ;
}

void MainWindow::on_but_adm_home_7_clicked()
{
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_profil))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_assurence))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_reclamation))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_ajout))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_affi))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_emp))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_mod))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_sup))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_assur))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->menu_ag))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->aj_ajout))  ;

    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_aff))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_mod))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_supp))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_stat))  ;
    ui->tabWidget->addTab(ui->adm_menu,"Home") ;
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->adm_menu)) ;
}

void MainWindow::on_but_adm_ajou_7_clicked()
{
    ui->tabWidget->addTab(ui->ag_stat,"Statistique") ;
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->ag_stat)) ;
}

void MainWindow::on_menu_emp_clicked()
{
    employer e ;
    //agence ag ;
    //e.afficher() ;
     ui->adm_tab_aff->setModel(e.afficher());

    max=0 ;
    ui->tabWidget->removeTab(max)  ;
    ui->tabWidget->insertTab(max,ui->adm_emp,"Home") ;
    max++ ;
    ui->tabWidget->insertTab(max,ui->adm_ajout,"Ajouter");
    max++ ;
    ui->tabWidget->insertTab(max,ui->adm_affi,"Afficher") ;
    max++  ;
    ui->tabWidget->insertTab(max,ui->adm_mod,"Modifier") ;
    max++ ;
    ui->tabWidget->insertTab(max,ui->adm_sup,"Supprimer") ;
    max++ ;
}

void MainWindow::on_but_adm_ajou_clicked()
{
  ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->adm_ajout)) ;
}

void MainWindow::on_but_adm_affi_clicked()
{
     ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->adm_affi)) ;
}

void MainWindow::on_but_adm_mod_clicked()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->adm_mod)) ;
}

void MainWindow::on_but_adm_sup_clicked()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->adm_sup)) ;
}

void MainWindow::on_but_adm_home_8_clicked()
{
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_profil))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_assurence))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_reclamation))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_ajout))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_affi))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_emp))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_mod))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_sup))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_assur))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->menu_ag))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->aj_ajout))  ;

     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_aff))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_mod))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_supp))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_stat))  ;
     ui->tabWidget->addTab(ui->adm_menu,"Home") ;
     ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->adm_menu)) ;
}

void MainWindow::on_assurence_8_clicked()
{
    ui->tabWidget->addTab(ui->adm_assur,"Assurence") ;
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->adm_assur)) ;
}

void MainWindow::on_assurence_clicked()
{
    if (ass==true ) {
       ui->tabWidget->addTab(ui->em_assurence,"Assurence") ;
    ass=false ;
    }
       ui->tabWidget->setCurrentIndex( ui->tabWidget->indexOf(ui->em_assurence) )   ;
}

void MainWindow::on_reclamation_clicked()
{
    if (rec==true ) {
        ui->tabWidget->addTab(ui->em_reclamation,"Reclamation") ;
    rec=false ;
    }
    ui->tabWidget->setCurrentIndex( ui->tabWidget->indexOf(ui->em_reclamation) )   ;
}

void MainWindow::on_btn_ajouter_clicked()
{
    int cin=ui->adm_aj_cin->text().toInt() ;
    int salaire=ui->adm_aj_salaire->text().toInt() ;
    QString nom=ui->adm_aj_nom->text() ;
    QString prenom=ui->adm_aj_prenom->text() ;
    QString poste=ui->adm_aj_poste->text()  ;
    QString etat=ui->adm_aj_combo_etat->currentText() ;
    int nombre=ui->adm_aj_spin_nbrenfant->value() ;
    QDateTime time ;

    QString passe= ui->adm_aj_cin->text()+ui->adm_aj_spin_nbrenfant->text();
    QString adresse=nom+"."+prenom+"_factory@gamil.com" ;

    employer e(cin,nom,prenom,poste,etat,adresse,passe,salaire,nombre) ;





     e.ajouter();
     // afficher() ;
     // ui->adm_tab_aff->setModel(afficher());

      /*if(test)
    {

          ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                    QObject::tr("Etudiant ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
                                  */
}



void MainWindow::on_btn_adm_supp_clicked()
{
    employer e ;
    int id=ui->adm_id_supp->text().toUInt() ;
     e.supprimer(id) ;
}

void MainWindow::on_btn_adm_load_clicked()
{
    employer e ;
    QSqlQueryModel *modal=new QSqlQueryModel() ;
    QSqlQuery query ;
    query.prepare("SELECT CIN  FROM TABLE1") ;
    if (query.exec()&&query.next()) {
        modal->setQuery(query) ;
        ui->adm_list_view->setModel(modal) ;
        ui->adm_combobox_aff->setModel(modal) ;



    }
}

void MainWindow::on_adm_combobox_aff_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query ;
    query.prepare("SELECT *  FROM TABLE1 WHERE CIN=:cin") ;
    query.bindValue(":cin",ui->adm_combobox_aff->currentText() ) ;
    if (query.exec()&&query.next()) {
    ui->adm_aj_cin_2->setText(query.value(0).toString() );
    ui->adm_aj_nom_2->setText(query.value(1).toString() );
    ui->adm_aj_prenom_2->setText(query.value(2).toString() );
    ui->adm_aj_salaire_2->setText(query.value(3).toString() );
    ui->adm_aj_poste_2->setText(query.value(4).toString() );
     if(query.value(5).toString()=="married"){
    ui->adm_mod_aff_combo_etat->setCurrentIndex(2) ;
    }
     else
         ui->adm_mod_aff_combo_etat->setCurrentIndex(1) ;
    ui->adm_aj_spin_nbrenfant_2->setValue(query.value(6).toInt()) ;
 }
}

void MainWindow::on_btn_ajouter_2_clicked()
{
    QSqlQuery query ;
    QString passe= ui->adm_aj_cin_2->text()+ui->adm_aj_spin_nbrenfant_2->text();
    QString adresse=ui->adm_aj_nom_2->text()+"."+ui->adm_aj_prenom_2->text()+"_factory@gamil.com" ;

    //query.prepare("UPDATE  TABLE1 SET CIN='" +  ui->adm_aj_cin_2->text() + "' ,NAME='"+ ui->adm_aj_nom_2->text()+"' ,PRENOM= '"+ui->adm_aj_prenom_2->text()+"' ,SALAIRE='"+ui->adm_aj_salaire_2->text().toInt()+"',POSTE'"+ui->adm_aj_poste_2->text()+"',ETAT='"+ui->adm_mod_aff_combo_etat->currentText()+"',NOMBRE='"+ ui->adm_aj_spin_nbrenfant_2->value()+"',PASSE= '"+passe+ "',ADRESSE='"+adresse+ "' WHERE ,CIN='"+ui->adm_aj_cin_2->text() +"'") ;

     query.prepare("UPDATE  TABLE1 SET  NOM=:nom, PRENOM=:prenom,SALAIRE=:salaire,POSTE=:poste,ETAT=:etat,NOMBRE=:nombre,ADRESSE=:adresse,PASSE=:passe WHERE CIN=:cin ");

    query.bindValue(":cin",ui->adm_aj_cin_2->text().toInt());
    query.bindValue(":nom", ui->adm_aj_nom_2->text());
    query.bindValue(":prenom",ui->adm_aj_prenom_2->text());
    query.bindValue(":salaire", ui->adm_aj_salaire_2->text().toInt());
    query.bindValue(":poste",ui->adm_aj_poste_2->text());
    query.bindValue(":etat",ui->adm_mod_aff_combo_etat->currentText());
    query.bindValue(":nombre",ui->adm_aj_spin_nbrenfant_2->value());

    query.bindValue(":adresse",adresse);
    query.bindValue(":passe",passe);

query.exec();
query.next() ;

}

void MainWindow::on_btn_ag_aj_clicked()
{
    QString id=ui->ag_aj_id->text() ;
    QString nom=ui->ag_aj_nom->text();
    QString adresse=ui->ag_aj_adresse->text() ;
    QDate date=ui->ag_aj_dateEdit->date() ;
    int nbr_emp=ui->aj_ag_spinBox_nbremp->value()  ;
    int  cin_d=ui->ag_aj_cin->text().toInt() ;
    int nbr_v=2 ;
    QDateTime time ;

    //QString passe= ui->adm_aj_cin->text()+ui->adm_aj_spin_nbrenfant->text();
    //QString adresse=nom+"."+prenom+"_factory@gamil.com" ;

    //employer e(cin,nom,prenom,poste,etat,adresse,passe,salaire,nombre) ;
agence ag(id,nom,adresse,date,nbr_emp,cin_d,nbr_v) ;
ag.ajouter() ;
}

void MainWindow::on_btn_adm_supp_2_clicked()
{
    agence ag ;
    QString id=ui->ag_id_supp->text() ;
     ag.supprimer(id) ;

}

void MainWindow::on_btn_ag_supp__clicked()
{
    agence ag ;
    QString id=ui->ag_id_supp->text() ;
     ag.supprimer(id) ;

}

void MainWindow::on_btn_ag_load_clicked()
{

    agence ag ;
    QSqlQueryModel *modal=new QSqlQueryModel() ;
    QSqlQuery query ;
    query.prepare("SELECT ID  FROM AGENCE ") ;
    if (query.exec()&&query.next()) {
        modal->setQuery(query) ;
        ui->ag_list_view->setModel(modal) ;
        ui->ag_combobox_aff->setModel(modal) ;
}
}

void MainWindow::on_ag_combobox_aff_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query ;
    query.prepare("SELECT *  FROM AGENCE WHERE ID=:id") ;
    query.bindValue(":id",ui->adm_combobox_aff->currentText()  ) ;
    if (query.exec()&&query.next()) {
    ui->ag_aj_id_2->setText(query.value(0).toString() );
    ui->ag_aj_nom_2->setText(query.value(1).toString() );
    ui->ag_aj_adresse_2->setText(query.value(2).toString() );
    ui->ag_aj_dateEdit_2->setDate(query.value(3).toDate() );
    ui->aj_ag_spinBox_nbremp_2->setValue(query.value(4).toInt() );
    ui->aj_ag_spinBox_nb_vente_2->setValue(6) ;
    ui->ag_aj_cin_2->setText(query.value(5).toString()) ;

}
}

void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery query ;
    //QString passe= ui->adm_aj_cin_2->text()+ui->adm_aj_spin_nbrenfant_2->text();
    //QString adresse=ui->adm_aj_nom_2->text()+"."+ui->adm_aj_prenom_2->text()+"_factory@gamil.com" ;

    //query.prepare("UPDATE  TABLE1 SET CIN='" +  ui->adm_aj_cin_2->text() + "' ,NAME='"+ ui->adm_aj_nom_2->text()+"' ,PRENOM= '"+ui->adm_aj_prenom_2->text()+"' ,SALAIRE='"+ui->adm_aj_salaire_2->text().toInt()+"',POSTE'"+ui->adm_aj_poste_2->text()+"',ETAT='"+ui->adm_mod_aff_combo_etat->currentText()+"',NOMBRE='"+ ui->adm_aj_spin_nbrenfant_2->value()+"',PASSE= '"+passe+ "',ADRESSE='"+adresse+ "' WHERE ,CIN='"+ui->adm_aj_cin_2->text() +"'") ;

     query.prepare("UPDATE  AGENCE SET  ID=:id, NOM=:nom,ADRESSE=:adresse,D=:d,EMPLOYER=:employer,DIRECTEUR=:directeur,VENTE=:vente");

    query.bindValue(":id", ui->ag_aj_id_2->text());
    query.bindValue(":nom", ui->ag_aj_nom_2->text());
    query.bindValue(":adresse",ui->adm_aj_prenom_2->text());
    query.bindValue(":d", ui->ag_aj_dateEdit_2->date());
    query.bindValue(":employer", ui->aj_ag_spinBox_nbremp_2->text().toInt());
    query.bindValue(":directeur",ui->ag_aj_cin_2->text().toInt());
    query.bindValue(":vente",ui->aj_ag_spinBox_nb_vente_2->text().toInt());



query.exec();

}

void MainWindow::on_btn_adm_tri_aff_clicked()
{    QSqlQueryModel *model=new QSqlQueryModel() ;
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    ui->adm_tab_aff->setModel(model) ;
    QSqlQuery query ;
     if (ui->comboBox->currentText()=="CIN")
     query.prepare("SELECT *  FROM TABLE1 ORDER BY CIN ASC ") ;
else
         if (ui->comboBox->currentText()=="NOM")
         query.prepare("SELECT *  FROM TABLE1 ORDER BY NOM ASC ") ;
  else
             if (ui->comboBox->currentText()=="SALAIRE")
             query.prepare("SELECT *  FROM TABLE1 ORDER BY SALAIRE ASC ") ;

    if (query.exec()&&query.next()) {
        model->setQuery(query) ;

        ui->adm_tab_aff->setModel(model) ;




}

}



