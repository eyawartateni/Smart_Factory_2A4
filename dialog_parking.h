#ifndef DIALOG_PARKING_H
#define DIALOG_PARKING_H

#include "parking.h"
#include <QDialog>

namespace Ui {
class dialog_parking;
}

class dialog_parking : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_parking(QWidget *parent = nullptr);
    ~dialog_parking();

private slots:
    void on_park_ajout_2_clicked();

    void on_mod_park_2_clicked();

    void on_supp_park_2_clicked();

    //void on_comboBox_currentIndexChanged(const QString &arg1);

    //void on_comboBox_currentIndexChanged(int index);

    void on_trier_2_clicked();

    void on_afficher_tab_park_2_clicked();

private:
    Ui::dialog_parking *ui;
    Parking tmp1;

};

#endif // DIALOG_PARKING_H
