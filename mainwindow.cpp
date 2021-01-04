#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "C:/Users/Mayssa/Desktop/Qt-Table-Printer-master/Qt-Table-Printer-master/tableprinter.h"
//#include "C:/Users/eyaou/Desktop/Qt-Table-Printer-master/tableprinter.h"
//#include "C:/Users/eyaou/Desktop/Smart_Factory_2A4-master/Smart_factory_2A4/Qt-Table-Printer-master/tableprinter.h"
#include<QPixmap>
#include <QComboBox>
#include "QMessageBox"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QPrintDialog>
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include<arduino1.h>
#include "exportexcelobject.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);

     ui->stackedWidget->setCurrentWidget(ui->login) ;


     ///arduino
     arduino_is_available=false;
     arduino_port_name="";
     arduino = new QSerialPort;
     foreach(const QSerialPortInfo &serial_port_info , QSerialPortInfo::availablePorts())
     {
         if(serial_port_info.hasProductIdentifier() && serial_port_info.hasVendorIdentifier())
         {
             if(serial_port_info.vendorIdentifier()==arduino_uno_vendor_id && serial_port_info.productIdentifier()==arduino_uno_producy_id)
             {
                 arduino_port_name = serial_port_info.portName();
                   arduino_is_available=true;
             }
         }
     }
     qDebug()<<"arduino_port_name is:"<<arduino_port_name;
     if(arduino_is_available)
     {
        arduino->setPortName(arduino_port_name);
         if(arduino->open(QSerialPort::ReadWrite))
         {
             arduino->setBaudRate(QSerialPort::Baud9600);
             arduino->setDataBits(QSerialPort::Data8);
             arduino->setParity(QSerialPort::NoParity);
             arduino->setStopBits(QSerialPort::OneStop);
             arduino->setFlowControl(QSerialPort::NoFlowControl);
         }
 }

      ui->ag_aj_cin->setValidator(new QIntValidator(0,99999999,this));
      ui->adm_id_supp->setValidator(new QIntValidator(0,99999999,this));

      ui->adm_aj_salaire->setValidator(new QIntValidator(0,99999999,this));
      ui->adm_aj_cin->setValidator(new QIntValidator(0,99999999,this));

      processLabel = new QLabel(this);

      QMovie *movie = new QMovie(":/new/prefix1/image/car-loader-gif-1.gif");

       movie->start();

   processLabel->setWindowFlags(Qt::FramelessWindowHint);

   //processLabel->setMask((new QPixmap(":/image/res/car-loader-gif-1.gif"))->mask());
          if (ui->stackedWidget->currentWidget()==ui->login) {

            movie->setScaledSize(QSize(500,500));

            processLabel->setMovie(movie);

            processLabel->setAttribute(Qt::WA_NoSystemBackground);

            processLabel->setAttribute(Qt::WA_TranslucentBackground,true);

            processLabel->setGeometry(450,100,351,470);

            processLabel->setScaledContents(true);
            scene.addWidget(processLabel);

          }


          son =new QSound("C:/Users/Mayssa/Desktop/gestion_production/projett/son.wav");
          ui->tableView_voiture->setModel(vtmp.afficher());
          ui->tableView_chaine->setModel(ctmp.afficher());
          ui->comboBox_ch->addItem("REFERENCE");
          ui->comboBox_ch->addItem("NB_MACHINE");
          ui->comboBox_ch->addItem("TYPE_PRODUIT");



          //pfd
          model = new QSqlTableModel;
          model->setTable("chaine");
          model->select();

          //controle de saisie sue les entiers
          ui->tableView_chaine->setModel(model);
          ui->lineEdit_prix->setValidator(new QIntValidator(0,999999,this));
          ui->lineEdit_p_op->setValidator(new QIntValidator(0,999999,this));
          ui->lineEdit_reference_voi->setValidator(new QIntValidator(0,99999999,this));
          ui->lineEdit_reference_ch->setValidator(new QIntValidator(0,99999999,this));
          ui->lineEdit_ref_ch->setValidator(new QIntValidator(0,99999999,this));
          ui->lineEdit_nb_mach->setValidator(new QIntValidator(0,999999,this));

          //controle de saisie sur les chaines de caracteres
          ui->lineEdit_maq->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
          ui->lineEdit_marque->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
          ui->lineEdit_mod->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
          ui->lineEdit_modele->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
          ui->lineEdit_couleur->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
          ui->lineEdit_option->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
          ui->lineEdit_type->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
          ui->lineEdit_type_prod->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
/////eya
          //////pdf

          model1 = new QSqlTableModel;
              model1->setTable("client");
              model1->select();
              ui->tabclient_2->setModel(model1);
              //////

              ui->tri_four->addItem("CIN");
               ui->tri_four->addItem("NOM");
                ui->tri_four->addItem("PRENOM");


      //// affichage client et fournisseur
          ui->tabclient_2->setModel(tmpclient.afficher());
          ui->tabfour_2->setModel(tmpfournisseur.afficherFour());

      ///////filtrer les données d'un client

      modClient= new QSqlRelationalTableModel(this);
      modClient->setTable("client");
      modClient->select();
      proxyclient=new QSortFilterProxyModel(this);
      proxyclient->setSourceModel(modClient);
      proxyclient->setFilterCaseSensitivity(Qt::CaseInsensitive);
      proxyclient->setFilterKeyColumn(0);

      ui->tabclient_2->setModel(proxyclient);


      /////////filtrer les donnees fournisseur

      modFournisseur= new QSqlRelationalTableModel(this);
      modFournisseur->setTable("fournisseur");
      modFournisseur->select();
      proxyfournisseur=new QSortFilterProxyModel(this);
      proxyfournisseur->setSourceModel(modFournisseur);
      proxyfournisseur->setFilterCaseSensitivity(Qt::CaseInsensitive);
      proxyfournisseur->setFilterKeyColumn(1);


      ui->tabfour_2->setModel(proxyfournisseur);

      ui->lineEdit_cin_2->setValidator(new QIntValidator(0,99999999,this));
      ui->cinfour_2->setValidator(new QIntValidator(0,99999999,this));
       ui->lineEdit_paiement_2->setValidator(new QIntValidator(0,99999999,this));
       ui->prixpayer_4->setValidator(new QIntValidator(0,99999999,this));
        ui->nbre_2->setValidator(new QIntValidator(0,99999999,this));


       ui->lineEdit_achat_2->setValidator(new QIntValidator(0,99999999,this));
       ui->lineEdit_nom_2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
       ui->lineEdit_prenom_2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
       ui->lineEdit_model_2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
       ui->NomFournisseur_4->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
       ui->prenomfour_2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
       ui->piecedemand_2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));

       ui->choix_2->addItem("reference");
       ui->choix_2->addItem("place");
       ui->choix_2->addItem("nom");

       ui->choix_3->addItem("reference");
       ui->choix_3->addItem("parking number");
       ui->choix_3->addItem("name");

       ui->ln_reference->setValidator(new QIntValidator(0,99999999,this));
       ui->ln_prix->setValidator(new QIntValidator(0,99999999,this));
       ui->ln_compagnie->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
       ui->ln_type->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
       ui->reference_2->setValidator(new QIntValidator( 0,99999999, this ));
       ui->nbr_place_2->setValidator(new QIntValidator( 0,99999999, this ));
       ui->nom_employe_2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));

}


MainWindow::~MainWindow()
{
    if(arduino->isOpen())
    {
        arduino->close();
    }
    delete ui;
}



QByteArray MainWindow::read_from_arduino()
{
  if(arduino->isReadable())
  {
      data=arduino->readAll();

  }
   return data;
}


void MainWindow::write_to_arduino(QByteArray d)
{
  if(arduino->isWritable())
  {
      arduino->write(d);

  }else

      qDebug() <<"couldn't write to serial!";

}

void MainWindow::on_arreter_clicked()
{
      write_to_arduino("0");
}


