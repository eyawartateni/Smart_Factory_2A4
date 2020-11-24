#ifndef DIALOG_FOURNISSEUR_H
#define DIALOG_FOURNISSEUR_H
#include "fournisseur.h"

#include <QDialog>

namespace Ui {
class Dialog_fournisseur;
}

class Dialog_fournisseur : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_fournisseur(QWidget *parent = nullptr);

    void setfournisseur(fournisseur F);
    ~Dialog_fournisseur();

private slots:
    void on_nbre_valueChanged(const QString &arg1);

private:
    Ui::Dialog_fournisseur *ui;
};

#endif // DIALOG_FOURNISSEUR_H
