#ifndef DIALOG_ASSURANCE_H
#define DIALOG_ASSURANCE_H

#include"assurance.h"
#include <QDialog>
#include <QSortFilterProxyModel>

namespace Ui {
class dialog_assurance;
}

class dialog_assurance : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_assurance(QWidget *parent = nullptr);
    ~dialog_assurance();

private slots:
    void on_supprimer_clicked();

    void on_ajouter_assu_clicked();

    void on_mod_assu_clicked();

    void on_recherche_clicked();

    void on_export_pdf_clicked();

    void on_afficher_tab_assu_clicked();

    void on_pushButton_clicked();

private:
    Ui::dialog_assurance *ui;
    Assurance tmp;
    QSortFilterProxyModel * proxy;
};

#endif // DIALOG_ASSURANCE_H