void MainWindow::on_ajouter_voi_clicked()
{
     son->play();
     QString marque = ui->lineEdit_marque->text();//text pour recuperer les infos des lineedit
     QString modele=ui->lineEdit_modele->text();
     QString type=ui->lineEdit_type->text();
     QString options=ui->lineEdit_option->text();
     QString couleur=ui->lineEdit_couleur->text();
     int prix=ui->lineEdit_prix->text().toInt();
     int  prix_option=ui->lineEdit_p_op->text().toInt();
     int reference=ui->lineEdit_reference_voi->text().toInt();
     voiture v(marque,reference,modele,prix,type,prix_option,couleur,options);
     bool test=v.ajouter();
     if(test)
     {
         ui->tableView_voiture->setModel(vtmp.afficher());
         QMessageBox::information(nullptr, QObject::tr("ajout effectuee"),
                     QObject::tr("voiture ajouté avec succés.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("ajout non effectuee"),
                     QObject::tr("voiture non ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}






void MainWindow::on_ajouter_ch_clicked()
{
     son->play();
     QString type_produit = ui->lineEdit_type_prod->text();
     int  reference=ui->lineEdit_reference_ch->text().toInt();
     int nb_machine=ui->lineEdit_nb_mach->text().toInt();
     chaine c(reference,nb_machine,type_produit);
     bool test=c.ajouter();
     if(test)
     {
          ui->tableView_chaine->setModel(ctmp.afficher());
         QMessageBox::information(nullptr, QObject::tr("ajout effectuee"),
                     QObject::tr("chaine ajouté avec succés.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("ajout non effectuee"),
                     QObject::tr("chaine non ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}





void MainWindow::on_afficher_voi_clicked()
{
      son->play();
 ui->tableView_voiture->setModel(vtmp.afficher());
}

void MainWindow::on_afficher_ch_clicked()
{
      son->play();
      ui->tableView_chaine->setModel(ctmp.afficher());
}


void MainWindow::on_modifier_voi_clicked()
{
  son->play();
    QMessageBox msgBox;
    QMessageBox msgBox1;
     voiture v(ui->lineEdit_maq->text(),ui->lineEdit_reference_voi->text().toInt(),ui->lineEdit_modele->text(),ui->lineEdit_prix->text().toInt(),ui->lineEdit_type->text(),ui->lineEdit_p_op->text().toInt(),ui->lineEdit_couleur->text(),ui->lineEdit_option->text());
     bool test=v.modifier();
    if(test)
    {
       ui->tableView_voiture->setModel(vtmp.afficher());
       msgBox.setText("voiture modifié");
       msgBox.exec();
    }
else
    {
       msgBox1.setText("voiture non modifié");
           msgBox1.exec();
     }

}


void MainWindow::on_supprimer_voi_clicked()
{

     son->play();
     int reference=ui->lineEdit_ref_voi->text().toInt();
    bool test=vtmp.supprimer(reference);
    if(test)
    {
         ui->tableView_voiture->setModel(vtmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("suppression effectuee"),
                    QObject::tr("voiture supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
 }
    else
        QMessageBox::critical(nullptr, QObject::tr("suppression non effectuee"),
                              QObject::tr("voiture non supprimé.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_trier_2_clicked()
{

 son->play();
    int test=0;

      if (ui->comboBox_ch->currentText()=="REFERENCE")
                 {test=1;}

      else if (ui->comboBox_ch->currentText()=="NB_MACHINE")
                  {test=2;}

      else if (ui->comboBox_ch->currentText()=="TYPE_PRODUIT")
                  {test=3;}

      ui->tableView_chaine->setModel(ctmp.trier(test)) ;


 }



void MainWindow::on_rechercher_voi_clicked()
{
        son->play();
     ui->tableView_voiture->setModel(vtmp.recherche(ui->lineEdit_ref_voi->text(),ui->lineEdit_maq->text(),ui->lineEdit_mod->text()));
}



void MainWindow::on_comboBox_ch_currentIndexChanged()
{
     son->play();
   QString REFERENCE = ui->comboBox_ch->currentText();
    QSqlQuery query;
    query.prepare("select*  from CHAINE where REFERENCE =:REFERENCE");
  query.bindValue(":REFERENCE",REFERENCE);
       if(query.exec())
    {
       while(query.next())
{
            ui->lineEdit_ref_ch->setText(query.value(0).toString());
            ui->lineEdit_nb_mach->setText(query.value(1).toString());
            ui->lineEdit_type_prod->setText(query.value(2).toString());
}
    }

}


void MainWindow::on_modifier_ch_clicked()
{
    son->play();
    QSqlQuery query;
    QMessageBox msgBox;
    QMessageBox msgBox1;
    chaine c(ui->lineEdit_ref_ch->text().toInt(),ui->lineEdit_nb_mach->text().toInt(),ui->lineEdit_type_prod->text());
    bool test=c.modifier();
    if(test)
    {
       ui->tableView_chaine->setModel(ctmp.afficher());
       msgBox.setText("chaine modifié");
       msgBox.exec();
    }
else
    {
       msgBox1.setText("chaine non modifié");
           msgBox1.exec();
     }

}


void MainWindow::on_supp_ch_clicked()
{
     son->play();
   bool test=ctmp.supprimer(ui->lineEdit_ref_ch->text().toInt());
   if(test)
   {
        ui->tableView_chaine->setModel(ctmp.afficher());
       QMessageBox::information(nullptr, QObject::tr("suppression effectuee"),
                   QObject::tr("chaine supprimé.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
  }
   else
       QMessageBox::critical(nullptr, QObject::tr("suppression non effectuee"),
                             QObject::tr("chaine non supprimé.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pdf_clicked()
{
    QString strStream;

                 QTextStream out(&strStream);


                 const int rowCount = ui->tableView_chaine->model()->rowCount();

                 const int columnCount = ui->tableView_chaine->model()->columnCount();


                 out <<  "<html>\n"

                     "<head>\n"

                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"

                     <<  QString("<title>%1</title>\n").arg("strTitle")

                     <<  "</head>\n"

                     "<body bgcolor=#ffffff link=#5000A0>\n"


                    //     "<align='right'> " << datefich << "</align>"

                     "<center> <H1>Liste des Agences </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";


                 // headers

                 out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";

                 for (int column = 0; column < columnCount; column++)

                     if (!ui->tableView_chaine->isColumnHidden(column))

                         out << QString("<th>%1</th>").arg(ui->tableView_chaine->model()->headerData(column, Qt::Horizontal).toString());

                 out << "</tr></thead>\n";


                 // data table

                 for (int row = 0; row < rowCount; row++) {

                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";

                     for (int column = 0; column < columnCount; column++) {

                         if (!ui->ag_tab_aff->isColumnHidden(column)) {

                             QString data = ui->tableView_chaine->model()->data(ui->tableView_chaine->model()->index(row, column)).toString().simplified();

                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));

                         }

                     }

                     out << "</tr>\n";

                 }

                 out <<  "</table> </center>\n"

                     "</body>\n"

                     "</html>\n";


           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");

             if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }


            QPrinter printer (QPrinter::PrinterResolution);

             printer.setOutputFormat(QPrinter::PdfFormat);

            printer.setPaperSize(QPrinter::A4);

           printer.setOutputFileName(fileName);


            QTextDocument doc;

             doc.setHtml(strStream);

             doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number

             doc.print(&printer);
}

void MainWindow::on_stat_clicked()
{
     son->play();
    chart=new QChart();
    int pos=0 ;
         QPieSeries *series = new QPieSeries();
         QSqlQuery query ;
        query.prepare("select * from VOITURE1 ") ;
        if(query.exec()) {
            while(query.next()){
       series->append(query.value(1).toString(), query.value(3).toInt());
        QPieSlice *slice = series->slices().at(pos);
        slice->setLabelVisible(true);
        pos++ ;
        }

          chart->addSeries(series);
        chart->setTheme( QChart::ChartThemeDark);

        chart->setAnimationOptions(QChart::AllAnimations);

        chart->setAnimationDuration(2000);

        chart->setAnimationEasingCurve(QEasingCurve::InOutBounce);

                   chart->setTitle("les prix");

                   QChartView *chartview = new QChartView(chart);

                   chartview->setParent(ui->frame_chaine);

                   chartview->setBaseSize(300,300);

                   chartview->setGeometry(0,0,1000,600);


        chart->addSeries(series);
        chart->setTitle("LES PRIX DES DIFFERENT MARQUE");

        chartview->setParent(ui->frame_chaine);
        ui->stackedWidget->setCurrentWidget(ui->page) ;


}
}

void MainWindow::on_tableView_voiture_activated(const QModelIndex &index)
{
  son->play();
        QString  val=ui->tableView_voiture->model()->data(index).toString();
        QSqlQuery qry;


        qry.prepare("select * from VOITURE1  where REFERENCE='"+val+"'or MARQUE='"+val+"'");

        if(qry.exec())
        {
           while(qry.next())
           {
               ui->lineEdit_reference_voi->setText(qry.value(0).toString());

               ui->lineEdit_marque->setText(qry.value(1).toString());

               ui->lineEdit_modele->setText(qry.value(2).toString());

               ui->lineEdit_prix->setText(qry.value(3).toString());

               ui->lineEdit_type->setText(qry.value(4).toString());

               ui->lineEdit_p_op->setText(qry.value(5).toString());

               ui->lineEdit_couleur->setText(qry.value(6).toString());

               ui->lineEdit_option->setText(qry.value(7).toString());



           }
        }
        else
        {
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        }


}

void MainWindow::on_tableView_chaine_activated(const QModelIndex &index)
{
      son->play();
    QString  val=ui->tableView_chaine->model()->data(index).toString();
    QSqlQuery qry;


    qry.prepare("select * from CHAINE  where REFERENCE='"+val+"'or TYPE_PRODUIT='"+val+"'");

    if(qry.exec())
    {
       while(qry.next())
       {
           ui->lineEdit_reference_ch->setText(qry.value(0).toString());

           ui->lineEdit_nb_mach->setText(qry.value(1).toString());

           ui->lineEdit_type_prod->setText(qry.value(2).toString());

       }
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}




void MainWindow::on_btn_login_clicked()
{
    employer e ;

    if(e.auth(ui->logpass->text(),ui->log_add->text() ) ) {


      QSqlQuery query   ;
      query.prepare("SELECT *  FROM TABLE1 WHERE PASSE=:passe AND ADRESSE=:adresse");
      query.bindValue(":passe",ui->logpass->text());
      query.bindValue(":adresse", ui->log_add->text()) ;
    //  query.exec() ;
     if (query.exec()&&query.next()) {


          processLabel->hide() ;

          QSound *son=new QSound(":/new/prefix1/image/Welcome - Male Voice Speaks (128 kbps) (mp3cut.net)(1).wav");
          son->play() ;
         if(query.value(4).toString()=="administrateur") {
    //        ui->tabWidget->insertTab(max,ui->adm_menu,"Home") ;

    ui->stackedWidget->setCurrentWidget(ui->Menu) ;
         }

       else {

          //   processLabel->close() ;
     //   ui->tabWidget->insertTab(max,ui->em_profil,"Profile") ;
        ui->aff_cin->setText(query.value(0).toString() );
        ui->aff_nom->setText(query.value(1).toString() );
        ui->aff_prenom->setText(query.value(2).toString() );
        ui->aff_sal->setText(query.value(3).toString() );
        ui->aff_poste->setText(query.value(4).toString() );
         if(query.value(5).toString()=="married"){

}
         else
             ui->aff_combo_etat->setCurrentIndex(1) ;

         ui->stackedWidget->setCurrentWidget(ui->employer) ;
  }
     }




ui->logpass->clear() ;
ui->log_add->clear() ;
    }

}

void MainWindow::on_ajouterFour_clicked()
{
    if(ui->adm_aj_cin->text().isEmpty()||ui->adm_aj_salaire->text().isEmpty()||ui->adm_aj_nom->text().isEmpty()|| ui->adm_aj_prenom->text().isEmpty() ||ui->adm_aj_poste->text().isEmpty() ) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
        QObject::tr("Information incomplete.\n""Click Cancel to exit."), QMessageBox::Cancel);
}


   else {

       int count=0 ;
        QSqlQuery query ;
        query.prepare("SELECT * FROM  TABLE1 where CIN = :cin ");

        query.bindValue(":cin", ui->adm_aj_cin->text().toInt() );

        if(query.exec())

        {


            while(query.next())

            {

                count++;

            }

            if(count!=0)

            {

                QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                QObject::tr(" CIN existe deja !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }

            if(count==0 )

            {
                int cin=ui->adm_aj_cin->text().toInt() ;
                int salaire=ui->adm_aj_salaire->text().toInt() ;
                QString nom=ui->adm_aj_nom->text() ;
                QString prenom=ui->adm_aj_prenom->text() ;
                QString poste=ui->adm_aj_poste->text()  ;
                QString etat=ui->adm_aj_combo_etat->currentText() ;
                int nombre=ui->adm_aj_spin_nbrenfant->value() ;
                QDateTime time ;
                QString passe= ui->adm_aj_cin->text()+ui->adm_aj_spin_nbrenfant->text()+ui->adm_aj_cin->text()+ui->adm_aj_spin_nbrenfant->text();
                QString adresse=nom+"."+prenom+".factory@gamil.com" ;





                employer e(cin,nom,prenom,poste,etat,adresse,passe,salaire,nombre) ;





                 if(e.ajouter()) {
                     QMessageBox::information(nullptr, QObject::tr("OK "),
                     QObject::tr(" Employer ajouter avec succes ok.\n""Click Cancel to exit."), QMessageBox::Cancel);
                     ui->adm_tab_aff->setModel(e.afficher());
                 }
                 else {
                     QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                     QObject::tr("Probleme de conixion.\n""Click Cancel to exit."), QMessageBox::Cancel);

                 }


            }



        }



    }
}

void MainWindow::on_afficherfour_clicked()
{
    employer  e ;
    ui->adm_tab_aff->setModel(e.afficher());

}

void MainWindow::on_trier_clicked()
{
    QSqlQueryModel *model=new QSqlQueryModel() ;
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

void MainWindow::on_quitter_clicked()
{
    if(ui->adm_id_supp->text().isEmpty()) {

        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Information incomplete !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

    else {



            QSqlQuery query;


        int count =0;

            query.prepare("SELECT * FROM  TABLE1 where CIN = :cin ");

            query.bindValue(":cin", ui->adm_id_supp->text().toInt());

            if(query.exec())

            {


                while(query.next())

                {

                    count++;

                }

                if(count!=0)

                {

                      employer e ;
                     int id=ui->adm_id_supp->text().toUInt() ;
                      if(e.supprimer(id))  {



                          QMessageBox::information(nullptr, QObject::tr(" OK"),
                          QObject::tr("employe supprimer avec succes !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

                      ui->adm_tab_aff->setModel(e.afficher());
                      }
                      else {
                          QMessageBox::critical(nullptr, QObject::tr(" Erreur"),
                          QObject::tr("Probleme de conixion !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);


                      }

                }

                if(count==0 )

                {

                    QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("CIN NOT FOUND !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                }



            }



 }
}

void MainWindow::on_adm_tab_aff_activated(const QModelIndex &index)
{


    QString  val=ui->adm_tab_aff->model()->data(index).toString();

    QSqlQuery query;
   query.prepare("select * from TABLE1  where CIN='"+val+"'or NOM='"+val+"'");

    if(query.exec())
    {
       while(query.next())
       {
           ui->adm_aj_cin->setText(query.value(0).toString() );
           ui->adm_aj_nom->setText(query.value(1).toString() );
           ui->adm_aj_prenom->setText(query.value(2).toString() );
           ui->adm_aj_salaire->setText(query.value(3).toString() );
           ui->adm_aj_poste->setText(query.value(4).toString() );
            if(query.value(5).toString()=="MARRIED"){
           ui->adm_aj_combo_etat->setCurrentIndex(1) ;
           }
            else
             ui->adm_aj_combo_etat->setCurrentIndex(0) ;
           ui->adm_aj_spin_nbrenfant->setValue(query.value(6).toInt()) ;


       }
    }

}

void MainWindow::on_modifier_emp_clicked()
{  if (ui->adm_aj_nom->text().isEmpty()||ui->adm_aj_prenom->text().isEmpty()||ui->adm_aj_salaire->text().isEmpty()||ui->adm_aj_poste->text().isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("inforamation incomplete !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else {

        QSqlQuery query ;
        QString passe= ui->adm_aj_cin->text()+ui->adm_aj_spin_nbrenfant->text()+ui->adm_aj_cin->text()+ui->adm_aj_spin_nbrenfant->text();
        QString adresse=ui->adm_aj_nom->text()+"."+ui->adm_aj_prenom->text()+".factory@gamil.com" ;

        //query.prepare("UPDATE  TABLE1 SET CIN='" +  ui->adm_aj_cin_2->text() + "' ,NAME='"+ ui->adm_aj_nom_2->text()+"' ,PRENOM= '"+ui->adm_aj_prenom_2->text()+"' ,SALAIRE='"+ui->adm_aj_salaire_2->text().toInt()+"',POSTE'"+ui->adm_aj_poste_2->text()+"',ETAT='"+ui->adm_mod_aff_combo_etat->currentText()+"',NOMBRE='"+ ui->adm_aj_spin_nbrenfant_2->value()+"',PASSE= '"+passe+ "',ADRESSE='"+adresse+ "' WHERE ,CIN='"+ui->adm_aj_cin_2->text() +"'") ;

        query.prepare("UPDATE  TABLE1 SET  NOM=:nom, PRENOM=:prenom,SALAIRE=:salaire,POSTE=:poste,ETAT=:etat,NOMBRE=:nombre,ADRESSE=:adresse,PASSE=:passe WHERE CIN=:cin ");

    query.bindValue(":cin",ui->adm_aj_cin->text().toInt());
    query.bindValue(":nom", ui->adm_aj_nom->text());
    query.bindValue(":prenom",ui->adm_aj_prenom->text());
    query.bindValue(":salaire", ui->adm_aj_salaire->text().toInt());
    query.bindValue(":poste",ui->adm_aj_poste->text());
    query.bindValue(":etat",ui->adm_aj_combo_etat->currentText());
    query.bindValue(":nombre",ui->adm_aj_spin_nbrenfant->value());
    query.bindValue(":adresse",adresse);
    query.bindValue(":passe",passe);

if(query.exec()) {

    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("SUCCES,OK  !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
employer e ;
 ui->adm_tab_aff->setModel(e.afficher());
}
else {
    QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                QObject::tr("Probleme de conixion ,  !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
//query.next() ;
 }
}



void MainWindow::on_ajouter_agence_clicked()
{
    if(ui->ag_aj_id->text().isEmpty()|| ui->ag_aj_nom->text().isEmpty()||  ui->ag_aj_adresse->text().isEmpty()|| ui->ag_aj_cin->text().isEmpty() )
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("information  incomplete,OK  !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
      }

    else {
        int count=0 ;
         QSqlQuery query ;
         query.prepare("SELECT * FROM  AGENCE where ID = :id ");

         query.bindValue(":id", ui->ag_aj_id->text()  );

         if(query.exec())

         {


             while(query.next())

             {

                 count++;

             }

             if(count!=0)

             {

                 QMessageBox::critical(nullptr, QObject::tr(" Erreur"),
                 QObject::tr(" ID existe deja !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

             }

             if(count==0 )

             {

                 QString id=ui->ag_aj_id->text() ;
                 QString nom=ui->ag_aj_nom->text();
                 QString adresse=ui->ag_aj_adresse->text();
                 QDate date=ui->ag_aj_dateEdit->date() ;
                 int nbr_emp=ui->aj_ag_spinBox_nbremp->value()  ;
                 int  cin_d=ui->ag_aj_cin->text().toInt() ;
                 int  nbr_v=ui->aj_ag_spinBox_nb_vente->text().toInt() ;
                 QDateTime time ;

                 //QString passe= ui->adm_aj_cin->text()+ui->adm_aj_spin_nbrenfant->text();
                 //QString adresse=nom+"."+prenom+"_factory@gamil.com" ;

                 //employer e(cin,nom,prenom,poste,etat,adresse,passe,salaire,nombre) ;
             agence ag(id,nom,adresse,date,nbr_emp,cin_d,nbr_v) ;

             if (ag.ajouter() ) {
                 QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Agence ajouter avec succès ,OK  !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

             ui->ag_tab_aff->setModel(ag.afficher());
             }
             else {
                 QMessageBox::critical(nullptr, QObject::tr(" Erreur"),
                             QObject::tr("Probeleme de conixion ,OK  !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

             }




                  }



    }
    }
}

void MainWindow::on_afficher_agence_clicked()
{
 agence ag ;
 ui->ag_tab_aff->setModel(ag.afficher());
}

void MainWindow::on_supprimer_agence_clicked()
{
    if(ui->ag_id_supp->text().isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr(" ID VIDE !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else {

        int count=0 ;
         QSqlQuery query ;
         query.prepare("SELECT * FROM  AGENCE where ID = :id ");

         query.bindValue(":id", ui->ag_id_supp->text() );

         if(query.exec())

         {


             while(query.next())

             {

                 count++;

             }

             if(count!=0)

             {
                 agence ag ;
              QString id=ui->ag_id_supp->text() ;
             if(  ag.supprimer(id))  {
                 QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Agence supprimer avec succes !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
                            ui->ag_tab_aff->setModel(ag.afficher());
             }
             else {
                             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("probleme de conixion !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             }

             }

             if(count==0 )

             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                 QObject::tr("ID nexiste pas  !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
             }


             }

    }
}

void MainWindow::on_ag_tab_aff_activated(const QModelIndex &index)
{
    QString  val=ui->ag_tab_aff->model()->data(index).toString();

    QSqlQuery query;
   query.prepare("select * from AGENCE  where ID='"+val+"'or NOM='"+val+"'");

    if(query.exec())
    {
       while(query.next())
       {
           ui->ag_aj_id->setText(query.value(0).toString() );
           ui->ag_aj_nom->setText(query.value(1).toString() );
           ui->ag_aj_adresse->setText(query.value(2).toString() );
           ui->ag_aj_dateEdit->setDate(query.value(3).toDate() );
           ui->aj_ag_spinBox_nbremp->setValue(query.value(4).toInt() );
           ui->aj_ag_spinBox_nb_vente->setValue(query.value(6).toInt() ) ;
           ui->ag_aj_cin->setText(query.value(5).toString()) ;


       }
    }

}

void MainWindow::on_modifier_agence_clicked()
{
    if (ui->ag_aj_nom->text().isEmpty()||ui->ag_aj_adresse->text().isEmpty()||ui->ag_aj_cin->text().isEmpty() ) {
        QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                    QObject::tr(" Inforamation incomplete !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else {

    QSqlQuery query ;
    //QString passe= ui->adm_aj_cin_2->text()+ui->adm_aj_spin_nbrenfant_2->text();
    //QString adresse=ui->adm_aj_nom_2->text()+"."+ui->adm_aj_prenom_2->text()+"_factory@gamil.com" ;

    //query.prepare("UPDATE  TABLE1 SET CIN='" +  ui->adm_aj_cin_2->text() + "' ,NAME='"+ ui->adm_aj_nom_2->text()+"' ,PRENOM= '"+ui->adm_aj_prenom_2->text()+"' ,SALAIRE='"+ui->adm_aj_salaire_2->text().toInt()+"',POSTE'"+ui->adm_aj_poste_2->text()+"',ETAT='"+ui->adm_mod_aff_combo_etat->currentText()+"',NOMBRE='"+ ui->adm_aj_spin_nbrenfant_2->value()+"',PASSE= '"+passe+ "',ADRESSE='"+adresse+ "' WHERE ,CIN='"+ui->adm_aj_cin_2->text() +"'") ;

    query.prepare("UPDATE  AGENCE SET  ID=:id, NOM=:nom,ADRESSE=:adresse,D=:d,EMPLOYER=:employer,DIRECTEUR=:directeur,VENTE=:vente WHERE ID=:cin");
    query.bindValue(":cin",ui->ag_aj_id->text()) ;
    query.bindValue(":id", ui->ag_aj_id->text());
    query.bindValue(":nom", ui->ag_aj_nom->text());
    query.bindValue(":adresse",ui->ag_aj_adresse->text());
    query.bindValue(":d", ui->ag_aj_dateEdit->date());
    query.bindValue(":employer", ui->aj_ag_spinBox_nbremp->text().toInt());
    query.bindValue(":directeur",ui->ag_aj_cin->text().toInt());
    query.bindValue(":vente",ui->aj_ag_spinBox_nb_vente->text().toInt());


    if(query.exec()) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr(" Agence modifier avec succes !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        agence ag ;
        ui->ag_tab_aff->setModel(ag.afficher());
 }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Probleme de conixion !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

    }
}

void MainWindow::on_imprimer_clicked()
{
    QPrinter printer;


    printer.setPrinterName("desiered printer name");


  QPrintDialog dialog(&printer,this);


    if(dialog.exec()== QDialog::Rejected)


        return;
}

void MainWindow::on_btn_exporter_clicked()
{
    QString strStream;

                 QTextStream out(&strStream);


                 const int rowCount = ui->ag_tab_aff->model()->rowCount();

                 const int columnCount = ui->ag_tab_aff->model()->columnCount();


                 out <<  "<html>\n"

                     "<head>\n"

                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"

                     <<  QString("<title>%1</title>\n").arg("strTitle")

                     <<  "</head>\n"

                     "<body bgcolor=#ffffff link=#5000A0>\n"


                    //     "<align='right'> " << datefich << "</align>"

                     "<center> <H1>Liste des Agences </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";


                 // headers

                 out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";

                 for (int column = 0; column < columnCount; column++)

                     if (!ui->ag_tab_aff->isColumnHidden(column))

                         out << QString("<th>%1</th>").arg(ui->ag_tab_aff->model()->headerData(column, Qt::Horizontal).toString());

                 out << "</tr></thead>\n";


                 // data table

                 for (int row = 0; row < rowCount; row++) {

                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";

                     for (int column = 0; column < columnCount; column++) {

                         if (!ui->ag_tab_aff->isColumnHidden(column)) {

                             QString data = ui->ag_tab_aff->model()->data(ui->ag_tab_aff->model()->index(row, column)).toString().simplified();

                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));

                         }

                     }

                     out << "</tr>\n";

                 }

                 out <<  "</table> </center>\n"

                     "</body>\n"

                     "</html>\n";


           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");

             if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }


            QPrinter printer (QPrinter::PrinterResolution);

             printer.setOutputFormat(QPrinter::PdfFormat);

            printer.setPaperSize(QPrinter::A4);

           printer.setOutputFileName(fileName);


            QTextDocument doc;

             doc.setHtml(strStream);

             doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number

             doc.print(&printer);
}

void MainWindow::on_btn_statistique_clicked()
{
   /* int pos=0 ;
       QChart *chart = new QChart();

         QPieSeries *series = new QPieSeries();

         QSqlQuery query ;
        query.prepare("select * from AGENCE ") ;
        if(query.exec()) {
            while(query.next()){
        series->append(query.value(1).toString(), query.value(6).toInt());
        QPieSlice *slice = series->slices().at(pos);
        //slice->setExploded(true);
        slice->setLabelVisible(true);
        pos++ ;
        }
   }




          chart->setTheme( QChart::ChartThemeDark);

          chart->setAnimationOptions(QChart::AllAnimations);

          chart->setAnimationDuration(2000);

          chart->setAnimationEasingCurve(QEasingCurve::InOutBounce);

                     chart->setTitle("nombre de produit");

                     QChartView *chartview = new QChartView(chart);

                     chartview->setParent(ui->horizontalFrame);

                  //   chartview->setBaseSize(300,300);

                     chartview->setGeometry(-100,-180,981,821);


          chart->addSeries(series);
          chart->setTitle("NOMBRE DE VANETE");

          chartview->setParent(ui->horizontalFrame);
          ui->stackedWidget->setCurrentWidget(ui->statistique) ;

*/
}

void MainWindow::on_reclamation_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;
    //QString a ;

    //qDebug()<<(ui->textEdit->document()->isEmpty()) ;

    if(ui->textEdit->document()->isEmpty()) {

         QMessageBox::critical(nullptr, QObject::tr("MAIL Denied"),
         QObject::tr("Desole le mail est vide .\n""Click Cancel to exit."), QMessageBox::Cancel);
     }
    else {
        // This is a first demo application of the SmtpClient for Qt project


        // First we need to create an SmtpClient object
        // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

        SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        // We need to set the username (your email address) and password
        // for smtp authentification.

        smtp.setUser(ui->log_add->text());
        smtp.setPassword(ui->logpass->text());

        // Now we create a MimeMessage object. This is the email.

        MimeMessage message;
        QString name =ui->adm_aj_nom->text() ;
        EmailAddress sender(ui->log_add->text(), name );
        message.setSender(&sender);

        EmailAddress to("ros.ch.factory@gmail.com", "Recipient's Name");
        message.addRecipient(&to);

        message.setSubject("RECLAMATION");

        // Now add some text to the email.
        // First we create a MimeText object.

        MimeText text;

        text.setText(ui->textEdit->toPlainText());

        // Now add it to the mail

        message.addPart(&text);

        // Now we can send the mail

        if (!smtp.connectToHost()) {
            qDebug() << "Failed to connect to host!" << endl;

        }

        if (!smtp.login()) {
            qDebug() << "Failed to login!" << endl;

        }

        if (!smtp.sendMail(message)) {
            qDebug() << "Failed to send mail!" << endl;
            QMessageBox::critical(nullptr, QObject::tr("MAILING"),
            QObject::tr(" Mail NO send .\n""Click Cancel to exit."), QMessageBox::Cancel);


        }
        else {
            QMessageBox::information(nullptr, QObject::tr("OK"),
            QObject::tr("Mail envoye .\n""Click Cancel to exit."), QMessageBox::Cancel);

        }

        smtp.quit();
}
}

/*
void MainWindow::on_btn_em_rec_clicked()
{
    //QString a ;

    //qDebug()<<(ui->textEdit->document()->isEmpty()) ;

    if(ui->textEdit->document()->isEmpty()) {

         QMessageBox::critical(nullptr, QObject::tr("MAIL Denied"),
         QObject::tr("Desole le mail est vide .\n""Click Cancel to exit."), QMessageBox::Cancel);
     }
    else {
        // This is a first demo application of the SmtpClient for Qt project


        // First we need to create an SmtpClient object
        // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

        SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        // We need to set the username (your email address) and password
        // for smtp authentification.

        smtp.setUser(ui->log_add->text());
        smtp.setPassword(ui->logpass->text());

        // Now we create a MimeMessage object. This is the email.

        MimeMessage message;
        QString name =ui->adm_aj_nom->text() ;
        EmailAddress sender(ui->log_add->text(), name );
        message.setSender(&sender);

        EmailAddress to("ros.ch.factory@gmail.com", "Recipient's Name");
        message.addRecipient(&to);

        message.setSubject("RECLAMATION");

        // Now add some text to the email.
        // First we create a MimeText object.

        MimeText text;

        text.setText(ui->textEdit->toPlainText());

        // Now add it to the mail

        message.addPart(&text);

        // Now we can send the mail

        if (!smtp.connectToHost()) {
            qDebug() << "Failed to connect to host!" << endl;

        }

        if (!smtp.login()) {
            qDebug() << "Failed to login!" << endl;

        }

        if (!smtp.sendMail(message)) {
            qDebug() << "Failed to send mail!" << endl;
            QMessageBox::critical(nullptr, QObject::tr("MAILING"),
            QObject::tr(" Mail NO send .\n""Click Cancel to exit."), QMessageBox::Cancel);


        }
        else {
            QMessageBox::information(nullptr, QObject::tr("OK"),
            QObject::tr("Mail envoye .\n""Click Cancel to exit."), QMessageBox::Cancel);

        }

        smtp.quit();

    }
    
 }

*/


void MainWindow::on_btn_resource_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->admin) ;
}

void MainWindow::on_pushButton_3_clicked()
{

 processLabel->show() ;

      ui->stackedWidget->setCurrentWidget(ui->login) ;

}

void MainWindow::on_btn_existe_clicked()
{

        processLabel->show() ;

        ui->stackedWidget->setCurrentWidget(ui->login) ;

}

void MainWindow::on_btn_existe_2_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->Menu) ;
}

void MainWindow::on_btn_retour_em_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->employer) ;
}

void MainWindow::on_btn_retour_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->Menu) ;
}

void MainWindow::on_btn_existe_3_clicked()
{
      ui->stackedWidget->setCurrentWidget(ui->Menu) ;
}

void MainWindow::on_btn_Production_clicked()
{

    ui->stackedWidget->setCurrentWidget(ui->voiture_ch) ;
}

void MainWindow::on_btn_existe_4_clicked()
{
        ui->stackedWidget->setCurrentWidget(ui->Menu) ;
}

void MainWindow::on_btn_existe_5_clicked()
{
      ui->stackedWidget->setCurrentWidget(ui->voiture_ch) ;
}



void MainWindow::on_btn_echange_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->echange) ;
}

void MainWindow::on_aff_four_clicked()
{
    ui->tabfour_2->setModel(tmpfournisseur.afficherFour());
}

void MainWindow::on_ajout_four_clicked()
{
    QString cin=ui->cinfour_2->text();
     QString nom=ui->NomFournisseur_4->text();
      QString prenom=ui->prenomfour_2->text();
       QDate dateLimite=ui->date_limite_2->date();
        QString piece_demandee=ui->piecedemand_2->text();
        QString nbre_piece=ui->nbre_2->text();
      QString prix_apayer=ui->prixpayer_4->text();
     fournisseur F(cin,nom,prenom,piece_demandee,nbre_piece,prix_apayer,dateLimite);
       bool test=F.ajouterFour();
       if(test)
       {
           ui->tabfour_2->setModel(tmpfournisseur.afficherFour()); //refresh


           modFournisseur= new QSqlRelationalTableModel(this);
           modFournisseur->setTable("fournisseur");
           modFournisseur->select();
           proxyfournisseur=new QSortFilterProxyModel(this);
           proxyfournisseur->setSourceModel(modFournisseur);
           proxyfournisseur->setFilterCaseSensitivity(Qt::CaseInsensitive);
           proxyfournisseur->setFilterKeyColumn(1);


           ui->tabfour_2->setModel(proxyfournisseur);

           QMessageBox::information(nullptr, QObject::tr("ajouter un fournisseur"),
                       QObject::tr("fournisseur ajouté.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("ajouter un fournisseur"),
                       QObject::tr("ajout échoué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


       }
}

void MainWindow::on_trier_four_clicked()
{
    int test=0;


             if (ui->tri_four->currentText()=="CIN")
            {test=1;}
        else
                 if (ui->tri_four->currentText()=="NOM")
                {
                     test=2;
                 }
          else
                     if (ui->tri_four->currentText()=="PRENOM")
                     {
                         test=3;
                     }



                ui->tabfour_2->setModel(tmpc.trier(test)) ;

}

void MainWindow::on_chercher_four_clicked()
{
    ui->tabfour_2->setModel(tmpfournisseur2.rechercherfournisseur(ui->cincherf_2->text(),ui->cherf_nom_2->text(),ui->cherf_prenom_2->text()));
}

void MainWindow::on_modif_four_clicked()
{
    QString CIN=ui->cincherf_2->text();
     QString cin=ui->cinfour_2->text();



      QString nom=ui->NomFournisseur_4->text();
       QString prenom=ui->prenomfour_2->text();
        QDate dateLimite=ui->date_limite_2->date();
         QString piece_demandee=ui->piecedemand_2->text();
         QString nbre_piece=ui->nbre_2->text();
       QString prix_apayer=ui->prixpayer_4->text();
      fournisseur F(cin,nom,prenom,piece_demandee,nbre_piece,prix_apayer,dateLimite);


        bool test=F.modifierFour(CIN);
        if(test)
        {
            ui->tabfour_2->setModel(tmpfournisseur.afficherFour()); //refresh
            modFournisseur= new QSqlRelationalTableModel(this);
            modFournisseur->setTable("fournisseur");
            modFournisseur->select();
            proxyfournisseur=new QSortFilterProxyModel(this);
            proxyfournisseur->setSourceModel(modFournisseur);
            proxyfournisseur->setFilterCaseSensitivity(Qt::CaseInsensitive);
            proxyfournisseur->setFilterKeyColumn(1);


            ui->tabfour_2->setModel(proxyfournisseur);


            QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                        QObject::tr("done.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("modifier un fournisseur"),
                        QObject::tr("try again.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


        }

}

void MainWindow::on_supp_four_clicked()
{
    QString CIN=ui->cincherf_2->text();
    bool test=tmpfournisseur.supprimerFour(CIN);
    if(test)
    {
        ui->tabfour_2->setModel(tmpfournisseur.afficherFour());
        ui->tabfour_2->setModel(tmpfournisseur.afficherFour()); //refresh
        modFournisseur= new QSqlRelationalTableModel(this);
        modFournisseur->setTable("fournisseur");
        modFournisseur->select();
        proxyfournisseur=new QSortFilterProxyModel(this);
        proxyfournisseur->setSourceModel(modFournisseur);
        proxyfournisseur->setFilterCaseSensitivity(Qt::CaseInsensitive);
        proxyfournisseur->setFilterKeyColumn(1);


        ui->tabfour_2->setModel(proxyfournisseur);

        QMessageBox::information(nullptr, QObject::tr("supprimer fournisseur"),
                    QObject::tr("fournisseur supprime.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("supprimer un fournisseur"),
                    QObject::tr("suppression échouée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }

}

void MainWindow::on_ajouter_client_clicked()
{
    QString cin=ui->lineEdit_cin_2->text();
     QString nom=ui->lineEdit_nom_2->text();
      QString prenom=ui->lineEdit_prenom_2->text();
       QDate date_naissance=ui->date_naissance_2->date();
        QString achat=ui->lineEdit_achat_2->text();
        QString model_choisi=ui->lineEdit_model_2->text();
      QString paiement=ui->lineEdit_paiement_2->text();
     Client C(cin,nom,prenom,achat,paiement,model_choisi,date_naissance);
       bool test=C.ajouter();
       if(test)
       {
           ui->tabclient_2->setModel(tmpclient.afficher()); //refresh
          /*modClient= new QSqlRelationalTableModel(this);
           modClient->setTable("client");
           modClient->select();
           proxyclient=new QSortFilterProxyModel(this);
           proxyclient->setSourceModel(modClient);
           proxyclient->setFilterCaseSensitivity(Qt::CaseInsensitive);
           proxyclient->setFilterKeyColumn(0);

           ui->tabclient->setModel(proxyclient);*/






           //ui->tabclient->setModel(tmpclient.rechercherclient(ui->cin_chercher->text(),ui->cher_nom->text(),ui->cher_prenom->text()));
           QMessageBox::information(nullptr, QObject::tr("ajouter un client"),
                       QObject::tr("client ajouté.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("ajouter un client"),
                       QObject::tr("ajout échoué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


       }
}

void MainWindow::on_aff_client_clicked()
{
  ui->tabclient_2->setModel(tmpclient.afficher());
}

void MainWindow::on_cher_client_clicked()
{
  ui->tabclient_2->setModel(tmpclient2.rechercherclient(ui->cin_chercher_2->text(),ui->cher_nom_2->text(),ui->cher_prenom_2->text()));
}

void MainWindow::on_mod_client_clicked()
{
    QString CIN=ui->cin_chercher_2->text();
        QString cin=ui->lineEdit_cin_2->text();
         QString nom=ui->lineEdit_nom_2->text();
          QString prenom=ui->lineEdit_prenom_2->text();
           QDate date_naissance=ui->date_naissance_2->date();
            QString achat=ui->lineEdit_achat_2->text();
            QString model_choisi=ui->lineEdit_model_2->text();
          QString paiement=ui->lineEdit_paiement_2->text();
         Client C(cin,nom,prenom,achat,paiement,model_choisi,date_naissance);
           bool test=C.modifier(CIN);
           if(test)
           {
               ui->tabclient_2->setModel(tmpclient.afficher()); //refresh
               modClient= new QSqlRelationalTableModel(this);
               modClient->setTable("client");
               modClient->select();
               proxyclient=new QSortFilterProxyModel(this);
               proxyclient->setSourceModel(modClient);
               proxyclient->setFilterCaseSensitivity(Qt::CaseInsensitive);
               proxyclient->setFilterKeyColumn(0);

               ui->tabclient_2->setModel(proxyclient);
               QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                           QObject::tr("done.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

           }
           else
           {
               QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
                           QObject::tr("try again.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);


           }
}

void MainWindow::on_supp_client_clicked()
{
    QString CIN=ui->cin_chercher_2->text();
    bool test=tmpclient.supprimer(CIN);
    if(test)
    {
        ui->tabclient_2->setModel(tmpclient.afficher());
        ui->tabclient_2->setModel(tmpclient.afficher()); //refresh
        modClient= new QSqlRelationalTableModel(this);
        modClient->setTable("client");
        modClient->select();
        proxyclient=new QSortFilterProxyModel(this);
        proxyclient->setSourceModel(modClient);
        proxyclient->setFilterCaseSensitivity(Qt::CaseInsensitive);
        proxyclient->setFilterKeyColumn(-1);




        ui->tabclient_2->setModel(proxyclient);
        QMessageBox::information(nullptr, QObject::tr("supprimer un client"),
                    QObject::tr("client supprimer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("supprimer un client"),
                    QObject::tr("suppression échouée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }


}

void MainWindow::on_tabclient_2_activated(const QModelIndex &index)
{
    QString  val=ui->tabclient_2->model()->data(index).toString();
    QSqlQuery qry;


    qry.prepare("select * from client  where CIN='"+val+"'or nom='"+val+"'");

    if(qry.exec())
    {
       while(qry.next())
       {
           ui->lineEdit_cin_2->setText(qry.value(0).toString());

           ui->lineEdit_prenom_2->setText(qry.value(1).toString());

           ui->lineEdit_nom_2->setText(qry.value(2).toString());

           ui->lineEdit_model_2->setText(qry.value(3).toString());

           ui->lineEdit_achat_2->setText(qry.value(4).toString());

           ui->lineEdit_paiement_2->setText(qry.value(5).toString());
ui->date_naissance_2->setDate(qry.value(6).toDate());



       }
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}

void MainWindow::on_tabfour_2_activated(const QModelIndex &index)
{
    QString  val=ui->tabfour_2->model()->data(index).toString();

    QSqlQuery qry;
   qry.prepare("select * from fournisseur  where CIN='"+val+"'or nom='"+val+"'");

    if(qry.exec())
    {
       while(qry.next())
       {
           ui->cinfour_2->setText(qry.value(0).toString());
           ui->NomFournisseur_4->setText(qry.value(1).toString());
           ui->prenomfour_2->setText(qry.value(2).toString());
           ui->piecedemand_2->setText(qry.value(3).toString());
           ui->nbre_2->setText(qry.value(5).toString());
           ui->prixpayer_4->setText(qry.value(4).toString());
           ui->date_limite_2->setDate(qry.value(6).toDate());


       }
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}


void MainWindow::on_btn_existe_6_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Menu) ;
}

void MainWindow::on_btn_service_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->service);
}

void MainWindow::on_btn_existe_7_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Menu) ;
}

void MainWindow::on_btn_existe_8_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Menu) ;
}

void MainWindow::on_ajouter_assu_clicked()
{
    // recuperer les informations saisies dans l'interface
     QString compagnie = ui->ln_compagnie->text();
     int prix = ui->ln_prix->text().toInt();
     QString type = ui->ln_type->text();
     int reference = ui->ln_reference->text().toInt();

     Assurance A(compagnie,prix,type,reference);
     bool test=A.ajouter();

     if(test)
     {
         ui->tableView_assurance->setModel(tmp.afficher()); // refresh => chaque ajout sera affiché
         QMessageBox::information(nullptr, QObject::tr("Assurance Ajoutée"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

 }
     else
         QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Ajoutée"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     ui->ln_compagnie->clear();
        ui->ln_type->clear();
        ui->ln_prix->clear();
        ui->ln_reference->clear();
}

void MainWindow::on_mod_assu_clicked()
{
    QString compagnie,type,reference,prix;
    //int reference,prix;
    compagnie=ui->ln_compagnie->text();
    type=ui->ln_type->text();
    prix=ui->ln_prix->text();
    reference=ui->ln_reference->text();

    QSqlQuery qry;
    qry.prepare("update assurance set reference='"+reference+"',type='"+type+"',prix='"+prix+"',compagnie='"+compagnie+"'where reference='"+reference+"'");
    if(qry.exec())
    {
        ui->tableView_assurance->setModel(tmp.afficher());
        //ui->tableView_upark->setModel(tmp.afficher());
        QMessageBox::information(this,tr("Edit"),tr("Updated"));

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Modifiée"),
                              QObject::tr("OK.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }
    ui->ln_compagnie->clear();
       ui->ln_type->clear();
       ui->ln_prix->clear();
       ui->ln_reference->clear();

}

void MainWindow::on_export_pdf_clicked()
{
    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tableView_assurance->model()->rowCount();
                     const int columnCount = ui->tableView_assurance->model()->columnCount();

                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView_assurance->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView_assurance->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView_assurance->isColumnHidden(column)) {
                                 QString data = ui->tableView_assurance->model()->data(ui->tableView_assurance->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n"
                         "</body>\n"
                         "</html>\n";

               QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                 if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                QPrinter printer (QPrinter::PrinterResolution);
                 printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName(fileName);

                QTextDocument doc;
                 doc.setHtml(strStream);
                 doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                 doc.print(&printer);
}

void MainWindow::on_recherche_clicked()
{
    ui->tableView_assurance->setModel(tmp.recherche(ui->reref->text().toInt(),ui->retype->text(),ui->recom->text()));
    ui->retype->clear();
       ui->reref->clear();
       ui->recom->clear();
}

void MainWindow::on_afficher_tab_assu_clicked()
{
    ui->tableView_assurance->setModel(tmp.afficher());
}

void MainWindow::on_park_ajout_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    int reference = ui->reference_2->text().toInt();
    int place = ui->nbr_place_2->text().toInt();
    QString nom = ui->nom_employe_2->text();

    Parking P(reference,place,nom);
    model=P.recherche(nom,place);
    if(model==0)
    {
        bool test=P.ajouter();
        if(test)
        {
            ui->tableView_parking_2->setModel(tmp1.afficher());
            QMessageBox::information(nullptr, QObject::tr("Parking ajouté"),
                         QObject::tr("OK.\n"
                                     "Click Cancel to exit"),QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr, QObject::tr("Parking pas ajouté"),
                         QObject::tr("OK.\n"
                                     "Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Nom ou Place Deja Utilisée"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit."),QMessageBox::Cancel);
        ui->nbr_place_2->clear();
           ui->nom_employe_2->clear();
           ui->reference_2->clear();
}

void MainWindow::on_mod_park_2_clicked()
{
    QString reference,place,nom;
    reference=ui->reference_2->text();
    place=ui->nbr_place_2->text();
    nom=ui->nom_employe_2->text();

    QSqlQuery qry1;
    qry1.prepare("update parking set reference='"+reference+"',place='"+place+"',nom='"+nom+"'where reference='"+reference+"'");
    if(qry1.exec())
    {
        ui->tableView_parking_2->setModel(tmp1.afficher());
        QMessageBox::information(this,tr("Edit"),tr("Updated"));

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Modifiée"),
                              QObject::tr("OK.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }

    ui->nbr_place_2->clear();
       ui->nom_employe_2->clear();
       ui->reference_2->clear();
}

void MainWindow::on_afficher_tab_park_2_clicked()
{
    ui->tableView_parking_2->setModel(tmp1.afficher());
}

void MainWindow::on_supp_park_2_clicked()
{
    int reference = ui->reference_2->text().toInt();
    bool test=tmp1.supprimer(reference);
    if(test)
    {
        ui->tableView_parking_2->setModel(tmp1.afficher());// refresh => chaque ajout sera affiché

        QMessageBox::information(nullptr, QObject::tr("Assurance Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    ui->nbr_place_2->clear();
       ui->nom_employe_2->clear();
       ui->reference_2->clear();
}

void MainWindow::on_supprimer_clicked()
{
    int reference = ui->ln_reference->text().toInt();
    bool test=tmp.supprimer(reference);
    if(test)
    {
        ui->tableView_assurance->setModel(tmp.afficher());// refresh => chaque ajout sera affiché

        QMessageBox::information(nullptr, QObject::tr("Assurance Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    ui->ln_compagnie->clear();
       ui->ln_type->clear();
       ui->ln_prix->clear();
       ui->ln_reference->clear();

}

void MainWindow::on_tableView_assurance_activated(const QModelIndex &index)
{
    QString  val=ui->tableView_assurance->model()->data(index).toString();
    QSqlQuery qry;


    qry.prepare("select * from ASSURANCE  where PRIX='"+val+"'or REFERENCE='"+val+"'");

    if(qry.exec())
    {
       while(qry.next())
       {
           ui->ln_compagnie->setText(qry.value(0).toString());

           ui->ln_type->setText(qry.value(1).toString());

           ui->ln_prix->setText(qry.value(2).toString());

           ui->ln_reference->setText(qry.value(3).toString());
       }
    }
}

void MainWindow::on_tableView_parking_2_activated(const QModelIndex &index)
{
    QString  val=ui->tableView_parking_2->model()->data(index).toString();
    QSqlQuery qry;


    qry.prepare("select * from PARKING  where REFERENCE='"+val+"'or NOM='"+val+"'");

    if(qry.exec())
    {
       while(qry.next())
       {
           ui->reference_2->setText(qry.value(0).toString());

           ui->nbr_place_2->setText(qry.value(1).toString());

           ui->nom_employe_2->setText(qry.value(2).toString());
       }
    }
}

void MainWindow::on_trier_parking_clicked()
{
    int test=0;

          if (ui->choix_2->currentText()=="reference")
                     {test=1;}

          else if (ui->choix_2->currentText()=="nom")
                      {test=2;}

          else if (ui->choix_2->currentText()=="place")
                      {test=3;}


          ui->tableView_parking_2->setModel(tmp1.trier(test)) ;
}

void MainWindow::on_pdf_client_clicked()
{
    QString strStream;

                 QTextStream out(&strStream);


                 const int rowCount = ui->tabclient_2->model()->rowCount();

                 const int columnCount = ui->tabclient_2->model()->columnCount();


                 out <<  "<html>\n"

                     "<head>\n"

                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"

                     <<  QString("<title>%1</title>\n").arg("strTitle")

                     <<  "</head>\n"

                     "<body bgcolor=#ffffff link=#5000A0>\n"


                    //     "<align='right'> " << datefich << "</align>"

                     "<center> <H1>Liste des Agences </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";


                 // headers

                 out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";

                 for (int column = 0; column < columnCount; column++)

                     if (!ui->tabclient_2->isColumnHidden(column))

                         out << QString("<th>%1</th>").arg(ui->tabclient_2->model()->headerData(column, Qt::Horizontal).toString());

                 out << "</tr></thead>\n";


                 // data table

                 for (int row = 0; row < rowCount; row++) {

                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";

                     for (int column = 0; column < columnCount; column++) {

                         if (!ui->ag_tab_aff->isColumnHidden(column)) {

                             QString data = ui->tabclient_2->model()->data(ui->tabclient_2->model()->index(row, column)).toString().simplified();

                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));

                         }

                     }

                     out << "</tr>\n";

                 }

                 out <<  "</table> </center>\n"

                     "</body>\n"

                     "</html>\n";


           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");

             if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }


            QPrinter printer (QPrinter::PrinterResolution);

             printer.setOutputFormat(QPrinter::PdfFormat);

            printer.setPaperSize(QPrinter::A4);

           printer.setOutputFileName(fileName);


            QTextDocument doc;

             doc.setHtml(strStream);

             doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number

             doc.print(&printer);
}

void MainWindow::on_imprimer_assu_clicked()
{
    //imprimer

        QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}

void MainWindow::on_btn_existe_9_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->voiture_ch);
}

void MainWindow::on_stat_2_clicked()
{
      write_to_arduino("0");
}

void MainWindow::on_btn_pointage_clicked()
{   arduino1 a ;

    ui->tab_pointage->setModel(a.afficher());
    ui->stackedWidget->setCurrentWidget(ui->pointage) ;

}

void MainWindow::on_excel_clicked()
{
   /* QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "xlsx_connection");
    db.setDatabaseName("DRIVER={Microsoft Excel Driver (*.xls, *.xlsx, *.xlsm, *.xlsb)};DBQ=" + QString("C:/Users/eyaou/Desktop/projet/file.xls")); if(db.open())
    {

    QSqlQuery query("select * from fournisseur [" + QString("Sheet1") + "$]",db); // Select range, place A1:B5 after $
    while (query.next())
    {
    QString column1= query.value(0).toString();
    qDebug() << column1;
    }
}*/

    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->tabfour_2);

        // you can change the column order and
        // choose which colum to export
        obj.addField(0, "1cin", "char(20)");
        obj.addField(1, "2nom", "char(20)");
        obj.addField(2, "3prenom", "char(20)");
        obj.addField(3, "4piece", "char(20)");
        obj.addField(4, "5nombre", "char(20)");
        obj.addField(5, "6prix", "char(20)");
        obj.addField(6, "7date", "char(20)");


        int retVal = obj.export2Excel();

        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }
}

void MainWindow::on_NomFournisseur_4_textChanged(const QString &arg1)
{
    proxyfournisseur->setFilterFixedString(arg1);
}

void MainWindow::on_imp_clicked()
{

    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()== QDialog::Rejected)

        return;
}

void MainWindow::on_tutoriel_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("database is open"),
             QObject::tr("Tutoriel.\n1)	Pour modifier appuyer sur la référence de l’élément à modifier 2 fois pour le sélectionner. Après la modification appuyer sur modifier (vous ne pouvez pas modifier la référence).\n2)	Export PDF n’exporte que les éléments dans le tableau, par exemple : si on cherche les compagnies dont le nom commence par ‘A’, c’est cette liste qui va être exporté.\n3)	Pour supprimer sélectionner ou écrivez la référence de l’élément à supprimer puis appuyez sur le bouton ‘Supprimer’.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tutoriel_2_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Tutoriel"),
             QObject::tr("1)	Pour modifier appuyer sur la référence de l’élément à modifier 2 fois pour le sélectionner. Après la modification appuyer sur modifier (vous ne pouvez pas modifier la référence).\n2)	Export PDF n’exporte que les éléments dans le tableau, par exemple : si on cherche les compagnies dont le nom commence par ‘A’, c’est cette liste qui va être exporté.\n3)	Pour supprimer sélectionner ou écrivez la référence de l’élément à supprimer puis appuyez sur le bouton ‘Supprimer’.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_commandLinkButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->service_anglais) ;
}

void MainWindow::on_commandLinkButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->service_anglais) ;
}

void MainWindow::on_commandLinkButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->service) ;
}

void MainWindow::on_commandLinkButton_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->service) ;
}

void MainWindow::on_Tutorial_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Tutorial"),
             QObject::tr("1)	To edit press the reference of the item you change 2 times to select it. After the the modifications press edit (you cannot edit the reference).\n2)	Export PDF only exports items in the table, for example: if we look for companies whose name starts with ‘A’, it is this list that will be exported.\n3)	To delete select or write the reference of the item you want to delete and press the ‘Delete’ button.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_ajouter_assu_2_clicked()
{
    // recuperer les informations saisies dans l'interface
     QString compagnie = ui->ln_compagnie_2->text();
     int prix = ui->ln_prix_2->text().toInt();
     QString type = ui->ln_type_2->text();
     int reference = ui->ln_reference_2->text().toInt();

     Assurance A(compagnie,prix,type,reference);
     bool test=A.ajouter();

     if(test)
     {
         ui->tableView_assurance_2->setModel(tmp2.afficher()); // refresh => chaque ajout sera affiché
         QMessageBox::information(nullptr, QObject::tr("Assurance Ajoutée"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

 }
     else
         QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Ajoutée"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     ui->ln_compagnie_2->clear();
        ui->ln_type_2->clear();
        ui->ln_prix_2->clear();
        ui->ln_reference_2->clear();
        ui->tableView_assurance_2->setModel(tmp2.afficher());
}

void MainWindow::on_afficher_tab_assu_2_clicked()
{
    ui->tableView_assurance_2->setModel(tmp.afficher());

}

void MainWindow::on_mod_assu_2_clicked()
{
    QString compagnie,type,reference,prix;
    //int reference,prix;
    compagnie=ui->ln_compagnie_2->text();
    type=ui->ln_type_2->text();
    prix=ui->ln_prix_2->text();
    reference=ui->ln_reference_2->text();

    QSqlQuery qry;
    qry.prepare("update assurance set reference='"+reference+"',type='"+type+"',prix='"+prix+"',compagnie='"+compagnie+"'where reference='"+reference+"'");
    if(qry.exec())
    {
        ui->tableView_assurance_2->setModel(tmp2.afficher());
        //ui->tableView_upark->setModel(tmp.afficher());
        QMessageBox::information(this,tr("Edit"),tr("Updated"));

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Modifiée"),
                              QObject::tr("OK.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }
    ui->tableView_assurance_2->setModel(tmp2.afficher());
    ui->ln_compagnie_2->clear();
       ui->ln_type_2->clear();
       ui->ln_prix_2->clear();
       ui->ln_reference_2->clear();
}

void MainWindow::on_supprimer_2_clicked()
{
    int reference = ui->ln_reference_2->text().toInt();
    bool test=tmp2.supprimer(reference);
    if(test)
    {
        ui->tableView_assurance->setModel(tmp2.afficher());// refresh => chaque ajout sera affiché

        QMessageBox::information(nullptr, QObject::tr("Assurance Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

ui->tableView_assurance->setModel(tmp2.afficher());
    ui->ln_compagnie_2->clear();
       ui->ln_type_2->clear();
       ui->ln_prix_2->clear();
       ui->ln_reference_2->clear();
}

void MainWindow::on_export_pdf_2_clicked()
{
    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tableView_assurance_2->model()->rowCount();
                     const int columnCount = ui->tableView_assurance_2->model()->columnCount();

                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView_assurance->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView_assurance->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView_assurance->isColumnHidden(column)) {
                                 QString data = ui->tableView_assurance->model()->data(ui->tableView_assurance->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n"
                         "</body>\n"
                         "</html>\n";

               QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                 if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                QPrinter printer (QPrinter::PrinterResolution);
                 printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName(fileName);

                QTextDocument doc;
                 doc.setHtml(strStream);
                 doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                 doc.print(&printer);
}

void MainWindow::on_recherche_2_clicked()
{
    ui->tableView_assurance_2->setModel(tmp2.recherche(ui->reref_2->text().toInt(),ui->retype_2->text(),ui->recom_2->text()));
    ui->retype_2->clear();
       ui->reref_2->clear();
       ui->recom_2->clear();
}

void MainWindow::on_park_ajout_3_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    int reference = ui->reference_3->text().toInt();
    int place = ui->nbr_place_3->text().toInt();
    QString nom = ui->nom_employe_3->text();

    Parking P(reference,place,nom);
    model=P.recherche(nom,place);
    if(model==0)
    {
        bool test=P.ajouter();
        if(test)
        {
            ui->tableView_parking_3->setModel(tmp3.afficher());
            QMessageBox::information(nullptr, QObject::tr("Parking Added"),
                         QObject::tr("OK.\n"
                                     "Click Cancel to exit"),QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr, QObject::tr("Parking Not Added"),
                         QObject::tr("OK.\n"
                                     "Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Parking Already Exists"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit."),QMessageBox::Cancel);
    ui->tableView_parking_3->setModel(tmp3.afficher());
    ui->nbr_place_3->clear();
           ui->nom_employe_3->clear();
           ui->reference_3->clear();
}

void MainWindow::on_afficher_tab_park_3_clicked()
{
    ui->tableView_parking_3->setModel(tmp3.afficher());

}

void MainWindow::on_mod_park_3_clicked()
{
    QString reference,place,nom;
    reference=ui->reference_3->text();
    place=ui->nbr_place_3->text();
    nom=ui->nom_employe_3->text();

    QSqlQuery qry1;
    qry1.prepare("update parking set reference='"+reference+"',place='"+place+"',nom='"+nom+"'where reference='"+reference+"'");
    if(qry1.exec())
    {
        ui->tableView_parking_3->setModel(tmp3.afficher());
        QMessageBox::information(this,tr("Edit"),tr("Updated"));

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Inssurance Not Edited"),
                              QObject::tr("OK.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }

    ui->tableView_parking_3->setModel(tmp3.afficher());
    ui->nbr_place_3->clear();
       ui->nom_employe_3->clear();
       ui->reference_3->clear();
}

void MainWindow::on_supp_park_3_clicked()
{
    int reference = ui->reference_3->text().toInt();
    bool test=tmp3.supprimer(reference);
    if(test)
    {
        ui->tableView_parking_3->setModel(tmp3.afficher());// refresh => chaque ajout sera affiché

        QMessageBox::information(nullptr, QObject::tr("Inssurance Deteled"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Inssurance Not Delted"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    ui->nbr_place_3->clear();
       ui->nom_employe_3->clear();
       ui->reference_3->clear();
}

void MainWindow::on_trier_parking_2_clicked()
{
    int test=0;

          if (ui->choix_3->currentText()=="reference")
                     {test=1;}

          else if (ui->choix_3->currentText()=="name")
                      {test=2;}

          else if (ui->choix_3->currentText()=="parking number")
                      {test=3;}


          ui->tableView_parking_3->setModel(tmp3.trier(test)) ;
}

void MainWindow::on_tableView_parking_3_activated(const QModelIndex &index)
{
    QString  val=ui->tableView_parking_3->model()->data(index).toString();
    QSqlQuery qry;


    qry.prepare("select * from PARKING  where REFERENCE='"+val+"'or NOM='"+val+"'");

    if(qry.exec())
    {
       while(qry.next())
       {
           ui->reference_3->setText(qry.value(0).toString());

           ui->nbr_place_3->setText(qry.value(1).toString());

           ui->nom_employe_3->setText(qry.value(2).toString());
       }
    }
}

void MainWindow::on_tableView_assurance_2_activated(const QModelIndex &index)
{
    QString  val=ui->tableView_assurance_2->model()->data(index).toString();
    QSqlQuery qry;


    qry.prepare("select * from ASSURANCE  where PRIX='"+val+"'or REFERENCE='"+val+"'");

    if(qry.exec())
    {
       while(qry.next())
       {
           ui->ln_compagnie_2->setText(qry.value(0).toString());

           ui->ln_type_2->setText(qry.value(1).toString());

           ui->ln_prix_2->setText(qry.value(2).toString());

           ui->ln_reference_2->setText(qry.value(3).toString());
       }
    }
}

void MainWindow::on_btn_existe_10_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Menu) ;
}

void MainWindow::on_btn_existe_123_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Menu) ;
}


void MainWindow::on_Tutorial_55_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Tutorial"),
             QObject::tr("1)	To edit press the reference of the item you change 2 times to select it. After the the modifications press edit (you cannot edit the reference).\n2)	Export PDF only exports items in the table, for example: if we look for companies whose name starts with ‘A’, it is this list that will be exported.\n3)	To delete select or write the reference of the item you want to delete and press the ‘Delete’ button.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_btn_em_rec_clicked()
{
    //QString a ;

    //qDebug()<<(ui->textEdit->document()->isEmpty()) ;

    if(ui->textEdit->document()->isEmpty()) {

         QMessageBox::critical(nullptr, QObject::tr("MAIL Denied"),
         QObject::tr("Desole le mail est vide .\n""Click Cancel to exit."), QMessageBox::Cancel);
     }
    else {
        // This is a first demo application of the SmtpClient for Qt project


        // First we need to create an SmtpClient object
        // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

        SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        // We need to set the username (your email address) and password
        // for smtp authentification.

        smtp.setUser("aderssa.dhia.factory@gmail.com");
        smtp.setPassword("15621562");

        // Now we create a MimeMessage object. This is the email.

        MimeMessage message;
        QString name ="aderssa";
        EmailAddress sender("aderssa.dhia.factory@gmail.com", name );
        message.setSender(&sender);

        EmailAddress to("ros.ch.factory@gmail.com", "Recipient's Name");
        message.addRecipient(&to);

        message.setSubject("RECLAMATION");

        // Now add some text to the email.
        // First we create a MimeText object.

        MimeText text;

        text.setText(ui->textEdit->toPlainText());

        // Now add it to the mail

        message.addPart(&text);

        // Now we can send the mail

        if (!smtp.connectToHost()) {
            qDebug() << "Failed to connect to host!" << endl;

        }

        if (!smtp.login()) {
            qDebug() << "Failed to login!" << endl;

        }

        if (!smtp.sendMail(message)) {
            qDebug() << "Failed to send mail!" << endl;
            QMessageBox::critical(nullptr, QObject::tr("MAILING"),
            QObject::tr(" Mail NO send .\n""Click Cancel to exit."), QMessageBox::Cancel);


        }
        else {
            QMessageBox::information(nullptr, QObject::tr("OK"),
            QObject::tr("Mail envoye .\n""Click Cancel to exit."), QMessageBox::Cancel);

        }

        smtp.quit();

    }
}

void MainWindow::on_reclamation_3_clicked()
{
    //QString a ;

    //qDebug()<<(ui->textEdit->document()->isEmpty()) ;
ui->stackedWidget->setCurrentWidget(ui->reclamation) ;
    if(ui->textEdit->document()->isEmpty()) {

         QMessageBox::critical(nullptr, QObject::tr("MAIL Denied"),
         QObject::tr("Desole le mail est vide .\n""Click Cancel to exit."), QMessageBox::Cancel);
     }
    else {
        // This is a first demo application of the SmtpClient for Qt project


        // First we need to create an SmtpClient object
        // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

        SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        // We need to set the username (your email address) and password
        // for smtp authentification.

        smtp.setUser("aderssa.dhia.factory@gmail.com");
        smtp.setPassword("15621562");

        // Now we create a MimeMessage object. This is the email.

        MimeMessage message;
        QString name ="aderssa";
        EmailAddress sender("aderssa.dhia.factory@gmail.com", name );
        message.setSender(&sender);

        EmailAddress to("ros.ch.factory@gmail.com", "Recipient's Name");
        message.addRecipient(&to);

        message.setSubject("RECLAMATION");

        // Now add some text to the email.
        // First we create a MimeText object.

        MimeText text;

        text.setText(ui->textEdit->toPlainText());

        // Now add it to the mail

        message.addPart(&text);

        // Now we can send the mail

        if (!smtp.connectToHost()) {
            qDebug() << "Failed to connect to host!" << endl;

        }

        if (!smtp.login()) {
            qDebug() << "Failed to login!" << endl;

        }

        if (!smtp.sendMail(message)) {
            qDebug() << "Failed to send mail!" << endl;
            QMessageBox::critical(nullptr, QObject::tr("MAILING"),
            QObject::tr(" Mail NO send .\n""Click Cancel to exit."), QMessageBox::Cancel);


        }
        else {
            QMessageBox::information(nullptr, QObject::tr("OK"),
            QObject::tr("Mail envoye .\n""Click Cancel to exit."), QMessageBox::Cancel);

        }

        smtp.quit();

    }

}
