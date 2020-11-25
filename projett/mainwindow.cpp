#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"voiture.h"
#include"chaine.h"
#include"connexion.h"
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QSqlRelationalTableModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->tableView->setModel(vtmp.afficher());
     ui->tableView->setModel(vtmp.afficher());
     ui->tableView_2->setModel(ctmp.afficher());
    ui->comboBox->setModel(vtmp.load());
    ///////filtrer les données d'un client
           modVoiture= new QSqlRelationalTableModel(this);
           modVoiture->setTable("voiture1");
           modVoiture->select();
           proxyVoiture=new QSortFilterProxyModel(this);
           proxyVoiture->setSourceModel(modVoiture);
           proxyVoiture->setFilterCaseSensitivity(Qt::CaseInsensitive);
           proxyVoiture->setFilterKeyColumn(1);
          ui->tableView->setModel(proxyVoiture);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{
    QString marque = ui->lineEdit_marque->text();
     QString modele=ui->lineEdit_modele->text();
     QString type=ui->lineEdit_type->text();
     QString options=ui->lineEdit_option->text();
     QString couleur=ui->lineEdit_couleur->text();
     int prix=ui->lineEdit_prix->text().toInt();
     int  prix_option=ui->lineEdit_p_op->text().toInt();
     int reference=ui->lineEdit_reference->text().toInt();
     voiture v(marque,reference,modele,prix,type,prix_option,couleur,options);
     bool test=v.ajouter();
     if(test)
     {
         ui->tableView->setModel(vtmp.afficher());
         QMessageBox::information(nullptr, QObject::tr("ajout effectuee"),
                     QObject::tr("voiture ajouté avec succés.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("ajout non effectuee"),
                     QObject::tr("voiture non ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_ajouter_chaine_clicked()
{
    QString type_produit = ui->lineEdit_type_p->text();
     int  reference=ui->lineEdit_ref->text().toInt();
     int nb_machine=ui->spinBox->text().toInt();
     chaine c(type_produit,reference,nb_machine);
     bool test=c.ajouter();
     if(test)
     {
          ui->tableView_2->setModel(ctmp.afficher());
         QMessageBox::information(nullptr, QObject::tr("ajout effectuee"),
                     QObject::tr("chaine ajouté avec succés.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("ajout non effectuee"),
                     QObject::tr("chaine non ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_afficher_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void MainWindow::on_quitter_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question
            (this,"quitter","voulez-vous vraiment quitter?",QMessageBox::Yes |QMessageBox::No);
    if(reply==QMessageBox::Yes)
{
        close();
    }else
    {

    }
}





/*void MainWindow::on_supprimer_clicked()
{
    int matricule = ui->lineEdit_matricule->text().toInt();
    bool test=ctmp.supprimer(matricule);
    if(test)
    {
         ui->tableView->setModel(ctmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("suppression effectuee"),
                    QObject::tr("ok.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
 }
    else
        QMessageBox::critical(nullptr, QObject::tr("suppression non effectuee"),
                              QObject::tr("ko.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}*/

void MainWindow::on_retour_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_modifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_retour_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_supprimer_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_retour_4_clicked()
{
      ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_retour_clicked()
{
      ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_retour_2_clicked()
{
      ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_afficher_chaine_clicked()
{
      ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_modifier_chaine_clicked()
{
      ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_supprimer_chaine_clicked()
{
      ui->stackedWidget_2->setCurrentIndex(3);
}



void MainWindow::on_quitter_2_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question
         (this,"quitter","voulez-vous vraiment quitter?",QMessageBox::Yes |QMessageBox::No);
    if(reply==QMessageBox::Yes)
{
        close();
    }else
    {

    }
}

void MainWindow::on_recherche_2_clicked()
{
    int reference = ui->lineEdit_ref_3->text().toInt();
    bool test=vtmp.supprimer(reference);
    if(test)
    {
         ui->tableView->setModel(vtmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("suppression effectuee"),
                    QObject::tr("ok.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
 }
    else
        QMessageBox::critical(nullptr, QObject::tr("suppression non effectuee"),
                              QObject::tr("ko.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_load_data_clicked()
{
     ui->comboBox->setModel(vtmp.load());
}

void MainWindow::on_modifier_3_clicked()
{
/*

    QString marque= ui->lineEdit_maq->text();
    QString modele=ui->lineEdit_mod->text();
    QString type=ui->lineEdit_typ->text();
    QString options=ui->lineEdit_ops->text();
    QString couleur=ui->lineEdit_col->text();
    int prix=ui->lineEdit_p->text().toInt();
    int  prix_option=ui->lineEdit_po->text().toInt();
    int reference=ui->lineEdit_refer->text().toInt();
// voiture v(marque,reference,modele,prix,type,prix_option,couleur,options);
    bool test=v.modifier();
    if(test)
    {
         ui->tableView->setModel(vtmp.afficher());
        msgBox.setText("voiture modifié");
       msgBox.exec();
    }
else
    {
       msgBox1.setText("voiture non modifié");
           msgBox1.exec();
     }
*/
    QSqlQuery query;
    QMessageBox msgBox;
    QMessageBox msgBox1;
    query.prepare("update VOITURE1 SET  MARQUE=:marque, MODELE=:modele, PRIX=:prix ,TYPE=:type,PRIX_OPTION=:prix_option,COULEUR=:couleur, OPTIONS=:options where REFERENCE=:reference");
    query.bindValue(":marque",ui->lineEdit_maq->text());
    query.bindValue(":reference",ui->lineEdit_refer->text().toInt());
    query.bindValue(":modele",ui->lineEdit_mod->text());
    query.bindValue(":prix",ui->lineEdit_p->text().toInt());
    query.bindValue(":type",ui->lineEdit_typ->text());
    query.bindValue(":prix_option",ui->lineEdit_po->text().toInt());
    query.bindValue(":couleur",ui->lineEdit_col->text());
    query.bindValue(":options",ui->lineEdit_ops->text());
    if(query.exec())
    {
         ui->tableView->setModel(vtmp.afficher());
        msgBox.setText("voiture modifié");
       msgBox.exec();
    }
else
    {
       msgBox1.setText("voiture non modifié");
           msgBox1.exec();
     }

}


void MainWindow::on_comboBox_currentIndexChanged()
{
    QString reference = ui->comboBox->currentText();
    QSqlQuery query;
    query.prepare("select*  from voiture1 where reference='"+reference+"'");
       if(query.exec())
    {
        while(query.next())
        {
             ui->lineEdit_refer->setText(query.value(0).toString());
            ui->lineEdit_maq->setText(query.value(1).toString());
            ui->lineEdit_mod->setText(query.value(2).toString());
            ui->lineEdit_typ->setText(query.value(3).toString());
            ui->lineEdit_ops->setText(query.value(4).toString());
            ui->lineEdit_col->setText(query.value(5).toString());
            ui->lineEdit_p->setText(query.value(6).toString());
            ui->lineEdit_po->setText(query.value(7).toString());

       }
    }

}


/*void MainWindow::on_recherche_clicked()
{
    int reference=ui->lineEdit_referencee->text().toInt();
    QSqlQueryModel *model =v->recherche(reference);
           int IDRech = model->data(model->index(0, 0)).toInt();

           if(reference == IDRech)
           {
               ui->tableView->show();
               ui->tableView->setModel(model);
           }
}*/




void MainWindow::on_sup_clicked()
{
     int reference=ui->lineEdit_referencee->text().toInt();
    bool test=vtmp.supprimer(reference);
    if(test)
    {
         ui->tableView->setModel(vtmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("suppression effectuee"),
                    QObject::tr("ok.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
 }
    else
        QMessageBox::critical(nullptr, QObject::tr("suppression non effectuee"),
                              QObject::tr("ko.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_lineEdit_referencee_textChanged(const QString &arg1)
{
    proxyVoiture->setFilterFixedString(arg1);

}
