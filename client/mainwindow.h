#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "client.h"
#include "fournisseur.h"
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QSqlRelationalTableModel>
#include <connection.h>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlRelationalTableModel *modClient;
    QSortFilterProxyModel * proxyclient;
    QSqlRelationalTableModel *modFournisseur;
    QSortFilterProxyModel * proxyfournisseur;


private slots:
    void on_quitter_clicked();









    void on_terminer_clicked();

    void on_afficher_clicked();

    void on_afficher_fournisseur_clicked();

    void on_modifier_clicked();

    void on_pushButton_clicked();

    void on_nbre_valueChanged(int arg1);

    void on_nbre_valueChanged(const QString &arg1);

    void on_nbre_textChanged(const QString &arg1);

    void on_terminer_fournisseur_clicked();

    void on_supprimer_client_clicked();

    void on_supprimer_fournisseur_clicked();

    void on_modifierFour_clicked();

    void on_ajouterFour_clicked();




    void on_trier_clicked();

    void on_cin_chercher_textChanged(const QString &arg1);

    void on_cincherf_textChanged(const QString &arg1);

    void on_tabfour_activated(const QModelIndex &index);

    void on_tabclient_activated(const QModelIndex &index);

    void on_exportpdf_clicked();

private:
    Ui::MainWindow *ui;
    Client tmpclient;
    fournisseur tmpfournisseur;

};
#endif // MAINWINDOW_H
