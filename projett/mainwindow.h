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
#include"statistique.h"

#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
class QPrinter;
class QSqlTableModel;

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


    void on_load_data_clicked();
    void on_modifier_3_clicked();

    void on_comboBox_currentIndexChanged();

    void on_sup_clicked();
    void on_tri_clicked();

    void on_recherche_clicked();

    void on_load_ch_clicked();

    void on_modifier_ch_clicked();

    void on_comboBox_ch_currentIndexChanged();

    void on_sup_ch_clicked();

    void on_pushButton_4_clicked();
    void print(QPrinter *printer);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    voiture vtmp;
    chaine ctmp;
    Statistique *stat;
    QSqlTableModel *model;
};
#endif // MAINWINDOW_H
