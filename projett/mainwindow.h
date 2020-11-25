#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include"voiture.h"
#include"chaine.h"
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QSqlRelationalTableModel>
#include<QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlRelationalTableModel *modVoiture;
    QSortFilterProxyModel * proxyVoiture;
private slots:
    void on_ajouter_clicked();

    void on_afficher_clicked();

    void on_retour_clicked();

    void on_quitter_clicked();

    void on_supprimer_clicked();

    void on_retour_2_clicked();

    void on_modifier_clicked();

    void on_retour_3_clicked();

    void on_retour_4_clicked();

    void on_pushButton_retour_clicked();

    void on_pushButton_retour_2_clicked();

    void on_pushButton_afficher_chaine_clicked();

    void on_pushButton_modifier_chaine_clicked();

    void on_pushButton_supprimer_chaine_clicked();

    void on_quitter_2_clicked();

    void on_pushButton_ajouter_chaine_clicked();

    void on_recherche_2_clicked();



    void on_load_data_clicked();

    //void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_modifier_3_clicked();

    void on_comboBox_currentIndexChanged();

  //  void on_recherche_clicked();

    void on_sup_clicked();


    void on_lineEdit_referencee_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    voiture vtmp;
    chaine ctmp;
    voiture *v;
};
#endif // MAINWINDOW_H
