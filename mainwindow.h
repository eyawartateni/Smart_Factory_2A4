#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"assurance.h"
#include "parking.h"
#include <QDialog>
#include <QSortFilterProxyModel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_connexion_clicked();

    void on_ajouter_assu_clicked();

    void on_mod_assu_clicked();

    void on_supprimer_clicked();

    void on_export_pdf_clicked();

    void on_recherche_clicked();

    void on_afficher_tab_assu_clicked();

    void on_park_ajout_2_clicked();

    void on_mod_park_2_clicked();

    void on_supp_park_2_clicked();

    void on_trier_2_clicked();

    void on_afficher_tab_park_2_clicked();

private:
    Ui::MainWindow *ui;
    Assurance tmp;
    QSortFilterProxyModel * proxy;
    Parking tmp1;
};
#endif // MAINWINDOW_H
