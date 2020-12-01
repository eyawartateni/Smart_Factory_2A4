#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include <QSound>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
QLabel *processLabel ;

private:
    QString F_name ,L_name, ADRESSE ;
  //  QDate Mydate ;
public:

//tab_map tab_pos ;
    int max=0 ;
   // MainWindow l  ;
   // void setF_name(QString F_n) {F_name=F_n;} ;
   // void setL_name(QString L_n) {L_name=L_n;} ;
    //void setADRESSE(QString AD) {ADRESSE=AD;} ;
   // void setDATE(QDate DT) {Mydate=DT;} ;
   // QString getF_name(){return F_name ;  } ;
    //QString getL_name(){return L_name ;  } ;
    //QString getADRESSE(){return ADRESSE ;  } ;
   // QDate getDATE(){return Mydate ;  } ;
//    employer e ;


    int cin  ;
  bool ass=true  ;
  bool rec=true ;
  //void setEMPLOYER(employer em) ;
  //QString get_nom();
 // QString get_prenom();
  //int get_id();
  //bool ajouter(employer);
 // QSqlQueryModel * afficher();
//  bool supprimer(int);



private slots:
  void on_btn_login_clicked();

  void on_m_agence_clicked();

  void on_but_ag_ajou_clicked();

  void on_but_ag_affi_clicked();

  void on_but_ag_mod_clicked();

  void on_but_adm_sup_2_clicked();

  void on_but_adm_home_7_clicked();

  void on_but_adm_ajou_7_clicked();

  void on_menu_emp_clicked();

  void on_but_adm_ajou_clicked();

  void on_but_adm_affi_clicked();

  void on_but_adm_mod_clicked();

  void on_but_adm_sup_clicked();

  void on_but_adm_home_8_clicked();

  void on_assurence_8_clicked();

  void on_assurence_clicked();

  void on_reclamation_clicked();

  void on_btn_ajouter_clicked();

  void on_btn_adm_supp_clicked();

  void on_btn_adm_load_clicked();

  void on_adm_combobox_aff_currentIndexChanged(const QString &arg1);

  void on_btn_ajouter_2_clicked();

  void on_btn_ag_aj_clicked();

  void on_btn_adm_supp_2_clicked();

  void on_btn_ag_supp__clicked();

  void on_btn_ag_load_clicked();

  void on_ag_combobox_aff_currentIndexChanged(const QString &arg1);

  void on_pushButton_2_clicked();

  void on_btn_adm_tri_aff_clicked();



  void on_btn_em_rec_clicked();

  void on_but_adm_ajou_stat_clicked();



  void on_btn_ag_export_3_clicked();

  void on_btn_ag_export_clicked();

  void on_btn_ag_imprimer_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
